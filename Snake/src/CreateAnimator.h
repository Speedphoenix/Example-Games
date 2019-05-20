#ifndef CREATEANIMATOR_H_INCLUDED
#define CREATEANIMATOR_H_INCLUDED

/*
 * this is a provisory class to assemble concrete animators
*/

class Animator;

class CreateAnimator
{
	public:
		static void snakeBodyAnimator(Animator& what);
		static void appleAnimator(Animator& what);
};

#endif //CREATEANIMATOR_H_INCLUDED
