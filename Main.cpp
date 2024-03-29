#include "Ejercicio1.cpp"
#include "Ejercicio3.cpp"
#include <time.h>
#include <sys/time.h>
#include <chrono>
using namespace std;



/* retorna "a - b" en segundos */
double timeval_diff(struct timeval *a, struct timeval *b)
{
  return
    (double)(a->tv_sec + (double)a->tv_usec)/1000000 -
    (double)(b->tv_sec + (double)b->tv_usec)/1000000;
}

int main(int argc, char const *argv[]){


        
        struct timeval t_ini, t_fin;
        double secs;

        ifstream input;
        input.open(argv[1]);
        string aux;
        int n;
        int h;
        getline(input,aux);
        n=atoi(aux.c_str());
        vector<int>dataInt;
        vector<tupNumero> data;
        for (int i = 0; i < n; ++i){
                getline(input,aux,' ');
                h=atoi(aux.c_str());
                tupNumero numero(h,0);
                data.push_back(numero);
                dataInt.push_back(h);
        }
        int ejercicio=atoi(argv[2]);
        if(ejercicio==1){

                // cout<<"Ejercicio 1"<<endl;
                vector<int> llenarR;
                vector<int> llenarA;
                // cout<<"SALIDA: "<<endl;

                // gettimeofday(&t_ini, NULL);
                auto start = chrono::high_resolution_clock::now();
                int sal=backtracking(data,data.size());
                auto finish = chrono::high_resolution_clock::now();

                float milli = chrono::duration_cast<chrono::milliseconds>(finish-start).count();
                float secs = milli/1000;
                cout << secs;
                // gettimeofday(&t_fin, NULL);
                // cout<<sal<<endl; 
                // secs = timeval_diff(&t_fin, &t_ini);

                // cout<<"tardo: "<<endl;
                // cout<<secs<<endl;
                
                // cout<<"Explicación:"<<endl;
                // cout<<"ROJO: ";
                // mostrarVector(llenarR);
                // cout<<"AZUL: ";
                // mostrarVector(llenarA);
        }else if(ejercicio==2){
                // cout<<"ejer ACOT"<<endl;
                // cout<<"SALIDA: "<<endl;
                
                gettimeofday(&t_ini, NULL);

                            auto start = chrono::high_resolution_clock::now();

                int salCool=backtracking_cota(dataInt,dataInt.size());
                            auto finish = chrono::high_resolution_clock::now();
                            float milli = chrono::duration_cast<chrono::milliseconds>(finish-start).count();

            float segs = milli/1000;


                gettimeofday(&t_fin, NULL); 
                secs = timeval_diff(&t_fin, &t_ini);
                // cout<<"sal: "<<salCool<<endl;
                // cout<<"tardo: "<<endl;
                cout<<segs;
                // cout<<"dinamica cuesta pa, mejor mira backtracking"<<endl;                

        }else if(ejercicio==0){
        	gettimeofday(&t_ini, NULL);
                            auto start = chrono::high_resolution_clock::now();

            int salFb= fuerzaBruta(data,data.size());
        	// cout<<salFb<<endl;
                                        auto finish =  chrono::high_resolution_clock::now();
                            float milli = chrono::duration_cast<chrono::milliseconds>(finish-start).count();

        	gettimeofday(&t_fin, NULL); 

        	secs = timeval_diff(&t_fin, &t_ini);
                        float segs = milli/1000;

        	// cout<<"SALIDA: "<<salFb<<endl;
        	cout<<segs;

        }else if(ejercicio==3){
        
            // gettimeofday(&t_ini, NULL);
            auto start = chrono::high_resolution_clock::now();
            int pd=programacionDinamica(dataInt);
            auto finish = chrono::high_resolution_clock::now();

            float milli = chrono::duration_cast<chrono::milliseconds>(finish-start).count();

            float secs = milli/1000;

            cout << secs;

            // gettimeofday(&t_fin, NULL); 
            // cout<<secs<<endl;

            // cout<<"pd"<<endl;
            // cout<<pd<<endl;

            // cout<<"btc"<<endl;
            // int bt=backtracking_cota(dataInt,dataInt.size());
            // cout<<bt<<endl;
            // bool aux=bt==pd;
            // cout<<"sol: "<<aux<<endl;
        }else{

                cout<<"no existe ese ejercicio"<<endl;

        }
}