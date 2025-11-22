#include"DxLib.h"
#include"Message.h"
#include"Rain.h"
#include"Player.h"
#include"Stage.h"
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
}

void Play::init()
{
	
}

void Play::update()
{
	rain_->update();

	message_->update();

	//メッセージが終わるまでほかの更新はしない
	if (message_->getIsDrawing()) return;

	player_->update(stage_);

	stage_->update();
}

void Play::draw()
{
	stage_->draw();

	rain_->draw();

	message_->draw(context()->getFontSize35());

	player_->draw();
}