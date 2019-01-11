int BarreHorizentale(int x,int y,char tab[],int taille)
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

int BarreVerticale(int x,int y,char tab[],int taille)
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



