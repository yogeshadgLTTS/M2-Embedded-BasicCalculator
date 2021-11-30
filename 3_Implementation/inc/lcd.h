/**
 * @file lcd.h
 * @author Kavin Vignes
 * @brief 
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LCD_H_
#define LCD_H_

#include<avr/io.h>
#include<util/delay.h>
#include "../pin_config.h"


#define LCD_CMD_CLEAR_DISPLAY	             0x01
#define LCD_CMD_CURSOR_HOME		             0x02

// Display control
#define LCD_CMD_DISPLAY_OFF                0x08
#define LCD_CMD_DISPLAY_NO_CURSOR          0x0c
#define LCD_CMD_DISPLAY_CURSOR_NO_BLINK    0x0E
#define LCD_CMD_DISPLAY_CURSOR_BLINK       0x0F

// Function set
#define LCD_CMD_4BIT_2ROW_5X7              0x28
#define LCD_CMD_8BIT_2ROW_5X7              0x38

//functions prototype
void lcd_init(void);
void lcd_send_command (uint8_t );
void lcd_write_character(uint8_t );
void lcd_write_word(uint8_t[]);
void lcd_clear(void);
void lcd_set_courser(uint8_t,uint8_t);
void lcd_goto_xy (uint8_t , uint8_t );



#endif /* LCD_H_ */