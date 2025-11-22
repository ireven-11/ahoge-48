#include"DxLib.h"
#include"JumpState.h"
#include"Player.h"

JumpState::JumpState()
{
}

JumpState::~JumpState()
{
}

void JumpState::enter(std::shared_ptr<Player> chara)
{

}

void JumpState::exit(std::shared_ptr<Player> chara)
{

}

void JumpState::update(std::shared_ptr<Player> chara)
{
	changeState(chara);
}

void JumpState::draw(std::shared_ptr<Player> chara)
{
	if (chara->getIsFacingRight())
	{

	}
	else
	{

	}
}

void JumpState::changeState(std::shared_ptr<Player> chara)
{
	if (!chara->getIsGround()) return;

	if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_A))
	{
		chara->changeToWalkState();
	}
	else
	{
		chara->changeToIdleState();
	}
}