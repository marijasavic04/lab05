#pragma once
#include "Vector3D.h"

class Array{
    private:
      int capacity;
      int size;
      Vector3D *arr;
    public:
      Array(int capacity=1): capacity(capacity>0? capacity: 1), size(0){
        arr= capacity>0 ? new Vector3D[capacity]: nullptr;
      }
      ~Array();
      Array(const Array &other);
      Array(Array &&other);
      Array& operator=(const Array &other);
      Array& operator=(Array &&other);
      void add(const Vector3D &other);
      Vector3D& at(int index,bool &s) const;
      Vector3D& at(int index) const;
      Vector3D& remove();
    private:
      void realloc(int suggestedCapacoty);
     
};