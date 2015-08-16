/**
 * Josh Harshman
 * Terribly Coded (But gets the job done) LinkedList Tester
 * */

#include <iostream>
#include "LinkedList.cpp"
#include "BigInteger.h"

using namespace std;
void displaymenu();
int main() {

    LinkedList<BigInt> BigIntList;
    LinkedList<int> SmallIntList;

    int choice;
    do {
        displaymenu();
        cout << "enter selection: ";
        cin >> choice;
        switch (choice) {
            case 1:
                BigIntList.add(BigInt("100"));
                BigIntList.add(BigInt("200"));
                BigIntList.add(BigInt("300"));
                BigIntList.print();
                break;
            case 2:
                SmallIntList.add(1);
                SmallIntList.add(2);
                SmallIntList.add(3);
                SmallIntList.print();
                break;
            case 3:
                //run automated tests for Big integer
                cout << "Adding data" << endl;
                BigIntList.add(BigInt("400"));
                BigIntList.print();
                cout << "removing data" << endl;
                BigIntList.remove(BigInt("400"));
                BigIntList.print();
                cout << "adding at index" << endl;
                BigIntList.add(2, BigInt("400"));
                BigIntList.print();
                cout << "removing at index" << endl;
                BigIntList.remove_at_index(2);
                BigIntList.print();
                cout << "adding a bunch of data" << endl;
                BigIntList.add(BigInt("100"));
                BigIntList.add(BigInt("100"));
                BigIntList.add(BigInt("100"));
                BigIntList.add(BigInt("100"));
                BigIntList.print();
                cout << "removing all instances of that data" << endl;
                BigIntList.removeAll(BigInt("100"));
                BigIntList.print();
                break;
            case 4:
                //run automated tests
                cout << "Adding data" << endl;
                SmallIntList.add(4);
                SmallIntList.print();
                cout << "removing data" << endl;
                SmallIntList.remove(4);
                SmallIntList.print();
                cout << "adding at index" << endl;
                SmallIntList.add(2, 4);
                SmallIntList.print();
                cout << "removing at index" << endl;
                SmallIntList.remove_at_index(2);
                SmallIntList.print();
                cout << "adding a bunch of data" << endl;
                SmallIntList.add(1);
                SmallIntList.add(1);
                SmallIntList.add(1);
                SmallIntList.add(1);
                SmallIntList.print();
                cout << "removing all instances of that data" << endl;
                SmallIntList.removeAll(1);
                SmallIntList.print();
                break;
            case 5:
                //destroy list
                BigIntList.clear();
                SmallIntList.clear();
                break;
            default:
                cout << "input not recognized" << endl;
        }
    }while (choice != 6);

    return 0;
}

void displaymenu() {
    cout << "1. Create list of Big Integers" << endl;
    cout << "2. Create list of Integers" << endl;
    cout << "3. Run automated tests for Big Integer" << endl;
    cout << "4. Run automated tests for Integer" << endl;
    cout << "5. Destroy List" << endl;
    cout << "6. Quit" << endl;
}