#pragma once
#include"SceneBase.h"
#include"SceneContext.h"

class TitleUI;

class Title : public SceneBase<SceneContext>
{
public:
	Title(std::shared_ptr<SceneContext> context);
	~Title();

	void init();
	void update();
	void draw();

private:
	std::shared_ptr<TitleUI> ui_ = std::make_shared<TitleUI>();
};