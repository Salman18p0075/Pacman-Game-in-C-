#include <iostream>    
#include <stdio.h>
#include <windows.h>   
#include <string>
#include <vector>     
#include "Color.h"     //header file macros
#include "mmsystem.h"  //lib for sound (-lwinmm)
#include<fstream>
using namespace std;

char tmp_map[32][31];
char map[32][30+ 1] = {
    "1555555555555555555555555552",
    "6            ^^            6",
    "6 !%%@ !%%%@ ^^ !%%%@ !%%@ 6",
   	"6 ^  ^ ^   ^ ^^ ^   ^ ^  ^ 6",
    "6 #%%$ #%%%$ #$ #%%%$ #%%$ 6",
    "6                          6",
    "6 !%%@ !@ !%%%%%%@ !@ !%%@ 6",
    "6 #%%$ ^^ #%%@!%%$ ^^ #%%$ 6",
    "6      ^^    ^^    ^^      6",
    "355552 ^#%%@ ^^ !%%$^ 155554",
    "     6 ^!%%$ #$ #%%@^ 6     ",
    "     6 ^^          ^^ 6     ",
    "     6 ^^ 155  552 ^^ 6     ",
    "555554 #$ 6      6 #$ 355555",
    "          6      6          ",
    "555552 !@ 6      6 !@ 155555",
    "     6 ^^ 35555554 ^^ 6     ",
    "     6 ^^          ^^ 6     ",
    "     6 ^^ !%%%%%%@ ^^ 6     ",
    "155554 #$ #%%@!%%$ #$ 355552",
    "6            ^^            6",
    "6 !%%@ !%%%@ ^^ !%%%@ !%%@ 6",
    "6 #%@^ #%%%$ #$ #%%%$ ^!%$ 6",
    "6   ^^                ^^   6",
    "6%@ ^^ !@ !%%%%%%@ !@ ^^ !%6",
    "6%$ #$ ^^ #%%@!%%$ ^^ #$ #%6",
    "6      ^^    ^^    ^^      6",
    "6 !%%%%$#%%@ ^^ !%%$#%%%%@ 6",
    "6 #%%%%%%%%$ #$ #%%%%%%%%$ 6",
    "6                          6",
    "3555555555555555555555555554"
};
	


class Pages{
	protected:
		string page[5]={
			"@@@@@@@  @@@@@@@  @@@@@@  @@@@@@@@@@@  @@@@@@@  @@@@@@@@",
			"||   ||  ||   ||  ||      ||   ||  ||  ||   ||  ||    ||",
			"||###||  ||###||  ||      ||   ||  ||  ||###||  ||    ||",
			"||       ||   ||  ||      ||   ||  ||  ||   ||  ||    ||",
			"||       ||   ||  ||####  ||   ||  ||  ||   ||  ||    ||"
			};

string lpage[5]={
			"@@@@@@  @@@@@@@  @@@@@@@@@@@  @@@@@@    @@@@@@  ||     ||  @@@@@@  @@@@@@@",
			"||      ||   ||  ||   ||  ||  ||        ||  ||  ||     ||  ||      ||   ||",
			"|| ###  ||###||  ||   ||  ||  ||####    ||  ||  ||     ||  ||####  ||@@@@@",
			"||  ||  ||   ||  ||   ||  ||  ||        ||  ||    || ||    ||      ||   ||",
			"||##||  ||   ||  ||   ||  ||  ||####    ||##||      @      ||####  ||   ||" 
			};
			
	public:
		virtual void Show_Page()=0;
};
class Front_p : public Pages{				
	public:
		void Set_Front_Page();
		void Show_Page();
};

class Last_p: public Pages{
	public:
		void Set_Last_Page();
		void Show_Page();
};

void Front_p::Set_Front_Page(){
	for(int i=0; i<5; i++){
		for(int j=0; j<58 ;j++){
			if(page[i][j]=='#'){
				page[i][j]=char(220);
			}else if(page[i][j]=='|'){
				page[i][j]=char(219);
			}else if(page[i][j]=='@'){
				page[i][j]=char(223);
			}
		}
	}
}

