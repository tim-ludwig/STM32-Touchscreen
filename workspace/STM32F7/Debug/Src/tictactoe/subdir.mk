################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/tictactoe/TicTacToe.cpp 

OBJS += \
./Src/tictactoe/TicTacToe.o 

CPP_DEPS += \
./Src/tictactoe/TicTacToe.d 


# Each subdirectory must supply rules for building sources it contributes
Src/tictactoe/%.o: ../Src/tictactoe/%.cpp Src/tictactoe/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DSTM32 -DDISP_LCD -D_GCC -D_HSE_CLK=25000 -D_HSE_BYPASS_OFF -DSTM32F769xx -DSTM32F7 -DDEBUG -DSTM32F769NIHx -c -I../../EmbSysLib/Src/MCU/STM32F7xx/Sys/GCC -I../Src -I../../EmbSysLib/Src/MCU/STM32F7xx -I../../EmbSysLib/Src -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-tictactoe

clean-Src-2f-tictactoe:
	-$(RM) ./Src/tictactoe/TicTacToe.d ./Src/tictactoe/TicTacToe.o

.PHONY: clean-Src-2f-tictactoe

