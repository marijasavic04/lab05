#include "Array.h"
#include <climits>

Vector3D error(INT_MIN, INT_MIN, INT_MIN); // moras neku inicijalizaciju uraditi

Array::~Array()
{
    delete[] arr;
}
Array::Array(const Array &other)
{
    this->capacity = other.capacity;
    this->size = other.size;

    arr = new Vector3D[capacity];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = other.arr[i];
    }
}
Array::Array(Array &&other)
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->arr = other.arr;

    other.capacity = 0;
    other.size = 0;
    other.arr = nullptr;
};
Array &Array::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] this->arr;
        this->capacity = other.capacity;
        this->size = other.size;

        arr = new Vector3D[capacity];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
};
Array &Array::operator=(Array &&other)
{
    if (this != &other)
    {
        delete[] this->arr;
        this->capacity = other.capacity;
        this->size = other.size;
        this->arr = other.arr;

        other.capacity = 0;
        other.size = 0;
        other.arr = nullptr;
    }
    return *this;
}
Vector3D &Array::at(int index, bool &s) const
{
    if (index >= size || index < 0)
    {
        s = false;
        return error;
    }
    s = true;
    return this->arr[index];
};
Vector3D &Array::at(int index) const
{
    if (index >= size || index < 0)
    {
        return error;
    }
    return this->arr[index];
};
void Array::add(const Vector3D &other)
{
    if (this->size >= this->capacity)
    {
        this->realloc(this->capacity * 2);
    }
    this->arr[size] = other;
    this->size++;
}
Vector3D &Array::remove()
{
    if (this->size == 0)
    {
        return error;
    }
    this->size--;
    return this->arr[size - 1];
}
void Array::realloc(int suggestedCapacoty)
{
    int newCapacity = (suggestedCapacoty > 0 ? suggestedCapacoty : 1);
    Vector3D *result = new Vector3D[newCapacity];
    for (int i = 0; i < this->size; i++)
    {
        result[i] = this->arr[i];
    }
    delete[] this->arr;
    this->capacity = newCapacity;
    this->arr = result;
}