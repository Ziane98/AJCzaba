#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct structAnnuaire
{
    char listNom[100][100];
    char listNum[100][100];
} T_annuaire;

void printContacts(T_annuaire *annuaire){
        int i = 0;
        printf("---LISTE DE CONTACTS---\n");

        while (annuaire->listNom[i][0] != '\0'){

            printf("%s  |   %s\n",annuaire->listNom[i],annuaire->listNum[i]);
            i++;
        }
}

int chercheContacts (char shearch[100] , T_annuaire *annuaire){
    int i = 0;
    int j = 0;
    while (annuaire->listNom[i][0] != '\0'){
        while (annuaire->listNom[i][j]==shearch[j])
        {
            if ((annuaire->listNom[i][j] == '\0') &&  (shearch[j]=='\0')){
                printf("%d",i+1);
                return i+1;
            }
           j++;
        }
        j=0;
        i++;
        }
    return 0;
}


void addContacts(char contact[100], char num[100], T_annuaire *annuaire){

    int i=0;
    int j=0;
    while (annuaire->listNom[i][0] != '\0') i++;

    strcpy(annuaire->listNum[i],num);

    j=0;

    strcpy(annuaire->listNom[i],contact);
}

void dellContact(char contact[100], T_annuaire *annuaire){
    int existe = chercheContacts(contact,annuaire);
    if (existe){
        existe -= 1;
        while (annuaire->listNom[existe+1][0]){
            strcpy(annuaire->listNom[existe],annuaire->listNom[existe+1]);
            strcpy(annuaire->listNum[existe],annuaire->listNum[existe+1]);
            existe++;
        }
        strcpy(annuaire->listNom[existe],annuaire->listNom[existe+1]);
        strcpy(annuaire->listNum[existe],annuaire->listNum[existe+1]);
        
    }
    else{
        printf("\ncontact non Existe");
    }
}