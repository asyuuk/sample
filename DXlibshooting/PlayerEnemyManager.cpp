#include "PlayerEnemyManager.h"
#include<DxLib.h>
#include<math.h>	
#include <chrono>
#include <thread>
#include <functional>
#include"typedefclass.h"

Player player;
Enemy1 en1;
Enemy2 en2;
Enemy3 en3;
Enemy4 en4;
Boss Bos;
SHOT  *shot=new SHOT[Shot];
BackGround Bk;
Enemy_Bullet *EB = new Enemy_Bullet[5];
Enemy_Bullet1 *EB1=new Enemy_Bullet1[1];
Enemy_Bullet2 *EB2=new Enemy_Bullet2[5];
Attack_area At;
Bomb bomb;
#define M_PI 3.1415926535897932384626

int pattern=0;
int image[12];
int point = 0;
int image2[3];
int image3[3];
int effect;
void PlayerEnemyManager::LoadImages()
{
	Bos.g_handle = LoadGraph("E:\\Aseprite\\enemy_big.png");
	LoadDivGraph("E:\\Aseprite\\player.png", 12, 4, 3, 25, 25, image);
	player.g_handle = LoadGraph("E:\\Aseprite\\player.png");
	en1.g_handle = LoadGraph("E:\\Aseprite\\enemyg_2.png");
	en1.g_handle1 = LoadGraph("E:\\Aseprite\\enemyg_2.png");
	en1.g_handle2 = LoadGraph("E:\\Aseprite\\enemyg_2.png");
	en2.g_handle = LoadGraph("E:\\Aseprite\\enemyg_1.png");
	en2.g_handle1 = LoadGraph("E:\\Aseprite\\enemyg_1.png");
	en2.g_handle2= LoadGraph("E:\\Aseprite\\enemyg_1.png");
	en3.g_handle = LoadGraph("E:\\Aseprite\\hakureireimu_0001_7.png");
	en4.g_handle = LoadGraph("E:\\Aseprite\\enemyg_1.png");
	en4.g_handle1 = LoadGraph("E:\\Aseprite\\enemyg_1.png");
	LoadDivGraph("E:\\Aseprite\\enemy_big.png", 3, 3, 1, 47, 50, image2);
	for (int i = 0; i < Shot; i++) shot[i].g_handle = LoadGraph("E:\\Aseprite\\bullet0001.png");
	Bk.g_handle = LoadGraph("E:\\Aseprite\\Boom.png");
	for (int i = 0; i < 256; i++) EB[i].g_handle = LoadGraph("E:\\Aseprite\\blt01.png");
	for (int i = 0; i < 256; i++) EB1[i].g_handle = LoadGraph("E:\\Aseprite\\blt01.png");
	for (int i = 0; i < 256; i++) EB2[i].g_handle = LoadGraph("E:\\Aseprite\\blt01.png");
	LoadDivGraph("E:\\Aseprite\\Boom.png", 3, 3, 1, 72,72, image3);


}



void PlayerEnemyManager::Attack_area(int character_x, int character_y, int g_handle, bool visible, int life, int x, int y)
{
	int chara_x = 0 , chara_y = 0;
	int shotx = 0, shoty = 0;
	GetGraphSize(g_handle, &chara_x, &chara_y);
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	
	for (int i = 0; i < Shot; i++) {
		if (shot[i].visible == 1 && visible == true) {
			if (((shot[i].x > character_x && shot[i].x < character_x+x + chara_x) || (character_x > shot[i].x && character_x+x < shot[i].x + shotx)) && ((shot[i].y > character_y && shot[i].y < character_y+y + chara_y) || (character_y > shot[i].y && character_y < shot[i].y + shoty)))
			{
				life--;
				//光る処理　当たったら光る。
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

				DrawRotaGraph(character_x+x, character_y+y, 2.0, 0.0, g_handle, true);

				
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 20);

				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

				

				shot->visible = false;
				if (life <= 0) {
					visible = false;
					point++;
					DeleteGraph(g_handle);
				}
			}
		}
	}
}


