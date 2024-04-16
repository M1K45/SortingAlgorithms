#pragma once 
#include <iostream>

float srednia (int tab[], int n){ 
    float suma =0;
    for (int i =0; i < n; i++){
        suma += tab[i];
    }
    return suma / n;
}

float mediana (int tab[], int n){ 
    if (n % 2 == 0){ 
        return (tab[n/2] + tab[(n/2)-1]) / 2;
    }
    else return tab[((n -1)/2)];
}

void sortCheck (int tab[], int n){
    for (int i =1; i <n ; i++){
        if (tab[i] < tab[i-1]){
            std::cout << "\nTablica nie jest posortowana!\n";
            return;
        }
    }
    std::cout << "\n Tablica jest posortowana\n";
}

void display(int tab[], int n){
    for (int i=0; i < n ; i++){
        std::cout << tab[i] << ", ";
    }
    std::cout << "\n";
}


