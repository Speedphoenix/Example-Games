#include "CreateAnimator.h"

#include "Animator.h"
#include "SpritesContainer.h"
#include "AimedAnimation.h"

#include "allegroImplem.h"
#include "game_config.h"
#include "debugNerrors.h"
#include "basic_ops.h"

void CreateAnimator::snakeBodyAnimator(Animator& what)
{
	Transition newAnimKey;
	AimedAnimation *newAnim;
	SpritesContainer *sprites = SpritesContainer::instance();
	ALLEGRO_BITMAP *sheet = sprites->at("SnakeSprites");

	//these are more temporary and for testing more than anything
	newAnimKey = Transition(Walking, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, tileSide, 0, tileSide, tileSide, 1);
	newAnim->setLapse(defaultIdleLapse);
	what.m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(TipToes, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, 2 * tileSide, 0, tileSide, tileSide, 1);
	newAnim->setLapse(defaultActiveLapse);
	what.m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Attacking, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, 3 * tileSide, 0, tileSide, tileSide, 1);
	newAnim->setLapse(defaultIdleLapse);
	what.m_animations[newAnimKey] = newAnim;

	what.m_currState = Transition(Walking, Anim::Idle, false);
}

void CreateAnimator::appleAnimator(Animator& what)
{
	Transition newAnimKey;
	AimedAnimation *newAnim;
	SpritesContainer *sprites = SpritesContainer::instance();
	ALLEGRO_BITMAP *sheet = sprites->at("SnakeSprites");

	newAnimKey = Transition(Walking, Anim::Idle, false);
	newAnim = new AimedAnimation(sheet, 0, 0, tileSide, tileSide, 1);
	newAnim->setLapse(defaultIdleLapse);
	what.m_animations[newAnimKey] = newAnim;

	what.m_currState = newAnimKey;
}

