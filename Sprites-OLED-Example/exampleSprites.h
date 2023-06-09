/* This file holds arrays of zeros and ones that are used with the logic
 *  behind an OLED screen to display the images as Sprites on the screen.
 *  
 *  Written 7/2/18 by: Hunter Hykes & Laverena Wienclaw for TinyCircuits
 */

// A pixel pictue of Pac-Man facing right with an open mouth
const unsigned int pacManRightBitmap[] = {
  0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0
};

// A pixel picture of a bunny leaping right.
const unsigned int bunnyBitmap[] = {
  0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
  0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
  1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1,
  1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
  0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
  1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0,
  1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0,
  0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0
};

// An array initialized to zero. This is a good starting point for someone
// else that wants to create a Sprite.
const unsigned int zeroBitmap[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
