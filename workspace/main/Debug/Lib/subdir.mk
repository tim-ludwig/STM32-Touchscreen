################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/nucleoPin.c \
../Lib/port.c \
../Lib/timer.c \
../Lib/uart.c 

OBJS += \
./Lib/nucleoPin.o \
./Lib/port.o \
./Lib/timer.o \
./Lib/uart.o 

C_DEPS += \
./Lib/nucleoPin.d \
./Lib/port.d \
./Lib/timer.d \
./Lib/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/%.o: ../Lib/%.c Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DSTM32L432xx -c -I./Src -I./Lib -I../Lib/Sys -I../Lib/Sys/GCC -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib

clean-Lib:
	-$(RM) ./Lib/nucleoPin.d ./Lib/nucleoPin.o ./Lib/port.d ./Lib/port.o ./Lib/timer.d ./Lib/timer.o ./Lib/uart.d ./Lib/uart.o

.PHONY: clean-Lib

