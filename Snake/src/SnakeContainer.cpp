#include "SnakeContainer.h"

#include "GameController.h"
#include "GameObject.h"
#include "Events.h"

#include "game_config.h"
#include "debugNerrors.h"

SnakeContainer::SnakeContainer(long _width, long _height)
	:GameContainer(), m_map(_width, _height), m_camera(), m_controller(nullptr)
{

}

SnakeContainer::~SnakeContainer()
{

}

void SnakeContainer::init()
{
	m_controller = new GameController(getGlobalObject());
	getGlobalObject()->attachBehaviour(m_controller);
}

void SnakeContainer::onKeyboardEvent(const KeyboardEvent& event)
{
	m_controller->onKeyboardEvent(event);
}

