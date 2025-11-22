#include"DxLib.h"
#include"JumpState.h"
#include"Player.h"

JumpState::JumpState()
{
	jumpGraph_ = LoadGraph("graph/catJump.png");
}

JumpState::~JumpState()
{
	DeleteGraph(jumpGraph_);
}

void JumpState::enter(std::shared_ptr<Player> chara)
{
	chara->startJump();
}

void JumpState::exit(std::shared_ptr<Player> chara)
{

}

void JumpState::update(std::shared_ptr<Player> chara)
{
	chara->jump();
	chara->walk();
	chara->dash();

	changeState(chara);
}

void JumpState::draw(std::shared_ptr<Player> chara)
{
	if (chara->getIsFacingRight())
	{
		DrawExtendGraph(chara->getPosition().x, chara->getPosition().y,
			chara->getPosition().x + player_widht, chara->getPosition().y + player_height, jumpGraph_, TRUE);
	}
	else
	{
		DrawExtendGraph(chara->getPosition().x, chara->getPosition().y,
			chara->getPosition().x - player_widht, chara->getPosition().y + player_height, jumpGraph_, TRUE);
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