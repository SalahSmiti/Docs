#include <stdio.h>
//#include <windows.h>

typedef struct Point Point;
struct Point
{
    int x;
    int y;
};

int main()
{
    char arr[30];
    int i = 30;
    remplirTableauAvecAlphabet(arr,i);
    for(int j=0; j<30; j++)
    {
        printf("%c",arr[j]);
    }
    //Locate(3,2);
    
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

int egalite(point p1,point p2)
{
    if(p1.x == p2.x && p1.y == p2.y)
        return 1;
    return 0;
}
 
/*void Locate(int x,int y)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=x;
    C.Y=y;
    SetConsoleCursorPosition(H,C);
}*/


void barreHorizentale(int x,int y,char tab[],int taille)
{
    //Locate(x,y);
    for(int i = 0; i < taille; i++)
    {
        printf("%c",tab[i]);
    }
}
void barreHorizentale2(Point p,char tab[],int taille)
{
    //Locate(p.x,p.y);
    for(int i = 0; i < taille; i++)
    {
        printf("%c",tab[i]);
    }
}
void barreVerticale(int x,int y,char tab[],int taille)
{
    //Locate(x,y);
    for(int i = 0; i < taille; i++)
    {
        printf("%c\n",tab[i]);
    }
}

void barreVerticale2(Point p,char tab[],int taille)
{
    //Locate(p.x,p.y);
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



