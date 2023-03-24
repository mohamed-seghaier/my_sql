//
// Created by Dali on 17/03/2023.
//

#include "../headers/sql.h"

void
initCmdirectorPointerTab(ftab_t *cmdList)
{
    cmdList[CMD_CREATE] = &cmdCreate;
    cmdList[CMD_SHOW] = &cmdShow;
    cmdList[CMD_DESCRIBE] = &cmdDescribe;
    cmdList[CMD_INSERT] = &cmdInsert;
    cmdList[CMD_SELECT] = &cmdSelect;
    cmdList[CMD_USE] = &cmdUse;
    cmdList[CMDTAB_NULL] = NULL;
}

void
treatSqlCommand(t_line *t)
{
    char *cmdList[] = {
            "CREATE",
            "SHOW",
            "DESCRIBE",
            "INSERT",
            "SELECT",
            "USE",
            NULL
    };

    ftab_t cmdFlag[CMDTAB_SIZE];
    initCmdirectorPointerTab(&*cmdFlag);
    for (int i = 0; cmdList[i] != NULL; i += 1)
    {
        if (strcmp(t->cmd.tab[0], cmdList[i]) == 0)
        {
            (*cmdFlag[i])(t);
        }
    }
    return;
}

void    cmdCreate(t_line *t)
{
    char *createCmdList[] = {
            "DATABASE",
            "TABLE",
            "USER",
            NULL
    };
    ftab_t createCmdFlag[4];
    createCmdFlag[0] = &createDatabase;
    createCmdFlag[1] = &createTable;
    createCmdFlag[2] = &createUser;
    createCmdFlag[3] = NULL;

    for (int i = 0; createCmdList[i]; i += 1)
    {
        if (strcmp(createCmdList[i], t->cmd.tab[1]) == 0)
        {
            (*createCmdFlag[i])(*&t);
        }
    }
}

void    cmdShow(t_line *t)
{
    char *showCmdList[] = {
            "DATABASES",
            "TABLES",
            NULL
    };
    ftab_t showCmdFlag[3];
    showCmdFlag[0] = &showDatabases;
    showCmdFlag[1] = &showTables;
    showCmdFlag[2] = NULL;

    for (int i = 0; showCmdList[i]; i += 1)
    {
        if (strcmp(showCmdList[i], t->cmd.tab[1]) == 0)
        {
            (*showCmdFlag[i])(*&t);
        }
    }}

void    cmdDescribe(t_line *t)
{
    my_printf("describe\n");
}

