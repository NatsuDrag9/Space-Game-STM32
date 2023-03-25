#include "game_engine.h"

/* Private function prototypes */
int16_t game_random_x(void);
int16_t game_random_y(void);
int8_t game_random_sign(void);

void wrap_coordinate(int16_t* xPtr, int16_t* yPtr);
void update_spaceship_dir(Space_Object_t* playerSpaceShipPtr);
void update_spaceship_pos(Space_Object_t* playerSpaceShipPtr);
void delete_dead_rocket(Space_Object_t* rocketPtr);
void delete_dead_asteroid(Space_Object_t* asteroidPtr);
uint8_t collision_detect(Space_Object_t* object1Ptr, Space_Object_t* object2Ptr);
void accelerate_player_spaceship(Space_Object_t* playerSpaceShipPtr, int8_t ddx, int8_t ddy);
void create_medium_asteroid(vector* asteroidVectorPtr, Space_Object_t* deadAsteroidPtr);

/* Global variables */
uint8_t frameUpdate = CLEAR_FRAME;
int16_t currentScore = 0;
int16_t prevScore = 0;
char displayScore[15];

uint8_t shootButtonFirstTimeFlag = FIRST_TIME_TRUE;

Space_Object_t playerSpaceShip;
volatile Space_Object_t asteroid[ASTEROID_BUFFER_SIZE];
Space_Object_t rocket[ROCKET_BUFFER_SIZE];

vector asteroidVector;
vector rocketVector;

uint8_t currentWave = 1;
uint8_t numOfAsteroidInWave[NUM_OF_WAVE] = {1, 2, 3, 4, 5};

/* Initialize game engine */
void game_init(){
	vector_init(&asteroidVector);	// Initialize asteroid vector
	vector_init(&rocketVector);		// Initialize rocket vector
}

/* Start updating game screen */
void start_frame_update(void){
	HAL_TIM_Base_Start_IT(&htim4);
}

/* Create player spaceship */
void create_player_spaceship(Space_Object_t* playerSpaceShipPtr){
	playerSpaceShipPtr->Object_Property.x = 30;
	playerSpaceShipPtr->Object_Property.y = 10;

	playerSpaceShipPtr->Object_Property.dx = 0;
	playerSpaceShipPtr->Object_Property.dy = 0;

	playerSpaceShipPtr->Object_Property.headingDir = HEADING_N;
	playerSpaceShipPtr->Object_Property.aliveFlag = ALIVE_TRUE;
	playerSpaceShipPtr->Object_Property.lifeSpan = 0;

	playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_NORTH;
	playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
	playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
}

/* Create asteroid */
void create_asteroid(vector* asteroidVectorPtr, Space_Object_t* asteroidPtr,
		uint8_t numberOfAsteroids, Space_Object_t* playerSpaceShipPtr) {

	Space_Object_t* prevAsteroidPtr = NULL;
	uint8_t check1 = 0, check2 = 0;

	for (uint8_t count = 0; count < numberOfAsteroids; count++, asteroidPtr++){
		vector_add(asteroidVectorPtr, (void*) asteroidPtr);	// stores the address of asteroid to be created in the asteroid vector

//		asteroidPtr->Object_Image.bitmapImage = ASTEROID_16x16;
//		asteroidPtr->Object_Image.imageHeight = ASTEROID_BMP_SIZE_M_HEIGHT;
//		asteroidPtr->Object_Image.imageWidth = ASTEROID_BMP_SIZE_M_WIDTH;
//		asteroidPtr->Object_Image.clearWhenDead = DEAD_OBJECT_UNDECLARED;
		asteroidPtr->Object_Image.bitmapImage = ASTEROID_24x24;
		asteroidPtr->Object_Image.imageHeight = ASTEROID_BMP_SIZE_L_HEIGHT;
		asteroidPtr->Object_Image.imageWidth = ASTEROID_BMP_SIZE_L_WIDTH;
		asteroidPtr->Object_Image.clearWhenDead = DEAD_OBJECT_UNDECLARED;

		// Randomize asteroid's position until the created asteroid doesn't
		// collide with player and other asteroids
		do {
			check1 = COLLISION_FALSE;
			check2 = COLLISION_FALSE;

			asteroidPtr->Object_Property.x = game_random_x();
			asteroidPtr->Object_Property.y = game_random_y();

			check1 = collision_detect(asteroidPtr, playerSpaceShipPtr);
			if (check1 == COLLISION_TRUE){
				continue;
			}

			if (count == 0){
				// No need to check collision for first asteroid created
				break;
			}

			prevAsteroidPtr = asteroidPtr-1;	// Adjacent address as asteroidPtr is incremented with corresponding count

			for (uint8_t i = 0; i < count; i++, prevAsteroidPtr--){
				check2 = collision_detect(asteroidPtr, prevAsteroidPtr);
			}
		} while((check1 == COLLISION_TRUE) || (check2 == COLLISION_TRUE));

		asteroidPtr->Object_Property.dx = game_random_sign()*ASTEROID_BASE_SPEED;
		asteroidPtr->Object_Property.dy = game_random_sign()*ASTEROID_BASE_SPEED;
		asteroidPtr->Object_Property.aliveFlag = ALIVE_TRUE;
		asteroidPtr->Object_Property.lifeSpan = 0;
		asteroidPtr->Object_Property.asteroidSize = ASTEROID_SIZE_L;
	}
}

