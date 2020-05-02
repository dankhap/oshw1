//
// Created by daniel on 13/04/2020.
//

#include <iostream>
#include <wait.h>
#include "FgCommand.h"

using std::string;
using std::vector;

ContCommand::ContCommand(ContType type) : type(type) {}

void ContCommand::execute(std::vector<string> args, State &s) {
    if(args.size() > 2) {
        s.ilegal_command = true;
        return;
    }
    unsigned int p_idx = 1;
    if(args.size() == 2) {
        try {
            p_idx = std::stoi(args[1]);
        } catch (const std::invalid_argument &e) {
            s.ilegal_command = true;
            return;
        }
    } else {
        p_idx = s.p_state.size();
    }
    if(s.p_state.empty()){
        std::cerr << "no active jobs" << std::endl;
        return;
    }

    s.refresh_jobs();
    if((int)p_idx > (int)s.p_state.size() or (int)p_idx < 1){
        std::cerr << "no such job" << std::endl;
        return;
    }

    continue_job(s.p_state[p_idx - 1], type == ContType::FG, s);
}

void ContCommand::continue_job( Job&  j, bool wait, State& s) {
    if(!wait && !j.stopped) {
        std::cerr << "job is not stopped, cannot continue!" << std::endl;
        return;
    }
    std::cout << j.name << std::endl;
    kill(j.pid, SIGCONT);
    std::cout << "smash > signal SIGCONT was sent to pid " << j.pid<< std::endl;
    j.stopped = false;
    int status = 0;
    if(wait){
        s.fg_pid = j.pid;    // for signal handler if signal is sent to this process
        waitpid(j.pid, &status, WUNTRACED);  // to catch signal properly
    }
    
}
