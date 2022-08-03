################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/gui_generated/src/containers/AlarmlistBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/CustomContainer1Base.cpp \
../TouchGFX/generated/gui_generated/src/containers/Settings__screenBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_AlertBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_DepartmentBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_Display_ModeBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_Dury_LibraryBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_HistoryBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_LanguageBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_ManualBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_Time_DateBase.cpp \
../TouchGFX/generated/gui_generated/src/containers/popup_auto_diagnosticBase.cpp 

OBJS += \
./TouchGFX/generated/gui_generated/src/containers/AlarmlistBase.o \
./TouchGFX/generated/gui_generated/src/containers/CustomContainer1Base.o \
./TouchGFX/generated/gui_generated/src/containers/Settings__screenBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_AlertBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_DepartmentBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_Display_ModeBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_Dury_LibraryBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_HistoryBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_LanguageBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_ManualBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_Time_DateBase.o \
./TouchGFX/generated/gui_generated/src/containers/popup_auto_diagnosticBase.o 

CPP_DEPS += \
./TouchGFX/generated/gui_generated/src/containers/AlarmlistBase.d \
./TouchGFX/generated/gui_generated/src/containers/CustomContainer1Base.d \
./TouchGFX/generated/gui_generated/src/containers/Settings__screenBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_AlertBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_DepartmentBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_Display_ModeBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_Dury_LibraryBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_HistoryBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_LanguageBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_ManualBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_Time_DateBase.d \
./TouchGFX/generated/gui_generated/src/containers/popup_auto_diagnosticBase.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/gui_generated/src/containers/%.o: ../TouchGFX/generated/gui_generated/src/containers/%.cpp TouchGFX/generated/gui_generated/src/containers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/HP/Documents/GitHub/openh7/Core/Inc" -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers:
	-$(RM) ./TouchGFX/generated/gui_generated/src/containers/AlarmlistBase.d ./TouchGFX/generated/gui_generated/src/containers/AlarmlistBase.o ./TouchGFX/generated/gui_generated/src/containers/CustomContainer1Base.d ./TouchGFX/generated/gui_generated/src/containers/CustomContainer1Base.o ./TouchGFX/generated/gui_generated/src/containers/Settings__screenBase.d ./TouchGFX/generated/gui_generated/src/containers/Settings__screenBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_AlertBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_AlertBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_DepartmentBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_DepartmentBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_Display_ModeBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_Display_ModeBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_Dury_LibraryBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_Dury_LibraryBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_HistoryBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_HistoryBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_LanguageBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_LanguageBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_ManualBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_ManualBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_Time_DateBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_Time_DateBase.o ./TouchGFX/generated/gui_generated/src/containers/popup_auto_diagnosticBase.d ./TouchGFX/generated/gui_generated/src/containers/popup_auto_diagnosticBase.o

.PHONY: clean-TouchGFX-2f-generated-2f-gui_generated-2f-src-2f-containers

