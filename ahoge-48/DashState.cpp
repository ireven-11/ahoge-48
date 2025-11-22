#include"DxLib.h"
#include"DashState.h"
#include"Player.h"

DashState::DashState()
{
}

DashState::~DashState()
{
}

void DashState::enter(std::shared_ptr<Player> chara)
{

}

void DashState::exit(std::shared_ptr<Player> chara)
{

}

void DashState::update(std::shared_ptr<Player> chara)
{
	chara->dash();

	changeState(chara);
}

void DashState::draw(std::shared_ptr<Player> chara)
{
	if (chara->getIsFacingRight())
	{

	}
	else
	{

	}
}

void DashState::changeState(std::shared_ptr<Player> chara)
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		chara->changeToJumpState();
	}
	else if (!CheckHitKey(KEY_INPUT_LSHIFT))
	{
		if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_A))
		{
			chara->changeToWalkState();
		}
	}
	else if (!CheckHitKey(KEY_INPUT_D) && !CheckHitKey(KEY_INPUT_A))
	{
		chara->changeToIdleState();
	}
}