//
// Created by daniel on 12/04/2020.
//

#ifndef SMASH_KILLCOMMAND_H
#define SMASH_KILLCOMMAND_H

#include <string>
#include "Command.h"

class KillCommand : public Command{
public:
    void  execute(std::vector<std::string> args,State& S) override;
};


#endif //SMASH_KILLCOMMAND_H
