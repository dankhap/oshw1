//
// Created by igor de paula on 4/8/2020.
//

#include <unistd.h>
#include <wait.h>
#include <algorithm>
#include <cstring>
#include "State.h"

using std::vector;
using std::string;


/**
 * terminal state intialize
 */
State::State() : ilegal_command(false),
    exit_request(false)
    {
    char* cdir = get_current_dir_name(); // memory managment
    cur_dir = string(cdir);
    prev_dir = string(cdir);
    free(cdir);
}



Job::Job(int id, std::time_t time, std::string n) :pid(id),time_in(time), name(std::move(n)),stopped(false){ // defaulted at stopped bug

}

Job::Job() {
    pid = 0;
    time_in = 0;
    stopped = false; // defaulted at stopped bug
}

/**
 * refresh jobs list, check which jobs are done and remove them.
 */
void State::refresh_jobs() {
    std::vector<int> dead_jobs;
    int status = 0;
    for (auto &job : p_state) {
        pid_t result = waitpid(job.pid, &status, WUNTRACED|WNOHANG);
        if(result == 0){
            continue;
        }
        //if job is just died or is non-existant, add it the dead job list
        if (result == -1 || WIFEXITED(status) || WIFSIGNALED(status)) {
            dead_jobs.push_back(job.pid);
            continue;
        }
        job.stopped = WIFSTOPPED(status);
    }

    //remove all dead jobs from our list
    auto predicate = [&](const Job &v) { return find(dead_jobs.begin(), dead_jobs.end(), v.pid) != dead_jobs.end();};
    p_state.erase(std::remove_if(p_state.begin(), p_state.end(), predicate), p_state.end());
}