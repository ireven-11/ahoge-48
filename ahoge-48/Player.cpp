#include"DxLib.h"
#include"Stage.h"
#include"Player.h"

Player::Player()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 500.0f, 0.0f);
	veclocityY_		= 0.0f;
	isboot_			= false;
	currentState_	= idleState_();
	isGround_		= false;
}

Player::~Player()
{
}

void Player::init()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 500.0f, 0.0f);
	veclocityY_		= 0.0f;
	currentState_	= nullptr;
	isboot_			= false;
	isGround_		= false;
}

void Player::update()
{
	if (CheckHitKey(KEY_INPUT_D))		isFacingRight_	= true;
	else if(CheckHitKey(KEY_INPUT_A))	isFacingRight_	= false;

	currentState_->update(shared_from_this());
}

void Player::draw()
{
	currentState_->draw(shared_from_this());
}

void Player::jump()
{
	
}

void Player::walk()
{
	if (isFacingRight_)
	{
		position_.x += move_speed_x;
	}
	else
	{
		position_.x -= move_speed_x;
	}
}

void Player::dash()
{
	if (isFacingRight_)
	{
		position_.x += move_speed_x * dash_magnification;
	}
	else
	{
		position_.x -= move_speed_x * dash_magnification;
	}
}

void Player::changeToWalkState()
{
	currentState_->exit(shared_from_this());
	currentState_ = walkState_();
	currentState_->enter(shared_from_this());
}

void Player::changeToDashState()
{
	currentState_->exit(shared_from_this());
	currentState_ = dashState_();
	currentState_->enter(shared_from_this());
}

void Player::changeToJumpState()
{
	currentState_->exit(shared_from_this());
	currentState_ = jumpState_();
	currentState_->enter(shared_from_this());
}
void Player::changeToIdleState()
{
	currentState_->exit(shared_from_this());
	currentState_ = idleState_();
	currentState_->enter(shared_from_this());
}