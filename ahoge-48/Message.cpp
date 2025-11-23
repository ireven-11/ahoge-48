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

void Message::draw(const int fontHandle)const
{
	if (!isdrawing_) return;

	DrawBox(150, 850, 1800, 1000, GetColor(255, 255, 255), TRUE);

	switch (counter_)
	{
	case 0:
		DrawStringFToHandle(text_pos.x, text_pos.y, "アナウンサー：緊急速報です！ありえんくらいの大雨により海面が急上昇しています!!",
			GetColor(50, 50, 255), fontHandle);
		break;

	case 1:
		DrawStringFToHandle(text_pos.x, text_pos.y, "アナウンサー：政府が開発した魔法の長靴を履いてできるだけ高いところに避難してください!!",
			GetColor(50, 50, 255), fontHandle);
		break;

	case 2:
		DrawStringFToHandle(text_pos.x, text_pos.y, "アナウンサー：以上緊急速報でした。続報が入り次第お知らせします。",
			GetColor(50, 50, 255), fontHandle);
		break;
	}
}

void Message::init()
{
	isdrawing_		= true;
	isPrevButton_	= false;
	counter_		= 0;
}