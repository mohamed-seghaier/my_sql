//
// Created by Nans Maurel on 16/03/2023.
//

#include "headers/main.h"

#define LINE_SIZE 4096

char *remplitab(char *dest, char *src, int j, char sep) {
    int idx = 0;

    for ( idx = 0 ; src[j] != sep && src[j] ; idx += 1, j += 1 )
        dest[idx] = src[j];
    dest[idx] = 0;

    return (dest);
}

int my_eolen(char *str, char sep) {
    int idx_len = 0;
    int idx_str = 0;

    for ( idx_len = 0 ; str[idx_str] ; idx_str += 1)
        str[idx_str] == sep ? idx_len += 1 : 0;

    return (idx_len);
}

char **my_strtab(char *str, char sep) {

    char **tab;
    int idx_tab;
    int i = 0;
    int len = 0;
    int j = 0;
    int toto = my_eolen(str, sep) + sizeof(char *);

    if ((tab = malloc(sizeof(char *) * toto)) == NULL)
        return (NULL);

    for ( idx_tab = 0 ; idx_tab < my_eolen(str, sep) + 1 ; idx_tab += 1 ) {

        for ( ; str[i] != sep && str[i] ; i += 1, len += 1);
        if ((tab[idx_tab] = malloc(sizeof(char) * len + 1)) == NULL)
            return (NULL);

        remplitab(tab[idx_tab], str, j, sep);

        for ( ; str[j] != sep && str[j] ; j += 1 );

        len = 0;
        i += 1;
        j += 1;
    }

    tab[idx_tab] = NULL;
    return (tab);
}

int createTable(char *tableName, char **col) {

    char *filePath = my_strcat(my_strcat("./data/", tableName), ".csv");
    FILE * file = NULL;

    if ( (file = fopen(filePath, "w")) == NULL ) {
        printf("Erreur a la creation du fichier\n");
        exit(0);
    }
    for (int i = 0; col[i] != NULL ; ++i) {
        if( (fputs(col[i], file)) == EOF ) {
            printf("Erreur a l'ecriture du fichier\n");
            exit(0);
        }
        fputc(',', file);
    }

    printf("le fichier %s a bien ete ecrit\n", tableName);
    return fclose(file);
}

int readTable(char *tableName, char ***columns, char ***lines) {

    char *filePath = my_strcat(my_strcat("./data/", tableName), ".csv");
    FILE * file = NULL;

    if ( (file = fopen(filePath, "r")) == NULL ) {
        printf("Erreur a l'ouvertre du fichier\n");
        exit(0);
    }

    printf("Lecture du fichier\n");
    char *line = malloc(LINE_SIZE);

    printf("Lecture des colones\n");
    line = fgets(line, LINE_SIZE, file);
    columns = my_strtab(line, ',');

    return fclose(file);
}