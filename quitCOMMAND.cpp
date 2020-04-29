//
// Created by os on 12.4.2020.
//

#include "quitCOMMAND.h"
void quitCOMMAND::execute(std::vector<string> args, State &S) {
    if(args.size() > 1 ) {
        if(args.size() == 2 && !args[1].compare("kill")){
            // deal with kill commnad
            return; // just here for regular quit testing
        }
        S.ilegal_command = true;
    }
    S.exit_request = true;
}
