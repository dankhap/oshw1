//
// Created by daniel on 12/04/2020.
//

#ifndef SMASH_JOBSCOMMAND_H
#define SMASH_JOBSCOMMAND_H


#include "Command.h"

class JobsCommand : public Command{
public:
    void  execute(std::vector<std::string> args,State& S) override;
};


#endif //SMASH_JOBSCOMMAND_H
