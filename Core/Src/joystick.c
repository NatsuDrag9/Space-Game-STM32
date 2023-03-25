#include "joystick.h"

/* Private variables */
volatile uint32_t adc_buf[2];
volatile uint32_t vr_x, vr_y;

//void control_led(uint32_t x_data, uint32_t y_data){
//	if ((x_data >= 20) && (x_data <= 3000)){
//		HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LD1_Green_GPIO_Port, LD1_Green_Pin, GPIO_PIN_RESET);
//	}
//
//	else if ((x_data >= 3100) && (x_data <= 4000)){
//		HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LD1_Green_GPIO_Port, LD1_Green_Pin, GPIO_PIN_SET);
//	}
//
//	if ((y_data >= 20) && (y_data <= 2900)){
//		HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_RESET);
//	}
//
//	else if ((y_data >= 2900) && (y_data <= 4000)){
//		HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_SET);
//	}
//
//}

//void joystick_run(){
//	  HAL_ADC_Start_DMA(&hadc1,(uint32_t *) adc_buf, 2);
////	  vr_x = adc_buf[1];
////	  vr_y = adc_buf[0];
//	  control_led(adc_buf[1], adc_buf[0]);
//
//}

uint8_t joystick_read_direction(){
	  HAL_ADC_Start_DMA(&hadc1,(uint32_t *) adc_buf, 2);
	  vr_x = adc_buf[1];
	  vr_y = adc_buf[0];

	  int16_t xDir = 0, yDir = 0;

	  if (vr_x > X_POS_THRES_HIGH) {
		  xDir = X_DIR_RIGHT;
	  }
	  else if (vr_x < X_POS_THRES_LOW) {
		  xDir = X_DIR_LEFT;
	  }
	  else {
		  xDir = X_DIR_CENTER;
	  }

	  if (vr_y > Y_POS_THRES_HIGH) {
		  yDir = Y_DIR_UP;
	  }
	  else if (vr_y < Y_POS_THRES_LOW) {
		  yDir = Y_DIR_DOWN;
	  }
	  else {
		  yDir = Y_DIR_CENTER;
	  }


	  if (xDir == X_DIR_LEFT) {
		  if (yDir == Y_DIR_UP) {
			  return JS_DIR_LEFT_UP;
		  }
		  else if (yDir == Y_DIR_DOWN) {
			  return JS_DIR_LEFT_DOWN;
		  }
		  else if (yDir == Y_DIR_CENTER) {
			  return JS_DIR_LEFT;
		  }
	  }

	  if (xDir == X_DIR_RIGHT) {
		  if (yDir == Y_DIR_UP) {
			  return JS_DIR_RIGHT_UP;
		  }
		  else if (yDir == Y_DIR_DOWN) {
			  return JS_DIR_RIGHT_DOWN;
		  }
		  else if (yDir == Y_DIR_CENTER) {
			  return JS_DIR_RIGHT;
		  }
	  }

	  if (xDir == X_DIR_CENTER) {
		  if (yDir == Y_DIR_UP) {
			  return JS_DIR_UP;
		  }
		  else if (yDir == Y_DIR_DOWN) {
			  return JS_DIR_DOWN;
		  }
		  else if (yDir == Y_DIR_CENTER) {
			  return JS_DIR_CENTERED;
		  }
	  }
	  return -2; // -1, 1, 0 are already used
}
