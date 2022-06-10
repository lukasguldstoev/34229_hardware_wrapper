#pragma region

#define soc_cv_av
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include "header/hps_soc_system.h"
#include "header/hps_linux.h"

#include "header/httpd.h"
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>


#define CHUNK_SIZE 1024 // read 1024 bytes at a time
#define PUBLIC_DIR "./public"
#define INDEX_HTML "/index.html"
#define NOT_FOUND_HTML "/404.html"
 
#define FIFO_FRAMING_FULL		((*(fifo_framing_status_ptr+1))& 1 )
#define FIFO_FRAMING_EMPTY		((*(fifo_framing_status_ptr+1))& 2 )

#define FIFO_FRAMING_FULL2		((*(fifo_fpga_hps_status_ptr+1))& 1 )
#define FIFO_FRAMING_EMPTY2		((*(fifo_fpga_hps_status_ptr+1))& 2 )

#define alt_write_word(dest, src)       (*ALT_CAST(volatile uint32_t *, (dest)) = (src))

volatile unsigned short * fifo_framing_transmit_ptr = NULL;
volatile unsigned int * fifo_framing_status_ptr = NULL;
volatile unsigned short * fifo_fpga_hps_receive_ptr = NULL;
volatile unsigned int * fifo_fpga_hps_status_ptr = NULL;
volatile unsigned int * fpga_HEX0 = NULL;
volatile unsigned int * fpga_leds = NULL;
volatile unsigned int * fpga_switches = NULL;


char 
    *token, 
    *key, 
    *value, 
    *p;
char *array[3];
char *list[7];
int i, j = 0;
int scanok;
unsigned short N;

struct pair {
  char *key;
  char *value;
};

struct pair pairs[4];

#pragma endregion



int main(int c, char **v) {
  char *port = c == 1 ? "80" : v[1];

  open_physical_memory_device();
  mmap_fpga_peripherals();

  serve_forever(port);
  return 0;
}


