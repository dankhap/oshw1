//
// Created by daniel on 13/04/2020.
//

#ifndef SMASH_FGCOMMAND_H
#define SMASH_FGCOMMAND_H


#include "Command.h"

class FgCommand : public Command{
private:
    static unsigned int find_latest_job_idx(const map<int, Job>& map);
    static void move_to_fg(const Job &j);

public:
    void  execute(std::vector<string> args,State& S) override;

};


#endif //SMASH_FGCOMMAND_H
