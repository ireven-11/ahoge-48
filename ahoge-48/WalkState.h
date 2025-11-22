#pragma once
#include"IState.h"

class Player;

class WalkState : public IState<Player>
{
public:
	WalkState();
	~WalkState();

	void enter(std::shared_ptr<Player> chara);
	void exit(std::shared_ptr<Player> chara);
	void update(std::shared_ptr<Player> chara);
	void draw(std::shared_ptr<Player> chara);

private:
	void changeState(std::shared_ptr<Player> chara);

	int walkGraph_[6];
};