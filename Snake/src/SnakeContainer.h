#ifndef DOWNFCONTAINER_H
#define DOWNFCONTAINER_H

#include "GameContainer.h"
#include "GameMap.h"
#include "Camera.h"

#include <vector>

struct KeyboardEvent;
struct MouseEvent;
struct TouchEvent;

class Player;
class GameController;

/** The game container specific to Stiek2Bellum */
class SnakeContainer : public GameContainer
{
	protected:
		GameMap m_map;
		Camera m_camera;

		GameController *m_controller;

		virtual void onKeyboardEvent(const KeyboardEvent& event);

		virtual void init();

	public:
		SnakeContainer(long _width, long _height);
		virtual ~SnakeContainer();

		//no copy ctor or assignment
		SnakeContainer(const SnakeContainer&) = delete;
		SnakeContainer& operator=(const SnakeContainer&) = delete;

		virtual double maximumX() { return mapWidth(); }
		virtual double maximumY() { return mapHeight(); }

		void setMap(const GameMap& val) { m_map = val; }

		long mapWidth() const { return m_map.widthpx(); }
		long mapHeight() const { return m_map.heightpx(); }

		long mapTileWidth() const { return m_map.widthtl(); }
		long mapTileHeight() const { return m_map.heighttl(); }

};

#endif // DOWNFCONTAINER_H

