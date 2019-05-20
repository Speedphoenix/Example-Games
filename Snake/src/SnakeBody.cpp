#include "SnakeBody.h"

#include "Animator.h"
#include "GameController.h"
#include "TransformBase.h"
#include "GameObject.h"
#include "GameMap.h"

#include "debugNerrors.h"

SnakeBody::SnakeBody(GameObject *attachTo, Animator *_attachedAnimator,
		SnakeBody *_prev, SnakeBody *_next)
	:Behaviour(attachTo), m_next(_next), m_prev(_prev),
	m_attachedAnimator(_attachedAnimator)
{
	setAnimState();
}

SnakeBody::~SnakeBody()
{

}

void SnakeBody::setAnimState()
{
	if (m_prev == nullptr)
		m_attachedAnimator->setState(Attacking);
	else if (m_next == nullptr)
		m_attachedAnimator->setState(TipToes);
	else
		m_attachedAnimator->setState(Walking);
}

void SnakeBody::start()
{
	m_attachedAnimator->launch();
}

void SnakeBody::update()
{

}

void SnakeBody::forward()
{
	if (m_next == nullptr)
		return;
	Transform& newone = m_next->attachedObject()->transform();
	attachedObject()->transform().setAbsPos(newone.absX(), newone.absY());
}

void SnakeBody::forward(unsigned direction)
{
	if (m_next != nullptr)
	{
		forward();
		return;
	}
	GameMap *instance = GameMap::currentInstance();
	int x = attachedObject()->transform().absX();
	int y = attachedObject()->transform().absY();

	switch (direction)
	{
		case Direction::Up:
		attachedObject()->transform().setAbsY((y - tileSide) %
					instance->heightpx());
	break;

		case Direction::Left:
		attachedObject()->transform().setAbsX((x - tileSide) %
					instance->widthpx());
	break;

		case Direction::Down:
		attachedObject()->transform().setAbsY((y + tileSide) %
					instance->heightpx());
	break;

		default:
		case Direction::Right:
		attachedObject()->transform().setAbsX((x + tileSide) %
					instance->widthpx());
	break;
	}
}

void SnakeBody::setPrev(SnakeBody *val)
{
	m_prev = val;
	setAnimState();
}

void SnakeBody::setNext(SnakeBody *val)
{
	m_next = val;
	setAnimState();
}
