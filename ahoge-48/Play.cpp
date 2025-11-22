#include"DxLib.h"
#include"Message.h"
#include"Play.h"

Play::Play(std::shared_ptr<SceneContext> context) : SceneBase(context)
{
	
}

Play::~Play()
{
	message_ = nullptr;
}

void Play::init()
{
	
}

void Play::update()
{
	message_->update();

	//メッセージが終わるまでほかの更新はしない
	if (message_->getIsDrawing()) return;
}

void Play::draw()
{
	message_->draw();
}