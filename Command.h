//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_COMMAND_H
#define OSHW1_COMMAND_H
#include <string>
#include <vector>
#include "State.h"

using std::vector;
using std::string;
/*
 * param string f the argumetns and the state of the terminal
 * Checks if command is legal, if so executes the path change and edits the paramaters.
 */

class  Command
{
private:
public:
    Command() = default;
    ~Command() = default;

    virtual void  execute(std::vector<std::string>,State&) {
        //vitrual func
    }

};
#endif //OSHW1_COMMAND_H
