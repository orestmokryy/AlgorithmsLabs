#include <iostream>
#include <stdlib.h>
using namespace std;
class Printer
{
    int arrayLength;
};
void createFilledArray(int arrayLength, int primaryParam[], int secondaryParam[])
{
    for (int currentElement = 0; currentElement < arrayLength; currentElement++)
    {
        cout << "Enter parameters for Printer#" << currentElement + 1<<" Price: ";
        cin >> primaryParam[currentElement];
        cout<<"UAH; Speed: ";
        cin >> secondaryParam[currentElement];
    }
}
void InsertionSort(int numLength, int mainParam[], int secondaryParam[])
{
    int i, j, key, key2;
    for (j = 1; j < numLength; j++)
    {
        key = mainParam[j];
        key2 = secondaryParam[j];
        for (i = j - 1; (i >= 0) && (mainParam[i] < key); i--)
        {
            mainParam[i + 1] = mainParam[i];
            secondaryParam[i + 1] = secondaryParam[i];
        }
        mainParam[i + 1] = key;
        secondaryParam[i + 1] = key2;
    }
    return;
}
void merge(int primaryParam[], int secondaryParam[], int l, int m, int r) 
{ 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int Left[n1], Right[n2], Left2[n1], Right2[n2]; 
    for(int i = 0; i < n1; i++) {
        Left[i] = primaryParam[l + i]; 
        Left2[i] = secondaryParam[l + i];
    }     
    for(int j = 0; j < n2; j++){
        Right[j] = primaryParam[m + 1 + j]; 
        Right2[j] = secondaryParam[m + 1 + j]; 
    }
    int firstSubarrayIndex = 0;   
    int secondSubarrayIndex = 0;    
    int k = l;      
    while (firstSubarrayIndex < n1 && secondSubarrayIndex < n2) 
    { 
        if (Left[firstSubarrayIndex] <= Right[secondSubarrayIndex])  
        { 
            primaryParam[k] = Left[firstSubarrayIndex];
            secondaryParam[k] = Left2[firstSubarrayIndex];
            firstSubarrayIndex++; 
        } 
        else 
        { 
            primaryParam[k] = Right[secondSubarrayIndex]; 
            secondaryParam[k] = Right2[secondSubarrayIndex]; 
            secondSubarrayIndex++; 
        } 
        k++; 
    } 
    while (firstSubarrayIndex < n1)  
    { 
        primaryParam[k] = Left[firstSubarrayIndex]; 
        secondaryParam[k] = Left2[firstSubarrayIndex]; 
        firstSubarrayIndex++; 
        k++; 
    } 
    while (secondSubarrayIndex < n2) 
    { 
        primaryParam[k] = Right[secondSubarrayIndex]; 
        secondaryParam[k] = Right2[secondSubarrayIndex]; 
        secondSubarrayIndex++; 
        k++; 
    } 
} 
void mergeSort(int primaryParam[], int secondaryParam[], int left, int right) 
{ 
    if (left < right) 
    { 
        int middle = left + (right - left) / 2; 
        mergeSort(primaryParam, secondaryParam, left, middle); 
        mergeSort(primaryParam, secondaryParam, middle + 1, right); 
        merge(primaryParam, secondaryParam, left, middle, right); 
    } 
} 
void printArray(int arrayLength, int firstParameter[], int secondParameter[])
{
    for (int currentElement = 0; currentElement < arrayLength; currentElement++)
    {
        cout << "Name: Printer#" << currentElement << "; Price: " << firstParameter[currentElement] << "UAH; Speed: " << secondParameter[currentElement] << " pages per minute.\n";
    }
}
int main()
{
    int arrayLength, priceArray[arrayLength], speedArray[arrayLength];
    std::cout << "Enter the number of printers: ";
    std::cin >> arrayLength;
    
    createFilledArray(arrayLength, priceArray, speedArray);
    cout << "Unsorted:\n";
    printArray(arrayLength, priceArray, speedArray);

    InsertionSort(arrayLength, speedArray, priceArray);
    cout << "Sorted(insertion, descending):\n";
    printArray(arrayLength, priceArray, speedArray);

    mergeSort(priceArray, speedArray, 0, arrayLength - 1); 
    cout<<"Sorted(merge, ascending):\n";
    printArray(arrayLength, priceArray, speedArray);
}