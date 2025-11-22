#include"DxLib.h"
#include"Score.h"

Score::Score()
{
	counter_ = 0;
}

Score::~Score()
{
}

void Score::update()
{
	++counter_;
}

void Score::init()
{
	counter_ = 0;
}