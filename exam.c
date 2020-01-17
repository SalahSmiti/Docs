#include<stdio.h>
#include<conio.h>
#include<string.h>


struct LettreMorse {
char lettre;
char morse[7];
};

int main()
{
    LettreMorse Alphabet[36] =
    {
        {'A',".-"},
        {'B',"-..."},
        {'C',"-.-."},
        {'D',"-.."},
        {'E',"."},
        {'F',"..-."},
        {'G',"--."},
        {'H',"...."},
        {'I',".."},
        {'J',".---"},
        {'K',"-.-"},
        {'L',".-.."},
        {'M',"--"},
        {'N',"-."},
        {'O',"---"},
        {'P',".--."},
        {'Q',"--.-"},
        {'R',".-."},
        {'S',"..."},
        {'T',"-"},
        {'U',"..-"},
        {'V',"...-"},
        {'W',".--"},
        {'X',"-..-"},
        {'Y',"-.--"},
        {'Z',"--.."},
        {'0',"-----"},
        {'1',".----"},
        {'2',"..---"},
        {'3',"...--"},
        {'4',"....-"},
        {'5',"....."},
        {'6',"-...."},
        {'7',"--..."},
        {'8',"---.."},
        {'9',"---."}
    };
    
    char MaChaineATranscoder[30] = "";
    menu(MaChaineATranscoder);
    return 0;
}

void menu(char c[])
{
printf(" Vous desirez :\n\n");
printf("\t1 : Coder un texte en morse\n\n");
printf("\t2 : Decoder un texte morse\n\n");
printf("\t3 : Quitter le programme\n\n\n");
printf("\t\t\tFaites votre choix...\n");


 switch(getch())
 {
 case'1':SaisirUneChaineATranscoder(c);
 			clrscr();
         printf("\n voici - %s - code en morse\n\n",c);
         affiche_morse(c);break;
 case'2':saisie_m(c);getch();break;
 case'3':help(m,t);getch();break;
 case'4':*k=0;break;
 default:printf("\a");
 }
}

void SaisirUneChaineATranscoder(char c[])
{
clrscr();
printf("\t\t\t* Codage d'un texte en morse *\n\n\n");
printf("\tVeuillez saisir votre phrase a coder en morse (200 caracteres max)\n\n  ->  ");
gets(c);
}


void LettreVersMorse(char caractere)
{
    int i,j=0;
    for(j=0;j<37;j++)
    {
    
        if(caractere==Alphabet[i].lettre)
        {
            i = 1;
            cprintf("%s",Alphabet[i].LettreMorse);
        }
    }
    if(i == 0)
        printf("%c",'?');

}

void affiche_morse(char c[])
{
    int i = 0;
    
    for(i=0;i<taille_mot(c);i++)
    {
    LettreVersMorse(c[i]);
    
    }
    getch();
}

int taille_mot(char c[])
{
int i=0;
while(c[i]!='\0'){i++;}
return i;
}
