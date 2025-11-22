#pragma once

class Message
{
public:
	Message();
	~Message();

	void update();
	void draw()const;
	void init();

	bool getIsDrawing()const noexcept { return isdrawing_; }

private:
	bool	isdrawing_;
	bool	isPrevButton_;
	short	counter_;

	constexpr static short max_count = 2;
};