/* Create rocket */
void create_rocket(vector *rocketVectorPtr, Space_Object_t* rocketPtr,
		Space_Object_t* playerSpaceShipPtr){
	if(!button_readPin(SHOOT_BUTTON_PORT, SHOOT_BUTTON_PIN)){
		if (shootButtonFirstTimeFlag == FIRST_TIME_TRUE){
			HAL_TIM_Base_Start_IT(&htim2);

			shootButtonFirstTimeFlag = FIRST_TIME_FALSE;

			HAL_GPIO_WritePin(LD1_Green_GPIO_Port, LD1_Green_Pin, GPIO_PIN_SET); // Turning ON green LED for visual indication

			prevScore = currentScore;
			currentScore--;

			Space_Object_t* head = rocketPtr;

			while((rocketPtr->Object_Property.aliveFlag != ALIVE_FALSE) && (rocketPtr->Object_Property.aliveFlag != ALIVE_UNSET)){
				rocketPtr++;
				if(rocketPtr - head > (ROCKET_BUFFER_SIZE-1)){
					return;
				}
			}

			vector_add(rocketVectorPtr, rocketPtr);

			rocketPtr->Object_Property.aliveFlag = ALIVE_TRUE;
			rocketPtr->Object_Property.lifeSpan = ROCKET_LIFESPAN;
			rocketPtr->Object_Image.clearWhenDead = DEAD_OBJECT_UNDECLARED;

			if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_N){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_N_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_N_START_Y_POS;

				rocketPtr->Object_Property.dx = 0;
				rocketPtr->Object_Property.dy = -ROCKET_BASE_SPEED;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
			else if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_S){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_S_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_S_START_Y_POS;

				rocketPtr->Object_Property.dx = 0;
				rocketPtr->Object_Property.dy = ROCKET_BASE_SPEED;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
			else if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_E){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_E_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_E_START_Y_POS;

				rocketPtr->Object_Property.dx = ROCKET_BASE_SPEED;
				rocketPtr->Object_Property.dy = 0;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
			else if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_W){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_W_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_W_START_Y_POS;

				rocketPtr->Object_Property.dx = -ROCKET_BASE_SPEED;
				rocketPtr->Object_Property.dy = 0;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
			else if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_NE){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_NE_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_NE_START_Y_POS;

				rocketPtr->Object_Property.dx = ROCKET_BASE_SPEED;
				rocketPtr->Object_Property.dy = -ROCKET_BASE_SPEED;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
			else if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_SE){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_SE_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_SE_START_Y_POS;

				rocketPtr->Object_Property.dx = ROCKET_BASE_SPEED;
				rocketPtr->Object_Property.dy = ROCKET_BASE_SPEED;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
			else if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_NW){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_NW_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_NW_START_Y_POS;

				rocketPtr->Object_Property.dx = -ROCKET_BASE_SPEED;
				rocketPtr->Object_Property.dy = -ROCKET_BASE_SPEED;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
			else if (playerSpaceShipPtr->Object_Property.headingDir == HEADING_SW){
				rocketPtr->Object_Property.x = playerSpaceShipPtr->Object_Property.x + ROCKET_SW_START_X_POS;
				rocketPtr->Object_Property.y = playerSpaceShipPtr->Object_Property.y + ROCKET_SW_START_Y_POS;

				rocketPtr->Object_Property.dx = -ROCKET_BASE_SPEED;
				rocketPtr->Object_Property.dy = ROCKET_BASE_SPEED;

				rocketPtr->Object_Image.bitmapImage = ROCKET_12x12;
				rocketPtr->Object_Image.imageHeight = ROCKET_BMP_HEIGHT;
				rocketPtr->Object_Image.imageWidth = ROCKET_BMP_WIDTH;
			}
		}
	}
	else {
		HAL_GPIO_WritePin(LD1_Green_GPIO_Port, LD1_Green_Pin, GPIO_PIN_RESET); // Turning OFF green LED for visual indication
	}
}


