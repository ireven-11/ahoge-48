#pragma once
#include<memory>

template <typename Chara>
class IState
{
public:
	~IState()											= default;
	virtual void enter(std::shared_ptr<Chara> chara)	= 0;
	virtual void exit(std::shared_ptr<Chara> chara)		= 0;
	virtual void update(std::shared_ptr<Chara> chara)	= 0;
};