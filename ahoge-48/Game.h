#pragma once
#include"Singleton.h"
#include<memory>

#define winmainSetting	HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow		//winmainの引数
#define gameRoopSetting ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0						//ゲームループの引数

class FPS;
class SceneManager;

class Game : public Singleton<Game>
{
public:
	~Game();

	void update();

private:
	//Singletonのフレンドに宣言してコンストラクタにアクセス許可
	friend class Singleton<Game>;
	Game();

	int rain_;

	//インスタンス
	std::unique_ptr<FPS> fps_				= std::make_unique<FPS>();
	std::unique_ptr<SceneManager> scene_	= std::make_unique<SceneManager>();
};