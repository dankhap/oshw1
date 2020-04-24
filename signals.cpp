//
// Created by os on 17.4.2020.
//

#include <iostream>
#include <unistd.h>
#include "signals.h"
#include "State.h"
#include "Terminal.h"


void SignalHandler::INT_handler() {
    std::cout<<"sending control cc signal to process"<<std::endl;
    SignalHandler& s = getInstance();
    if(s.stateInstance->fg_pid == -1)return;
    kill(s.stateInstance->fg_pid, SIGINT);
    std::cout<<"sending control cc signal to process"<<std::endl;


}

void SignalHandler::STP_handler() {
    std::cout<<"sending control zz signal to process"<<std::endl;
    SignalHandler& s = getInstance();
    if(s.stateInstance->fg_pid == -1)return;
    std::cout<<"sending control zz signal to process"<<std::endl;
    kill(s.stateInstance->fg_pid, SIGTSTP);
    Job j;
    j.pid  = s.stateInstance->fg_pid;
    j.name = s.stateInstance->cur_command;
    j.stopped = true;
    j.time_in = time(nullptr);
    s.stateInstance->p_state.insert({j.pid,j});
    s.stateInstance->cur_command = {};
    s.stateInstance->fg_pid      = -1;


}