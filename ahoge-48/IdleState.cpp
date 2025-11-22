#include"DxLib.h"
#include"IdleState.h"
#include"Player.h"

IdleState::IdleState()
{
	
}

IdleState::~IdleState()
{
}

void IdleState::enter(std::shared_ptr<Player> chara)
{
	
}

void IdleState::exit(std::shared_ptr<Player> chara)
{

}

void IdleState::update(std::shared_ptr<Player> chara)
{
  	changeState(chara);
}

void IdleState::draw(std::shared_ptr<Player> chara)
{
	if (chara->getIsFacingRight())
	{

	}
	else
	{

	}
}

void IdleState::changeState(std::shared_ptr<Player> chara)
{
	if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_A))
	{
		chara->changeToWalkState();
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		chara->changeToJumpState();
	}
}