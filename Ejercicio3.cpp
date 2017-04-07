using namespace std;

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



int progDin(vector<int> arr, int n){
	int masLarga=1;
	int ultimos[n];
	ultimos[0]=arr[0];
	int valorActual;
	int j;
	for (int i = 1; i < n; ++i)
	{
		valorActual=arr[i];

		for (j = 0; j < masLarga; ++j)
		{
			if(valorActual<ultimos[j]){
				ultimos[j]=valorActual;
				j=masLarga+1;
			}
		}
		if(j==masLarga){
			ultimos[j]=valorActual;
			masLarga++;
		}
	}
	return masLarga;
}




void imprimirV(tupNumeroIndice v[],int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i].numero<<" ";
	}
	cout<<endl;
}





int programacionDinamica(vector<int> arr, int n){
	int masLargaA=1;
	int masLargaR=0;
	tupNumeroIndice ultimosRojos[n];
	tupNumeroIndice ultimosAzules[n];
	tupNumeroIndice elemento0(arr[0],0);
	ultimosAzules[0]=elemento0;


	int valorActual;
	int j;
	int k;

	for (int i = 1; i < n; ++i)
	{
		cout<<"i igual a: "<<i<<endl;
		cout<<"Azul: ";
		imprimirV(ultimosAzules,masLargaA);
		cout<<"Rojo: ";
		imprimirV(ultimosRojos,masLargaR);
		tupNumeroIndice tuplaActual(arr[i],i);

		for (j = 0; j < masLargaA; ++j)
		{
			if(tuplaActual.numero==ultimosAzules[j].numero){
				// cout<<"ENTREE"<<endl;
				//no me sirve, veo si le va al rojo

				for (k = 0; k < masLargaR; ++k)
				{
					if(tuplaActual.numero==ultimosRojos[k].numero && tuplaActual.indice<ultimosRojos[k].indice){
						ultimosRojos[k]=tuplaActual;
						k=masLargaR+1;
						break;
					}else if(tuplaActual.numero < ultimosRojos[k].numero && tuplaActual.indice<ultimosRojos[k].indice){
						for (int l = masLargaR; l > k; l--){
							/* code */
							ultimosRojos[l]=ultimosRojos[l-1];
						}
						ultimosRojos[k]=tuplaActual;
						k=masLargaR+1;
						masLargaR++;
						break;
					}else if(tuplaActual.numero < ultimosRojos[k].numero && tuplaActual.indice>ultimosRojos[k].indice){
						ultimosRojos[k]=tuplaActual;
						k=masLargaR+1;
						break;
					}else{
						//nada ?
					}
				}
				if(k==masLargaR && tuplaActual.indice > ultimosRojos[k-1].indice){
					ultimosRojos[k]=tuplaActual;
					masLargaR++;

				}
				break;
			}

			//no es repetido
			//veo si me sirve a mi (azul)
			if(tuplaActual.numero>ultimosAzules[j].numero){
				// if(i==12){
				// 	cout<<"ACAAA"<<endl;
				// 	cout<<tuplaActual.numero<<endl;
				// 	cout<<ultimosAzules[j].numero<<endl;
				// }
				//me sirve, ultimosAzules[j] veo de pasarsel al rojo
				for (k = 0; k < masLargaR; ++k)
				{
					if(ultimosAzules[j].numero == ultimosRojos[k].numero && ultimosAzules[j].indice < ultimosRojos[k].indice){
						//le sirve al rojo
						ultimosRojos[k]=ultimosAzules[j];
						k=masLargaR+1;
						break;

					}else if(ultimosAzules[j].numero < ultimosRojos[k].numero && ultimosAzules[j].indice<ultimosRojos[k].indice){
						for (int l = masLargaR; l > k; l--){
							/* code */
							ultimosRojos[l]=ultimosRojos[l-1];
						}
						ultimosRojos[k]=ultimosAzules[j];
						k=masLargaR+1;
						masLargaR++;
						break;
					}else if(ultimosAzules[j].numero < ultimosRojos[k].numero && ultimosAzules[j].indice>ultimosRojos[k].indice){
						ultimosRojos[k]=ultimosAzules[j];
						k=masLargaR+1;
						break;
					}
				}
			
				if(k==0 || (k==masLargaR && ultimosRojos[k-1].indice < ultimosAzules[j].indice)){
					// cout<<"i: "<<i<<"  k: "<<k<<endl;
					ultimosRojos[k]=ultimosAzules[j];
					masLargaR++;

				}

				ultimosAzules[j]=tuplaActual;
				j=masLargaA+1;

			}


		}
		if(j==masLargaA){
			ultimosAzules[j]=tuplaActual;
			masLargaA++;
		}
	}

	return n-masLargaR-masLargaA;
}










