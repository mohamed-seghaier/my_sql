//
// Created by Dali on 23/03/2023.
//

#include "../headers/sql.h"

void
createDatabase(t_line *t)
{
    int i = 0;
    for (i = 0; t->cmd.tab[i]; i++);
    char *str = my_strcat("./users/", t->usr.user);
    struct stat sb;

    if (i >= 3
        && stat(str, &sb) == 0
        && S_ISDIR(sb.st_mode)
        && stat(my_strcat(my_strcat(str, "/"), t->cmd.tab[2]), &sb) != 0
            ) {
        str = my_strcat(my_strcat(str, "/"), t->cmd.tab[2]);
        mkdir(str, 0777);
        my_printf("Database \" %s \" successfully created\n", t->cmd.tab[2]);
    } else {
        my_printerror("Error occurred on database creation.\n");
        exit(-42);
    }
}


void
showDatabases(t_line *t)
{
    char *username = my_strcat("./users/", t->usr.user);
    DIR *d;
    struct dirent *dir;

    showDatabaseHeader();
    d = opendir(username);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, ".") != 0
                && strcmp(dir->d_name, "..") != 0
                && dir->d_type == DT_DIR) {
                my_printf("|%s", dir->d_name);
                for (int i = 0; i < 18 - my_strlen(dir->d_name); i += 1)
                    my_printf(" ");
                my_printf("|\n");
            }
        }
        closedir(d);
    }
    showDatabaseFooter();
}


void
showDatabaseHeader()
{
    write(1, "+",1);
    for (int i = 0; i < 18; i += 1)
        my_printf("-");
    write(1, "+",1);
    my_printf("\n|Database");
    for (int i = 0; i < 20 - my_strlen("|Database "); i += 1)
        my_printf(" ");
    my_printf("|\n+");
    for (int i = 0; i < 18; i += 1)
        my_printf("-");
    write(1, "+\n",2);
}
void
showDatabaseFooter()
{
    write(1, "+",1);
    for (int i = 0; i < 18; i += 1)
        my_printf("-");
    write(1, "+\n",2);
}

void    cmdUse(t_line *t)
{
    char *str = my_strcat("./users/", t->usr.user);
    int i;
    struct stat sb;

    for (i = 0; t->cmd.tab[i]; i++);

    if (i >= 2
        && stat(str, &sb) == 0
        && S_ISDIR(sb.st_mode)
        && stat(my_strcat(my_strcat(str, "/"), t->cmd.tab[1]), &sb) == 0)
    {
        str = my_strcat(my_strcat(str, "/"), t->cmd.tab[1]);
        if (t->usr.databaseSelected) {
            t->usr.databaseSelected = str;
            t->usr.databaseSelectedName = t->cmd.tab[1];
            my_printf("Database successfully switched to %s.\n", t->cmd.tab[1]);
        }
        else {
            t->usr.databaseSelected = str;
            t->usr.databaseSelectedName = t->cmd.tab[1];
            my_printf("Database %s successfully selected.\n", t->cmd.tab[1]);
        }

    }
    else
    {
        my_printerror("Error on database selection.\n");
    }
}