void PlayerEnemyManager::Enemy1()
{

	static int starttime = 0;
	static int starttime1 = 0;
	//移動処理
	if (en1.count < 30)
	{
		en1.y += 4;
		en1.y_1 += 2;
		en1.y_2 += 2;
	}
	if (en1.count > 30+30)
	{
		en1.y -= 4;
		en1.y_1 -= 4;
		en1.y_2 -= 4;
	}

	
	int shotx, shoty, en1x, en1y;
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en1.g_handle, &en1x, &en1y);
	//当たり判定
	Attack_area(en1.x, en1.y,  en1.g_handle, en1.visible,en1.life1,0,0);
	
	Attack_area(en1.x_1, en1.y_1, en1.g_handle1, en1.visible1, en1.life2,0,0);

	Attack_area(en1.x_2, en1.y_2, en1.g_handle2, en1.visible2, en1.life3,0,0);

	
	
	//表示
	if (en1.visible == true) {
		DrawRotaGraph(en1.x, en1.y,3.5,0.0, en1.g_handle, true);
	}
	if (en1.visible1 == true) {
		DrawRotaGraph(en1.x_1+10, en1.y_1, 3.5, 0.0, en1.g_handle1, true);
	}
	if (en1.visible2 == true) {
		DrawRotaGraph(en1.x_2, en1.y_2, 3.5, 0.0, en1.g_handle2, true);
	}
	if (en1.y < -10)
	{
		en1.visible = false;
		en1.visible1 = false;
		en1.visible2 = false;
	}
	en1.count++;
	if (en1.count == 150) {
		pattern = 1;
	}
}

void PlayerEnemyManager::Enemy2()
{

	static int starttime = 0;
	en2.y += 10;
	en2.y_1 += 5;
	en2.y_2 += 10;

	int shotx, shoty, en2x, en2y;
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en2.g_handle, &en2x, &en2y);

	if (en2.y > 150)
	{
		en2.y = 150;
		if (starttime == 0) {
			starttime = GetNowCount();
		}
		else {
			int currentTime = GetNowCount();
			if (currentTime - starttime >= 1000) { // 5000ミリ秒（5秒）待つ
				en2.x -= sin(M_PI * (-135) / 180) * 5;
			}
		}
	}


	if (en2.y_2 > 150)
	{
		en2.y_2 = 150;
		if (starttime == 0) {
			starttime = GetNowCount();
		}
		else {
			int currentTime = GetNowCount();
			if (currentTime - starttime >= 1000) { // 5000ミリ秒（5秒）待つ
				en2.x_2 -= sin(M_PI * (135) / 180) * 5;
			}
		}
	}

	if (en2.visible == true)
		DrawRotaGraph(en2.x, en2.y, 2.0, 0.0, en2.g_handle, TRUE);
	if (en2.visible1 == true)
		DrawRotaGraph(en2.x_1, en2.y_1, 2.0, 0.0, en2.g_handle1, TRUE);
	if (en2.visible2 == true)
		DrawRotaGraph(en2.x_2, en2.y_2, 2.0, 0.0, en2.g_handle2, TRUE);
	Attack_area(en2.x, en2.y, en2.g_handle, en2.visible, en2.life,0,0);
	Attack_area(en2.x_1, en2.y_1, en2.g_handle1, en2.visible1, en2.life,0,0);
	Attack_area(en2.x_2, en2.y_2, en2.g_handle2, en2.visible2, en2.life1,0,0);

	
	if (en2.x < -10) {
		en2.visible = false;
		en2.visible1 = false;
		en2.visible2 = false;
	}
		
	en2.count++;
	if (en2.count > 100)
		pattern = 2;
}

void PlayerEnemyManager::Enemy3()
{
	static int starttime = 0;
	int shotx, shoty, en3x, en3y;
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en3.g_handle, &en3x, &en3y);
	//移動処理
	en3.y += 10;
	if (en3.y > 150)
	{
		en3.y = 150;
		if (starttime == 0) {
			starttime = GetNowCount();
		}
		else {
			int currentTime = GetNowCount();
			if (currentTime - starttime >= 1000) { // 5000ミリ秒（5秒）待つ
				en3.x -= sin(M_PI * (270) / 180) * 2;
			}
		}
	}
	//当たり判定
	Attack_area(en3.x, en3.y, en3.g_handle, en3.visible, en3.life,0,0);
	//弾
	if (en3.x > 300)en3.visible = false;
	//表示
	if (en3.visible == true)
		DrawGraph(en3.x, en3.y, en3.g_handle, TRUE);
	en3.count++;
	if(en3.count>100)
		pattern = 3;
}

