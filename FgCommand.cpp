//
// Created by daniel on 13/04/2020.
//

#include <iostream>
#include <wait.h>
#include "FgCommand.h"

void FgCommand::execute(std::vector<string> args, State &s) {
    if(args.size() > 2) {
        s.ilegal_command = true;
        return;
    }
    unsigned int p_idx = -1;
    if(args.size() == 2)
        p_idx = std::stoi(args[2]);
    if((int)p_idx > (int)s.p_state.size()){
        s.ilegal_command = true;
        return;
    }
    s.refresh_jobs();
    unsigned int i = 0;
    if((int)p_idx == -1){
        p_idx = find_latest_job_idx(s.p_state);
    }
    Job j;
    for (const auto& kv : s.p_state) {
        if(i==p_idx)
            j=kv.second;
        i++;
    }
    move_to_fg(j);
}

unsigned int FgCommand::find_latest_job_idx(const map<int, Job>& jobs) {
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

void FgCommand::move_to_fg(const Job & j) {
    std::cout << j.name << std::endl;
    kill(j.pid, SIGCONT);
    int status = 0;
    waitpid(j.pid, &status, 0);
}
