//Phat 1
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
//Phuc 2
void TextColor(int x)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
};
//Sa  3
enum TT{RIGHT, LEFT, UP, DOWN};
struct Toado{
    int x, y;
};
struct Snake{
    Toado dot[500];
    int n;
    TT tt;
};
struct HQ{
    Toado td;
};
//Anh 4
void playgame(int &thoat, char name[], int &level, Snake &luusnake, char dname[]);
void khungplay();
void help(int &thoat, char name[], int &level, Snake &luusnake, char dname[]);
void about(int &thoat, char name[], int &level, Snake &luusnake, char dname[]);
void Score(int &thoat, char name[], int &level, Snake &luusnake, char dname[]);
void khungngoai();
void khoitao(Snake &snake, HQ &hq);
void hienthi(Snake &snake, HQ &hq);
void dieukhien(Snake &snake,int &cam);
void Random(Snake &snake, HQ &hq);
void thuagame(Snake snake, int &thua);
void Time();
void vaogame(char name[], int &level,  Snake &luusnake, char dname[]);
void docfile(Snake &luusnake, char dname[]);
void ghifile(Snake snake, char name[]);
void Score(Snake &luusnake, char dname[]);
void gameover(char name[], Snake snake, Snake luusnake);
void tamdung();


//Phuc 5
int main()
{
    resizeConsole(700,550);
    int thua=1, cam=0, thoat = 0, level;
    char name[30], dname[30] = "No name";
    Snake snake, luusnake;
    luusnake.n = 0;
    HQ hq;
    docfile(luusnake, dname);
    playgame(thoat, name, level, luusnake, dname);
    system("cls");
    fflush(stdin);
    if(thoat==0)
    {
        do{
            thua=1; cam=0;
            khungngoai();
            khoitao(snake, hq);
            do{
                hienthi(snake, hq);
                dieukhien(snake, cam);
                Random(snake, hq);
                thuagame(snake, thua);
                Sleep(level);
              }while(thua != 0);
              gameover(name, snake,luusnake);
              system("cls");
              if(snake.n > luusnake.n)
               {
                    ghifile(snake, name);
                    docfile(luusnake, dname);
                }
              playgame(thoat, name, level, luusnake, dname);
          }while(thoat == 0);
      }
}
//Anh 6
void khungngoai()
{
            for(int i = 5; i<75; i++)
    {
        for(int j = 2; j<28; j++)
        {
            gotoxy(i, j+6); TextColor(112); printf(" ");
        }
        printf("\n");
    }
        TextColor(11);
    for(int i = 0; i<=78; i++)
    {
        gotoxy(i, 0); printf("%c", 205);
        Sleep(1);
    }
        for(int i = 0; i<=78; i++)
    {
        gotoxy(i, 40); printf("%c", 205);
        Sleep(1);
    }
    for(int i = 0; i<=40; i++)
    {
        gotoxy(0, i); printf("%c", 186);
        Sleep(1);
    }
    for(int i = 0; i<=40; i++)
    {
        gotoxy(79, i); printf("%c", 186);
        Sleep(1);
    }
    TextColor(14);
    gotoxy(0,0); printf("%c", 201);
    gotoxy(0,40); printf("%c", 200);
    gotoxy(79,0); printf("%c", 187);
    gotoxy(79,40); printf("%c", 188);

    TextColor(11);
    for(int i = 2; i<=77; i++)
    {
        gotoxy(i, 1); printf("%c", 205);
        Sleep(1);
    }
        for(int i = 1; i<=77; i++)
    {
        gotoxy(i, 41); printf("%c", 205);
        Sleep(1);
    }
    for(int i = 1; i<=41; i++)
    {
        gotoxy(1, i); printf("%c", 186);
        Sleep(1);
    }
    for(int i = 1; i<=41; i++)
    {
        gotoxy(78, i); printf("%c", 186);
        Sleep(1);
    }
    TextColor(14);
    gotoxy(1,1); printf("%c", 201);
    gotoxy(1,41); printf("%c", 200);
    gotoxy(78,1); printf("%c", 187);
    gotoxy(78,41); printf("%c", 188);


    TextColor(6);
    for(int i = 4; i<=75; i++)
    {
        gotoxy(i, 7); printf("%c", 220);
        Sleep(1);
    }
        for(int i = 4; i<=75; i++)
    {
        gotoxy(i, 34); printf("%c", 223);
        Sleep(1);
    }
    for(int i = 1; i<=26; i++)
    {
        gotoxy(4, i+7); printf("%c", 186);
        Sleep(1);
    }
    for(int i = 1; i<=26; i++)
    {
        gotoxy(75, i+7); printf("%c", 186);
        Sleep(1);
    }
    TextColor(15);
    gotoxy(4,7); printf("%c", 201);
    gotoxy(4,34); printf("%c", 200);
    gotoxy(75,7); printf("%c", 187);
    gotoxy(75,34); printf("%c", 188);


    TextColor (11);
    for(int i = 0; i<15; i++)
    {
        gotoxy(63+i, 4); printf("%c", 205);
    }
    for(int i = 0; i<2; i++)
    {
        gotoxy(63, i+2); printf("%c", 186);
    }
    TextColor(14);
    gotoxy(63, 4); printf("%c", 200);
    gotoxy(65, 2);TextColor(10); printf("Playing Time");
    gotoxy(5, 2);TextColor(10); printf("Lengh");
    TextColor(11);
    for(int i = 0; i<15; i++)
    {
        gotoxy(2+i, 4); printf("%c", 205);
    }
    for(int i = 0; i<2; i++)
    {
        gotoxy(17, i+2); printf("%c", 186);
    }
        for(int i = 0; i<43; i++)
    {
        gotoxy(19+i, 2); printf("_");
    }
    TextColor(14);
    gotoxy(17, 4); printf("%c", 188);
    gotoxy(34, 0); TextColor(160); printf("SNAKE GAME ");
    gotoxy(25,2); TextColor(12); printf("HOPE YOU HAVE FUN WITH OUR GAME!");
    TextColor(4);
        for(int i = 0; i<55; i++)
    {
        gotoxy(13+i, 36); printf("%c", 205);
    }
        for(int i = 0; i<55; i++)
    {
        gotoxy(13+i, 38); printf("%c", 205);
    }
    gotoxy(27, 37); TextColor(4); printf("Team ");
    gotoxy(38, 37); TextColor(3); printf("PPSAL");
    gotoxy(79,41);
}
//Sa 7
void playgame(int &thoat, char name[], int &level, Snake &luusnake, char dname[])
{
    khungplay();
        for(int i = 0; i<40; i++)
    {
         if(i%5 == 0) {
            TextColor(9); gotoxy(20+i, 6); (5);    printf("%c", 220);
           }
           else if(i%5 == 1) {
         TextColor(10);  gotoxy(20+i, 6);    Sleep(5); printf("%c", 220);
           }
            else if(i%5 == 2) {
         TextColor(11);  gotoxy(20+i, 6);   Sleep(5); printf("%c", 220);
           }
            else if(i%5 == 3){
         TextColor(12);   gotoxy(20+i, 6);  Sleep(5);   printf("%c", 220);
           }
            else if(i%5 == 4) {
         TextColor(13);   gotoxy(20+i, 6);   Sleep(5);printf("%c", 220);
           }
    }
        for(int i = 0; i<40; i++)
    {
         if(i%5 == 0) {
            TextColor(9); gotoxy(20+i, 17);   Sleep(5);  printf("%c", 220);
           }
           else if(i%5 == 1) {
         TextColor(10);  gotoxy(20+i, 17);   Sleep(5);  printf("%c", 220);
           }
            else if(i%5 == 2) {
         TextColor(11);  gotoxy(20+i, 17);  Sleep(5);  printf("%c", 220);
           }
            else if(i%5 == 3){
         TextColor(12);   gotoxy(20+i, 17);  Sleep(5);   printf("%c", 220);
           }
            else if(i%5 == 4) {
         TextColor(13);   gotoxy(20+i, 17);   Sleep(5); printf("%c", 220);
           }
     }
    TextColor(202);
            gotoxy(33, 10); printf("%c  Play Game  ", 175);
            TextColor(14);
            gotoxy(33, 11); printf("  Help         ");
            gotoxy(33, 12); printf("  About        ");
            gotoxy(33, 13); printf("  High Score   ");
            gotoxy(33, 14); printf("  Exit         ");
            gotoxy(78,40);
    int chon = 0;
    int toado = 15;
    do{
        char a = getch();
        if(a == 80 ||a == 's'||a=='S'||a=='2') chon = 1;
        else if(a == 72 || a == 'w'||a=='W'||a=='8') chon = 2;
        else if(a == 13 ||a=='5') chon = 3;
        else chon = 0;
        if(chon == 1 && toado < 19) toado++;
        else if(chon == 2 && toado >15) toado--;
        if(toado == 15)
        {
            TextColor(202);
            gotoxy(33, 10); printf("%c  Play Game  ", 175);
            TextColor(14);
            gotoxy(33, 11); printf("  Help         ");
            gotoxy(33, 12); printf("  About        ");
            gotoxy(33, 13); printf("  High Score   ");
            gotoxy(33, 14); printf("  Exit         ");
            TextColor(0);
        }
        if(toado == 16)
        {
            TextColor(14);
            gotoxy(33, 10); printf("  Play Game    ");
            TextColor(202);
            gotoxy(33, 11); printf("%c  Help       ", 175);
            TextColor(14);
            gotoxy(33, 12); printf("  About        ");
            gotoxy(33, 13); printf("  High Score   ");
            gotoxy(33, 14); printf("  Exit         ");
            TextColor(0);
        }
        if(toado == 17)
        {
            TextColor(14);
            gotoxy(33, 10); printf("  Play Game  ");
            gotoxy(33, 11); printf("  Help         ");
            TextColor(202);
            gotoxy(33, 12); printf("%c  About      ", 175);
            TextColor(14);
            gotoxy(33, 13); printf("  High Score     ");
            gotoxy(33, 14); printf("  Exit       ");
            TextColor(0);
        }
            if(toado == 18)
        {
            TextColor(14);
            gotoxy(33, 10); printf("  Play Game    ");
            gotoxy(33, 11); printf("  Help         ");
            gotoxy(33, 12); printf("  About        ");
            TextColor(202);
            gotoxy(33, 13); printf("%c  High Score  ", 175);
            TextColor(14);
            gotoxy(33, 14); printf(" Exit        ");
        }
        if(toado == 19)
        {
            TextColor(14);
            gotoxy(33, 10); printf("  Play Game    ");
            gotoxy(33, 11); printf("  Help         ");
            gotoxy(33, 12); printf("  About        ");
            gotoxy(33, 13); printf("  High Score   ");
            TextColor(202);
            gotoxy(33, 14); printf("%c  Exit      ", 175);
            TextColor(0);
        }
    }while(chon != 3);
    system("cls");
    if(toado == 15) vaogame(name, level, luusnake, dname);
    else if(toado == 16) help(thoat, name, level, luusnake, dname);
    else if(toado == 17) about(thoat, name,level, luusnake, dname);
    else if(toado == 18) Score(thoat, name,level, luusnake, dname);
    else if(toado == 19)
     {
         thoat = 1;
         TextColor(14);
         gotoxy(22,15); printf("==================================");
         gotoxy(27,16); printf("NICE DAY WITH YOU!");
         TextColor(9); gotoxy(65,17); printf("PPSAL");
         Sleep(2000);
     }
}
//Anh 8
void khungplay()
{
    for(int i = 0; i<78; i++)
    {
        gotoxy(1+i, 0);TextColor(12); printf("%c", 220);
    }
        for(int i = 0; i<78; i++)
    {
        gotoxy(1+i, 41); TextColor(12); printf("%c", 205);
    }
    for(int j = 0; j<40; j++)
    {
        gotoxy(0, j+1); TextColor(12); printf("%c", 186);
    }
        for(int j = 0; j<40; j++)
    {
        gotoxy(79, j+1); TextColor(12); printf("%c", 186);
    }
    TextColor(14);
    gotoxy(0,0); printf("%c", 201);
    gotoxy(0,41); printf("%c", 200);
    gotoxy(79,0); printf("%c", 187);
    gotoxy(79,41); printf("%c", 188);
    gotoxy(34, 0); TextColor(160); printf(" GAME SNAKE ");
    TextColor(6);
    gotoxy(3,26); printf("             @@@@@@@@   @@@@@@@@    @@@@@@@    @@@@@@@   @@@       \n"); Sleep(40);TextColor(6);
    gotoxy(3,27); printf("             @@@   @@@  @@@   @@@  @@@   @@@  @@@   @@@  @@@       \n"); Sleep(40); TextColor(6);
    gotoxy(3,28); printf("             @@@   @@@  @@@   @@@   @@@@      @@@   @@@  @@@       \n"); Sleep(40);TextColor(6);
    gotoxy(3,29); printf("             @@@@@@@@   @@@@@@@@       @@@@   @@@@@@@@@  @@@       \n"); Sleep(40); TextColor(6);
    gotoxy(3,30); printf("             @@@        @@@        @@@   @@@  @@@   @@@  @@@       \n"); Sleep(40);TextColor(6);
    gotoxy(3,31); printf("             @@@        @@@         @@@@@@@   @@@   @@@  @@@@@@@@  \n");


        TextColor(1);
        for(int i = 0; i<55; i++)
    {
        gotoxy(13+i, 38); printf("%c", 205);
    }
        for(int i = 0; i<55; i++)
    {
        gotoxy(13+i, 40); printf("%c", 205);
    }
    gotoxy(27, 39); TextColor(4); printf("Team ");
    gotoxy(38, 39); TextColor(3); printf("PPSAL");
}
//Lam 9
void help(int &thoat, char name[], int &level,  Snake &luusnake, char dname[])
{
    khungplay();
    gotoxy(34, 0); TextColor(160); printf("    Help   ");
    TextColor(0);
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 11); printf(" ");
    }
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 21); printf(" ");
    }
    gotoxy(31, 4);TextColor(12); printf("Navigation keys");
    TextColor(14);
    gotoxy(12,7);  printf("Group 1");
    TextColor(15);
    gotoxy(16, 8); printf("A: Left");
    gotoxy(16, 9); printf("D: Right");
    gotoxy(16, 10); printf("S: Up");
    gotoxy(16, 11); printf("W: Down");

    TextColor(14);
    gotoxy(46,7); printf("Group 2");
    TextColor(15);
    gotoxy(50, 8); printf("4: Left");
    gotoxy(50, 9); printf("6: Right");
    gotoxy(50, 10); printf("8: Up");
    gotoxy(50, 11); printf("2: Down");
    TextColor(14);
    gotoxy(28,14);  printf("P :");
    TextColor(15);
    gotoxy(32, 14); printf("Pause - Play");
    gotoxy(36,36); TextColor(47); printf("  Exit  ");
    gotoxy(39,36);
    TextColor(0);
    char a;
    do
    {
        a = getch();
    }while(a!=13 && a != 'e' && a != 'E' && a !='5' && a !=8);
    system("cls");
    fflush(stdin);
    playgame(thoat, name, level, luusnake, dname);
}
//Anh 10
void Score(int &thoat, char name[], int &level, Snake &luusnake, char dname[])
{
  khungplay();
  gotoxy(34, 0); TextColor(160); printf(" High Score ");
  TextColor(0);
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 11); printf(" ");
    }
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 21); printf(" ");
    }
 gotoxy(33, 6); TextColor(12); printf("Highest Score");
 gotoxy(25, 8); TextColor(11); printf("Name:");       gotoxy(41, 8); TextColor(15); printf("%s", dname);
 gotoxy(25, 9); TextColor(11); printf("Score:");             gotoxy(41, 9); TextColor(10); printf("%d", luusnake.n);
    gotoxy(36,36); TextColor(47); printf("  Exit  ");
    gotoxy(39,36);
    TextColor(0);
 char a;
    do
    {
        a = getch();
    }while(a!=13 && a != 'e' && a != 'E' && a !='5' && a != 8);
    system("cls");
    fflush(stdin);
    playgame(thoat, name, level, luusnake, dname);
}
//Sa 11
void about(int &thoat, char name[], int &level, Snake &luusnake, char dname[])
{
  khungplay();
  gotoxy(34, 0); TextColor(160); printf("    Information   ");
  TextColor(0);
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 11); printf(" ");
    }
        for(int i = 0; i<45; i++)
    {
        gotoxy(18+i, 21); printf(" ");
    }

     gotoxy(22, 5); TextColor(11); printf("PROJECT:");      gotoxy(34, 5); TextColor(15); printf("SNAKE GAME");
     gotoxy(22, 6); TextColor(11); printf("TEAM:");         gotoxy(34, 6); TextColor(15); printf("PPSAL");
     gotoxy(22, 7); TextColor(11); printf("MEMBER:");       gotoxy(34, 7); TextColor(10); printf("");
     gotoxy(22, 8); TextColor(11); printf("");              gotoxy(34, 8); TextColor(10); printf("Tran Hoang Phuc");
     gotoxy(22, 9); TextColor(11); printf("");              gotoxy(34, 9); TextColor(10); printf("Vo Tan Phat");
     gotoxy(22, 10); TextColor(11); printf("");             gotoxy(34, 10); TextColor(10); printf("Nguyen Nu Kim Sa");
     gotoxy(22, 11); TextColor(11); printf("");             gotoxy(34, 11); TextColor(10); printf("Kieu Xuan Anh");
     gotoxy(22, 12); TextColor(11); printf("");             gotoxy(34, 12); TextColor(10); printf("Le Nguyen Hoang Bao Lam");

    gotoxy(36,36); TextColor(47); printf("  Exit  ");
    gotoxy(39,36);
    TextColor(0);
 char a;
    do
    {
        a = getch();
    }while(a!=13 && a != 'e' && a != 'E' && a !='5' && a != 8);
    system("cls");
    fflush(stdin);
    playgame(thoat, name, level, luusnake, dname);
}
//Phat 12
void khoitao(Snake &snake, HQ &hq)
{
    snake.dot[0].x = 7;  snake.dot[0].y = 8;
    snake.dot[1].x = 6;  snake.dot[1].y = 8;
    snake.dot[2].x = 5;  snake.dot[2].y = 8;
    snake.dot[3].x = 20;  snake.dot[3].y =20;
    hq.td.x = 20;        hq.td.y = 20;
    snake.tt = RIGHT;
    snake.n = 3;
}
//Lam 13
void hienthi(Snake &snake, HQ &hq)
{
    TextColor(113);
    gotoxy(snake.dot[0].x, snake.dot[0].y); printf("%c", 2);
    TextColor(113);
    for(int i = 1; i < snake.n; i++)
    {
        gotoxy(snake.dot[i].x, snake.dot[i].y); printf("%c", 1);
    }
    int n = 0, l = 0;
   if(snake.tt == RIGHT) n++; l++;
   gotoxy(snake.dot[snake.n].x, snake.dot[snake.n].y); printf(" ");
   gotoxy(hq.td.x, hq.td.y); TextColor(124); printf("%c",15 );
   Time();
   gotoxy(9, 3);TextColor(15); printf("%d", snake.n);
}
//Phat 14
void dieukhien(Snake &snake, int &cam)
{
    fflush(stdin);
    for(int i = snake.n; i>0; i--)   snake.dot[i] = snake.dot[i-1];
    int tamdung = 0;
    if(kbhit())
    {
        char a = getch();
        if((a=='a'||a=='A'||a=='4') && cam != 2) { snake.tt = LEFT;cam=1;}
        else if((a=='d'||a=='D'||a=='6') && cam!=1) { snake.tt = RIGHT;cam=2; }
        else if((a=='s'||a=='S'||a=='2'||a=='5') && cam!=12) { snake.tt = DOWN;cam=11;}
        else if((a=='w'||a=='W'||a=='8') && cam!=11)  {snake.tt = UP;cam=12;}
        else if(a=='p'||a=='P'||a==27)  tamdung = 1;
    }
    if(snake.tt == LEFT) snake.dot[0].x--;
    else if(snake.tt == RIGHT) snake.dot[0].x++;
    else if(snake.tt == DOWN) snake.dot[0].y++;
    else if(snake.tt == UP) snake.dot[0].y--;
     if(tamdung == 1)
    {
        gotoxy(34, 18);TextColor(144); printf("Pause!");
        gotoxy(29, 18);
        int thoat = 0;
        do{
            char a = getch(); if(a == 'p' ||a =='P') thoat = 1;
        }while(thoat!=1);
        gotoxy(33, 18);TextColor(112); printf("                   ");
    }
    }
