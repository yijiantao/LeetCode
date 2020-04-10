#include <stack>
#include <iostream>
// #include"coutStackQueue.h"
#include"output_container.h"
#include <vector>

int main(int argc, char const *argv[])
{
    // std::stack<int> s; // works with std::queue also!
    // s.push(1);
    // s.push(2);

    std::vector<int> s = {1,2,3,4,5};

    std::cout << s; // [ 1, 2 ]
    return 0;
}
