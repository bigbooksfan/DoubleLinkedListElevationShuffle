#include <iostream>
#include <iomanip>

#include "single_linked_list.h"

int main() {
    List l;     // default
    //l.Add(-1);

    for (int i = 1; i <= 10; ++i) l.Add(i);

    std::cout << l;


    l.Reverse();
    std::cout << l;
    l.PrintAddresses();

#if 0
    for (int i = 0; i < 9; ++i) {
        l.ElevationShuffle();
        std::cout << l;
    }

    l.ElevationShuffle();
    std::cout << l;
    l.ElevationShuffle();
    std::cout << l;
    //l.PrintAddresses();
#endif

    return 0;
}