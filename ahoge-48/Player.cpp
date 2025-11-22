#include"DxLib.h"
#include"Stage.h"
#include"Player.h"

Player::Player()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 500.0f, 0.0f);
	velocityY_		= 0.0f;
	isboot_			= true;
	currentState_	= idleState_();
	isGround_		= false;
	catInBootGraph_	= LoadGraph("graph/catInBoot.png");
}

Player::~Player()
{
	currentState_ = nullptr;
	DeleteGraph(catInBootGraph_);
}

void Player::init()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 500.0f, 0.0f);
	velocityY_		= 0.0f;
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
	if (isboot_)
	{
		if (isFacingRight_)
		{
			DrawExtendGraph(position_.x, position_.y, position_.x + player_widht, position_.y + player_height, catInBootGraph_, TRUE);
		}
		else
		{
			DrawExtendGraph(position_.x + player_widht, position_.y, position_.x, position_.y + player_height, catInBootGraph_, TRUE);
		}
	}
	else
	{
		currentState_->draw(shared_from_this());
	}
}

void Player::startJump()
{
	velocityY_ = init_jump_speed;
}

void Player::jump()
{
	velocityY_ += gravity;
	if (velocityY_ > max_velocity_y)
	{
		velocityY_ = max_velocity_y;
	}

	position_.y += velocityY_;
}

void Player::walk()
{
	if (CheckHitKey(KEY_INPUT_LSHIFT)) return;

	if (CheckHitKey(KEY_INPUT_D))
	{
		position_.x += move_speed_x;
	}
	else if(CheckHitKey(KEY_INPUT_A))
	{
		position_.x -= move_speed_x;
	}
}

void Player::dash()
{
	if (!CheckHitKey(KEY_INPUT_LSHIFT)) return;

	if (CheckHitKey(KEY_INPUT_D))
	{
		position_.x += move_speed_x * dash_magnification;
	}
	else if(CheckHitKey(KEY_INPUT_A))
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