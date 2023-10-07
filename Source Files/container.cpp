#include "container.hpp"

template <class T>
container<T>::container(){
    this->capacity = 4;
    this->array = new T[this->capacity];
    for(int i = 0; i < 4; ++i)this->array[i] = NULL;
    this->size = 0;
}

template <class T>
container<T>::~container(){
    if(this->array != NULL){
        delete this->array;
        this->array = NULL;
    }
}

template <class T>
int container<T>::size_of_container(){return this->size;}

template <class T>
int container<T>::capacity_of_container(){return this->capacity;}

template <class T>
bool container<T>::empty(){return this->size == 0 ? true : false;}

template <class T>
bool container<T>::push_back(T val){
    if(this->size == this->capacity)this->resize(true);
    this->array[this->size] = val;
    ++this->size;
    return true;
}

template <class T>
bool container<T>::push_front(T val){
    if(this->size == this->capacity)this->resize(true);
    if(this->shiftUpFrom(0)){
        this->array[0] = val;
        ++this->size;
        return true;
    }
    else return false;
}

template <class T>
T container<T>::pop_front(){
    T val = this->array[0];
    this->shiftDownFrom(0);
    --this.size;
    if(this->size == this->capacity / 2)this->resize(false);
    return val;
}

template <class T>
T container<T>::pop_back(){
    T val = this->array[this->size -1];
    --this.size;
    if(this->size == this->capacity / 2)this->resize(false);
    return val;
}

template <class T>
void container<T>::resize(bool increase){
    this->capacity = increase ? this->capacity * 2 : this->capacity / 2;
    T* newarray = new T[this->capacity];
    for(int i = 0; i < this->size; ++i)newarray[i] = this->array[i];
    
    delete this->array;
    this->array = NULL;
    this->array = newarray;
}

template <class T>
bool container<T>::shiftUpFrom(int index){
    if(index < 0 || index > this->size)return false;

    for(int i = this->size; i >= index; --i){
        if(i == 0)this->array[i] = NULL;
        else this->array[i] = this->array[i - 1];
    }

    return true;
}

template <class T>
bool container<T>::shiftDownFrom(int index){
    if(index < 0 || index > this->size)return false;

    for(int i = index; i <= this->size; ++i){
        if(i == this->size)this->array[i] = NULL;
        else this->array[i] = this->array[i + 1];
    }

    return true;
}

template <class T>
T container<T>::get(int index){return index < 0 || index > this->size ? NULL : this->array[index];}

template <class T>
T container<T>::operator[](const int& index){return this->array[index];}