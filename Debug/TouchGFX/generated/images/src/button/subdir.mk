################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/button/image_btn.cpp \
../TouchGFX/generated/images/src/button/image_btn_pressed.cpp 

OBJS += \
./TouchGFX/generated/images/src/button/image_btn.o \
./TouchGFX/generated/images/src/button/image_btn_pressed.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/button/image_btn.d \
./TouchGFX/generated/images/src/button/image_btn_pressed.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/button/%.o TouchGFX/generated/images/src/button/%.su: ../TouchGFX/generated/images/src/button/%.cpp TouchGFX/generated/images/src/button/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/STM32CubeIDE_1.6.1/STM32CubeIDE/openh7/Core/Inc" -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-button

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-button:
	-$(RM) ./TouchGFX/generated/images/src/button/image_btn.d ./TouchGFX/generated/images/src/button/image_btn.o ./TouchGFX/generated/images/src/button/image_btn.su ./TouchGFX/generated/images/src/button/image_btn_pressed.d ./TouchGFX/generated/images/src/button/image_btn_pressed.o ./TouchGFX/generated/images/src/button/image_btn_pressed.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-button

