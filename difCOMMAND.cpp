//
// Created by os on 12.4.2020.
//

#include "difCOMMAND.h"
using std::string;

void difCOMMAND::execute(std::vector<string> args, State &S) {
    if(args.size()!=3){
        S.ilegal_command = true;
        return;
    }
    std::string line1;
    std::string line2;
    std::fstream source;
    std::fstream dest;
    source.open(args[1],std::fstream::in);
    if(!source.good()){
        perror(nullptr);
        return;
    }
    dest.open(args[2],std::fstream::in);
    if(!dest.good()){
        perror(nullptr);
        source.close();
        return;
    }
    if(source.tellg()!=dest.tellg()){
        std::cout<<"not same size"<<std::endl;
        source.close();
        dest.close();
        return;
    }
    while(getline(source,line1) && getline(dest,line2)){
        if(line1.compare(line2)){
            std::cout<<"1"<<std::endl;
            source.close();
            dest.close();
            return;
        }
    }
    std::cout<<"0"<<std::endl;
    source.close();
    dest.close();
}