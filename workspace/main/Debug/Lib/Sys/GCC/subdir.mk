################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Lib/Sys/GCC/startup_stm32l432kcux.s 

C_SRCS += \
../Lib/Sys/GCC/syscalls.c \
../Lib/Sys/GCC/sysmem.c 

OBJS += \
./Lib/Sys/GCC/startup_stm32l432kcux.o \
./Lib/Sys/GCC/syscalls.o \
./Lib/Sys/GCC/sysmem.o 

S_DEPS += \
./Lib/Sys/GCC/startup_stm32l432kcux.d 

C_DEPS += \
./Lib/Sys/GCC/syscalls.d \
./Lib/Sys/GCC/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/Sys/GCC/%.o: ../Lib/Sys/GCC/%.s Lib/Sys/GCC/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Lib/Sys/GCC/%.o: ../Lib/Sys/GCC/%.c Lib/Sys/GCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DSTM32L432xx -c -I./Src -I./Lib -I../Lib/Sys -I../Lib/Sys/GCC -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-Sys-2f-GCC

clean-Lib-2f-Sys-2f-GCC:
	-$(RM) ./Lib/Sys/GCC/startup_stm32l432kcux.d ./Lib/Sys/GCC/startup_stm32l432kcux.o ./Lib/Sys/GCC/syscalls.d ./Lib/Sys/GCC/syscalls.o ./Lib/Sys/GCC/sysmem.d ./Lib/Sys/GCC/sysmem.o

.PHONY: clean-Lib-2f-Sys-2f-GCC

