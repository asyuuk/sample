#include "Enemys.h"
#include "typedefclass.h"
#include<DxLib.h>
#include<math.h>

#define M_PI 3.141592653589794338

Enemy1 en1;
Enemy2 en2;
Enemy3 en3;

void Enemys::LoadImageEnemys()
{
	en1.g_handle = LoadGraph("E:\\Aseprite\\hakureireimu_0001_7.png");
	en2.g_handle = LoadGraph("E:\\Aseprite\\hakureireimu_0001_7.png");
	en3.g_handle = LoadGraph("E:\\Aseprite\\hakureireimu_0001_7.png");
}

void Enemys::EnemyMove1()
{

	SHOT shot[Shot];
	Player player;
	en1.y += 2;

	
	if(en1.visible==true)
	DrawGraph(en1.x, en1.y, en1.g_handle, true);
	
}

void Enemys::EnemyMove2()
{
	static int starttime = 0;
	en2.y += 10;
	if (en2.y > 150)
	{
		en2.y = 150;
		if (starttime == 0) {
			starttime = GetNowCount();
		}
		else {
			int currentTime = GetNowCount();
			if (currentTime - starttime >= 1000) { // 5000ミリ秒（5秒）待つ
				en2.x -= sin(M_PI * (135) / 180) * 2;
			}
		}
	}
	if(en2.visible==true)
	DrawGraph(en2.x, en2.y, en2.g_handle, TRUE);

}

void Enemys::EnemyMove3()
{
	static int starttime = 0;
	bool bulletFlag3 = true;

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
	if(bulletFlag3==true)
	DrawGraph(en3.x, en3.y, en3.g_handle, TRUE);
}

