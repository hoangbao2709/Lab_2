/*
 * updateClockBuffer.h
 *
 *  Created on: Oct 1, 2024
 *      Author: PC
 */

#include "Component.h"

#ifndef INC_UPDATECLOCKBUFFER_H_
#define INC_UPDATECLOCKBUFFER_H_

extern int hour;        // Khai báo biến
extern int minute;      // Khai báo biến
extern int second;      // Khai báo biến
#define MAX_LED 4       // Định nghĩa hằng số
extern int index_led;   // Khai báo biến
extern int led_buffer[4]; // Khai báo biến
extern int counter;      // Khai báo biến
extern int bit;         // Khai báo biến

void update7SEG(int index);
void updateClockBuffer();

#endif /* INC_UPDATECLOCKBUFFER_H_ */
