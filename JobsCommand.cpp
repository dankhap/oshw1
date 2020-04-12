//
// Created by daniel on 12/04/2020.
//

#include <iostream>
#include <csignal>
#include <ctime>
#include "JobsCommand.h"

void JobsCommand::execute(std::vector<string> args, State &s) {
    if(args.size() > 1){
        s.ilegal_command = true;
        return;
    }
    int i = 0;
    vector<int> dead_jobs;
    for (std::pair<int, Job> job : s.p_state) {
        if(kill(job.second.pid, 0) == -1 && errno == ESRCH) {
            dead_jobs.push_back(job.second.pid);
            continue;
        }
        double elapsed_time = difftime(job.second.time_in, time(nullptr));
        std::cout << "[" << i << "] " << job.second.name << " : " <<  job.first << " " << elapsed_time << " secs" << std::endl;
        i++;
    }
    for(int pid: dead_jobs) {
        s.p_state.erase(pid);
    }
}
