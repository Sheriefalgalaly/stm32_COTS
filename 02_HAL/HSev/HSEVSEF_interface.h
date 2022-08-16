/*
 * HSEVSEF_interface.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Admin
 */

#ifndef HSEVSEF_INTERFACE_H_
#define HSEVSEF_INTERFACE_H_
enum SevSeg_type  {CommonAnode,CommonCathode};

typedef struct {
	u8* port;
	u8* pins;
	enum SevSeg_type Common;
	u8 PortOfCommon;
	u8 PinOfCommon
}SevSeg_t;

void HSevSeg_voidSetNum(SevSeg_t* Sev,u8 Num);
void HSevSeg_voidSetTwoNum(SevSeg_t* Sev1,SevSeg_t* Sev2,u8 Num);

void HSevSeg_voidClear(SevSeg_t* Sev);
void HSevSeg_voidDisable(SevSeg_t* Sev);

#endif /* HSEVSEF_INTERFACE_H_ */
