#pragma once

#include "player.h"
#include "ShotBase.h"
#include <vector>


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

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// �v���C���[
	Player m_player;
	// �V���b�g
	 std::vector<ShotBase*> m_pShotVt;
	//ShotBase* m_pShot[kShotMax];
};