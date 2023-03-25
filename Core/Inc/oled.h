/*
 * oled.h
 *
 *  Created on: Jan 31, 2023
 *      Author: rohitimandi
 */

#ifndef INC_OLED_H_
#define INC_OLED_H_

#include "peripheral-drivers-inc/drivers.h"
#include "game-objects-inc/asteroid.h"
#include "game-objects-inc/earth.h"
#include "game-objects-inc/spaceship.h"
#include "ssd1306.h"
#include <stdbool.h>

/* Macros */
#define num_gameObjects 1

/* Data structure for the game object */
typedef struct {
	int x;	// X coordinate (top left corner) of where the game object is placed in the screen
	int y;	// Y coordinate (top left corner) of where the game object is placed in the screen
	int width; // Width of the sprite
	int height; // Height of the sprite
	const unsigned char* bitmap; // Array of 0's and 1's that creates the game object on the screen
} GameObject;

/* Game objects */
GameObject asteroid_medium;
GameObject spaceship_east;
GameObject* list_gameObjects[num_gameObjects];

/* OLED function prototype */
void oled_init();
void oled_fillWhite();
void oled_display();
void oled_buttonDisplay();
void oled_drawGameObjects();

#endif /* INC_OLED_H_ */
