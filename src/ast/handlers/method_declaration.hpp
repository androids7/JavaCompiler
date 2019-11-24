#pragma once

#include <string>
#include <memory>

#include <yyltype.hpp>
#include <handlers/visitable.hpp>
#include <visitors/ivisitor.hpp>

#include <handlers/var_declaration.hpp>
#include <handlers/statements.hpp>
#include <handlers/method_body.hpp>

namespace ast {

class MethodDeclaration : public IVisitable {
public:
    MethodDeclaration(const std::string &privacy,
                const PType &type,
                const std::string &identifier,
                const PMethodBody &method_body,
            MC::YYLTYPE pos) : privacy_(privacy), type_(type), identifier_(identifier), method_body_(method_body) { setPos(pos); }

    const PType &getType() const {
        return type_;
    }

    const std::string& getPrivacy() const {
        return privacy_;
    }

    const std::string& getIdentifier() const {
        return identifier_;
    }

    const PMethodBody& getMethodBody() const {
        return method_body_;
    }

    void accept(IVisitor *visitor) const { visitor->visit(this); }
protected:
    std::string identifier_;
    PType type_;
    PMethodBody method_body_;
    std::string privacy_;

    void setPos(const MC::YYLTYPE pos) { pos_ = pos; }
};

typedef std::shared_ptr<MethodDeclaration> PMethodDeclaration;
}
