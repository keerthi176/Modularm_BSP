################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/RS232_Thread.c \
../ra_gen/common_data.c \
../ra_gen/eeprom_thread.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/pin_data.c \
../ra_gen/rtc_thread.c \
../ra_gen/vector_data.c 

C_DEPS += \
./ra_gen/RS232_Thread.d \
./ra_gen/common_data.d \
./ra_gen/eeprom_thread.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/pin_data.d \
./ra_gen/rtc_thread.d \
./ra_gen/vector_data.d 

CREF += \
Modularm_SIB_H_BSP.cref 

OBJS += \
./ra_gen/RS232_Thread.o \
./ra_gen/common_data.o \
./ra_gen/eeprom_thread.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/pin_data.o \
./ra_gen/rtc_thread.o \
./ra_gen/vector_data.o 

MAP += \
Modularm_SIB_H_BSP.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -fshort-enums -fno-unroll-loops -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra_gen" -I"." -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra_cfg\\fsp_cfg" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra_cfg\\aws" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\src" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra\\fsp\\inc" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra\\fsp\\inc\\api" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra\\fsp\\inc\\instances" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra\\fsp\\src\\rm_freertos_port" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\Modularm_SIB_H_BSP\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

