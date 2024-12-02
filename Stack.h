#pragma once
#include "Vector3D.h"
#include "Array.h"

class Stack{
    private:
      Array stack;
      int tos=-1;
    public:
      Stack(){
        this->stack=Array();
      }
      void push(const Vector3D &m);
      Vector3D &pop();
      bool isEmpty();
      void forEach(void (*f)(const Vector3D&));
};