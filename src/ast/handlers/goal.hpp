#pragma once

#include <string>
#include <memory>
#include <cassert>

#include <yyltype.hpp>
#include <handlers/visitable.hpp>
#include <visitors/ivisitor.hpp>

#include <handlers/var_declaration.hpp>
#include <handlers/statements.hpp>
#include <handlers/main_class.hpp>

namespace ast {

class Goal : public IVisitable {
public:
    Goal(const PMainClass &main_class,
            MC::YYLTYPE pos) : main_class_(main_class)  { setPos(pos);
    }

    const PMainClass& getMainClass() const {
        return main_class_;
    }

    void accept(IVisitor *visitor, bool need_new_line = true) const { visitor->visit(this, need_new_line); }
protected:

    PMainClass main_class_;
    void setPos(const MC::YYLTYPE pos) { pos_ = pos; }
};

typedef std::shared_ptr<Goal> PGoal;
}