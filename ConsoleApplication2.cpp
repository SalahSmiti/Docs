// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
// Inclut les en-têtes standards
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

#include <stdlib.h>
#include <string.h>




#include "stdafx.h"

	
#define LGL 100       /* Longueur max d'une ligne de fichier   */


int _tmain(int argc, _TCHAR* argv[])
{
	char ligne[LGL];
	char entryPath[1000];
	char resultPath[1000];

	char descriptionFileName[LGL], imageFileName[LGL];
	FILE *descriptionFile, *imageFile;
	unsigned int n, i, j,k, nbColonneImage, nbLigneImage;
	int nbLigne = 0;
	char caractere;
	char matrice[LGL][LGL] = { { "" } };

	/* Saisie du nom de fichier a lire */
	
	printf("Nom du fichier a lire: ");
	fgets(ligne, LGL, stdin);
	entryPath[0] = '\0';
	resultPath[0] = '\0';
	sscanf(ligne, "%s", descriptionFileName);
	strcat(entryPath, "C:\\development\\");
	strcat(entryPath, descriptionFileName);
	while (strcmp(descriptionFileName, "fin") != 0)
	{

		descriptionFile = fopen(entryPath, "r");
		if (descriptionFile == NULL) {
			printf("Le fichier %s n'existe pas\n", descriptionFileName);
			break;
		}
		else {
			fgets(imageFileName, LGL, descriptionFile);
			/* Lecture du fichier entree ligne par ligne */
			while (!feof(descriptionFile)) {
				if (nbLigne == 0)
				{

				}
				else if (nbLigne == 1)
				{
					nbLigneImage = atoi(&ligne[0]);
					nbColonneImage = atoi(&ligne[2]);

				}
				else
				{
					i = atoi(&ligne[2]);
					j = atoi(&ligne[4]);
					caractere = ligne[0];
					matrice[i][j] = caractere;
				}
				nbLigne++;
				fgets(ligne, LGL, descriptionFile);
			}
			fclose(descriptionFile);
			strcat(resultPath, "C:\\development\\");
			strcat(resultPath, imageFileName);
			for (k = 0; k < strlen(resultPath); k++) { 
				if (resultPath[k] == '\n') {
					resultPath[k] = ' ';
				}
			}
			imageFile = fopen(resultPath, "w");
			if (imageFile == NULL) {
				printf("Erreur de creation de fichier %s \n", imageFileName);
			}
			else {
				for (i = 0; i < nbLigneImage; i++)
				{
					for (j = 0; j < nbColonneImage; j++)
					{
						char* input = &matrice[i][j];
						fputs(input, imageFile);
						fputs(" ", imageFile);
					}
					fputs("\n", imageFile);
				}

			}
			fclose(imageFile);
		}
		printf("Nom du fichier a lire: ");
		fgets(ligne, LGL, stdin);
		entryPath[0] = '\0';
		resultPath[0] = '\0';
		sscanf(ligne, "%s", descriptionFileName);
		strcat(entryPath, "C:\\development\\");
		strcat(entryPath, descriptionFileName);
	}

	
	system("pause");
}

void loadData(string filename, vector<float> &vols, vector<float> &vals){
	
	std::ifstream file(filename);
	// declare file stream: http://www.cplusplus.com/reference/iostream/ifstream/
	string value;
	getline(file, value, '\n'); //skip first line

	float minval = 0.0f;
	float minvol = 0;
	float maxval = 0.0f;
	float maxvol = 0;
	while (file.good()) {
		// TO DO

		vals.push_back(adjclose);
		vols.push_back(volume);
	}

	// on rajoute 2 fausses valeurs a la fin que l'on affichera pas .. mais qu'on utilisera pour normaliser !
	vals.push_back(minval);
	vals.push_back(maxval);
	vols.push_back(minvol);
	vols.push_back(maxvol);
}


vector<string> load_f(string file) {
	vector<string> text;

	ifstream ifs(file);
	string buffer, str_line;

	int brackets = 0;
	str_line = "";

	while (getline(ifs, buffer)) {
		buffer = Trim(buffer);
		size_t s = buffer.find_first_of("()");

		if (s == string::npos) str_line += "" + buffer;
		else {
			while (s != string::npos) {
				str_line += "" + buffer.substr(0, s + 1);
				brackets += (buffer[s] == '(' ? 1 : -1);

				if (brackets == 0) {
					text.push_back(str_line);
					str_line = "";
				}

				buffer = buffer.substr(s + 1);
				s = buffer.find_first_of("()");
			}
		}
	}

	return text;
}