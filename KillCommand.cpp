//
// Created by daniel on 12/04/2020.
//

#include <iostream>
#include <wait.h>
#include "KillCommand.h"

using namespace std;
/**
 * sends signal to specefic job
 * @param args the signal to send and the job to send to
 * @param s shell state
 */
void KillCommand::execute(std::vector<string> args, State &s) {
    if(args.size() != 3){
        s.ilegal_command = true; // check if command is kegak
        return;
    }
    if(args[1][0] != '-'){
        s.ilegal_command = true;
        return;
    }

    int pidx = 0;
    int sig = 0;

    try {
        pidx = std::stoi(args[2]);
        sig = std::stoi(args[1].erase(0, 1));
    }catch (const std::invalid_argument &e){
        s.ilegal_command = true;
        return;
    }
    s.refresh_jobs();  // check if job exits
    if(pidx < 1 || (unsigned int)pidx > s.p_state.size()) {
        std::cout << "smash error: > kill " << pidx << "- job does not exist" << std::endl;
        return;
    }

    if(kill(s.p_state[pidx - 1].pid, sig) == -1) {  // send signal, display result
        std::cout << "smash error: > kill " << pidx << "- cannot send signal" << std::endl;
        return;
    }
    cout << "signal " << sig << " was sent to pid " << s.p_state[pidx - 1].pid << endl;
    s.refresh_jobs();
}
