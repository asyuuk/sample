
#include "Moving.h"
#include "typedefclass.h"
#include <DxLib.h>
#include<math.h>


Player player;
SHOT shot[Shot];
Enemy1 en1;
void Moving::LoadImageCharacter()
{
	player.g_handle = LoadGraph("E:\\Aseprite\\hakureireimu_0001_7.png");
	for (int i = 0; i < Shot; i++)	shot[i].g_handle = LoadGraph("E:\\Aseprite\\bullet0001.png");
}


void Moving::PlayerMove()
{
	//キー入力初期化
	int key[256];
	char tmpkey[256];
	
	GetHitKeyStateAll(tmpkey);
	for (int i = 0; i < 256; i++) {
		if (tmpkey[i] != 0) {
			key[i] ++;
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
	}
	else if (key[KEY_INPUT_S] != 0) {
		player.y += 10;
		if (player.y > 400) {
			player.y = 400;
		}
	}
	else if (key[KEY_INPUT_D] != 0) {
		player.x += 10;
		if (player.x > 250) {
			player.x = 250;
		}
	}
	else if (key[KEY_INPUT_A] != 0)
	{
		player.x -= 10;
		if (player.x < 50) {
			player.x = 50;
		}
	}
	DrawGraph(player.x, player.y, player.g_handle, TRUE);

}


void Moving::BulletShootPlayer()
{
	
	//スペースが押されたときの初期化
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		for (int i = 0; i < Shot; i++)
		{
			if (shot[i].visible == 0)
			{
				shot[i].x = player.x + 25;
				shot[i].y = player.y;
				shot[i].visible = 1;
				break;
			}
		}
	}
	for (int i = 0; i < Shot; i++) {
		if (shot[i].visible == 1)
		{
			shot[i].y -= 70;
			if (shot[i].y < -200)
			{
				shot[i].visible = 0;

			}
		}
		DrawGraph(shot[i].x, shot[i].y, shot[i].g_handle, true);
	}
	

}

void Moving::attachshot()
{
	int shotx, shoty, en1x, en1y;
	GetGraphSize(shot->g_handle, &shotx, &shoty);
	GetGraphSize(en1.g_handle, &en1x, &en1y);

	for (int i = 0; i < Shot; i++) {
		if (shot[i].visible == 1) {
			if (((shot[i].x > en1.x && shot[i].x < en1.x + en1x) || (en1.x > shot[i].x && en1.x < shot[i].x + shotx)) && ((shot[i].y > en1.y && shot[i].y < en1.y + en1y) || (en1.y > shot[i].y && en1.y < shot[i].y + shoty)))
			{
				en1.visible = false;
			}
		}
	}
}