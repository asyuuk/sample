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
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}

	SetFontSize(20);	// ���₷���̂��߁A�t�H���g�T�C�Y��傫��
	ChangeFont("PixelMplus10", DX_CHARSET_DEFAULT);
	DrawFormatString(500, 200, GetColor(255, 255, 255), "�^�C�g���i���j");
	DrawString(350, 300, "kari", GetColor(255, 255, 255));
	DrawFormatString(500, 350, GetColor(255, 255, 255), "press enter");


}

