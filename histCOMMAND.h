//
// Created by os on 11.4.2020.
//

#ifndef SMASH_HISTCOMMAND_H
#define SMASH_HISTCOMMAND_H
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "State.h"
#include "Command.h"
/*
 * param A Built in command that prints the history of the last commands (up to 50).
 * We check if the command is legal and print the history member of the state of the terminal
 */

class histCOMMAND : public Command{
private:
public:
    virtual void  execute(std::vector<string> args,State& S) override;
};

#endif //SMASH_HISTCOMMAND_H
