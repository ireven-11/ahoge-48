#pragma once

class Score
{
public:
	Score();
	~Score();

	void	init();
	void	update();
	int		getCounter()const noexcept { return counter_; }

private:
	int counter_;

	const int max_count = 1000;
};