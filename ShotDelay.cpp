#include "ShotDelay.h"
#include "game.h"

namespace
{
	// �V���b�g�̑��x
	constexpr float kShotSpeed2 = 8.0f;
	// �V���b�g��ł��o���Ď~�܂�܂ł̎���
	constexpr int kDelayTime = 15;
	// ��~�����V���b�g���ēx�ł��o���܂ł̎���
	constexpr int kWaitFrame = 30;
	// �ēx�ł��o���ꂽ�V���b�g�̑��x
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
