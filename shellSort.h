#pragma once
#include <math.h>
#include <iostream>

int KnuthInterval[13] = { 1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161 };

void shellSort(int tab[], int n) {
	
	int counter = 12;

	for (int i = 12; i >= 0; i--) {
		if (KnuthInterval[i] > ceil((float)n / 3)) {
			counter--;
		}
		else break;		
	}

	int bufor = 0; 
		
	for (int j = counter; j >= 0; j--) {
		
		for (int k = KnuthInterval[j]; k < n; k++) {
			
			for (int m = k - KnuthInterval[j]; m >= 0; m -= KnuthInterval[j]) {
				if (tab[m] > tab[m + KnuthInterval[j]]) {
					bufor = tab[m];
					tab[m]  = tab[m + KnuthInterval[j]];
					tab[m + KnuthInterval[j]] = bufor;
				}
			}
		}
	}
}