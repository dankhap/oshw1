//
// Created by igor de paula on 4/8/2020.
//

#include "PWDcommand.h"


/**
 * prints out current directory
 * @param args should be empty
 * @param s shell state
 */
void PWDcommand:: execute(std::vector<string> args,State& s) {
    if(args.size() == 1){
        std::cout << s.cur_dir << std::endl;
        return;}
    s.ilegal_command = true;
}
