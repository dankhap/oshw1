//
// Created by os on 12.4.2020.
//

#ifndef SMASH_DIFCOMMAND_H
#define SMASH_DIFCOMMAND_H
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include "State.h"
#include "Command.h"

class difCOMMAND : public Command{
private:
public:
    void execute(std::vector<std::string> args,State& S) override;
};
#endif //SMASH_DIFCOMMAND_H
