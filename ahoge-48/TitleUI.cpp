#include"DxLibForIreven.h"
#include"TitleUI.h"

TitleUI::TitleUI()
{
}

TitleUI::~TitleUI()
{
}

void TitleUI::update()
{

}

void TitleUI::draw(const int fontHandle1, const int fontHandle2)const
{
    DrawStringFToHandle(title_pos.x, title_pos.y, "–‚–@‚Ì’·ŒCwith”L", GetColor(50, 50, 255), fontHandle1);
    DrawStringFToHandle(start_button_pos.x, UpDownPositionY(start_button_pos.y, up_down_amplitude, up_down_period),
        "EnterToStart", GetColor(50, 50, 255), fontHandle2);
}