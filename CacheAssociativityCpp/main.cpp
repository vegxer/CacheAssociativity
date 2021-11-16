#include <iostream>
#include <intrin.h>
#include "LinkedList.h"


typedef unsigned long long ull;


int main()
{
    int size;
    printf_s("Input max array size: ");
    scanf_s("%d", &size);

    for (int i = 1; i <= size; ++i)
    {
        LinkedList* list = new LinkedList(i);
        ull startTime = __rdtsc();
        list->walk();
        ull endTime = __rdtsc();
        printf_s("Time for %d elements: %llu ticks\n", i, endTime - startTime);
        delete list;
    }

    return 0;
}
