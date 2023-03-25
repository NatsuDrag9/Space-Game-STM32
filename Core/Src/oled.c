#include "oled.h"

/* Variables */
GameObject asteroid_medium = {16, 5, 16, 16, ASTEROID_16x16};
GameObject spaceship_east = {16, 20, 24, 24, SPACESHIP_24x24_EAST};
GameObject* list_gameObjects[num_gameObjects] = {&spaceship_east};

/* Initializes SPI and the OLED */
void oled_init(){
	ssd1306_Init();
	HAL_Delay(20);
}

/* Changes OLED background to white */
void oled_fillWhite(){
	  ssd1306_Fill(White);
	  ssd1306_UpdateScreen();
	  HAL_Delay(100);
}

/* Displays content on the OLED */
void oled_display(){
	ssd1306_DrawBitmap(asteroid_medium.x, asteroid_medium.y, asteroid_medium.bitmap, asteroid_medium.width, asteroid_medium.height, White);
	HAL_Delay(1000);
//	  ssd1306_SetCursor(20, 20);
//	  ssd1306_WriteString("Hello", Font_7x10, White);
//	  ssd1306_UpdateScreen();
//	  HAL_Delay(1000);
//
//	  ssd1306_Clear(100);
//	  ssd1306_SetCursor(0, 0);
//
//	  ssd1306_DrawBitmap(0, 0, EARTH_SCALE_To_FIT, 128, 64, White);
//	  ssd1306_UpdateScreen();
//	  HAL_Delay(2000);
//	  ssd1306_Clear(100);
//
//	  ssd1306_DrawBitmap(0, 0, ASTEROID_12x12, 12, 12, White);
//	  ssd1306_DrawBitmap(16, 0, ASTEROID_16x16, 16, 16, White);
//	  ssd1306_DrawBitmap(30, 0, ASTEROID_24x24, 24, 24, White);
//	  ssd1306_DrawBitmap(54, 0, ASTEROID_EXPLOSION_16x16, 16, 16, White);
//	  ssd1306_DrawBitmap(70, 0, ASTEROID_EXPLOSION_24x24, 24, 24, White);
//	  ssd1306_DrawBitmap(90, 0, ASTEROID_EXPLOSION_2_24x24, 24, 24, White);
//
//	   ssd1306_DrawBitmap(0, 10, ROCKET_12x12, 12, 12, White);
//
//	   ssd1306_DrawBitmap(0, 20, SPACESHIP_12x12_NORTH, 12, 12, White);
//
//	   ssd1306_DrawBitmap(10, 20, SPACESHIP_16x16_NORTH, 12, 12, White);
//
//	   ssd1306_DrawBitmap(20, 20, SPACESHIP_24x24_NORTH, 24, 24, White);
//	   ssd1306_DrawBitmap(40, 20, SPACESHIP_24x24_EAST, 24, 24, White);
//	   ssd1306_DrawBitmap(60, 20, SPACESHIP_24x24_SOUTH, 24, 24, White);
//	   ssd1306_DrawBitmap(80, 20, SPACESHIP_24x24_WEST, 24, 24, White);
//
//	   ssd1306_DrawBitmap(100, 20, SPACESHIP_24x24_NORTH_EAST, 24, 24, White);
//	   ssd1306_DrawBitmap(0, 40, SPACESHIP_24x24_NORTH_WEST, 24, 24, White);
//	   ssd1306_DrawBitmap(20, 40, SPACESHIP_24x24_SOUTH_EAST, 24, 24, White);
//	   ssd1306_DrawBitmap(40, 40, SPACESHIP_24x24_SOUTH_WEST, 24, 24, White);
//	 //  ssd1306_DrawBitmap(70, 30, SPACESHIP_32x32, 32, 32, White);
//	   ssd1306_UpdateScreen();
//	   HAL_Delay(5000);
//	   ssd1306_Clear(100);
//
//	   ssd1306_DrawBitmap(0, 0, SPACESHIP_EXPLOSION_128x64, 128, 64, White);
//	   ssd1306_UpdateScreen();
//	   HAL_Delay(5000);
}

