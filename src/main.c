//
// Created by Dali on 16/03/2023.
//

#include "../headers/main.h"

int
main(int argc, char **argv) {
    char *cflagstr[] = {
            "--help",
            "--version",
            "--login",
            "--signin",
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
            "-i",
            "-u",
            "-p",
            "-s",
            "-f",
            NULL
    };

    starter_flags(argc, argv, cflagstr, flagstr);

    return 0;
}
