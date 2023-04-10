#include <iostream>
#include <cstdlib>
#include <ctime>
#include "euclid.h"
#include "test.h"

void runTests(int numTests) {
    std::srand(std::time(nullptr));

    int a, b, recursiveResult, iterativeResult;
    clock_t recursiveTime, iterativeTime;

    for (int i = 0; i < numTests; i++) {
        // Generate two random integers
        a = std::rand();
        b = std::rand();

        // Run recursive Euclid algorithm and measure time
        recursiveTime = clock();
        recursiveResult = euclid_recursive(a, b);
        recursiveTime = clock() - recursiveTime;

        // Run iterative Euclid algorithm and measure time
        iterativeTime = clock();
        iterativeResult = euclid_iterative(a, b);
        iterativeTime = clock() - iterativeTime;

        // Check if results match
        if (recursiveResult != iterativeResult) {
            std::cout << "Error: Recursive and iterative results do not match." << std::endl;
            return;
        }

        // Print test results
        std::cout << "Test " << i + 1 << ": a = " << a << ", b = " << b << ", result = " << recursiveResult
            << ", recursive time = " << ((double)recursiveTime) / CLOCKS_PER_SEC << "s"
            << ", iterative time = " << ((double)iterativeTime) / CLOCKS_PER_SEC << "s" << std::endl;
    }
}