//Sa 15
void Random(Snake &snake, HQ &hq)
{
    if(snake.dot[0].x == hq.td.x && snake.dot[0].y == hq.td.y)
    {
    hq.td.x = rand()%69+5;
    hq.td.y = rand()%18+8;
    snake.n++;
    Beep(1000, 100);
    }
    gotoxy(78,40);
}
//Lam 16
void thuagame(Snake snake, int &thua)
{
    if (snake.dot[0].x == 75)
      {
      thua = 0;
        Beep(3000, 500);Sleep(20);Beep(3000, 500);
            }
        else if (snake.dot[0].y == 34)
        {
            thua = 0;
            Beep(3000, 500);Sleep(20);Beep(3000, 500);
            }
            else if (snake.dot[0].x == 4)
            {
            thua = 0;
            Beep(3000, 500);Sleep(20);Beep(3000, 500);
            }
                else if (snake.dot[0].y == 7)
                {
            thua = 0;
            Beep(3000, 500);Sleep(20);Beep(3000, 500);
            }
    else thua = 1;

    for(int i = snake.n-1; i>0; i--)
    {
        if(snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y )
        {
            thua = 0;
            Beep(3000, 500);Sleep(20);Beep(3000, 500);
            }
    }
}
//Lam 17
void Time()
{
    int time = clock()/1000, gio, phut, giay;
    gio = time/3600; phut = (time/60)%60, giay = time%60;
    gotoxy(67, 3);TextColor(15);
    if(giay < 10 && gio<10 && phut<10) printf("0%d:0%d:0%d",gio, phut, giay );
    else if(giay < 10 && gio<10) printf("0%d:%d:0%d",gio, phut, giay );
    else if(phut < 10 && gio<10) printf("0%d:0%d:%d",gio, phut, giay );
    else if(giay < 10 && phut<10) printf("%d:%d:0%d",gio, phut, giay );
    else if(giay < 10 ) printf("%d:%d:0%d",gio, phut, giay );
    else if(gio<10) printf("0%d:%d:%d",gio, phut, giay );
    else if(phut<10)printf("%d:0%d:%d",gio, phut, giay );
}

