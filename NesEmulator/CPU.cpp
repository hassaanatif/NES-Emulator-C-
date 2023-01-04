#include "CPU.h"


CPU::CPU() {
    using tmp = CPU;

    CPU::instructions = {
            {"BRK", &tmp::BRK(),&tmp::IMM, 7} //more to come here
    };
}

