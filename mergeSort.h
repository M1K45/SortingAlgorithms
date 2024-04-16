#pragma once 

void merge (int tab[], int firstIndex, int midIndex, int lastIndex, int size){
    int f = firstIndex; 
    int m = midIndex + 1; 
    int t = firstIndex; 
    int temp [size]; 

    while (f <= midIndex && m <= lastIndex){ 
        if (tab[f] <= tab[m]){ 
            temp[t] = tab[f];
            t++; f++;
        }
        else{
            temp[t] = tab[m];
            t++; m++;
        }
    }

    while (f <= midIndex){
        temp[t] = tab[f];
        f++; t++;
    }

    while (m <= lastIndex){
        temp[t] = tab[m];
        m++; t++;
    }

    for (int i=firstIndex; i <= lastIndex; i++){
        tab[i] = temp[i];
    }
}



void mergesort (int tab[], int firstIndex, int lastIndex, int size){
    if (firstIndex < lastIndex){
        int midIndex = (firstIndex + lastIndex) / 2;

        mergesort (tab, firstIndex, midIndex, size);
        
        mergesort (tab, midIndex+1, lastIndex, size);

        merge (tab, firstIndex, midIndex, lastIndex, size);
    }
}

