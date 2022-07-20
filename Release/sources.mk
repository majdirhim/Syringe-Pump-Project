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
TouchGFX/build/MINGW32_NT-6.2/generated/fonts/src \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/activealarms_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/alarmandeventconfig_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/battery_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/common \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/configuration_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/containers \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/departements_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/diagnostic_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/displaymode_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/druglibrary_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/genderchoice_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/home_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/keyboard_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/keyboardnb_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/language_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/log_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/main_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/maintenance_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/manual_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/newpatient_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/oclusionthresholds_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/password_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/patientdatabase_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/perfusiontimesetting_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/samepatient_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/settings_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/sound_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/specialmodes_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/startup_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/syringelibrary_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/syringeselection_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/timeanddatesetting_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/gui_generated/src/transitions_screen \
TouchGFX/build/MINGW32_NT-6.2/generated/images/src \
TouchGFX/build/MINGW32_NT-6.2/generated/images/src/__designer \
TouchGFX/build/MINGW32_NT-6.2/generated/images/src/mini_Flat_hourglass \
TouchGFX/build/MINGW32_NT-6.2/generated/simulator/src \
TouchGFX/build/MINGW32_NT-6.2/generated/simulator/src/video \
TouchGFX/build/MINGW32_NT-6.2/generated/texts/src \
TouchGFX/build/MINGW32_NT-6.2/gui/src/activealarms_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/alarmandeventconfig_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/battery_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/common \
TouchGFX/build/MINGW32_NT-6.2/gui/src/configuration_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/containers \
TouchGFX/build/MINGW32_NT-6.2/gui/src/departements_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/diagnostic_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/displaymode_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/druglibrary_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/genderchoice_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/home_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/keyboard_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/keyboardnb_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/language_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/log_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/main_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/maintenance_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/manual_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/model \
TouchGFX/build/MINGW32_NT-6.2/gui/src/newpatient_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/oclusionthresholds_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/password_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/patientdatabase_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/perfusiontimesetting_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/samepatient_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/settings_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/sound_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/specialmodes_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/startup_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/syringelibrary_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/syringeselection_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/timeanddatesetting_screen \
TouchGFX/build/MINGW32_NT-6.2/gui/src/transitions_screen \
TouchGFX/build/MINGW32_NT-6.2/simulator \
TouchGFX/build/MINGW32_NT-6.2/touchgfx/framework/source/platform/driver/touch \
TouchGFX/build/MINGW32_NT-6.2/touchgfx/framework/source/platform/hal/simulator/sdl2 \
TouchGFX/generated/fonts/src \
TouchGFX/generated/gui_generated/src/activealarms_screen \
TouchGFX/generated/gui_generated/src/alarmandeventconfig_screen \
TouchGFX/generated/gui_generated/src/battery_screen \
TouchGFX/generated/gui_generated/src/common \
TouchGFX/generated/gui_generated/src/configuration_screen \
TouchGFX/generated/gui_generated/src/containers \
TouchGFX/generated/gui_generated/src/departements_screen \
TouchGFX/generated/gui_generated/src/diagnostic_screen \
TouchGFX/generated/gui_generated/src/displaymode_screen \
TouchGFX/generated/gui_generated/src/druglibrary_screen \
TouchGFX/generated/gui_generated/src/genderchoice_screen \
TouchGFX/generated/gui_generated/src/home_screen \
TouchGFX/generated/gui_generated/src/keyboard_screen \
TouchGFX/generated/gui_generated/src/keyboardnb_screen \
TouchGFX/generated/gui_generated/src/language_screen \
TouchGFX/generated/gui_generated/src/log_screen \
TouchGFX/generated/gui_generated/src/main_screen \
TouchGFX/generated/gui_generated/src/maintenance_screen \
TouchGFX/generated/gui_generated/src/manual_screen \
TouchGFX/generated/gui_generated/src/newpatient_screen \
TouchGFX/generated/gui_generated/src/oclusionthresholds_screen \
TouchGFX/generated/gui_generated/src/password_screen \
TouchGFX/generated/gui_generated/src/patientdatabase_screen \
TouchGFX/generated/gui_generated/src/perfusiontimesetting_screen \
TouchGFX/generated/gui_generated/src/samepatient_screen \
TouchGFX/generated/gui_generated/src/settings_screen \
TouchGFX/generated/gui_generated/src/sound_screen \
TouchGFX/generated/gui_generated/src/specialmodes_screen \
TouchGFX/generated/gui_generated/src/startup_screen \
TouchGFX/generated/gui_generated/src/syringelibrary_screen \
TouchGFX/generated/gui_generated/src/syringeselection_screen \
TouchGFX/generated/gui_generated/src/timeanddatesetting_screen \
TouchGFX/generated/gui_generated/src/transitions_screen \
TouchGFX/generated/images/src \
TouchGFX/generated/images/src/__designer \
TouchGFX/generated/images/src/mini_Flat_hourglass \
TouchGFX/generated/texts/src \
TouchGFX/gui/src/activealarms_screen \
TouchGFX/gui/src/alarmandeventconfig_screen \
TouchGFX/gui/src/battery_screen \
TouchGFX/gui/src/common \
TouchGFX/gui/src/configuration_screen \
TouchGFX/gui/src/containers \
TouchGFX/gui/src/departements_screen \
TouchGFX/gui/src/diagnostic_screen \
TouchGFX/gui/src/displaymode_screen \
TouchGFX/gui/src/druglibrary_screen \
TouchGFX/gui/src/genderchoice_screen \
TouchGFX/gui/src/home_screen \
TouchGFX/gui/src/keyboard_screen \
TouchGFX/gui/src/keyboardnb_screen \
TouchGFX/gui/src/language_screen \
TouchGFX/gui/src/log_screen \
TouchGFX/gui/src/main_screen \
TouchGFX/gui/src/maintenance_screen \
TouchGFX/gui/src/manual_screen \
TouchGFX/gui/src/model \
TouchGFX/gui/src/newpatient_screen \
TouchGFX/gui/src/oclusionthresholds_screen \
TouchGFX/gui/src/password_screen \
TouchGFX/gui/src/patientdatabase_screen \
TouchGFX/gui/src/perfusiontimesetting_screen \
TouchGFX/gui/src/samepatient_screen \
TouchGFX/gui/src/settings_screen \
TouchGFX/gui/src/sound_screen \
TouchGFX/gui/src/specialmodes_screen \
TouchGFX/gui/src/startup_screen \
TouchGFX/gui/src/syringelibrary_screen \
TouchGFX/gui/src/syringeselection_screen \
TouchGFX/gui/src/timeanddatesetting_screen \
TouchGFX/gui/src/transitions_screen \
TouchGFX/target \
TouchGFX/target/generated \
