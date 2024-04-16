#pragma once 

#include <iostream>
#include "takeData.h"
#include "mergeSort.h"
#include "heapSort.h"
#include "shellSort.h"
#include "Check&Calculate.h"
#include <time.h>

void measure (){
    int rozmiar;
    std::cout << "Podaj rozmiar tablicy: "; // maksymalny po odfiltrowaniu to 962903
    std::cin >> rozmiar;

    int *tablica;
    tablica = new int [rozmiar];

    takeData(tablica, rozmiar);
    
    std::cout << "W strukturze znajduje się " << rozmiar << " danych.\n";
    std::cout << "Jakim algorytmem zamierzasz je posortowac?\n";
    std::cout << "1) Heap Sort\n";
    std::cout << "2) Shell Sort\n";
    std::cout << "3) Merge sort\n";
    std::cout << "Wybierz cyfrę odpowiadającą algorymtowi: ";
    int choice; std::cin >> choice;

    clock_t start;
    double duration;

    switch (choice)
    {
    case 1:{
        start = clock();
        heapsort(tablica, rozmiar);
        duration = clock() - start;

        sortCheck(tablica, rozmiar);
        std::cout<< "\n";
        std::cout << "czas sortowania heap sortem dla " << rozmiar << " elementow wynosi " << double(duration)/CLOCKS_PER_SEC << " s.\n";
        std::cout << "srednia: " << srednia(tablica, rozmiar) << "\nmediana: " << mediana(tablica, rozmiar) << std::endl; 
        break;

        }
    case 2:{
        start = clock();
        shellSort(tablica, rozmiar);
        duration = clock() - start;
        sortCheck(tablica, rozmiar);
 
        std::cout<< "\n";
        std::cout << "czas sortowania shell sortem dla " << rozmiar << " elementow wynosi " << double(duration)/CLOCKS_PER_SEC << " s.\n";
        std::cout << "srednia: " << srednia(tablica, rozmiar) << "\nmediana: " << mediana(tablica, rozmiar) << std::endl; 
        break;

        }
    case 3:{
        start = clock();
        mergesort(tablica, 0, rozmiar -1, rozmiar);
        duration = clock() - start;

        sortCheck(tablica, rozmiar);
        std::cout<< "\n";
        std::cout << "czas sortowania merge sortem dla " << rozmiar << " elementow wynosi " << double(duration)/CLOCKS_PER_SEC << " s.\n";
        std::cout << "srednia: " << srednia(tablica, rozmiar) << "\nmediana: " << mediana(tablica, rozmiar) << std::endl; 
        break;
        }
    
    default:{
        std::cout << "Wybierz liczbe odpowiadajaca algorytmowi.\n";
        break;
    }

    delete [] tablica;

}
}