//
// Created by os on 11.4.2020.
//

#ifndef SMASH_CPCOMMAND_H
#define SMASH_CPCOMMAND_H

#include "State.h"
#include "Command.h"

class cpCOMMAND :public Command{
private:
public:
    void  execute(std::vector<std::string> args,State& S) override;
};
#endif //SMASH_CPCOMMAND_H
