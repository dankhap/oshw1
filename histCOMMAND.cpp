//
// Created by os on 11.4.2020.
//

#include "histCOMMAND.h"
#include <iostream>

using std::string;

/**
 * prints out commands in history
 * @param args should be empty
 * @param S terminal status
 */
void histCOMMAND::execute(std::vector<string> args, State &S) {
    if(args.size()>1){
        S.ilegal_command = true;
        return;
    }

    for(int i = 0; i!= (int)S.history.size();i++){
        for(int j = 0 ; j != (int)S.history[i].size();j++){
            std::cout<<S.history[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

}