################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DCMOTOR_PROG.c \
../DIO_PROG.c \
../KPD_PROG.c \
../LCD_PROG.c \
../main.c 

OBJS += \
./DCMOTOR_PROG.o \
./DIO_PROG.o \
./KPD_PROG.o \
./LCD_PROG.o \
./main.o 

C_DEPS += \
./DCMOTOR_PROG.d \
./DIO_PROG.d \
./KPD_PROG.d \
./LCD_PROG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


