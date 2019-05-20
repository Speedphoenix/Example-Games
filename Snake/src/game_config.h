#ifndef GAME_CONFIG_H_INCLUDED
#define GAME_CONFIG_H_INCLUDED

#include "config.h"
#include <map>

/********************************************************************
							THE SPRITES
********************************************************************/

#define SNAKE_SPRITES RES_DIR "SnakeSprites.png"

/********************************************************************
								MAP
********************************************************************/

///the side of a (square) tile
const int tileSide = 75;

const int defMapWidth = 10;
const int defMapHeight = 10;

///converts coordinates in number of tiles
inline int tileCoord(int pixels)
{
	return ((int) (pixels / tileSide));
}

/********************************************************************
								INPUT
********************************************************************/

namespace Input{
enum InputChoice : unsigned {
	Up = 0,
	Left = 1,
	Down = 2,
	Right = 3,
	Pause,
	End
};
}

extern std::map<int, unsigned> defaultKeys;

/********************************************************************
								UNITS
********************************************************************/
// in seconds
const double defaultIdleLapse = 0.3;
const double defaultActiveLapse = 0.1;

// in seconds
const double snakeInitialLapse = 0.5;
const double snakeDecreaseLapse = 0.02;
const double snakeMinLapse = 0.1;

const int snakeInitialBodyCount = 3;
// in tiles
const int snakeInitialPosX = 3;
const int snakeInitialPosY = 0;

const unsigned snakeInitialDirection = Input::InputChoice::Right;


#endif // GAME_CONFIG_H_INCLUDED
