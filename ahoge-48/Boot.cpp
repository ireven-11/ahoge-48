#include"DxLibForIreven.h"
#include"Stage.h"
#include"Boot.h"

Boot::Boot()
{
	graphHandle_ = LoadGraph("graph/boot.png");
	position_ = VGet(static_cast<float>(GetRand(1920)) - boot_widht, init_pos_y, 0.0f);
}

Boot::~Boot()
{
	DeleteGraph(graphHandle_);
}

void Boot::update()
{
	if (position_.y < 1000.0f)
	{
		position_.y += gravity * 4.0f;
	}
	else
	{
		init();
	}
}

void Boot::draw()
{
	DrawExtendGraph(position_.x, position_.y, position_.x + boot_widht, position_.y + boot_height, graphHandle_, TRUE);
}

void Boot::init()
{
	position_ = VGet(static_cast<float>(GetRand(1920)) - boot_widht, init_pos_y, 0.0f);
}