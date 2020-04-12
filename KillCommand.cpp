//
// Created by daniel on 12/04/2020.
//

#include <iostream>
#include <csignal>
#include "KillCommand.h"

void KillCommand::execute(std::vector<string> args, State &s) {
    if(args.size() != 3){
        s.ilegal_command = true;
        return;
    }
    if(args[1][0] != '-'){
        s.ilegal_command = true;
        return;
    }
    int pid = std::stoi(args[2]);
    int sig = std::stoi(args[1].erase(0, 1));
    if(!s.p_state.count(pid)) {
        std::cout << "smash error: > kill " << pid << "- job does not exist" << std::endl;
        return;
    }
    if(kill(pid, sig) == -1) {
        std::cout << "smash error: > kill " << pid << "- cannot send signal" << std::endl;
    }
    std::cout << "DEBUG - kill successfully: " << pid << std::endl;
    //s.p_state.erase(pid);
}
