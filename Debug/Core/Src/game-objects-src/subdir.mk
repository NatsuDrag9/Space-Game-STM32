################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/game-objects-src/asteroid.c \
../Core/Src/game-objects-src/earth.c \
../Core/Src/game-objects-src/spaceship.c 

OBJS += \
./Core/Src/game-objects-src/asteroid.o \
./Core/Src/game-objects-src/earth.o \
./Core/Src/game-objects-src/spaceship.o 

C_DEPS += \
./Core/Src/game-objects-src/asteroid.d \
./Core/Src/game-objects-src/earth.d \
./Core/Src/game-objects-src/spaceship.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/game-objects-src/%.o: ../Core/Src/game-objects-src/%.c Core/Src/game-objects-src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F413xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-game-2d-objects-2d-src

clean-Core-2f-Src-2f-game-2d-objects-2d-src:
	-$(RM) ./Core/Src/game-objects-src/asteroid.d ./Core/Src/game-objects-src/asteroid.o ./Core/Src/game-objects-src/earth.d ./Core/Src/game-objects-src/earth.o ./Core/Src/game-objects-src/spaceship.d ./Core/Src/game-objects-src/spaceship.o

.PHONY: clean-Core-2f-Src-2f-game-2d-objects-2d-src

