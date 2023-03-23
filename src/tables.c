//
// Created by Dali on 23/03/2023.
//

#include "../headers/sql.h"


void    cmdInsert(t_line *t) {
    int i = 0;
    FILE *file;
    char *str = NULL;
    struct stat sb;
    char *temp;
    char **fileContent;

    for (i = 0; t->cmd.tab[i]; i += 1) {
        t->cmd.tab[i] = epurStrForSqlCmd(t->cmd.tab[i]);
    }

    for (i = 0; t->cmd.tab[i]; i++);
    if (!t->usr.databaseSelected) my_printerror("Please select a database by using the USE function.\n");
    else {
        if (i > 4)
            str = my_strcat(my_strcat(t->usr.databaseSelected, "/"), t->cmd.tab[2]);
        if (stat(str, &sb) == 0
            && S_ISDIR(sb.st_mode)) {
            for (int j = 4, c = 0; t->cmd.tab[j]; j += 1, c += 1) {
                char **tmp = my_strtab(t->cmd.tab[j], ':');
                if ((file = fopen(my_strcat(my_strcat(str, "/"), tmp[0]), "r")) != NULL) {
                    stat(my_strcat(my_strcat(str, "/"), tmp[0]), &sb);
                    if (strcmp(tmp[0], "id") == 0
                        && (temp = malloc(sizeof(char) * sb.st_size)) != NULL
                        && (read(file->_file, temp, sb.st_size)) != 0
                        && (fileContent = my_strtab(temp, ';')) != NULL) {
                        for (int idx = 0; fileContent[idx]; idx += 1) {
                            if (strcmp(fileContent[idx], tmp[1]) == 0) {
                                my_printerror("Error occurred on table insertion.\n");
                                exit(-42);
                            }
                        }
                        fclose(file);
                    }
                }
                fclose(file);
                if ((file = fopen(my_strcat(my_strcat(str, "/"), tmp[0]), "a")) != NULL){
                    fprintf(file, "%s;", tmp[1]);
                    fclose(file);
                }
            }
            my_printf("Insertion success\n", t->cmd.tab[2]);
        } else {
            my_printerror("Error occurred on table insertion.\n");
            exit(-42);
        }
    }
}
//    if (i > 4
//        || t->usr.databaseSelectedName
//        || strcmp(t->cmd.tab[1], "INTO") == 0
//        || strcmp(t->cmd.tab[3], "VALUES") == 0
//            )
//    {
//
//    }
//    else
//    {
//        my_printf("Error occurred on inserting values into %s\n", t->usr.databaseSelectedName);
//        exit(-42);
//    }
//}

void
remplifile(char *filepath, char *str)
{
    FILE *f = fopen(filepath, "a");
    fprintf(f, "%s;\n", str);
}
void
createTable(t_line *t)
{
    int i = 0;
    struct stat sb;
    char *str = NULL;
    FILE *file;

    for (i = 0; t->cmd.tab[i]; i++);
    if (!t->usr.databaseSelected) my_printerror("Please select a database by using the USE function.\n");
    else {
        if (i >= 3
            && stat(t->usr.databaseSelected, &sb) == 0
            && S_ISDIR(sb.st_mode)
            && stat(my_strcat(my_strcat(t->usr.databaseSelected, "/"), t->cmd.tab[2]), &sb) != 0
                ) {
            str = my_strcat(my_strcat(t->usr.databaseSelected, "/"), t->cmd.tab[2]);
            mkdir(str, 0777);
            for (int j = 3, c = 0; t->cmd.tab[j]; j += 1, c += 1) {
                t->cmd.tab[j] = epurStrForSqlCmd(t->cmd.tab[j]);
                char **tmp = my_strtab(t->cmd.tab[j], ':');
                if ((file = fopen(my_strcat(my_strcat(str, "/"), tmp[0]),"w")) == NULL
                    || !fprintf(file, "%s;", tmp[1])) {
                    my_printerror("Error occurred on table creation.\n");
                    exit(-42);
                }
                my_printf("Table %s successfully created\n", t->cmd.tab[2]);
                fclose(file);
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
