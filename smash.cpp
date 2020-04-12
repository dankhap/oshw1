//
// Created by igor de paula on 4/8/2020.
//

//
// Created by igor de paula on 4/4/2020.
//
/*	smash.c
main file. This file contains the main function of smash
*******************************************************************/


#include <string.h>
#include <map>

#include "Command.h"
#include "Terminal.h"
#include "PWDcommand.h"
#include "cdCommand.h"
#include "histCOMMAND.h"
#include "shpdCOMMAND.h"
#include "cpCOMMAND.h"
#include "difCOMMAND.h"
#include "quitCOMMAND.h"
#define MAX_LINE_SIZE 80
#define MAXARGS 20

using std::map;


//**************************************************************************************
// function name: main
// Description: main function of smash. get command from user and calls command functions
//**************************************************************************************
int main(int argc, char *argv[])
{

    std::map<std::string,Command*> commands = {{"pwd",new PWDcommand},{"cd", new cdCommand},{"history",new histCOMMAND}
    ,{"showpid",new shpdCOMMAND},{"cp", new cpCOMMAND},{"diff",new difCOMMAND},
                                               {"quit",new quitCOMMAND}}; // built in command map
    Terminal term(commands);   // generate terminal
    term.run(); // run it

    return 0;
}



