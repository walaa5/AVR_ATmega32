################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_PROG.c \
../EXTI_PROG.c \
../LCD_PROG.c \
../PWM_LED.c \
../SEVEN_SEGMENT_PROG.c \
../TIMER1_PROG.c \
../TIMER_PROG.c \
../main.c 

OBJS += \
./DIO_PROG.o \
./EXTI_PROG.o \
./LCD_PROG.o \
./PWM_LED.o \
./SEVEN_SEGMENT_PROG.o \
./TIMER1_PROG.o \
./TIMER_PROG.o \
./main.o 

C_DEPS += \
./DIO_PROG.d \
./EXTI_PROG.d \
./LCD_PROG.d \
./PWM_LED.d \
./SEVEN_SEGMENT_PROG.d \
./TIMER1_PROG.d \
./TIMER_PROG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


