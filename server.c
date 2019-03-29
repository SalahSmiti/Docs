https://perso.liris.cnrs.fr/pchampin/enseignement/algo/exercices/tableaux.html
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
	Point coordonne;
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



void LireCarte(Ocean ocean)
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

int GetVitesseFinale(Bateau b, Vent v)
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
void UpdateCordonne(Ocean ocean, int vf, int index)
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
void OceanInfinie(Bateau b,Ocean ocean)
{
	// Si le bateau dépasse les cotes => Ocean infinie
	if (b.coordonne.y < 0) b.coordonne.y = ocean.largeur;
	if (b.coordonne.y > ocean.largeur) b.coordonne.y = 0;

	if (b.coordonne.x < 0) b.coordonne.x = ocean.longeur;
	if (b.coordonne.x> ocean.largeur) b.coordonne.x = 0;
}
void PrintOcean(Ocean oc)
{
	for (i = 0; i<oc.longeur; i++) {
		for (j = 0; j<oc.largeur; j++) {
			char aff = '~';
			for (k = 0; k<oc.nbrRochers; k++) {
				if (oc.rocherClasss[k].x == i  && oc.rocher[k].y == j) {
					aff = 'R';
				}
			}
			for (int l = 0; l<oc.nbrBateaux; l++) {

				if (oc.bateau[l].coordonne.x >= i && oc.bateau[l].coordonne.x < i + 1 && oc.bateau[l].coordonne.y >= j && oc.bateau[l].coordonne.y < j + 1) {
					aff = 'B';
				}
			}
			printf("%c", aff);
		}
		printf("\n");
	}
}

int main(){

	
	int i = 0, j = 0, k = 0;
	struct Vent vent;
	vent.force = 0;
	strcpy(vent.direction, "N");
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
		if ((childpid = fork()) == 0){
			close(sockfd);
			while (1){
				for (int d = 0; d<oc.nbrBateaux; d++)
				{
					// Calculer la vitesse finale
					int vf = GetVitesseFinale(oc.bateau[d], vent);
					// Mettre à jour les coordonnées du bateau
					UpdateCordonne(oc, vf, d);
					// Si le bateau dépsse les limite de l'ocean le faire apparaitre dans l'autre bout de l'ocean
					OceanInfinie(oc.bateau[d],oc);
				}
				recv(newSocket, buffer, 1024, 0);

				if (strcmp(buffer, ":exit") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}
				else if (strcmp(buffer, ":1") == 0){
					char vitesse[5];
					bzero(bufferResponse, sizeof(bufferResponse));
					strcpy(bufferResponse, "Veuiller saisir la vitesse: \n");
					send(newSocket, bufferResponse, strlen(bufferResponse), 0);
					recv(newSocket, vitesse, 5, 0);
					printf("Vitesse : %s\n", vitesse);
					for (i = 0; i < oc.nbrBateaux; i++){
						struct Bateau bateauTmp;
						bateauTmp = oc.bateau[i];

						if (strcmp(bateauTmp.identifiant, inet_ntoa(newAddr.sin_addr)) == 0)
							oc.bateau[i].vitesse = atoi(vitesse);
					}
					strcpy(bufferResponse, ":menu");
				}
				else
				if (strcmp(buffer, ":2") == 0){
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
				else
				if (strcmp(buffer, ":3") == 0){
					bzero(bufferResponse, sizeof(bufferResponse));
					
					printOcean(oc);
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
