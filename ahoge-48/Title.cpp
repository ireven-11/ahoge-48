#include"DxLib.h"
#include"TitleUI.h"
#include"Title.h"

Title::Title(std::shared_ptr<SceneContext> context) : SceneBase(context)
{
}

Title::~Title()
{
}

void Title::init()
{
	
}

void Title::update()
{
	
}

void Title::draw()
{
	ui_->draw(context()->getFontSize100(), context()->getFontSize50());
}

bool Title::canChangeScene()
{
	return true;
}