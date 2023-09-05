#include<iostream>
#include<cmath>
#include <algorithm>
using namespace std;
const int tam=1e6;
int main(){
	int N,M,H;	
	int vector[tam];
		
	cin>>N;// Numero de arboles
	cin>>M;// Metros de madera que se necesitan
	
	for(int i=0;i<N;i++){
		cin>>vector[i];
	}
	
	sort(vector,vector+N,greater<int>());
	
	H = vector[0];
	for(int i=0;i<N && 0<=M;i++){
		
		//Cantidad de madera posible que puedo cortar antes 
		// de pasar siguiente arbol 
		int posible = (i+1)*(vector[i]-vector[i+1]); 
												
		if(posible<=M){ // Si la cantidad de madera que necesito sobrepasa
			H = vector[i+1];	
			M = M - posible;
		}
		else{ // Si la cantidad de madera es suficiente
			H -= (M+i)/(i+1); // La cantidad de madera posible
			break; // termina
		}
	}
	cout<<H;
	
	return 0;
}
