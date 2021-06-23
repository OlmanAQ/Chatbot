#include <iostream>
#include "fstream"
#include <cstring>
#include "string.h"

using namespace std;

char nombreCliente[15];
char pizza[30];
int precioPizza;
char fresco[30];
int precioFresco;
string pan;
int precioPan;
string postre;
int precioPostre;

void menuTamRef(){

        cout << "\n\n\t\t\tEstos son los diferentes tama�os de refreco disponibles:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t1. 750ml         precio: 700  colones" << endl;
        cout << "\t2. 1L            precio: 1000 colones" << endl;
        cout << "\t3. 1.5L          precio: 1600 colones" << endl;
        cout << "\t4. 2L            precio: 2000 colones" << endl;

        cout << "\n\tIngresa el numero que tenga la opcion que deseas: ";
                   int TamFres = 0;
                   cin >> TamFres;
                   switch(TamFres)
                {
                 case 1: precioFresco = 700;

                break;

                case 2: precioFresco = 1000;

                break;

                case 3: precioFresco = 1600;

                break;

                case 4: precioFresco = 2000;

                break;

                default: cout << "Usted ha ingresado una opcion incorrecta";
        }
}

void menuTamPiz(){

        cout << "\n\n\t\t\tEstos son los diferentes tama�os de pizza disponibles:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t1. Pequena         precio: 4000 colones" << endl;
        cout << "\t2. Mediana         precio: 6200 colones" << endl;
        cout << "\t3. Grande          precio: 9000 colones" << endl;
        cout << "\t4. Extra Grande    precio: 12000 colones" << endl;

        cout << "\n\tIngresa el numero que tenga la opcion que deseas: ";
                   int TamPiz = 0;
                   cin >> TamPiz;
                   switch(TamPiz)
                {
                 case 1: precioPizza = 4000;

                break;

                case 2: precioPizza = 6200;

                break;

                case 3: precioPizza = 9000;

                break;

                case 4: precioPizza = 12000;

                break;

                default: cout << "Usted ha ingresado una opcion incorrecta";
        }
}

void menuPanPiz(){

        cout << "\n\n\t\t\tEstos son los diferentes opciones para el pan de tu pizza:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t1. Pan clasico         precio: 500 colones" << endl;
        cout << "\t2. Pan con ajo         precio: 600 colones" << endl;
        cout << "\t3. Pan integral        precio: 700 colones" << endl;
        cout << "\t4. Pan con queso       precio: 800 colones" << endl;

        cout << "\n\tIngresa el numero que tenga la opcion que deseas: ";
                   int PanPiz = 0;
                   cin >> PanPiz;
                   switch(PanPiz)
                {
                 case 1: precioPan = 500;
                         if(precioPan == 500){
                            pan = "Pan clasico";
                         }

                break;

                case 2: precioPan = 600;
                        if(precioPan == 600){
                            pan = "Pan con ajo";
                         }

                break;

                case 3: precioPan = 700;
                        if(precioPan == 700){
                            pan = "Pan integral";
                         }

                break;

                case 4: precioPan = 800;
                        if(precioPan == 800){
                            pan = "Pan con queso";
                         }
                break;

                default: cout << "Usted ha ingresado una opcion incorrecta";
        }
}

void menuPostre(){

        cout << "\n\n\t\t\tEstos son los diferentes opciones de postre que te ofrecemos:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t1. Helado de vainilla        precio: 800 colones" << endl;
        cout << "\t2. Queque de chocolate       precio: 1000 colones" << endl;
        cout << "\t3. Tres leches               precio: 900 colones" << endl;
        cout << "\t4. Sin postre                precio:  0  colones" << endl;

        cout << "\n\tIngresa el numero que tenga la opcion que deseas: ";
                   int Postre = 0;
                   cin >> Postre;
                   switch(Postre)
                {
                 case 1: precioPostre = 800;
                         if(precioPostre == 800){
                            postre = "Helado de vainilla";
                         }

                break;

                case 2: precioPostre = 1000;
                        if(precioPostre == 1000){
                            postre = "Queque de chocolate";
                         }

                break;

                case 3: precioPostre = 900;
                        if(precioPostre == 900){
                            postre = "Tres leches";
                         }

                break;

                case 4: precioPostre = 0;
                        if(precioPostre == 0){
                            postre = "Sin postre";
                         }
                break;

                default: cout << "Usted ha ingresado una opcion incorrecta";
        }
}



void menuFresco(){

        cout << "\n\n\t\t\tEstas son tus diferentes opciones:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t CocaCola" << endl;
        cout << "\t Fanta Naranja" << endl;
        cout << "\t Fanta Colita" << endl;
        cout << "\t Jugo de Naranja" << endl;
        cout << "\t Te frio de limon" << endl;

}

