#include "header/httpd.h"

//#include "hps_soc_system.h"
//#include "hps_linux.h"

#include <sys/stat.h>
#include <ctype.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <math.h>



#define CHUNK_SIZE 1024 // read 1024 bytes at a time

// Public directory settings
#define PUBLIC_DIR "./public"
#define INDEX_HTML "/index.html"
#define NOT_FOUND_HTML "/404.html"

char 
    *token, 
    *key, 
    *value, 
    *p;

char *array[3];
char *list[7];
int i, j = 0;

struct pair {
  char *key;
  char *value;
};

struct pair pairs[4];


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

int main(int c, char **v) {
  char *port = c == 1 ? "80" : v[1];
  serve_forever(port);
  return 0;
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

      printf("{key: %s", (pairs[0].key));
      printf(", value: %s } \n", (pairs[0].value));

      printf("{key: %s", (pairs[1].key));
      printf(", value: %s } \n", (pairs[1].value));

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