void PlayerEnemyManager::Enemy4()
{
	en4.visible = true;
	int shotx = 0;
	int shoty = 0;
	int en4x = 0;
	int en4y = 0;
	int count = 0;
	
	
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en4.g_handle1, &en4x, &en4y);
	//移動
	int runX = 2;
	float runY = 3;

	if (en4.count > 60) {
		runY = 0;
	}
	if (en4.count > 70) {
		runY = -1;
	}
	if (en4.count > 75) {
		runY = -2;
	}
	if (en4.count > 90) {
		runY = -3;
	}

	en4.x += runX;
	en4.y += runY;
	
	//当たり判定
	Attack_area(en4.x, en4.y, en4.g_handle, en4.visible,en4.life,0,0);
	//for (int i = 0; i < Shot; i++) {
	//	if (shot[i].visible == 1 && en4.visible == true) {
	//		
	//		if (((shot[i].x > en4.x && shot[i].x < en4.x + en4x) || (en4.x > shot[i].x && en4.x < shot[i].x + shotx)) && ((shot[i].y > en4.y && shot[i].y < en4.y + en4y) || (en4.y > shot[i].y && en4.y < shot[i].y + shoty)))
	//		{
	//			en4.visible = false;
	//			point++;
	//			DeleteGraph(en4.g_handle);
	//		}
	//	}
	//}
	
	if (en4.visible == true)
		DrawGraph(en4.x, en4.y, en4.g_handle, true);
	en4.count += 1;
	if (en4.count > 150)
		pattern = 4;
}

void PlayerEnemyManager::Enemy5()
{
	en4.visible = true;
	int shotx = 0;
	int shoty = 0;
	int en4x = 0;
	int en4y = 0;
	int count = 0;


	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en4.g_handle1, &en4x, &en4y);
	//移動
	int runX = 2;
	float runY = 3;

	if (en4.count > 60) {
		runY = 0;
	}
	if (en4.count > 70) {
		runY = -1;
	}
	if (en4.count > 75) {
		runY = 2;
	}
	if (en4.count > 90) {
		runY = 3;
	}

	en4.x += runX;
	en4.y += runY;

	//当たり判定
	Attack_area(en4.x, en4.y, en4.g_handle1, en4.visible1, en4.life,0,0);

	//for (int i = 0; i < Shot; i++) {
	//	if (shot[i].visible == 1&&en4.visible==true) {
	//
	//		if (((shot[i].x > en4.x && shot[i].x < en4.x + en4x) || (en4.x > shot[i].x && en4.x < shot[i].x + shotx)) && ((shot[i].y > en4.y && shot[i].y < en4.y + en4y) || (en4.y > shot[i].y && en4.y < shot[i].y + shoty)))
	//		{
	//			en4.visible = false;
	//			point++;
	//			DeleteGraph(en4.g_handle);
	//		}
	//	}
	//}

	if (en4.visible1 == true)
		DrawGraph(en4.x, en4.y, en4.g_handle1, true);
	en4.count += 1;
	if (en4.count > 100)
		pattern = 5;
}

void PlayerEnemyManager::Enemy6()
{
	en4.visible = true;
	int shotx = 0;
	int shoty = 0;
	int en4x = 0;
	int en4y = 0;
	int count = 0;


	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en4.g_handle1, &en4x, &en4y);
	//移動
	int runX = 2;
	float runY = 3;

	if (en4.count > 60) {
		runY = 0;
	}
	if (en4.count > 70) {
		runY = -1;
	}
	if (en4.count > 75) {
		runY = -2;
	}
	if (en4.count > 90) {
		runY = -3;
	}

	en4.x += runX;
	en4.y += runY;

	//当たり判定
	for (int i = 0; i < Shot; i++) {
		if (shot[i].visible == 1) {

			if (((shot[i].x > en4.x && shot[i].x < en4.x + en4x) || (en4.x > shot[i].x && en4.x < shot[i].x + shotx)) && ((shot[i].y > en4.y && shot[i].y < en4.y + en4y) || (en4.y > shot[i].y && en4.y < shot[i].y + shoty)))
			{
				en4.visible = false;
				point++;
				DeleteGraph(en4.g_handle);
			}
		}
	}

	if (en4.visible == true)
		DrawGraph(en4.x, en4.y, en4.g_handle, true);
	en4.count += 1;
	pattern = 5;
}

