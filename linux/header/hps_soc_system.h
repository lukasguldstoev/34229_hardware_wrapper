#ifndef _ALTERA_HPS_SOC_SYSTEM_H_
#define _ALTERA_HPS_SOC_SYSTEM_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'soc_system' in
 * file 'soc_system.sopcinfo'.
 */

/*
 * This file contains macros for module 'hps_0' and devices
 * connected to the following masters:
 *   h2f_axi_master
 *   h2f_lw_axi_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'fifo_tx_video_in', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_TX_VIDEO_IN_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_TX_VIDEO_IN_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_TX_VIDEO_IN_COMPONENT_NAME fifo_tx_video
#define FIFO_TX_VIDEO_IN_BASE 0x0
#define FIFO_TX_VIDEO_IN_SPAN 2
#define FIFO_TX_VIDEO_IN_END 0x1
#define FIFO_TX_VIDEO_IN_AVALONMM_AVALONMM_DATA_WIDTH 16
#define FIFO_TX_VIDEO_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_TX_VIDEO_IN_BITS_PER_SYMBOL 16
#define FIFO_TX_VIDEO_IN_CHANNEL_WIDTH 8
#define FIFO_TX_VIDEO_IN_ERROR_WIDTH 8
#define FIFO_TX_VIDEO_IN_FIFO_DEPTH 64
#define FIFO_TX_VIDEO_IN_SINGLE_CLOCK_MODE 0
#define FIFO_TX_VIDEO_IN_SYMBOLS_PER_BEAT 2
#define FIFO_TX_VIDEO_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_TX_VIDEO_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_TX_VIDEO_IN_USE_AVALONST_SINK 0
#define FIFO_TX_VIDEO_IN_USE_AVALONST_SOURCE 0
#define FIFO_TX_VIDEO_IN_USE_BACKPRESSURE 0
#define FIFO_TX_VIDEO_IN_USE_IRQ 0
#define FIFO_TX_VIDEO_IN_USE_PACKET 1
#define FIFO_TX_VIDEO_IN_USE_READ_CONTROL 1
#define FIFO_TX_VIDEO_IN_USE_REGISTER 0
#define FIFO_TX_VIDEO_IN_USE_WRITE_CONTROL 1

/*
 * Macros for device 'fifo_control_rx_out_csr', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_CONTROL_RX_OUT_CSR_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_CONTROL_RX_OUT_CSR_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_CONTROL_RX_OUT_CSR_COMPONENT_NAME fifo_control_rx
#define FIFO_CONTROL_RX_OUT_CSR_BASE 0x0
#define FIFO_CONTROL_RX_OUT_CSR_SPAN 32
#define FIFO_CONTROL_RX_OUT_CSR_END 0x1f
#define FIFO_CONTROL_RX_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 16
#define FIFO_CONTROL_RX_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_CONTROL_RX_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_CONTROL_RX_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_CONTROL_RX_OUT_CSR_ERROR_WIDTH 8
#define FIFO_CONTROL_RX_OUT_CSR_FIFO_DEPTH 8
#define FIFO_CONTROL_RX_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_CONTROL_RX_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_CONTROL_RX_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_CONTROL_RX_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_CONTROL_RX_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_CONTROL_RX_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_CONTROL_RX_OUT_CSR_USE_BACKPRESSURE 0
#define FIFO_CONTROL_RX_OUT_CSR_USE_IRQ 0
#define FIFO_CONTROL_RX_OUT_CSR_USE_PACKET 1
#define FIFO_CONTROL_RX_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_CONTROL_RX_OUT_CSR_USE_REGISTER 0
#define FIFO_CONTROL_RX_OUT_CSR_USE_WRITE_CONTROL 1

/*
 * Macros for device 'fifo_control_tx_in_csr', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_CONTROL_TX_IN_CSR_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_CONTROL_TX_IN_CSR_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_CONTROL_TX_IN_CSR_COMPONENT_NAME fifo_control_tx
#define FIFO_CONTROL_TX_IN_CSR_BASE 0x20
#define FIFO_CONTROL_TX_IN_CSR_SPAN 32
#define FIFO_CONTROL_TX_IN_CSR_END 0x3f
#define FIFO_CONTROL_TX_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 16
#define FIFO_CONTROL_TX_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_CONTROL_TX_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_CONTROL_TX_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_CONTROL_TX_IN_CSR_ERROR_WIDTH 8
#define FIFO_CONTROL_TX_IN_CSR_FIFO_DEPTH 8
#define FIFO_CONTROL_TX_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_CONTROL_TX_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_CONTROL_TX_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_CONTROL_TX_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_CONTROL_TX_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_CONTROL_TX_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_CONTROL_TX_IN_CSR_USE_BACKPRESSURE 0
#define FIFO_CONTROL_TX_IN_CSR_USE_IRQ 0
#define FIFO_CONTROL_TX_IN_CSR_USE_PACKET 1
#define FIFO_CONTROL_TX_IN_CSR_USE_READ_CONTROL 1
#define FIFO_CONTROL_TX_IN_CSR_USE_REGISTER 0
#define FIFO_CONTROL_TX_IN_CSR_USE_WRITE_CONTROL 1

/*
 * Macros for device 'fifo_tx_video_in_csr', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_TX_VIDEO_IN_CSR_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_TX_VIDEO_IN_CSR_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_TX_VIDEO_IN_CSR_COMPONENT_NAME fifo_tx_video
#define FIFO_TX_VIDEO_IN_CSR_BASE 0x40
#define FIFO_TX_VIDEO_IN_CSR_SPAN 32
#define FIFO_TX_VIDEO_IN_CSR_END 0x5f
#define FIFO_TX_VIDEO_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 16
#define FIFO_TX_VIDEO_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_TX_VIDEO_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_TX_VIDEO_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_TX_VIDEO_IN_CSR_ERROR_WIDTH 8
#define FIFO_TX_VIDEO_IN_CSR_FIFO_DEPTH 64
#define FIFO_TX_VIDEO_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_TX_VIDEO_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_TX_VIDEO_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_TX_VIDEO_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_TX_VIDEO_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_TX_VIDEO_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_TX_VIDEO_IN_CSR_USE_BACKPRESSURE 0
#define FIFO_TX_VIDEO_IN_CSR_USE_IRQ 0
#define FIFO_TX_VIDEO_IN_CSR_USE_PACKET 1
#define FIFO_TX_VIDEO_IN_CSR_USE_READ_CONTROL 1
#define FIFO_TX_VIDEO_IN_CSR_USE_REGISTER 0
#define FIFO_TX_VIDEO_IN_CSR_USE_WRITE_CONTROL 1

/*
 * Macros for device 'hps_fpga_hex0', class 'altera_avalon_pio'
 * The macros are prefixed with 'HPS_FPGA_HEX0_'.
 * The prefix is the slave descriptor.
 */
