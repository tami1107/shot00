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


	// �V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();
};
