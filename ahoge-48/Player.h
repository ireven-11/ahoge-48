#pragma once
#include"DashState.h"
#include"WalkState.h"
#include"JumpState.h"
#include"IdleState.h"

const float player_widht = 100.0f;
const float player_height = 100.0f;

class Stage;
class Boot;

class Player : public std::enable_shared_from_this<Player>
{
public:
	Player();
	~Player();

	void init();
	void update(std::shared_ptr<Stage> stage, std::shared_ptr<Boot> boot);
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
	void startJump();
	bool getIsRising()const noexcept { return isRising_; }
	bool getIsDead()const noexcept { return isDead_; }
	VECTOR getPosition()const noexcept { return position_; }

private:
	void collisionWithStage(std::shared_ptr<Stage> stage);

	bool	isFacingRight_;
	VECTOR	position_;
	float	velocityY_;
	bool	isboot_;
	bool	isGround_;
	int		catInBootGraph_;
	bool	isRising_;
	bool	isDead_;
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

	const float init_jump_speed		= -30.0f;
	const float max_velocity_y		= 5.5f;
	const float move_speed_x		= 5.0f;
	const float dash_magnification	= 1.5f;
};