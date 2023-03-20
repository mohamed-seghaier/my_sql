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
            "POUR CRÉER UN COMPTE, ENTRER LA COMMANDE SUIVANTE\n"
            "\t\tmy_bdd -i \"username\" \"password\"\n\n"
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
    my_printf("my_bdd Ver %s.\n", SQLVERSION);
    exit(0);
}

void
loginer(t_line *t) {

    if (checkUser(t)) my_printf("Hello %s !\n", t->usr.user);
    else
    {
        my_printf("User does not exist. Good Bye.\n");
        exit(0);
    }
}

void
userer(t_line *t) {
    for (int i = 0; t->args.argc > i; i += 1)
    {
        if (strcmp(t->args.argv[i], "--user") == 0 || strcmp(t->args.argv[i], "-u") == 0)
        {
            for (int j = 0; t->flags.shortFlags[j] != NULL || t->flags.longFlags[j] != NULL; j += 1)
            {
                if (i + 1 >= t->args.argc ||
                    strcmp(t->args.argv[i + 1], t->flags.longFlags[j]) == 0 ||
                    strcmp(t->args.argv[i + 1], t->flags.shortFlags[j]) == 0
                        ) {

                    exit_bad_args();
                } else
                {
                        t->usr.user = my_strcpy(t->args.argv[i+1]);
                    break;
                }
            }
        }
    }
}

void
passworder(t_line *t) {
    for (int i = 0; t->args.argc > i; i += 1)
    {
        if (strcmp(t->args.argv[i], "--password") == 0 || strcmp(t->args.argv[i], "-p") == 0)
        {
            for (int j = 0; t->flags.shortFlags[j] != NULL || t->flags.longFlags[j] != NULL; j += 1)
            {
                if (i + 1 >= t->args.argc ||
                    strcmp(t->args.argv[i + 1], t->flags.longFlags[j]) == 0 ||
                    strcmp(t->args.argv[i + 1], t->flags.shortFlags[j]) == 0
                    ) {
                    exit_bad_args();
                } else
                {
                    t->usr.password = my_strcpy(t->args.argv[i+1]);
                    break;
                }
            }
        }
    }
}

void
sqler(t_line *t) {
    char **tab2 = NULL;
    for (int i = 0; t->args.argc > i; i += 1)
    {
        if (strcmp(t->args.argv[i], "--sql") == 0 || strcmp(t->args.argv[i], "-s") == 0)
        {
            for (int j = 0; t->flags.shortFlags[j] != NULL || t->flags.longFlags[j] != NULL; j += 1)
            {
                if (i + 1 >= t->args.argc ||
                    strcmp(t->args.argv[i + 1], t->flags.longFlags[j]) == 0 ||
                    strcmp(t->args.argv[i + 1], t->flags.shortFlags[j]) == 0 ||
                    !checkUser(t))
                {
                    exit_bad_args();
                } else
                {
                    tab2 = my_strtab(t->args.argv[i + 1], '(');
                    if (tablen(tab2) > 1) {
                        t->cmd.sqlcmd = my_strtab(tab2[1], ',');
                        for (int e = 0; t->cmd.sqlcmd[e]; e+=1){
                            my_printf("before = %s\n", t->cmd.sqlcmd[e]);
                            char *tmp = epurStrForSqlCmd(t->cmd.sqlcmd[e]);
                            t->cmd.sqlcmd[e] = tmp;
                        }
                        for (int e = 0; t->cmd.sqlcmd[e]; e+=1) ;

                    }
                    t->cmd.tab = my_strtab(t->args.argv[i + 1], ' ');
                    treatSqlCommand(t);
                    exit(0);
                }
            }
        }
    }
}



void
formater(t_line *t) {
    my_printf("format\n");
}

void
signin(t_line *t){
    for (int i = 0; t->args.argc > i; i += 1)
    {
        if (strcmp(t->args.argv[i], "--signin") == 0 || strcmp(t->args.argv[i], "-i") == 0)
        {
            for (int j = 0; t->flags.shortFlags[j] != NULL || t->flags.longFlags[j] != NULL; j += 1)
            {
                if (i + 2 >= t->args.argc ||
                    strcmp(t->args.argv[i + 1], t->flags.longFlags[j]) == 0 ||
                    strcmp(t->args.argv[i + 1], t->flags.shortFlags[j]) == 0
                        ) {

                    exit_bad_args();
                } else
                {
                    t->usr.user = t->args.argv[i + 1];
                    t->usr.password = t->args.argv[i + 2];
                    newUser(t);
                    break;
                }
            }
        }
    }
}

void
newUser(t_line *t)
{

    FILE *file;
    if ((file = fopen(USERINFOFILE, "w")) == NULL
    || fprintf(file, "%s", my_strcat(my_strcat(t->usr.user, ","), t->usr.password)) != my_strlen(my_strcat(my_strcat(t->usr.user, ","), t->usr.password)))
    {
        my_printerror("Error occurred on registering.\n");
    }
    fclose(file);

}

bool
checkUser(t_line *t)
{
    int fd;
    struct stat st;
    char *file = NULL;
    char **lines = NULL;

    if ((fd = open(USERINFOFILE, O_RDWR))== -1
    || (fstat(fd, &st) == -1)
    || (file = malloc(sizeof (char) * st.st_size + 1)) == NULL
    || read(fd, file, st.st_size) == -1
    || (lines = my_strtab(file, ',')) == NULL)
    {
        my_printerror("Error occurred on login.\n");
    }

    if (t->usr.user != NULL
    && t->usr.password != NULL
    && lines[0] != NULL
    && lines[1] != NULL)
    {
        if (strcmp(t->usr.user, lines[0]) == 0
        && strcmp(t->usr.password, lines[1]) == 0)
        {
            return true;
        }
    }
    close(fd);
    return false;
}



