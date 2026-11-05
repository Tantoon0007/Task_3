#pragma once
#include "Instruction.h"
class DataTransferInstr :public Instruction
{ 
public:
    DataTransferInstr();
    virtual ~DataTransferInstr(); 

    bool isLoadFromMemory() const;
    bool isLoadValue() const;
    bool isStore() const;

    bool isMove() const;
    bool isStoreToScreen() const;


    int get_TargetRegister() const;
    int get_Address() const;
    int get_Value() const;
    int get_MoveSource() const;
    int get_MoveDestination() const;
};

