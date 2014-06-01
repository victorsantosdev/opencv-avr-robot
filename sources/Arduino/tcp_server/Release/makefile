################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ByteBuffer/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
tcp_server.lss \

FLASH_IMAGE += \
tcp_server.hex \

EEPROM_IMAGE += \
tcp_server.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: tcp_server.elf secondary-outputs

# Tool invocations
tcp_server.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++  -s -Os -o"tcp_server.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lm -Wl,-Map,tcp_server.map,--cref -mrelax -Wl,--gc-sections -L"/home/victor/workspace/eclipse_arduino/arduinoCore/Release" -mmcu=atmega328p
	@echo 'Finished building target: $@'
	@echo ' '

tcp_server.lss: tcp_server.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S tcp_server.elf  >"tcp_server.lss"
	@echo 'Finished building: $@'
	@echo ' '

tcp_server.hex: tcp_server.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex tcp_server.elf  "tcp_server.hex"
	@echo 'Finished building: $@'
	@echo ' '

tcp_server.eep: tcp_server.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex tcp_server.elf  "tcp_server.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: tcp_server.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p tcp_server.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) tcp_server.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
