//
// Created by daniel on 12/04/2020.
//

#include <iostream>
#include <ctime>
#include "JobsCommand.h"
using std::string;

void JobsCommand::execute(std::vector<string> args, State &s) {
    if(args.size() > 1){
        s.ilegal_command = true;
        return;
    }
    int i = 1; // jobs array counter bug fixed
    s.refresh_jobs();
    for (auto &job : s.p_state) {
        string lbl = job.stopped ? "(Stopped)" : "";
        double elapsed_time = difftime(job.time_in, time(nullptr));
        std::cout << "[" << i << "] " << job.name << " : " <<  job.pid <<
            " " << elapsed_time << " secs " << lbl << std::endl;
        i++;
    }
}
