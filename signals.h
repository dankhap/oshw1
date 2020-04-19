//
// Created by os on 17.4.2020.
//

#ifndef SMASH_SIGNALS_H
#define SMASH_SIGNALS_H

#include <signal.h>
#include "Terminal.h"
#include "State.h"

class SignalHandler{
private:
    SignalHandler(){};

public:
    SignalHandler(SignalHandler& s) = delete;
    void operator=(SignalHandler& s) = delete;
    static SignalHandler& getInstance(){
        static SignalHandler instance;
        return instance;
    }

    ~SignalHandler() = default;
    static void INT_handler();
    static void STP_handler();
    State* stateInstance;


};




#endif //SMASH_SIGNALS_H
