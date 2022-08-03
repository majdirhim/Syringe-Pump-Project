################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/screenlogo/image_Groupe12.cpp \
../TouchGFX/generated/images/src/screenlogo/image_Groupe16.cpp \
../TouchGFX/generated/images/src/screenlogo/image_Groupe20.cpp \
../TouchGFX/generated/images/src/screenlogo/image_Groupe49.cpp \
../TouchGFX/generated/images/src/screenlogo/image_Tra107.cpp \
../TouchGFX/generated/images/src/screenlogo/image_Trace57.cpp \
../TouchGFX/generated/images/src/screenlogo/image_hiclipart.com.cpp \
../TouchGFX/generated/images/src/screenlogo/image_mini_Groupe12.cpp \
../TouchGFX/generated/images/src/screenlogo/image_mini_white-home-icon-142452.cpp \
../TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools.cpp \
../TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools1.cpp \
../TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools13.cpp \
../TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools14.cpp \
../TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools2.cpp \
../TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools3.cpp \
../TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools555.cpp \
../TouchGFX/generated/images/src/screenlogo/image_pngegg.cpp \
../TouchGFX/generated/images/src/screenlogo/image_white-home-icon-142452.cpp 

OBJS += \
./TouchGFX/generated/images/src/screenlogo/image_Groupe12.o \
./TouchGFX/generated/images/src/screenlogo/image_Groupe16.o \
./TouchGFX/generated/images/src/screenlogo/image_Groupe20.o \
./TouchGFX/generated/images/src/screenlogo/image_Groupe49.o \
./TouchGFX/generated/images/src/screenlogo/image_Tra107.o \
./TouchGFX/generated/images/src/screenlogo/image_Trace57.o \
./TouchGFX/generated/images/src/screenlogo/image_hiclipart.com.o \
./TouchGFX/generated/images/src/screenlogo/image_mini_Groupe12.o \
./TouchGFX/generated/images/src/screenlogo/image_mini_white-home-icon-142452.o \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools.o \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools1.o \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools13.o \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools14.o \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools2.o \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools3.o \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools555.o \
./TouchGFX/generated/images/src/screenlogo/image_pngegg.o \
./TouchGFX/generated/images/src/screenlogo/image_white-home-icon-142452.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/screenlogo/image_Groupe12.d \
./TouchGFX/generated/images/src/screenlogo/image_Groupe16.d \
./TouchGFX/generated/images/src/screenlogo/image_Groupe20.d \
./TouchGFX/generated/images/src/screenlogo/image_Groupe49.d \
./TouchGFX/generated/images/src/screenlogo/image_Tra107.d \
./TouchGFX/generated/images/src/screenlogo/image_Trace57.d \
./TouchGFX/generated/images/src/screenlogo/image_hiclipart.com.d \
./TouchGFX/generated/images/src/screenlogo/image_mini_Groupe12.d \
./TouchGFX/generated/images/src/screenlogo/image_mini_white-home-icon-142452.d \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools.d \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools1.d \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools13.d \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools14.d \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools2.d \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools3.d \
./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools555.d \
./TouchGFX/generated/images/src/screenlogo/image_pngegg.d \
./TouchGFX/generated/images/src/screenlogo/image_white-home-icon-142452.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/screenlogo/%.o: ../TouchGFX/generated/images/src/screenlogo/%.cpp TouchGFX/generated/images/src/screenlogo/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/HP/Documents/GitHub/openh7/Core/Inc" -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-screenlogo

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-screenlogo:
	-$(RM) ./TouchGFX/generated/images/src/screenlogo/image_Groupe12.d ./TouchGFX/generated/images/src/screenlogo/image_Groupe12.o ./TouchGFX/generated/images/src/screenlogo/image_Groupe16.d ./TouchGFX/generated/images/src/screenlogo/image_Groupe16.o ./TouchGFX/generated/images/src/screenlogo/image_Groupe20.d ./TouchGFX/generated/images/src/screenlogo/image_Groupe20.o ./TouchGFX/generated/images/src/screenlogo/image_Groupe49.d ./TouchGFX/generated/images/src/screenlogo/image_Groupe49.o ./TouchGFX/generated/images/src/screenlogo/image_Tra107.d ./TouchGFX/generated/images/src/screenlogo/image_Tra107.o ./TouchGFX/generated/images/src/screenlogo/image_Trace57.d ./TouchGFX/generated/images/src/screenlogo/image_Trace57.o ./TouchGFX/generated/images/src/screenlogo/image_hiclipart.com.d ./TouchGFX/generated/images/src/screenlogo/image_hiclipart.com.o ./TouchGFX/generated/images/src/screenlogo/image_mini_Groupe12.d ./TouchGFX/generated/images/src/screenlogo/image_mini_Groupe12.o ./TouchGFX/generated/images/src/screenlogo/image_mini_white-home-icon-142452.d ./TouchGFX/generated/images/src/screenlogo/image_mini_white-home-icon-142452.o ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools.d ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools.o ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools1.d ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools1.o ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools13.d ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools13.o ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools14.d ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools14.o ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools2.d ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools2.o ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools3.d ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools3.o ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools555.d ./TouchGFX/generated/images/src/screenlogo/image_output-onlinepngtools555.o ./TouchGFX/generated/images/src/screenlogo/image_pngegg.d ./TouchGFX/generated/images/src/screenlogo/image_pngegg.o ./TouchGFX/generated/images/src/screenlogo/image_white-home-icon-142452.d ./TouchGFX/generated/images/src/screenlogo/image_white-home-icon-142452.o

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-screenlogo

