#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <time.h>



void takeData(int tablica[], int rozmiar){
    clock_t start;
    double duration;
 std::fstream plik;
    plik.open("dane.csv", std::fstream::in);

    
    if (plik.is_open())
    {
        start = clock();


        std::string naglowek;
        getline(plik, naglowek);

        int licznik =0;
        std::string obecnyWiersz;
        while (getline(plik, obecnyWiersz))
        {

            if (rozmiar != 0 && licznik == rozmiar)
            {
                break;
            }
            std::stringstream calyWiersz(obecnyWiersz);
            std::string l_p, tytul, ocena;

            getline(calyWiersz, l_p, ',');
            getline(calyWiersz, tytul, ',');

            while (tytul.front() == '"' && tytul.back() != '"')
            {
                std::string additionalTitlePart;
                getline(calyWiersz, additionalTitlePart, ',');
                tytul += ',' + additionalTitlePart;
            }

            getline(calyWiersz, ocena, ',');

            if (!ocena.empty())
            {
                tablica[licznik] = stoi(ocena);
                licznik ++;
            }
        }
        duration = clock() - start;
        std::cout << "czas przeszukiwania z filtrownaiem pliku .csv, do otrzymania " << rozmiar << " elementow wynosi " << double(duration)/CLOCKS_PER_SEC << " s.\n";
        plik.close();
    }

}