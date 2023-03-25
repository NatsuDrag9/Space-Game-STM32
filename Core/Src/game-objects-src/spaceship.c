// Spaceship firing rocket 1 12x12
const unsigned char ROCKET_12x12 [] = {
	// 'rocket_shot, 12x12px
	0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x0f, 0x00, 0x1f, 0x80, 0x1f, 0x80, 0x0f, 0x00, 0x06, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 12x12 facing north
const unsigned char SPACESHIP_12x12_NORTH [] = {
	0x00, 0x00, 0x06, 0x00, 0x0f, 0x00, 0x09, 0x00, 0x09, 0x00, 0x0f, 0x00, 0x1f, 0x80, 0x1f, 0x80,
	0x16, 0x80, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 16x16 facing north
const unsigned char SPACESHIP_16x16_NORTH [] = {
	0x00, 0x00, 0x01, 0x80, 0x03, 0xc0, 0x03, 0xc0, 0x06, 0x60, 0x07, 0xe0, 0x07, 0xe0, 0x07, 0xe0,
	0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x0c, 0x30, 0x03, 0xc0, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00
};


// Model 1 24x24 facing north
const unsigned char SPACESHIP_24x24_NORTH[] = {
	// 'Rocket_grayscale_12, 24x24px
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x7e, 0x00, 0x00,
	0x7e, 0x00, 0x00, 0xe7, 0x00, 0x00, 0xdb, 0x00, 0x00, 0xdb, 0x00, 0x00, 0xe7, 0x00, 0x00, 0xff,
	0x00, 0x01, 0xff, 0x80, 0x03, 0xff, 0xc0, 0x07, 0xff, 0xe0, 0x03, 0xff, 0xe0, 0x03, 0xff, 0xc0,
	0x03, 0xff, 0xc0, 0x03, 0x00, 0xc0, 0x00, 0x24, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00,
	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 24x24 facing east
const unsigned char SPACESHIP_24x24_EAST[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x40, 0x00, 0x07, 0xf0, 0x00, 0x07, 0xf0, 0x00, 0x03, 0xff, 0x80, 0x01, 0xff, 0xe0, 0x19, 0xfc,
	0x78, 0x3b, 0xfd, 0x7c, 0x3b, 0xfd, 0x7c, 0x19, 0xfc, 0x78, 0x01, 0xff, 0xe0, 0x03, 0xff, 0x80,
	0x07, 0xf0, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 24x24 facing south
const unsigned char SPACESHIP_24x24_SOUTH[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x03,
	0x00, 0xc0, 0x03, 0x99, 0xc0, 0x03, 0xff, 0xc0, 0x03, 0xff, 0xc0, 0x07, 0xff, 0xe0, 0x03, 0xff,
	0xc0, 0x03, 0xff, 0xc0, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xc3, 0x00, 0x00, 0xdb, 0x00,
	0x00, 0xc3, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x3c, 0x00, 0x00,
	0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 24x24 facing west
const unsigned char SPACESHIP_24x24_WEST[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x06, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x1f, 0xc0, 0x03, 0xff, 0x80, 0x0f, 0xff, 0x00, 0x1e, 0x7f,
	0xb8, 0x7d, 0xbf, 0x9c, 0x7d, 0xbf, 0x9c, 0x1e, 0x7f, 0xb8, 0x0f, 0xff, 0x80, 0x03, 0xff, 0x80,
	0x00, 0x1f, 0xc0, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 24x24 facing north east
const unsigned char SPACESHIP_24x24_NORTH_EAST[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00,
	0x07, 0xf0, 0x00, 0x1f, 0xf0, 0x00, 0x3c, 0xe0, 0x03, 0xfa, 0xe0, 0x07, 0xfa, 0xe0, 0x07, 0xf8,
	0xc0, 0x0f, 0xff, 0xc0, 0x0f, 0xff, 0x80, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x04, 0xff, 0x00,
	0x0e, 0x3f, 0x00, 0x07, 0x3e, 0x00, 0x0f, 0x9c, 0x00, 0x01, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 24x24 facing north west
const unsigned char SPACESHIP_24x24_NORTH_WEST[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x0f,
	0xe0, 0x00, 0x0f, 0xf8, 0x00, 0x07, 0x3c, 0x00, 0x07, 0x5f, 0xc0, 0x07, 0x5f, 0xe0, 0x03, 0x1f,
	0xf0, 0x03, 0xff, 0xf0, 0x01, 0xff, 0xf0, 0x00, 0xff, 0x80, 0x00, 0xff, 0x80, 0x00, 0xff, 0x20,
	0x00, 0xfc, 0x70, 0x00, 0x7c, 0xe0, 0x00, 0x3d, 0xf0, 0x00, 0x18, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 24x24 facing south west
const unsigned char SPACESHIP_24x24_SOUTH_WEST [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x38, 0xb0, 0x00,
	0x7d, 0xe0, 0x00, 0xfc, 0x70, 0x00, 0xff, 0x70, 0x00, 0xff, 0x20, 0x00, 0xff, 0x80, 0x01, 0xff,
	0xf0, 0x03, 0xff, 0xf0, 0x03, 0xff, 0xf0, 0x07, 0x5f, 0xe0, 0x06, 0xdf, 0xc0, 0x07, 0x1c, 0x80,
	0x07, 0xf8, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 24x24 facing south east
const unsigned char SPACESHIP_24x24_SOUTH_EAST [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0d, 0x1c, 0x00, 0x07,
	0xbe, 0x00, 0x0e, 0x3f, 0x00, 0x0e, 0xff, 0x00, 0x04, 0xff, 0x00, 0x01, 0xff, 0x00, 0x0f, 0xff,
	0x80, 0x0f, 0xff, 0xc0, 0x0f, 0xff, 0xc0, 0x07, 0xfa, 0xe0, 0x03, 0xfb, 0x60, 0x01, 0x38, 0xe0,
	0x00, 0x1f, 0xe0, 0x00, 0x0f, 0xf0, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


// Model 1 32x32
const unsigned char SPACESHIP_32x32 [] = {
	// 'Rocket_grayscale_12, 32x32px
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x03, 0xc0, 0x00,
	0x00, 0x07, 0xe0, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x1f, 0xf0, 0x00,
	0x00, 0x1e, 0x78, 0x00, 0x00, 0x1c, 0x38, 0x00, 0x00, 0x1d, 0xb8, 0x00, 0x00, 0x3d, 0xbc, 0x00,
	0x00, 0x3c, 0x3c, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x7f, 0xfe, 0x00,
	0x00, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0x80,
	0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xf3, 0xcf, 0x00, 0x00, 0xe0, 0x07, 0x00,
	0x00, 0x04, 0x20, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x07, 0xa0, 0x00,
	0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Model 1 explosion
const unsigned char SPACESHIP_EXPLOSION_128x64 [] = {
	// 'Rocket_explosion_1, 128x64px
	0xc0, 0x07, 0x80, 0x3f, 0x93, 0x79, 0xcc, 0xe9, 0xfe, 0x7f, 0x06, 0x0c, 0x78, 0x0f, 0xf8, 0xe0,
	0xf0, 0x21, 0xc0, 0x1f, 0xc9, 0xbc, 0xcc, 0xe9, 0xfe, 0xfe, 0xae, 0x18, 0xe0, 0x1f, 0xe3, 0x80,
	0x7c, 0x08, 0xf0, 0x0f, 0xe0, 0x9c, 0xec, 0xe9, 0xfe, 0xfd, 0x1c, 0x33, 0xc0, 0x7f, 0x8e, 0x00,
	0x1f, 0x00, 0x38, 0x07, 0xf4, 0x5e, 0x6e, 0xf9, 0xfe, 0xfd, 0x38, 0x67, 0x80, 0xff, 0xfc, 0x00,
	0x87, 0xc1, 0x1e, 0x03, 0xfa, 0x6f, 0x76, 0xf9, 0xfd, 0xfa, 0xb0, 0xcf, 0x03, 0xff, 0xf0, 0x00,
	0xe1, 0xf0, 0x47, 0x01, 0xfd, 0x37, 0x76, 0xf9, 0xfd, 0xf8, 0x61, 0x9e, 0xc7, 0xff, 0xc0, 0x00,
	0x7c, 0x7c, 0x13, 0xd0, 0xfe, 0x97, 0xbf, 0x79, 0xff, 0xf5, 0xeb, 0x3f, 0x1f, 0xff, 0x00, 0x02,
	0x0f, 0x1f, 0x08, 0xe8, 0x7f, 0xdb, 0xbb, 0x7d, 0xff, 0xfb, 0xde, 0x7e, 0x3f, 0xfc, 0x00, 0x00,
	0x03, 0xc7, 0xc2, 0x7e, 0x1f, 0xef, 0xdf, 0x7d, 0xff, 0xef, 0xbc, 0xfc, 0xff, 0xf0, 0x00, 0x40,
	0xe0, 0xf1, 0xf0, 0x9f, 0x0f, 0xf5, 0xdf, 0x7d, 0xff, 0xf7, 0x39, 0xf1, 0xff, 0xc0, 0x02, 0x01,
	0xf8, 0x3e, 0x78, 0x4f, 0xc7, 0xf6, 0xef, 0xfd, 0xff, 0xcf, 0x77, 0xe7, 0xff, 0x00, 0x08, 0x0f,
	0x7f, 0x0f, 0x9e, 0x17, 0xe3, 0xfb, 0xff, 0xfd, 0xff, 0xfe, 0xef, 0xdf, 0xfe, 0x00, 0x60, 0x7f,
	0x9f, 0xe1, 0xe7, 0x85, 0xf5, 0xff, 0xf7, 0xfd, 0xff, 0xdd, 0xdf, 0xbf, 0xf8, 0x01, 0x03, 0xf8,
	0x7f, 0xf8, 0x79, 0xe2, 0xfe, 0xff, 0xbf, 0xfd, 0xff, 0xfb, 0xbe, 0xff, 0xe0, 0x0c, 0x1f, 0xc0,
	0xcf, 0xff, 0x1e, 0x78, 0xbf, 0x7f, 0xff, 0xff, 0xff, 0xf7, 0xfd, 0xff, 0x80, 0x20, 0xfe, 0x00,
	0x1f, 0xff, 0xe3, 0xde, 0x7f, 0xbf, 0xff, 0xff, 0xff, 0x7e, 0xff, 0xfe, 0x01, 0x87, 0xf0, 0x40,
	0x03, 0xff, 0xf8, 0xf7, 0x97, 0xef, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf8, 0x04, 0x1f, 0xcf, 0x80,
	0xf0, 0x7f, 0xff, 0x3d, 0xe7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x30, 0xfe, 0xf8, 0x01,
	0xff, 0x07, 0xff, 0xe7, 0x79, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0x84, 0xc7, 0xff, 0xc0, 0x10,
	0x7f, 0xf0, 0xff, 0xf9, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x86, 0x3f, 0xfc, 0x03, 0x01,
	0x03, 0xff, 0x0f, 0xff, 0x7f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x19, 0xff, 0xe0, 0x60, 0x30,
	0x00, 0x3f, 0xf1, 0xff, 0xcf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xfa, 0xcf, 0xff, 0x06, 0x0e, 0x00,
	0x70, 0x01, 0xff, 0x9f, 0xfb, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xef, 0x7f, 0xf0, 0xe1, 0xc0, 0x00,
	0x81, 0xc0, 0x1f, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbb, 0xff, 0x8c, 0x3c, 0x00, 0x1f,
	0xff, 0x8f, 0x80, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xcf, 0x80, 0x0f, 0xc0,
	0x7f, 0xff, 0xbe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf0, 0x0f, 0xe0, 0xf0,
	0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbc, 0x0f, 0xff, 0xe0, 0x00,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xc0, 0x00, 0x00,
	0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xc0, 0x3c, 0x00, 0x03,
	0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf9, 0xff, 0xff, 0xf0,
	0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x00, 0x00, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00,
	0x3f, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
	0x00, 0x0f, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0x80, 0x7f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xe0, 0x00, 0x7f, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x7f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xe3, 0xff, 0xfc, 0x3f,
	0x7f, 0xc0, 0x1f, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0x07, 0xff, 0xf8,
	0xc0, 0x03, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf8, 0x1f, 0xff,
	0x00, 0x3f, 0xff, 0xc7, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf3, 0xff, 0xe0, 0x3f,
	0x07, 0xff, 0xfc, 0x3f, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x1f, 0xff, 0x00,
	0xff, 0xff, 0xc1, 0xff, 0xdf, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xe0, 0xff, 0xfc,
	0xff, 0xfc, 0x0f, 0xfe, 0x7f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x1e, 0x0f, 0xff,
	0xff, 0xc0, 0xfb, 0xf9, 0xff, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xe0, 0x7f,
	0xfc, 0x07, 0xdf, 0xc7, 0xff, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1e, 0x07,
	0xc0, 0x3e, 0x7f, 0x3f, 0xff, 0xdf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xfc, 0x01, 0xe0,
	0x01, 0xe3, 0xf8, 0xff, 0xfb, 0xbf, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0x00, 0x3e,
	0x0f, 0x1f, 0xc3, 0xff, 0xf6, 0x7f, 0xbf, 0xff, 0xff, 0xff, 0x7f, 0xe7, 0xf7, 0xff, 0xc0, 0x03,
	0x78, 0xff, 0x1f, 0xff, 0xdc, 0xff, 0x6f, 0x7f, 0xff, 0xff, 0xbb, 0xfb, 0xfd, 0xff, 0xf0, 0x00,
	0xc3, 0xf8, 0x7f, 0xff, 0xb1, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xdd, 0xfe, 0xff, 0x7f, 0x7e, 0x00,
	0x1f, 0xc1, 0xff, 0xfe, 0xe7, 0xf5, 0xdf, 0xff, 0xff, 0xfd, 0xee, 0xff, 0x3f, 0xcf, 0xcf, 0xc0,
	0xff, 0x07, 0xff, 0xf9, 0xcf, 0xe9, 0xbe, 0xff, 0xaf, 0xfe, 0xf7, 0x3f, 0xcf, 0xf3, 0xf9, 0xf0,
	0xf8, 0x37, 0xff, 0xf7, 0x1f, 0xd3, 0xbe, 0xff, 0xbf, 0xff, 0x7b, 0xdf, 0xf3, 0xfc, 0x7e, 0x3e,
	0xc0, 0xdf, 0xff, 0x4e, 0x3f, 0xb7, 0x7f, 0xff, 0xbf, 0x7f, 0xbd, 0xef, 0xf9, 0xff, 0x1f, 0x87,
	0x02, 0x7f, 0xfd, 0x9c, 0x7f, 0x67, 0x7f, 0xff, 0xb7, 0xff, 0x9e, 0xf3, 0xfe, 0x7f, 0xc7, 0xf1,
	0x09, 0xff, 0xfa, 0x70, 0x7e, 0x4e, 0xdd, 0xff, 0xf7, 0xbf, 0xcf, 0x39, 0xff, 0x9f, 0xf0, 0xfc,
	0x47, 0xff, 0xec, 0xe2, 0xfc, 0x9c, 0xdd, 0xff, 0xd7, 0xff, 0xe7, 0x9c, 0x7f, 0xc7, 0xfc, 0x3f,
	0x1f, 0xff, 0x93, 0xc5, 0xf9, 0x1d, 0xbf, 0xff, 0xd7, 0xdf, 0xf7, 0xce, 0x3f, 0xf1, 0xff, 0x07,
	0x7f, 0xff, 0x47, 0x0b, 0xf3, 0x3b, 0xbb, 0xff, 0xdb, 0xdf, 0xf3, 0xe7, 0x1f, 0xfc, 0x7f, 0xc1,
	0xde, 0x7c, 0x8e, 0x07, 0xf6, 0x7b, 0x3b, 0xff, 0xdb, 0xef, 0xf9, 0xf3, 0x87, 0xfe, 0x3f, 0xf0,
	0x3f, 0xd2, 0x38, 0x0f, 0xec, 0x77, 0x7b, 0xff, 0xdb, 0xef, 0xfc, 0xf9, 0x83, 0xfd, 0x8f, 0xfc,
	0xff, 0xe4, 0x70, 0x1f, 0xc8, 0xe6, 0x73, 0xdb, 0xd9, 0xf7, 0xfc, 0x7c, 0xc1, 0xff, 0x63, 0xff
};

/*
// Model 2
const unsigned char SPACESHIP2 []= {
		// 'Rocket_grayscale_6, 32x32px
		0x00, 0x03, 0xc0, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x0f, 0xf0, 0x00,
		0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0e, 0x70, 0x00, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x0f, 0xf0, 0x00,
		0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00,
		0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00,
		0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x3f, 0xfc, 0x00,
		0x00, 0x7f, 0xfe, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0x80,
		0x03, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xc0,
		0x03, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00
};
*/
