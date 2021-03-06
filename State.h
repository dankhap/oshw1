//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_STATE_H
#define OSHW1_STATE_H

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <ctime>


struct Job{
    int pid;
    std::time_t time_in;
    std::string name;
    bool stopped;
    Job();
    Job(int id, std::time_t time, std::string n);
};

class State
{
private:
public:
    int fg_pid{}; // for signal handler
    std::string cur_command;
    bool ilegal_command;
    bool exit_request;
    std::string cur_dir;
    std::string prev_dir;
    std::vector<std::vector<std::string>> history;
    std::vector<Job> p_state;
    State();

    //remove dead jobs from jobs list
    void refresh_jobs();

};
#endif //OSHW1_STATE_H
