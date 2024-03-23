#include <iostream>
#include <iomanip>

#include "single_linked_list.h"

int main() {
    List l;     // default
    l.Add(-1);

    for (int i = 0; i < 19; ++i) l.Add(i);
    //l.Add(19);

    std::cout << l;

    l.ElevationShuffle();
    std::cout << l;
    l.ElevationShuffle();
    std::cout << l;
    l.ElevationShuffle();
    std::cout << l;

    return 0;
}