#include "game_config.h"

using namespace Input;

std::map<int, unsigned> defaultKeys = {
	{ALLEGRO_KEY_UP, InputChoice::Up}, {ALLEGRO_KEY_DOWN, InputChoice::Down},
	{ALLEGRO_KEY_RIGHT, InputChoice::Right},
	{ALLEGRO_KEY_LEFT, InputChoice::Left},
	{ALLEGRO_KEY_P, InputChoice::Pause},
	{ALLEGRO_KEY_ESCAPE, InputChoice::End}};
