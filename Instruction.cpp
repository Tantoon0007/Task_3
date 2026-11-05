#include "Instruction.h"
#include"DataTransferInstr.h"
#include"ControlInstr.h"

Instruction::Instruction() {
    opcode = 0;
    r = 0;
    s = 0;
    t = 0;
    xy = 0;
    raw = 0;
}

Instruction::~Instruction() {}

void Instruction::decode(unsigned short word) {
    raw = word;
    opcode = (word >> 12) & 0xF;
    r = (word >> 8) & 0xF;
    s = (word >> 4) & 0xF;
    t = word & 0xF;
    xy = word & 0xFF;
}

bool Instruction::isValid() const {
    switch (opcode) {
    case 0x1: case 0x2: case 0x3:
    case 0x5: case 0x6: case 0x7:
    case 0x8: case 0x9: case 0xB:
        return true;
    case 0x4:
        return r == 0;
    case 0xA:
        return s == 0;
    case 0xC:
        return raw == 0xC000;
    default:
        return false;
    }
}
Instruction* Instruction::create(unsigned short word) {
    unsigned char op = (word >> 12) & 0xF;
    Instruction* ins = nullptr;
    if (op >= 0x1 && op <= 0x4) {
        ins = new DataTransferInstr();
    }
    else if (op == 0xB || op == 0xC) {
        ins = new ControlInstr();
    }
    else {
        ins = new Instruction();
    }

    ins->decode(word);

    if (!ins->isValid()) {
        delete ins;
        return nullptr;
    }
    return ins;
}

int Instruction::get_Opcode() const { return opcode; }
int Instruction::get_R() const { return r; }
int Instruction::get_S() const { return s; }
int Instruction::get_T() const { return t; }
int Instruction::get_XY() const { return (int)xy; }


