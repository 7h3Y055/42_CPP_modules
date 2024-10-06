#pragma once

template <class T>
class Array
{
private:
    T *arr;
    int n;
public:
    Array(): arr(NULL), n(0){
    }
    Array(unsigned int n):n(n){
        arr = new T[n];
    }
    Array(Array const &copy):n(copy.n){
        arr = new T[copy.size()];
        for (int i = 0; i < copy.size(); i++){
            arr[i] = copy.arr[i];
        }
    }
    Array &operator=(Array const &copy){
        if (this != &copy){
            n = copy.n;
            if (!arr)
                arr = new T[copy.size()];
            else{
                delete[] arr;
                arr = new T[copy.size()];
            }
            for (int i = 0; i < copy.size(); i++){
                arr[i] = copy.arr[i];
            }
        }
        return *this;
    }
    T &operator[](int i){
        if (i >= n || i < 0){
            throw std::out_of_range("[!] Index out of range");
        }
        else
            return arr[i];
    }
    const T &operator[](int i) const{
        if (i >= n || i < 0){
            throw std::out_of_range("[!] Index out of range");
        }
        else
            return arr[i];
    }
    ~Array(){
        delete[] arr;
    }



    int size() const{
        return n;
    }
};
