#ifndef GAMECONTROLLER_H_INCLUDED
#define GAMECONTROLLER_H_INCLUDED

#include "Behaviour.h"
#include <list>
#include <map>

struct KeyboardEvent;
class SnakeBody;
class Collider;
class GameObject;

enum Direction : unsigned
{
	Up = 0,
	Left = 1,
	Down = 2,
	Right = 3
};

/*
struct OnCollide
{
	Behaviour *what;
	void (Behaviour::*func)(Collider *other);
};
*/

class GameController : public Behaviour
{
	private:
		std::list<SnakeBody *> m_body;
		double m_currentElapsed;
		double m_currentSnakeLapse;
		Direction m_currentDir;
		std::map<int, unsigned> m_keyToEvent;
		GameObject *m_apple = nullptr;
		int m_toAdd = 0;

		void addBody(int x, int y);
		void putApple();
	public:
		GameController(GameObject *attachTo);
		~GameController();

		void onKeyboardEvent(const KeyboardEvent& event);

		virtual void start();
		virtual void update();

		virtual void onCollide(Collider *other);
};

#endif //GAMECONTROLLER_H_INCLUDED
