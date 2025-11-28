################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_flash_hp/r_flash_hp.c 

C_DEPS += \
./ra/fsp/src/r_flash_hp/r_flash_hp.d 

OBJS += \
./ra/fsp/src/r_flash_hp/r_flash_hp.o 

SREC += \
Modularm_BSP.srec 

MAP += \
Modularm_BSP.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_flash_hp/%.o: ../ra/fsp/src/r_flash_hp/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra_gen" -I"." -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra_cfg/fsp_cfg/bsp" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra_cfg/fsp_cfg" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra_cfg/aws" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/src" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra/fsp/inc" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra/fsp/inc/api" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra/fsp/inc/instances" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra/fsp/src/rm_freertos_port" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"D:/ModularmProject/Modularm_new_repo/Modularm_BSP/ra/arm/CMSIS_6/CMSIS/Core/Include" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

