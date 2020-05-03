//
// Created by os on 12.4.2020.
//

#include <ctime>
#include <unistd.h>
#include <iostream>
#include <wait.h>
#include "quitCOMMAND.h"
using std::string;

/**
 * quit command, also handle quit kill
 * @param args either no args or has kill, if has kill, handle.
 * @param s current shell state
 */
void quitCOMMAND::execute(std::vector<string> args, State &s) {
    if(args.size() > 1 ) {
        if (args.size() == 2 && args[1] == "kill") {// if has kill send to function to handle it.
            s.refresh_jobs();
            send_all_children(s, SIGTERM);
            s.refresh_jobs();
        } else {
            s.ilegal_command = true;
            return;
        }
    }
    s.exit_request = true;  // other wise request exit
}
/**
 * sends sigterm and sigkill (if sigterm hasnt worked to all jobs
 * @param s shell state
 * @param sig always SIGTERM
 */
void quitCOMMAND::send_all_children(State &s, int sig) {
    int i = 1;
    for (auto& job : s.p_state) {
        int status = 0;
        kill(job.pid, sig);
        std::cout<<"[" << i << "] " << job.name << " - Sending SIGTERM... "; // output sigterm
        usleep(10000);
        pid_t res = waitpid(job.pid, &status, WNOHANG); // check if worked
        if(!res || !WIFSIGNALED(status)){ // if not send sigkill
            sleep(5);
            std::cout<< "(5 sec passed)";
            kill(job.pid, SIGKILL);
            std::cout<<" Sending SIGKILL... ";
            waitpid(job.pid, nullptr, 0);
        }
        std::cout<<"Done."<<std::endl;
        i++;
    }
}
