//
// Created by os on 11.4.2020.
//

#include "cpCOMMAND.h"

 void::cpCOMMAND::execute(std::vector<string> args, State &S) {
    if(args.size()!=3){
        S.ilegal_command = true;
        return;
    }
   std::string line;
   std::fstream source;
   std::ofstream dest;
   source.open(args[1],std::fstream::in);
     if(!source.good()){
         perror("No such file");
         return;
     }
   dest.open(args[2],std::ostream::out);
   if(!dest.good()){
       perror("Couldnt open new file");
       source.close();
       return;
   }
    while (getline(source,line)){
        dest<<line;
        dest<< std::endl;
    }
    source.close();
    dest.close();

}
