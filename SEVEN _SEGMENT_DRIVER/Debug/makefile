################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SEVEN\ _SEGMENT_DRIVER.lss \

FLASH_IMAGE += \
SEVEN\ _SEGMENT_DRIVER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SEVEN\ _SEGMENT_DRIVER.elf secondary-outputs

# Tool invocations
SEVEN\ _SEGMENT_DRIVER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SEVEN _SEGMENT_DRIVER.map -mmcu=atmega32 -o "SEVEN _SEGMENT_DRIVER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SEVEN\ _SEGMENT_DRIVER.lss: SEVEN\ _SEGMENT_DRIVER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SEVEN _SEGMENT_DRIVER.elf  >"SEVEN _SEGMENT_DRIVER.lss"
	@echo 'Finished building: $@'
	@echo ' '

SEVEN\ _SEGMENT_DRIVER.hex: SEVEN\ _SEGMENT_DRIVER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SEVEN _SEGMENT_DRIVER.elf  "SEVEN _SEGMENT_DRIVER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SEVEN\ _SEGMENT_DRIVER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SEVEN _SEGMENT_DRIVER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "SEVEN _SEGMENT_DRIVER.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
