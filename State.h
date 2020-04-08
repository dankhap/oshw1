//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_STATE_H
#define OSHW1_STATE_H
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
using std::string;


class State
{
private:
public:
    bool ilegal_command;
    bool exit_request;
    string cur_dir;
    State();

};
#endif //OSHW1_STATE_H
