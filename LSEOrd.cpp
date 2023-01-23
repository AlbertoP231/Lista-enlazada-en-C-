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
	public:
		LSE(){ st = ed = gen = NULL; }
		void Insertar (Datos x);
		void InsOrd (Datos x);
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




int main()
{
	LSE R;
	Datos G;
	int ent,opc,opc1;
	
	do{
		system("cls");
		cout<<"\t\tMENU";
		cout<<"\n\t1.- Insertar";
		cout<<"\n\t2.- Imprimir";
		cout<<"\n\t3.- Salir";
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
