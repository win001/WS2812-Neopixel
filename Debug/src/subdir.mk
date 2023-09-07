################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c 

C_DEPS += \
./src/hal_entry.d 

OBJS += \
./src/hal_entry.o 

SREC += \
WS2812-Nepixel-Renesas-RA.srec 

MAP += \
WS2812-Nepixel-Renesas-RA.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/src" -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/ra/fsp/inc" -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/ra/fsp/inc/api" -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/ra/fsp/inc/instances" -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/ra_gen" -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/ra_cfg/fsp_cfg/bsp" -I"D:/RENESAS_TOUCH_SWITCHES/workspace/48_PIN_ICU_PIN_FINDER/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

