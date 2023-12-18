#include "DxLib.h"
#include"typedefclass.h"
#include"PlayerEnemyManager.h"
#include"BackGrounds.h"
#include"scenemanager.h"
// プログラムは WinMain から始まります

int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//プロセス処理がエラーなら-1を返す
	if (ClearDrawScreen() != 0)return -1;//画面クリア処理がエラーなら-1を返す
	 //現在のパッド入力処理を行う
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	PlayerEnemyManager PEM;
	BackGrounds Back;
	scenemanager sc;
	int key[256];
	char tmpkey[256];
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
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
	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ProcessLoop()==0) {
		ClearDrawScreen();
		sc.scene();
		ScreenFlip();
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}