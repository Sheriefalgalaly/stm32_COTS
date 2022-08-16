/*
 * HLED_interface.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Admin
 */

#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

enum LEDState_t {AtciveHigh,ActiveLow};
typedef struct {
	u8 Pin ;
	u8 Port;
	enum LEDState_t state;
}LED_t;

void HLED_voidTurnOn(LED_t* LED);
void HLED_voidTurnOff(LED_t* LED);

void HLED_testtttttttttttttttttt(void);



#endif /* HLED_INTERFACE_H_ */
