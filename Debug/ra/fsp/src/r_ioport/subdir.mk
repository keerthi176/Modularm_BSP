################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_ioport/r_ioport.c 

C_DEPS += \
./ra/fsp/src/r_ioport/r_ioport.d 

OBJS += \
./ra/fsp/src/r_ioport/r_ioport.o 

SREC += \
Modularm_BSP.srec 

MAP += \
Modularm_BSP.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_ioport/%.o: ../ra/fsp/src/r_ioport/%.c
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra_gen" -I"." -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra_cfg/fsp_cfg/bsp" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra_cfg/fsp_cfg" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra_cfg/aws" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/src" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra/fsp/inc" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra/fsp/inc/api" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra/fsp/inc/instances" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra/fsp/src/rm_freertos_port" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"D:/ModularmProject/E2_Studio_Workspace/Modularm_BSP_2/ra/arm/CMSIS_6/CMSIS/Core/Include" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

