#pragma once

#include "ShotBase.h"

class ShotParabolay : public ShotBase
{
public:
	ShotParabolay()
	{
	}

	virtual ~ShotParabolay()
	{
	}


	// ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();
};
