//
// Created by os on 12.4.2020.
//

#include <csignal>
#include <unistd.h>
#include <iostream>
#include <wait.h>
#include "quitCOMMAND.h"
using std::string;


void quitCOMMAND::execute(std::vector<string> args, State &s) {
    if(args.size() > 1 ) {
        if (args.size() == 2 && args[1] == "kill") {
            s.refresh_jobs();
            send_all_children(s, SIGTERM);
            s.refresh_jobs();
        } else {
            s.ilegal_command = true;
            return;
        }
    }
    s.exit_request = true;
}

void quitCOMMAND::send_all_children(State &s, int sig) {
    int i = 1;
    for (auto& job : s.p_state) {
        int status = 0;
        kill(job.pid, sig);
        std::cout<<"[" << i << "] " << job.name << " - Sending SIGTERM... ";
        waitpid(job.pid, &status,WNOHANG);
        if(!WIFEXITED(status)){
            sleep(5);
            std::cout<< "(5 sec passed)";
            kill(job.pid,SIGKILL);
            std::cout<<" Sending SIGKILL... ";
        }
        std::cout<<"Done."<<std::endl;
        i++;
    }
}
