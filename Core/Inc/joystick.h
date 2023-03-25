/*
 * joystick.h
 *
 *  Created on: Jan 23, 2023
 *      Author: rohitimandi
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "peripheral-drivers-inc/drivers.h"

/* X and Y axis thresholds */
#define X_POS_THRES_LOW 2000	// threshold for joystick left hold
#define X_POS_THRES_HIGH 3100	// threshold for joystick right hold
#define Y_POS_THRES_LOW	2000	// threshold for joystick bottom hold
#define Y_POS_THRES_HIGH 3100	// threshold for joystick up hold

/* X and Y direction */
#define X_DIR_LEFT -1
#define X_DIR_RIGHT 1
#define X_DIR_CENTER 0
#define Y_DIR_UP 1
#define Y_DIR_DOWN -1
#define Y_DIR_CENTER 0

/* Joystick direction */
#define JS_DIR_LEFT_UP 1
#define JS_DIR_LEFT_DOWN 2
#define JS_DIR_LEFT 3
#define JS_DIR_RIGHT_UP 4
#define JS_DIR_RIGHT_DOWN 5
#define JS_DIR_RIGHT 6
#define JS_DIR_UP 7
#define JS_DIR_DOWN 8
#define JS_DIR_CENTERED 0

/* Joystick function prototype */
uint8_t joystick_read_direction(void);
//void control_led(uint32_t x_data, uint32_t y_data);	// used for testing the joystick
//void joystick_run(void);	// used for testing the joystick

#endif /* INC_JOYSTICK_H_ */
