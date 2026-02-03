/* generated common source file - do not edit */
#include "common_data.h"
icu_instance_ctrl_t motion_detection_ctrl;

/** External IRQ extended configuration for ICU HAL driver */
const icu_extended_cfg_t motion_detection_ext_cfg = { .filter_src =
		EXTERNAL_IRQ_DIGITAL_FILTER_PCLK_DIV, };

const external_irq_cfg_t motion_detection_cfg = { .channel = 11, .trigger =
		EXTERNAL_IRQ_TRIG_BOTH_EDGE, .filter_enable = false, .clock_source_div =
		EXTERNAL_IRQ_CLOCK_SOURCE_DIV_64, .p_callback =
		motion_detection_irq_callback,
/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = (void*) &NULL,
#endif
		.p_extend = (void*) &motion_detection_ext_cfg, .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ11)
    .irq                 = VECTOR_NUMBER_ICU_IRQ11,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const external_irq_instance_t motion_detection = { .p_ctrl =
		&motion_detection_ctrl, .p_cfg = &motion_detection_cfg, .p_api =
		&g_external_irq_on_icu };
icu_instance_ctrl_t door_snesor_interrupt_ctrl;

/** External IRQ extended configuration for ICU HAL driver */
const icu_extended_cfg_t door_snesor_interrupt_ext_cfg = { .filter_src =
		EXTERNAL_IRQ_DIGITAL_FILTER_PCLK_DIV, };

const external_irq_cfg_t door_snesor_interrupt_cfg = { .channel = 1, .trigger =
		EXTERNAL_IRQ_TRIG_BOTH_EDGE, .filter_enable = false, .clock_source_div =
		EXTERNAL_IRQ_CLOCK_SOURCE_DIV_64,
		.p_callback = door_sensor_irq_callback,
		/** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
		.p_context = (void*) &NULL,
#endif
		.p_extend = (void*) &door_snesor_interrupt_ext_cfg, .ipl = (12),
#if defined(VECTOR_NUMBER_ICU_IRQ1)
    .irq                 = VECTOR_NUMBER_ICU_IRQ1,
#else
		.irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const external_irq_instance_t door_snesor_interrupt = { .p_ctrl =
		&door_snesor_interrupt_ctrl, .p_cfg = &door_snesor_interrupt_cfg,
		.p_api = &g_external_irq_on_icu };
ioport_instance_ctrl_t g_ioport_ctrl;
const ioport_instance_t g_ioport = { .p_api = &g_ioport_on_ioport, .p_ctrl =
		&g_ioport_ctrl, .p_cfg = &g_bsp_pin_cfg, };
void g_common_init(void) {
}