#define HPS_FPGA_HEX0_COMPONENT_TYPE altera_avalon_pio
#define HPS_FPGA_HEX0_COMPONENT_NAME hps_fpga_hex0
#define HPS_FPGA_HEX0_BASE 0x60
#define HPS_FPGA_HEX0_SPAN 16
#define HPS_FPGA_HEX0_END 0x6f
#define HPS_FPGA_HEX0_BIT_CLEARING_EDGE_REGISTER 0
#define HPS_FPGA_HEX0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HPS_FPGA_HEX0_CAPTURE 0
#define HPS_FPGA_HEX0_DATA_WIDTH 7
#define HPS_FPGA_HEX0_DO_TEST_BENCH_WIRING 0
#define HPS_FPGA_HEX0_DRIVEN_SIM_VALUE 0
#define HPS_FPGA_HEX0_EDGE_TYPE NONE
#define HPS_FPGA_HEX0_FREQ 50000000
#define HPS_FPGA_HEX0_HAS_IN 0
#define HPS_FPGA_HEX0_HAS_OUT 1
#define HPS_FPGA_HEX0_HAS_TRI 0
#define HPS_FPGA_HEX0_IRQ_TYPE NONE
#define HPS_FPGA_HEX0_RESET_VALUE 0

/*
 * Macros for device 'hps_fpga_switches', class 'altera_avalon_pio'
 * The macros are prefixed with 'HPS_FPGA_SWITCHES_'.
 * The prefix is the slave descriptor.
 */
#define HPS_FPGA_SWITCHES_COMPONENT_TYPE altera_avalon_pio
#define HPS_FPGA_SWITCHES_COMPONENT_NAME hps_fpga_switches
#define HPS_FPGA_SWITCHES_BASE 0x70
#define HPS_FPGA_SWITCHES_SPAN 16
#define HPS_FPGA_SWITCHES_END 0x7f
#define HPS_FPGA_SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define HPS_FPGA_SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HPS_FPGA_SWITCHES_CAPTURE 0
#define HPS_FPGA_SWITCHES_DATA_WIDTH 10
#define HPS_FPGA_SWITCHES_DO_TEST_BENCH_WIRING 0
#define HPS_FPGA_SWITCHES_DRIVEN_SIM_VALUE 0
#define HPS_FPGA_SWITCHES_EDGE_TYPE NONE
#define HPS_FPGA_SWITCHES_FREQ 50000000
#define HPS_FPGA_SWITCHES_HAS_IN 1
#define HPS_FPGA_SWITCHES_HAS_OUT 0
#define HPS_FPGA_SWITCHES_HAS_TRI 0
#define HPS_FPGA_SWITCHES_IRQ_TYPE NONE
#define HPS_FPGA_SWITCHES_RESET_VALUE 0

