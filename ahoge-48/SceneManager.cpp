#include"DxLib.h"
#include"Title.h"
#include"Play.h"
#include"Result.h"
#include"SceneManager.h"

SceneManager::SceneManager() : context_(std::make_shared<SceneContext>())
{
	titleScene_		= std::make_shared<Title>(context_);
	playScene_		= std::make_shared<Play>(context_);
	resultScene_	= std::make_shared<Result>(context_);
	currentScene_	= titleScene_;
}

SceneManager::~SceneManager()
{
	currentScene_	= nullptr;
	titleScene_		= nullptr;
	playScene_		= nullptr;
	context_		= nullptr;
}

void SceneManager::update()
{
	currentScene_->update();

	proceed();
}

void SceneManager::draw()const
{
	currentScene_->draw();
}

void SceneManager::proceed()
{
	titleToPlay();
	playToResult();
	resultToTitle();
}

void SceneManager::titleToPlay()
{
	if (CheckHitKey(KEY_INPUT_RETURN) && currentScene_ == titleScene_)
	{
		currentScene_ = playScene_;
	}
}

void SceneManager::playToResult()
{
	if (currentScene_->canChangeScene() && currentScene_ == playScene_)
	{
		currentScene_->init();
		currentScene_ = resultScene_;
	}
}

void SceneManager::resultToTitle()
{
	if (CheckHitKey(KEY_INPUT_SPACE) && currentScene_ == resultScene_)
	{
		currentScene_->init();
		currentScene_ = titleScene_;
	}
}