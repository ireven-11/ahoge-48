#include"DxLibForIreven.h"
#include"DashState.h"
#include"Player.h"

DashState::DashState()
{
	LoadDivGraph("graph/catDash.png", 5, 5, 1, 64, 48, dashGraph_);
}

DashState::~DashState()
{
	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(dashGraph_[i]);
	}
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
		DrawAnimationGraph(chara->getPosition(), dashGraph_, player_widht, player_height, 5, 4);
	}
	else
	{
		DrawAnimationGraph(chara->getPosition(), dashGraph_, -player_widht, player_height, 5, 4);
	}
}

void DashState::changeState(std::shared_ptr<Player> chara)
{
	if (CheckHitKey(KEY_INPUT_W))
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