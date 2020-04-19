//
// Created by os on 17.4.2020.
//

#include <iostream>
#include "signals.h"

void INT_sig_handler(int sig_num){
    std::cout<<"control c is press ... handl"<<std::endl;
}
void STP_sig_handler(int sig_num){
    std::cout<<"control z is press ... handl"<<std::endl;
}