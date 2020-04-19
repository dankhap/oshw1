//
// Created by igor de paula on 4/8/2020.
//

#include <iostream>
#include <utility>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <algorithm>
#include "Terminal.h"


#define MAXARGS 20
#define MAX_LINE_SIZE 80
using namespace std;

/*Terminal class initializer, very basic just for the beginning  */
Terminal::Terminal(std::map<string,Command*> com):commands(std::move(com))
{

}
/*Run function, takes input from user, stores in vector of strings for argument(cast from char to string (problem?)
 * */
void Terminal::run(){ // git hub test

    string cl;

    while(!terminal_state.exit_request){
        cout<<"smash > ";
        vector<string> args;
        getline(cin, cl);
        if(cl.empty()) continue;
        auto iss = istringstream{cl};
        auto token = string{};
        while (iss >> token) {
            args.emplace_back(token);
        }
        if(args.empty()) continue;

        if(commands.count(args.front())){  // if command is built in command (maybe better way the to use .count
            commands[args.front()]->execute(args,terminal_state);
            if(terminal_state.ilegal_command){
                std::cout<<"Ilegal command, try again"<<std::endl;
                terminal_state.ilegal_command = false;
            }
        } else(run_app(args));

        // handle saving the commands;
        if(terminal_state.history.size()<50){
            terminal_state.history.push_back(args);
        } else{
            terminal_state.history.pop_back();
            terminal_state.history.push_back(args);
            }
        if(terminal_state.exit_request ){
            exit(0);
                // handle quit command
        }


    }
}

const char *convert(const std::string & s)
{
    return s.c_str();
}

pid_t Terminal::run_app(vector<string> tokens) {
    if(tokens.empty()){
        return 0;
    }
    bool is_bg = false;
    int res = 0;
    if(tokens.back() == "&") {
        tokens.pop_back();
        is_bg = true;
    }
    string exe_name = tokens[0];
    vector<const char*>  vc;
    transform(tokens.begin(), tokens.end(), back_inserter(vc), convert);
    int pid = fork();
    if(pid == 0){
        setpgrp(); // Change group id for child process so signals wont be sent to all, and only main process will catch signal.
        if(execv(exe_name.c_str(), (char**)&vc[1]) == -1) {
            perror(nullptr);
            exit(errno);
        }
    } else {
        if(is_bg){
            time_t start = time(nullptr);
            Job j(pid, start, exe_name);
            this->terminal_state.p_state[pid] = j;
        } else{
            terminal_state.cur_command = exe_name;
            terminal_state.fg_pid = pid;
            wait(&res);
        }
    }

    return 0;
}

State& Terminal::stateGetter() {
    return this->terminal_state;
}




/*
/usr/bin/gnome-calculator &
jobs
kill -19

 */

