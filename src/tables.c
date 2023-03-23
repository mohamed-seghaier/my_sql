//
// Created by Dali on 23/03/2023.
//

#include "../headers/sql.h"



void
createTable(t_line *t)
{
    int i = 0;
    for (i = 0; t->cmd.tab[i]; i++);
    struct stat sb;
    char *str = NULL;
    FILE *file;


    if (!t->usr.databaseSelected) my_printerror("Please select a database by using the USE function.\n");
    else {
        if (i >= 3
            && stat(t->usr.databaseSelected, &sb) == 0
            && S_ISDIR(sb.st_mode)
            && stat(my_strcat(my_strcat(t->usr.databaseSelected, "/"), t->cmd.tab[2]), &sb) != 0
                ) {
            str = my_strcat(my_strcat(t->usr.databaseSelected, "/"), t->cmd.tab[2]);
            mkdir(str, 0777);
            my_printf("Table %s successfully created\n", t->cmd.tab[2]);
            for (int j = 3; t->cmd.tab[j]; j += 1) {
                t->cmd.tab[j] = epurStrForSqlCmd(t->cmd.tab[j]);

                printf("%s\n", t->cmd.tab[j]);
            }
        } else {
            my_printerror("Error occurred on table creation.\n");
            exit(-42);
        }
    }

}



void
showTables(t_line *t)
{
    DIR *d;
    struct dirent *dir;
    if (!t->usr.databaseSelected) my_printerror("Please select a database by using the USE function.\n");
    else {
        showTablesHeader(t);
        d = opendir(t->usr.databaseSelected);
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
        showTablesFooter();
    }
}


void
showTablesHeader(t_line *t)
{
    write(1, "+",1);
    for (int i = 0; i < 18; i += 1)
        my_printf("-");
    write(1, "+",1);
    my_printf("\n|Tables in %s", t->usr.databaseSelectedName);
    for (int i = 0; i < 20 - (my_strlen("|Tables in  ") + my_strlen(t->usr.databaseSelectedName)); i += 1)
        my_printf(" ");
    my_printf("|\n+");
    for (int i = 0; i < 18; i += 1)
        my_printf("-");
    write(1, "+\n",2);
}

void
showTablesFooter()
{
    write(1, "+",1);
    for (int i = 0; i < 18; i += 1)
        my_printf("-");
    write(1, "+\n",2);
}
