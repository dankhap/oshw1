//
// Created by os on 11.4.2020.
//

#include "cdCommand.h"

/** execute function for the cd command
 *
 * @param args arguments attached to fucntion
 * @param S current state of the shell
 */
void cdCommand::execute(std::vector<string> args, State& S) {
    const char *path = args[1].c_str();

    if(args.size() != 2 ){  // if argument size doesnt fit
        S.ilegal_command = true;
        return;
    }
    if(!strcmp(path, "-")) {
        const char *cstr = S.prev_dir.c_str();
        if (chdir(cstr) == 0) { // success the path function resturs zero
            std::cout << S.prev_dir << std::endl;
            S.cur_dir = S.prev_dir;
            return;                      // if chdir doesnt work? assuming if there is a path it works
        }
    }
        if(chdir(path) == 0){
            S.prev_dir = S.cur_dir;
            char* cdir = get_current_dir_name();
            S.cur_dir = string(cdir);   // memory managment
            free(cdir);
            return;
        }
        std::cerr<<"smash error: > \" "<<args[1]<<" \" - path not found"<<std::endl;
}