/* Draws the created spaceship on OLED screen */
void draw_player_spaceship(Space_Object_t* playerSpaceShipPtr){

	ssd1306_Clear(5);
	ssd1306_DrawBitmap(playerSpaceShipPtr->Object_Property.x, playerSpaceShipPtr->Object_Property.y,
			playerSpaceShipPtr->Object_Image.bitmapImage, playerSpaceShipPtr->Object_Image.imageWidth,
			playerSpaceShipPtr->Object_Image.imageHeight, White);
	ssd1306_UpdateScreen();
}

/* Draws all the created asteroids on OLED screen */
void draw_asteroid(vector* asteroidVectorPtr){
	Space_Object_t* asteroidPtr = NULL;
	for (uint8_t count = 0; count < asteroidVectorPtr->total; count++){
		asteroidPtr = vector_get(asteroidVectorPtr, count);
//		ssd1306_Clear(5);
		ssd1306_DrawBitmap(asteroidPtr->Object_Property.x, asteroidPtr->Object_Property.y,
		asteroidPtr->Object_Image.bitmapImage, asteroidPtr->Object_Image.imageWidth,
		asteroidPtr->Object_Image.imageHeight, White);
		ssd1306_UpdateScreen();
	}
}

/* Draws the created rocket on OLED screen */
void draw_rocket(vector* rocketVectorPtr){
	Space_Object_t* rocketPtr = NULL;
	for (uint8_t count = 0; count < rocketVectorPtr->total; count++){
		rocketPtr = vector_get(rocketVectorPtr, count);
//		ssd1306_Clear(5);
		ssd1306_DrawBitmap(rocketPtr->Object_Property.x, rocketPtr->Object_Property.y,
		rocketPtr->Object_Image.bitmapImage, rocketPtr->Object_Image.imageWidth,
		rocketPtr->Object_Image.imageHeight, White);
		ssd1306_UpdateScreen();
	}
}

/* Update player spaceship information */
void update_player_spaceship(Space_Object_t* playerSpaceShipPtr){
	update_spaceship_dir(playerSpaceShipPtr);
	update_spaceship_pos(playerSpaceShipPtr);
}

