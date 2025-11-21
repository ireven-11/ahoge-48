#pragma once
#include"IScene.h"
#include"SceneBase.h"
#include"SceneContext.h"
#include<vector>

class Play : public SceneBase<SceneContext>
{
public:
	Play(std::shared_ptr<SceneContext> context);
	~Play();

	void init();
	void update();
	void draw();

private:
};