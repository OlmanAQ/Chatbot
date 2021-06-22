#include <iostream>
#include "fstream"
#include <cstring>
#include "string.h"

using namespace std;

char nombreCliente[15];
char pizza[30];
int precioPizza;

void menuTamPiz(){

        cout << "\n\n\t\t\tEstos son los diferentes tamaños de pizza disponibles:" << endl;
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
 // Texto del menú que se verá cada vez
        cout << "\n\n\t\t\tChatbot" << endl;
        cout << "\t\t\t------------" << endl;
        cout << "\n Hola bienvenido a Pizzeria Potasio. Yo sere tu guia. Para inicar selecciona la opcion 1 y dinos tu nombre. " << endl;
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
                 cout << "\n\n\t\t\tListo " << nombreCliente << " ahora elige el tamaño que deseas por favor: ";
                 menuTamPiz();



                break;
        case 3: cout << "Usted ha seleccionado la opcion 3";
        break;
        default: cout << "Usted ha ingresado una opcion incorrecta";
}


}

int main()
{
menu();
return 0;
}
