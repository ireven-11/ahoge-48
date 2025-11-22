#pragma once
#include<memory>
#include"Score.h"

//playerなどの色々なシーンで使用するかもしれないオブジェクトを持つクラス
//オブジェクトを呼び出すことはできるが変更はできない
class SceneContext final
{
public:
	SceneContext()
	{

	}
	~SceneContext()
	{
		DeleteFontToHandle(fontSize100_);
	}
	int		getFontSize100()const noexcept { return fontSize100_; }
	int		getFontSize50()const noexcept { return fontSize50_; }
	int		getFontSize35()const noexcept { return fontSize35_; }
	std::shared_ptr<Score> getScore()const noexcept { return score_; }

private:
	std::shared_ptr<Score> score_ = std::make_shared<Score>();

	const int fontSize100_ = CreateFontToHandle("HGS創英角ポップ体", 100, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	const int fontSize50_ = CreateFontToHandle("HGS創英角ポップ体", 50, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	const int fontSize35_ = CreateFontToHandle("HGS創英角ポップ体", 35, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
};