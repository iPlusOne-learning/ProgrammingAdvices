#pragma once

#include <iostream>
using namespace std;

template <class T> 
class clsDynamicArray
{
    protected:

    int _Size = 0;
    T *_TempArray;

    public:
    T *OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;
        _Size = Size;
        OriginalArray = new T [_Size];
    }

    bool SetItem(int Index, T NewValue)
    {
        if (Index >= _Size)
            return false;
        
        OriginalArray[Index] = NewValue;
        return true;
    }

    bool IsEmpty()
    {
        return _Size < 0 ? true : false;
    }

    int Size()
    {
        return _Size;
    }

    void PrintList()
    {
        for (int i = 0; i < _Size; i++)
        {
            cout << OriginalArray[i] << " ";
        }
        cout << "\n";
    }

    ~clsDynamicArray()
    {
        delete [] OriginalArray;
    }

    // bool Resize(int NewSize)
    // {
    //     if (NewSize < 0)
    //         return false;
    //     T *_TempArray = new T[NewSize];
    //     for (int i = 0; i < _Size; i++)
    //     {
    //         _TempArray[i] = OriginalArray[i];
    //     }
    //     delete [] OriginalArray;
    //     OriginalArray = _TempArray;
    //     _Size = NewSize;
    //     return true;
    // }

    void Resize(int NewSize)
    {
        if (NewSize < 0)
        {
            NewSize = 0;
        }
        _TempArray = new T[NewSize];

        if (NewSize < _Size)
            _Size = NewSize;

        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }
        _Size = NewSize;
        delete [] OriginalArray;
        OriginalArray = _TempArray;
    }

    void Reverse()
    {
        _TempArray = new T[_Size];
        int counter = 0;

        for (int i = _Size; i >= 0 ; i--)
        {
            _TempArray[counter] = OriginalArray[i - 1];
            counter++;
        }
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }

    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete [] OriginalArray;
        OriginalArray = _TempArray;
    }
};