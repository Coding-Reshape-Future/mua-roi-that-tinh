#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<Windows.h>
#include<windows.h>
#include<mmsystem.h>
#include<time.h>

void gotoxy(int x,int y){
	HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD g = {(short)x,(short)y};
	SetConsoleCursorPosition(h,g);
}
void HideCur(bool hide) {
	HANDLE x = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO y;
    y.dwSize = 10;
    y.bVisible = hide;
    SetConsoleCursorInfo(x, &y);
}
void textcolor(int x){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,x);
}
class rain{
	int x;
	int y;
	public:
		rain();
		void fall();
		int getx();
		int gety();
};
rain::rain(){
	x = rand()%170 + 1;
	y = rand()%35 + 1;
}
int rain::getx(){
	return x;
}
int rain::gety(){
	return y;
}
void rain::fall(){
	if(y == 35){
		x = rand()%170 + 1;
		y = rand()%35 + 1;
	}
	else y++;
}

void intro(){
	gotoxy(30, 37);textcolor(13);printf("LTP");
	gotoxy(25, 38);textcolor(13);printf("Send with love <3");
	system("cls");
	for(int i=3; i>0; i--){
		gotoxy(77, 20);
		printf("%d", i);
		Sleep(1000);
	}
	gotoxy(75, 15);
	printf("READY!");
	Sleep(1000);
	system("cls");
}
void print(int x, int y, int time, char *a){
	int n = strlen(a);
	int rem = time/n;
	gotoxy(x,y);textcolor(12);
	for(int i=0; i<strlen(a); i++){
		printf("%c", a[i]);
		Sleep(rem);
	}
	Sleep(500);
}
void rainning(rain a[], int n, int time){
	for(int i=0; i<n; i++){
		gotoxy(a[i].getx(), a[i].gety());
		textcolor(3);printf("|");
	} 
	Sleep(time);
	for(int i=0; i<n; i++){
		gotoxy(a[i].getx(), a[i].gety());
		printf(" ");
		a[i].fall();
	}
}
int main(){
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	HideCur(false);
	int n = 100, time = 40, sl = 1;
	rain a[n];
	PlaySound(TEXT("nhinvaomua.wav"), NULL, SND_ASYNC);
	gotoxy(30, 37);textcolor(13);printf("LTP");
	gotoxy(25, 38);textcolor(13);printf("Send with love <3");
	while(sl < 50){ //time to ready
		sl++;
		rainning(a,n,time);
	}
	intro();
	gotoxy(30, 37);textcolor(13);printf("LTP");
	gotoxy(25, 38);textcolor(13);printf("Send with love <3");
	HideCur(true);
	textcolor(12);
	print(37, 6, 4000, "Minh chia tay nhau khi chua bat dau...");
	print(37, 8, 4000, "Minh chia tay nhau cho voi don dau...");
	print(33, 10, 6000, "Noi nho anh se giu lai, vao noi con mua cat giau");
	print(37, 12, 4000, "Minh chia tay nhau khi chua bat dau...");
	print(39, 14, 3000, "Tinh yeu co le la mot phep mau");
	print(35, 16, 6000, "Du co don dau long van muon yeu dam sau <3");
	Sleep(1000);
	sl = 1;
	while(sl < 180){
		if(sl < 10){
			textcolor(12);
			gotoxy(37, 6);textcolor(12);printf("Minh chia tay nhau khi chua bat dau...");
			gotoxy(37, 8);textcolor(12);printf("Minh chia tay nhau cho voi don dau...");
			gotoxy(33, 10);textcolor(12);printf("Noi nho anh se giu lai, vao noi con mua cat giau");
			gotoxy(37, 12);textcolor(12);printf("Minh chia tay nhau khi chua bat dau...");
			gotoxy(39, 14);textcolor(12);printf("Tinh yeu co le la mot phep mau");
			gotoxy(35, 16);textcolor(12);printf("Du co don dau long van muon yeu dam sau <3");
		}
		sl++;
		rainning(a,n,time);
	}
	textcolor(12); print(35, 20, 6000, "Du co don dau, long van muon yeu em dam sau...");
	Sleep(15000);
	return 0;
}

