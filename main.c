/*
 * LCD Clock Display
 * Author : Usman
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdio.h>

#define RS PB0
#define RW PB1
#define EN PB2

void LCD_init(void);
void LCD_Send_Command(unsigned char);
void LCD_Send_Data(unsigned char);
void LCD_Send_String(char*);

int main(void)
{
    LCD_init();
    char timeStr[16];
    int hours = 0, minutes = 0, seconds = 0;

    while (1) 
    {
        // Format time into hh:mm:ss
        sprintf(timeStr, "%02d:%02d:%02d", hours, minutes, seconds);

        LCD_Send_Command(0x80);   // Move cursor to first row
        LCD_Send_String("   Digital Clock");
        LCD_Send_Command(0xC0);   // Move to second row
        LCD_Send_String(timeStr);

        _delay_ms(1); // 1 second delay

        // Increment time
        seconds++;
        if(seconds == 60){
            seconds = 0;
            minutes++;
        }
        if(minutes == 60){
            minutes = 0;
            hours++;
        }
        if(hours == 24){
            hours = 0;
        }
    }
    return 0;
}

void LCD_init(void)
{
    DDRD = 0xFF;
    DDRB = 0x07;
    
    _delay_ms(50);
    
    LCD_Send_Command(0x38); //8-bit, 2 Lines, 5x7 matrix
    _delay_ms(1);
    LCD_Send_Command(0x0C); // Display ON, cursor OFF
    _delay_ms(1);
    LCD_Send_Command(0x01); // Clear display
    _delay_ms(2);
    LCD_Send_Command(0x06); // Entry mode set, increment cursor
    _delay_ms(1);
}

void LCD_Send_Command(unsigned char command)
{
    PORTB &= ~(1 << RS);
    PORTB &= ~(1 << RW);
    PORTD = command;
    
    PORTB |= (1 << EN);
    _delay_ms(1);
    PORTB &= ~(1 << EN);
    _delay_ms(1);
}

void LCD_Send_Data(unsigned char data)
{
    PORTB |= (1 << RS);
    PORTB &= ~(1 << RW);
    PORTD = data;
    
    PORTB |= (1 << EN);
    _delay_ms(1);
    PORTB &= ~(1 << EN);
    _delay_ms(1);
}

void LCD_Send_String(char* str)
{
    while(*str)
    {
        LCD_Send_Data(*str);
        str++;
    }
}
