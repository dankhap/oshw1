//
// Created by os on 11.4.2020.
//

#include "cpCOMMAND.h"
#include <iostream>
#include <fstream>

using std::string;

/**
 * execution fot cp command, opens two files and copies one to the other
 * @param args old file name and new file name
 * @param S current state of the shell
 */
 void::cpCOMMAND::execute(std::vector<string> args, State &S) {
    if(args.size()!=3){
        S.ilegal_command = true; // if illegal
        return;
    }
   std::string line;
   std::fstream source;
   std::ofstream dest;
   source.open(args[1],std::fstream::in);
     if(!source.good()){
         perror(nullptr);
         std::cout.flush();
         return;
     }
   dest.open(args[2],std::ostream::out);
   if(!dest.good()){
       perror(nullptr);
       source.close();
       return;
   }
    while (getline(source,line)){
        dest<<line;
        dest<< std::endl;
    }
    source.close();
    dest.close();
    std::cout<<args[1]<<" has been copied to "<<args[2]<<std::endl;

}
