//
// Created by os on 17.4.2020.
//

#include <iostream>
#include <unistd.h>
#include "signals.h"
#include "State.h"
#include "Terminal.h"


void SignalHandler::INT_handler() {
    SignalHandler& s = getInstance();
    if(s.stateInstance->fg_pid == -1)return;
    kill(s.stateInstance->fg_pid, SIGINT);
    std::cout<<"\n"<<"smash > "<<"signal SIGINT was sent to pid "<<s.stateInstance->fg_pid<<"\n";


}

void SignalHandler::STP_handler() {
    SignalHandler& s = getInstance();
    if(s.stateInstance->fg_pid == -1)return;
    kill((pid_t)s.stateInstance->fg_pid, SIGSTOP);
    std::cout<<"\n"<<"smash > "<<"signal SIGTSTP was sent to pid "<<s.stateInstance->fg_pid<<"\n";
    Job j;
    j.pid  = s.stateInstance->fg_pid;
    j.name = s.stateInstance->cur_command;
    j.stopped = true;
    j.time_in = time(nullptr);
    s.stateInstance->p_state.push_back(j);
    s.stateInstance->cur_command = {};
    s.stateInstance->fg_pid      = -1;
}