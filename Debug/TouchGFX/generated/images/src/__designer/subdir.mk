################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__designer/image_Blue_Backgrounds_Main_bg_800x480px.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.cpp \
../TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small.cpp \
../TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small_pressed.cpp \
../TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_highlight.cpp \
../TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_normal.cpp 

OBJS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Backgrounds_Main_bg_800x480px.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.o \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small.o \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small_pressed.o \
./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_highlight.o \
./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_normal.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Backgrounds_Main_bg_800x480px.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.d \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small.d \
./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small_pressed.d \
./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_highlight.d \
./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_normal.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__designer/%.o TouchGFX/generated/images/src/__designer/%.su: ../TouchGFX/generated/images/src/__designer/%.cpp TouchGFX/generated/images/src/__designer/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer:
	-$(RM) ./TouchGFX/generated/images/src/__designer/image_Blue_Backgrounds_Main_bg_800x480px.d ./TouchGFX/generated/images/src/__designer/image_Blue_Backgrounds_Main_bg_800x480px.o ./TouchGFX/generated/images/src/__designer/image_Blue_Backgrounds_Main_bg_800x480px.su ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.su ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small.d ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small.o ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small.su ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small_pressed.d ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small_pressed.o ./TouchGFX/generated/images/src/__designer/image_Dark_Buttons_Round_Edge_small_pressed.su ./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_highlight.d ./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_highlight.o ./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_highlight.su ./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_normal.d ./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_normal.o ./TouchGFX/generated/images/src/__designer/image_Dark_PageIndicator_dot_indicator_small_normal.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer

