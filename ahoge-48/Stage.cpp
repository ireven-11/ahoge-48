#include"DxLib.h"
#include"Stage.h"

Stage::Stage()
{
	waterGraph_		= LoadGraph("graph/water.png");
	skyGraph_		= LoadGraph("graph/sky.png");
	skypos1_		= VGet(0.0f, 0.0f, 0.0f);
	skypos2_		= VGet(0.0f, -sky_height + 1.0f, 0.0f);
	scaffoldGraph_	= LoadGraph("graph/tileset.png");
}

Stage::~Stage()
{
	DeleteGraph(waterGraph_);
	DeleteGraph(skyGraph_);
}

void Stage::init()
{
	skypos1_ = VGet(0.0f, 0.0f, 0.0f);
	skypos2_ = VGet(0.0f, -sky_height, 0.0f);

}

void Stage::update()
{
	updateSky();
}

void Stage::draw()const
{
	DrawExtendGraph(skypos1_.x, skypos1_.y, skypos1_.x + sky_widht, skypos1_.y + sky_height, skyGraph_, TRUE);
	DrawExtendGraph(skypos2_.x, skypos2_.y, skypos2_.x + sky_widht, skypos2_.y + sky_height, skyGraph_, TRUE);

	DrawExtendGraph(water_position.x, water_position.y, water_position.x + water_width, water_position.y + water_height,
		waterGraph_, TRUE);
}

void Stage::updateSky()
{
	skypos1_.y += scroll_speed;
	skypos2_.y += scroll_speed;

	if (skypos1_.y > sky_height)
	{
		skypos1_.y = -sky_height;
	}
	else if (skypos2_.y > sky_height)
	{
		skypos2_.y = -sky_height;
	}
}