/* Update active asteroid information */
void update_asteroid (vector* asteroidVectorPtr, Space_Object_t* playerSpaceShipPtr){
	Space_Object_t* asteroidPtr = NULL;
	Space_Object_t* otherAsteroidPtr = NULL;

	for (uint8_t count = 0; count < asteroidVectorPtr->total; count++){
		asteroidPtr = vector_get(asteroidVectorPtr, count);

		// Update current asteroid's position
		asteroidPtr->Object_Property.x += asteroidPtr->Object_Property.dx;
		asteroidPtr->Object_Property.y += asteroidPtr->Object_Property.dy;
		wrap_coordinate(&asteroidPtr->Object_Property.x, &asteroidPtr->Object_Property.y);

		// If there are more than one active asteroids check whether
		// the current asteroid collides with other asteroid
		if (asteroidVectorPtr->total > 1){
			for (uint8_t i = count+1; i < asteroidVectorPtr->total; i++){
				otherAsteroidPtr = vector_get(asteroidVectorPtr, i);

				if (otherAsteroidPtr->Object_Property.aliveFlag == ALIVE_TRUE){
					if (collision_detect(asteroidPtr, otherAsteroidPtr) == COLLISION_TRUE){
						// If collided both asteroids travel in opposite directions
						asteroidPtr->Object_Property.dx *= -1;
						asteroidPtr->Object_Property.dy *= -1;
						otherAsteroidPtr->Object_Property.dx *= -1;
						otherAsteroidPtr->Object_Property.dy *= -1;

						// Toggle all 3 LEDs once to indicate asteroid collision
						HAL_GPIO_TogglePin(LD1_Green_GPIO_Port, LD1_Green_Pin);
						HAL_GPIO_TogglePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin);
						HAL_GPIO_TogglePin(LD3_Red_GPIO_Port, LD3_Red_Pin);
						HAL_Delay(500);

					}
				}
			}
		}

		// Check whether the current asteroid collided with player spaceship
		if (collision_detect(asteroidPtr, playerSpaceShipPtr) == COLLISION_TRUE){

			// If collided then set player spaceship to dead and return to main loop
			playerSpaceShipPtr->Object_Property.aliveFlag = ALIVE_FALSE;

			// Toggle Red LED thrice to indicate death of player spaceship
//			HAL_GPIO_TogglePin(LD3_Red_GPIO_Port, LD3_Red_Pin);
//			HAL_Delay(500);
//			HAL_GPIO_TogglePin(LD3_Red_GPIO_Port, LD3_Red_Pin);
//			HAL_Delay(500);
//			HAL_GPIO_TogglePin(LD3_Red_GPIO_Port, LD3_Red_Pin);
//			HAL_Delay(500);
		}
	}
}

/* Update active rocket information */
void update_rocket(vector* rocketVectorPtr, vector* asteroidVectorPtr) {
	Space_Object_t* rocketPtr = NULL;
	Space_Object_t* asteroidPtr = NULL;

	for (uint8_t count = 0; count < rocketVectorPtr->total; count++){
		rocketPtr = vector_get(rocketVectorPtr, count);

		rocketPtr->Object_Property.lifeSpan--;

		rocketPtr->Object_Property.x += rocketPtr->Object_Property.dx;
		rocketPtr->Object_Property.y += rocketPtr->Object_Property.dy;
		wrap_coordinate(&rocketPtr->Object_Property.x, &rocketPtr->Object_Property.y);

		// If lifespan of rocket becomes 0 then set the rocket to dead
		// and remove it from rocket vector
		if (!(rocketPtr->Object_Property.lifeSpan)) {
			rocketPtr->Object_Property.aliveFlag = ALIVE_FALSE;
			delete_dead_rocket(rocketPtr);
			vector_delete(rocketVectorPtr, count);
			count--;
		}

		// If rocket hit a medium asteroid, set both as dead
		// and remove each of them from their respective vectors

		for (uint8_t i = 0; i < asteroidVectorPtr->total; i++){
			asteroidPtr = vector_get(asteroidVectorPtr, i);

			if (collision_detect(rocketPtr, asteroidPtr) == COLLISION_TRUE){
				prevScore = currentScore;
				currentScore += 5;

				rocketPtr->Object_Property.aliveFlag = ALIVE_FALSE;
				delete_dead_rocket(rocketPtr);
				vector_delete(rocketVectorPtr, count);
				count--;

				asteroidPtr->Object_Property.aliveFlag = ALIVE_FALSE;
				delete_dead_asteroid(asteroidPtr);
				vector_delete(asteroidVectorPtr, i);
				i--;

				// If large asteroid was hit then create two medium asteroids
				if (asteroidPtr->Object_Property.asteroidSize == ASTEROID_SIZE_L) {
//					create_medium_asteroid(asteroidVectorPtr, asteroidPtr);

					// Large asteroid hit by rocket LED indication
					HAL_GPIO_TogglePin(LD1_Green_GPIO_Port, LD1_Green_Pin);
					HAL_GPIO_TogglePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin);
					HAL_Delay(500);
					HAL_GPIO_TogglePin(LD1_Green_GPIO_Port, LD1_Green_Pin);
					HAL_GPIO_TogglePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin);
					HAL_Delay(500);
					break;
				}
				else if(asteroidPtr->Object_Property.asteroidSize == ASTEROID_SIZE_M) {

					// Medium asteroid hit by rocket LED indication
//					HAL_GPIO_TogglePin(LD1_Green_GPIO_Port, LD1_Green_Pin);
//					HAL_GPIO_TogglePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin);
//					HAL_Delay(500);
				}
			}
		}
	}
}

