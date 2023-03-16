//
// Created by Dali on 16/03/2023.
//

#include "../headers/main.h"

//void remplictab(char **tab){
//    tab[0] = malloc(sizeof(char ) * strlen("--help"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--version"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--login"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--signup"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--user"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--password"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--help"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--help"));
//    strcpy(tab[0],"--help");
//    tab[0] = malloc(sizeof(char ) * strlen("--help"));
//    strcpy(tab[0],"--help");
//
//    tab[1] = "--version";
//    tab[2] = "--login";
//    tab[3] = "--signup";
//    tab[4] = "--user";
//    tab[5] = "--password";
//    tab[6] = "--sql";
//    tab[7] = "--format";
//    tab[8] = NULL;
//}

void my_remplistab(char **tab) {
    tab[0] = my_strcpy("-h");
    tab[1] = my_strcpy("-v");
    tab[2] = my_strcpy("-l");
    tab[3] = my_strcpy("-su");
    tab[4] = my_strcpy("-u");
    tab[5] = my_strcpy("-p");
    tab[6] = my_strcpy("-s");
    tab[7] = my_strcpy("-f");
    tab[8] = NULL;

}

int
main(int argc, char **argv) {
    char *cflagstr[] = {
            "--help",
            "--version",
            "--login",
            "--signup",
            "--user",
            "--password",
            "--sql",
            "--format",
            NULL
    };

    char *flagstr[] = {
            "-h",
            "-v",
            "-l",
            "-su",
            "-u",
            "-p",
            "-s",
            "-f",
            NULL
    };

    starter_flags(argc, argv, cflagstr, flagstr);

    return 0;
}
