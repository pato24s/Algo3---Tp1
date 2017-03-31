#include "Ejercicio1.cpp"
using namespace std;
int main(int argc, char const *argv[]){
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

                cout<<"Ejercicio 1"<<endl;
                vector<int> llenarR;
                vector<int> llenarA;
                cout<<"SALIDA: "<<endl;
                cout<<backtracking(data,data.size(),llenarR,llenarA)<<endl;                
                cout<<"Explicación:"<<endl;
                cout<<"ROJO: ";
                mostrarVector(llenarR);
                cout<<"AZUL: ";
                mostrarVector(llenarA);
        }else if(ejercicio==2){
                cout<<"ejer ACOT"<<endl;
                cout<<"SALIDA: "<<endl;
                cout<<backtracking_cota(dataInt,dataInt.size())<<endl;
                // cout<<"dinamica cuesta pa, mejor mira backtracking"<<endl;                

        }else if(ejercicio==3){
                cout<<"Dinamicaaaaaaaa"<<endl;
        }else{

                cout<<"no existe ese ejercicio"<<endl;

        }
}