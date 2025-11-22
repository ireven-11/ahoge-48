#pragma once
#include"IState.h"

class Player;

class DashState : public IState<Player>
{
public:
	DashState();
	~DashState();

	void enter(std::shared_ptr<Player> chara);
	void exit(std::shared_ptr<Player> chara);
	void update(std::shared_ptr<Player> chara);
	void draw(std::shared_ptr<Player> chara);

private:
	void changeState(std::shared_ptr<Player> chara);
};