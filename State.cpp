//
// Created by igor de paula on 4/8/2020.
//

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "State.h"
State::State():cur_dir(get_current_dir_name()),exit_request(false),ilegal_command(false){

}