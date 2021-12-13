//
//  main.cpp
//  RGZ
//
//  Created by Mischa Karvasarskyi on 13.12.21.
//

#include <iostream>
#include <chrono>
#include "math.h"
#include "stdio.h"
#include <fstream>
#include <iomanip>
using namespace std::chrono;

std::ofstream F;
std::chrono::time_point<std::chrono::steady_clock> start, end;

    int* OrderedArray(int* MyArray, int Size) {
        for (int i = 0; i < Size; i++)
        {
            MyArray[i] = i;
        }
        return MyArray;
    }

    int* ReverseOrderedArray(int* MyArray, int Size) {
        int j = Size;
        for (int i = 0; i < Size; i++)
        {
            MyArray[i] = j;
            j--;
        }
        return MyArray;
    }

    int* UnorderedArray(int* MyArray, int Size) {
        for (int i = 0; i < Size; i++)
        {
            MyArray[i] = rand() % 45;
        }
        return MyArray;
    }

void Swap(int* MyArray, int i)
{
    int temp;
    temp = MyArray[i];
    MyArray[i] = MyArray[i - 1];
    MyArray[i - 1] = temp;
}


    int* ShakerSort(int* MyArray, int Start, int Size)
    {
        auto start = std::chrono::high_resolution_clock::now();
        int Left, Right, i, j=0, t = -1;
        Left = Start;
        Right = Size-1;
        for (int i = 0; i < Size; i++)
        {
            F << MyArray[i] << '\t';
        }
        F << std::endl;
        while (Left <= Right)
        {
            t += 2;
            for (i = Right; i >= Left; i--) {
                if (MyArray[i - 1] > MyArray[i])
                {
                    Swap(MyArray, i);
                }
            }
            Left++;
            for (i = Left; i <= Right; i++) {
                if (MyArray[i - 1] > MyArray[i])
                {
                    Swap(MyArray, i);
                }
            }
            Right--;
        }
        std::cout << "Size:" << Size << "\n\n";
        for (size_t i = 0; i < Size; i++)
        {
            std::cout << MyArray[i];
        }
        std::cout << "\n\n";
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = (end - start);
        F.open("info.txt", std::ios_base::app);
        F << std::fixed;
        F << "ShakerSort " << Size << ": " << '\t' << duration.count() << " s" << std::endl;
        F.close();
        return 0;
    }

    int* FindArray(int* MyArray, int Start, int Size)
    {
        int i = Start, j = Size-1;
        int tmp;
        float x = MyArray[(Start + Size) / 2];
        do {
            while (MyArray[i] < x)
                i++;
            while (MyArray[j] > x)
                j--;

            if (i <= j)
            {
                if (i < j)
                {
                    tmp = MyArray[i];
                    MyArray[i] = MyArray[j];
                    MyArray[j] = tmp;
                }
                i++;
                j--;
            }
        } while (i <= j);
        if (i < Size)
            FindArray(MyArray, i, Size);
        if (Start < j)
            FindArray(MyArray, Start, j);
        return MyArray;
    }
    int* Quicksort(int* MyArray, int Start, int Size) {
        auto start = std::chrono::high_resolution_clock::now();
        FindArray(MyArray, Start, Size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = (end - start);
        F.open("info.txt", std::ios_base::app);
        F << std::fixed;
        F << "QuickSort " << Size << ": " << '\t' << duration.count() << " s" << std::endl;
        F.close();
        std::cout << "Size:" << Size << "\n\n";
        for (size_t i = 0; i < Size; i++)
        {
            std::cout << MyArray[i];
        }
        std::cout << "\n\n";
        return 0;
    }


int main()
{
    F.open("info.txt", std::ios_base::trunc);
    F.close();
    setlocale(LC_ALL, "Rus");
    const int Size = 45;
    const int sizes = 9;
    int Start = 0;
    int* MyArray = new int[Size];
    int MyOrderedArrays[sizes][Size];
    int MyUnorderedArrays[sizes][Size];
    int MyReverseOrderedArrays[sizes][Size];
    F.open("info.txt", std::ios_base::app);
    F << "\nQuickSort Ordered Arrays\n\n" ;
    F.close();
    std::cout << "QuickSort Ordered Arrays\n\n";
    for (size_t i = 0; i < sizes; i++)
    {
        int arrsize = (i + 1) * 5;
        OrderedArray(MyOrderedArrays[i], arrsize);
        Quicksort(MyOrderedArrays[i], Start, arrsize);
    }
    F.open("info.txt", std::ios_base::app);
    F << "\nQuickSort Unordered Arrays\n" << std::endl;
    F.close();
    std::cout << "QuickSort Unordered Arrays\n\n";
    for (size_t i = 0; i < sizes; i++)
    {
        int arrsize = (i + 1) * 5;
        UnorderedArray(MyUnorderedArrays[i], arrsize);
        Quicksort(MyUnorderedArrays[i], Start, arrsize);
    }
    F.open("info.txt", std::ios_base::app);
    F << "\nQuickSort ReverseOrdered Arrays\n" << std::endl;
    F.close();
    std::cout << "QuickSort ReverseOrdered Arrays\n\n";
    for (size_t i = 0; i < sizes; i++)
    {
        int arrsize = (i + 1) * 5;
        ReverseOrderedArray(MyReverseOrderedArrays[i], arrsize);
        Quicksort(MyReverseOrderedArrays[i], Start, arrsize);
    }
    F.open("info.txt", std::ios_base::app);
    F << "\nShakerSort Ordered Arrays\n\n";
    F.close();
    std::cout << "ShakerSort Ordered Arrays\n\n";
    for (size_t i = 0; i < sizes; i++)
    {
        int arrsize = (i + 1) * 5;
        OrderedArray(MyOrderedArrays[i], arrsize);
        ShakerSort(MyOrderedArrays[i], Start, arrsize);
    }
    F.open("info.txt", std::ios_base::app);
    F << "\nShakerSort Unordered Arrays\n" << std::endl;
    F.close();
    std::cout << "ShakerSort Unordered Arrays\n\n";
    for (size_t i = 0; i < sizes; i++)
    {
        int arrsize = (i + 1) * 5;
        UnorderedArray(MyUnorderedArrays[i], arrsize);
        ShakerSort(MyUnorderedArrays[i], Start, arrsize);
    }
    F.open("info.txt", std::ios_base::app);
    F << "\nShakerSort ReverseOrdered Arrays\n" << std::endl;
    F.close();
    std::cout << "ShakerSort ReverseOrdered Arrays\n\n";
    for (size_t i = 0; i < sizes; i++)
    {
        int arrsize = (i + 1) * 5;
        ReverseOrderedArray(MyReverseOrderedArrays[i], arrsize);
        ShakerSort(MyReverseOrderedArrays[i], Start, arrsize);
    }
}


