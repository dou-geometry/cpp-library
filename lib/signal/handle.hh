#pragma once
#include<signal.h>
namespace d::signal {
    extern volatile sig_atomic_t SIGTERMcaught;
    extern volatile sig_atomic_t SIGUSR1caught;
    extern volatile sig_atomic_t SIGUSR2caught;
    void signalHandler(int);
}
