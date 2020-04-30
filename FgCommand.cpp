//
// Created by daniel on 13/04/2020.
//

#include <iostream>
#include <wait.h>
#include "FgCommand.h"
#include "signals.h"

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
        p_idx = find_latest_job_idx(s.p_state) + 1;
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

    Job* j;
    unsigned int i = 1;

    for ( auto& kv : s.p_state) {
        if(i==p_idx)
            j= &(kv.second);
        i++;
    }
    continue_job(j, type == ContType::FG);
}

unsigned int ContCommand::find_latest_job_idx(const map<int, Job>& jobs) {
    time_t t = time(nullptr);
    double diff = 0;
    int i = 0;
    int latest_pidx = -1;

    //find the latest job - with the smallest time diff from now
    //return the index, not the pid
    for (const auto& kv : jobs) {
        double d = difftime(t,kv.second.time_in);
        if(diff == 0) {
            diff = d;
            latest_pidx = i;
        }else{
            if(diff>d){
                diff = d;
                latest_pidx = i;
            }
        }
        i++;
    }
    return latest_pidx;
}

void ContCommand::continue_job( Job*  j, bool wait) {
    if(!wait && !j->stopped) {
        std::cerr << "job is not stopped, cannot continue!" << std::endl;
        return;
    }
    std::cout << j->name << std::endl;
    kill(j->pid, SIGCONT);
    std::cout << "smash > signal SIGCONT was sent to pid " << j->pid<< std::endl;
    j->stopped = false;
    int status = 0;
    if(wait){
        SignalHandler& sig = SignalHandler::getInstance();
        sig.stateInstance->fg_pid = j->pid;    // for signal handler if signal is sent to this process
        waitpid(j->pid, &status, WUNTRACED);  // to catch signal properly
    }
    
}
