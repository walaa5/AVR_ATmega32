################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_PROG.c \
../KPD_PROG.c \
../LCD_PROG.c \
../SEVEN_SEGMENT_PROG.c \
../STEPPER_PROG.c \
../main.c 

OBJS += \
./DIO_PROG.o \
./KPD_PROG.o \
./LCD_PROG.o \
./SEVEN_SEGMENT_PROG.o \
./STEPPER_PROG.o \
./main.o 

C_DEPS += \
./DIO_PROG.d \
./KPD_PROG.d \
./LCD_PROG.d \
./SEVEN_SEGMENT_PROG.d \
./STEPPER_PROG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


