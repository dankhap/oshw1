//
// Created by os on 12.4.2020.
//

#include "difCOMMAND.h"
using std::string;
/**
 * execution of diff commans
 * @param args two file names which will be compared. output 0 if equal and 1 if not
 * @param S current shell status
 */
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
    if(source.tellg()!=dest.tellg()){   // if not same size not equal
        std::cout<<"not same size"<<std::endl;
        source.close();
        dest.close();
        return;
    }
    while(getline(source,line1) && getline(dest,line2)){ // check line by line
        if(line1 != line2){
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