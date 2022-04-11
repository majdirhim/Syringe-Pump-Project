################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/containers/ActiveAlarmsBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/LogDisplayBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/ScreenBorderBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/SlideBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/textbubbleBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/containers/ActiveAlarmsBase.o \
./TouchGFX/generated/gui_generated/src/containers/LogDisplayBase.o \
./TouchGFX/generated/gui_generated/src/containers/ScreenBorderBase.o \
./TouchGFX/generated/gui_generated/src/containers/SlideBase.o \
./TouchGFX/generated/gui_generated/src/containers/textbubbleBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/containers/ActiveAlarmsBase.d \
./TouchGFX/generated/gui_generated/src/containers/LogDisplayBase.d \
./TouchGFX/generated/gui_generated/src/containers/ScreenBorderBase.d \
./TouchGFX/generated/gui_generated/src/containers/SlideBase.d \
./TouchGFX/generated/gui_generated/src/containers/textbubbleBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/containers/%.o TouchGFX/generated/gui_generated/src/containers/%.su: ../TouchGFX/generated/gui_generated/src/containers/%.cpp TouchGFX/generated/gui_generated/src/containers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers:
	-$(RM) ./TouchGFX/generated/gui_generated/src/containers/ActiveAlarmsBase.d ./TouchGFX/generated/gui_generated/src/containers/ActiveAlarmsBase.o ./TouchGFX/generated/gui_generated/src/containers/ActiveAlarmsBase.su ./TouchGFX/generated/gui_generated/src/containers/LogDisplayBase.d ./TouchGFX/generated/gui_generated/src/containers/LogDisplayBase.o ./TouchGFX/generated/gui_generated/src/containers/LogDisplayBase.su ./TouchGFX/generated/gui_generated/src/containers/ScreenBorderBase.d ./TouchGFX/generated/gui_generated/src/containers/ScreenBorderBase.o ./TouchGFX/generated/gui_generated/src/containers/ScreenBorderBase.su ./TouchGFX/generated/gui_generated/src/containers/SlideBase.d ./TouchGFX/generated/gui_generated/src/containers/SlideBase.o ./TouchGFX/generated/gui_generated/src/containers/SlideBase.su ./TouchGFX/generated/gui_generated/src/containers/textbubbleBase.d ./TouchGFX/generated/gui_generated/src/containers/textbubbleBase.o ./TouchGFX/generated/gui_generated/src/containers/textbubbleBase.su

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

