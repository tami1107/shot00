#include "ShotDelay.h"
#include "game.h"

namespace
{
	// ショットの速度
	constexpr float kShotSpeed2 = 8.0f;
	// ショットを打ち出して止まるまでの時間
	constexpr int kDelayTime = 15;
	// 停止したショットを再度打ち出すまでの時間
	constexpr int kWaitFrame = 30;
	// 再度打ち出されたショットの速度
	constexpr float kShotAcceleration = 12.0f;
}


void ShotDelay::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = kShotSpeed2;
	m_vec.y = 0.0f;

	m_waitFrame = kWaitFrame;
	m_delayTime = kDelayTime;
}

void ShotDelay::update()
{
	if (!m_isExist) return;
	m_pos += m_vec;

	m_delayTime--;

	if (m_delayTime < 0)
	{
		m_vec.x = 0.0f;
		m_waitFrame--;
	}
	if (m_waitFrame < 0)
	{
		m_vec.x = kShotAcceleration;
	}
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
