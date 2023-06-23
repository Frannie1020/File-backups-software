#include <iostream>
#include <conio.h>
#include "Pack.h"
#include "Unpack.h"
using namespace std;

int main()
{
	Pack kPack;  //打包
	Unpack kUnpack;  //解包

	char ch;
	while (1)
	{
		system("cls");
		cout << "输入1、打包" << endl;
		cout << "输入2、解包" << endl;
		cout << "输入0、退出" << endl << endl;
		cout << "请选择你想要的功能" << endl << endl;
		ch = _getch();
		switch (ch)
		{
		case '1': //打包
			if (kPack.Init())
				kPack.PackFile();
			break;
		case '2': //解包
			if (kUnpack.Init())
				kUnpack.UnpackFile();
			break;
		case '0': //退出
			return 0;
		default:
			cout << "打包成功" << endl;
		}
		system("pause");
	}
	return 0;
}