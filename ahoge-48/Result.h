#pragma once
#include"SceneBase.h"
#include"SceneContext.h"

class Result : public SceneBase<SceneContext>
{
public:
	Result(std::shared_ptr<SceneContext> context);
	~Result();

	void init();
	void update();
	void draw();
	bool canChangeScene();

private:
};