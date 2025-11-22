#pragma once
#include"IState.h"

class Player;

class IdleState : public IState<Player>
{
public:
	IdleState();
	~IdleState();

	void enter(std::shared_ptr<Player> chara);
	void exit(std::shared_ptr<Player> chara);
	void update(std::shared_ptr<Player> chara);
	void draw(std::shared_ptr<Player> chara);

private:
	void changeState(std::shared_ptr<Player> chara);

};