int programacionDinamicaca(vector<int> arr, int n){
	//prioridad Roja
	int masLargaR=1;
	int masLargaA=0;
	tupNumeroIndice ultimosRojos[n];
	tupNumeroIndice ultimosAzules[n];

	tupNumeroIndice elemento0(arr[0],0);
	// vector<tupNumeroIndice>ultimosAzules(n);
	ultimosRojos[0]=elemento0;
	int valorActual;
	int j;
	int k;
	for (int i = 1; i < n; ++i)
	{
		cout<<"i igual a: "<<i<<endl;
		cout<<"Rojo: ";
		imprimirV(ultimosRojos,masLargaR);
		cout<<"Azul: ";
		imprimirV(ultimosAzules,masLargaA);
		// valorActual=arr[i];
		tupNumeroIndice tuplaActual(arr[i],i);

		for (j = 0; j < masLargaR; ++j)
		{
			if(tuplaActual.numero==ultimosRojos[j].numero){
				//aca no me sirve para nada, veo de mandarlo al azul
				for (k = 0; k < masLargaA; ++k)
				{
					if(tuplaActual.numero==ultimosAzules[k].numero){
						break;
					}else if(tuplaActual.numero> ultimosAzules[k].numero){
						ultimosAzules[k]=tuplaActual;
						k=masLargaA+1;
					}
				}
			
				if(k==masLargaA){
					ultimosAzules[k]=tuplaActual;
					masLargaA++;
				}




				break;
			}


			if(tuplaActual.numero<ultimosRojos[j].numero){

				for (k = 0; k < masLargaA; ++k)
				{

					if(ultimosRojos[j].numero==ultimosAzules[k].numero && ultimosRojos[j].indice>ultimosAzules[k].indice){
						break;
					}else if(ultimosRojos[j].numero==ultimosAzules[k].numero && ultimosRojos[j].indice<ultimosAzules[k].indice){
						ultimosAzules[k]=ultimosRojos[j];
						break;
					}
					if(ultimosRojos[j].numero>ultimosAzules[k].numero){

						if(ultimosRojos[j].indice<ultimosAzules[k].indice){
							//desplazo
							for (int l=masLargaA ; l > k; l--)
							{
								ultimosAzules[l]=ultimosAzules[l-1];
							}
							ultimosAzules[k]=ultimosRojos[j];
							k=masLargaA+1;
							masLargaA++;

						}else{

							ultimosAzules[k]=ultimosRojos[j];
							k=masLargaA+1;//corte turro
						}
					}

				}
				if(k==masLargaA){
					if(k==0 || ultimosRojos[j].indice>ultimosAzules[k-1].indice){
						ultimosAzules[k]=ultimosRojos[j];
						masLargaA++;
					}
				}

				ultimosRojos[j]=tuplaActual;
				j=masLargaR+1;
			}
		}
		if(j==masLargaR){
			ultimosRojos[j]=tuplaActual;
			masLargaR++;
		}
	}
	return n-masLargaR-masLargaA;
}
