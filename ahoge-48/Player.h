#pragma once
#include"DashState.h"
#include"WalkState.h"
#include"JumpState.h"
#include"IdleState.h"

class Player : public std::enable_shared_from_this<Player>
{
public:
	Player();
	~Player();

	void init();
	void update();
	void draw();
	void jump();
	void walk();
	void dash();
	void changeToWalkState();
	void changeToDashState();
	void changeToJumpState();
	void changeToIdleState();
	bool getIsFacingRight()const noexcept { return isFacingRight_; }
	bool getIsGround()const noexcept { return isGround_; }

private:
	bool	isFacingRight_;
	VECTOR	position_;
	float	veclocityY_;
	bool	isboot_;
	bool	isGround_;
	std::shared_ptr<IState<Player>> currentState_;

	//ステート
	static std::shared_ptr<DashState> dashState_()
	{
		std::shared_ptr<DashState> state = std::make_shared<DashState>();
		return state;
	}
	static std::shared_ptr<WalkState> walkState_()
	{
		std::shared_ptr<WalkState> state = std::make_shared<WalkState>();
		return state;
	}
	static std::shared_ptr<JumpState> jumpState_()
	{
		std::shared_ptr<JumpState> state = std::make_shared<JumpState>();
		return state;
	}
	static std::shared_ptr<IdleState> idleState_()
	{
		std::shared_ptr<IdleState> state = std::make_shared<IdleState>();
		return state;
	}

	const float init_jump_speed		= -12.0f;
	const float max_velocity		= 3.0f;
	const float move_speed_x		= 3.0f;
};