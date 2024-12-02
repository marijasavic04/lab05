#include "Stack.h"
Vector3D error;
void Stack::push(const Vector3D &m){

    this->stack.add(m);
    this->tos++;
}
bool Stack::isEmpty(){
    return (this->tos == -1);
}
Vector3D &Stack::pop(){
    if(isEmpty()){
        return error;
    }
    tos--;
    return this->stack.remove();
}
void Stack::forEach(void (*f)(const Vector3D&)){
    while(!isEmpty()){
        Vector3D v;
        v=pop();
        f(v);
    }
}