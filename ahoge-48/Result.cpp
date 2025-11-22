#include"DxLibForIreven.h"
#include"Result.h"

Result::Result(std::shared_ptr<SceneContext> context) : SceneBase(context)
{
}

Result::~Result()
{
}

void Result::init()
{
	context()->getScore()->init();
}

void Result::update()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "スコア：%d", context()->getScore()->getCounter());

	DrawString(500, UpDownPositionY(500.0f,10.0f,100.0f), "spaceでタイトルへ", GetColor(255, 255, 255));
}

void Result::draw()
{
	
}

bool Result::canChangeScene()
{
	return true;
}