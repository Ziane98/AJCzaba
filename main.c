#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"



// void printContacts (char **listNom , char **listNum);

// int chercheContacts (char shearch , char **listNom , char **listNum);

// void addContacts(char contact, char **listNom , char **listNum);

// void dellContact(char contact, char **listNom , char **listNum);

void main(){
    char search[100];
    char contact[100];
    char num[100];
    char listNom[100][100];
    char listNum[100][100];

    memset(listNom, '\0', sizeof(listNom));
    memset(listNum, '\0', sizeof(listNum));
    memset(search, '\0', sizeof(search));

    int navMenu = 42;
    while (navMenu != -1)
    {
        while (navMenu>3 || navMenu<-1)
        {
            printf("---------------------------------\n");
            printf("   -----------MENU-----------\n");
            printf("---------------------------------\n");
            printf("Quitter : -1 \n");
            printf("Voir l'annuaire : 0 \n");
            printf("Chercher un contact : 1 \n");
            printf("Ajouter un contact : 2 \n");
            printf("Supprimer un contact : 3 \n");
            scanf("%d",&navMenu);

        }

        if (navMenu == 0)
        {
           printContacts(listNom ,listNum);
           navMenu = 42;
        }

        
        if (navMenu == 1)
        {
            printf("entre un nom a chercher :\n");
            scanf(" %s",search);
            int result = chercheContacts(search,listNom,listNum);
            if (result) printf("\n le num de %s est : %s\n",listNom[result-1],listNum[result-1]);
            else printf("Contacted non repertorier\n");
            navMenu = 42;
        }

        if (navMenu == 2)
        {
            printf("\n entrez le nom du contact à ajouter : ");
            scanf(" %s",contact);
            if (chercheContacts(contact,listNom,listNum)){
                printf("\ncontact deja Existe (%d  %s)",chercheContacts(contact,listNom,listNum),contact);
            }
            else{

            printf("\nentrez son numéro de téléphone :");
            scanf(" %s",num);

            addContacts(contact,num, listNom , listNum);
            
            }
            navMenu = 42;
        }


            if (navMenu == 3)
        {
            printf("entre un nom a supprimer :\n");
            scanf(" %s",search);
            int result = chercheContacts(search,listNom,listNum);
            if (result){
                dellContact(search,listNom,listNum);
                printContacts(listNom ,listNum);
            }
            else printf("Contacted non repertorier\n");
            navMenu = 42;
        }
    }
}
