#include"DxLibForIreven.h"
#include"IdleState.h"
#include"Player.h"

IdleState::IdleState()
{
	LoadDivGraph("graph/catIdle.png", 5, 5, 1, 64, 48, idleGraph_);
}

IdleState::~IdleState()
{
	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(idleGraph_[i]);
	}
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
		DrawAnimationGraph(chara->getPosition(), idleGraph_, player_widht, player_height, 5, 4);
	}
	else
	{
		DrawAnimationGraph(chara->getPosition(), idleGraph_, -player_widht, player_height, 5, 4);
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