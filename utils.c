#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printContacts(char listNom[100][100] , char listNum[100][100]){
        int i = 0;
        printf("---LISTE DE CONTACTS---\n");

        while (listNom[i][0] != '\0'){

            printf("%s  |   %s\n",listNom[i],listNum[i]);
            i++;
        }
}

int chercheContacts (char shearch[100] , char listNom[100][100] , char listNum[100][100]){
    int i = 0;
    int j = 0;
    while (listNom[i][0] != '\0'){
        while (listNom[i][j]==shearch[j])
        {
            if ((listNom[i][j] == '\0') &&  (shearch[j]=='\0')){
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


void addContacts(char contact[100], char num[100], char listNom[100][100] , char listNum[100][100]){

    int i=0;
    int j=0;
    while (listNom[i][0] != '\0') i++;

    strcpy(listNum[i],num);

    j=0;

    strcpy(listNom[i],contact);
}

void dellContact(char contact[100], char listNom[100][100] , char listNum[100][100]){
    int existe = chercheContacts(contact,listNom,listNum);
    if (existe){
        existe -= 1;
        while (listNom[existe+1][0]){
            strcpy(listNom[existe],listNom[existe+1]);
            strcpy(listNum[existe],listNum[existe+1]);
            existe++;
        }
        strcpy(listNom[existe],listNom[existe+1]);
        strcpy(listNum[existe],listNum[existe+1]);
        
    }
    else{
        printf("\ncontact non Existe");
    }
}