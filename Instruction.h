#pragma once
#include <string>
class Instruction
{
protected:
    int opcode;
    int r;
    int s ;
    int t;
    unsigned char xy;
    unsigned short raw;
public:

    Instruction();
    virtual ~Instruction();
    void decode(unsigned short word);
    bool isValid() const;
     
    static Instruction* create(unsigned short word);

    //getters

    int get_Opcode() const;
    int get_R() const;
    int get_S() const;
    int get_T() const;
    int get_XY() const;
};

