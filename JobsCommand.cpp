//
// Created by daniel on 12/04/2020.
//

#include <iostream>
#include "JobsCommand.h"

void JobsCommand::execute(std::vector<string> args, State &s) {
    if(args.size() > 1){
        s.ilegal_command = true;
        return;
    }
    int i = 0;
    for (std::pair<int, Job> job : s.p_state) {
        int elapsed_time = 0;
        std::cout << "[" << i << "] " << job.second.name << " : " <<  job.first << " " << elapsed_time << " secs" << std::endl;
        i++;
    }
}
