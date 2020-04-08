//
// Created by igor de paula on 4/8/2020.
//

#ifndef OSHW1_PWDCOMMAND_H
#define OSHW1_PWDCOMMAND_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "State.h"
#include "vector"
#include "Command.h"

class PWDcommand : public Command {
private:
public:
    void  execute(std::vector<char*>,State) override;

};
#endif //OSHW1_PWDCOMMAND_H
