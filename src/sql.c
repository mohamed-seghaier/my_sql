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

void    cmdInsert(t_line *t)
{

    my_printf("insert\n");
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
            my_printf("Database successfully switched to %s.\n", t->cmd.tab[1]);
        }
        else {
            t->usr.databaseSelected = str;
            my_printf("Database %s successfully selected.\n", t->cmd.tab[1]);
        }

    }
    else
    {
        my_printerror("Error on database selection.\n");
    }
}

void    cmdSelect(t_line *t)
{

    my_printf("select\n");
}


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
createTable(t_line *t)
{
    int i = 0;
    char *str = NULL;
    char **stab = NULL;


    for (i = 0; t->cmd.tab[i]; i += 1) my_printf("%s\n",t->cmd.tab[i]);
    if (i < 3) exit_bad_args();
//    str = epurStrForSqlCmd(t->cmd.tab[4]);
//    my_printf("%s\n",str);
//    stab = my_strtab(str, ',');
//    for (int j = 0; stab[j]; j += 1) my_printf("%s\n", stab[j]);


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

void
showTables(t_line *t)
{
    my_printf("i show tables\n");
}