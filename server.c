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

Déroulement du projet
Le projet est divisé en deux parties, chaque partie faisant l'objet d'une remise de rapport. Des commentaires vous seront faits à l'issue de la première partie. Ces commentaires sont à prendre en compte pour la deuxième partie.
Lors de la première partie, vous devez développer la partie algorithmique de votre programme. Lors de la deuxième partie, il faut corriger les problèmes détectés par votre encadrant et développer l'interface graphique. Attention : l'interface graphique ne doit pas apparaître lors de la première partie !

Les principales étapes du projet sont les suivantes : 
• Choix du projet => du 1 mars au 7 mars 2019 (12:15h)
• Première séance encadrée => 07 mars 2019 (Groupes 5-8) et le 08 mars 2019 (Groupes 1-4). Cette première séance sert à valider l'ensemble des projets choisis. Elle est programmée après 2Cr de TD (C2C3)
• Remise du rapport de la première partie => 08 avril  2019 à midi dernier délai
• La deuxième séance encadrée => 11 avril en C2C3 (pour les groupes 5-8) ou 12 avril en c5C7 pour les groupes  1-4.
• Troisième séance encadrée =>  09 mai (groupes 3, 4), 10 mai (groupes 7, 8), 16 mai (groupes 1,2) et 17 mai (groupes ou 2 mai 2018. Cette séance réservée pour l'interface graphique IHM.
• Remise du rapport de la deuxième partie => 07 juin 2019 à 13h00 dernier délai
• Soutenance :  12 juin 2019 (journée) et 13 et 14 juin (matin)  (sem 24)
													      
													      
Attention les figures imposées servent de base pour la notation.

Les notes d'un binôme peuvent être différentes si il apparait une différence de travail notoire.

Les figures imposées peuvent être différentes d'un sujet à un autres et d'un binôme à un autre. Il y a minimum 7 figures imposées par sujet dont 4 sont communes pour l’ensemble des sujets :
1. Factorisation du code : au moins trois modules et noms de classes distincts
2. Documentation et commentaires du code
3. Tests unitaires : (au moins 4 méthodes avec au moins 2 cas testés par méthode)
4. Création d'un type d’objet (classe) : il devra contenir au moins deux  variables d'instance
Pour chaque sujet proposé, les étudiant ont le libre choix de prendre trois autres figures imposées parmis les figures suivantes : 
• Héritage au moins entre deux types créés
• Héritage depuis un type intégré (hors en IHM)
• Fonction récursive (dans le cœur du projet)
• Structure de données dynamique (autre que celles intégrées à Python)
• Lecture/ écriture de fichiers : (type de fichier adapté – pas de « pickle »).
• Accès BDD (serveur BDD à valider avec l’encadrant
• Utilisation de calcul vectoriel (évaluer le gain en termes de temps d’exécution).
• Autres : autres figured peuvent être précisées selon le sujet
Pour la 1ère étape :
1. réaliser votre découpage de votre programme en classe en s'appuyant sur un diagramme de classes (pour générer un diagramme de classe
2. Respecter les 4 première figures imposés. 
3. Respecter les autres figures imposées (au minimum 3 figures supplémentaires) 
4. un jeu de tests unitaires (toutes les classes intermédiaires doivent être testées).
La manipulation de fichiers texte pourra être utile pour certains sujets.

• Pour la 2ème étape, en plus des figures imposées pour le 1ère étape :
1. Intégrer les corrections de la première partie.
2. Interface graphique (PyQt5 est recommandée)
Note : Il est indispensable que le développement de votre projet soit fait sous Python 3.6