//Sa 18
void vaogame(char name[], int &level,  Snake &luusnake, char dname[])
{
    level = 100;
    khungplay();
    for(int i = 0; i<4; i++)
    {
        gotoxy(24,8+i);
        for(int j = 0; j<30; j++)
        {
            if(i == 0 || i==3) printf("%c", 196);
            else if(j == 0 || j==29) printf("%c", 179);
            else printf(" ");
        }
    }
        for(int i = 0; i<4; i++)
    {
        gotoxy(24,12+i);
        for(int j = 0; j<30; j++)
        {
            if(i == 0 || i==3) printf("%c", 196);
            else if(j == 0 || j==29) printf("%c", 179);
            else printf(" ");
        }
    }
    TextColor(12);
    gotoxy(35,7); printf("Start");
    TextColor(11);
    gotoxy(26,13); printf("Level: ");
    gotoxy(26,9); printf("Name: "); gotoxy(37,9);TextColor(7); gets(name); fflush(stdin);
    gotoxy(37,13);TextColor(12); printf("%c", 174); gotoxy(41,13);TextColor(12); printf("%c", 175);
    gotoxy(39,13);TextColor(15); printf("4");
    int chon = 0;
    int capdo=4;
    gotoxy(27,14);TextColor(2); printf("Phim 4: -1 | Phim 6: +1");
     gotoxy(39, 13);
    do{
        fflush(stdin);
        char a = getch();
        if(a == 75 ||a == 'a'||a=='A'||a=='4') chon = 1;
        else if(a == 77 || a == 'd'||a=='D'||a=='6') chon = 2;
        else if(a == 13 ||a=='5') chon = 3;
        if(chon == 1 && capdo > 1) capdo=capdo-1;
        else if(chon == 2 && capdo < 9) capdo=capdo+1;
        gotoxy(39,13);TextColor(15); printf("%d", capdo);
    }while(chon != 3);
    //gan cap do
    switch(capdo)
    {
        case 1: level = 1000; break;
        case 2: level = 500; break;
        case 3: level = 250; break;
        case 4: level = 150; break;
        case 5: level = 100;  break;
        case 6: level = 80;  break;
        case 7: level = 50;  break;
        case 8: level = 25;  break;
        case 9: level = 15; break;
    }
    system("cls");
}
//Phat 19
void docfile(Snake &luusnake, char dname[])
{
    FILE *p = fopen("Diemcao.txt","rt");
    if(p!=NULL)
    do{
        fgets(dname, 30, p);
        fscanf(p, "%d", &luusnake.n);
    }while(feof(p) == 0);
    fclose(p);
}
//Phat 20
void ghifile(Snake snake, char name[])
{
    FILE *p = fopen("Diemcao.txt","wt");
    {
        fprintf(p, "%s\n%d", name, snake.n);
    }
    fclose(p);
}
//Lam 21
void gameover(char name[], Snake snake, Snake luusnake)
{
            for(int i = 5; i<75; i++)
    {
        for(int j = 2; j<28; j++)
        {
            gotoxy(i, j+6); TextColor(112); printf(" ");
        }
        printf("\n");
    }
    int thoat = 0;
    if(snake.n <= luusnake.n)
    {
        gotoxy(33,15); TextColor(124); printf("Game Over");
        gotoxy(20,18); TextColor(121); printf("Score: ");
        gotoxy(33,18); TextColor(121); printf("%d", snake.n);
        gotoxy(20,17); TextColor(121); printf("Name: ");
        gotoxy(33,17); TextColor(121); printf("%s", name);
    do{
    thoat = thoat+1;
    if(kbhit())
     {
        char a = getch();   if(a==13) thoat = 13;
      }
    gotoxy(77,40);  Sleep(300);
    }while(thoat != 13);
      }
    if(snake.n > luusnake.n)
    {
        gotoxy(25,15); TextColor(124); printf("Congratulation!");
        gotoxy(45,17); TextColor(121); printf("Old score: ");
        gotoxy(54,17); TextColor(121); printf("%d", luusnake.n);
        gotoxy(20,17); TextColor(121); printf("New Score: ");
        gotoxy(30,17); TextColor(121); printf("%d", snake.n);
    do{
    thoat = thoat+1;
    if(kbhit())
     {
        char a = getch();   if(a==13) thoat = 13;
      }
    gotoxy(77,40);  Sleep(300);
    }while(thoat != 13);
      }
    TextColor(0);
}
