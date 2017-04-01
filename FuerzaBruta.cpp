#include <bits/stdc++.h>
using namespace std;
 
struct tupNumero
{
    int numero;
    int arreglo; //N C D
    tupNumero(int num) : numero(num),arreglo(0){}
};


 void mostrarVector(vector<int> vec){
    for (int i = 0; i < vec.size(); ++i)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
 }

 /*  C++ code to generate all possible subsequences.
    Time Complexity O(n * 2^n) */
#include<bits/stdc++.h>
using namespace std;
 
void printSubsequences(vector<tupNumero> arr, int n)
{
    /* Number of subsequences is (2**n -1)*/
    unsigned int opsize = pow(2, n);
 
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j))
                cout << arr[j].numero << " ";
        }
        cout << endl;
    }
}

bool esCrec(std::vector<int> v){
    bool res = true;
    for (int i = 0; i < v.size()-1; ++i)
    {
        res=res && (v[i]<v[i+1]);
    }
    return res;
}

bool esDec(std::vector<int> v){
    bool res = true;
    for (int i = 0; i < v.size()-1; ++i)
    {
        res=res && (v[i]>v[i+1]);
    }
    return res;
}


bool esSolucion(vector<int > crec, vector<int> dec){
    return esCrec(crec) && esDec(dec);
}

 void fuerzaBruta(vector<tupNumero> arr, int n)
{
    int mejorNumerosOut=n;
    vector<int> mejorCrec;
    vector<int> mejorDec;
    /* Number of subsequences is (2**n -1)*/
    unsigned int opsize = pow(2, n);
 
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
        vector<int> crec;
        vector<int> dec;
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j)){
                crec.push_back(arr[j].numero);
                // cout << arr[j].numero << " ";
                arr[j].arreglo=1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if(arr[i].arreglo!=1){
                dec.push_back(arr[i].numero);
            }
        }
        // cout<<"creciente: ";
        // mostrarVector(crec);
        // cout<<"decreciente: ";
        // mostrarVector(dec);
         for (int i = 0; i < n; ++i){
            arr[i].arreglo=0;
        }
        unsigned int opsize2 = pow(2, dec.size());
 
        for (int counter2 = 1; counter2 < opsize2; counter2++){
            vector<int> dec_aux;
            // cout<<"crec: ";
            // mostrarVector(crec);
            // cout<<"dec: ";
            for (int j2 = 0; j2 < dec.size(); j2++){
                if (counter2 & (1<<j2)){
                    // cout << dec[j2] << " ";
                    dec_aux.push_back(dec[j2]);
                }
            }
        // cout<<"dec: ";
        // mostrarVector(dec_aux);
        // cout<<"sol: "<<esSolucion(crec,dec_aux)<<endl;
        int numerosOut=n-dec_aux.size()-crec.size();
        // cout<<"numeros out: "<<numerosOut<<endl;
        if(esSolucion(crec,dec_aux) && numerosOut<mejorNumerosOut){
            mejorNumerosOut=numerosOut;
            mejorDec=dec_aux;
            mejorCrec=crec;
        }
        if(mejorNumerosOut==0){
            counter2=opsize2;
            counter=opsize;
        }
        // cout<<endl;
        }
    }
    cout<<"Salida: "<<mejorNumerosOut<<endl;
    cout<<"ROJO: ";
    mostrarVector(mejorCrec);
    cout<<"AZUL: ";
    mostrarVector(mejorDec);
}

// Driver program
