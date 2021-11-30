/**
 * @file lcd.c
 * @author Kavin Vignes
 * @brief 
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "lcd.h"

/**
 * @brief (Initialize LCD pins as output and seting up the operation mode default setting)
 * 
 */
void lcd_init(void)
{

	DATA_DDR = (1<<LCD_D7) | (1<<LCD_D6) | (1<<LCD_D5)| (1<<LCD_D4);
	CTL_DDR |= (1<<LCD_EN)|(1<<LCD_RW)|(1<<LCD_RS);
	
	DATA_BUS = (0<<LCD_D7)|(0<<LCD_D6)|(1<<LCD_D5)|(0<<LCD_D4);
	CTL_BUS|= (1<<LCD_EN)|(0<<LCD_RW)|(0<<LCD_RS);
	
	_delay_ms(1);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(1);

	lcd_send_command(LCD_CMD_4BIT_2ROW_5X7);
	_delay_ms(1);
	lcd_send_command(LCD_CMD_DISPLAY_CURSOR_BLINK);
	_delay_ms(1);
	lcd_send_command(0x80);

}

/**
 * @brief (Sending a command to LCD by sending the first nibble then the second nibble enabling and disabling the LCD in between)
 * 
 * @param command 
 */
void lcd_send_command (uint8_t command)
{
	DATA_BUS=((command&0b11110000)>>4);
	CTL_BUS &=~(1<<LCD_RS);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(1);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(1);
	DATA_BUS=(command&0b00001111);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(1);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(1);
}

/**
 * @brief (Printing a full word to the LCD)
 * 
 * @param word 
 */
void lcd_write_word(uint8_t word[20])
{
	int i=0;
	while(word[i]!='\0')
	{
		lcd_write_character(word[i]);
		i++;
	}
}

/**
 * @brief (Sending one characterto LCD by sending the first nibble first then the second nibble enabling and disabling the LCD in between)
 * 
 * @param character 
 */
void lcd_write_character(uint8_t character)
{

	DATA_BUS=((character & 0b11110000)>>4);
	CTL_BUS|=(1<<LCD_RS);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(2);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(2);
	DATA_BUS=(character & 0b00001111);
	CTL_BUS |=(1<<LCD_EN);
	_delay_ms(2);
	CTL_BUS &=~(1<<LCD_EN);
	_delay_ms(2);
}

/**
 * @brief (Clearing the lcd screen by sending the LCD_CMD_CLEAR_DISPLAY command to LCD)
 * 
 */
void lcd_clear(void)
{
	lcd_send_command(LCD_CMD_CLEAR_DISPLAY);
	_delay_ms(5);
}
void lcd_goto_xy (uint8_t line,uint8_t pos)				
{
	lcd_send_command((0x80|(line<<6))+pos);
	_delay_us (50);
}