void Front_p::Show_Page(){
	Set_Front_Page();
	cout<<endl;
	cout<<endl;
	cout<<endl;
	SetColor(20);
	for(int i=0; i<5; i++){
		cout<<"                 "<<page[i]<<endl;
	}
	
	cout<<endl;
	cout<<"                               SEMESTER PROJECT BY AHMAD AND SALMAN"<<endl;
	SetColor(29);
	cout<<"                     "<<'<'<<" ";
	SetColor(31);
	cout<<"is your Pacman and ";
	SetColor(20);
	cout<<'O'<<" ";
	SetColor(31);
	cout<<"is your Enemy"<<endl;
	cout<<"                     ENTER THE MODE OF THE GAME"<<endl;
	cout<<"                     Press H for Hard mode\n                     N for Normal mode\n                     E for Easy mode\n\n                     Input : ";
	PlaySound(TEXT("front.wav"),NULL,SND_SYNC);
}

void Last_p::Set_Last_Page(){
	for(int i=0; i<5; i++){
		for(int j=0; j<79 ;j++){
			if(lpage[i][j]=='#'){
				lpage[i][j]=char(220);
			}else if(lpage[i][j]=='|'){
				lpage[i][j]=char(219);
			}else if(lpage[i][j]=='@'){
				lpage[i][j]=char(223);
			}
		}
	}
}

void Last_p::Show_Page(){
	Set_Last_Page();
	SetColor(29);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	for(int i=0 ; i < 5; i++){
		cout<<"                                           "<<lpage[i]<<endl;
	}
	cout<<endl;
	}
	
class Map{
	public:
		void setmap(char map[32][31]);
		void showmap(char map[32][31]);
};


void Map::setmap(char map[32][31]){
	for(int i=0; i<32; i++){
		for(int j=0; j<29+1 ;j++){
			if (map[i][j] == '1') {
                map[i][j] = char(201);
            }else if(map[i][j]=='I'){
            	SetColor(20);
			}
            else if (map[i][j] == '2') {
                map[i][j] = char(187);
            }
            else if (map[i][j] == '3') {
                map[i][j] = char(200);
            }
            else if (map[i][j] == '4') {
                map[i][j] = char(188);
            }
            else if (map[i][j] == '5') {
                map[i][j] = char(205);
            }
            else if (map[i][j] == '6') {
                map[i][j] = char(186);
            }
            else if (map[i][j] == '!') {
                map[i][j] = char(218);
            }
            else if (map[i][j] == '@') {
                map[i][j] = char(191);
            }
            else if (map[i][j] == '#') {
                map[i][j] = char(192);
            }
            else if (map[i][j] == '$') {
                map[i][j] = char(217);
            }
            else if (map[i][j] == '%') {
                map[i][j] = char(196);
            }
            else if (map[i][j] == '^') {
                map[i][j] = char(179);
            }else if(map[i][j]=='.'){
            	map[i][j]=' ';
			}
        }
		}
	}


void Map::showmap(char map[32][31]){
	setmap(map);
	SetColor(1);
	for(int i=0; i<30+1; i++){
		cout<<map[i]<<endl;
	}
}


void gotoxy( int x, int y ){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}

// nodes for searching
struct walk {
	short walk_count;
	short x;
	short y;
	short back;
};

struct target {
	short x;
	short y;
};

vector<target> walk_queue;
vector<walk> BFSArray;

