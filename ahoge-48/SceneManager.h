#pragma once
#include"SceneBase.h"

class SceneContext;
class Title;
class Play;
class Result;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void update();
	void draw()const;

private:
	void proceed();
	void titleToPlay();
	void playToResult();
	void resultToTitle();

	//シーンインスタンス
	std::shared_ptr<SceneBase<SceneContext>> currentScene_;
	std::shared_ptr<SceneContext> context_;
	std::shared_ptr<Title> titleScene_;
	std::shared_ptr<Play> playScene_;
	std::shared_ptr<Result> resultScene_;
};