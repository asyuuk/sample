#include "BackGrounds.h"
#include"typedefclass.h"
#include<DxLib.h>

BackGround Back;
void BackGrounds ::BackGroundImages ()
{
	
	Back.g_handle = LoadGraph("E:\\Aseprite\\Background Grid.png");

}

void BackGrounds::BackGround1()
{
	
	Back.y += 2;
	DrawGraph(Back.x, Back.y, Back.g_handle, TRUE);
	
}

