################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/can_thread_entry.c \
../src/hal_warmstart.c \
../src/uart_thread_entry.c 

C_DEPS += \
./src/can_thread_entry.d \
./src/hal_warmstart.d \
./src/uart_thread_entry.d 

CREF += \
Modualrm_BSP.cref 

OBJS += \
./src/can_thread_entry.o \
./src/hal_warmstart.o \
./src/uart_thread_entry.o 

MAP += \
Modualrm_BSP.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -fshort-enums -fno-unroll-loops -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_gen" -I"." -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_cfg\\fsp_cfg" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_cfg\\aws" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\src" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\inc" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\inc\\api" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\inc\\instances" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\src\\rm_freertos_port" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

