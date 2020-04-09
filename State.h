//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_STATE_H
#define OSHW1_STATE_H

#include <string>
using std::string;


class State
{
private:
public:
    bool ilegal_command;
    bool exit_request;
    std::string cur_dir;
    State();

};
#endif //OSHW1_STATE_H
