/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_NUM_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI2 RXI (Receive data full) */
            [1] = sci_uart_txi_isr, /* SCI2 TXI (Transmit data empty) */
            [2] = sci_uart_tei_isr, /* SCI2 TEI (Transmit end) */
            [3] = sci_uart_eri_isr, /* SCI2 ERI (Receive error) */
            [4] = sci_i2c_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [5] = sci_i2c_tei_isr, /* SCI0 TEI (Transmit end) */
            [6] = can_error_isr, /* CAN0 ERROR (Error interrupt) */
            [7] = can_rx_isr, /* CAN0 MAILBOX RX (Reception complete interrupt) */
            [8] = can_tx_isr, /* CAN0 MAILBOX TX (Transmission complete interrupt) */
            [9] = can_rx_isr, /* CAN0 FIFO RX (Receive FIFO interrupt) */
            [10] = can_tx_isr, /* CAN0 FIFO TX (Transmit FIFO interrupt) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_NUM_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_SCI2_RXI,GROUP0), /* SCI2 RXI (Receive data full) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_SCI2_TXI,GROUP1), /* SCI2 TXI (Transmit data empty) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_SCI2_TEI,GROUP2), /* SCI2 TEI (Transmit end) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_SCI2_ERI,GROUP3), /* SCI2 ERI (Receive error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TXI,GROUP4), /* SCI0 TXI (Transmit data empty) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TEI,GROUP5), /* SCI0 TEI (Transmit end) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_CAN0_ERROR,GROUP6), /* CAN0 ERROR (Error interrupt) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_CAN0_MAILBOX_RX,GROUP7), /* CAN0 MAILBOX RX (Reception complete interrupt) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_CAN0_MAILBOX_TX,GROUP0), /* CAN0 MAILBOX TX (Transmission complete interrupt) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_CAN0_FIFO_RX,GROUP1), /* CAN0 FIFO RX (Receive FIFO interrupt) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_CAN0_FIFO_TX,GROUP2), /* CAN0 FIFO TX (Transmit FIFO interrupt) */
        };
        #endif
        #endif
