//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_COMMAND_H
#define OSHW1_COMMAND_H
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "State.h"
class  Command
{
private:
public:
    Command() = default;
    ~Command() = default;

    virtual void  execute(std::vector<char*>,State) {
        //vitrual func
    }

};
#endif //OSHW1_COMMAND_H
