//
// Created by igor de paula on 4/8/2020.
//

//
// Created by igor de paula on 4/4/2020.
//
/*	smash.c
main file. This file contains the main function of smash
*******************************************************************/


#include <cstring>
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
#include "JobsCommand.h"
#include "KillCommand.h"
#include "FgCommand.h"
#include "signals.h"
//
#define MAX_LINE_SIZE 80
#define MAXARGS 20

using std::map;


//**************************************************************************************
// function name: main
// Description: main function of smash. get command from user and calls command functions
//**************************************************************************************
int main(int argc, char *argv[])
{
    
    std::map<std::string,Command*> commands = {{"pwd",new PWDcommand},
                                               {"cd", new cdCommand},
                                               {"history",new histCOMMAND},
                                               {"showpid",new shpdCOMMAND},
                                               {"cp", new cpCOMMAND},
                                               {"diff",new difCOMMAND},
                                               {"jobs", new JobsCommand},
                                               {"kill", new KillCommand},
                                               {"fg", new ContCommand(ContType::FG)},
                                               {"bg", new ContCommand(ContType::BG)},
                                               {"quit", new quitCOMMAND}
    }; // built in command map

    Terminal term(commands); // generate terminal
    SignalHandler& sig = SignalHandler::getInstance();
    sig.stateInstance = &term.get_state();



    if(signal(SIGTSTP , reinterpret_cast<__sighandler_t>(SignalHandler::STP_handler)) == SIG_ERR) {
        perror("smash error: failed to set ctrl-Z handler");
    }
    if(signal(SIGINT , reinterpret_cast<__sighandler_t>(SignalHandler::INT_handler)) == SIG_ERR) {
        perror("smash error: failed to set ctrl-C handler");
    }

    term.run(); // run it

    return 0;
}



