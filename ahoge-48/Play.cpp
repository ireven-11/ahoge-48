#include"DxLib.h"
#include"Message.h"
#include"Rain.h"
#include"Player.h"
#include"Play.h"

Play::Play(std::shared_ptr<SceneContext> context) : SceneBase(context)
{
	
}

Play::~Play()
{
	message_	= nullptr;
	rain_		= nullptr;
	player_		= nullptr;
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

	player_->update();
}

void Play::draw()
{
	rain_->draw();

	message_->draw(context()->getFontSize35());

	player_->draw();
}