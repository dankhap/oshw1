//
// Created by os on 12.4.2020.
//

#include <csignal>
#include <unistd.h>
#include "quitCOMMAND.h"
using std::string;

void quitCOMMAND::execute(std::vector<string> args, State &s) {
    if(args.size() > 1 ) {
        if (args.size() == 2 && args[1] == "kill") {
            send_all_children(s, SIGTERM);
            s.refresh_jobs();
            if (!s.p_state.empty()) {
                sleep(5);
                send_all_children(s, SIGKILL);
            }
        } else {
            s.ilegal_command = true;
            return;
        }
    }
    s.exit_request = true;
}

void quitCOMMAND::send_all_children(State &s, int sig) {
    for (auto& job : s.p_state) {
        kill(job.first, sig);
    }
}
