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


	// �V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();
};
