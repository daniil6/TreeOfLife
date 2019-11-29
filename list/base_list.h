#ifndef CBASELIST_H
#define CBASELIST_H

#include <string>

template <class T, class... SubT> class CBaseList
{
private:
    T* m_data;

    CBaseList* m_next;
    CBaseList* m_early;

    void SetNext(CBaseList* item)
    {
        m_next = item;
    }

    void SetEarly(CBaseList* item)
    {
        m_early = item;
    }

    CBaseList* GetEarly()
    {
        return m_early;
    }

public:
    CBaseList(T* data)
        : m_data(data)
    {
        m_next = nullptr;
        m_early = nullptr;
    }
    ~CBaseList(){};

    void PushBack(T* data)
    {
        if(m_next != nullptr) {
            CBaseList* item = m_next;

            while(item->GetNext() != nullptr)
                item = item->GetNext();

            item->SetNext(new CBaseList(data));
        } else
            SetNext(new CBaseList(data));
    }

    T* Find(std::string strFind, std::string (T::*pFunction)())
    {
        CBaseList<T, SubT...>* item = this;
        while(item != nullptr) {
            std::string t_string = (item->m_data->*pFunction)();
            if(strFind == t_string)
                return item->m_data;
            item = item->GetNext();
        }
        return nullptr;
    }

    T* GetData()
    {
        return m_data;
    }

    CBaseList* GetNext()
    {
        return m_next;
    }
};

template <class T, class... SubT> class CParentList : public CBaseList<T, SubT...>
{
public:
    CParentList(T* data)
        : CBaseList<T, SubT...>(data){};
    ~CParentList(){};
};

template <class T, class... SubT> class CChildList : public CBaseList<T, SubT...>
{
public:
    CChildList(T* data)
        : CBaseList<T, SubT...>(data){};
    ~CChildList(){};
};

template <class T, class... SubT> class CMarriageList : public CBaseList<T, SubT...>
{
public:
    CMarriageList(T* data)
        : CBaseList<T, SubT...>(data){};
    ~CMarriageList(){};
};

template <class T, class... SubT> class CHalfHeartedList : public CBaseList<T, SubT...>
{
public:
    CHalfHeartedList(T* data)
        : CBaseList<T, SubT...>(data){};
    ~CHalfHeartedList(){};
};

#endif // CBASELIST_H
