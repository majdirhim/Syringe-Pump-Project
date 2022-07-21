################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BSP_SDRAM.c \
../Core/Src/DEV_Config.c \
../Core/Src/TS_I2C.c \
../Core/Src/adc.c \
../Core/Src/batt.c \
../Core/Src/crc.c \
../Core/Src/dma2d.c \
../Core/Src/fmc.c \
../Core/Src/freertos.c \
../Core/Src/ft5x06.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/l6474.c \
../Core/Src/ltdc.c \
../Core/Src/main.c \
../Core/Src/motorcontrol.c \
../Core/Src/quadspi.c \
../Core/Src/sdmmc.c \
../Core/Src/spi.c \
../Core/Src/stm32746g_qspi.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_hal_timebase_tim.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c \
../Core/Src/x_nucleo_ihm01a1_stm32f4xx.c 

C_DEPS += \
./Core/Src/BSP_SDRAM.d \
./Core/Src/DEV_Config.d \
./Core/Src/TS_I2C.d \
./Core/Src/adc.d \
./Core/Src/batt.d \
./Core/Src/crc.d \
./Core/Src/dma2d.d \
./Core/Src/fmc.d \
./Core/Src/freertos.d \
./Core/Src/ft5x06.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/l6474.d \
./Core/Src/ltdc.d \
./Core/Src/main.d \
./Core/Src/motorcontrol.d \
./Core/Src/quadspi.d \
./Core/Src/sdmmc.d \
./Core/Src/spi.d \
./Core/Src/stm32746g_qspi.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_hal_timebase_tim.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d \
./Core/Src/x_nucleo_ihm01a1_stm32f4xx.d 

OBJS += \
./Core/Src/BSP_SDRAM.o \
./Core/Src/DEV_Config.o \
./Core/Src/TS_I2C.o \
./Core/Src/adc.o \
./Core/Src/batt.o \
./Core/Src/crc.o \
./Core/Src/dma2d.o \
./Core/Src/fmc.o \
./Core/Src/freertos.o \
./Core/Src/ft5x06.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/l6474.o \
./Core/Src/ltdc.o \
./Core/Src/main.o \
./Core/Src/motorcontrol.o \
./Core/Src/quadspi.o \
./Core/Src/sdmmc.o \
./Core/Src/spi.o \
./Core/Src/stm32746g_qspi.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_hal_timebase_tim.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o \
./Core/Src/x_nucleo_ihm01a1_stm32f4xx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -include"D:/STM32CubeIDE_1.6.1/STM32CubeIDE/openh7/Core/Inc/ft5x06.h" -include"D:/STM32CubeIDE_1.6.1/STM32CubeIDE/openh7/Core/Inc/DEV_Config.h" -include"D:/STM32CubeIDE_1.6.1/STM32CubeIDE/openh7/Core/Inc/TS_I2C.h" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/BSP_SDRAM.d ./Core/Src/BSP_SDRAM.o ./Core/Src/BSP_SDRAM.su ./Core/Src/DEV_Config.d ./Core/Src/DEV_Config.o ./Core/Src/DEV_Config.su ./Core/Src/TS_I2C.d ./Core/Src/TS_I2C.o ./Core/Src/TS_I2C.su ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/batt.d ./Core/Src/batt.o ./Core/Src/batt.su ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/crc.su ./Core/Src/dma2d.d ./Core/Src/dma2d.o ./Core/Src/dma2d.su ./Core/Src/fmc.d ./Core/Src/fmc.o ./Core/Src/fmc.su ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/ft5x06.d ./Core/Src/ft5x06.o ./Core/Src/ft5x06.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/l6474.d ./Core/Src/l6474.o ./Core/Src/l6474.su ./Core/Src/ltdc.d ./Core/Src/ltdc.o ./Core/Src/ltdc.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/motorcontrol.d ./Core/Src/motorcontrol.o ./Core/Src/motorcontrol.su ./Core/Src/quadspi.d ./Core/Src/quadspi.o ./Core/Src/quadspi.su ./Core/Src/sdmmc.d ./Core/Src/sdmmc.o ./Core/Src/sdmmc.su ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32746g_qspi.d ./Core/Src/stm32746g_qspi.o ./Core/Src/stm32746g_qspi.su ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_hal_timebase_tim.d ./Core/Src/stm32h7xx_hal_timebase_tim.o ./Core/Src/stm32h7xx_hal_timebase_tim.su ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/x_nucleo_ihm01a1_stm32f4xx.d ./Core/Src/x_nucleo_ihm01a1_stm32f4xx.o ./Core/Src/x_nucleo_ihm01a1_stm32f4xx.su

.PHONY: clean-Core-2f-Src

