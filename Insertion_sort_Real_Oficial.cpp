#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void GeraAleatorios(int numeros[],int quantNumeros, int Limite){
	srand(time(NULL));			//Gera um vetor aleatorio
	for(int i =0; i<quantNumeros; i++){
		numeros[i] = rand() % Limite;		//Atribui para cada casa do vetor declarado os numeros variando até o valor atribuido a Limite.
	}	
}
//A função a seguir printa o vetor que receber inicialmente printa um vetor aleatoriamente ordenado, mas pode ser usada para verificar 
//as otras ordenações.
void InsertSort_Aleatorio(int *v,int tam){
		cout<<"\nAleatoriamente ordenado:"<<endl;
		for (int i=0; i<tam;i++){
			cout<<"\nValor "<<v[i]<<endl;
			}
}
//Função que vai ordenar o vetor de forma crescente utilizando o algoritmo insertion sort.
void InsertSort_Crescente(int *v, int tam){		//Aponta para um vetor e  recebe seu tamanho total.
	int aux,j;
	clock_t ticks[2];							//Vetor usado para armazenar os tempos de inicio de fim do processo de ordenação.
	ticks[0] = clock();							//Recebe o tempo incial de exeução  do codigo baseado no relogio do computador.
		for (int i=1; i<tam;i++){				//loop que varia da posição 1 até o tamanho maximo do vetor.
			aux=v[i];							//Auxiliar vai guardar o valor da posição a ser comparada.
			j= i-1;								//j vai começar na posição 0(inicial do vetor).
			while (j>=0 && v[j]>aux){			// Loop para fazer a ordenação
				v[j+1]=v[j];					//faz o vetor ser ordenado a esquerda.
				j--;							//decrementa J até n entrar mais no loop isso acontecerá quando tivermos a posição em que a variavel
												//Auxiliar deverá ficar dentro do vetor.
			}
		v[j+1]=aux;								//Atribui auxiliar a sua devida posição.OBS.: J+1 dentro do vetor é porque quando J sai do while ele 
												//sempre vai estar com o valor -1 por isso no pior dos casos auxiliar irá para a posição zero do vetor.
		}
		ticks[1] = clock();						//Recebe o tempo final da ordenação.
		double tempo = (ticks[1] - ticks[0]) * 1000/ CLOCKS_PER_SEC;	 //Calcula o tempo que levou para ordenar o vetor em segundos.
		/*cout<<"--------------------------------";
		cout<<"\nOrdenacao crescente: "<<endl;
		for (int i=0; i<tam;i++){
			cout<<"\nPoiscao "<<i<<" valor "<<v[i]<<endl;
			}*/
			
			//A função acima serve para printar o vetor ordenado caso deseje pode tirar os /* e */ para ver o vetor sendo printado na sua tela.
		cout<<"\nTempo de ordenacao em segundos: "<<tempo<<endl;
}
/*
A função InsertSort_Aleatorio deixada antes dos vetores serem ordenados é para caso tenha dificuldade a pessoa consiga ter uma melhor vizualização
de que o vetor antes de ser ordenado de forma crescente realmente está ordenado no seu caso especidifo
caso não deseje pode deixar essa função comentada para verificar somente os tempos de ordenação. :) 
*/		

int main(){
	int n,aux,j,aux2,q;
	cout<<"Insira a quantidade de numeros que deseja ordenar:";
	cin>>n;
	int vet[n];
	GeraAleatorios(vet,n,100000); //Recebe o vetor, seu tamanho e os valores que podem existir dele no caso de 0 até 99999.
	InsertSort_Aleatorio(vet,n);//Printa o vetor aleatorimanete ordenado gerado. 
	InsertSort_Crescente(vet,n);//recebe o vetor aleatoriamente ordenado e ordena de forma crescente;
	//Verificar com a juliana se esta parte ainda continua no codigo;
		for (int i=1; i<n;i++){
			aux=vet[i];
			j= i-1;
			while (j>=0 && vet[j]>aux){
				vet[j+1]=vet[j];
				j--;
			}
		vet[j+1]=aux;
	}
	
	//InsertSort_Aleatorio(vet,n);
	InsertSort_Crescente(vet,n);//Recebe o vetor já ordenado de forma crescente para ordena-lo de forma crescente novamente;
	
	//Inverte o vetor de forma decrescente para ordena-lo.
		for (int i=1; i<n;i++){
			aux=vet[i];
			j= i-1;
			while (j>=0 && vet[j]<aux){
				vet[j+1]=vet[j];
				j--;
			}
		vet[j+1]=aux;
	}
	
	//InsertSort_Aleatorio(vet,n);
	//InsertSort_Crescente(vet,n);//Recebe o vetor decrescente e ordena de forma crescente
	
	//Ordena a peimeira metade de forma crescente;
	for (int i=0; i<n/2; i++){
			aux=vet[i];
			j= i-1;
		while (j>=0 && vet[j]>aux){
			vet[j+1]=vet[j];
			j--;
			}
		vet[j+1]=aux;
		}
	//Ordena segunda metade de forma decrescente;
	for (int i=n/2; i<=n; i++){
		aux2 = vet[i];
		q=i-1;
		while (q>=0 && vet[q]<aux2){
		vet[q+1]=vet[q];
		q--;	
		}
		vet[q+1]=aux2;
	}
	
	//InsertSort_Aleatorio(vet,n);
	//InsertSort_Crescente(vet,n);//Recebe o vetor metade crescente e metade decrescente para ordena-lo de forma crescente;
	
	//Ordena a primeira metade do vetor de forma decresnte.
	for (int i=1; i<n/2; i++){
			aux=vet[i];
			j= i-1;
		while (j>=0 && vet[j]<aux){
			vet[j+1]=vet[j];
			j--;
			}
		vet[j+1]=aux;
		}
	//Ordena de a segunda metade de forma crescente;
	for (int i=(n/2)+1; i<n; i++){
		aux2 = vet[i];
		q=i-1;
		while (q>=n/2 && vet[q]>aux2){
		vet[q+1]=vet[q];
		q--;	
		}
		vet[q+1]=aux2;
	}
	
	//InsertSort_Aleatorio(vet,n);
	//InsertSort_Crescente(vet,n);//Recebe o vetor metade decrescente e metade crescente para ordena-lo;
	return 0;
}
