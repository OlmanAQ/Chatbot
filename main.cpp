#include <iostream>
#include "fstream"
#include <cstring>
#include "string.h"

using namespace std;

struct factura{       //Guarda los datos generales de la factura
public:
    int numFac;
    char cliente[15];
    long enlace;     // detalles de la factura
                     //agregar los atributos necesarios de la aplicación fecha, dir, etc
    long izq, der;   //para formar el indice binario

    factura(){
        numFac= 0;
        enlace=-1;  // igual a NULL
        izq=0;
        der=0;
    }
}regFac;

struct detalle{                 //almacena los detalles de una factura
public:
    int cantArt;                //cantidad de articulos
    char nomArt[15];            //nombre del articulo
    long precioUnit;
    long sig;                   //apunta al siguiente articulo comprado en la misma factura

    detalle(){
        cantArt= 0;
        precioUnit=0;
        sig=-1;        //igual a NULL
    }
}regDet;


char * nombre;
fstream fileFac("archivoFacturas.dat", ios::in | ios::out |ios::binary |ios::trunc );
fstream fileFac2("archivoFacturas.dat", ios::in | ios::out |ios::binary );
fstream fileDet("archivoDetalle.dat", ios::in | ios::out |ios::binary|ios::trunc);
//prototipos
long buscar(long ,int );

//Devuelve la cantidad de registros que tiene el archivo de facturas
long fin_archivo(){

    long n;
    fileFac.seekg(0, ios::end);
    n = fileFac.tellg();
    n= (n/sizeof(regFac))-1;

    return n;
}
//Devuelve la cantidad de registros que tiene el archivo de Detalles
long fin_archivo2(){

    long n;
    fileDet.seekg(0, ios::end);
    n = fileDet.tellg();
    n= (n/sizeof(regDet))-1;

    return n;
}


void llenar(char *nombre){   // Restringe los string a 15 caracteres.

for(int i=0; i<15; i++)
    regFac.cliente[i]=nombre[i];
}
void llenar2(char *nombre){  // Restringe los string a 15 caracteres.

for(int i=0; i<15; i++)
    regDet.nomArt[i]=nombre[i];
}

void insertar(int num, char * nombre){
    int index=0;

    if(!fileFac){
    cout <<"error en la apertura del archivo";
    }

    regFac.numFac=num;
    llenar(nombre); //  regFac.cliente =nombre;
    regFac.der=-1;
    regFac.izq=-1;
    fileFac.seekg(0,ios::end);
    fileFac.write(reinterpret_cast<char *> (&regFac), sizeof(regFac));

    if(fin_archivo()<1)//evitar que se compare con el mismo
        {
            //cout <<"Solo hay uno, el es la raiz y no se enlaza";
            return;
        }

    while(true){
        fileFac.seekg(index*sizeof(regFac));
        fileFac.read(reinterpret_cast<char *> (&regFac), sizeof(regFac));

        if(regFac.numFac==num){
            cout <<"No aceptamos duplicados";
            return;
        }
        else if(regFac.numFac<num){//irse por el lado der
            if(regFac.der!=-1)
                index=regFac.der;
            else{
                regFac.der=fin_archivo();//asignarle que apunte el final de archivo
                fileFac.seekg(index*sizeof(regFac));
                fileFac.write(reinterpret_cast<char *> (&regFac), sizeof(regFac));
                break;
            }

        }
        else{ //irse por el lado izq

            if(regFac.izq!=-1)
                index=regFac.izq;
            else{
                regFac.izq=fin_archivo();//asignarle que apunte el final de archivo
                fileFac.seekg(index*sizeof(regFac));
                fileFac.write(reinterpret_cast<char *> (&regFac), sizeof(regFac));
                break;
            }
        }
    }
}


