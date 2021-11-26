################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/Peripheral/Disp_OTM8009A.cpp \
C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/lib.cpp \
../Src/main.cpp 

OBJS += \
./Src/Disp_OTM8009A.o \
./Src/lib.o \
./Src/main.o 

CPP_DEPS += \
./Src/Disp_OTM8009A.d \
./Src/lib.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Disp_OTM8009A.o: C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/Peripheral/Disp_OTM8009A.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DSTM32 -DDISP_LCD -D_GCC -D_HSE_CLK=25000 -D_HSE_BYPASS_OFF -DSTM32F769xx -DSTM32F7 -DDEBUG -DSTM32F769NIHx -c -I../../EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC -I../Src -I../../EmbSysLib/Src/MCU/STM32F7xx -I../../EmbSysLib/Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/Disp_OTM8009A.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/lib.o: C:/Users/TIm\ Ludwig/Documents/GitHub/STM32-Touchscreen/workspace/EmbSysLib/Src/lib.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DSTM32 -DDISP_LCD -D_GCC -D_HSE_CLK=25000 -D_HSE_BYPASS_OFF -DSTM32F769xx -DSTM32F7 -DDEBUG -DSTM32F769NIHx -c -I../../EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC -I../Src -I../../EmbSysLib/Src/MCU/STM32F7xx -I../../EmbSysLib/Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Src/lib.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/%.o: ../Src/%.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DSTM32 -DDISP_LCD -D_GCC -D_HSE_CLK=25000 -D_HSE_BYPASS_OFF -DSTM32F769xx -DSTM32F7 -DDEBUG -DSTM32F769NIHx -c -I../../EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC -I../Src -I../../EmbSysLib/Src/MCU/STM32F7xx -I../../EmbSysLib/Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

