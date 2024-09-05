/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */

#include <xc.h>
#include "project.h"
#include "ECU/BUTTON/ecu_button.h"
#define _XTAL_FREQ 80000000UL

void initialization(void);
button_status_t btn_last_status = BUTTON_RELEASED;
button_status_t btn_valid_status = BUTTON_RELEASED;

volatile uint8 flag = 0;
uint8 counter_debouncing = 0;

void main(void) {
    initialization();
    while(1){
        button_read_status(&btn, &btn_last_status);
            // Debouncing
        if(btn_last_status == BUTTON_PRESSED){
            counter_debouncing++;
            if(counter_debouncing > 500){
                btn_valid_status = BUTTON_PRESSED;
            }
        }
        
        if(btn_valid_status != btn_last_status){
            btn_valid_status = btn_last_status;
            if((btn_valid_status == BUTTON_PRESSED) && (flag == 0)){
                flag = 1;
                Relay_Turn_On(&relay);
                lcd_8bit_send_command(&lcd_8bit, LCD_CLEAR_SCREEN);
                lcd_8bit_send_command(&lcd_8bit, LCD_SHIFT_RIGHT);
                lcd_8bit_send_string_pos(&lcd_8bit, "Running", 1, 6);
                __delay_ms(15);
                lcd_8bit_send_command(&lcd_8bit, LCD_CURSOR_OFF_DISPLAY_OFF);
                __delay_ms(15);
                lcd_8bit_send_command(&lcd_8bit, LCD_CURSOR_OFF_DISPLAY_ON);   
            }
            
            else if((btn_valid_status == BUTTON_PRESSED) && (flag == 1)){
                flag = 0;
                Relay_Turn_Off(&relay);
                lcd_8bit_send_command(&lcd_8bit, LCD_CLEAR_SCREEN);
                lcd_8bit_send_command(&lcd_8bit, LCD_SHIFT_RIGHT);
                lcd_8bit_send_string_pos(&lcd_8bit, "Not Running", 1, 3);
                __delay_ms(15);
                lcd_8bit_send_command(&lcd_8bit, LCD_CURSOR_OFF_DISPLAY_OFF);
                __delay_ms(15);
                lcd_8bit_send_command(&lcd_8bit, LCD_CURSOR_OFF_DISPLAY_ON); 
            }
        }
    }
    
    return;
}

void initialization(void){
    ecu_initialization();
}
