#pragma once
#include"SceneBase.h"
#include"SceneContext.h"

class Message;

class Play : public SceneBase<SceneContext>
{
public:
	Play(std::shared_ptr<SceneContext> context);
	~Play();

	void init();
	void update();
	void draw();

private:
	
	//インスタンス
	std::shared_ptr<Message> message_ = std::make_shared<Message>();
};