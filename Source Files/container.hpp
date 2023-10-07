#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <iostream>

template <class T>

class container{
    public:
        container();
        ~container();
        bool push_back(T val);
        bool push_front(T val);
        T pop_back();
        T pop_front();
        int size_of_container();
        int capacity_of_container();
        bool empty();

        T operator[](const int& index);
        T get(int index);
        //bool insertAt(T val, int index);
        //
    private:
        void resize(bool increase);
        bool shiftUpFrom(int index);
        bool shiftDownFrom(int index);
        int size;
        int capacity;
        T * array;

};

#endif