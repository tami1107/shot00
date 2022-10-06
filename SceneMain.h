#pragma once

#include "player.h"
#include "ShotBase.h"
#include <vector>


class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// 初期化
	void init();
	// 終了処理
	void end();

	// 毎フレームの処理
	void update();
	// 毎フレームの描画
	void draw();

	// 弾の生成
	bool createShotNormal(Vec2 pos);
	bool createShotParabolay(Vec2 pos);
	bool createShotDelay(Vec2 pos);


private:

	// プレイヤーのグラフィックハンドル
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// プレイヤー
	Player m_player;
	// ショット
	 std::vector<ShotBase*> m_pShotVt;
	//ShotBase* m_pShot[kShotMax];
};