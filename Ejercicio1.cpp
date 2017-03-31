#include <bits/stdc++.h>

using namespace std;
 
struct tupNumero
{
    int numero;
    int arreglo; //0 1 2 = n r a
    tupNumero(int num, int arr) : numero(num),arreglo(arr){}
};

struct tupBoolNumero
{
	bool usado;
	int numero;
};

void mostrarVector(vector<int> vec){
    for (int i = 0; i < vec.size(); ++i)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
 }
using namespace std;

bool esCrec(vector<int> v){
    bool res = true;
    if (v.size()==0){
    	return true;
    }
    for (int i = 0; i < v.size()-1; ++i)
    {
        res=res && (v[i]<v[i+1]);
    }
    return res;
}

bool esDec(vector<int> v){
    bool res = true;
    if (v.size()==0){
    	return true;
    }

    for (int i = 0; i < v.size()-1; ++i)
    {
        res=res && (v[i]>v[i+1]);
    }
    return res;
}


bool esSolucion(vector<int > crec, vector<int> dec){
    return esCrec(crec) && esDec(dec);
}

int estudiarCaso(vector<tupNumero> v,vector<int> &llenarR, vector<int> &llenarA){
	int sinUsar= v.size();
	vector<int> rojos;
	vector<int> azules;	

	for (int i = 0; i < sinUsar; ++i)
	{
		if(v[i].arreglo==1){
			rojos.push_back(v[i].numero);
		}else if(v[i].arreglo==2){
			azules.push_back(v[i].numero);
		}
	}
	if(esSolucion(rojos,azules)){
		sinUsar= sinUsar-rojos.size()-azules.size();
		llenarR=rojos;
		llenarA=azules;
	}
	return sinUsar;
}

int min3(int a, int b, int c){
	if(a<b){
		if(a<c){
			return a;
		}else{
			return c;
		}
	}else{
		if(b<c){
			return b;
		}else{
			return c;
		}
	}
}



int bt_recur(vector<tupNumero> arr, int n, int i, vector<tupNumero> v, vector<int> &optimoR, vector<int> &optimoA){
	vector<tupNumero> caminoRojo=v;
	vector<tupNumero> caminoAzul=v;

	vector<int> posibleRojo1;
	vector<int> posibleRojo2;
	vector<int> posibleRojo3;

	vector<int> posibleAzul1;
	vector<int> posibleAzul2;
	vector<int> posibleAzul3;


	int posible1;
	int posible2;
	int posible3;
	int sol1;
	int sol2;
	int sol3;

	int valor=arr[i].numero;

	tupNumero nada(valor,0);
	tupNumero roja(valor,1);
	tupNumero azul(valor,2);

	
	v.push_back(nada);
	caminoRojo.push_back(roja);
	caminoAzul.push_back(azul);


	// cout<<"i actual:"<<i<<endl;
	i++;


	if(i==n){
		// cout<<"tam v: "<<v.size()<<endl;
		

		posible1 = estudiarCaso(v,posibleRojo1,posibleAzul1);
		posible2 = estudiarCaso(caminoRojo,posibleRojo2,posibleAzul2);
		posible3 = estudiarCaso(caminoAzul,posibleRojo3,posibleAzul3);


		int minimoHastaAca = min3(posible3,posible2,posible1);
		if(minimoHastaAca==posible1){
			optimoR=posibleRojo1;
			optimoA=posibleAzul1;
		}else if(minimoHastaAca==posible2){
			optimoR=posibleRojo2;
			optimoA=posibleAzul2;
		}else{
			optimoR=posibleRojo3;
			optimoA=posibleAzul3;
		}
		// mostrarVector(optimoA);
		return minimoHastaAca;
	}else{
	

		sol1= bt_recur(arr,n,i,v,posibleRojo1,posibleAzul1);
		sol2= bt_recur(arr,n,i,caminoRojo,posibleRojo2,posibleAzul2);
		sol3= bt_recur(arr,n,i,caminoAzul,posibleRojo3,posibleAzul3);

		//si no flasheo aca llego cuando termine todas las recurs

		int minimoOptimo =min3(sol1,sol2,sol3);
		if(minimoOptimo==sol1){
			optimoR=posibleRojo1;
			optimoA=posibleAzul1;
		}else if(minimoOptimo==sol2){
			optimoR=posibleRojo2;
			optimoA=posibleAzul2;
		}else{
			optimoR=posibleRojo3;
			optimoA=posibleAzul3;
		}
		return minimoOptimo;
	}

}

int backtracking (vector<tupNumero> arr, int n,vector<int> &optimoR, vector<int> &optimoA){
	vector<tupNumero> v;
	int i=0;

	return bt_recur(arr,n,i,v,optimoR,optimoA);
}

int bt_recur_acot(vector<int> arr,int n, int i, bool rojoUsado,int ultimoRojo, bool azulUsado,int ultimoAzul, int &res, bool &termino){
	int valor= arr[i];
	// int res=n;
	if(i==n){
		termino =true;
		return res;
	}else{
		if(rojoUsado==false){
			rojoUsado=true;
			ultimoRojo=arr[i];
			res--;
			bt_recur_acot(arr,n,i+1,rojoUsado,ultimoRojo,azulUsado,ultimoAzul,res,termino);
			if(termino){
				return res;
			}
		}else{
			//ya hay un ultimoROjo
			if(ultimoRojo<arr[i]){
				ultimoRojo=arr[i];
				res--;
				bt_recur_acot(arr,n,i+1,rojoUsado,ultimoRojo,azulUsado,ultimoAzul,res,termino);
				if(termino){
					return res;
				}
			}else{
				//no puede ser rojo
				bt_recur_acot(arr,n,i+1,rojoUsado,ultimoRojo,azulUsado,ultimoAzul,res,termino);
				if(termino){
					return res;
				}
			}
		}
		if(azulUsado==false){
			azulUsado=true;
			ultimoAzul=arr[i];
			res--;
			bt_recur_acot(arr,n,i+1,rojoUsado,ultimoRojo,azulUsado,ultimoAzul,res,termino);
			if(termino){
				return res;
			}
		}else{
			if(ultimoAzul>arr[i]){
				ultimoAzul=arr[i];
				res--;
				bt_recur_acot(arr,n,i+1,rojoUsado,ultimoRojo,azulUsado,ultimoAzul,res,termino);
				if(termino){
					return res;
				}
			}else{
				//no puede ser azul
				bt_recur_acot(arr,n,i+1,rojoUsado,ultimoRojo,azulUsado,ultimoAzul,res,termino);
					if(termino){
						return res;
				}
			}
		}
	}

}

int backtracking_cota (vector<int> arr, int n){
	bool bfalse=false;
	int res=n;
	return bt_recur_acot(arr,n,0,false,0,false,0,res,bfalse);
}	