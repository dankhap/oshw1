//
// Created by igor de paula on 4/8/2020.
//

#include <unistd.h>
#include "State.h"

State::State() : ilegal_command(false),
    exit_request(false),
    cur_dir(get_current_dir_name()),
    prev_dir(get_current_dir_name()){

}

Job::Job(int id, std::time_t time, std::string n) :pid(id),time_in(time), name(std::move(n)){

}

Job::Job() {
    pid = 0;
    time_in = 0;
}
