################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingPresenter.cpp \
../TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingView.cpp 

OBJS += \
./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingPresenter.o \
./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingView.o 

CPP_DEPS += \
./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingPresenter.d \
./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingView.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/timeanddatesetting_screen/%.o TouchGFX/gui/src/timeanddatesetting_screen/%.su: ../TouchGFX/gui/src/timeanddatesetting_screen/%.cpp TouchGFX/gui/src/timeanddatesetting_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-timeanddatesetting_screen

clean-TouchGFX-2f-gui-2f-src-2f-timeanddatesetting_screen:
	-$(RM) ./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingPresenter.d ./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingPresenter.o ./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingPresenter.su ./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingView.d ./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingView.o ./TouchGFX/gui/src/timeanddatesetting_screen/TimeAndDateSettingView.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-timeanddatesetting_screen

