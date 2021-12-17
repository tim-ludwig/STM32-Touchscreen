################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/touchlib/components/Component.cpp \
../Src/touchlib/components/Slider.cpp \
../Src/touchlib/components/TicTacToeGame.cpp 

OBJS += \
./Src/touchlib/components/Component.o \
./Src/touchlib/components/Slider.o \
./Src/touchlib/components/TicTacToeGame.o 

CPP_DEPS += \
./Src/touchlib/components/Component.d \
./Src/touchlib/components/Slider.d \
./Src/touchlib/components/TicTacToeGame.d 


# Each subdirectory must supply rules for building sources it contributes
Src/touchlib/components/%.o: ../Src/touchlib/components/%.cpp Src/touchlib/components/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DSTM32 -DDISP_LCD -D_GCC -D_HSE_CLK=25000 -D_HSE_BYPASS_OFF -DSTM32F769xx -DSTM32F7 -DDEBUG -DSTM32F769NIHx -c -I../../EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC -I../Src -I../../EmbSysLib/Src/MCU/STM32F7xx -I../../EmbSysLib/Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-touchlib-2f-components

clean-Src-2f-touchlib-2f-components:
	-$(RM) ./Src/touchlib/components/Component.d ./Src/touchlib/components/Component.o ./Src/touchlib/components/Slider.d ./Src/touchlib/components/Slider.o ./Src/touchlib/components/TicTacToeGame.d ./Src/touchlib/components/TicTacToeGame.o

.PHONY: clean-Src-2f-touchlib-2f-components