/* Display score */
void display_score(){
	char displayScore[15];
	sprintf(displayScore, "Score: %d", prevScore);
	ssd1306_SetCursor(70, 0);
	ssd1306_UpdateScreen();

	// If score is updated, clear old score before printing new score
	if (prevScore != currentScore){
		ssd1306_WriteString(displayScore, Font_6x8, Black);	// changing text color to black clears the old score
		ssd1306_UpdateScreen();

		sprintf(displayScore, "Score: %d", currentScore);
		ssd1306_WriteString(displayScore, Font_6x8, White);
		ssd1306_UpdateScreen();
//		HAL_Delay(10);
	}
	else {
		ssd1306_WriteString(displayScore, Font_6x8, White);
		ssd1306_UpdateScreen();
//		HAL_Delay(10);
	}
}

/* Display start screen */
void display_start_screen(){
	ssd1306_DrawBitmap(0, 0, EARTH_SCALE_To_FIT, 128, 64, White);
	ssd1306_UpdateScreen();
	HAL_Delay(3000);

	ssd1306_Clear(100);
	ssd1306_SetCursor(5, 10);
	ssd1306_WriteString("Press shoot button", Font_6x8, White);
	ssd1306_SetCursor(5, 20);
	ssd1306_WriteString("to start..", Font_6x8, White);
	ssd1306_UpdateScreen();
}

/* Display game over screen */
void display_game_over_screen(){
	ssd1306_DrawBitmap(0, 0, EARTH_SCALE_To_FIT, 128, 40, White);
	ssd1306_UpdateScreen();

	ssd1306_SetCursor(0, 45);
	ssd1306_WriteString("Game over!! Try again?", Font_6x8, White);
	ssd1306_UpdateScreen();
}


/* Preparation before resetting game */
void reset_game(){
	currentScore = 0;
	prevScore = 0;
	frameUpdate = CLEAR_FRAME;
//	MX_RNG_Init();
	HAL_TIM_Base_Stop_IT(&htim4);
	currentWave = 0;

	for (uint8_t count = 0; count < asteroidVector.total;) {
		vector_delete(&asteroidVector, count);
	}

	for (uint8_t count = 0; count < rocketVector.total;) {
		vector_delete(&rocketVector, count);
	}

	for (uint8_t count = 0; count < ASTEROID_BUFFER_SIZE; count++) {
		asteroid[count].Object_Property.aliveFlag = ALIVE_FALSE;
	}

	for (uint8_t count = 0; count < ROCKET_BUFFER_SIZE; count++) {
		rocket[count].Object_Property.aliveFlag = ALIVE_FALSE;
	}
}

/* Wrap co-ordinate */
void wrap_coordinate(int16_t* xPtr, int16_t* yPtr){
	if (*xPtr < 0) {
		*xPtr += SSD1306_WIDTH;
	}

	if (*xPtr >= SSD1306_WIDTH && *yPtr > 1 && *yPtr < SSD1306_HEIGHT) {
		*xPtr -= SSD1306_WIDTH;
	}

	if (*xPtr >= 68 && *yPtr < 1) {
		*yPtr += SSD1306_HEIGHT; // avoiding overlap of game character and score displayed on OLED
	}

	if (*yPtr < 0) {
		*yPtr += SSD1306_HEIGHT;
	}

	if (*yPtr >= SSD1306_HEIGHT) {
		*yPtr -= SSD1306_HEIGHT;
	}
}

