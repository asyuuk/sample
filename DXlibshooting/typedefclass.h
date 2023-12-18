
#pragma once
#define Shot 10
#define Ecount 4

typedef struct Enemy1
{
	bool visible=true;
	int x=100;
	int y=0;
	int x_1 = 10;
	int x_2 = 190;
	int y_1 = 0;
	int y_2 = 0;
	int g_handle;
	int g_handle1;
	int g_handle2;
	int count=0;
	int pattern = 0;
	bool visible1 = true;
	bool visible2 = true;
	bool visible3 = true;
	int life1=1;
	int life2=1;
	int life3=1;
};

typedef struct Enemy2
{
	bool visible=true;
	int x = 300;
	int y = 0;
	int x_1 = 200;
	int y_1 = 0;
	int x_2 = 100;
	int y_2 = 0;
	int g_handle;
	int g_handle1;
	int g_handle2;
	int angle;
	int pattern = 1;
	int count = 0;
	bool visible1 = true;
	bool visible2 = true;
	int life = 1;
	int life1 = 1;
};

typedef struct Enemy3
{
	bool visible=true;
	int x = 150;
	int y;
	int g_handle;
	int pattern = 2;
	int count = 0;
	int life = 1;
};

typedef struct Enemy4
{
	
	bool visible;
	bool visible1=true;
	int x=0;
	int y=0;
	int radius = 0;
	int centerX = 400;
	int centerY = 0;
	int g_handle;
	int g_handle1;
	int pattern = 3;
	int count = 0;
	int life = 10;
};
typedef struct Enemy5
{

	bool visible;
	int x = 0;
	int y = 0;
	int radius = 0;
	int centerX = 400;
	int centerY = 0;
	int g_handle;
	int g_handle1;
	int pattern = 3;
	int count = 0;
};
typedef struct Enemy6
{

	bool visible;
	int x = 0;
	int y = 0;
	int radius = 0;
	int centerX = 400;
	int centerY = 0;
	int g_handle;
	int g_handle1;
	int pattern = 3;
	int count = 0;
};

typedef struct Boss
{
	bool visible=true;
	int x=100;
	int y=0;
	int life = 200;
	int g_handle;
	int life1;
	int life2;
	int life3;
	int maxlife = 100;
	int radius;
	int Angle;
	int centerX;
	int centerY;
	int count = 0;
	bool bulletvisible = false;
};

typedef struct BackGround
{
	bool visible;
	int x=0;
	int y=0;
	int g_handle;
};

typedef struct SHOT//弾の構造体、視覚、ｘ、ｙ及び高さ、幅の一つ一つの情報体
{
	bool visible=false;
	int x=-100;
	int y;
	int g_handle;
	int width, height;
};
typedef struct Player
{
	bool visible = true;
	int x=100;
	int y=400;
	int g_handle;
	int life=100;
};

typedef struct Enemy_Bullet // 敵の弾
{
	bool visible = false;
	int x=1000;
	int y;
	int g_handle;
	int shot = false;
	int count = 0;
	int faze = 0;
};

typedef struct Enemy_Bullet1//ホーミング
{
	bool visible = false;
	int x;
	int y;
	int g_handle;
	int count = 0;
	int angle[12]= { 270, 240, 300, 210, 330, 180, 0, 150, 30, 120, 60, 90 };
};

typedef struct Enemy_Bullet2//ホーミング
{
	bool visible = false;
	float x;
	float y;
	int g_handle;
	int angle=0;
};

//当たり判定
typedef struct Attack_area
{
	bool visible = true;
	int character_x;
	int character_y;
	int character_g_handle;

};

//爆発
typedef struct Bomb
{
	bool visible=false;
	int count = 0;
};

typedef struct Scene
{
	int scenecount = 1;
};

typedef struct title
{
	int character;

};