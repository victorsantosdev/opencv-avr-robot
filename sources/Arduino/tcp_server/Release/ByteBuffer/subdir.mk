################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer/ByteBuffer.cpp 

OBJS += \
./ByteBuffer/ByteBuffer.o 

CPP_DEPS += \
./ByteBuffer/ByteBuffer.d 


# Each subdirectory must supply rules for building sources it contributes
ByteBuffer/ByteBuffer.o: /home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer/ByteBuffer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