/* Random value of x from RNG */
int16_t game_random_x(){
	uint32_t x_randomNumber;
	generate_randomNumber(&x_randomNumber);
	x_randomNumber = (x_randomNumber & 0x1FF) % (SSD1306_WIDTH+1);
	return (int16_t) x_randomNumber;
}

/* Random value of y from RNG */
int16_t game_random_y(){
	uint32_t y_randomNumber;
	generate_randomNumber(&y_randomNumber);
	y_randomNumber = (y_randomNumber & 0xFF) % (SSD1306_HEIGHT+1);
	return (int16_t) y_randomNumber;
}

/* Random value of sign from RNG */
int8_t game_random_sign(){
	uint32_t sign_randomNumber;
	generate_randomNumber(&sign_randomNumber);
	int8_t temp = (sign_randomNumber & 0x0F) % 9;
	if (temp < 5){
		return -1;
	}
	return 1;
}

/* Update player spaceship direction */
void update_spaceship_dir(Space_Object_t* playerSpaceShipPtr){
	uint8_t direction = 0;
	direction = joystick_read_direction();
//	ssd1306_SetCursor(10, 10);

	if (direction == JS_DIR_CENTERED){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_CENTERED", Font_6x8, White);
//		ssd1306_UpdateScreen();
		return;
	}
	else if (direction == JS_DIR_UP){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_UP", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_N;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_NORTH;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
	else if (direction == JS_DIR_DOWN){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_DOWN", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_S;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_SOUTH;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
	else if (direction == JS_DIR_RIGHT){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_RIGHT", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_E;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_EAST;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
	else if (direction == JS_DIR_LEFT){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_LEFT", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_W;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_WEST;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
	else if (direction == JS_DIR_RIGHT_UP){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_RIGHT_UP", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_NE;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_NORTH_EAST;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
	else if (direction == JS_DIR_RIGHT_DOWN){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_RIGHT_DOWN", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_SE;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_SOUTH_EAST;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
	else if (direction == JS_DIR_LEFT_UP){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_LEFT_UP", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_NW;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_NORTH_WEST;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
	else if (direction == JS_DIR_LEFT_DOWN){
//		ssd1306_Clear(5);
//		ssd1306_WriteString("JS_DIR_LEFT_DOWN", Font_6x8, White);
//		ssd1306_UpdateScreen();
		playerSpaceShipPtr->Object_Property.headingDir = HEADING_SW;
		playerSpaceShipPtr->Object_Image.bitmapImage = SPACESHIP_24x24_SOUTH_WEST;
		playerSpaceShipPtr->Object_Image.imageWidth = SPACESHIP_BMP_WIDTH;
		playerSpaceShipPtr->Object_Image.imageHeight = SPACESHIP_BMP_HEIGHT;
		return;
	}
}


/* Update player spaceship position */
void update_spaceship_pos(Space_Object_t* playerSapceShipPtr){
	if (!button_readPin(THRUST_BUTTON_PORT, THRUST_BUTTON_PIN)){
		int8_t ddx = 0;
		int8_t ddy = 0;

		// Indicates that the thrust button was pressed
		HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_SET);

		if (playerSapceShipPtr->Object_Property.headingDir == HEADING_N){
			ddx = 0;
			ddy = -PLAYER_BASE_ACCELERATION;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}
		else if (playerSapceShipPtr->Object_Property.headingDir == HEADING_S){
			ddx += 0;
			ddy += PLAYER_BASE_ACCELERATION;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}
		else if (playerSapceShipPtr->Object_Property.headingDir == HEADING_E){
			ddx += PLAYER_BASE_ACCELERATION;
			ddy += 0;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}
		else if (playerSapceShipPtr->Object_Property.headingDir == HEADING_W){
			ddx += -PLAYER_BASE_ACCELERATION;
			ddy += 0;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}
		else if (playerSapceShipPtr->Object_Property.headingDir == HEADING_NE){
			ddx += PLAYER_BASE_ACCELERATION;
			ddy += -PLAYER_BASE_ACCELERATION;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}
		else if (playerSapceShipPtr->Object_Property.headingDir == HEADING_NW){
			ddx += -PLAYER_BASE_ACCELERATION;
			ddy += -PLAYER_BASE_ACCELERATION;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}
		else if (playerSapceShipPtr->Object_Property.headingDir == HEADING_SE){
			ddx += PLAYER_BASE_ACCELERATION;
			ddy += PLAYER_BASE_ACCELERATION;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}
		else if (playerSapceShipPtr->Object_Property.headingDir == HEADING_SW){
			ddx += -PLAYER_BASE_ACCELERATION;
			ddy += PLAYER_BASE_ACCELERATION;
			accelerate_player_spaceship(playerSapceShipPtr, ddx, ddy);
		}

	}
	else{
		HAL_GPIO_WritePin(LD2_Blue_GPIO_Port, LD2_Blue_Pin, GPIO_PIN_RESET);

		playerSapceShipPtr->Object_Property.x += playerSapceShipPtr->Object_Property.dx;
		playerSapceShipPtr->Object_Property.y += playerSapceShipPtr->Object_Property.dy;
		wrap_coordinate(&playerSapceShipPtr->Object_Property.x, &playerSapceShipPtr->Object_Property.y);

		// decelerate player spaceship
		if (fabs(playerSapceShipPtr->Object_Property.dx) > PLAYER_BASE_DECELERATION){
			if (playerSapceShipPtr->Object_Property.dx > 0){
				playerSapceShipPtr->Object_Property.dx -= PLAYER_BASE_DECELERATION;
			}
			else if (playerSapceShipPtr->Object_Property.dx < 0){
				playerSapceShipPtr->Object_Property.dx += PLAYER_BASE_DECELERATION;
			}
		}
		else {
			playerSapceShipPtr->Object_Property.dx = 0;
		}

		if (fabs(playerSapceShipPtr->Object_Property.dy) > PLAYER_BASE_DECELERATION){
			if (playerSapceShipPtr->Object_Property.dy > 0){
				playerSapceShipPtr->Object_Property.dy -= PLAYER_BASE_DECELERATION;
			}
			else if (playerSapceShipPtr->Object_Property.dy < 0){
				playerSapceShipPtr->Object_Property.dy += PLAYER_BASE_DECELERATION;
			}
		}
		else {
			playerSapceShipPtr->Object_Property.dy = 0;
		}
	}
}


/* Collision detect using AABB algorithm */
uint8_t collision_detect(Space_Object_t* object1Ptr, Space_Object_t* object2Ptr){
	int16_t object1BottomRight_x = object1Ptr->Object_Property.x + object1Ptr->Object_Image.imageWidth-10;
	int16_t object1BottomRight_y = object1Ptr->Object_Property.y + object1Ptr->Object_Image.imageHeight-10;

	int16_t object2BottomRight_x = object2Ptr->Object_Property.x + object2Ptr->Object_Image.imageWidth-10;
	int16_t object2BottomRight_y = object2Ptr->Object_Property.y + object2Ptr->Object_Image.imageHeight-10;

	// Collision occurs when the edges of the two objects overlap
	if(object1Ptr->Object_Property.x < object2BottomRight_x
			&& object2Ptr->Object_Property.x < object1BottomRight_x
			&& object1Ptr->Object_Property.y < object2BottomRight_y
			&& object2Ptr->Object_Property.y < object1BottomRight_y){

		return COLLISION_TRUE;
	}
	else {
		return COLLISION_FALSE;
	}
}

/* Delete dead rocket */
void delete_dead_rocket(Space_Object_t* rocketPtr){
	if((rocketPtr->Object_Property.aliveFlag == ALIVE_FALSE) && (rocketPtr->Object_Image.clearWhenDead == DEAD_OBJECT_UNDECLARED)){
//		ssd1306_Clear(5);
		ssd1306_DrawBitmap(rocketPtr->Object_Property.x, rocketPtr->Object_Property.y, rocketPtr->Object_Image.bitmapImage,
				rocketPtr->Object_Image.imageWidth, rocketPtr->Object_Image.imageHeight, Black);
		ssd1306_UpdateScreen();
		rocketPtr->Object_Image.clearWhenDead = DEAD_OBJECT_DECLARED;
	}
}

/* Delete dead asteroid */
void delete_dead_asteroid(Space_Object_t* asteroidPtr){
	if((asteroidPtr->Object_Property.aliveFlag == ALIVE_FALSE) && (asteroidPtr->Object_Image.clearWhenDead == DEAD_OBJECT_UNDECLARED)){
//		ssd1306_Clear(5);
		ssd1306_DrawBitmap(asteroidPtr->Object_Property.x, asteroidPtr->Object_Property.y, asteroidPtr->Object_Image.bitmapImage,
				asteroidPtr->Object_Image.imageWidth, asteroidPtr->Object_Image.imageHeight, Black);
		ssd1306_UpdateScreen();
		asteroidPtr->Object_Image.clearWhenDead = DEAD_OBJECT_DECLARED;
	}
}

/* Accelerate player spaceship */
void accelerate_player_spaceship(Space_Object_t* playerSpaceShipPtr, int8_t ddx, int8_t ddy){
	if(fabs(playerSpaceShipPtr->Object_Property.dx) < PLAYER_MAX_SPEED){
		playerSpaceShipPtr->Object_Property.dx += ddx;
	}
	if(fabs(playerSpaceShipPtr->Object_Property.dy) < PLAYER_MAX_SPEED){
		playerSpaceShipPtr->Object_Property.dy += ddy;
	}
}


/* Create two medium size asteroids */
void create_medium_asteroid(vector* asteroidVectorPtr, Space_Object_t* deadAsteroidPtr){
	Space_Object_t* asteroidPtr = asteroid;

	uint8_t deadAsteroid_x = deadAsteroidPtr->Object_Property.x;
	uint8_t deadAsteroid_y = deadAsteroidPtr->Object_Property.y;

	for (uint8_t j = 0; j < 2; j++){
		while((asteroidPtr->Object_Property.aliveFlag != ALIVE_FALSE) && (asteroidPtr->Object_Property.aliveFlag != ALIVE_UNSET)){
			asteroidPtr++;
			if((asteroidPtr - asteroid) > ASTEROID_BUFFER_SIZE){
				return;
			}
		}

		vector_add(asteroidVectorPtr, asteroidPtr);
		asteroidPtr->Object_Property.aliveFlag = ALIVE_TRUE;
		asteroidPtr->Object_Property.asteroidSize = ASTEROID_SIZE_M;
		asteroidPtr->Object_Image.bitmapImage = ASTEROID_16x16;
		asteroidPtr->Object_Image.imageWidth = ASTEROID_BMP_SIZE_M_WIDTH;
		asteroidPtr->Object_Image.imageHeight = ASTEROID_BMP_SIZE_M_HEIGHT;
		asteroidPtr->Object_Image.clearWhenDead = DEAD_OBJECT_UNDECLARED;

		if(j == 0){
			asteroidPtr->Object_Property.dx = game_random_sign()*2;
			asteroidPtr->Object_Property.dy = game_random_sign()*2;
			asteroidPtr->Object_Property.x = deadAsteroid_x + ASTEROID_BMP_SIZE_M_WIDTH;
			asteroidPtr->Object_Property.y = deadAsteroid_y + ASTEROID_BMP_SIZE_M_HEIGHT;
		}
		else if (j == 1){
			asteroidPtr->Object_Property.dx = game_random_sign()*2;
			asteroidPtr->Object_Property.dy = game_random_sign()*2;
			asteroidPtr->Object_Property.x = deadAsteroid_x;
			asteroidPtr->Object_Property.y = deadAsteroid_y;
		}
	}
}

/* Display black background */
void display_black_background(){
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();
}


/* Timer interrupt callback */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == htim2.Instance){
		shootButtonFirstTimeFlag = FIRST_TIME_TRUE;
	}
	if(htim->Instance == htim4.Instance){
		frameUpdate = SET_FRAME;
	}
}
