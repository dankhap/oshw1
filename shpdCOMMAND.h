//
// Created by os on 11.4.2020.
//

#ifndef SMASH_SHPDCOMMAND_H
#define SMASH_SHPDCOMMAND_H
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "State.h"
#include "Command.h"

class shpdCOMMAND : public Command{
private:
public:
    virtual void  execute(std::vector<std::string> args,State& S) override;
};


#endif //SMASH_SHPDCOMMAND_H
