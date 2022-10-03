#pragma once

#include "ShotBase.h"

class ShotDelay : public ShotBase
{
public:
	ShotDelay()
	{
	}

	virtual ~ShotDelay()
	{
	}


	// ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();
};
