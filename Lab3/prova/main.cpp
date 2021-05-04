#include <iostream>

int main() {
    std::unique_ptr<int[]> d(new int[10]);
    for(int i=0; i<10; i++)
        d[i] = i;
    for(int i=0; i<10; i++)
        std::cout << d[i];
    std::cout << '\n';
    return 0;
}
