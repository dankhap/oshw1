//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_PWDCOMMAND_H
#define OSHW1_PWDCOMMAND_H


#include "State.h"
#include "Command.h"
#include <iostream>

using namespace std;


class PWDcommand : public Command {
private:
public:
    void execute(std::vector<string> args,State&) override;

};
#endif //OSHW1_PWDCOMMAND_H