int  PlayerEnemyManager::rang(int x)
{
	return (-x + x * 2 * GetRand(10000) / 10000.0);
}

void PlayerEnemyManager::Bossmove(int dist)
{
	
		int x = Bos.x;
		int y = Bos.y;
		Bos.x = cos(rang(M_PI)) * dist;
		Bos.y = sin(rang(M_PI)) * dist;
		
	
}


void PlayerEnemyManager::Boss()
{
	//移動
	int num = 3;
	int Bosx = 0, Bosy = 0;
	int shotx=0, shoty=0;
	int scean = 0;
	int BossY=0;
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(Bos.g_handle,&Bosx, &Bosy);
	BossY = 5;
	if (Bos.count > 40) {
		BossY = 0;
	}
	Bos.y += BossY;
	//
	
	//当たり判定
	for (int i = 0; i < 3; i++) {
		num = i;
	}
	
	//当たり判定
	for (int i = 0; i < 5; i++) {
		if (shot->visible == 1) {
			if (((shot->x > Bos.x+20 && shot->x < Bos.x + Bosx-50) || (Bos.x+20  > shot->x && Bos.x+20 < EB[i].x +Bosx-50)) && ((shot->y > Bos.y && shot->y < Bos.y + Bosy) || (Bos.y > shot->y && player.y < shot->y + Bosy)))
			{
				//ライフを削る
				Bos.life--;

				//光る処理　当たったら光る。
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

				DrawRotaGraph(Bos.x-25,Bos.y, 2.0, 0.0, image2[num], TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 20);

				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);
				shot->visible == 0;

			}


			if (Bos.life < 0) {
				Bos.visible = false;
				for (int i = 0; i < 12; i++)
					DeleteGraph(image2[i]);
			}
		}
	}
	if (Bos.visible == true) {
		for (int i = 0; i < 3; i++) {
			num = i;
		}
		DrawRotaGraph(Bos.x-25, Bos.y, 2.0, 0.0, image2[num], TRUE);
	}
	//カウント
	Bos.count++;
	//パターン

}

void PlayerEnemyManager::Player()
{
	//キー入力初期化
	int key[256];
	char tmpkey[256];
	int playerX, playerY;
	int num = 0;
	int nm = 0;
	int count=0;
	GetGraphSize(player.g_handle, &playerX, &playerY);
	GetHitKeyStateAll(tmpkey);
	for (int i = 0; i < 256; i++) {
		if (tmpkey[i] != 0) {
			key[i]++;
		}
		else {
			key[i] = 0;
		}
	}


	//操作及び領域確定
	if (key[KEY_INPUT_W] != 0) {
		player.y -= 10;
		if (player.y < 0) {
			player.y = 0;
		}
		for (int i = 0; i < 4; i++) {
			num = i;
		}
	}
	else if (key[KEY_INPUT_S] != 0) {
		player.y += 10;
		if (player.y > 400) {
			player.y = 400;
		}
		for (int i = 0; i < 4; i++) {
			num = i;
		}

	}
	else if (key[KEY_INPUT_D] != 0) {
		player.x += 10;
		if (player.x > 250) {
			player.x = 250;
		}

		for (int i = 0; i < 4; i++)
		{
			num = 4 + i;
		}
	}
	else if (key[KEY_INPUT_A] != 0)
	{
		player.x -= 10;
		if (player.x < 0) {
			player.x = 0;
		}

		for (int i = 0; i < 4; i++) {
			num = 8 + i;
		}
	}
	//当たり判定
	for (int i = 0; i < 5; i++) {
		if (EB[i].visible == 1) {
			if (((EB[i].x - 90 > player.x && EB[i].x < player.x + playerX) || (player.x + 20 > EB[i].x && player.x < EB[i].x + playerX)) && ((EB[i].y > player.y && EB[i].y < player.y + playerY) || (player.y > EB[i].y && player.y < EB[i].y + playerY)))
			{
				//ライフを削る
				player.life--;

				//光る処理　当たったら光る。
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

				DrawRotaGraph(player.x, player.y, 2.0, 0.0, image[num], TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 20);

				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


			}


			if (player.life < 0) {
				player.visible = false;
				for (int i = 0; i < 12; i++)
					DeleteGraph(image[i]);
			}
		}
	}



	for (int i = 0; i < 1; i++) {
		if (EB1[i].visible == true) {
			if (((EB1[i].x + 5 > player.x && EB1[i].x + 5 < player.x + playerX) || (player.x > EB1[i].x + 5 && player.x < EB1[i].x + 5 + playerX)) && ((EB1[i].y > player.y && EB1[i].y < player.y + playerY) || (player.y > EB1[i].y && player.y < EB1[i].y + playerY)))
			{
				//ライフを削る
				player.life--;

				//光る処理　当たったら光る。
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

				DrawRotaGraph(player.x, player.y, 2.0, 0.0, image[num], TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 20);

				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


			}


			if (player.life < 0) {
				player.visible = false;

				for (int i = 0; i < 12; i++)
					DeleteGraph(image[i]);
			}

		}
	}

	//爆発
	if (player.visible == false) {
		
		for (int i = 0; i < 3; i++) {
			nm = i;
			
		}
		if (bomb.visible == true)
			DrawGraph(player.x - 40, player.y - 25, image3[nm], TRUE);
		if (bomb.count==4)
			bomb.visible = false;
		bomb.count++;
	}
		
	
	if(player.visible==true)
	DrawRotaGraph(player.x, player.y,2.0,0.0, image[num], TRUE);

	
}



	



