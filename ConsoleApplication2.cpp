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

	
#include <stdio.h>

void pgcd (int a, int b) 
{
  int r;
  if(b>a)
  {
      printf("Permutation des paramètres \n");
      int temp = a ;
      a = b;
      b = temp;
  }
  while (1) {
    r = a % b;
    if (r == 0)
    {
      printf("Le PGCD est égal à %d",b);
      break;  
    }
    a = b;
    b = r;
  }
}
int main()
{
    pgcd(6,12);

    return 0;
}
	
	
	
#include <stdio.h>

void Transformer (char mot_a_changer[]) 
{
    for (char* p = mot_a_changer; p = strchr(p, 'e'); ++p) {
        *p = '3';
    }
    for (char* p = mot_a_changer; p = strchr(p, 'a'); ++p) {
        *p = '4';
    }
    printf("%s\n", mot_a_changer);  // 3v4lu4tion
}
int main()
{
    char mot_a_changer[] = "evaluation!";
    Transformer (mot_a_changer);
    return 0;
}

	
	
}


















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555
#define LGL 100       /* Longueur max d'une ligne de fichier   */

struct Rocher{
	int x;
	int y;
};
struct Vent{
	int force;
	char direction[1];
};
struct Point
{
	int x;
	int y;
};
struct Bateau{
	char identifiant[30];
	char nom[10];
	int vitesse;
	char direction[1];
	struct Point coordonne;
};

struct Ocean{
	int longeur;
	int largeur;
	char* oceanMatrix[100][100];
	struct Rocher rocher[100];
	struct Bateau bateau[100];
	int nbrRochers;
	int nbrBateaux;
	struct Vent vent;
};
void LireCarte(struct Ocean ocean);

int GetVitesseFinale(struct Bateau b,struct Vent v);
void UpdateCordonne(struct Ocean ocean, int vf, int index);
void OceanInfinie(struct Bateau b,struct Ocean ocean);



int main()
{

	
	int i = 0, j = 0, k = 0;
	struct Vent vent;
	vent.force = 0;
	//strcpy(vent.direction, "N");
	struct Ocean oc;
	// Lecture des paramètre à partir du ficier de config mis sous c:/
	LireCarte(oc);
	oc.vent = vent;
	
	int sockfd, ret;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	char bufferResponse[1024];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		printf("[-]Error de connexion.\n");
		exit(1);
	}
	printf("[+]Serveur de Socket est bien creer.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if (ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Ereur dans le port %d\n", 4444);

	if (listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}
	else{
		printf("[-]Error in binding.\n");
	}
	while (1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if (newSocket < 0){
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
		if ((childpid = fork()) == 0)
		{
			close(sockfd);
			while (1)
			{
				printf("on a : %s\n", buffer);
				if (strcmp(buffer, ":2") == 0)
				{
					char direction[10];
					bzero(bufferResponse, sizeof(bufferResponse));
					strcpy(bufferResponse, "Veuiller saisir la direction: \n");
					send(newSocket, bufferResponse, strlen(bufferResponse), 0);
					recv(newSocket, direction, 10, 0);
					printf("Direction : %s\n", direction);
					for (i = 0; i < oc.nbrBateaux; i++){
						struct Bateau bateauTmp;
						bateauTmp = oc.bateau[i];

						if (strcmp(bateauTmp.identifiant, inet_ntoa(newAddr.sin_addr)) == 0)
							strcpy(oc.bateau[i].direction, direction);
					}
					strcpy(bufferResponse, ":menu");
				}
				
				printf("Client: %s\n", buffer);
				send(newSocket, bufferResponse, strlen(bufferResponse), 0);
				bzero(buffer, sizeof(buffer));
				bzero(bufferResponse, sizeof(bufferResponse));
			}
		}

	}

	close(newSocket);

	return 0;
}

void LireCarte(struct Ocean ocean)
{
	ocean.nbrRochers = 0;
	int LongeurCarte;
	int	LargeurCarte;
	char ligne[LGL];
	char entryPath[1000];
	char descriptionFileName[LGL];
	FILE *carte;


	while (strcmp(descriptionFileName, "fin") != 0)
	{
		printf("Veuillez mettre le fichier decrivant la carte : sous C:\\Carte.txt");
		fgets(entryPath, LGL, stdin);
		carte = fopen("C:\\Carte.txt", "r");
		if (carte == NULL) {
			printf("Le fichier %s n'existe pas\n", descriptionFileName);
		}
		else {
			descriptionFileName[0] = '\0';
			strcat(descriptionFileName, "fin");
			
			while (!feof(carte)) {
				fgets(ligne, LGL, carte);
				int init_size = strlen(ligne);
				char delim[] = " ";
				char *first = strtok(ligne, delim);
				char *second;
				while (first != NULL)
				{
					if (strcmp("LongeurCarte", first) == 0) {
						second = strtok(NULL, delim);
						LongeurCarte = atoi(&second[0]);
						ocean.longeur = LongeurCarte;
						first = NULL;
					}
					else if (strcmp("LargeurCarte", first) == 0) {
						second = strtok(NULL, delim);
						LargeurCarte = atoi(&second[0]);
						ocean.largeur = LargeurCarte;
						first = NULL;
					}
					else if (strcmp("PositionBateau", first) == 0) {
						second = strtok(NULL, delim);
						second = strtok(second, ",");
						struct Bateau b;
						b.coordonne.x = atoi(&second[0]);
						b.coordonne.y = atoi(strtok(NULL, ","));
						b.vitesse = 0;
						ocean.bateau[ocean.nbrBateaux] = b;
						ocean.nbrBateaux++;
						// B designe un bateau au position X,Y
						strcpy(ocean.oceanMatrix[b.coordonne.x][b.coordonne.y], "B");
						first = NULL;
					}
					else if(strcmp("Rocher", first) == 0) {
						second = strtok(NULL, delim);
						second = strtok(second, ",");
						struct Rocher rocher;
						rocher.x = atoi(&second[0]);
						rocher.y = atoi(strtok(NULL, ","));
						ocean.rocher[ocean.nbrRochers] = rocher;
						ocean.nbrRochers++;
						first = NULL;
						// R designe un rocher au position X,Y
						strcpy(ocean.oceanMatrix[rocher.x][rocher.y], "R");
					}
				}


			}
			fgets(entryPath, LGL, stdin);
			fclose(carte);
		}
	}

}