void menupostre(){

        cout << "\n\n\t\t\tEstas son tus diferentes opciones de postres que te ofrecemos:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t Peperoni" << endl;
        cout << "\t Suprema" << endl;
        cout << "\t Jamon y queso" << endl;
        cout << "\t Hawaiana" << endl;
        cout << "\t Brazilena" << endl;
}

void menuPizza(){

        cout << "\n\n\t\t\tEstas son tus diferentes opciones:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t Peperoni" << endl;
        cout << "\t Suprema" << endl;
        cout << "\t Jamon y queso" << endl;
        cout << "\t Hawaiana" << endl;
        cout << "\t Brazilena" << endl;

}


void menu(){
 // Texto del men� que se ver� cada vez
        cout << "\n\n\t\t\tChatbot" << endl;
        cout << "\t\t\t------------" << endl;
        cout << "\n Hola bienvenido a Pizzeria Potasio. Yo sere tu guia. " << endl;
        cout << "\n\n\t\t\tEstas son tus opciones:" << endl;
        cout << "\t\t\t" << endl;
        cout << "\t1. Ingresar nombre" << endl;
        cout << "\t2. Hacer un pedido" << endl;
        cout << "\t3. Solicitar Factura" << endl;
        cout << "\t4. Cancelar Factura" << endl;

        cout << "\n\tIngresa tu numero de opcion: ";
        int opcion = 0;
        cin >> opcion;

        switch(opcion)
    {
        case 1: cout << "\n Ingresa tu nombre para iniciar tus pedidos: ";
                cin >> nombreCliente;
                cout << "\n\n\t\t\t Hola " << nombreCliente << " Ya puedes iniciar con tu pedido" <<endl;
                menu();
                break;

        case 2: cout << "\n\n\t\t\t"<<nombreCliente << " dinos que pizza quieres ordenar";
                menuPizza();
                 cout << "\n\tIngresa el nombre de la pizza que deseas: ";
                 cin >> pizza;
                 cout << "\n\n\t\t\tListo " << nombreCliente << " ahora elige el tamano que deseas por favor: ";
                 menuTamPiz();

                 cout << "\n\n\t\t\tListo " << nombreCliente << " ahora dejanos saber que refresco vas a ordenar";
                 menuFresco();
                 cout << "\n\tIngresa el nombre del refresco que deseas: ";
                 cin >> fresco;
                 cout << "\n\n\t\t\tGenial " << nombreCliente << " ahora elige de que tamano quieres tu refresco: ";
                 menuTamRef();

                 cout << "\n\n\t\t\tGrandioso " << nombreCliente << " ahora dinos como quieres el pan de tu pizza";
                 menuPanPiz();

                 cout << "\n\n\t\t\tListo " << nombreCliente << " ya para terminar dinos que postre quieres ordenar";
                 menuPostre();

                 cout << "\n\n\t\t\t Ya terminaste tu pedido " << nombreCliente << " para solicitar tu factura ingresa la opci�n 3" <<endl;
                 menu();


                break;
        case 3: cout << "\n\n\t\t\t Hola " << nombreCliente << " A continuaci�n te mostramos tu Factura:" <<endl;
                cout << "\t\t\t------------" << endl;
                cout << "\n\n\t\t\tCliente: " << nombreCliente <<endl;
                cout << "\n\n\t\t\t                              Pedido"<<endl;
                cout << "\n\n\t\t   Cantidad 		       Descripci�n 		Precio unitario           Subtotal" <<endl;
                cout << "\n\n\t\t       1 " <<"\t\t\t"<<pizza<<"\t\t\t"<<precioPizza<<"\t\t\t\t"<<precioPizza <<endl;
                cout << "\n\n\t\t       1 " <<"\t\t\t"<<fresco<<"\t\t\t"<<precioFresco<<"\t\t\t\t"<<precioFresco <<endl;
                cout << "\n\n\t\t       1 " <<"\t\t\t"<<pan<<"\t\t\t"<<precioPan<<"\t\t\t\t"<<precioPan <<endl;
                cout << "\n\n\t\t       1 " <<"\t\t\t"<<postre<<"\t\t\t"<<precioPostre<<"\t\t\t\t"<<precioPostre <<endl;
                cout << "\n\n\t\t\t                                                                      Total: Suave"<<endl;

        break;

        case 4: cout << "Usted ha seleccionado la opcion 4";

        break;

        default: cout << "Usted ha ingresado una opcion incorrecta";
}


}

int main()
{
cout << "\n\n\t\tHola usuario para iniciar selecciona la opcion 1 y dinos tu nombre" <<endl;
menu();
return 0;
}
