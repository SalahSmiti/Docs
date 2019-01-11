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
