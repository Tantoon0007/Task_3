#include "DataTransferInstr.h"

DataTransferInstr::DataTransferInstr() : Instruction() {}
DataTransferInstr::~DataTransferInstr() {}

bool DataTransferInstr::isLoadFromMemory() const {
    return opcode == 0x1;
}

bool DataTransferInstr::isLoadValue() const {
    return opcode == 0x2;
}

bool DataTransferInstr::isStore() const {
    return opcode == 0x3;
}

bool DataTransferInstr::isMove() const {
    return opcode == 0x4;
}

bool DataTransferInstr::isStoreToScreen() const {
    return opcode == 0x3 && xy == 0xFF;
}

int DataTransferInstr::get_TargetRegister() const {
    return r;
}

int DataTransferInstr::get_Address() const {
    return (int)xy;
}

int DataTransferInstr::get_Value() const {
    return (int)xy;
}

int DataTransferInstr::get_MoveSource() const {
    return s;
}

int DataTransferInstr::get_MoveDestination() const {
    return t;
}
