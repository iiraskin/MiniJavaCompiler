//
// Created by nikolai on 10.12.19.
//

#pragma once

#include <fstream>

#include "IRT/IRTNodeBase.h"
#include "IRT/Statement/IRTStatement.h"
#include "IRT/IRTExp/IRTExp.h"
#include "Visitor.h"



class IRTDotVisitor : public Visitor {
private:
    int n = 0;          // Номер вершины при обходе.
    std::ofstream& f;    // Файл, в который будет печататься дерево.
public:
    explicit
    IRTDotVisitor(std::ofstream& f) : f(f){}

    void IncN() {
        ++n;
    }

    int Visit(Arg* node);
    int Visit(BinOp* node);
    int Visit(Call* node);
    int Visit(Const* node);
    int Visit(ESeq* node);
    int Visit(IRTExpBase* node);
    int Visit(Local* node);
    int Visit(Mem* node);
    int Visit(Name* node);
    int Visit(Temp* node);
    int Visit(ExpList* node);


    //int Visit(CJump* node);
};

