void BarreHorizentale(int x,int y,char tab[],int taille)
{
  
    for(int i = 0; i< x; ++i)
    {
        printf(" ");
    }
    for(int i = 0; i<  y; ++i)
    {
      printf("\n");
    }
    for(int i = 0; i< taille; ++i)
    {
       printf("%c ", tab[i]);
    }
    
}

void BarreVerticale(int x,int y,char tab[],int taille)
{
    for(int i = 0; i< taille; ++i)
    {
	    for(int i = 0; i< x; ++i)
	    {
		printf(" ");
	    }
	    for(int i = 0; i< taille + y; ++i)
	    {
	      printf("\n");
	    }
       printf("%c ", tab[i]);
    }
    
}

struct Point 
{ 
   int x, y; 
}; 

  Point PlusX(Point p, int max)
  {
      if(p.x < max)
        p.x++;
      return p;
  }

  Point PlusY(Point p, int max)
  {
      if(p.y < max)
        p.y++;
      return p;
  }

  Point MoinsY(Point p, int min)
  {
    if(p.y > max)
        p.y--;
    return p;
  }

  Point MoinsX(Point p, int min)
  {
    if(p.x > max)
        p.x--;
    return p;
  }

int Egalite(Point p1,Point p2)
{
	if(p1.x == p2.x && p1.y == p2.y)
		return 1;
	return 0;
}

void BarreHorizentale2(Point p,char tab[],int taille)
{
  
    for(int i = 0; i< p.x; ++i)
    {
        printf(" ");
    }
    for(int i = 0; i<  p.y; ++i)
    {
      printf("\n");
    }
    for(int i = 0; i< taille; ++i)
    {
       printf("%c ", tab[i]);
    }
    
}

void BarreVerticale2(Point p,char tab[],int taille)
{
    for(int i = 0; i< taille; ++i)
    {
	    for(int i = 0; i< p.x; ++i)
	    {
		printf(" ");
	    }
	    for(int i = 0; i< taille + p.y; ++i)
	    {
	      printf("\n");
	    }
       printf("%c ", tab[i]);
    }
    
}




struct Point
{
    int x;
    int y;
} depart, cible;
void main ())
{
char murHorizental[80];
char murVertical[28];
BarreHorizentale(0,0,murHorizental,80);
BarreHorizentale(28,0,murHorizental,80);
BarreVerticale(0,0,murVertical,28);
BarreVerticale(0,80,murVertical,28);

depart.x = 2;
depart.y = 2;
cible.x = 20;
cible.y = 15;


    int  number = 0;


	
while (number != key_esc) 
{
	scanf("%d", &number);
	if(number == 6)
	    PlusX(depart, 80);
	if(number == 4)
	    MoinsX(depart, 0);
	if(number == 8)
	    PlusY(depart, 28);
	if(number == 2)
	    MoinsY(depart, 0);
	if(Egalite(depart,cible) == 1)
	     printf("Gagné!");
	number = key_esc;
}

}

