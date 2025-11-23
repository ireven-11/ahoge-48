#include"DxLib.h"
#include"Message.h"
#include"Rain.h"
#include"Player.h"
#include"Stage.h"
#include"Boot.h"
#include"Play.h"

Play::Play(std::shared_ptr<SceneContext> context) : SceneBase(context)
{
	
}

Play::~Play()
{
	message_	= nullptr;
	rain_		= nullptr;
	player_		= nullptr;
	stage_		= nullptr;
	boot_		= nullptr;
}

void Play::init()
{
	message_->init();
	rain_->init();
	player_->init();
	stage_->init();
}

void Play::update()
{
	rain_->update();

	message_->update();

	//メッセージが終わるまでほかの更新はしない
	if (message_->getIsDrawing()) return;

	player_->update(stage_, boot_);

	stage_->update();

	boot_->update();

	context()->getScore()->update();
}

void Play::draw()
{
	stage_->draw();

	boot_->draw();

	rain_->draw();

	message_->draw(context()->getFontSize35());

	player_->draw();
}

bool Play::canChangeScene()
{
	return player_->getIsDead();
}