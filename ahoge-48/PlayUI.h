#pragma once

class PlayUI
{
public:
	PlayUI();
	~PlayUI();

	void draw(const int fontHandle, int gage);
	void init();

private:
	int boot_;
};