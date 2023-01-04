#pragma once
#include <cstdint>
#include "iostream"
using namespace std;
 


class CPU
{
    uint8_t accumulator;
    uint8_t x;
    uint8_t y;

    uint16_t pc;
    uint8_t sp;
    uint8_t streg;


    struct flags {
        uint8_t C : 1; //carry flag
        uint8_t Z : 1; // Zero flag
        uint8_t D : 1; //Decimal mode
        uint8_t B : 1; //Break
        uint8_t U : 1; //unused
        uint8_t O : 1; //overflow
        uint8_t N : 1; //Negative

    };

    uint8_t ram[0x200]; //2kb ram

    /**all the addressing modes**/
    uint8_t IMP;
    uint8_t IMM;
    uint8_t ZP0;
    uint8_t	ZPX;
    uint8_t	ZPY;
    uint8_t	REL;
    uint8_t	ABS;
    uint8_t ABX;
    uint8_t ABY;
    uint8_t	IND;
    uint8_t	IZX;
    uint8_t	IZY;
    //fetching instructions

    uint8_t fetchedInst = 0x00;
    uint8_t fetch();

    uint8_t clockCounter; //this can overflow because the 8 bit value is too small
//signals
    void CLK(); //clock signal
    void RESET(); //reset signal
    void NMI();  //Non maskable interrupt signal. These cannot be disabled
    void IRQ(); //interrupt request signal. These can be disabled depending on the setting of the interrupt enable flag

//function pointer
    using InstructionFn = void(*);


    //instruction
    struct instruction {
        std::string name;
        uint8_t (CPU::*instructionFn) (void) = nullptr; //operation
        uint8_t (CPU::*addrMode)(void) = nullptr; //addressing mode
        uint8_t cyclesCount = 0;
    };

public :
    vector<instruction> instructions;

CPU(){
}
    void tick() {
        uint8_t opcode = ram[pc];
        uint8_t operand = ram[pc + 1];
        //pc += 2 ?
    }

    /**instructions functions**/
    uint8_t BRK ();
};

int main () {
    CPU cpu;
    cpu.tick();
}



