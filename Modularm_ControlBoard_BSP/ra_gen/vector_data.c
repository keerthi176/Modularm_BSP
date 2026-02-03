/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_NUM_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = iic_master_rxi_isr, /* IIC2 RXI (Receive data full) */
            [1] = iic_master_txi_isr, /* IIC2 TXI (Transmit data empty) */
            [2] = iic_master_tei_isr, /* IIC2 TEI (Transmit end) */
            [3] = iic_master_eri_isr, /* IIC2 ERI (Transfer error) */
            [4] = adc_scan_end_isr, /* ADC0 SCAN END (End of A/D scanning operation) */
            [5] = canfd_error_isr, /* CAN1 CHERR (Channel  error) */
            [6] = canfd_channel_tx_isr, /* CAN1 TX (Transmit interrupt) */
            [7] = canfd_common_fifo_rx_isr, /* CAN1 COMFRX (Common FIFO receive interrupt) */
            [8] = canfd_error_isr, /* CAN GLERR (Global error) */
            [9] = canfd_rx_fifo_isr, /* CAN RXF (Global receive FIFO interrupt) */
            [10] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [11] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [12] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [13] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [14] = sci_uart_rxi_isr, /* SCI5 RXI (Receive data full) */
            [15] = sci_uart_txi_isr, /* SCI5 TXI (Transmit data empty) */
            [16] = sci_uart_tei_isr, /* SCI5 TEI (Transmit end) */
            [17] = sci_uart_eri_isr, /* SCI5 ERI (Receive error) */
            [18] = r_icu_isr, /* ICU IRQ1 (External pin interrupt 1) */
            [19] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_NUM_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_IIC2_RXI,GROUP0), /* IIC2 RXI (Receive data full) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_IIC2_TXI,GROUP1), /* IIC2 TXI (Transmit data empty) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_IIC2_TEI,GROUP2), /* IIC2 TEI (Transmit end) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_IIC2_ERI,GROUP3), /* IIC2 ERI (Transfer error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_ADC0_SCAN_END,GROUP4), /* ADC0 SCAN END (End of A/D scanning operation) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_CAN1_CHERR,GROUP5), /* CAN1 CHERR (Channel  error) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_CAN1_TX,GROUP6), /* CAN1 TX (Transmit interrupt) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_CAN1_COMFRX,GROUP7), /* CAN1 COMFRX (Common FIFO receive interrupt) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_CAN_GLERR,GROUP0), /* CAN GLERR (Global error) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_CAN_RXF,GROUP1), /* CAN RXF (Global receive FIFO interrupt) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_SCI0_RXI,GROUP2), /* SCI0 RXI (Receive data full) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TXI,GROUP3), /* SCI0 TXI (Transmit data empty) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TEI,GROUP4), /* SCI0 TEI (Transmit end) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_SCI0_ERI,GROUP5), /* SCI0 ERI (Receive error) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_SCI5_RXI,GROUP6), /* SCI5 RXI (Receive data full) */
            [15] = BSP_PRV_VECT_ENUM(EVENT_SCI5_TXI,GROUP7), /* SCI5 TXI (Transmit data empty) */
            [16] = BSP_PRV_VECT_ENUM(EVENT_SCI5_TEI,GROUP0), /* SCI5 TEI (Transmit end) */
            [17] = BSP_PRV_VECT_ENUM(EVENT_SCI5_ERI,GROUP1), /* SCI5 ERI (Receive error) */
            [18] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ1,GROUP2), /* ICU IRQ1 (External pin interrupt 1) */
            [19] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ11,GROUP3), /* ICU IRQ11 (External pin interrupt 11) */
        };
        #endif
        #endif
