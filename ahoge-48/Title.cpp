#include"DxLib.h"
#include"TitleUI.h"
#include"Title.h"

Title::Title(std::shared_ptr<SceneContext> context) : SceneBase(context)
{
	backGround_		= LoadGraph("graph/titleback.png");
	bootWithCat_	= LoadGraph("graph/catInBoot.png");
}

Title::~Title()
{
	DeleteGraph(backGround_);
	DeleteGraph(bootWithCat_);
}

void Title::init()
{
	
}

void Title::update()
{
	
}

void Title::draw()
{
	DrawExtendGraph(0, 0, 1920, 1080, backGround_, TRUE);

	DrawExtendGraph(300, 300, 900, 900, bootWithCat_, TRUE);

	ui_->draw(context()->getFontSize100(), context()->getFontSize50());
}

bool Title::canChangeScene()
{
	return true;
}