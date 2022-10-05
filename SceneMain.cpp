#include "DxLib.h"
#include "SceneMain.h"

namespace
{
	// ショットの発射間隔
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);

	for (auto& shot : m_pShotNormal)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotParabolay)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotDelay)
	{
		shot = nullptr;
	}
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotParabolay)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotDelay)
	{
		if (!shot) continue;
		delete shot;
		shot = nullptr;
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotParabolay)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotDelay)
	{
		if (!shot) continue;
		shot->update();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		shot->draw();
	}
	for (auto& shot : m_pShotParabolay)
	{
		if (!shot) continue;
		shot->draw();
	}
	for (auto& shot : m_pShotDelay)
	{
		if (!shot) continue;
		shot->draw();
	}
	
	// 現在存在している弾の数を表示
	int shotNum = 0;
	for (auto& shot : m_pShotNormal)
	{
		if (!shot) continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Normal：%d", shotNum);

	shotNum = 0;
	for (auto& shot : m_pShotParabolay)
	{
		if (!shot) continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 32, GetColor(255, 255, 255), "Parabolay：%d", shotNum);

	shotNum = 0;
	for (auto& shot : m_pShotDelay)
	{
		if (!shot) continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 64, GetColor(255, 255, 255), "Delay：%d", shotNum);
}

bool SceneMain::createShotNormal(Vec2 pos)
{
	for (auto& shot : m_pShotNormal)
	{
		if (shot)	continue;

		shot = new ShotNormal;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}

bool SceneMain::createShotParabolay(Vec2 pos)
{
	for (auto& shot : m_pShotParabolay)
	{
		if (shot)	continue;

		shot = new ShotParabolay;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}

bool SceneMain::createShotDelay(Vec2 pos)
{
	for (auto& shot : m_pShotDelay)
	{
		if (shot)	continue;

		shot = new ShotDelay;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}