#include "firstscene.h"
#include"typedefclass.h"
#include <DxLib.h>


void firstscene::title()
{
	LPCSTR char_number = "E:\\Fonts\\PixelMplus10-Regular.ttf";
	if (AddFontResource(char_number) > 0) {
		PostMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}

	SetFontSize(20);	// 見やすさのため、フォントサイズを大きく
	ChangeFont("PixelMplus10", DX_CHARSET_DEFAULT);
	DrawFormatString(500, 200, GetColor(255, 255, 255), "タイトル（仮）");
	DrawString(350, 300, "kari", GetColor(255, 255, 255));
	DrawFormatString(500, 350, GetColor(255, 255, 255), "press enter");


}

