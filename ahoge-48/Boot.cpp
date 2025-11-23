#include"DxLibForIreven.h"
#include"Stage.h"
#include"Boot.h"

Boot::Boot()
{
	graphHandle_ = LoadGraph("graph/boot.png");
	position_ = VGet(static_cast<float>(GetRand(1920)) - boot_widht, init_pos_y, 0.0f);
	timer_ = 0;
}

Boot::~Boot()
{
	DeleteGraph(graphHandle_);
}

void Boot::update()
{
	timer_++;
	if (position_.y < 1000.0f)
	{
		position_.y += gravity * 4.0f;
	}
	else
	{
		if (timer_ > 10000)
		{
			if (timer_ > 20000)
			{
				timer_ = 10000;
			}

			static short count = 0;
			count++;
			if (count == 2)
			{
				initPos();
				count = 0;
			}
		}
		else
		{
			initPos();
		}
		
	}
}

void Boot::draw()
{
	DrawExtendGraph(position_.x, position_.y, position_.x + boot_widht, position_.y + boot_height, graphHandle_, TRUE);
}

void Boot::initPos()
{
	position_ = VGet(static_cast<float>(GetRand(1920)) - boot_widht, init_pos_y, 0.0f);
}

void Boot::init()
{
	timer_ = 0;
	position_ = VGet(static_cast<float>(GetRand(1920)) - boot_widht, init_pos_y, 0.0f);
}