#include "ecu_relay.h"

static void Relay_Config(pin_config_t *pin_config, Relay_t *_relay);

Std_ReturnType Relay_initialize(Relay_t *_relay)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config;
        Relay_Config(&pin_config, _relay);
        gpio_pin_initialize(&pin_config);
        
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType Relay_Turn_On(Relay_t *_relay)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config;
        Relay_Config(&pin_config, _relay);
        gpio_pin_write_logic(&pin_config, GPIO_HIGH);
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType Relay_Turn_Off(Relay_t *_relay)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config;
        Relay_Config(&pin_config, _relay);
        gpio_pin_write_logic(&pin_config, GPIO_LOW);
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType Relay_toggle(Relay_t *_relay)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config;
        Relay_Config(&pin_config, _relay);
        
        if(RELAY_TURN_ON == _relay->Status){
            _relay->Status = RELAY_TURN_OFF;
            ret = gpio_pin_write_logic(&pin_config, GPIO_LOW);
        }
        else if(RELAY_TURN_OFF == _relay->Status){
            _relay->Status = RELAY_TURN_ON;
            ret = gpio_pin_write_logic(&pin_config, GPIO_HIGH);
        }
        else{
            /*Nothing*/
        }
    }
    return ret;
}


Std_ReturnType Relay_read_status(Relay_t *_relay, uint8 *status)
{
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _relay){
        ret = E_NOT_OK;
    }
    else{
        pin_config_t pin_config;
        Relay_Config(&pin_config, _relay);
        
        *status = _relay->Status;
        ret = E_OK;
    }
    return ret;
}





static void Relay_Config(pin_config_t *pin_config, Relay_t *_relay)
{
    pin_config->Direction = GPIO_OUTPUT;
    pin_config->Logic = _relay->Status;
    pin_config->Pin = _relay->Pin;
    pin_config->Port = _relay->Port;
}
