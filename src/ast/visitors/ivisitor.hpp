#ifndef JAVACOMPILER_SRC_AST_IVISITOR_HPP_
#define JAVACOMPILER_SRC_AST_IVISITOR_HPP_

#include <iostream>
#include <string>
#include <memory>

namespace ast {

class ExpressionInt;
class ExpressionBinaryOp;
typedef std::shared_ptr<ExpressionInt> PExpressionInt;
typedef std::shared_ptr<ExpressionBinaryOp> PExpressionBinaryOp;

class IVisitor {
public:
    virtual ~IVisitor() = default;

    virtual void visit(const ExpressionInt* expr) = 0;
    virtual void visit(const ExpressionBinaryOp* expr) = 0;
};

}

#endif //JAVACOMPILER_SRC_AST_IVISITOR_HPP_