#include"DxLibForIreven.h"
#include"Result.h"

Result::Result(std::shared_ptr<SceneContext> context) : SceneBase(context)
{
	sleep_ = LoadGraph("graph/sleep.png");
}

Result::~Result()
{
	DeleteGraph(sleep_);
}

void Result::init()
{
	context()->getScore()->init();
}

void Result::update()
{
	SetFontSize(100);

	DrawExtendGraph(600, 500, 1200, 1000, sleep_, TRUE);

	DrawFormatString(600, 100, GetColor(255, 255, 255), "スコア：%d", context()->getScore()->getCounter());

	SetFontSize(50);

	DrawString(700, UpDownPositionY(400.0f,10.0f,100.0f), "spaceでタイトルへ", GetColor(255, 255, 255));
}

void Result::draw()
{
	
}

bool Result::canChangeScene()
{
	return true;
}