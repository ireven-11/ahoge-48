#pragma once

constexpr float boot_widht	= 100.0f;
constexpr float boot_height = 100.0f;

class Boot
{
public:
	Boot();
	~Boot();

	void	update();
	void	draw();
	void	init();
	VECTOR	getPosition()const noexcept { return position_; }

private:
	int		graphHandle_;
	VECTOR	position_;

	const float init_pos_y = -100;
};