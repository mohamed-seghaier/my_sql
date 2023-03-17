//
// Created by Dali on 16/03/2023.
//

#include "headers/main.h"

int main(int argc, char **argv) {

    //char *myArray[] = {"Nom", "Prenom", "age", "taille", "poid"};
    char **myArray = malloc(sizeof(char *) * 5+1);
    myArray[0] = my_strcpy("Nom");
    myArray[1] = my_strcpy("Prenom");
    myArray[2] = my_strcpy("age");
    myArray[3] = my_strcpy("taille");
    myArray[4] = my_strcpy("poid");
    myArray[5] = NULL;

    createTable("Person", myArray);

    char **colArray = malloc(sizeof (char *) * 1+1);
    colArray[0] = NULL;

    char ***linesArray = malloc(sizeof (char *) * (1+1) * (1+1));
    linesArray[0] = NULL;
    linesArray[1] = NULL;

    readTable("Person", &colArray, linesArray);

    int i = 0;
    while (colArray[i] != NULL) {
        printf(" %s |", colArray[i]);
        i++;
    }
    printf("\n");
    return 0;
}
