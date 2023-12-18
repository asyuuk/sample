#include "scenemanager.h"
#include"PlayerEnemyManager.h"
#include"BackGrounds.h"
#include "typedefclass.h"
#include"firstscene.h"
#include"DxLib.h"

PlayerEnemyManager PEM;
BackGrounds Back;
Scene sc;
firstscene fs;
void scenemanager::scene()
{
	int key[256];
	char tmpkey[256];
	
	GetHitKeyStateAll(tmpkey);
	for (int i = 0; i < 256; i++) {
		if (tmpkey[i] != 0) {
			key[i]++;
		}
		else {
			key[i] = 0;
		}
	}
	switch (sc.scenecount) {
	case 1:

		fs.title();
		if (CheckHitKey(KEY_INPUT_Q))
			ClearDrawScreen();
			sc.scenecount = 2;
		break;
	case 2:
		Back.BackGround1();
		PEM.EnemyAppearPattern();
		PEM.Player();
		PEM.Player_Shooting();
		PEM.Score();
		break;
	}
}