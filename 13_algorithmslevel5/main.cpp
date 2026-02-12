#include <iostream>
<<<<<<< HEAD
#include "clsDynamicArray.h"
=======
#include "clsMyStack.h"
>>>>>>> ad546c3 (Stack+Queue are done)

using namespace std;

int main()
{
    clsMyStack<int> MyStack;

<<<<<<< HEAD
    clsDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty? " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size: " << MyDynamicArray.Size() << "\n";
    cout << "\nArray Items: \n";
    MyDynamicArray.PrintList();

    cout << "\nItem(2): " << MyDynamicArray.GetItem(2) << "\n";
    MyDynamicArray.Reverse();
    cout << "\nArray Items after Reverse: \n";
    MyDynamicArray.PrintList();

    MyDynamicArray.Clear();
    cout << "\nArray after clear: \n";
    MyDynamicArray.PrintList();

=======
    MyStack.push(10);
    MyStack.push(20);
    MyStack.push(30);
    MyStack.push(40);
    MyStack.push(50);

    cout << "\nStack: \n";
    MyStack.Print();

    cout << "\nStack size: " << MyStack.Size();
    cout << "\nStack top: " << MyStack.Top();
    cout << "\nStack bottom: " << MyStack.Bottom();

    MyStack.pop();
    cout << "\n\nStack after pop(): \n";
    MyStack.Print();

    // extension #1
    cout << "\n\nItem(2): " << MyStack.GetItem(2);
    // extension #2
    MyStack.Reverse();
    cout << "\n\nStack after reverse(): \n";
    MyStack.Print();
    // extension #3
    MyStack.UpdateItem(2, 6000);
    cout << "\n\nStack after reverse(): \n";
    MyStack.Print();
    // extension #4
    MyStack.InsertAfter(2, 800);
    cout << "\n\nStack after Inserting 800 after Item(2): \n";
    MyStack.Print();
    //extension #5
    MyStack.InsertAtFront(1000);
    cout << "\n\nStack after Inserting 1000 at front: \n";
    MyStack.Print();

    //extension #6
     MyStack.InsertAtBack(1000);
    cout << "\n\nStack after Inserting 1000 at front: \n";
    MyStack.Print();
    //extension #7
    MyStack.Clear();
    cout << "\n\nStack after clear(): \n";
    MyStack.Print();

    return 0;
>>>>>>> ad546c3 (Stack+Queue are done)
}