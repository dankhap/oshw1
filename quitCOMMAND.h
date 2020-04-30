//
// Created by os on 12.4.2020.
//

#ifndef SMASH_QUITCOMMAND_H
#define SMASH_QUITCOMMAND_H

#include <vector>
#include <string>
#include "State.h"
#include "Command.h"

class quitCOMMAND : public Command{
private:
    static void send_all_children(State& s, int sig);
public:
    void  execute(std::vector<std::string> args,State& S) override;
};

#endif //SMASH_QUITCOMMAND_H
