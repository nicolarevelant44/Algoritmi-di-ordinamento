
/* 
 * File:   main.cpp
 * Author: allievo
 *
 * Created on 21 febbraio 2019, 11.45
 */

#include <iostream>

using namespace std;

/*
 * Ordinamento dei vettori
 */
int main(int argc, char** argv)
{
    int elementi, min_index, aux;
    int * elem;
    cout << "Numero elementi: ";
    cin >> elementi;
    if (elementi < 1) return -1;
    elem = new int[elementi];
    
    
    for (int i = 0; i < elementi; i++)
    {
        cout << "Elemento " << i + 1 << "/" << elementi <<  ": ";
        cin >> elem[i];
    }
    
    for (int i = 0; i < elementi - 1; i++)
    {
        min_index = i;
        for (int in = i; in < elementi; in++)
        {
            if (elem[in] < elem[min_index])
            {
                min_index = in;
            }
        }
        
        if (min_index != i)
        {
            aux = elem[i];
            elem[i] = elem[min_index];
            elem[min_index] = aux;
        }
    }
    
    cout << "\nVettore ordinato:\n";
    
    for (int i = 0; i < elementi; i++)
    {
        cout << elem[i] << " ";
    }
    return 0;
}

