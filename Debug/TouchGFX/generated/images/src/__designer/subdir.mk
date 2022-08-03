################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Square_large_pressed.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Icons_Remove_48.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_highlight.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_normal.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Indicators_Slider_Round_nob.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_back.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_fill.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_OFF.cpp \
../TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_ON.cpp 

OBJS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Square_large_pressed.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Icons_Remove_48.o \
./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_highlight.o \
./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_normal.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Indicators_Slider_Round_nob.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_back.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_fill.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_OFF.o \
./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_ON.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Square_large_pressed.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Icons_Remove_48.d \
./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_highlight.d \
./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_normal.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Indicators_Slider_Round_nob.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_back.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_fill.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_OFF.d \
./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_ON.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/__designer/%.o TouchGFX/generated/images/src/__designer/%.su: ../TouchGFX/generated/images/src/__designer/%.cpp TouchGFX/generated/images/src/__designer/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/STM32CubeIDE_1.6.1/STM32CubeIDE/openh7/Core/Inc" -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer:
	-$(RM) ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_Edge_medium_pressed.su ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button.su ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Round_icon_button_pressed.su ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Square_large_pressed.d ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Square_large_pressed.o ./TouchGFX/generated/images/src/__designer/image_Blue_Buttons_Square_large_pressed.su ./TouchGFX/generated/images/src/__designer/image_Blue_Icons_Remove_48.d ./TouchGFX/generated/images/src/__designer/image_Blue_Icons_Remove_48.o ./TouchGFX/generated/images/src/__designer/image_Blue_Icons_Remove_48.su ./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_highlight.d ./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_highlight.o ./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_highlight.su ./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_normal.d ./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_normal.o ./TouchGFX/generated/images/src/__designer/image_Blue_PageIndicator_dot_indicator_small_normal.su ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Indicators_Slider_Round_nob.d ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Indicators_Slider_Round_nob.o ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Indicators_Slider_Round_nob.su ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_back.d ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_back.o ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_back.su ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_fill.d ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_fill.o ./TouchGFX/generated/images/src/__designer/image_Blue_Slider_Horizontal_Medium_Slider_Round_fill.su ./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_OFF.d ./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_OFF.o ./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_OFF.su ./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_ON.d ./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_ON.o ./TouchGFX/generated/images/src/__designer/image_Blue_Togglebars_Toggle_round_large_button_ON.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-__designer

