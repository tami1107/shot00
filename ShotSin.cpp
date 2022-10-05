#include "ShotSin.h"
#include "game.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
	constexpr float kGrabity = 0.5f;
	constexpr float kSinTime = 0.5f;
}


void ShotSin::start(Vec2 pos)
{
	ShotBase::start(pos);


	m_vec.x = kShotSpeed;
	m_vec.y = -10.0f;

	m_SinTime = kSinTime;
}

void ShotSin::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;

	m_SinTime--;
	m_vec.y += kGrabity;

	if (m_SinTime < 0)
	{
		m_vec.y -= kGrabity;
	}


	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}

