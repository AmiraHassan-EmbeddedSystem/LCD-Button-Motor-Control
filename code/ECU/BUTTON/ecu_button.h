/* 
 * File:   ecu_button.h
 * Author: ah427
 *
 * Created on 24 ?????, 2024, 12:02 ?
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* SECTION: Include */
#include "../../MCAL/GPIO/hal_gpio.h"

/* SECTION: Macro Declarations */
/* SECTION: Macro Function Declarations */
/* SECTION: Data Type Declarations */
typedef enum{
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED,
}button_status_t;

typedef enum{
    BUTTON_ACTIVE_LOW = 0,
    BUTTON_ACTIVE_HIGH,
}button_active_t;

typedef struct{
    pin_config_t button_pin;        /*@ref GPIO => pin_config_t*/
    button_status_t button_status;    /*@ref button_state_t*/
    button_active_t button_active;  /*@ref button_active_t*/
}button_t;

/* SECTION: Interface Function Declarations */


/**
 * @brief Initialize the assigned pin to be Input.
 * @param btn pointer to the button configurations
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_initialize(const button_t *btn);

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue while performing this action
 */
Std_ReturnType button_read_status(const button_t *btn, button_status_t *btn_status);




#endif	/* ECU_BUTTON_H */

