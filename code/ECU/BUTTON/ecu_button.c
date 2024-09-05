
#include "ecu_button.h"

Std_ReturnType button_initialize(const button_t *btn)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == btn){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize(&(btn->button_pin));
    }
    return ret;
}


Std_ReturnType button_read_status(const button_t *btn, button_status_t *btn_status)
{
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == btn) || (NULL == btn_status)){
        ret = E_NOT_OK;
    }
    else{
        logic_t pin_login_status = GPIO_LOW;
        ret = gpio_pin_read_logic(&(btn->button_pin), &pin_login_status);
        if(BUTTON_ACTIVE_HIGH == btn->button_active){
            if(GPIO_HIGH == pin_login_status){
                *btn_status = BUTTON_PRESSED;
            }
            else{
                *btn_status = BUTTON_RELEASED;
            }
            ret = E_OK;
        }
            
        else if(BUTTON_ACTIVE_LOW == btn->button_active){
            if(GPIO_HIGH == pin_login_status){
                *btn_status = BUTTON_RELEASED;
            }
            else{
                *btn_status = BUTTON_PRESSED;
            }
            ret = E_OK;
        }
            
        else{
                /*Nothing*/
            }
    }
    return ret;
}