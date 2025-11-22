#pragma once

constexpr	float	gravity				= 0.6f;
const		VECTOR	water_position		= VGet(0.0f, 700.0f, 0.0f);
constexpr	short	max_scaffold_number = 10;
constexpr	float	scaffold_widht		= 200.0f;
constexpr	float	scaffold_height		= 75.0f;

class Stage
{
public:
	Stage();
	~Stage();

	void init();
	void update();
	void draw()const;

private:
	void updateSky();
	void updateScaffold();

	int		waterGraph_;
	int		skyGraph_;
	VECTOR	skypos1_;
	VECTOR	skypos2_;
	int		scaffoldGraph_;
	int		scaffoldGraphArray_[max_scaffold_number];
	VECTOR	scaffoldPos_[max_scaffold_number];
	short	scaffoldCounter_;

	const float		water_width			= 1920.0f;
	const float		water_height		= 1080.0f;
	const float		sky_widht			= 1920.0f;
	const float		sky_height			= 1080.0f;
	const float		scroll_speed		= 1.0f;
	const float		init_scaffold_pos_y	= -20.0f;
	const short		max_scaffold_Count	= 200;
	const float		scaffold_fall_spped = 5.0f;
};