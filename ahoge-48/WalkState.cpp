#include"DxLibForIreven.h"
#include"WalkState.h"
#include"Player.h"

WalkState::WalkState()
{
	LoadDivGraph("graph/catWalk.png", 6, 6, 1, 64, 48, walkGraph_);
}

WalkState::~WalkState()
{
	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(walkGraph_[i]);
	}
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
		DrawAnimationGraph(chara->getPosition(), walkGraph_, player_widht, player_height, 5, 5);
	}
	else
	{
		DrawAnimationGraph(chara->getPosition(), walkGraph_, -player_widht, player_height, 5, 5);
	}
}

void WalkState::changeState(std::shared_ptr<Player> chara)
{
	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		chara->changeToDashState();
	}
	else if (CheckHitKey(KEY_INPUT_W))
	{
		chara->changeToJumpState();
	}
	else if (!CheckHitKey(KEY_INPUT_D) && !CheckHitKey(KEY_INPUT_A))
	{
		chara->changeToIdleState();
	}
}