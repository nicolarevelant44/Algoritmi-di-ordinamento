#include <iostream>


using namespace std;

// prototipi
void caricaVettore(int[], int);
void algoritmo1(int [], int);
void algoritmo2(int [], int);
void quickSort(int [], int, int);
void swap(int *, int *);
int partition(int [], int, int);

int main(int argc, char** argv)
{
    int dim, t1, t2, *v1;
    double trascorso = 0;
    
    cout << "Inserisci la lunghezza del vettore: ";
    cin >> dim;
    
    v1 = new int[dim];
    caricaVettore(v1, dim);
    
    
    //                          ALGORITMO 1
    
    
    cout << "Inizio algoritmo 1 ..." << endl;
    
    t1 = clock();
    algoritmo1(v1, dim);
    t2 = clock();
    
    trascorso = (double)(t2 - t1) / CLOCKS_PER_SEC;
    cout << "Algoritmo 1: " << to_string(trascorso) << " secondi" << endl << endl;
    for (int i = 0; i < dim; i++)
    {
        cout << i+1 << "/" << dim << ": " << v1[i] << endl;
    }
    
    v1 = new int[dim];
    caricaVettore(v1, dim);
    
    
    //                          ALGORITMO 2
    
    
    cout << "Inizio algoritmo 2 ..." << endl;
    
    t1 = clock();
    algoritmo2(v1, dim);
    t2 = clock();
    
    trascorso = (double)(t2 - t1) / CLOCKS_PER_SEC;
    cout << "Algoritmo 2: " << to_string(trascorso) << " secondi" << endl << endl;
    for (int i = 0; i < dim; i++)
    {
        cout << i+1 << "/" << dim << ": " << v1[i] << endl;
    }
    return 0;
}

void caricaVettore(int v[], int dim)
{
    srand(time(NULL)); // srand() not secure for random password seek
    for (int i = 0; i < dim; i++)
    {
        v[i] = rand() % 1000000 + 1; // rand() not secure for random password gen
    }
}

void algoritmo1(int v[], int dim)
{
    int iM, min, aux;
    
    for (int p = 0; p < dim - 1; p++)
    {
        iM = p;
        min = v[p];
        for (int s = p + 1; s < dim; s++)
        {
            if (v[s] < min)
            {
                min = v[s];
                iM = s;
            }
        }
        aux = v[p];
        v[p] = v[iM];
        v[iM] = aux;
    }
}

void algoritmo2(int v[], int dim)
{
    quickSort(v, 0, dim-1);
}


// A utility function to swap two elements 
void swap(int* a, int* b)
{ 
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 