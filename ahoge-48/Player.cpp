#include"DxLib.h"
#include"Stage.h"
#include"Boot.h"
#include"Player.h"

Player::Player()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 300.0f, 0.0f);
	velocityY_		= 0.0f;
	isboot_			= false;
	currentState_	= idleState_();
	isGround_		= false;
	catInBootGraph_	= LoadGraph("graph/catInBoot.png");
	isRising_		= false;
	isDead_			= false;
}

Player::~Player()
{
	currentState_ = nullptr;
	DeleteGraph(catInBootGraph_);
}

void Player::init()
{
	isFacingRight_	= true;
	position_		= VGet(1000.0f, 300.0f, 0.0f);
	velocityY_		= 0.0f;
	currentState_	= idleState_();
	isboot_			= false;
	isGround_		= false;
	isRising_		= false;
	isDead_			= false;
}

void Player::update(std::shared_ptr<Stage> stage, std::shared_ptr<Boot> boot)
{
	if (CheckHitKey(KEY_INPUT_D))		isFacingRight_	= true;
	else if(CheckHitKey(KEY_INPUT_A))	isFacingRight_	= false;

	currentState_->update(shared_from_this());

	if (!isGround_)
	{
		position_.y += max_velocity_y;
	}

	if (position_.x < 0.0f)
	{
		position_.x = 0.0f;
	}
	else if (position_.x + player_widht > 1920.0f)
	{
		position_.x = 1920.0f - player_widht;
	}

	collisionWithStage(stage);
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
	if (velocityY_ < max_velocity_y)
	{
		isRising_ = true;
		velocityY_ += gravity;
		if (velocityY_ > max_velocity_y)
		{
			velocityY_ = max_velocity_y;
		}
		position_.y += velocityY_;
	}
	else
	{
		isRising_ = false;
	}
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

void Player::collisionWithStage(std::shared_ptr<Stage> stage)
{
	for (int i = 0; i < max_scaffold_number; i++)
	{
		if (i == 0)
		{
			if (stage->getScaffoldPos()[i].x < position_.x && position_.x < stage->getScaffoldPos()[i].x + scaffold_widht * 2 ||
				stage->getScaffoldPos()[i].x < position_.x + player_widht && position_.x + player_widht < stage->getScaffoldPos()[i].x + scaffold_widht * 2)
			{
				if (stage->getScaffoldPos()[i].y < position_.y + player_height && position_.y + player_height < stage->getScaffoldPos()[i].y + scaffold_height)
				{
					position_.y = stage->getScaffoldPos()[i].y - player_height;
					isGround_ = true;

					return;
				}
			}
		}
		else if (stage->getScaffoldPos()[i].x < position_.x && position_.x < stage->getScaffoldPos()[i].x + scaffold_widht ||
			stage->getScaffoldPos()[i].x < position_.x + player_widht && position_.x + player_widht < stage->getScaffoldPos()[i].x + scaffold_widht)
		{
			if (stage->getScaffoldPos()[i].y < position_.y + player_height && position_.y + player_height < stage->getScaffoldPos()[i].y + scaffold_height)
			{
				position_.y = stage->getScaffoldPos()[i].y - player_height;
				isGround_ = true;

				return;
			}
		}
	}

	isGround_ = false;

	if (water_position.y < position_.y)
	{
		isDead_ = true;
	}
}