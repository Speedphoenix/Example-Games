#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "game_config.h"

class GameMap
{
	//statics
	protected:
		static GameMap * m_currentInstance;
	public:
		static GameMap * currentInstance() { return m_currentInstance; }
		static void setCurrentInstance(GameMap* what) { if (what) m_currentInstance = what; }

	protected:
		long m_width;	//!< in tiles, not pixels
		long m_height;	//!< in tiles, not pixels

	public:
		GameMap(long _width, long _height);
		virtual ~GameMap();

		//the dimentions expressed in pixels
		long widthpx() const { return m_width * tileSide; }
		long heightpx() const { return m_height * tileSide; }

		//the dimensions expressed in tiles
		long widthtl() const { return m_width; }
		long heighttl() const { return m_height; }
};

#endif // GAMEMAP_H
