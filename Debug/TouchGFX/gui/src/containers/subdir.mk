################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/containers/ActiveAlarms.cpp \
../TouchGFX/gui/src/containers/LogDisplay.cpp \
../TouchGFX/gui/src/containers/ScreenBorder.cpp \
../TouchGFX/gui/src/containers/Slide.cpp \
../TouchGFX/gui/src/containers/textbubble.cpp 

OBJS += \
./TouchGFX/gui/src/containers/ActiveAlarms.o \
./TouchGFX/gui/src/containers/LogDisplay.o \
./TouchGFX/gui/src/containers/ScreenBorder.o \
./TouchGFX/gui/src/containers/Slide.o \
./TouchGFX/gui/src/containers/textbubble.o 

CPP_DEPS += \
./TouchGFX/gui/src/containers/ActiveAlarms.d \
./TouchGFX/gui/src/containers/LogDisplay.d \
./TouchGFX/gui/src/containers/ScreenBorder.d \
./TouchGFX/gui/src/containers/Slide.d \
./TouchGFX/gui/src/containers/textbubble.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/containers/%.o TouchGFX/gui/src/containers/%.su: ../TouchGFX/gui/src/containers/%.cpp TouchGFX/gui/src/containers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-containers

clean-TouchGFX-2f-gui-2f-src-2f-containers:
	-$(RM) ./TouchGFX/gui/src/containers/ActiveAlarms.d ./TouchGFX/gui/src/containers/ActiveAlarms.o ./TouchGFX/gui/src/containers/ActiveAlarms.su ./TouchGFX/gui/src/containers/LogDisplay.d ./TouchGFX/gui/src/containers/LogDisplay.o ./TouchGFX/gui/src/containers/LogDisplay.su ./TouchGFX/gui/src/containers/ScreenBorder.d ./TouchGFX/gui/src/containers/ScreenBorder.o ./TouchGFX/gui/src/containers/ScreenBorder.su ./TouchGFX/gui/src/containers/Slide.d ./TouchGFX/gui/src/containers/Slide.o ./TouchGFX/gui/src/containers/Slide.su ./TouchGFX/gui/src/containers/textbubble.d ./TouchGFX/gui/src/containers/textbubble.o ./TouchGFX/gui/src/containers/textbubble.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-containers

