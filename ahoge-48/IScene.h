#pragma once

class IScene
{
public:
	virtual ~IScene() = default;

	virtual void init()				= 0;
	virtual void update()			= 0;
	virtual void draw()				= 0;
	virtual bool canChangeScene()	= 0;
};