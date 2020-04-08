//
// Created by igor de paula on 4/8/2020.
//

//
// Created by igor de paula on 4/4/2020.
//
/*	smash.c
main file. This file contains the main function of smash
*******************************************************************/
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "commands.h"
#include "signals.h"
#include "Command.h"
#include "map"
#include "Terminal.h"
#include "PWDcommand.h"
#define MAX_LINE_SIZE 80
#define MAXARGS 20

using std::map;


//**************************************************************************************
// function name: main
// Description: main function of smash. get command from user and calls command functions
//**************************************************************************************
int main(int argc, char *argv[])
{

    std::map<std::string,Command*> commands = {{"pwd",new PWDcommand}}; // built in command map
    Terminal term(commands);   // generate terminal
    term.run(); // run it


    return 0;
}



