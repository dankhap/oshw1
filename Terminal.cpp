//
// Created by igor de paula on 4/8/2020.
//

#include <iostream>
#include <utility>
#include <sstream>
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

        auto iss = istringstream{cl};
        auto token = string{};
        while (iss >> token) {
            args.emplace_back(token);
        }

        if(commands.count(args.front())){  // if command is built in command (maybe better way the to use .count
            commands[args.front()]->execute(args,terminal_state);
            if(terminal_state.ilegal_command){
                std::cout<<"Ilegal command, try again"<<std::endl;
                terminal_state.ilegal_command = false;
            }
        } else(run_app(args));

        if(!terminal_state.ilegal_command){       // handle saving the commands;
            if(terminal_state.history.size()<50){
                terminal_state.history.push_back(args);
            } else{
                terminal_state.history.pop_back();
                terminal_state.history.push_back(args);
            }


        }



    }
}

pid_t Terminal::run_app(const vector<string>& tokens) {

    if(tokens.back() == "&"){
        std::cout<<"Backround & arg "<<std::endl;// do backround stuff
    } else{
        std::cout<<"Forground  "<<std::endl;// do forground stuff
    }
    return 0;
}

void Terminal::signal_handler() {
    this->terminal_state.ilegal_command=true;
}

