//
// Created by os on 11.4.2020.
//

#ifndef SMASH_CDCOMMAND_H
#define SMASH_CDCOMMAND_H
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "State.h"
#include "Command.h"
using namespace std;

class cdCommand : public Command{
private:
public:
    virtual void  execute(std::vector<string> args,State& S) override;
    virtual ~cdCommand()= default;

};

#endif //SMASH_CDCOMMAND_H
