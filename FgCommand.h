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
    static unsigned int find_latest_job_idx(const map<int, Job>& map);
    static void continue_job( Job* j, bool wait);

public:
    ContCommand(ContType type);
    void  execute(std::vector<string> args,State& S) override;

};


#endif //SMASH_FGCOMMAND_H
