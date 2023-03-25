/*
 * game_engine.h
 *
 * macros used to create the game
 */

#ifndef INC_GAME_ENGINE_H_
#define INC_GAME_ENGINE_H_

#include "game-objects-inc/asteroid.h"
#include "game-objects-inc/earth.h"
#include "game-objects-inc/spaceship.h"
#include "peripheral-drivers-inc/drivers.h"
#include "stm32f4xx_hal.h"
#include "vector.h"
#include "joystick.h"
#include "oled.h"
#include "math.h"
#include <stdio.h>

/* Frame */
#define CLEAR_FRAME 0
#define SET_FRAME 1

/* Shoot and thrust */
#define SHOOT_BUTTON_PORT	GPIOF
#define SHOOT_BUTTON_PIN	GPIO_PIN_13

#define THRUST_BUTTON_PORT	GPIOF
#define THRUST_BUTTON_PIN	GPIO_PIN_14

/* Joystick inputs */
#define JOYSTICK_ADC	ADC1
#define JOYSTICK_ADC_X_CHANNEL	ADC_CHANNEL_11
#define JOYSTICK_ADC_Y_CHANNEL	ADC_CHANNEL_14

/* Firing rockets and asteroid */
#define PLAYER_INITIAL_SPEED	0
#define PLAYER_BASE_ACCELERATION	1
#define PLAYER_BASE_DECELERATION	0.1
#define PLAYER_MAX_SPEED	5
#define ASTEROID_BASE_SPEED	1
#define ROCKET_BASE_SPEED	3	// Using ROCKET_12x12[] as the rocket that is fired whcich is nothing but ASTEROID_12x12
#define ROCKET_LIFESPAN	30		// Lifespan of the fired rocket

/* Sizes of asteroids used in the game */
#define ASTEROID_SIZE_L	0	// Using ASTEROID_24x24[]
#define ASTEROID_SIZE_M	1	// Using ASTEROID_16x16[]

/* Directions */
#define HEADING_N	1
#define HEADING_S	2
#define HEADING_E	3
#define HEADING_W	4
#define HEADING_NE	5
#define HEADING_NW	6
#define HEADING_SE	7
#define HEADING_SW	8

/* BITMAP images sizes of game characters */
#define ASTEROID_BMP_SIZE_L_WIDTH	24
#define ASTEROID_BMP_SIZE_L_HEIGHT	24
#define ASTEROID_BMP_SIZE_M_WIDTH	16
#define ASTEROID_BMP_SIZE_M_HEIGHT	16

// Size of spaceship BMP is 24x24 px and rocket BMP is 12x12 px
// for cardinal and non-cardinal directions so same width for both
#define SPACESHIP_BMP_WIDTH	24
#define SPACESHIP_BMP_HEIGHT	24
#define ROCKET_BMP_WIDTH	12
#define ROCKET_BMP_HEIGHT	12

// Tip of spaceship from where the rocket is fired is at (spaceship_width/2, spaceship_height = 0)
#define ROCKET_N_START_X_POS	(SPACESHIP_BMP_WIDTH)/2
#define ROCKET_N_START_Y_POS	-ROCKET_BMP_HEIGHT
#define ROCKET_S_START_X_POS	(SPACESHIP_BMP_WIDTH)/2
#define ROCKET_S_START_Y_POS	ROCKET_BMP_HEIGHT
#define ROCKET_E_START_X_POS	SPACESHIP_BMP_WIDTH
#define ROCKET_E_START_Y_POS	(SPACESHIP_BMP_HEIGHT)/2
#define ROCKET_W_START_X_POS	-ROCKET_BMP_HEIGHT
#define ROCKET_W_START_Y_POS	(SPACESHIP_BMP_HEIGHT)/2

#define ROCKET_NE_START_X_POS	SPACESHIP_BMP_WIDTH
#define ROCKET_NE_START_Y_POS	-ROCKET_BMP_HEIGHT
#define ROCKET_SE_START_X_POS	SPACESHIP_BMP_WIDTH
#define ROCKET_SE_START_Y_POS	SPACESHIP_BMP_HEIGHT
#define ROCKET_NW_START_X_POS	-ROCKET_BMP_WIDTH
#define ROCKET_NW_START_Y_POS	-ROCKET_BMP_HEIGHT
#define ROCKET_SW_START_X_POS	-ROCKET_BMP_WIDTH
#define ROCKET_SW_START_Y_POS	SPACESHIP_BMP_HEIGHT

/* Spaceship is alive */
#define ALIVE_FALSE 2
#define ALIVE_TRUE 1
#define ALIVE_UNSET 0

/* Other declarations */
#define DEAD_OBJECT_UNDECLARED 0
#define DEAD_OBJECT_DECLARED 1

#define COLLISION_TRUE 1
#define COLLISION_FALSE 0

#define FIRST_TIME_TRUE 1
#define FIRST_TIME_FALSE 0

#define ASTEROID_BUFFER_SIZE 15
#define ROCKET_BUFFER_SIZE 3

#define MARGIN 0

#define NUM_OF_WAVE 5

/* Structures */
typedef struct {
	int16_t x;
	int16_t y;
	double dx;
	double dy;
	uint8_t headingDir;
	uint8_t aliveFlag;
	uint8_t lifeSpan;
	uint8_t asteroidSize;
} Object_Property_t;

typedef struct {
	uint8_t imageWidth;
	uint8_t imageHeight;
	const unsigned char* bitmapImage;
	uint8_t clearWhenDead;
} Object_Image_t;

typedef struct {
	Object_Property_t Object_Property;
	Object_Image_t Object_Image;
} Space_Object_t;


/* Function prototypes */
void game_init(void);

void start_frame_update(void);

void create_player_spaceship(Space_Object_t* playerSpaceShipPtr);
void create_asteroid(vector* asteroidVectorPtr, Space_Object_t* asteroidPtr, uint8_t numberOfAsteroids, Space_Object_t* playerSpaceShipPtr);
void create_rocket(vector *rocketVectorPtr, Space_Object_t* rocketPtr, Space_Object_t* playerSpaceShipPtr);

void draw_player_spaceship(Space_Object_t* playerSpaceShipPtr);
void draw_asteroid(vector* asteroidVectorPtr);
void draw_rocket(vector* rocketVectorPtr);

void update_player_spaceship(Space_Object_t* playerSpaceShipPtr);
void update_asteroid(vector* asteroidVectorPtr, Space_Object_t* playerSpaceShipPtr);
void update_rocket(vector* rocketVectorPtr, vector* asteroidVectorPtr);

void display_black_background(void);
void display_start_screen(void);
void display_score(void);
void display_game_over_screen(void);

void reset_game(void);

#endif /* INC_GAME_ENGINE_H_ */
