#include"DxLibForIreven.h"
#include"Message.h"

Message::Message()
{
	isdrawing_		= true;
	isPrevButton_	= false;
	counter_		= 0;
}

Message::~Message()
{
}

void Message::update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (!isPrevButton_)
		{
			++counter_;
			isPrevButton_ = true;
		}
	}
	else
	{
		isPrevButton_ = false;
	}

	if (counter_ > max_count) isdrawing_ = false;
}

void Message::draw()const
{
	if (!isdrawing_) return;

	switch (counter_)
	{
	case 0:
		DrawString(100, 100, "test0", GetColor(255, 255, 255));
		break;

	case 1:
		DrawString(100, 100, "test1", GetColor(255, 255, 255));
		break;

	case 2:
		DrawString(100, 100, "test2", GetColor(255, 255, 255));
		break;
	}
}

void Message::init()
{
	isdrawing_		= true;
	isPrevButton_	= false;
	counter_		= 0;
}