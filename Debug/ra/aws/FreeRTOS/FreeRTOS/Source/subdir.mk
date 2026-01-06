################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/aws/FreeRTOS/FreeRTOS/Source/event_groups.c \
../ra/aws/FreeRTOS/FreeRTOS/Source/list.c \
../ra/aws/FreeRTOS/FreeRTOS/Source/queue.c \
../ra/aws/FreeRTOS/FreeRTOS/Source/stream_buffer.c \
../ra/aws/FreeRTOS/FreeRTOS/Source/tasks.c \
../ra/aws/FreeRTOS/FreeRTOS/Source/timers.c 

C_DEPS += \
./ra/aws/FreeRTOS/FreeRTOS/Source/event_groups.d \
./ra/aws/FreeRTOS/FreeRTOS/Source/list.d \
./ra/aws/FreeRTOS/FreeRTOS/Source/queue.d \
./ra/aws/FreeRTOS/FreeRTOS/Source/stream_buffer.d \
./ra/aws/FreeRTOS/FreeRTOS/Source/tasks.d \
./ra/aws/FreeRTOS/FreeRTOS/Source/timers.d 

CREF += \
Modualrm_BSP.cref 

OBJS += \
./ra/aws/FreeRTOS/FreeRTOS/Source/event_groups.o \
./ra/aws/FreeRTOS/FreeRTOS/Source/list.o \
./ra/aws/FreeRTOS/FreeRTOS/Source/queue.o \
./ra/aws/FreeRTOS/FreeRTOS/Source/stream_buffer.o \
./ra/aws/FreeRTOS/FreeRTOS/Source/tasks.o \
./ra/aws/FreeRTOS/FreeRTOS/Source/timers.o 

MAP += \
Modualrm_BSP.map 


# Each subdirectory must supply rules for building sources it contributes
ra/aws/FreeRTOS/FreeRTOS/Source/%.o: ../ra/aws/FreeRTOS/FreeRTOS/Source/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O2 -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -fshort-enums -fno-unroll-loops -w -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_gen" -I"." -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_cfg\\fsp_cfg\\bsp" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_cfg\\fsp_cfg" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra_cfg\\aws" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\src" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\inc" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\inc\\api" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\inc\\instances" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\fsp\\src\\rm_freertos_port" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"D:\\ModularmProject\\Technosoft_Repo2\\KB_Bringup_project_repo\\KB_BringUpProject\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

