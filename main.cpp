#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {

    LinkedList<int> list;
    cout << "created empty linked list" << endl;
    list.print();

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(10);
    list.add(40);
    list.add(50);
    list.add(60);

    cout << "loaded list " << endl;
    list.print();

    cout << "testing add at index " << endl;
    list.add(2, 100);
    list.print();

    cout << "testing remove at index" << endl;
    list.remove_at_index(2);
    list.print();

    cout << "testing remove data" << endl;
    list.remove(20);
    list.print();

    cout << "testing remove all" << endl;
    list.removeAll(10);
    list.print();

    cout << "testing list size report" << endl;
    cout << "current list size: " << list.getSize() << endl;

    return 0;
}