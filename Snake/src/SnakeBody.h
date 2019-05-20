#ifndef SNAKEBODY_H_INCLUDED
#define SNAKEBODY_H_INCLUDED

#include "Behaviour.h"

class Animator;

class SnakeBody : public Behaviour
{
	friend class GameController;

	protected:
		SnakeBody *m_next;
		SnakeBody *m_prev;
		Animator *m_attachedAnimator;

		virtual void setAnimState();
	public:
		SnakeBody(GameObject *attachTo, Animator *_attachedAnimator,
			SnakeBody *_prev = nullptr, SnakeBody *_next = nullptr);
		virtual ~SnakeBody();

		virtual void start();
		virtual void update();

		virtual void forward();
		virtual void forward(unsigned direction);

		virtual void setPrev(SnakeBody *val);
		virtual void setNext(SnakeBody *val);
};

#endif //SNAKEBODY_H_INCLUDED
