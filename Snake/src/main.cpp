#include "allegroImplem.h"
#include "colors.h"
#include "game_config.h"
#include "debugNerrors.h"

#include "SnakeContainer.h"
#include "SpritesContainer.h"

using namespace std;

namespace test {
	void maketestSprites();
}

int main(int argc, char* argv[])
{
	try
	{
		initAlleg(ALLEGRO_WINDOWED, defMapWidth * tileSide, defMapHeight * tileSide);
		// or pass ALLEGRO_FULLSCREEN_WINDOW as a param
	}
	catch (const char* e)
	{
		ES(e)
	}

	SpritesContainer* sprites = new SpritesContainer();
	SnakeContainer* theGame = new SnakeContainer(defMapWidth, defMapHeight);

	test::maketestSprites();

	theGame->start();

	double elapsed = 0.02;

	while(!theGame->shouldStop())
	{
		theGame->update(elapsed*10);

		al_rest(elapsed);
	}

	delete theGame;
	delete sprites;

	closeAlleg();
	return 0;
}


namespace test {

///FOR TESTING PURPOSES
void maketestSprites()
{
	//the default flags, just in case it was changed somewhere
	al_set_new_bitmap_flags(ALLEGRO_CONVERT_BITMAP);

	SpritesContainer::instance()->addSprite("SnakeSprites", al_load_bitmap(SNAKE_SPRITES));
}

}