bool thoseColumnsExist(char  *str, char **tab, int fromPos)
{
    DIR *table_dir = opendir(str);
    int cpt = 0;
    int tabSize = 0;
    if (table_dir == NULL) {
        printf("Error on select function.\n");
        return false;
    }
    for (int i = 1; strcmp(tab[i], "FROM") != 0; i += 1, tabSize += 1);

    struct dirent *entry;
    while ((entry = readdir(table_dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            for (int i = 1; strcmp(tab[i], "FROM") != 0; i++) {
                if (strcmp(tab[i], entry->d_name) == 0) {
                    cpt += 1;
                }
            }
        }
    }
    return (cpt == tabSize || tabSize < cpt);
}

void    cmdSelect(t_line *t)
{
    int i = 0;
    FILE *file;
    DIR *table_dir;
    struct dirent *dir;
    char *tableSelected = NULL;
    int fromPos = 0;
    struct stat sb;
    char *temp;
    char *filename;

    for (i = 0; t->cmd.tab[i]; i += 1) {
        t->cmd.tab[i] = epurStrForSqlCmd(t->cmd.tab[i]);
    }

    for (i = 0; t->cmd.tab[i]; i++)if (strcmp(t->cmd.tab[i], "FROM") == 0) fromPos = i;
    if (strcmp(t->cmd.tab[1], "*") == 0) showStar(t);
    else if (!t->usr.databaseSelected) my_printerror("Please select a database by using the USE function.\n");
    else {
        if (i > 3 && t->cmd.tab[fromPos + 1]){
            tableSelected = my_strcat(my_strcat(t->usr.databaseSelected, "/"), t->cmd.tab[fromPos + 1]);
            if (!thoseColumnsExist(tableSelected, t->cmd.tab, fromPos))
            {
                printf("Error on select function333.\n");
                exit (-42);
            } else{
                table_dir = opendir(tableSelected);
                while ((dir = readdir(table_dir)) != NULL) {
                    filename = my_strcat(tableSelected, "/");
                    file = fopen(my_strcat(filename, dir->d_name), "r");
                    stat(dir->d_name, &sb);
                    temp = malloc(sizeof (char ) * sb.st_size + 1);
                    read(file->_file, temp,sb.st_size);
                    for (int i = 1; strcmp(t->cmd.tab[i], "FROM") != 0; i++) {
                        epurStrForSelectCmd(temp);
                        if (strcmp(t->cmd.tab[i], dir->d_name) == 0) {
                            my_printf("Column : ** %s ** \n%s\n", dir->d_name, temp);
                        }
                    }
                    fclose(file);
                    free(temp);
                }
            }
        }
    }
}

void
epurStrForSelectCmd(char *str)
{
    for (int i = 0; str[i] ; ++i) {
        if (str[i] == ';') str[i] = '\n';
    }
}

void
showStar(t_line *t)
{
    FILE *file;
    DIR *table_dir;
    struct dirent *dir;
    char *tableSelected;
    int fromPos = 0;
    char *filename;
    struct stat sb;
    char *temp;


    for (int i = 0; t->cmd.tab[i]; i++)if (strcmp(t->cmd.tab[i], "FROM") == 0) fromPos = i;

    tableSelected = my_strcat(my_strcat(t->usr.databaseSelected, "/"), t->cmd.tab[fromPos + 1]);

    table_dir = opendir(tableSelected);
    while ((dir = readdir(table_dir)) != NULL) {
        filename = my_strcat(tableSelected, "/");
        file = fopen(my_strcat(filename, dir->d_name), "r");
        stat(dir->d_name, &sb);
        temp = malloc(sizeof (char ) * sb.st_size + 1);
        read(file->_file, temp,sb.st_size);
        for (int i = 1; strcmp(t->cmd.tab[i], "FROM") != 0; i++) {
            epurStrForSelectCmd(temp);
            if (strcmp(dir->d_name, ".") != 0
            && strcmp(dir->d_name, "..") != 0)
                my_printf("Column : ** %s ** \n%s\n", dir->d_name, temp);
        }
        fclose(file);
        free(temp);
    }
}



void
createUser(t_line *t)
{
    t->usr.user = NULL;
    t->usr.password = NULL;
    struct stat sb;
    if (stat("./users", &sb) == 0 && S_ISDIR(sb.st_mode)) {
        createUserDir(t);
    } else {
        my_printerror("Error occurred on user creation.\n");
        exit(-42);
    }
}

void
createUserDir(t_line *t)
{
    int i = 0;
    char *user = NULL;
    FILE *file;
    struct stat sb;

    for (i = 0;t->cmd.tab[i]; i++);
    if (i != 6) goto errorOnCreateUser;

    if (strcmp(t->cmd.tab[2], "user") != 0
    && strcmp(t->cmd.tab[2], "USER") != 0
    && strcmp(t->cmd.tab[2], "u") != 0) goto errorOnCreateUser;
    else user = my_strcat("./users/", t->cmd.tab[3]);
    if (stat(user, &sb) == 0) goto errorOnCreateUser;
    else {
        mkdir(user, 0777);
    }

    if (strcmp(t->cmd.tab[4], "password") != 0
        && strcmp(t->cmd.tab[4], "PASSWORD") != 0
        && strcmp(t->cmd.tab[4], "p") != 0) goto errorOnCreateUser;
    else {
        user = my_strcat(user, "/");
        if ((file = fopen(my_strcat(user, "password"), "w")) == NULL
            || fprintf(file, "%s", t->cmd.tab[5]) != my_strlen(t->cmd.tab[5]))goto errorOnCreateUser;
        fclose(file);
        return;
    }

    errorOnCreateUser:
    my_printerror("Error occurred on user creation.\n");
    exit(-42);
}

