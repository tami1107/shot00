#include "ShotParabolay.h"

namespace
{
	constexpr float kShotSpeed2 = 8.0f;
	// èdóÕ
	constexpr float kGrabity = 0.5f;
}


void ShotParabolay::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = kShotSpeed2;
	m_vec.y = -10.0f;

	
}

void ShotParabolay::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;
	
	m_vec.y += kGrabity;
}
