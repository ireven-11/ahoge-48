#include"DxLib.h"
#include"PlayUI.h"

PlayUI::PlayUI()
{
	boot_ = LoadGraph("graph/boot.png");
}

PlayUI::~PlayUI()
{
	DeleteGraph(boot_);
}

void PlayUI::draw(const int fontHandle, int gage)
{
	DrawBox(150, 975, 150 + gage, 1025, GetColor(50, 255, 50), TRUE);
	DrawCircle(100, 1000, 75, GetColor(255, 255, 255), TRUE);
	DrawRotaGraph(100, 1000, 0.25, 0, boot_, TRUE);

	DrawStringToHandle(1000, 975, "移動：A,D ジャンプ：W ダッシュ：左シフト", GetColor(255, 255, 255), fontHandle);
}

void PlayUI::init()
{

}