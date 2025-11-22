#pragma once

class Message
{
public:
	Message();
	~Message();

	void update();
	void draw(const int fontHandle)const;
	void init();

	bool getIsDrawing()const noexcept { return isdrawing_; }

private:
	bool	isdrawing_;
	bool	isPrevButton_;
	short	counter_;

	constexpr static	short	max_count	= 2;
	const				VECTOR	text_pos	= VGet(200.0f, 900.0f, 0.0f);
};