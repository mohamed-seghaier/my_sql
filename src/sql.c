//
// Created by Dali on 17/03/2023.
//

#include "../headers/sql.h"

void
initCmdPointerTab(ftab_t *cmdList)
{
    cmdList[CMD_CREATE] = &cmdCreate;
    cmdList[CMD_SHOW] = &cmdShow;
    cmdList[CMD_DESCRIBE] = &cmdDescribe;
    cmdList[CMD_INSERT] = &cmdInsert;
    cmdList[CMD_SELECT] = &cmdSelect;
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
            NULL
    };

    ftab_t cmdFlag[CMDTAB_SIZE];
    initCmdPointerTab(&*cmdFlag);
    for (int i = 0; cmdList[i] != NULL; i += 1)
    {
        if (strcmp(t->cmd.tab[0], cmdList[i]) == 0)
        {
            (*cmdFlag[i])(t);
        }
    }}

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
    createCmdFlag[2] = NULL;

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

void    cmdSelect(t_line *t)
{

    my_printf("select\n");
}


void
createDatabase(t_line *t)
{
    my_printf("database created\n");
}
void
createTable(t_line *t)
{
    int i = 0;
    char *str = NULL;
    char **stab = NULL;


    for (i = 0; t->cmd.tab[i]; i += 1);
    if (i < 3) exit_bad_args();
//    str = epurStrForSqlCmd(t->cmd.tab[4]);
//    my_printf("%s\n",str);
//    stab = my_strtab(str, ',');
//    for (int j = 0; stab[j]; j += 1) my_printf("%s\n", stab[j]);


}
void
createUser(t_line *t)
{
    my_printf("user created\n");
}

void
showDatabases(t_line *t)
{
    my_printf("i show databases\n");
}

void
showTables(t_line *t)
{
    my_printf("i show tables\n");
}