void insertar(int numFactura,int cantidad,char *descrip,int precio){
    long ant=-1;
    //buscar factura
    int buscado =buscar(0,numFactura);
    if(buscado==-1){
        cout <<"Error no se encuentra el numero de factura. ";
        return;
    }
    //crea el registro
    //lo inserta al final del archivo
    regDet.cantArt=cantidad;
    llenar2(descrip);//regDet.descripcion=descrip;
    regDet.precioUnit=precio;
    regDet.sig=-1;
    fileDet.seekg(0,ios::end);
    fileDet.write(reinterpret_cast<char *> (&regDet), sizeof(regDet));


    //realizar el enlace
    //buscar el ultimo detalle si el enlace es dif de -1
        fileFac.seekg(buscado*sizeof(regFac),ios::beg);
        fileFac.read(reinterpret_cast<char *> (&regFac), sizeof(regFac));

        if(regFac.enlace==-1){//es el primer detalle
            regFac.enlace=fin_archivo2();
            fileFac.seekg(buscado*sizeof(regFac),ios::beg);
            fileFac.write(reinterpret_cast<char *> (&regFac), sizeof(regFac));
        }
        //tiene ya detalles insertados
        else {
                long sig=regFac.enlace;
            while(sig!=-1){
                 ant=sig;
                fileDet.seekg(sig*sizeof(regDet),ios::beg);
                fileDet.read(reinterpret_cast<char *> (&regDet), sizeof(regDet));
                sig= regDet.sig;
            }
            //enlazarlo
            regDet.sig=fin_archivo2();
            fileDet.seekg(ant*sizeof(regDet),ios::beg);
            fileDet.write(reinterpret_cast<char *> (&regDet), sizeof(regDet));
        }

}

void imprimirFac(){
    fileFac.seekg(0);
    cout<< endl <<"-------- Se imprimen las facturas del árbol binario -----------"<<endl<<endl<<endl;
    cout<< "Izq   NumFac     Cliente       Enlace   Der"<<endl<<endl;
    while(fileFac.eof() != true){
        fileFac.read(reinterpret_cast<char *> (&regFac), sizeof(regFac));
        if(fileFac.eof() != true)
            cout<< regFac.izq<<"\t "<<regFac.numFac <<"\t " <<regFac.cliente<<"\t "<<regFac.enlace<<"\t "<<regFac.der <<endl;
    }

}

void imprimirDet(){
    int reg=0;
    fileDet.seekg(0);
    cout<< endl <<"-------- Se imprimen los detalles de las facturas -----------"<<endl<<endl<<endl;

    cout<< "Reg   Cantidad   Descripcion    PrecioUnitario   Sig"<<endl;
    while(fileDet.eof() != true){
        fileDet.read(reinterpret_cast<char *> (&regDet), sizeof(regDet));
        if (fileDet.eof() != true)
           cout<<" "<<reg<<"\t"<< regDet.cantArt<<"\t "<<regDet.nomArt <<"\t\t\t " <<regDet.precioUnit<<"\t "<<regDet.sig<<endl;
        reg++;
    }

}





void login(){
    int opcion;

    bool repetir = true;

    do
    {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\tChatbot" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n Hola usuario. Soy el Chatbot. ¿Dime que quieres hacer? " << endl;
        cout << "\n\n\t\t\tEstos son mis comandos" << endl;
        cout << "\tRealizar nuevo carrito de compras" << endl;
        cout << "\tModificar el carrito de compras" << endl;
        cout << "\tCancelar un carrito de compras" << endl;
        cout << "\tConsultar un carrito de compras" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            //string admin;
            //admin=elegirAdmin()
            //menuAdmin();
            break;

        case 2:
            //string profe;
            //elegirProfe();
          //  menuProfe();
            break;

        case 3:
            //string estudiante;
            //elegirEstudiante();
         //   menuEstudiante();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

}


int main()
{
    insertar(18,"Ana Lorena");
    insertar(5, "Carlos    ");
    insertar(12,"Juan      ");
    insertar(32,"Maria     ");

//numFact,cant,descrip, precio

    insertar(18,1,"Lapiz",100);
    insertar(18,3,"Hojas",10);
    insertar(18,2,"Libro",1020);
    insertar(12,30,"Hojas",10);
    insertar(32,3,"Hojas",10);
    insertar(18,3,"Folder",200);


    imprimirFac();    //imprime el archivo indice
    //imprimirDet();

    system("pause");
    cout <<endl;
    return 0;

    //cargardatos();
   // login();
}
