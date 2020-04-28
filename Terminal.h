//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_TERMINAL_H
#define OSHW1_TERMINAL_H
#include <vector>
#include <map>
#include <string>
#include "Command.h"
#include "State.h"

using std::map;
using std::string ;



class Terminal
{
private:
    std::map<string ,Command*> commands;
    State terminal_state;

    void push_to_history(const std::vector<string>&);

public:
    explicit  Terminal(std::map<string,Command*> );
      ~Terminal() = default;
    void run();
    void printBuildIn(const std::vector<string>& args);
    pid_t run_app(std::vector<string> tokens);
    State& stateGetter();




};



#endif //OSHW1_TERMINAL_H