/*
 * Macros for device 'hps_fpga_leds', class 'altera_avalon_pio'
 * The macros are prefixed with 'HPS_FPGA_LEDS_'.
 * The prefix is the slave descriptor.
 */
#define HPS_FPGA_LEDS_COMPONENT_TYPE altera_avalon_pio
#define HPS_FPGA_LEDS_COMPONENT_NAME hps_fpga_leds
#define HPS_FPGA_LEDS_BASE 0x80
#define HPS_FPGA_LEDS_SPAN 16
#define HPS_FPGA_LEDS_END 0x8f
#define HPS_FPGA_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define HPS_FPGA_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HPS_FPGA_LEDS_CAPTURE 0
#define HPS_FPGA_LEDS_DATA_WIDTH 10
#define HPS_FPGA_LEDS_DO_TEST_BENCH_WIRING 0
#define HPS_FPGA_LEDS_DRIVEN_SIM_VALUE 0
#define HPS_FPGA_LEDS_EDGE_TYPE NONE
#define HPS_FPGA_LEDS_FREQ 50000000
#define HPS_FPGA_LEDS_HAS_IN 0
#define HPS_FPGA_LEDS_HAS_OUT 1
#define HPS_FPGA_LEDS_HAS_TRI 0
#define HPS_FPGA_LEDS_IRQ_TYPE NONE
#define HPS_FPGA_LEDS_RESET_VALUE 0

/*
 * Macros for device 'fifo_control_rx_out', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_CONTROL_RX_OUT_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_CONTROL_RX_OUT_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_CONTROL_RX_OUT_COMPONENT_NAME fifo_control_rx
#define FIFO_CONTROL_RX_OUT_BASE 0x90
#define FIFO_CONTROL_RX_OUT_SPAN 2
#define FIFO_CONTROL_RX_OUT_END 0x91
#define FIFO_CONTROL_RX_OUT_AVALONMM_AVALONMM_DATA_WIDTH 16
#define FIFO_CONTROL_RX_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_CONTROL_RX_OUT_BITS_PER_SYMBOL 16
#define FIFO_CONTROL_RX_OUT_CHANNEL_WIDTH 8
#define FIFO_CONTROL_RX_OUT_ERROR_WIDTH 8
#define FIFO_CONTROL_RX_OUT_FIFO_DEPTH 8
#define FIFO_CONTROL_RX_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_CONTROL_RX_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_CONTROL_RX_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_CONTROL_RX_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_CONTROL_RX_OUT_USE_AVALONST_SINK 0
#define FIFO_CONTROL_RX_OUT_USE_AVALONST_SOURCE 0
#define FIFO_CONTROL_RX_OUT_USE_BACKPRESSURE 0
#define FIFO_CONTROL_RX_OUT_USE_IRQ 0
#define FIFO_CONTROL_RX_OUT_USE_PACKET 1
#define FIFO_CONTROL_RX_OUT_USE_READ_CONTROL 1
#define FIFO_CONTROL_RX_OUT_USE_REGISTER 0
#define FIFO_CONTROL_RX_OUT_USE_WRITE_CONTROL 1

/*
 * Macros for device 'fifo_control_tx_in', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_CONTROL_TX_IN_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_CONTROL_TX_IN_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_CONTROL_TX_IN_COMPONENT_NAME fifo_control_tx
#define FIFO_CONTROL_TX_IN_BASE 0x92
#define FIFO_CONTROL_TX_IN_SPAN 2
#define FIFO_CONTROL_TX_IN_END 0x93
#define FIFO_CONTROL_TX_IN_AVALONMM_AVALONMM_DATA_WIDTH 16
#define FIFO_CONTROL_TX_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_CONTROL_TX_IN_BITS_PER_SYMBOL 16
#define FIFO_CONTROL_TX_IN_CHANNEL_WIDTH 8
#define FIFO_CONTROL_TX_IN_ERROR_WIDTH 8
#define FIFO_CONTROL_TX_IN_FIFO_DEPTH 8
#define FIFO_CONTROL_TX_IN_SINGLE_CLOCK_MODE 0
#define FIFO_CONTROL_TX_IN_SYMBOLS_PER_BEAT 2
#define FIFO_CONTROL_TX_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_CONTROL_TX_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_CONTROL_TX_IN_USE_AVALONST_SINK 0
#define FIFO_CONTROL_TX_IN_USE_AVALONST_SOURCE 0
#define FIFO_CONTROL_TX_IN_USE_BACKPRESSURE 0
#define FIFO_CONTROL_TX_IN_USE_IRQ 0
#define FIFO_CONTROL_TX_IN_USE_PACKET 1
#define FIFO_CONTROL_TX_IN_USE_READ_CONTROL 1
#define FIFO_CONTROL_TX_IN_USE_REGISTER 0
#define FIFO_CONTROL_TX_IN_USE_WRITE_CONTROL 1


#endif /* _ALTERA_HPS_SOC_SYSTEM_H_ */