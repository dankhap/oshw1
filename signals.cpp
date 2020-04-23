//
// Created by os on 17.4.2020.
//

#include <iostream>
#include <unistd.h>
#include "signals.h"
#include "State.h"
#include "Terminal.h"


void SignalHandler::INT_handler() {
    extern int fg_pid;
    std::cout<<"sending control c signal to process"<<std::endl;
    //SignalHandler& s = getInstance();
    if(fg_pid == -1)return;
    kill(fg_pid, SIGINT);


}

void SignalHandler::STP_handler() {
    extern int fg_pid;
    std::cout<<"sending control z signal to process"<<std::endl;
    SignalHandler& s = getInstance();
    if(fg_pid == -1)return;
    kill(fg_pid, SIGTSTP);
    Job j;
    j.pid  = fg_pid;
    j.name = s.stateInstance->cur_command;
    j.stopped = true;
    j.time_in = time(nullptr);
    s.stateInstance->p_state.insert({j.pid,j});
    s.stateInstance->cur_command = {};
    fg_pid      = -1;


}