#include "person.h"

#include <iostream>

CPerson::CPerson(const std::string& id)
    : m_id(id)
{
    // printf("Constructor CPerson %p\n", this);
    m_parent = nullptr;
    m_child = nullptr;
    m_marriage = nullptr;
    m_halfHearted = nullptr;
}

CPerson::~CPerson()
{
    // printf("Destructor CPerson %p\n", this);
}

std::string CPerson::GetId()
{
    return m_id;
}

void CPerson::Print()
{
    std::cout << m_id << std::endl;

    CBaseList<CPerson>* t_parent = m_parent;
    while(t_parent != nullptr) {
        t_parent->GetData()->Print();
        t_parent = t_parent->GetNext();
    }

    CBaseList<CPerson>* t_child = m_child;
    while(t_child != nullptr) {
        t_child->GetData()->Print();
        t_child = t_child->GetNext();
    }
}

// Parent
void CPerson::SetParent(std::string parent)
{
    if(m_parent == nullptr)
        m_parent = new CBaseList<CPerson>(new CPerson(parent));
    else
        m_parent->PushBack(new CPerson(parent));
}

CPerson* CPerson::GetParent(std::string parent)
{
    return m_parent->Find(parent, &CPerson::GetId);
}

// Child
void CPerson::SetChild(std::string child)
{
    if(m_child == nullptr)
        m_child = new CBaseList<CPerson>(new CPerson(child));
    else
        m_child->PushBack(new CPerson(child));
}

CPerson* CPerson::GetChild(std::string child)
{
    return m_child->Find(child, &CPerson::GetId);
}

// Marriage
void CPerson::SetMarriage(std::string marriage)
{
    if(m_marriage == nullptr)
        m_marriage = new CBaseList<CPerson>(new CPerson(marriage));
    else
        m_marriage->PushBack(new CPerson(marriage));
}

CPerson* CPerson::GetMarriage(std::string marriage)
{
    return m_marriage->Find(marriage, &CPerson::GetId);
}

// Half-hearted
void CPerson::SetHalfHearted(std::string halfHearted)
{
    if(m_halfHearted == nullptr)
        m_halfHearted = new CBaseList<CPerson>(new CPerson(halfHearted));
    else
        m_halfHearted->PushBack(new CPerson(halfHearted));
}

CPerson* CPerson::GetHalfHearted(std::string halfHearted)
{
    return m_halfHearted->Find(halfHearted, &CPerson::GetId);
}