int GetVitesseFinale(struct Bateau b,struct Vent v)
{
	int vitesseFinale = 0;
	if (strcmp(b.direction, v.direction) == 0)
	{
		vitesseFinale = b.vitesse * (1 + (v.force / 10));
	}
	else
	{
		vitesseFinale = b.vitesse * (1 / v.force);
	}
	return vitesseFinale;
}
void UpdateCordonne(struct Ocean ocean, int vf, int index)
{
	if (strcmp(ocean.bateau[index].direction, "N") == 0 )
	{
		if ((strcmp(ocean.vent.direction, "N") == 0 || strcmp(ocean.vent.direction, "S") == 0))
			ocean.bateau[index].coordonne.y = ocean.bateau[index].coordonne.y - vf;
		else if ((strcmp(ocean.vent.direction, "E") == 0) || (strcmp(ocean.bateau[index].direction, "E") == 0 && strcmp(ocean.vent.direction, "N") == 0))
		{
			ocean.bateau[index].coordonne.y = ocean.bateau[index].coordonne.y - vf;
			ocean.bateau[index].coordonne.x = ocean.bateau[index].coordonne.x + vf;
		}
		else if ((strcmp(ocean.vent.direction, "O") == 0) || (strcmp(ocean.bateau[index].direction, "O") == 0 && strcmp(ocean.vent.direction, "N") == 0))
		{
			ocean.bateau[index].coordonne.y = ocean.bateau[index].coordonne.y - vf;
			ocean.bateau[index].coordonne.x = ocean.bateau[index].coordonne.x - vf;
		}
	}
	if (strcmp(ocean.bateau[index].direction, "S") == 0 && (strcmp(ocean.vent.direction, "N") == 0 || strcmp(ocean.vent.direction, "S") == 0))
	{
		if ((strcmp(ocean.vent.direction, "N") == 0 || strcmp(ocean.vent.direction, "S") == 0))
			ocean.bateau[index].coordonne.y = ocean.bateau[index].coordonne.y + vf;
		else if ((strcmp(ocean.vent.direction, "E") == 0) || (strcmp(ocean.bateau[index].direction, "E") == 0 && strcmp(ocean.vent.direction, "S") == 0))
		{
			ocean.bateau[index].coordonne.y = ocean.bateau[index].coordonne.y + vf;
			ocean.bateau[index].coordonne.x = ocean.bateau[index].coordonne.x + vf;
		}
		else if ((strcmp(ocean.vent.direction, "O") == 0) || (strcmp(ocean.bateau[index].direction, "O") == 0 && strcmp(ocean.vent.direction, "S") == 0))
		{
			ocean.bateau[index].coordonne.y = ocean.bateau[index].coordonne.y + vf;
			ocean.bateau[index].coordonne.x = ocean.bateau[index].coordonne.x - vf;
		}
	}
	if (strcmp(ocean.bateau[index].direction, "E") == 0 && (strcmp(ocean.vent.direction, "E") == 0 || strcmp(ocean.vent.direction, "O") == 0)){
		ocean.bateau[index].coordonne.x = ocean.bateau[index].coordonne.x - vf;
	}
	if (strcmp(ocean.bateau[index].direction, "O") == 0 && (strcmp(ocean.vent.direction, "E") == 0 || strcmp(ocean.vent.direction, "O") == 0)){
		ocean.bateau[index].coordonne.x = ocean.bateau[index].coordonne.x + vf;
	}

	
}
void OceanInfinie(struct Bateau b,struct Ocean ocean)
{
	// Si le bateau dépasse les cotes => Ocean infinie
	if (b.coordonne.y < 0) b.coordonne.y = ocean.largeur;
	if (b.coordonne.y > ocean.largeur) b.coordonne.y = 0;

	if (b.coordonne.x < 0) b.coordonne.x = ocean.longeur;
	if (b.coordonne.x> ocean.largeur) b.coordonne.x = 0;
}
