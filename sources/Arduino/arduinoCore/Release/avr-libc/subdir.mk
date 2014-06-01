################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/avr-libc/malloc.c \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/avr-libc/realloc.c 

OBJS += \
./avr-libc/malloc.o \
./avr-libc/realloc.o 

C_DEPS += \
./avr-libc/malloc.d \
./avr-libc/realloc.d 


# Each subdirectory must supply rules for building sources it contributes
avr-libc/malloc.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/avr-libc/malloc.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

avr-libc/realloc.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/avr-libc/realloc.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


