#include"DxLib.h"
#include"FPS.h"
#include"SceneManager.h"
#include"Game.h"

Game::Game()
{
	fps_->init();
	rain_ = LoadSoundMem("sound/rain.mp3");
}

Game::~Game()
{
	fps_	= nullptr;
	scene_	= nullptr;
	DeleteSoundMem(rain_);
}

void Game::update()
{
	PlaySoundMem(rain_, DX_PLAYTYPE_LOOP);
	while (gameRoopSetting)
	{
		//画面に描かれた物を消す(ゲームループの最初に呼ぶ)
		ClearDrawScreen();

		scene_->update();
		scene_->draw();

		fps_->update();
		//fps_->draw();
		fps_->wait();

		//裏画面の内容を表画面に反映(ゲームループの最後に呼ぶ)
		ScreenFlip();
	}
	StopSoundMem(rain_);
}