void AddArray( int x, int y, int wc , int back ){
	if( tmp_map[y][x] == ' ' || tmp_map[y][x] == '.' ){
		tmp_map[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		BFSArray.push_back( tmp );
	}
}

void FindPath( int sx, int sy, int x, int y ){
	memcpy( tmp_map, map, sizeof(map) );   // copying of address from map to temp_map for ghost
	walk tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	BFSArray.push_back( tmp );

	int i = 0;
	while( i < BFSArray.size() ){
		if( BFSArray[i].x == x   &&   BFSArray[i].y == y ){
			target tmp2;
			
			while( BFSArray[i].walk_count != 0 ){
				tmp2.x = BFSArray[i].x;
				tmp2.y = BFSArray[i].y;
				walk_queue.push_back( tmp2 );

				 i = BFSArray[i].back;
			}

		break;	
		} 

		AddArray( BFSArray[i].x+1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x-1, BFSArray[i].y, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y+1, BFSArray[i].walk_count+1, i );
		AddArray( BFSArray[i].x, BFSArray[i].y-1, BFSArray[i].walk_count+1, i );

	i++;
		
}
	BFSArray.clear();

}

void PacmanGame(){
	int lives = 3;
	char pacman = '?' ;
	bool running = true;
	Pages *p1,*p2; 
	p1=new Front_p;
	p2=new Last_p;
	ifstream fin;
	ofstream fout;
	int Highscore; 
	fin.open("HighScore.txt");
	fin>>Highscore;
	fin.close();
	int x = 1; // hero x
	int y = 14; // hero y
	int old_x;
	int old_y;

	int ex = 12;
	int ey = 14;


	int pts = 0;
	p1->Show_Page();
	char diffi;
	int speedmod = 3;    //default speed easy

	cin >> diffi;

	if( diffi == 'N' ){
		speedmod = 2;
	}else if( diffi == 'H' ){
		speedmod = 1;
	}

	system("cls");
	Map m;
    m.showmap(map);
    SetColor(30);
	gotoxy( x, y ); 
	cout << '?';

	int frame = 0;

	FindPath( ex,ey,x,y );

	while( running ){
		gotoxy( x, y ); 
		cout << " ";

		old_x = x;
		old_y = y;

		if ( GetAsyncKeyState( VK_UP ) ){
			if( map[y-1][x] == '.' ){ y--; pts++; } else
			if( map[y-1][x] == ' ' ) y--;
			pacman='?';
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( map[y+1][x] == '.' ){ y++; pts++; } else
			if( map[y+1][x] == ' ' ) y++;
			pacman='?';
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( map[y][x-1] == '.' ){
			 x--; pts++; }
			  else if( map[y][x-1] == ' ' ){x--;}
			  else if(y==14 &&  x == 0)
			  {
			  	x = 27;
			  }
			  pacman='?';
			  }
		
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( map[y][x+1] == '.' ){ x++; pts++; } else
			if( map[y][x+1] == ' ' ){x++;}
			else if(map[y][x+1] == map[14][28])x=1;
			pacman='?';
		}

		if( old_x != x || old_y != y ){
			FindPath( ex,ey,x,y );
		}

		gotoxy( x,y );
		SetColor(29); 
		cout << pacman;

		map[ey][ex] = '.';
		gotoxy( ex, ey );
		SetColor(10); 
		cout << ".";

		if( frame%speedmod == 0 && walk_queue.size() != 0 ){
			ex = walk_queue.back().x;
			ey = walk_queue.back().y;
			walk_queue.pop_back();
		}

		gotoxy( ex, ey );
		SetColor(20);
		char ghost='O';
		cout << ghost;

		if( ex == x && ey == y ){
			lives--;
			if(lives==0){
				PlaySound(TEXT("death.wav"),NULL,SND_SYNC);
				break;
			}
			PlaySound(TEXT("eat.wav"),NULL,SND_SYNC);
			x=1;
			y=14;
		}

		gotoxy( 2, 31 );
		SetColor(30); 
		cout <<"Score:"<<pts;
		Sleep( 100 );
		frame++;
		gotoxy(12,31);
		cout<<"Lives Remaining : "<<lives<<endl;
		gotoxy(29,14);
		cout<<"High Score : "<<Highscore<<endl;
}

	system("cls");
	
	p2->Show_Page();
	cout<<endl;
	cout<<endl;
	cout<<endl;
	if(Highscore<=pts){
		cout<<"		New High Score : "<<pts<<endl;
		fout.open("HighScore.txt");
		fout<<pts;
		fout.close();
	}else{
	cout<<"             YOUR TOTAL SCORE IS : "<<pts<<endl;
	cout<<"             High Score "<<Highscore<<endl;
	}
	delete p1;
	delete p2;
	cin.get();
	cin.get();

}
// Game call Here
int main()
{
   PacmanGame();

	return 0;
}

