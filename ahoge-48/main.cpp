#include"DxLibForIreven.h"
#include"Game.h"

int WINAPI WinMain(winmainSetting)
{
    InitDxLib();

    Game& game = Game::instance();
    game.update();

    DxLib_End();

    return 0;
}