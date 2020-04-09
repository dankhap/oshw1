//
// Created by igor de paula on 4/8/2020.
//

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "PWDcommand.h"


void PWDcommand:: execute(std::vector<string>,State&) {
    std::cout<<State().cur_dir<<std::endl;
}
