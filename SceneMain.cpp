#include "DxLib.h"
#include "SceneMain.h"

#include "ShotNormal.h"
#include "ShotParabolay.h"
#include "ShotDelay.h"
#include "ShotSin.h"
#include "ShotBound.h"

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
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& pShot : m_pShotVt)
	{
		if (!pShot) continue;
		delete pShot;
		pShot = nullptr;
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();

	std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
	while (it != m_pShotVt.end())
	{
		auto pShot = (*it);
		if (!pShot)
		{
			it++;
			continue;
		}
		pShot->update();
		if (!pShot->isExist())
		{
			delete pShot;
			pShot = nullptr;

			// vestorの要素削除
			it = m_pShotVt.erase(it);
			continue;
		}
		
		it++;
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	for (auto& pShot : m_pShotVt)
	{
		if (!pShot) continue;
		pShot->draw();
	}

	// 現在存在している弾の数を表示
	DrawFormatString(0, 0, GetColor(255, 255, 255), "弾の数：%d", m_pShotVt.size());

}

bool SceneMain::createShotNormal(Vec2 pos)
{
	ShotNormal* pShot = new ShotNormal;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}

bool SceneMain::createShotParabolay(Vec2 pos)
{
	ShotDelay* pShot = new ShotDelay;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}

bool SceneMain::createShotDelay(Vec2 pos)
{
	ShotParabolay* pShot = new ShotParabolay;
	pShot->setHandle(m_hShotGraphic);
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}