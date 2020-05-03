//
// Created by os on 17.4.2020.
//

#include <iostream>
#include <csignal>
#include "signals.h"
#include "State.h"

/**
 * handler for contrl C on smash
 */
void SignalHandler::INT_handler() {
    SignalHandler& s = getInstance(); // make instance os terminal state to get fg pid
    if(s.stateInstance->fg_pid == -1)return;
    kill(s.stateInstance->fg_pid, SIGINT); // send signal
    std::cout<<"\n"<<"smash > "<<"signal SIGINT was sent to pid "<<s.stateInstance->fg_pid<<"\n";

}
 /**
  * handle control Z function
  */
void SignalHandler::STP_handler() {
    SignalHandler& s = getInstance(); // get instance of terminal state
    if(s.stateInstance->fg_pid == -1)return;
    kill((pid_t)s.stateInstance->fg_pid, SIGSTOP);  // stop job we wand to stop
    std::cout<<"\n"<<"smash > "<<"signal SIGTSTP was sent to pid "<<s.stateInstance->fg_pid<<"\n";
    Job j;
    j.pid  = s.stateInstance->fg_pid;  // save job paramaters
    j.name = s.stateInstance->cur_command;
    j.stopped = true;
    j.time_in = time(nullptr);
    s.stateInstance->p_state.push_back(j);
    s.stateInstance->cur_command = {};
    s.stateInstance->fg_pid      = -1;
}