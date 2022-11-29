#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;
struct nodo{
	string ciudad;
	int temperature;
	struct nodo*siguiente;
};
typedef nodo*Tlista;

void insertarinicio(Tlista &lista,string valor,int valor2){
	Tlista nd;
	nd=new(struct nodo);
	nd->ciudad=valor;
	nd->temperature=valor2;
	nd->siguiente=lista;
	lista=nd;
}
void insertarfinal(Tlista &lista,string valor,int valor2){
	Tlista temp,nd=new(struct nodo);
	nd->ciudad=valor;
	nd->temperature=valor2;
	nd->siguiente=NULL;
	if(lista==NULL){
		lista=nd;
	}else{
		temp=lista;
		while(temp->siguiente!=NULL){
			temp=temp->siguiente;
		}
		temp->siguiente=nd;
	}
}
void imprimir(Tlista lista){
	Tlista aux;
	int contador=0;
	int suma=0;
	int promedio;
	int mayor=0;
	int menor=9999;


	while(lista!=NULL){

		if((lista->temperature)>mayor){
			mayor=lista->temperature;

		}

		if((lista->temperature)<menor){
			menor=lista->temperature;
		}

		suma=suma+lista->temperature;

		cout<<" "<<lista->ciudad<<" "<<lista->temperature<<endl;
	

		lista=lista->siguiente;
		contador++;
	
	}

	promedio=suma/contador;



	cout<<" la temperatura mas alta es de "<<mayor<<" y la mas baja es de "<<menor<<" temperatura promedio "<<promedio<<endl;
	
}
void menu(){
	cout<<"opcion 1 insertar al inicio"<<endl;
	cout<<"opcion 2 insertar al final "<<endl;
	cout<<"opcion 3 mostrar resultados "<<endl;

}
main(){
	Tlista lista=NULL;
	string valor;
	int  valor2;
	int opc;
	do{
		menu();
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"ingrese el nombre de la ciudad "<<endl;
				cin>>valor;
				cout<<"ingrese la temperatura "<<endl;
				cin>>valor2;
				
				insertarinicio(lista,valor,valor2);
				system("PAUSE"); system("cls");
				break;
			case 2:
				cout<<"ingrese el nombre de la ciudad "<<endl;
				cin>>valor;
				cout<<"ingrese la temperatura "<<endl;
				cin>>valor2;
				
				insertarfinal(lista,valor,valor2);
				system("PAUSE"); system("cls");
				break;
			case 3:
				imprimir(lista);
				system("PAUSE"); system("cls");
				break;
		}
		
	}while(opc>=1 and opc<=3);
}
