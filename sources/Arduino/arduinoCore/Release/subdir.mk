################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/CDC.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/HID.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/HardwareSerial.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/IPAddress.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/Print.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/Stream.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/Tone.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/USBCore.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/WMath.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/WString.cpp \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/new.cpp 

C_SRCS += \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/WInterrupts.c \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring.c \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_analog.c \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_digital.c \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_pulse.c \
/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_shift.c 

OBJS += \
./CDC.o \
./HID.o \
./HardwareSerial.o \
./IPAddress.o \
./Print.o \
./Stream.o \
./Tone.o \
./USBCore.o \
./WInterrupts.o \
./WMath.o \
./WString.o \
./new.o \
./wiring.o \
./wiring_analog.o \
./wiring_digital.o \
./wiring_pulse.o \
./wiring_shift.o 

C_DEPS += \
./WInterrupts.d \
./wiring.d \
./wiring_analog.d \
./wiring_digital.d \
./wiring_pulse.d \
./wiring_shift.d 

CPP_DEPS += \
./CDC.d \
./HID.d \
./HardwareSerial.d \
./IPAddress.d \
./Print.d \
./Stream.d \
./Tone.d \
./USBCore.d \
./WMath.d \
./WString.d \
./new.d 


# Each subdirectory must supply rules for building sources it contributes
CDC.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/CDC.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HID.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/HID.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HardwareSerial.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

IPAddress.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Print.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/Print.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Stream.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Tone.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/Tone.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

USBCore.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

WInterrupts.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

WMath.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

WString.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/WString.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

new.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/new.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

wiring.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

wiring_analog.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

wiring_digital.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

wiring_pulse.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

wiring_shift.o: /home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


