//
// Created by igor de paula on 4/8/2020.
//

#include <unistd.h>
#include "State.h"

State::State() : ilegal_command(false),exit_request(false), cur_dir(get_current_dir_name()){

}