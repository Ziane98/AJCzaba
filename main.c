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
    T_annuaire annuaire;

    memset(annuaire.listNom, '\0', sizeof(annuaire.listNom));
    memset(annuaire.listNum, '\0', sizeof(annuaire.listNum));
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
           printContacts(&annuaire);
           navMenu = 42;
        }

        
        if (navMenu == 1)
        {
            printf("entre un nom a chercher :\n");
            scanf(" %s",search);
            int result = chercheContacts(search,&annuaire);
            if (result) printf("\n le num de %s est : %s\n",annuaire.listNom[result-1],annuaire.listNum[result-1]);
            else printf("Contacted non repertorier\n");
            navMenu = 42;
        }

        if (navMenu == 2)
        {
            printf("\n entrez le nom du contact à ajouter : ");
            scanf(" %s",contact);
            if (chercheContacts(contact,&annuaire)){
                printf("\ncontact deja Existe (%d  %s)",chercheContacts(contact,&annuaire),contact);
            }
            else{

            printf("\nentrez son numéro de téléphone :");
            scanf(" %s",num);

            addContacts(contact,num,&annuaire);
            
            }
            navMenu = 42;
        }


            if (navMenu == 3)
        {
            printf("entre un nom a supprimer :\n");
            scanf(" %s",search);
            int result = chercheContacts(search,&annuaire);
            if (result){
                dellContact(search,&annuaire);
                printContacts(&annuaire);
            }
            else printf("Contacted non repertorier\n");
            navMenu = 42;
        }
    }
}