void open_physical_memory_device() {
    // We need to access the system's physical memory so we can map it to user
    // space. We will use the /dev/mem file to do this. /dev/mem is a character
    // device file that is an image of the main memory of the computer. Byte
    // addresses in /dev/mem are interpreted as physical memory addresses.
    // Remember that you need to execute this program as ROOT in order to have
    // access to /dev/mem.

    fd_dev_mem = open("/dev/mem", O_RDWR | O_SYNC);
    if(fd_dev_mem  == -1) {
        printf("ERROR: could not open \"/dev/mem\".\n");
        printf("    errno = %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void close_physical_memory_device() {
    close(fd_dev_mem);
}

void mmap_fpga_peripherals() {
    h2f_lw_axi_master = mmap(NULL, h2f_lw_axi_master_span, PROT_READ | PROT_WRITE, MAP_SHARED, fd_dev_mem, h2f_lw_axi_master_ofst);
    if (h2f_lw_axi_master == MAP_FAILED) {
        printf("Error: h2f_lw_axi_master mmap() failed.\n");
        printf("    errno = %s\n", strerror(errno));
        close(fd_dev_mem);
        exit(EXIT_FAILURE);
    }
	h2f_axi_master = mmap(NULL, h2f_axi_master_span, (PROT_READ | PROT_WRITE), MAP_SHARED, fd_dev_mem, h2f_axi_master_ofst);
    if (h2f_axi_master == MAP_FAILED) {
        printf("Error: h2f_lw_axi_master mmap() failed.\n");
        printf("    errno = %s\n", strerror(errno));
        close(fd_dev_mem);
        exit(EXIT_FAILURE);
    }

	fifo_framing_transmit_ptr = (unsigned short *) (h2f_axi_master + FIFO_TX_VIDEO_IN_BASE);
	fifo_framing_status_ptr = (unsigned int *)(h2f_lw_axi_master +  FIFO_TX_VIDEO_IN_CSR_BASE);

	fifo_fpga_hps_receive_ptr = (unsigned short *) (h2f_lw_axi_master + FIFO_CONTROL_RX_OUT_BASE);
	fifo_fpga_hps_status_ptr = (unsigned int *)(h2f_lw_axi_master +  FIFO_CONTROL_RX_OUT_CSR_BASE);
	

	fpga_leds =   (unsigned int *) (h2f_lw_axi_master +  HPS_FPGA_LEDS_BASE);
	fpga_switches = h2f_lw_axi_master + HPS_FPGA_SWITCHES_BASE;
	fpga_HEX0 = h2f_lw_axi_master + HPS_FPGA_HEX0_BASE;
}

void munmap_fpga_peripherals() {
    if (munmap(h2f_lw_axi_master, h2f_lw_axi_master_span) != 0) {
        printf("Error: h2f_lw_axi_master munmap() failed\n");
        printf("    errno = %s\n", strerror(errno));
        close(fd_dev_mem);
        exit(EXIT_FAILURE);
    }
	if (munmap(h2f_axi_master, h2f_axi_master_span) != 0) {
        printf("Error: h2f_lw_axi_master munmap() failed\n");
        printf("    errno = %s\n", strerror(errno));
        close(fd_dev_mem);
        exit(EXIT_FAILURE);
    }
    h2f_lw_axi_master = NULL;
	h2f_axi_master    = NULL;
    fpga_leds         = NULL;
	fpga_switches	  = NULL;
	fifo_framing_transmit_ptr = NULL;
	fifo_framing_status_ptr = NULL;
	fifo_fpga_hps_receive_ptr = NULL;
	fifo_fpga_hps_status_ptr = NULL;

}



char *urlDecode(const char *str) {
  int d = 0; /* whether or not the string is decoded */

  char *dStr = malloc(strlen(str) + 1);
  char eStr[] = "00"; /* for a hex code */

  strcpy(dStr, str);

  while(!d) {
    d = 1;
    int i; /* the counter for the string */

    for(i=0;i<strlen(dStr);++i) {

      if(dStr[i] == '%') {
        if(dStr[i+1] == 0)
          return dStr;

        if(isxdigit(dStr[i+1]) && isxdigit(dStr[i+2])) {

          d = 0;

          /* combine the next to numbers into one */
          eStr[0] = dStr[i+1];
          eStr[1] = dStr[i+2];

          /* convert it to decimal */
          long int x = strtol(eStr, NULL, 16);

          /* remove the hex */
          memmove(&dStr[i+1], &dStr[i+3], strlen(&dStr[i+3])+1);

          dStr[i] = x;
        }
      }
    }
  }

  return dStr;
}

void formDataToKeyPair(char * payload){
  // Extract the key-value pair
      p = strtok(payload, "&");

      // Exctract rest of key-value pairs
      while (p != NULL){
        array[i++] = p;
        p = strtok(NULL, "&");
      }

      // iterate key-value pairs
      for (i = 0; i < 2; ++i){
        // split key value pairs
        p = strtok(array[i], "=");

        // get the values into a list
        while (p!= NULL){
          list[j++] = p;
          p = strtok(NULL, "&"); // print each keyvalue
        }
      }

      for (i = 0; i < 4; ++i){
        // key [i % 2 = 0] - value [i % 2 = 1]
        // insert key-value into one array object
        if (i % 2 == 0){
          pairs[(int) i/2].key = list[i];
        } else if (i % 2 == 1){
          pairs[(int) i/2].value = list[i];
        }
      }
}

/**
 * @brief helper function
 * 
 * @param file_name 
 * @return int 
 */
int file_exists(const char *file_name) {
  struct stat buffer;
  int exists;

  exists = (stat(file_name, &buffer) == 0);

  return exists;
}

/**
 * @brief helper function
 * 
 * @param file_name 
 * @return int 
 */
int read_file(const char *file_name) {
  char buf[CHUNK_SIZE];
  FILE *file;
  size_t nread;
  int err = 1;

  file = fopen(file_name, "r");

  if (file) {
    while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
      fwrite(buf, 1, nread, stdout);

    err = ferror(file);
    fclose(file);
  }
  return err;
}

/**
 * @brief routing 
 * 
 */
void route() {
  ROUTE_START()

  /**
   * @brief get index.html
   * 
   */
  GET("/") {
    char index_html[20];
    sprintf(index_html, "%s%s", PUBLIC_DIR, INDEX_HTML);

    HTTP_200;
    if (file_exists(index_html)) {
      read_file(index_html);
    } else {
      printf("Hello! You are using %s\n\n", request_header("User-Agent"));
    }
  }

  /**
   * @brief 
   * get request test
   * 
  GET("/test") {
    HTTP_200;
    printf("List of request headers:\n\n");

    header_t *h = request_headers();

    while (h->name) {
      printf("%s: %s\n", h->name, h->value);
      h++;
    }
  }
   */

  POST("/aes/encrypt") {
    HTTP_201;
    printf("ENCRYPT: %d bytes receieved.\n", payload_size);

    if (payload_size > 0){
     
      payload = urlDecode(payload);
      formDataToKeyPair(payload);

      printf("{key: %s, value: %s}\n", (pairs[0].key), (pairs[0].value));
      printf("{key: %s, value: %s}\n", (pairs[1].key), (pairs[1].value));

      N=(unsigned short) 7;
      printf("Writing %d to FIFO\n\n",N);
      if (!FIFO_FRAMING_FULL) {* fifo_framing_transmit_ptr=N;};

      while (FIFO_FRAMING_EMPTY2==0){
        printf("\nRead: %i", *fifo_fpga_hps_receive_ptr);
      }
     // printf("\n\r Read: %i", *fifo_fpga_hps_receive_ptr);

    }
  }

  POST("/aes/decrypt") {
    HTTP_201;
    printf("DECRYPT: %d bytes receieved.\n", payload_size);

    if (payload_size > 0)
      payload = urlDecode(payload);
      formDataToKeyPair(payload);

      printf("{key: %s", (pairs[0].key));
      printf(", value: %s } \n", (pairs[0].value));

      printf("{key: %s", (pairs[1].key));
      printf(", value: %s } \n", (pairs[1].value));

      // handle above with HPS

  }

  GET(uri) {
    char file_name[255];
    sprintf(file_name, "%s%s", PUBLIC_DIR, uri);

    if (file_exists(file_name)) {
      HTTP_200;
      read_file(file_name);
    } else {
      HTTP_404;
      sprintf(file_name, "%s%s", PUBLIC_DIR, NOT_FOUND_HTML);
      if (file_exists(file_name))
        read_file(file_name);
    }
  }

  ROUTE_END()
}
