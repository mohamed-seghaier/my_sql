//
// Created by Dali on 16/03/2023.
//

#include "../headers/core.h"



void
helper(t_line *t) {
    my_printf(
            "///\t\tMY_BDD \t\t\\\\\\\n\n"
            "AUTHORS :\n"
            "\t MAUREL Nans && SEGHAIER Mohamed-Ali\n\n\n"
            "\tLes identifiants sont aussi enregistrés dans un fichier, permettre de tester les identifiants sans devoir faire de requêtes SQL. (option -l permet de tester les identifiants)\n"
            "\tmybdd -u user -p password -l\n"
            "\t\t> Login success\n\n"
            "\tListe des commandes :\n"
            "\tCREATE DATABASE database\n"
            "\tSHOW DATABASES\n"
            "\tCREATE TABLE table (col1, col2, col3)\n"
            "\tSHOW TABLES\n"
            "\tDESCRIBE TABLE\n"
            "\tINSERT INTO table VALUES (value1, value2, value3)\n"
            "\tSELECT * FROM table\n");
    exit(0);
}

void
versioner(t_line *t) {
    my_printf("version\n");
}

void
loginer(t_line *t) {
    my_printf("login\n");
}

void
userer(t_line *t) {
    my_printf("user\n");
}

void
passworder(t_line *t) {
    my_printf("passworder\n");

    //    for (int i = 0; i <= t->t->argc; i += 1) {
//        if (strcmp(t->t->argv[i], "password") == 0 ||
//                strcmp(t->t->argv[i], "--p") == 0)
//        {
//            my_printf("a");
//            for (int j = 0; t->t->flagstr[j] != NULL; j += 1 )
//            {
//                my_printf("a");
//                if (i + 1 > t->t->argc ||
//                    strcmp(t->t->argv[i + 1], t->t->flagstr[j]) == 0 ||
//                    strcmp(t->t->argv[i + 1], t->t->flagstr[j]) == 0
//                    )
//                {
//
//                    my_printerror("Calling password flag without giving password.\n");
//                    exit(-42);
//                }
//
//            }
//        }
//    }
}

void
sqler(t_line *t) {
    my_printf("sql\n");
}

void
formater(t_line *t) {
    my_printf("format\n");
}

void
signup(t_line *t){
    my_printf("registred\n");
}




