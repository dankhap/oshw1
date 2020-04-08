//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_TERMINAL_H
#define OSHW1_TERMINAL_H
#include <sched.h>
#include <vector>
#include "map"
#include "string"
#include "Command.h"
#include "State.h"
using std::map;
using std::string ;

class Terminal
{
private:
    char* delim = " \t\n";
    std::map<string ,Command*> commands;
    State terminal_state;
    std::vector<char*> tokens; // vector for arguments
    //
public:
    explicit  Terminal(std::map<string,Command*>);
    ~Terminal() = default;
    void run();
    pid_t run_app();
    void signal_handler();




};
#endif //OSHW1_TERMINAL_H
