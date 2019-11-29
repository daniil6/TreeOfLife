#ifndef CNODE_H
#define CNODE_H

#include "base_list.h"

class CPerson
{
private:
    CBaseList<CPerson>* m_parent;
    CBaseList<CPerson>* m_child;
    CBaseList<CPerson>* m_marriage;
    CBaseList<CPerson>* m_halfHearted;

    std::string m_id;

    std::string GetId();

public:
    CPerson(const std::string& id);
    ~CPerson();

    void Print();

    void SetParent(std::string parent);
    CPerson* GetParent(std::string parent);

    CPerson* GetChild(std::string child);
    void SetChild(std::string child);

    CPerson* GetMarriage(std::string marriage);
    void SetMarriage(std::string marriage);

    CPerson* GetHalfHearted(std::string halfHearted);
    void SetHalfHearted(std::string halfHearted);
};

#endif // CNODE_H