#include"DxLib.h"
#include"Stage.h"

Stage::Stage()
{
	waterGraph_		= LoadGraph("graph/water.png");
	skyGraph_		= LoadGraph("graph/sky.png");
	skypos1_		= VGet(0.0f, 0.0f, 0.0f);
	skypos2_		= VGet(0.0f, -sky_height + 1.0f, 0.0f);
	scaffoldGraph_	= LoadGraph("graph/tileset.png");
	for (int i = 0; i < max_scaffold_number; i++)
	{
		scaffoldPos_[i] = VGet(0.0f, 0.0f, 0.0f);
		scaffoldGraphArray_[i] = scaffoldGraph_;
	}
	scaffoldCounter_ = 0;
}

Stage::~Stage()
{
	DeleteGraph(waterGraph_);
	DeleteGraph(skyGraph_);
	for (int i = 0; i < max_scaffold_number; i++)
	{
		DeleteGraph(scaffoldGraphArray_[i]);
	}
}

void Stage::init()
{
	skypos1_ = VGet(0.0f, 0.0f, 0.0f);
	skypos2_ = VGet(0.0f, -sky_height, 0.0f);
	for (int i = 0; i < max_scaffold_number; i++)
	{
		scaffoldPos_[i] = VGet(0.0f, 0.0f, 0.0f);
	}
	scaffoldCounter_ = 0;
}

void Stage::update()
{
	updateSky();
	updateScaffold();
}

void Stage::draw()const
{
	DrawExtendGraph(skypos1_.x, skypos1_.y, skypos1_.x + sky_widht, skypos1_.y + sky_height, skyGraph_, TRUE);
	DrawExtendGraph(skypos2_.x, skypos2_.y, skypos2_.x + sky_widht, skypos2_.y + sky_height, skyGraph_, TRUE);

	for (int i = 0; i < max_scaffold_number; i++)
	{
		DrawExtendGraph(scaffoldPos_[i].x, scaffoldPos_[i].y, scaffoldPos_[i].x + scaffold_widht, scaffoldPos_[i].y + scaffold_height,
			scaffoldGraph_, TRUE);
	}

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

void Stage::updateScaffold()
{
	for (int i = 0; i < max_scaffold_number; i++)
	{
		scaffoldPos_[i].y += scaffold_fall_spped;
	}

	++scaffoldCounter_;
	if (scaffoldCounter_ < max_scaffold_Count) return;

	scaffoldCounter_ = 0;
	for (int i = 0; i < max_scaffold_number; i++)
	{
		if (scaffoldPos_[i].y > 1080 || scaffoldPos_[i].y < 0) 
		{
			scaffoldPos_[i].y = init_scaffold_pos_y;
			scaffoldPos_[i].x = static_cast<float>(SRand(1920) - scaffold_widht / 2);
		}
	}
}