/*
 * tests.c
 *
 *  Created on: Jan 28, 2023
 *      Author: rohitimandi
 */

/* // Joystick test inside main while loop
//	  HAL_ADC_Start_DMA(&hadc1,(uint32_t *) adc_buf, 2);
//	  vr_x = adc_buf[1];
//	  vr_y = adc_buf[0];
//	  control_led(adc_buf[1], adc_buf[0]);
*/



/* Inside main function() and not in while loop
 *
//  ssd1306_Init();
//  HAL_Delay(20);

//  ssd1306_Fill(White);
//  ssd1306_UpdateScreen();
//  HAL_Delay(100);

//  ssd1306_SetCursor(20, 20);
//  ssd1306_WriteString("Hello", Font_7x10, White);
//  ssd1306_UpdateScreen();
//  HAL_Delay(1000);
//
//  ssd1306_Clear();
//  ssd1306_SetCursor(0, 0);

//  ssd1306_DrawBitmap(0, 0, EARTH_STRETCH, 128, 64, White);
//  ssd1306_UpdateScreen();
//  HAL_Delay(2000);
//  ssd1306_Clear();

//  ssd1306_DrawBitmap(0, 0, EARTH_SCALE_To_FIT, 128, 64, White);
//  ssd1306_UpdateScreen();
//  HAL_Delay(2000);
//  ssd1306_Clear();

//  ssd1306_DrawBitmap(0, 0, ASTEROID_12x12, 12, 12, White);
//  ssd1306_DrawBitmap(16, 0, ASTEROID_16x16, 16, 16, White);
//  ssd1306_DrawBitmap(30, 0, ASTEROID_24x24, 24, 24, White);
//  ssd1306_DrawBitmap(54, 0, ASTEROID_EXPLOSION_16x16, 16, 16, White);
//  ssd1306_DrawBitmap(70, 0, ASTEROID_EXPLOSION_24x24, 24, 24, White);
//  ssd1306_DrawBitmap(90, 0, ASTEROID_EXPLOSION_2_24x24, 24, 24, White);
//
//  ssd1306_DrawBitmap(0, 10, ROCKET_12x12, 12, 12, White);
//
//  ssd1306_DrawBitmap(0, 20, SPACESHIP_12x12_NORTH, 12, 12, White);
//
//  ssd1306_DrawBitmap(10, 20, SPACESHIP_16x16_NORTH, 12, 12, White);
//
//  ssd1306_DrawBitmap(20, 20, SPACESHIP_24x24_NORTH, 24, 24, White);
//  ssd1306_DrawBitmap(40, 20, SPACESHIP_24x24_EAST, 24, 24, White);
//  ssd1306_DrawBitmap(60, 20, SPACESHIP_24x24_SOUTH, 24, 24, White);
//  ssd1306_DrawBitmap(80, 20, SPACESHIP_24x24_WEST, 24, 24, White);
//
//  ssd1306_DrawBitmap(100, 20, SPACESHIP_24x24_NORTH_EAST, 24, 24, White);
//  ssd1306_DrawBitmap(0, 40, SPACESHIP_24x24_NORTH_WEST, 24, 24, White);
//  ssd1306_DrawBitmap(20, 40, SPACESHIP_24x24_SOUTH_EAST, 24, 24, White);
//  ssd1306_DrawBitmap(40, 40, SPACESHIP_24x24_SOUTH_WEST, 24, 24, White);
//  ssd1306_DrawBitmap(70, 30, SPACESHIP_32x32, 32, 32, White);
//  ssd1306_UpdateScreen();
//  HAL_Delay(5000);
//  ssd1306_Clear();
//
//  ssd1306_DrawBitmap(0, 0, SPACESHIP_EXPLOSION_128x64, 128, 64, White);
//  ssd1306_UpdateScreen();
*/


/*
 * B1, B2 and OLED test inside main while loop
	  // B1, B2 and OLED Test
//	  if (HAL_GPIO_ReadPin(GPIO_Input_B1_GPIO_Port, GPIO_Input_B1_Pin) == GPIO_PIN_RESET){
//		  HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_SET);
//
//		  ssd1306_Clear();
//		  ssd1306_DrawBitmap(0, 0, ASTEROID_12x12, 12, 12, White);
//		  ssd1306_DrawBitmap(16, 0, ASTEROID_16x16, 16, 16, White);
//		  ssd1306_DrawBitmap(30, 0, ASTEROID_24x24, 24, 24, White);
//		  ssd1306_DrawBitmap(54, 0, ASTEROID_EXPLOSION_16x16, 16, 16, White);
//		  ssd1306_DrawBitmap(70, 0, ASTEROID_EXPLOSION_24x24, 24, 24, White);
//		  ssd1306_DrawBitmap(90, 0, ASTEROID_EXPLOSION_2_24x24, 24, 24, White);
//		  ssd1306_DrawBitmap(40, 30, ROCKET_24x24, 24, 24, White);
//		  ssd1306_DrawBitmap(60, 30, ROCKET_32x32, 32, 32, White);
//		  ssd1306_UpdateScreen();
//	  }
//	  else {
//		  HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_RESET);
//	  }
//
//	  if (HAL_GPIO_ReadPin(GPIO_Input_B2_GPIO_Port, GPIO_Input_B2_Pin) == GPIO_PIN_RESET){
//		  HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_SET);
//
//		  ssd1306_Clear();
//		  ssd1306_DrawBitmap(0, 0, ROCKET_EXPLOSION_128x64, 128, 64, White);
//		  ssd1306_UpdateScreen();
//	  }
//	  else {
//	  		  HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_RESET);
//	  }
 */
