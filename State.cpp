//
// Created by igor de paula on 4/8/2020.
//

#include <unistd.h>
#include <wait.h>
#include "State.h"

State::State() : ilegal_command(false),
    exit_request(false),
    cur_dir(get_current_dir_name()),
    prev_dir(get_current_dir_name())
    {


}



Job::Job(int id, std::time_t time, std::string n) :pid(id),time_in(time), name(std::move(n)){

}

Job::Job() {
    pid = 0;
    time_in = 0;
}

void State::refresh_jobs() {
    std::vector<int> dead_jobs;
    int status = 0;
    for (std::pair<int, Job> job : p_state) {
        pid_t result = waitpid(job.second.pid, &status, WUNTRACED|WNOHANG);
        if(result == 0){
            continue;
        }
        if (result == -1 || WIFEXITED(status) || WIFSIGNALED(status)) {
            dead_jobs.push_back(job.second.pid);
            continue;
        }
        p_state[job.first].stopped = WIFSTOPPED(status);
    }
    for (int pid: dead_jobs) {
        p_state.erase(pid);
    }
}