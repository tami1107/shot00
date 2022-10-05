#pragma once

#include "player.h"
#include "ShotNormal.h"
#include "ShotParabolay.h"
#include "ShotDelay.h"
#include "ShotSin.h"
#include "ShotBound.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();

	// �e�̐���
	bool createShotNormal(Vec2 pos);
	bool createShotParabolay(Vec2 pos);
	bool createShotDelay(Vec2 pos);

private:
	// �V���b�g�̍ő吔
	static constexpr int kShotMax = 64;

private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// �v���C���[
	Player m_player;
	// �V���b�g
//	ShotBase* m_Shot[kShotMax];

	ShotNormal* m_pShotNormal[kShotMax];
	ShotParabolay* m_pShotParabolay[kShotMax];
	ShotDelay* m_pShotDelay[kShotMax];



//	ShotSin m_shot[kShotMax];
//	ShotBound m_shot[kShotMax];
};