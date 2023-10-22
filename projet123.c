#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date
{
    int jour;
    char mois[100];
    int annee;
} Date;

typedef struct Livres
{
    int id;
    char titre[100];
    Date DateEdition;
    char genre[100];
} Livres;

struct Livres livre;

void ajouter();
void afficher();
void supprimer();
void modifier();
void rechercher();
void quitter();

int main()
{

    int choix;
    char reponse;
    do
    {
    	system("cls");
        printf("\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
        printf("\n $$ Pour ajouter un livre ------------------------1 $$");
        printf("\n $$ Pour afficher la liste des livres-------------2 $$");
        printf("\n $$ Pour supprimer un livre-----------------------3 $$");
        printf("\n $$ Pour modifier un livre------------------------4 $$");
        printf("\n $$ Pour rechercher un livre----------------------5 $$");
        printf("\n $$ Pour quitter le programme---------------------6 $$");
        printf("\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
        printf("\n\n Donner votre choix S.V.P  -----------------------: ");
        scanf("%d", &choix);

        switch (choix){
        case 1:
            ajouter();
            break;

        case 2:
            afficher();
            break;

        case 3:
            supprimer();
            break;

        case 4:
            modifier();
            break;

        case 5:
            rechercher();
            break;

        case 6:
            quitter();
            break;

        default:
            printf("Choix non disponible.");
        }
        
        printf("\n Voulez vous continuez o/n : ");
        scanf("%s", &reponse);
    } while (reponse == 'O' || reponse == 'o');
}
/*---------------------------------fonction ajouter-------------------------*/
void ajouter()
{
    FILE *F;
    F = fopen("Livres.txt", "a");
    printf("Entre l'id du livre : ");
    scanf("%d", &livre.id);
    printf("titre du livre :  ");
    scanf("%s", &livre.titre);
    printf("entrer le jour d'edition :");
    scanf("%d", &livre.DateEdition.jour);
    printf("entrer le mois d'edition :");
    scanf("%s", &livre.DateEdition.mois);
    printf("entrer l'annee d'edition :");
    scanf("%d", &livre.DateEdition.annee);
    printf("entre le genre de livre : ");
    scanf("%s", &livre.genre);
    

    fprintf(F, "%d %s %d %s %d %s\n", livre.id, livre.titre, livre.DateEdition.jour, livre.DateEdition.mois, livre.DateEdition.annee, livre.genre);


    fclose(F);
}
/*------------------------------fonction afficher---------------------*/
void afficher()
{
    FILE *F;
    F = fopen("Livres.txt", "r");
    char buffer[500];

    if (F == NULL)
    {
        printf("le fichier est vide");
        exit(1);
    }

    printf("la liste des auteurs est : \n\n");
    printf("id\t titre\t genre\t DateEdition\n");
    printf("----------------------------------------------------\n");


    while (fgets(buffer, 500, F) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(F);
}
/*-------------------------fonction supprimer------------------------*/
void supprimer()
{
    int value;
    printf("\n\nEntrer l'id livre que vous voulez supprimer : ");
    scanf("%d", &value);
    FILE *F2, *F;
    F = fopen("Livres.txt", "r");
    F2 = fopen("livre.txt", "a");
    
 	while (!feof(F))
 	{
        fscanf(F, "%d %s %d %s %d %s\n", &livre.id, &livre.titre, &livre.DateEdition.jour, &livre.DateEdition.mois,  &livre.DateEdition.annee, &livre.genre);
        
        
        if (value != livre.id)
        {
            fprintf(F2, "%d %s %d %s %d %s\n", livre.id, livre.titre, livre.DateEdition.jour, livre.DateEdition.mois,  livre.DateEdition.annee, livre.genre);
				              
        }
    }
    fclose(F2);
    fclose(F);
    remove("Livres.txt");
    rename("livre.txt", "Livres.txt");
    printf("\t \t \t Supression reussite. ");
}
/*-------------------------fonction quitter--------------- */
void quitter()
{
    exit(1);
}
/*-------------------------fonction modifier-------------*/
void modifier()
{
    int id;
    FILE *F2, *F;
    F = fopen("Livres.txt", "r");
    F2 = fopen("livre.txt", "a");
        	printf("\n\nEntrer l'id livre que vous voulez modifier:");
	        scanf("%d", &id);
    while (!feof(F))
    {
    	fscanf(F, "%d %s %d %s %d %s\n", &livre.id, &livre.titre, &livre.DateEdition.jour, &livre.DateEdition.mois,   &livre.DateEdition.annee, &livre.genre);
    	
    	
    	
        if (id == livre.id)
        {

	        livre.id == id;
	        printf("\nEntrez les nouveaux information du livre \n");
	        printf("Le titre : ");
	        scanf("%s", &livre.titre);
	        printf("Le jour : ");
	        scanf("%d", &livre.DateEdition.jour);
	        printf("Le mois : ");
	        scanf("%s", &livre.DateEdition.mois);
	        printf("L'annee : ");
	        scanf("%d", &livre.DateEdition.annee);
	        printf("Le genre : ");
	        scanf("%s", &livre.genre);   
        }               
		fprintf(F2, "%d %s %d %s %d %s\n", livre.id, livre.titre, livre.DateEdition.jour, livre.DateEdition.mois,     livre.DateEdition.annee, livre.genre);
		
		
		
		
		
    }
    
    
    
        fclose(F2);
        fclose(F);
        remove("Livres.txt");
        rename("livre.txt", "Livres.txt");
        if(id == livre.id){
			printf("\nModification reussi avec succes !\n\n");        	
		}else{
				printf("\nError livre introuvoable !\n\n");  
		}
}
/*----------------------------fonction rechercher-------------------------*/
void rechercher()
{
    int id;
    int existe = 0;
    FILE *F, *F2;
    F = fopen("Livres.txt", "r");
    printf("\n\n\t \t \t Entrer l'id du livre  a cherche:");
    scanf("%d", &id);
    
    while (!feof(F))
    {
        fscanf(F, "%d %s %d %s %d %s\n", &livre.id, &livre.titre, &livre.DateEdition.jour, &livre.DateEdition.mois,   &livre.DateEdition.annee, &livre.genre);
        
        
        if (livre.id == id)
        {
        	int existe = 1;
        }
    }
    
    
    if (existe = 1)
    {
        printf("\nEntrez les informations du livre touvre \n");
        printf("ID\t TITRE\t DATE D'EDITION\t GENRE\n");               
		printf("%d\t %s\t %d/%s/%d\t\t %s\n", livre.id, livre.titre, livre.DateEdition.jour, livre.DateEdition.mois,   livre.DateEdition.annee, livre.genre);
			
    }
    else
    {
        printf("\nLe livre n'est pas disponible !\n");
    }

    
}
