#pragma once
#include<memory>

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
	int getFontSize100()const noexcept { return fontSize100_; }
	int getFontSize50()const noexcept { return fontSize50_; }

private:
	const int fontSize100_ = CreateFontToHandle("HGS創英角ポップ体", 100, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	const int fontSize50_ = CreateFontToHandle("HGS創英角ポップ体", 50, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
};