//
// Created by os on 11.4.2020.
//
#include <iostream>
#include <unistd.h>
#include "shpdCOMMAND.h"

void shpdCOMMAND::execute(std::vector<std::string> args, State &S) {
    if(args.size() == 1){
        std::cout<<"smash pid is "<<getpid()<<std::endl;
    } else{
        S.ilegal_command = true;
    }
}
