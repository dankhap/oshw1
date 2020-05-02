//
// Created by daniel on 13/04/2020.
//

#ifndef SMASH_FGCOMMAND_H
#define SMASH_FGCOMMAND_H


#include "Command.h"
enum class ContType { BG, FG};
class ContCommand : public Command{
private:
    ContType type;
    static void continue_job( Job& j, bool wait, State& s);

public:
    explicit ContCommand(ContType type);
    void  execute(std::vector<std::string> args,State& S) override;

};


#endif //SMASH_FGCOMMAND_H
