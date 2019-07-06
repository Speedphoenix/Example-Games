#include "GameController.h"

#include "CreateAnimator.h"
#include "GameContainer.h"
#include "GameObject.h"
#include "SnakeBody.h"
#include "Collider.h"
#include "Animator.h"
#include "GameMap.h"
#include "Events.h"

#include "debugNerrors.h"
#include "game_config.h"

using namespace std;

GameController::GameController(GameObject* attacTo) 
	:Behaviour(attacTo), m_body(), m_currentElapsed(0.0),
	m_currentSnakeLapse(snakeInitialLapse), m_currentDir(Direction::Up),
	m_keyToEvent(defaultKeys)
{

}

GameController::~GameController()
{

}

/// subsribe to the oncollide OF THE HEAD

void GameController::addBody(int x, int y)
{
	GameObject *currObject;
	Collider *currCollider;
	Animator *currAnim;
	SnakeBody *curr;

	currObject = new GameObject(x, y, tileSide, tileSide);
	currAnim = new Animator(currObject);
	CreateAnimator::snakeBodyAnimator(*currAnim);
	currObject->attachBehaviour(currAnim);

	curr = new SnakeBody(currObject, currAnim,
		m_body.empty() ? nullptr : m_body.back());
	
	currObject->attachBehaviour(curr);
	if (!m_body.empty())
		m_body.back()->setNext(curr);
	m_body.push_back(curr);

	currCollider = new Collider(currObject, currObject->transform());
	currObject->attachBehaviour(currCollider);
	if (m_body.size() == 1)
	{
		currCollider->subscribe(OnCollide(this,
			static_cast<void (Behaviour::*)(Collider *)>(&GameController::onCollide)));
	}
}

void GameController::start()
{
	Animator *currAnim;
	Collider *currCollider;
	int currX, currY;

	currX = snakeInitialPosX;
	currY = snakeInitialPosY;
	for (int i = 0;i < snakeInitialBodyCount;i++)
	{
		addBody(currX * tileSide, currY * tileSide);
		if (snakeInitialDirection % 2 == 1)
			currX += snakeInitialDirection - 2;
		else
			currY += snakeInitialDirection - 1;
	}
	m_apple = new GameObject(0.0, 0.0, tileSide, tileSide);
	currCollider = new Collider(m_apple, m_apple->transform());
	m_apple->attachBehaviour(currCollider);
	currAnim = new Animator(m_apple);
	CreateAnimator::appleAnimator(*currAnim);
	m_apple->attachBehaviour(currAnim);
	putApple();
}

void GameController::update()
{
	int lastx, lasty;
	list<SnakeBody*>::iterator it;
SEPP
/*
E(m_currentElapsed)
E(m_currentSnakeLapse)
E(m_body.size())
E(m_body.front()->attachedObject()->transform().absX())
E(m_body.front()->attachedObject()->transform().absY())
*/
	m_currentElapsed += GameContainer::deltaTime();
	while (m_currentElapsed > m_currentSnakeLapse)
	{
		lastx = m_body.back()->attachedObject()->transform().absX();
		lasty = m_body.back()->attachedObject()->transform().absY();
		m_currentElapsed -= m_currentSnakeLapse;

		it = m_body.end();
		it--;
		while (it != m_body.begin())
		{
//			E((*it)->attachedObject()->transform().absX())
//			E((*it)->attachedObject()->transform().absY())
			(*it)->forward();
			it--;
		}
//		E(*it == m_body.front())
		(*it)->forward(m_currentDir);
		if (m_toAdd > 0)
		{
			addBody(lastx, lasty);
			m_toAdd--;
		}
	}
}

void GameController::onKeyboardEvent(const KeyboardEvent& event)
{
	EINF
	if (m_keyToEvent.count(event.keycode) == 0)
		return;
	unsigned choice = m_keyToEvent.at(event.keycode);
	if (choice < 4)
	{
		// change course only if the new one isn't a u turn 
		// already the prvious one
		if (choice % 2 != m_currentDir % 2)
			m_currentDir = static_cast<Direction>(choice);
	}
	else
	{
		EINF
		if (choice == Input::InputChoice::End)
		{
			EINF
			GameContainer::instance()->setFinished(true);
		}
		//pause the game if choise == InputChoice::pause?
	}
}

void GameController::onCollide(Collider *other)
{
	if (other->attachedObject()->id() == "Apple")
	{
		m_toAdd++;
		putApple();
	}
	else
		GameContainer::instance()->setFinished(true);
}

void GameController::putApple()
{
	int newX, newY;
	int where;
	GameMap *instance = GameMap::currentInstance();

	where = rand() % (instance->widthtl() * instance->heighttl() - m_body.size());
	newX = 0;
	newY = 0;
	while (where != 0)
	{
		bool cant = false;
		for (const auto& elem : m_body)
		{
			const TransformBase& trnsf = elem->attachedObject()->transform();
			if (tileCoord(trnsf.absX()) == newX
				&& tileCoord(trnsf.absY()) == newY)
			{
				cant = true;
				break;
			}
		}
		if (!cant)
			where--;
		if (where != 0)
		{
			newX++;
			if (newX >= instance->widthtl())
			{
				newX = 0;
				newY++;
			}
		}
	}
	m_apple->transform().setAbsPos(newX * tileSide, newY * tileSide);
}
