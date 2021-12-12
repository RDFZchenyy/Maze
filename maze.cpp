//头文件 
#include<bits/stdc++.h>
#include<windows.h>
#include<ctime>
#include<conio.h>

//标准名空间 
using namespace std;

//全局变量
char m[15][25];
bool win=false;
clock_t start,finish,last;
char keyboard;

//玩家位置
struct user_place{
	int x;//0~24
	int y;//0~14
}place,end;

void print_map(char map[15][25],user_place user){
	system("cls");
	for(int i=0;i<15;i++){
		for(int j=0;j<25;j++){
			if(user.y==i&&user.x==j){
				printf("O "); 
			}else{
				if(map[i][j]=='1'){
					printf("■");
				}
				if(map[i][j]=='2'){
					printf("  ");
				}
				if(map[i][j]=='3'||map[i][j]=='4'){
					printf("==");
				}
			} 
		}
		printf("\n");
	}
	return;
}

int main(){
	freopen("map.txt","r",stdin);
	for(int i=0;i<15;i++){
		for(int j=0;j<25;j++){
			cin>>m[i][j];
			if(m[i][j]=='3'){
				place.x=j;
				place.y=i;
			}
			if(m[i][j]=='4'){
				end.x=j;
				end.y=i;
			}
		}
	}
	printf("按任意键开始游戏\n");
	while(!kbhit());
	print_map(m,place);	
	start=clock();	
	while(!win){
		if(kbhit()){
			keyboard=getch();
		}
		if(keyboard=='w'&&place.y!=0){
			if(m[place.y-1][place.x]!='1'){
				place.y--;
				print_map(m,place);
			}
		}
		if(keyboard=='a'&&place.x!=0){
			if(m[place.y][place.x-1]!='1'){
				place.x--;
				print_map(m,place);
			}
		}
		if(keyboard=='s'&&place.y!=14){
			if(m[place.y+1][place.x]!='1'){
				place.y++;
				print_map(m,place);
			}
		}
		if(keyboard=='d'&&place.x!=24){
			if(m[place.y][place.x+1]!='1'){
				place.x++;
				print_map(m,place);
			}
		}
		if(end.x==place.x&&end.y==place.y){
			win=true;
		}
		keyboard==' ';
	}
	finish=clock();
	last=finish-start;
	system("cls");
	cout<<"time:"<<last*1.0/1000;
	Sleep(100000);
	
	return 0;
}
