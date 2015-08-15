#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {

    LinkedList<int> list;
    cout << "created empty linked list" << endl;
    list.print();

    std::cout << "As you can see. no content. Now adding content..." << std::endl;

    list.add(10);
    list.print();

    return 0;
}