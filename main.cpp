#include "measure.h"

int main()
{   
    char wybor;
    std::cout << "Co chcesz zrobić?\n";
    std::cout << "a) Zwizualizowac poprawne dzialanie algorytmów (na pierwszych 40 danych z akrusza)\n";
    std::cout << "b) Przeprowadzić pomiary czasu, sredniej i mediany wybranego algorytmu na wybranej ilosci danych\n";
    std::cout << "Wybierz litere odpowiadającą Twojej decycji: "; std::cin >> wybor;

    switch (wybor)
    {
    case 'a':{
        int tabHeap[40], tabShell[40], tabMerge[40];

        takeData(tabHeap, 40);
        takeData(tabShell, 40);
        takeData(tabMerge, 40);

        std::cout<< "\nPierwsze 40 elementow sortowanych tablic:\n";
        display (tabHeap, 40); 

        heapsort(tabHeap, 40);
        shellSort(tabShell, 40);
        mergesort(tabMerge, 0, 39, 40);

        std::cout << "\nTablica sortowana algorytmem heapsort:\n";
        display(tabHeap, 40);

        std::cout << "\nTablica sortowana algorytmem Shell sort:\n";
        display(tabShell, 40);

        std::cout << "\nTablica sortowana algorytmem mergesort:\n";
        display(tabMerge, 40);
        break;
    }
    
    case 'b':{
        measure();
        break;
    }
    default:{
        std::cout << "Wybierz liczbe odpowiadajaca mozliwej decycji\n";
        break;
    }
    }
    return 0;
}
