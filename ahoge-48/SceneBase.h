#pragma once
#include<memory>
#include"IScene.h"

//サンドボックスパターン
//テンプレートにして色々なコンテキストに対応する
template<typename ContextT>
class SceneBase : IScene
{
public:
	SceneBase(std::shared_ptr<ContextT> context)
		: context_(context)
	{

	}
	virtual ~SceneBase() = default;

	virtual void init()		= 0;
	virtual void update()	= 0;
	virtual void draw()		= 0;

protected:
	//コンテキストを継承先で呼び出せるようにしてさらにコンテキストからオブジェクトを呼ぶ
	std::shared_ptr<ContextT> context() { return context_; }

private:
	std::shared_ptr<ContextT> context_;
};