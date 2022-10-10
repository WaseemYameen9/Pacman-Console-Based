#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
/*when the game  will start the ghosts will automatically move in the maze i have given the coordinates*/
char maze[24][71];
int pacmanx = 9;
int pacmany = 31;
int score = 0;
int g1x = 6;
int g1y = 5;
int g2x = 22;
int g2y = 1;
int g3x = 5;
int g3y = 60;
int g4x = 10;
int g4y = 41;
int check = 0;
int life = 3;
char previousitem1 = ' ';
char previousitem2 = ' ';
char previousitem3 = ' ';
char previousitem4 = ' ';
string line;
char flagc = '0';
string g1direction = "up";
string g2direction = "left";
void header()
{
    cout << "      ____  ___   ________  ______    _   __  " << endl;
    cout << "     / __ |/   | / ____/  |/  /   |  / | / /  " << endl;
    cout << "    / /_/ / /| |/ /   / /|_/ / /| | /  |/ /   " << endl;
    cout << "   / ____/ ___ / /___/ /  / / ___ |/ /|  /    " << endl;
    cout << "  /_/   /_/  | |____/_/  /_/_/  |_/_/ |_/     " << endl;
}
void flag()
{
    flagc = '1';
}
void display()
{
    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 71; col++)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void movepacleft()
{
    if (maze[pacmanx][pacmany - 1] == ' ' || maze[pacmanx][pacmany - 1] == '.')
    {
        maze[pacmanx][pacmany] = ' ';
        gotoxy(pacmany, pacmanx);
        cout << " ";
        pacmany = pacmany - 1;
        gotoxy(pacmany, pacmanx);
        cout << "P";
    }

    if (maze[pacmanx][pacmany - 1] == '.')
    {
        score = score + 1;
    }
    if (maze[pacmanx][pacmany - 1] == 'E')
    {
        maze[pacmanx][pacmany - 1] = ' ';
        life++;
    }
}
void movepacright()
{
    if (maze[pacmanx][pacmany + 1] == ' ' || maze[pacmanx][pacmany + 1] == '.')
    {
        maze[pacmanx][pacmany] = ' ';
        gotoxy(pacmany, pacmanx);
        cout << " ";
        pacmany = pacmany + 1;
        gotoxy(pacmany, pacmanx);
        cout << "P";
    }

    if (maze[pacmanx][pacmany + 1] == '.')
    {
        score = score + 1;
    }
    if (maze[pacmanx][pacmany + 1] == 'E')
    {
        maze[pacmanx][pacmany + 1] = ' ';
        life++;
    }
}
void movepacup()
{

    if (maze[pacmanx - 1][pacmany] == ' ' || maze[pacmanx - 1][pacmany] == '.')
    {
        maze[pacmanx][pacmany] = ' ';
        gotoxy(pacmany, pacmanx);
        cout << " ";
        pacmanx = pacmanx - 1;
        gotoxy(pacmany, pacmanx);
        cout << "P";
    }
    if (maze[pacmanx - 1][pacmany] == '.')
    {
        score = score + 1;
    }
    if (maze[pacmanx - 1][pacmany] == 'E')
    {
        maze[pacmanx - 1][pacmany] = ' ';
        life++;
    }
}
void movepacdown()
{
    if (maze[pacmanx + 1][pacmany] == ' ' || maze[pacmanx + 1][pacmany] == '.')
    {
        maze[pacmanx][pacmany] = ' ';
        gotoxy(pacmany, pacmanx);
        cout << " ";
        pacmanx = pacmanx + 1;
        gotoxy(pacmany, pacmanx);
        cout << "P";
    }

    if (maze[pacmanx + 1][pacmany] == '.')
    {
        score = score + 1;
    }
    if (maze[pacmanx + 1][pacmany] == 'E')
    {
        maze[pacmanx + 1][pacmany] = ' ';
        life++;
    }
}
void moveg1up()
{
    maze[g1x][g1y] = previousitem1;
    gotoxy(g1y, g1x);
    cout << previousitem1;
    g1x = g1x - 1;
    previousitem1 = maze[g1x][g1y];
    gotoxy(g1y, g1x);
    cout << "G";
}
void moveg1down()
{
    maze[g1x][g1y] = previousitem1;
    gotoxy(g1y, g1x);
    cout << previousitem1;
    g1x = g1x + 1;
    previousitem1 = maze[g1x][g1y];
    gotoxy(g1y, g1x);
    cout << "G";
}
void g1movement()
{
    if (g1direction == "up")
    {
        if (maze[g1x - 1][g1y] == '%' || maze[g1x - 1][g1y] == '#')
        {
            g1direction = "down";
        }
        else
        {
            moveg1up();
        }
    }
    else if (g1direction == "down")
    {
        if (maze[g1x + 1][g1y] == '%' || maze[g1x + 1][g1y] == '#')
        {
            g1direction = "up";
        }
        else
        {
            moveg1down();
        }
    }
}
void moveg2left()
{

    maze[g2x][g2y] = previousitem2;
    gotoxy(g2y, g2x);
    cout << previousitem2;
    g2y = g2y - 1;
    previousitem2 = maze[g2x][g2y];
    gotoxy(g2y, g2x);
    cout << "G";
}
void moveg2right()
{

    maze[g2x][g2y] = previousitem2;
    gotoxy(g2y, g2x);
    cout << previousitem2;
    g2y = g2y + 1;
    previousitem2 = maze[g2x][g2y];
    gotoxy(g2y, g2x);
    cout << "G";
}
void g2movement()
{
    if (g2direction == "left")
    {
        if (maze[g2x][g2y - 1] == '%' || maze[g2x][g2y - 1] == '|')
        {
            g2direction = "right";
        }
        else
        {
            moveg2left();
        }
    }
    else if (g2direction == "right")
    {
        if (maze[g2x][g2y + 1] == '%' || maze[g2x][g2y + 1] == '|')
        {
            g2direction = "left";
        }
        else
        {
            moveg2right();
        }
    }
}
void g3movement()
{
    srand(time(0));
    int num;
    num = rand() % 4;
    if (num == 0)
    {
        if (maze[g3x - 1][g3y] == '%' || maze[g3x - 1][g3y] == '#' || maze[g3x - 1][g3y] == '|')
        {
        }
        else
        {
            maze[g3x][g3y] = previousitem3;
            gotoxy(g3y, g3x);
            cout << previousitem3;
            g3x = g3x - 1;
            previousitem3 = maze[g3x][g3y];
            gotoxy(g3y, g3x);
            cout << "G";
        }
    }
    if (num == 1)
    {
        if (maze[g3x + 1][g3y] == '%' || maze[g3x + 1][g3y] == '#' || maze[g3x + 1][g3y] == '|')
        {
        }
        else
        {
            maze[g3x][g3y] = previousitem3;
            gotoxy(g3y, g3x);
            cout << previousitem3;
            g3x = g3x + 1;
            previousitem3 = maze[g3x][g3y];
            gotoxy(g3y, g3x);
            cout << "G";
        }
    }
    if (num == 2)
    {
        if (maze[g3x][g3y - 1] == '%' || maze[g3x][g3y - 1] == '#' || maze[g3x][g3y - 1] == '|')
        {
        }
        else
        {
            maze[g3x][g3y] = previousitem3;
            gotoxy(g3y, g3x);
            cout << previousitem3;
            g3y = g3y - 1;
            previousitem3 = maze[g3x][g3y];
            gotoxy(g3y, g3x);
            cout << "G";
        }
    }
    if (num == 3)
    {
        if (maze[g3x][g3y + 1] == '%' || maze[g3x][g3y + 1] == '#' || maze[g3x][g3y + 1] == '|')
        {
        }
        else
        {
            maze[g3x][g3y] = previousitem3;
            gotoxy(g3y, g3x);
            cout << previousitem3;
            g3y = g3y + 1;
            previousitem3 = maze[g3x][g3y];
            gotoxy(g3y, g3x);
            cout << "G";
        }
    }
}
void g4movement()
{
    if (check == 1)
    {
        if (maze[g4x][g4y - 1] == '%' || maze[g4x][g4y - 1] == '#' || maze[g4x][g4y - 1] == '|')
        {
        }
        else
        {
            maze[g4x][g4y] = previousitem4;
            gotoxy(g4y, g4x);
            cout << previousitem4;
            g4y = g4y - 1;
            previousitem4 = maze[g4x][g4y];
            gotoxy(g4y, g4x);
            cout << "G";
        }
    }
    if (check == 2)
    {
        if (maze[g4x][g4y + 1] == '%' || maze[g4x][g4y + 1] == '#' || maze[g4x][g4y + 1] == '|')
        {
        }
        else
        {
            maze[g4x][g4y] = previousitem4;
            gotoxy(g4y, g4x);
            cout << previousitem4;
            g4y = g4y + 1;
            previousitem4 = maze[g4x][g4y];
            gotoxy(g4y, g4x);
            cout << "G";
        }
    }
    if (check == 3)
    {
        if (maze[g4x - 1][g4y] == '%' || maze[g4x - 1][g4y] == '#' || maze[g4x - 1][g4y] == '|')
        {
        }
        else
        {
            maze[g4x][g4y] = previousitem4;
            gotoxy(g4y, g4x);
            cout << previousitem4;
            g4x = g4x - 1;
            previousitem4 = maze[g4x][g4y];
            gotoxy(g4y, g4x);
            cout << "G";
        }
    }
    if (check == 4)
    {
        if (maze[g4x + 1][g4y] == '%' || maze[g4x + 1][g4y] == '#' || maze[g4x - 1][g4y] == '|')
        {
        }
        else
        {
            maze[g4x][g4y] = previousitem4;
            gotoxy(g4y, g4x);
            cout << previousitem4;
            g4x = g4x + 1;
            previousitem4 = maze[g4x][g4y];
            gotoxy(g4y, g4x);
            cout << "G";
        }
    }
}
void checklifes()
{
    if ((pacmanx == g1x) || (pacmanx == g2x) || (pacmanx == g3x) || (pacmanx == g4x))
    {
        if ((pacmany == g1y) || (pacmany == g2y) || (pacmany == g3y) || (pacmany == g4y))
        {
            life--;
            maze[pacmanx][pacmany] = ' ';
            gotoxy(pacmany, pacmanx);
            cout << " ";
            pacmanx = 9;
            pacmany = 31;
            gotoxy(pacmany, pacmanx);
            cout << "P";
        }
    }
}
void load()
{
    fstream newwfile;
    newwfile.open("maze.txt", ios::in);
    string line;
    for (int roww = 0; roww < 24; roww++)
    {
        getline(newwfile, line);
        for (int coll = 0; coll < 71; coll++)
        {
            maze[roww][coll] = line[coll];
        }
    }
    newwfile.close();
}

main()
{

    load();
    system("CLS");
    display();
    while (flagc != '1')
    {
        Sleep(200);
        if (GetAsyncKeyState(VK_LEFT))
        {
            movepacleft();
            check = 1;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movepacright();
            check = 2;
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movepacup();
            check = 3;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movepacdown();
            check = 4;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            flag();
        }
        if (life == 0)
        {
            flag();
        }
        g1movement();
        g2movement();
        g3movement();
        g4movement();
        checklifes();
        gotoxy(3, 25);
        cout << "POWERED BY MUHAMMAD WASEEM   2021-CS-61" << endl;
        gotoxy(85, 6);
        cout << "RULES:" << endl;
        gotoxy(85, 7);
        cout << "1-If Pacman eats pallet his score increases by 1" << endl;
        gotoxy(85, 8);
        cout << "2-P represents PACMAN and G represents GHOST" << endl;
        gotoxy(76, 9);
        cout << "3-IF Pacman eats energizer(E) then his life increases by 1." << endl;
        gotoxy(100, 10);
        cout << "SCORE:" << score;
        gotoxy(100, 11);
        cout << "Lives :" << life;
    }
    system("CLS");
    cout << " score : " << score << endl;
    cout << "Thanks For Playing. Get Back soon.." << endl;
}