///*
// * Draws game objects that continuously move out from one side
// * and reappear on the other side
// */
//void oled_drawGameObjects(){
//	ssd1306_Clear(20);
//	for (int y = 0; y < SSD1306_HEIGHT; y++){
//		// Iterates through all y coordinates of the screen
//		for (int index_gameObject = 0; index_gameObject < num_gameObjects; index_gameObject++){
//			GameObject* current_gameObject = list_gameObjects[index_gameObject];
//			if (y >= current_gameObject->y && (y < (current_gameObject->y + current_gameObject->height))){ // Game object found
//				int endX = current_gameObject->x + current_gameObject->width;	// x bound of the game object
//				if (current_gameObject->x < SSD1306_WIDTH && endX > 0){
//					// Checks whether the game object's x coordinate is within the width of the screen
//					int xBitmapOffset = 0;
//					int xStart = 0;
//					if (current_gameObject->x < 0) {
//						xBitmapOffset -= current_gameObject->x;
//					}
//					if (current_gameObject->x > 0) {
//						xStart = current_gameObject->x;
//					}
//					int yBitmapOffset = (y - current_gameObject->y) * current_gameObject->width;	// Multiplying by width because the y-offset is the entire row for the current iterating y coordinate
//
//					for (int x = xStart; x < endX && x < SSD1306_WIDTH; x++) {
//						// Iterates through the x bound of the game object
//						bool drawPixel = current_gameObject->bitmap[xBitmapOffset + yBitmapOffset++];
//						if (drawPixel){
//							// Draws the pixel on the screen if found in the bitmap
//							ssd1306_DrawPixel(x, y, White);
//						}
//					}
//				}
//			}
//		}
//	}
//}


/* B1, B2 and OLED test */
void oled_buttonDisplay(){

	if (!button_readPin(GPIO_Input_B1_GPIO_Port, GPIO_Input_B1_Pin)) {
		asteroid_medium.x += 1;	// Changes the speed of the game object; larger value implies faster movement
		if (asteroid_medium.x > SSD1306_WIDTH){
			asteroid_medium.x = asteroid_medium.x - SSD1306_WIDTH;
		}
		HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_SET);
		ssd1306_Clear(20);
		ssd1306_DrawBitmap(asteroid_medium.x, asteroid_medium.y, asteroid_medium.bitmap, asteroid_medium.width, asteroid_medium.height, White);
		ssd1306_UpdateScreen();
//		ssd1306_Clear(500);
//		ssd1306_DrawBitmap(0, 0, ASTEROID_12x12, 12, 12, White);
//		ssd1306_DrawBitmap(16, 0, ASTEROID_16x16, 16, 16, White);
//		ssd1306_DrawBitmap(30, 0, ASTEROID_24x24, 24, 24, White);
//		ssd1306_DrawBitmap(54, 0, ASTEROID_EXPLOSION_16x16, 16, 16, White);
//		ssd1306_DrawBitmap(70, 0, ASTEROID_EXPLOSION_24x24, 24, 24, White);
//		ssd1306_DrawBitmap(90, 0, ASTEROID_EXPLOSION_2_24x24, 24, 24, White);
//		ssd1306_DrawBitmap(40, 30, ROCKET_12x12, 12, 12, White);
//		ssd1306_UpdateScreen();
//		HAL_Delay(2000);
//
//		ssd1306_ScrollLeft(PAGE0, PAGE3);
//		HAL_Delay(5000);
//		ssd1306_StopScroll();
//		HAL_Delay(2000);
//
//		ssd1306_ScrollDiagLeft(0x0A, 0x10, PAGE3, PAGE5);
//		HAL_Delay(5000);
//		ssd1306_StopScroll();
//		HAL_Delay(2000);
	  }
	  else {
		  HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_RESET);
	  }

	  if (!button_readPin(GPIO_Input_B2_GPIO_Port, GPIO_Input_B2_Pin)) {
		  asteroid_medium.y += 1;	// Height of the game object; larger value implies faster movement
		  if (asteroid_medium.y > SSD1306_HEIGHT){
			  asteroid_medium.y = asteroid_medium.y - SSD1306_HEIGHT;
		  }
		  HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_SET);
		  ssd1306_Clear(20);
		  ssd1306_DrawBitmap(asteroid_medium.x, asteroid_medium.y, asteroid_medium.bitmap, asteroid_medium.width, asteroid_medium.height, White);
		  ssd1306_UpdateScreen();

//		  ssd1306_Clear(100);
//		  ssd1306_DrawBitmap(0, 0, SPACESHIP_EXPLOSION_128x64, 128, 64, White);
//		  ssd1306_UpdateScreen();
//		  HAL_Delay(2000);
//
//		  ssd1306_ScrollRight(PAGE0, PAGE3);
//		  HAL_Delay(5000);
//		  ssd1306_StopScroll();
//		  HAL_Delay(2000);
//
//		  ssd1306_ScrollDiagRight(0x0A, 0x10, PAGE3, PAGE5);
//		  HAL_Delay(5000);
//		  ssd1306_StopScroll();
//		  HAL_Delay(2000);

	  }
	  else {
		  HAL_GPIO_WritePin(LD3_Red_GPIO_Port, LD3_Red_Pin, GPIO_PIN_RESET);
	  }

//	  oled_drawGameObjects();

}
