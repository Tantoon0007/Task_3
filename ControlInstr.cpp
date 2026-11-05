#include "ControlInstr.h"

ControlInstr::ControlInstr() : Instruction() {}
ControlInstr::~ControlInstr() {}

bool ControlInstr::isJump() const { return opcode == 0xB; }
bool ControlInstr::isHalt() const { return opcode == 0xC; }
int ControlInstr::get_JumpRegister() const { return r; }
int ControlInstr::get_JumpAddress() const { return (int)xy; }
