using namespace std;

#include <cstdio>
#include <algorithm>

struct tupNumeroIndice
{
    int numero;
    int indice; //0 1 2 = n r a
    tupNumeroIndice(int num, int ind) : numero(num),indice(ind){}
    tupNumeroIndice(){}

    tupNumeroIndice& operator =(const tupNumeroIndice tup1){
    	numero = tup1.numero;
    	indice = tup1.indice;
    	return *this;
    }
};

int dp[503][503][503];
int a[504];
int N;

int rec(int dec, int inc, int idx){
    if(idx == N) {
        return 0;
    }
    if(dp[dec][inc][idx] != -1) return dp[dec][inc][idx];
    int ret = 0;
    if(a[dec] > a[idx]){
        ret = max(ret, 1 + rec(idx, inc, idx+1));
    }
    if(a[inc] < a[idx]){
        ret = max(ret, 1 + rec(dec, idx, idx+1));
    } 
    ret = max(ret, rec(dec, inc, idx+1));
    dp[dec][inc][idx] = ret;
    return ret;
}

int programacionDinamica(vector<int> &arr){
	// 	memset(dp, -1, sizeof dp);


	// // int a[204];
	// int n=arr.size();
	N=arr.size();

	for (int i = 0; i < N; ++i)	{
		a[i]=arr[i];
	}
	a[N] = -1;
	a[N+1] = 1234567;
	for(int i=0;i<=N+1;++i){
		for(int j=0;j<=N+1;++j){
	        for(int k=0;k<=N+1;++k){
	            dp[i][j][k] = -1;
	        }
	    }
	}
	return N- rec(N+1,N,0);
}

