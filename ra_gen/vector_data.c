/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_NUM_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = rtc_carry_isr, /* RTC CARRY (Carry interrupt) */
            [1] = fcu_frdyi_isr, /* FCU FRDYI (Flash ready interrupt) */
            [2] = fcu_fiferr_isr, /* FCU FIFERR (Flash access error interrupt) */
            [3] = canfd_error_isr, /* CAN0 CHERR (Channel  error) */
            [4] = canfd_channel_tx_isr, /* CAN0 TX (Transmit interrupt) */
            [5] = canfd_common_fifo_rx_isr, /* CAN0 COMFRX (Common FIFO receive interrupt) */
            [6] = canfd_error_isr, /* CAN GLERR (Global error) */
            [7] = canfd_rx_fifo_isr, /* CAN RXF (Global receive FIFO interrupt) */
            [8] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [9] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [10] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [11] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [12] = iic_master_rxi_isr, /* IIC0 RXI (Receive data full) */
            [13] = iic_master_txi_isr, /* IIC0 TXI (Transmit data empty) */
            [14] = iic_master_tei_isr, /* IIC0 TEI (Transmit end) */
            [15] = iic_master_eri_isr, /* IIC0 ERI (Transfer error) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_NUM_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_RTC_CARRY,GROUP0), /* RTC CARRY (Carry interrupt) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_FCU_FRDYI,GROUP1), /* FCU FRDYI (Flash ready interrupt) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_FCU_FIFERR,GROUP2), /* FCU FIFERR (Flash access error interrupt) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_CAN0_CHERR,GROUP3), /* CAN0 CHERR (Channel  error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_CAN0_TX,GROUP4), /* CAN0 TX (Transmit interrupt) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_CAN0_COMFRX,GROUP5), /* CAN0 COMFRX (Common FIFO receive interrupt) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_CAN_GLERR,GROUP6), /* CAN GLERR (Global error) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_CAN_RXF,GROUP7), /* CAN RXF (Global receive FIFO interrupt) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_SCI0_RXI,GROUP0), /* SCI0 RXI (Receive data full) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TXI,GROUP1), /* SCI0 TXI (Transmit data empty) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_SCI0_TEI,GROUP2), /* SCI0 TEI (Transmit end) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_SCI0_ERI,GROUP3), /* SCI0 ERI (Receive error) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_IIC0_RXI,GROUP4), /* IIC0 RXI (Receive data full) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_IIC0_TXI,GROUP5), /* IIC0 TXI (Transmit data empty) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_IIC0_TEI,GROUP6), /* IIC0 TEI (Transmit end) */
            [15] = BSP_PRV_VECT_ENUM(EVENT_IIC0_ERI,GROUP7), /* IIC0 ERI (Transfer error) */
        };
        #endif
        #endif
