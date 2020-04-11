//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_STATE_H
#define OSHW1_STATE_H

#include <stdio.h>
#include <string>
#include <vector>

using std::string;


class State
{
private:
public:
    bool ilegal_command;
    bool exit_request;
    std::string cur_dir;
    std::string prev_dir;
    std::vector<std::vector<std::string>> history;
    State();

};
#endif //OSHW1_STATE_H