void PlayerEnemyManager::Player_Shooting()
{
	//スペースが押されたときの初期化
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < Shot; i++)
		{
			if (shot[i].visible == 0)
			{
				shot[i].x = player.x-10;
				shot[i].y = player.y;
				shot[i].visible = 1;
				break;
			}
		}
	}
	for (int i = 0; i < Shot; i++) {
		if (shot[i].visible == 1)
		{
			shot[i].y -= 30;
			if (shot[i].y < -200)
			{
				shot[i].visible = 0;

			}
		}
		DrawGraph(shot[i].x, shot[i].y, shot[i].g_handle, true);
	}

	if (player.visible == false)
	{
		shot->visible = false;
		DeleteGraph(shot->g_handle);
	}
}



void PlayerEnemyManager::Score()
{
	int shotx = 0;
	int shoty = 0;
	int en1x = 0;
	int en1y = 0;
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en1.g_handle, &en1x, &en1y);

	
	LPCSTR char_number = "E:\\Fonts\\PixelMplus10-Regular.ttf";
	if (AddFontResource(char_number) > 0) {
		PostMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	if (player.life < 0)
		player.life = 0;

	SetFontSize(20);	// 見やすさのため、フォントサイズを大きく
	ChangeFont("PixelMplus10", DX_CHARSET_DEFAULT);
	DrawFormatString(500, 200, GetColor(255, 255, 255),"%d", point);
	DrawString(350, 300, "自機ライフポイント", GetColor(255, 255, 255));
	DrawFormatString(500, 350, GetColor(255, 255, 255), "%d", player.life);
	DrawFormatString(500, 450, GetColor(255, 255, 255), "%d", en1.life1);


}

void PlayerEnemyManager::Enemy_Shooting()
{
	int count=1;
	if (en1.y < 0 || en1.visible == false)
	{
		EB2->visible = false;
		DeleteGraph(EB2->g_handle);
	}

	for (int i = 0; i < 1; i++) {
		if (EB2[i].visible == false) {
			EB2[i].x = en1.x_1;
			EB2[i].y = en2.y_1;
			EB2[i].visible = true;
		}
	}
	for (int i = 0; i < 1; i++) {
		if (EB2[i].visible) 
		{
			EB2[i].y += 10.0f;
			EB2[i].x += 1.5f;
			DrawGraph(EB2[i].x, EB2[i].y, EB2[i].g_handle, true);
		}
		count++;
	}
	
	if (EB2->y > 500) {
		DeleteGraph(EB2->g_handle);
	}
	
}

void PlayerEnemyManager::Rotate()
{

}

