################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

ELF_SRCS := 
C_UPPER_SRCS := 
CXX_SRCS := 
C++_SRCS := 
OBJ_SRCS := 
S_SRCS := 
CC_SRCS := 
C_SRCS := 
CPP_SRCS := 
S_UPPER_SRCS := 
O_SRCS := 
OBJDUMP_LIST := 
C_UPPER_DEPS := 
S_DEPS := 
C_DEPS := 
CC_DEPS := 
SIZE_OUTPUT := 
C++_DEPS := 
SU_FILES := 
EXECUTABLES := 
OBJS := 
CXX_DEPS := 
MAP_FILES := 
S_UPPER_DEPS := 
CPP_DEPS := 

# Every subdirectory with source files must be described here
SUBDIRS := \
Core/Src \
Core/Startup \
Drivers/STM32H7xx_HAL_Driver/Src \
FATFS/App \
FATFS/Target \
Middlewares/Third_Party/FatFs/src \
Middlewares/Third_Party/FatFs/src/option \
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 \
Middlewares/Third_Party/FreeRTOS/Source \
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F \
Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang \
TouchGFX/App \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/battery_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/containers \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/intro_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/lockscreen_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/oclusion_level_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/screenselectdrug_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/settings__screen_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/startup_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/alarmlist_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/battery_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/common \
TouchGFX/build/MINGW32_NT-6.2/gui/src/containers \
TouchGFX/build/MINGW32_NT-6.2/gui/src/departement_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/druglibrary_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/functiongeneration_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/genderchoice_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/intro_1_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/intro_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/keyboardnb_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/lockscreen_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/logscreen_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/mainscreen_withstart_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/maintenance_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/manual_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/new_paitent_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/oclusion_level_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/same_patient_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/screenkeyboard_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/screenselectdrug_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/settings__screen_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/settings_time_date_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/specialmode_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/startup_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/syringedetected_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/testversion_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/timeparam_screen \
TouchGFX/generated/fonts/src \
TouchGFX/generated/gui_generated/src/alarmlist_screen \
TouchGFX/generated/gui_generated/src/battery_screen \
TouchGFX/generated/gui_generated/src/common \
TouchGFX/generated/gui_generated/src/containers \
TouchGFX/generated/gui_generated/src/departement_screen \
TouchGFX/generated/gui_generated/src/druglibrary_screen \
TouchGFX/generated/gui_generated/src/functiongeneration_screen \
TouchGFX/generated/gui_generated/src/genderchoice_screen \
TouchGFX/generated/gui_generated/src/intro_1_screen \
TouchGFX/generated/gui_generated/src/intro_screen \
TouchGFX/generated/gui_generated/src/keyboardnb_screen \
TouchGFX/generated/gui_generated/src/lockscreen_screen \
TouchGFX/generated/gui_generated/src/logscreen_screen \
TouchGFX/generated/gui_generated/src/mainscreen_withstart_screen \
TouchGFX/generated/gui_generated/src/maintenance_screen \
TouchGFX/generated/gui_generated/src/manual_screen \
TouchGFX/generated/gui_generated/src/new_paitent_screen \
TouchGFX/generated/gui_generated/src/oclusion_level_screen \
TouchGFX/generated/gui_generated/src/same_patient_screen \
TouchGFX/generated/gui_generated/src/screenkeyboard_screen \
TouchGFX/generated/gui_generated/src/screenselectdrug_screen \
TouchGFX/generated/gui_generated/src/settings__screen_screen \
TouchGFX/generated/gui_generated/src/settings_time_date_screen \
TouchGFX/generated/gui_generated/src/specialmode_screen \
TouchGFX/generated/gui_generated/src/startup_screen \
TouchGFX/generated/gui_generated/src/syringedetected_screen \
TouchGFX/generated/gui_generated/src/testversion_screen \
TouchGFX/generated/gui_generated/src/timeparam_screen \
TouchGFX/generated/images/src \
TouchGFX/generated/images/src/Flat_hourglass \
TouchGFX/generated/images/src/__designer \
TouchGFX/generated/images/src/button \
TouchGFX/generated/images/src/icon \
TouchGFX/generated/images/src/mini_Flat_hourglass \
TouchGFX/generated/images/src/screen1 \
TouchGFX/generated/images/src/screen2/circle \
TouchGFX/generated/images/src/screen2 \
TouchGFX/generated/images/src/screen3 \
TouchGFX/generated/images/src/screen4 \
TouchGFX/generated/images/src/screenbutton \
TouchGFX/generated/images/src/screenlogo \
TouchGFX/generated/images/src/time \
TouchGFX/generated/texts/src \
TouchGFX/gui/src/alarmlist_screen \
TouchGFX/gui/src/battery_screen \
TouchGFX/gui/src/common \
TouchGFX/gui/src/containers \
TouchGFX/gui/src/departement_screen \
TouchGFX/gui/src/druglibrary_screen \
TouchGFX/gui/src/functiongeneration_screen \
TouchGFX/gui/src/genderchoice_screen \
TouchGFX/gui/src/intro_1_screen \
TouchGFX/gui/src/intro_screen \
TouchGFX/gui/src/keyboardnb_screen \
TouchGFX/gui/src/lockscreen_screen \
TouchGFX/gui/src/logscreen_screen \
TouchGFX/gui/src/mainscreen_withstart_screen \
TouchGFX/gui/src/maintenance_screen \
TouchGFX/gui/src/manual_screen \
TouchGFX/gui/src/model \
TouchGFX/gui/src/new_paitent_screen \
TouchGFX/gui/src/oclusion_level_screen \
TouchGFX/gui/src/same_patient_screen \
TouchGFX/gui/src/screenkeyboard_screen \
TouchGFX/gui/src/screenselectdrug_screen \
TouchGFX/gui/src/settings__screen_screen \
TouchGFX/gui/src/settings_time_date_screen \
TouchGFX/gui/src/specialmode_screen \
TouchGFX/gui/src/startup_screen \
TouchGFX/gui/src/syringedetected_screen \
TouchGFX/gui/src/testversion_screen \
TouchGFX/gui/src/timeparam_screen \
TouchGFX/target \
TouchGFX/target/generated \

