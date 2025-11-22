#include"DxLib.h"
#include"WalkState.h"
#include"Player.h"

WalkState::WalkState()
{
}

WalkState::~WalkState()
{
}

void WalkState::enter(std::shared_ptr<Player> chara)
{

}

void WalkState::exit(std::shared_ptr<Player> chara)
{

}

void WalkState::update(std::shared_ptr<Player> chara)
{
	chara->walk();

	changeState(chara);
}

void WalkState::draw(std::shared_ptr<Player> chara)
{
	if (chara->getIsFacingRight())
	{

	}
	else
	{

	}
}

void WalkState::changeState(std::shared_ptr<Player> chara)
{
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		chara->changeToDashState();
	}
	else if (CheckHitKey(KEY_INPUT_SPACE))
	{
		chara->changeToJumpState();
	}
	else if (!CheckHitKey(KEY_INPUT_D) && !CheckHitKey(KEY_INPUT_A))
	{
		chara->changeToIdleState();
	}
}