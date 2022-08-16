/*
 * HStepper_interface.h
 *
 *  Created on: Aug 4, 2022
 *      Author: Admin
 */

#ifndef HSTEPPER_INTERFACE_H_
#define HSTEPPER_INTERFACE_H_

#include "HStepper_private.h"

typedef struct {
	u8* Port;  //pointer to array of ports in this order -> //MS1-MS2-MS3-Pulse-Dir
	u8* Pins;  //pointer to array of pins in this order -> //MS1-MS2-MS3-Pulse-Dir
	enum Resolution Res;
}Stepper_t;

void HStepper_voidMoveMotorNumberofSteps(Stepper_t* s,u16 Steps,u16 Speed ,enum Direction d1);
#endif /* HSTEPPER_INTERFACE_H_ */
