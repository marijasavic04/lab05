#include <iostream>
#include "Vector3D.h"
#include "Stack.h"
#include "Array.h"

int main()
{
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    Vector3D v3(7, 8, 9);

    std::cout << v1.getX() << v1.getY(), v1.getZ();
    std::cout << v2.getX() << v2.getY(), v2.getZ();
    std::cout << v3.getX() << v3.getY(), v3.getZ();

    return 0;
}

// greske su bile u array.cpp i stack.cpp, "vector3d error" nije inicijalizovan, pa se ne moze koristiti kao vracanje u slucaju greske iz metoda, korigovao sam na nacin na koji je jednom na auditornim radjen.