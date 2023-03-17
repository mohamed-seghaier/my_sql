//
// Created by Dali on 16/03/2023.
//

#include "../headers/core.h"


void
initTlineStruct(int argc, char **argv, char **shortFlags, char **longFlags, t_line *t)
{
    t->args.argc = argc;
    t->args.argv = argv;
    t->flags.longFlags = longFlags;
    t->flags.shortFlags = shortFlags;
    t->usr.user = NULL;
    t->usr.password = NULL;
}

void initArgPointerTab(ftab_t *argList)
{
    argList[HELP] = &helper;
    argList[VERSION] = &versioner;
    argList[LOGIN] = &loginer;
    argList[SIGNIN] = &signin;
    argList[USER] = &userer;
    argList[PASSWORD] = &passworder;
    argList[SQL] = &sqler;
    argList[FORMAT] = &formater;
    argList[FTAB_NULL] = NULL;
}

void
starter_flags(int argc, char **argv, char **shortFlags, char **longFlags) {

    t_line toto;
    bool isValid = false;
    initTlineStruct(argc, argv, shortFlags, longFlags, &toto);

    ftab_t argList[FTAB_SIZE];
    initArgPointerTab(&*argList);

    for (int i = 0; argc > i; i += 1)
    {
        for (int j = 0; shortFlags[j] != NULL || longFlags[j] != NULL; j += 1)
        {
            if (strcmp(argv[i], shortFlags[j]) == 0
            || strcmp(argv[i], longFlags[j]) == 0
            )
            {
                (*argList[j])(&toto);
                isValid = true;
            }
        }
    }
    if (isValid == false)
    {
        exit_bad_args();
    }
    else core(&toto);
    exit(0);
}

void
exit_bad_args() {
    my_printerror("Bad argument\n");
    exit(-42);
}

void
core(t_line *t) {
    char *str = "";
    while ("DALI")
    {
        my_printf(">");
        if ((str = get_next_line(0)) == NULL)
        {
            my_printf("Good Bye !\n");
            exit(0);
        }
        my_printf("%s\n", str);
        if ( strcmp(str, "exit") == 0) {
            my_printf("Good Bye !\n");
            exit(0);
        }
    }
    my_printf("Bye =\n");
    exit(0);
}
