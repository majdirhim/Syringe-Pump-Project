#ifndef POPUP_DEPARTMENT_HPP
#define POPUP_DEPARTMENT_HPP

#include <gui_generated/containers/popup_DepartmentBase.hpp>

class popup_Department : public popup_DepartmentBase
{
public:
    popup_Department();
    virtual ~popup_Department() {}

    virtual void initialize();
protected:
};

#endif // POPUP_DEPARTMENT_HPP
