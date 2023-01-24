#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct Datos {
    char Nom[30];
    int edad;
    float peso;
    double alt;
};

Datos Ini = {'\0', 0, 0.0, 0.0};

Datos LeerDatos()
{
    Datos L;
    cout<<"\nDame el nombre= ";
    cin>>L.Nom;
    cout<<"\nDame la edad= ";
    cin>>L.edad;
    cout<<"\nDame el peso= ";
    cin>>L.peso;
    cout<<"\nDame la altura= ";
    cin>>L.alt;
    return(L);
}

class Nodo
{
    Datos Dato;
    Nodo *sig;
public:
    Nodo(Datos d=Ini,Nodo *s=NULL) {
        cout<<"\nMe esta llamando la declaracion del objeto";
        Dato = d;
        sig = s;
    }
    Datos ModDatos(Datos d) { Dato = d; }

    int ModEdad(int e) {Dato.edad = e; }
    float ModPeso( float p) {Dato.peso = p; }
    double ModAlt( double a ) {Dato.alt = a; }
    Nodo ModSig( Nodo *s) { sig=s; }
    
    Datos RegDatos(){ return(Dato);}
	char *RegNom(){ return(Dato.Nom);}
	int RegEdad(){ return(Dato.edad);}
	float RegPeso(){ return(Dato.peso);}
	double RegAlt(){ return (Dato.alt);}
	Nodo *RegSig(){ return(sig);}
};

class LSE 
{
	Nodo *st, *ed, *gen;
	Nodo *aux,*aux1;
	public:
		LSE(){ st = ed = gen = NULL; }
		void Insertar (Datos x);
		void InsOrd (Datos x);
		void Buscar(Datos x);
		void Eliminar();
		void Imprimir ();		
};

void LSE::Insertar(Datos x)
{
	if(st == NULL){
		gen = new Nodo (x);
		if(gen==NULL){
			cout<<"No hay memoria";
			exit(1);
		}
		st = ed = gen;
	}
	else{
		Nodo *p = gen;
		gen = new Nodo (x);
		if(gen==NULL){
			cout<<"No hay memoria";
			exit(1);
		}
	
		p->ModSig(gen);
		ed = gen;
			
	}
}

void LSE::Imprimir() 
{
	Nodo *i;
	cout<<"\nImprime la lista"<<endl;
	for(i=st; i!=NULL; i= i->RegSig())
		cout<<"\n"<<setw(10)<<i->RegNom()<<setw(10)<<i->RegEdad()<<setw(10)<<i->RegAlt()<<setw(10)<<i->RegPeso();
}

void LSE::InsOrd(Datos x)
{
	Nodo *p,*q;
	if(st==NULL){
		gen=new Nodo(x);
		if(gen==NULL){
			cout<<"No hay memoria";
			exit(1);
		} 
		st=ed=gen;	
	}
	else{
		p=st;
		if(x.edad<p->RegEdad()){
			gen = new Nodo(x,p);
			if(gen==NULL){
			cout<<"No hay memoria";
			exit(1);
		} 	
		st=gen;
		}
		else{
			p=ed;
			if(x.edad>p->RegEdad()){
				gen = new Nodo(x);
				if(gen==NULL){
				cout<<"No hay memoria";
				exit(1);
				}
				ed = gen;
				p->ModSig(gen);
			}
			else{
				p=st;
				while(x.edad>p->RegEdad()){
					q=p;
					p=p->RegSig();
				}
				gen= new Nodo(x,p);
				if(gen==NULL){
				cout<<"No hay memoria";
				exit(1);
				}
				q->ModSig(gen);
			}
		}
	}
}

void LSE::Buscar(Datos x)
{
	aux=st;
	while(x.edad!=aux->RegEdad()){
		aux1 = aux;
		aux = aux->RegSig();
	}
	cout<<"Valor encontrado"<<aux->RegEdad();
}

void LSE::Eliminar()
{
	if(aux==st){
		st=aux->RegSig();
		aux->ModSig(NULL);
		delete aux;
		return;
	}
	else{
		if(aux==ed){
			ed=aux1;
			aux1->ModSig(NULL);
			delete aux;
			return;
		}
		else{
			aux1->ModSig(aux->RegSig());
			aux->ModSig(NULL);
		}
	}	
} 

int main()
{
	LSE R;
	Datos G;
	int ent,opc,opc1;
	
	do{
		system("cls");
		cout<<"\t\tMENU";
		cout<<"\n\t1.- Insertar";
		cout<<"\n\t2.- Insertar Ordenado";
		cout<<"\n\t3.- Imprimir";
		cout<<"\n\t4.- Salir";
		cout<<"\n\t\t\t Opcion: ";
		cin>>opc;
	
		switch(opc)
		{
			case 1:
				cout<<"\nDame los valores\n ";
				G = LeerDatos();
				R.Insertar(G);
				break;
			case 2:
				cout<<"\nLista ordenada por la edad:";
				G = LeerDatos();
				R.InsOrd(G);
				break;
			case 3:
				cout<<"\nLos valores de la lista:"<<endl;
				R.Imprimir();
				getch();
				break;
			
			default:
				cout<<"\n\n\tGracias por usar este software"<<endl;
				getch();
		}
		system("cls");
		cout<<"\n\t\tDesea hacer otra operacion:\n\t1= si \n\t2= no\n\t\t\t\topcion: ";
		cin>>opc1;
	}while(opc1==1);
	getch();
	return(0);
}
