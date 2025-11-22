#include"DxLib.h"
#include"Title.h"
#include"Play.h"
#include"SceneManager.h"

SceneManager::SceneManager() : context_(std::make_shared<SceneContext>())
{
	titleScene_		= std::make_shared<Title>(context_);
	playScene_		= std::make_shared<Play>(context_);
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
}

void SceneManager::titleToPlay()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		currentScene_ = playScene_;
	}
}