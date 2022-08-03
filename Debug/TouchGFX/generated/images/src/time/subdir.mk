################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/time/image_Down_arrow.cpp \
../TouchGFX/generated/images/src/time/image_Down_arrow_pressed.cpp \
../TouchGFX/generated/images/src/time/image_Up_arrow.cpp \
../TouchGFX/generated/images/src/time/image_Up_arrow_pressed.cpp \
../TouchGFX/generated/images/src/time/image_background_Screen1.cpp \
../TouchGFX/generated/images/src/time/image_background_Screen2.cpp \
../TouchGFX/generated/images/src/time/image_btn_round.cpp \
../TouchGFX/generated/images/src/time/image_btn_round_pressed.cpp \
../TouchGFX/generated/images/src/time/image_configuration.cpp 

OBJS += \
./TouchGFX/generated/images/src/time/image_Down_arrow.o \
./TouchGFX/generated/images/src/time/image_Down_arrow_pressed.o \
./TouchGFX/generated/images/src/time/image_Up_arrow.o \
./TouchGFX/generated/images/src/time/image_Up_arrow_pressed.o \
./TouchGFX/generated/images/src/time/image_background_Screen1.o \
./TouchGFX/generated/images/src/time/image_background_Screen2.o \
./TouchGFX/generated/images/src/time/image_btn_round.o \
./TouchGFX/generated/images/src/time/image_btn_round_pressed.o \
./TouchGFX/generated/images/src/time/image_configuration.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/time/image_Down_arrow.d \
./TouchGFX/generated/images/src/time/image_Down_arrow_pressed.d \
./TouchGFX/generated/images/src/time/image_Up_arrow.d \
./TouchGFX/generated/images/src/time/image_Up_arrow_pressed.d \
./TouchGFX/generated/images/src/time/image_background_Screen1.d \
./TouchGFX/generated/images/src/time/image_background_Screen2.d \
./TouchGFX/generated/images/src/time/image_btn_round.d \
./TouchGFX/generated/images/src/time/image_btn_round_pressed.d \
./TouchGFX/generated/images/src/time/image_configuration.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/time/%.o: ../TouchGFX/generated/images/src/time/%.cpp TouchGFX/generated/images/src/time/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/HP/Documents/GitHub/openh7/Core/Inc" -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-time

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-time:
	-$(RM) ./TouchGFX/generated/images/src/time/image_Down_arrow.d ./TouchGFX/generated/images/src/time/image_Down_arrow.o ./TouchGFX/generated/images/src/time/image_Down_arrow_pressed.d ./TouchGFX/generated/images/src/time/image_Down_arrow_pressed.o ./TouchGFX/generated/images/src/time/image_Up_arrow.d ./TouchGFX/generated/images/src/time/image_Up_arrow.o ./TouchGFX/generated/images/src/time/image_Up_arrow_pressed.d ./TouchGFX/generated/images/src/time/image_Up_arrow_pressed.o ./TouchGFX/generated/images/src/time/image_background_Screen1.d ./TouchGFX/generated/images/src/time/image_background_Screen1.o ./TouchGFX/generated/images/src/time/image_background_Screen2.d ./TouchGFX/generated/images/src/time/image_background_Screen2.o ./TouchGFX/generated/images/src/time/image_btn_round.d ./TouchGFX/generated/images/src/time/image_btn_round.o ./TouchGFX/generated/images/src/time/image_btn_round_pressed.d ./TouchGFX/generated/images/src/time/image_btn_round_pressed.o ./TouchGFX/generated/images/src/time/image_configuration.d ./TouchGFX/generated/images/src/time/image_configuration.o

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-time

