#pragma once
#include"IState.h"

class Player;

class JumpState : public IState<Player>
{
public:
	JumpState();
	~JumpState();

	void enter(std::shared_ptr<Player> chara);
	void exit(std::shared_ptr<Player> chara);
	void update(std::shared_ptr<Player> chara);

private:
};