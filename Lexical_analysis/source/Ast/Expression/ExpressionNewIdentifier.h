//
// Created by nikolai on 22.10.19.
//

#ifndef MINI_JAVA_COMPILER_EXPRESSIONNEWIDENTIFIER_H
#define MINI_JAVA_COMPILER_EXPRESSIONNEWIDENTIFIER_H

#include "../Expression/ExpressionBase.h"

class ExpressionNewIdentifier : public ExpressionBase {
public:
    ExpressionNewIdentifier(const std::string& identifier) : identifier(identifier) {}

private:
    std::string identifier;
};


#endif //MINI_JAVA_COMPILER_EXPRESSIONNEWIDENTIFIER_H
