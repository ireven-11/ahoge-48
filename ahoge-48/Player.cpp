#include"DxLib.h"
#include"Stage.h"
#include"Player.h"

Player::Player()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 500.0f, 0.0f);
	veclocity_		= VGet(0.0f, 0.0f, 0.0f);
}

Player::~Player()
{
}

void Player::init()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 500.0f, 0.0f);
	veclocity_		= VGet(0.0f, 0.0f, 0.0f);
	currentState_	= nullptr;
}

void Player::update()
{
	if (CheckHitKey(KEY_INPUT_D))		isFacingRight_	= true;
	else if(CheckHitKey(KEY_INPUT_A))	isFacingRight_	= false;

	currentState_->update(shared_from_this());
}

void Player::draw()
{
	if (isFacingRight_)
	{

	}
	else
	{

	}
}

void Player::jump()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{

	}
}

void Player::walk()
{
	if (CheckHitKey(KEY_INPUT_D))
	{

	}
	else if ((CheckHitKey(KEY_INPUT_A)))
	{

	}
}

void Player::dash()
{
	if (CheckHitKey(KEY_INPUT_D))
	{

	}
	else if ((CheckHitKey(KEY_INPUT_A)))
	{

	}
}

void Player::changeToWalkState()
{
	currentState_ = walkState_();
}

void Player::changeToDashState()
{
	currentState_ = dashState_();
}

void Player::changeToJumpState()
{
	currentState_ = jumpState_();
}
void Player::changeToIdleState()
{
	currentState_ = idleState_();
}