//
// Created by daniel on 12/04/2020.
//

#include <iostream>
#include <csignal>
#include <ctime>
#include <wait.h>
#include "JobsCommand.h"

void JobsCommand::execute(std::vector<string> args, State &s) {
    if(args.size() > 1){
        s.ilegal_command = true;
        return;
    }
    int i = 1; // jobs array counter bug fixed
    s.refresh_jobs();
    for (std::pair<int, Job> job : s.p_state) {
        string lbl = job.second.stopped ? "(Stopped)" : "";
        double elapsed_time = difftime(job.second.time_in, time(nullptr));
        std::cout << "[" << i << "] " << job.second.name << " : " <<  job.first <<
            " " << elapsed_time << " secs " << lbl << std::endl;
        i++;
    }
}
