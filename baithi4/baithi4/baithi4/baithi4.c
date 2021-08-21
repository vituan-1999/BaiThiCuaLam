#include<stdio.h>
#include<Windows.h>
HANDLE readPipe;
HANDLE writePipe;

WINAPI Submain(LPVOID a)
{
	while (1)
	{
		int x = 0;
		int y = 0;// doc note giup em anh oi 
		ReadFile(readPipe, &x, sizeof(x), &y, NULL); // ly do dung pipe: mac du cai de khong su dung nhung dung no dong bo
		printf("Xin chao\r\n");
		Sleep(1000);
	}
}
void main()
{
	CreatePipe(&readPipe, &writePipe, NULL, 128);
	HANDLE subthread = CreateThread(NULL, 128, Submain, NULL, 0, NULL);
	int cnt = 0;
	DWORD written = 0;
	while (1)
	{
		printf("Say hello\r\n");
		WriteFile(writePipe, &cnt, sizeof(cnt), &written, NULL);
		Sleep(1000);
	}
}
// neu em dung cah duoi no khong co xen ke duoc o mot so giay dau

/*
#include<stdio.h>
#include<Windows.h>
WINAPI subMain(LPVOID lpThreadParameter)	
{
	while (1)
	{
		printf("Xin chao\n");
		Sleep(2000);
	}
}

void main()
{
	CreateThread(NULL, 128, subMain, NULL, 0, NULL);
	while (1)
	{
		printf("Say hello\n");
		Sleep(1000);
	}
}
*/