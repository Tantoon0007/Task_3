#pragma once
#include "Instruction.h"
class ControlInstr :public Instruction
{
public:
	ControlInstr();
	virtual ~ControlInstr();

	bool isJump() const;
	bool isHalt() const;
	int get_JumpRegister() const;
	int get_JumpAddress() const;
};

