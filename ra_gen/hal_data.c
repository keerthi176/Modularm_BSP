/* generated HAL source file - do not edit */
#include "hal_data.h"
flash_hp_instance_ctrl_t g_flash0_ctrl;
const flash_cfg_t g_flash0_cfg =
{ .data_flash_bgo = true, .p_callback = rm_vee_flash_callback, .p_context = &g_vee0_ctrl,
#if defined(VECTOR_NUMBER_FCU_FRDYI)
    .irq                 = VECTOR_NUMBER_FCU_FRDYI,
#else
  .irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_FCU_FIFERR)
    .err_irq             = VECTOR_NUMBER_FCU_FIFERR,
#else
  .err_irq = FSP_INVALID_VECTOR,
#endif
  .err_ipl = (15),
  .ipl = (15), };
/* Instance structure to use this module. */
const flash_instance_t g_flash0 =
{ .p_ctrl = &g_flash0_ctrl, .p_cfg = &g_flash0_cfg, .p_api = &g_flash_on_flash_hp };
rm_vee_flash_instance_ctrl_t g_vee0_ctrl;

const rm_vee_flash_cfg_t g_vee0_cfg_ext =
{ .p_flash = &g_flash0 };

static uint16_t g_vee0_record_offset[16 + 1] =
{ 0 };

const rm_vee_cfg_t g_vee0_cfg =
{ .start_addr = BSP_FEATURE_FLASH_DATA_FLASH_START,
  .num_segments = 2,
  .total_size = BSP_DATA_FLASH_SIZE_BYTES,
  .ref_data_size = 0,
  .record_max_id = 16,
  .rec_offset = &g_vee0_record_offset[0],
  .p_callback = vee_callback,
  .p_context = NULL,
  .p_extend = &g_vee0_cfg_ext };

/* Instance structure to use this module. */
const rm_vee_instance_t g_vee0 =
{ .p_ctrl = &g_vee0_ctrl, .p_cfg = &g_vee0_cfg, .p_api = &g_rm_vee_on_flash };
rtc_instance_ctrl_t g_rtc0_ctrl;
const rtc_error_adjustment_cfg_t g_rtc0_err_cfg =
{ .adjustment_mode = RTC_ERROR_ADJUSTMENT_MODE_AUTOMATIC,
  .adjustment_period = RTC_ERROR_ADJUSTMENT_PERIOD_10_SECOND,
  .adjustment_type = RTC_ERROR_ADJUSTMENT_NONE,
  .adjustment_value = 0, };
const rtc_cfg_t g_rtc0_cfg =
{ .clock_source = RTC_CLOCK_SOURCE_LOCO,
  .freq_compare_value = 255,
  .p_err_cfg = &g_rtc0_err_cfg,
  .p_callback = NULL,
  .p_context = NULL,
  .p_extend = NULL,
  .alarm_ipl = (BSP_IRQ_DISABLED),
  .periodic_ipl = (BSP_IRQ_DISABLED),
  .carry_ipl = (12),
#if defined(VECTOR_NUMBER_RTC_ALARM)
    .alarm_irq               = VECTOR_NUMBER_RTC_ALARM,
#else
  .alarm_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_PERIOD)
    .periodic_irq            = VECTOR_NUMBER_RTC_PERIOD,
#else
  .periodic_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_RTC_CARRY)
    .carry_irq               = VECTOR_NUMBER_RTC_CARRY,
#else
  .carry_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const rtc_instance_t g_rtc0 =
{ .p_ctrl = &g_rtc0_ctrl, .p_cfg = &g_rtc0_cfg, .p_api = &g_rtc_on_rtc };
void g_hal_init(void)
{
    g_common_init ();
}