void PlayerEnemyManager::Enemy_Shooting_H()
{
	int count = 1;
	int atanx = 0;
	int atany[12];
	int atan [12];
	
	if (en2.y < 0 || en2.visible == false)
	{
		EB2->visible = false;
		DeleteGraph(EB1->g_handle);
	}
	if (EB1->count > 9) 
	{
		for (int i = 0; i < 12; i++) {
			if (EB1[i].visible == false) {
				atan[i] = EB1->angle[i];
				atany[i] = EB1->angle[i];
				EB1[i].x = en2.x;
				EB1[i].y = en2.y;
				EB1[i].visible = true;
				
			}
		}
		for (int i = 0; i < 500; i++) {
			if (EB1[i].visible)
			{
		
				EB1[i].y += sin(atany[i]) * 3;
				EB1[i].x += cos(atan[i]) * 3;
				DrawGraph(EB1[i].x - 10, EB1[i].y, EB1[i].g_handle, true);
			}

		}

	}
	
	if (EB1->y > 500) {
		DeleteGraph(EB1->g_handle);
	}

	EB1->count++;
}

void PlayerEnemyManager::Enemy_Shooting_M()
{
	int shotX, shotY;
	int playerX, playerY;
	double enemysx = 0, enemysy = 0, shot_x = 0, shot_y = 0, enemyshotx = 0, enemyshoty = 0, sb = 0, sbx = 0, sby = 0;
	int count = 0;


	GetGraphSize(EB->g_handle, &shotX, &shotY);
	GetGraphSize(player.g_handle, &playerX, &playerY);

	static int starttime = 0;

	if (starttime == 0) {
		starttime = GetNowCount();
	}
	else {
		int currentTime = GetNowCount();
		if (currentTime - starttime >= 1000)
		{



			for (int i = 0; i < 1; i++)
			{
				if (EB1[i].visible == 0)
				{
					EB1[i].x = en1.x;
					EB1[i].y = en1.y;



					EB1[i].visible = 1;
					break;
				}
			}
			for (int i = 0; i < 1; i++) {
				if (EB1[i].visible == 1)
				{
					enemysx = en1.x;
					enemysy = en1.y;
					shot_x = player.x;
					shot_y = player.y;
					enemyshotx = shot_x - enemysx;
					enemyshoty = shot_y - enemysy;

					sb = sqrt(enemyshotx * enemyshotx + enemyshoty * enemyshoty);

					sbx = enemyshotx / sb * 3;
					sby = enemyshoty / sb * 3;
					EB1[i].x += sbx;
					EB1[i].y += sby;

					if (EB1[i].y > 500 || EB1[i].y < 0)
					{
						EB1[i].visible = 0;

					}
				}

				DrawGraph(EB1[i].x + 10, EB1[i].y, EB1[i].g_handle, true);
				DrawGraph(EB1[i].x - 40, EB1[i].y, EB1[i].g_handle, true);
				DrawGraph(EB1[i].x + 60, EB1[i].y, EB1[i].g_handle, true);


			}

			if (en1.y < 0 || en1.visible == false)
			{
				EB1->visible = false;
				DeleteGraph(EB1->g_handle);
			}
		}
	}
}

void PlayerEnemyManager::Boss_Shooting()
{
	int count = 1;
	
	if (Bos.y < 0 || Bos.visible== false)
	{
		EB2->visible = false;
		DeleteGraph(EB2->g_handle);
	}

	for (int i = 0; i < 1; i++) {
		if (EB2[i].visible == false) {
			EB2[i].x = Bos.x;
			EB2[i].y = Bos.y;
			EB2[i].visible = true;
		}
	}
	for (int i = 0; i < 1; i++) {
		if (EB2[i].visible)
		{
			EB2[i].y += 10.0f;
			EB2[i].x += 1.5f;
			DrawGraph(EB2[i].x, EB2[i].y, EB2[i].g_handle, true);
		}
		count++;
	}

	if (EB2->y > 300) {
		DeleteGraph(EB2->g_handle);
	}



}

void PlayerEnemyManager::EnemyAppearPattern()
{

	
		switch (pattern) {
		case 0:
			Enemy1();
			Enemy_Shooting();
			break;
		case 1:
			Enemy2();
			Enemy_Shooting_H();
			break;
		case 2:
			Enemy3();
			break;
		case 3:
			Enemy4();
			break;
		case 4:
			Enemy5();
			
			break;
		case 5:
			Boss();
			Boss_Shooting();
			break;
		default:
			break;
		}
	
	
		
}



