#pragma once
#include"SceneBase.h"
#include"SceneContext.h"

class Message;
class Rain;
class Player;
class Stage;

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
	std::shared_ptr<Message>	message_	= std::make_shared<Message>();
	std::shared_ptr<Rain>		rain_		= std::make_shared<Rain>();
	std::shared_ptr<Player>		player_		= std::make_shared<Player>();
	std::shared_ptr<Stage>		stage_		= std::make_shared<Stage>();
};