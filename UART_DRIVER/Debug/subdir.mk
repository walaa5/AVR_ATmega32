################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DCMOTOR_PROG.c \
../DIO_PROG.c \
../LCD_PROG.c \
../TIMER1_PROG.c \
../UART_PROG.c \
../main.c \
../smart_home.c \
../smart_home_voice.c 

OBJS += \
./DCMOTOR_PROG.o \
./DIO_PROG.o \
./LCD_PROG.o \
./TIMER1_PROG.o \
./UART_PROG.o \
./main.o \
./smart_home.o \
./smart_home_voice.o 

C_DEPS += \
./DCMOTOR_PROG.d \
./DIO_PROG.d \
./LCD_PROG.d \
./TIMER1_PROG.d \
./UART_PROG.d \
./main.d \
./smart_home.d \
./smart_home_voice.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


