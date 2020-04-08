//
// Created by igor de paula on 4/8/2020.
//

#include "Terminal.h"
#include "Terminal.h"
#define MAXARGS 20
#define MAX_LINE_SIZE 80
using std::vector;
using std::stringstream ;
using std::cout;

/*Terminal class initializer, very basic just for the beginning  */
Terminal::Terminal(std::map<string,Command*> com):commands(com)
{


}
/*Run function, takes input from user, stores in vector of strings for argument(cast from char to string (problem?)
 * */
void Terminal::run(){
    char c1[MAX_LINE_SIZE];
    char* token;
    while(!terminal_state.exit_request){
        std::cout<<"smash > ";
        fgets(c1,MAX_LINE_SIZE,stdin);
        token = strtok(c1,delim);
        while(token!=nullptr && tokens.size()<MAXARGS){
            tokens.push_back(token);
            token = strtok(NULL,delim);
        }

        if(commands.count((tokens.front()))>0){  // if command is built in command (maybe better way the to use .count
            commands[tokens.front()]->execute(tokens,terminal_state);
        } else(run_app());




        tokens.clear();



    }}

pid_t Terminal::run_app() {

    if(*tokens.back() == '&'){
        std::cout<<"Backround & arg "<<std::endl;// do backround stuff
    } else{
        std::cout<<"Forground  "<<std::endl;// do forground stuff
    }}

