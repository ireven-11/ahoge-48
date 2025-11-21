#pragma once
#include"SceneBase.h"
#include"SceneContext.h"

class Title : public SceneBase<SceneContext>
{
public:
	Title(std::shared_ptr<SceneContext> context);
	~Title();

	void init();
	void update();
	void draw();

private:
};