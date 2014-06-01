################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/socket.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/w5100.cpp 

OBJS += \
./utility/socket.o \
./utility/w5100.o 

CPP_DEPS += \
./utility/socket.d \
./utility/w5100.d 


# Each subdirectory must supply rules for building sources it contributes
utility/socket.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/socket.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

utility/w5100.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/w5100.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


