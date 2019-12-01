//
// Created by nikolai on 24.11.19.
//

#pragma once

#include <string>
#include <memory>
#include <vector>

#include "../Statement/IRTStatementBase.h"

class IRTExpBase : public IRTStatementBase {
public:

    IRTExpBase() {
        ret_type = "int";
        registerToReturn = "smth";
    }

    std::string GetRetType() {
        return ret_type;
    }
    std::string GetRegister() {
        return registerToReturn;
    }
    IRTExpBase(const std::string& ret_type,  const std::string& registerToReturn)
            : ret_type(ret_type),
              registerToReturn(registerToReturn)
    {
    }

    void SetRetType(const std::string& ret) {
        ret_type = ret;
    }

private:
    std::string ret_type;
    std::string registerToReturn;
};


class ExpList {
private:
    std::shared_ptr<IRTExpBase> head = nullptr;
    std::shared_ptr<ExpList> tail = nullptr;
public:
    ExpList(const std::shared_ptr<IRTExpBase>& head_, const std::shared_ptr<ExpList>& tail_) : head(head_), tail(tail_) {}
    ExpList(std::vector<std::shared_ptr<IRTExpBase>> all) {
        if (all.size() == 0) {
            head = nullptr;
            tail = nullptr;
            return;
        }
        head = all[0];
        all.erase(all.begin());
        tail = std::make_shared<ExpList>(ExpList(all));
    }
};
