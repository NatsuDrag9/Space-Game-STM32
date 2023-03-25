/*
 * asteroid.h
 *
 *  Created on: Jan 28, 2023
 *      Author: rohitimandi
 */

#ifndef INC_GAME_OBJECTS_INC_ASTEROID_H_
#define INC_GAME_OBJECTS_INC_ASTEROID_H_

extern const unsigned char ASTEROID_12x12 []; // Small size asteroid
extern const unsigned char ASTEROID_16x16 []; // Medium size asteroid
extern const unsigned char ASTEROID_24x24 []; // Large size asteroid breaks into two 16x16 when hit
extern const unsigned char ASTEROID_EXPLOSION_16x16 []; // Asteroid explosion type 1 16x16 pixels
extern const unsigned char ASTEROID_EXPLOSION_24x24 []; // Asteroid explosion type 1 24x24 pixels
extern const unsigned char ASTEROID_EXPLOSION_2_24x24 []; // Asteroid explosion type 2 24x24 pixels

/*
// Very large asteroid breaks into three 12x12 when hit
extern const unsigned char ASTEROID_32x32[];
*/

/*
// Other explosion images
extern const unsigned char ASTEROID_EXPLOSION_16x16 [];
// extern const unsigned char ASTEROID_EXPLOSION_24x24 [];
*/

#endif /* INC_GAME_OBJECTS_INC_ASTEROID_H_ */
