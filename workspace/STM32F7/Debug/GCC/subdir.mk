################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC/RTOScontext.s \
C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC/startup_stm32f769nihx.s 

S_DEPS += \
./GCC/RTOScontext.d \
./GCC/startup_stm32f769nihx.d 

OBJS += \
./GCC/RTOScontext.o \
./GCC/startup_stm32f769nihx.o 


# Each subdirectory must supply rules for building sources it contributes
GCC/RTOScontext.o: C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC/RTOScontext.s GCC/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
GCC/startup_stm32f769nihx.o: C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC/startup_stm32f769nihx.s GCC/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-GCC

clean-GCC:
	-$(RM) ./GCC/RTOScontext.d ./GCC/RTOScontext.o ./GCC/startup_stm32f769nihx.d ./GCC/startup_stm32f769nihx.o

.PHONY: clean-GCC
