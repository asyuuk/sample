#include "DxLib.h"
#include"typedefclass.h"
#include"PlayerEnemyManager.h"
#include"BackGrounds.h"
#include"scenemanager.h"
// �v���O������ WinMain ����n�܂�܂�

int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if (ClearDrawScreen() != 0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	 //���݂̃p�b�h���͏������s��
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	PlayerEnemyManager PEM;
	BackGrounds Back;
	scenemanager sc;
	int key[256];
	char tmpkey[256];
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	GetHitKeyStateAll(tmpkey);
	for (int i = 0; i < 256; i++) {
		if (tmpkey[i] != 0) {
			key[i] ++;
		}
		else {
			key[i] = 0;
		}
	}
	
	SetDrawScreen(DX_SCREEN_BACK);
	ChangeWindowMode(TRUE);
	//SetGraphMode(1064, 840,32);

	PEM.LoadImages();
	Back.BackGroundImages();
	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
	while (ProcessLoop()==0) {
		ClearDrawScreen();
		sc.scene();
		ScreenFlip();
	}
	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}