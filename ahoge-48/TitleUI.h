#pragma once

class TitleUI
{
public:
	TitleUI();
	~TitleUI();

	void update();
	void draw(const int fontHandle1, const int fontHandle2)const;

private:

	const VECTOR title_pos			= VGet(500.0f, 100.0f, 0.0f);
	const VECTOR start_button_pos	= VGet(770.0f, 720.0f, 0.0f);
	const float up_down_amplitude	= 10.0f;
	const float up_down_period		= 100.0f;
};