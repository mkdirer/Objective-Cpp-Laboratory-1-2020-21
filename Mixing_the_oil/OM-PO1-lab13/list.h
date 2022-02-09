#pragma once

#include <ostream>
#include <iostream>

// szblon struktury reprezentujący węzeł, przechowuje dane dowolnego typu oraz wskaźniki na poprzedni i następny element
template <typename T>
struct Node
{
    
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    
};

// szablon klasy reprezentujący listę, przechowuje wskaźniki na początek i koniec listy
template <typename T>
class List
{
    
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

public:

    // klasa reprezentująca iterator, przechowuje adres węzła oraz informację o tym, czy przechodzi po elementach do przodu czy do tyłu
    class Iterator
    {
        
        private:
            Node<T>* data;
            bool isReverse = false;
            
        public:
        
            // konstruktor
            Iterator(Node<T>* data, bool isReverse = false) : data(data), isReverse(isReverse)
            {
            }
            
            // operator inkrementacji, zwraca iterator na następny element listy
            Iterator& operator++()
            {
                data = isReverse ? data->prev : data->next;
                return *this;
            }
            
            // operator porównanie (not_eq), porównuje iteratory
            bool operator!=(const Iterator& right) const
            {
                return right.data != data;
            }
            
            // operator wyłuskania
            T operator*() const
            {
                return data->data;
            }
            
            // operator strzałki
            T* operator->()
            {
                return &data->data;
            }
            
    };
    
    List() = default;
    
    // destruktor
    ~List()
    {
        auto it = head->next;
        
        while(it != tail)
        {
            delete it->prev;
            it = it->next;
        }
        
        delete tail;
    }
    
    // konstruktor z tablicy
    List(size_t size, const T* input)
    {
        const T* it = input;
        while(it != input + size)
        {    
            push_back(*it);
            ++it;
        }
    }
    
    // konstruktor kopiujący
    List(const List& cp)
    {
        for(auto it = cp.begin(); it != cp.end(); ++it)
        {
            push_back(*it);
        }
        
        push_back(*cp.end());
    }
        
        
     void push_back(T elem)
     {
         
            
        if(!head)
        {
            head = new Node<T>();
            head->data = elem;
            tail = head;
        }
        else
        {
            auto& next = tail->next;
            next = new Node<T>();
            next->data = elem;
            next->prev = tail;
            tail = next;
        }
     }
     
     void pop_back()
     {
         if(tail)
         {
             Node<T>* newTail = tail->prev;
             newTail->next = nullptr;
             delete tail;
             tail = newTail;
         }
     }
     
     Iterator begin()  const
     {
         return Iterator(head);
     }
     
     Iterator end()  const
     {
         return Iterator(tail);
     }
     
     Iterator rbegin()  const
     {
         return Iterator(tail, true);
     }
     
     Iterator rend()  const
     {
         return Iterator(head, true);
     }
     
     T& front()
     {
         return head->data;
     }
     
     template <typename B>
     friend std::ostream& operator<<(std::ostream& str, const List<B>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& str, const List<T>& list)
{
    //{"0", "1", "2", "3", "4"}
    str << "{\"" << *list.begin() << "\"";
    
    for(auto it = ++list.begin(); it != list.end(); ++it)
    {
        str << ", \"" << *it << "\"";
    }
    
    str << ", \"" << *list.end() << "\"" <<"}";
    return str;
}