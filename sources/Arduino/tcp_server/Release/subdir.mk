################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/victor/arduino/arduino-1.0.5/libraries/Adb/Adb.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/Dhcp.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/Dns.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/Ethernet.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/EthernetClient.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/EthernetServer.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/EthernetUdp.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/SD/File.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/SD/SD.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/SPI/SPI.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/SD/utility/Sd2Card.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/SD/utility/SdFile.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/SD/utility/SdVolume.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial/SoftwareSerial.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS/TinyGPS.cpp \
../main.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Adb/max3421e.cpp \
../motores.cpp \
../myDelay.cpp \
../sensorIR.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/socket.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Adb/usb.cpp \
/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/w5100.cpp 

OBJS += \
./Adb.o \
./Dhcp.o \
./Dns.o \
./Ethernet.o \
./EthernetClient.o \
./EthernetServer.o \
./EthernetUdp.o \
./File.o \
./SD.o \
./SPI.o \
./Sd2Card.o \
./SdFile.o \
./SdVolume.o \
./SoftwareSerial.o \
./TinyGPS.o \
./main.o \
./max3421e.o \
./motores.o \
./myDelay.o \
./sensorIR.o \
./socket.o \
./usb.o \
./w5100.o 

CPP_DEPS += \
./Adb.d \
./Dhcp.d \
./Dns.d \
./Ethernet.d \
./EthernetClient.d \
./EthernetServer.d \
./EthernetUdp.d \
./File.d \
./SD.d \
./SPI.d \
./Sd2Card.d \
./SdFile.d \
./SdVolume.d \
./SoftwareSerial.d \
./TinyGPS.d \
./main.d \
./max3421e.d \
./motores.d \
./myDelay.d \
./sensorIR.d \
./socket.d \
./usb.d \
./w5100.d 


# Each subdirectory must supply rules for building sources it contributes
Adb.o: /home/victor/arduino/arduino-1.0.5/libraries/Adb/Adb.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dhcp.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/Dhcp.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Dns.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/Dns.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Ethernet.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/Ethernet.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EthernetClient.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/EthernetClient.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EthernetServer.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/EthernetServer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EthernetUdp.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/EthernetUdp.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

File.o: /home/victor/arduino/arduino-1.0.5/libraries/SD/File.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SD.o: /home/victor/arduino/arduino-1.0.5/libraries/SD/SD.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SPI.o: /home/victor/arduino/arduino-1.0.5/libraries/SPI/SPI.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sd2Card.o: /home/victor/arduino/arduino-1.0.5/libraries/SD/utility/Sd2Card.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SdFile.o: /home/victor/arduino/arduino-1.0.5/libraries/SD/utility/SdFile.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SdVolume.o: /home/victor/arduino/arduino-1.0.5/libraries/SD/utility/SdVolume.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SoftwareSerial.o: /home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial/SoftwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TinyGPS.o: /home/victor/arduino/arduino-1.0.5/libraries/TinyGPS/TinyGPS.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

max3421e.o: /home/victor/arduino/arduino-1.0.5/libraries/Adb/max3421e.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

socket.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/socket.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

usb.o: /home/victor/arduino/arduino-1.0.5/libraries/Adb/usb.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

w5100.o: /home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility/w5100.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/victor/arduino/arduino-1.0.5/libraries/SoftwareSerial -I/home/victor/arduino/arduino-1.0.5/libraries/pt-1.4 -I/home/victor/arduino/arduino-1.0.5/libraries/SD -I/home/victor/arduino/arduino-1.0.5/libraries/SD/utility -I/home/victor/arduino/arduino-1.0.5/libraries/TinyGPS -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet -I/home/victor/arduino/arduino-1.0.5/libraries/Ethernet/utility -I/home/victor/arduino/arduino-1.0.5/libraries/SPI -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/victor/arduino/arduino-1.0.5/hardware/arduino/variants/standard -I"/home/victor/workspace/eclipse_arduino/tcp_server" -I/home/victor/arduino/arduino-1.0.5/libraries/ByteBuffer -I/home/victor/arduino/arduino-1.0.5/libraries/Adb -Wall -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


