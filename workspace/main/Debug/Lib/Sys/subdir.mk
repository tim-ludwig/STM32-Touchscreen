################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/Sys/system_stm32l4xx.c 

OBJS += \
./Lib/Sys/system_stm32l4xx.o 

C_DEPS += \
./Lib/Sys/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/Sys/%.o: ../Lib/Sys/%.c Lib/Sys/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DSTM32L432xx -c -I./Src -I./Lib -I../Lib/Sys -I../Lib/Sys/GCC -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

