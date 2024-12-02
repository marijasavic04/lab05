#include "Stack.h"
#include <climits>

Vector3D error_vect(INT_MIN, INT_MIN, INT_MIN); // moras neku inicijalizaciju uraditi

void Stack::push(const Vector3D &m)
{

    this->stack.add(m);
    this->tos++;
}
bool Stack::isEmpty()
{
    return (this->tos == -1);
}
Vector3D &Stack::pop()
{
    if (isEmpty())
    {
        return error_vect;
    }
    tos--;
    return this->stack.remove();
}
void Stack::forEach(void (*f)(const Vector3D &))
{
    while (!isEmpty())
    {
        Vector3D v;
        v = pop();
        f(v);
    }
}