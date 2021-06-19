#include <iostream>

using namespace std;

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
            menuAdmin();
            break;

        case 2:
            //string profe;
            //elegirProfe();
            menuProfe();
            break;

        case 3:
            //string estudiante;
            //elegirEstudiante();
            menuEstudiante();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

}


int main()
{
    //cargardatos();
    login();

    return 0;
}
