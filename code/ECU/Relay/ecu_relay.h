/* 
 * File:   ecu_relay.h
 * Author: ah427
 *
 * Created on 27 ?????, 2024, 02:23 ?
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* SECTION: Include */
#include "../../MCAL/GPIO/hal_gpio.h"

/* SECTION: Macro Declarations */
#define RELAY_TURN_ON       1
#define RELAY_TURN_OFF      0

/* SECTION: Macro Function Declarations */
/* SECTION: Data Type Declarations */
typedef struct{
    uint8 Port:3;
    uint8 Pin:3;
    uint8 Status:1;
}Relay_t;

/* SECTION: Interface Function Declarations */
Std_ReturnType Relay_initialize(Relay_t *_relay);
Std_ReturnType Relay_Turn_On(Relay_t *_relay);
Std_ReturnType Relay_Turn_Off(Relay_t *_relay);
Std_ReturnType Relay_toggle(Relay_t *_relay);
Std_ReturnType Relay_read_status(Relay_t *_relay, uint8 *status);




#endif	/* ECU_RELAY_H */

