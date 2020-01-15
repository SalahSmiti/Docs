#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct Point Point;
struct Point
{
    int x;
    int y;
};

int main()
{
    char murHorizental[80];
    remplirTableauAvecAlphabet(murHorizental,80);
    char murVertical[28];
    remplirTableauAvecAlphabet(murVertical,28);
    barreHorizentale(0,0,murHorizental,80);
    barreHorizentale(28,0,murHorizental,80);
    barreVerticale(0,0,murVertical,28);
    barreVerticale(0,80,murVertical,28);
    Point depart;
    depart.x = 2;
    depart.y = 2;
    Locate(depart.x,depart.y);
    printf("X");
    Point cible;
    srand((int) time(NULL));
    cible.x = 20 + rand()%40;
    cible.y = 20 + rand()%40;
    Locate(cible.x,cible.y);
    printf("C");
     while (1) 
     {
        char c = getchar();            
        if (c == 27) { break; }  // Sortir si ESC
        if (c == "8")
        {
            plusY(depart,28);
        }
        else if (c == "2")
        {
            moinsY(depart,0);
        }
        else if (c == "6")
        {
            plusX(depart,80);
        }
        else if (c == "2")
        {
            moinsX(depart,0);
        }
        if(egalite(depart,cible))
        {
            break; 
        }           
    }
    Locate(3,2);
    
    Point point;
    
    point.x = 10;
    point.y = 20;
    plusX(point,30);
    return 0;
}

void plusX(Point point,int max)
{
    if(point.x +1 <= max)
        point.x = point.x +1;
}

void plusY(Point point,int max)
{
    if(point.y +1 <= max)
        point.y = point.x +1;
}

void moinsX(Point point,int min)
{
    if(point.x - 1 >= min)
        point.x = point.x - 1;
}

void moinsY(Point point,int min)
{
    if(point.y - 1 >= min)
        point.y = point.x - 1;
}

int egalite(Point p1,Point p2)
{
    if(p1.x == p2.x && p1.y == p2.y)
        return 1;
    return 0;
}
 
void Locate(int x,int y)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=x;
    C.Y=y;
    SetConsoleCursorPosition(H,C);
}


void barreHorizentale(int x,int y,char tab[],int taille)
{
    Locate(x,y);
    for(int i = 0; i < taille; i++)
    {
        printf("%c",tab[i]);
    }
}
void barreHorizentale2(Point p,char tab[],int taille)
{
    Locate(p.x,p.y);
    for(int i = 0; i < taille; i++)
    {
        printf("%c",tab[i]);
    }
}
void barreVerticale(int x,int y,char tab[],int taille)
{
    Locate(x,y);
    for(int i = 0; i < taille; i++)
    {
        printf("%c\n",tab[i]);
    }
}

void barreVerticale2(Point p,char tab[],int taille)
{
    Locate(p.x,p.y);
    for(int i = 0; i < taille; i++)
    {
        printf("%c\n",tab[i]);
    }
}

void remplirTableauAvecAlphabet(char tab[],int taille)
{
    for(int i = 0; i < taille; i++)
    {
        if(i<26)
        tab[i] = (char)(97 + i);
        else
        tab[i] = (char)(97 + i - 26);
    }
}



