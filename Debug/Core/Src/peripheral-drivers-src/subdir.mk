################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/peripheral-drivers-src/drivers.c 

OBJS += \
./Core/Src/peripheral-drivers-src/drivers.o 

C_DEPS += \
./Core/Src/peripheral-drivers-src/drivers.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/peripheral-drivers-src/%.o: ../Core/Src/peripheral-drivers-src/%.c Core/Src/peripheral-drivers-src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F413xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-peripheral-2d-drivers-2d-src

clean-Core-2f-Src-2f-peripheral-2d-drivers-2d-src:
	-$(RM) ./Core/Src/peripheral-drivers-src/drivers.d ./Core/Src/peripheral-drivers-src/drivers.o

.PHONY: clean-Core-2f-Src-2f-peripheral-2d-drivers-2d-src

