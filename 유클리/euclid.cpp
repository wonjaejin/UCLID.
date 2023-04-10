#include "euclid.h"

int euclid_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return euclid_recursive(b, a % b);
}

int euclid_iterative(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}