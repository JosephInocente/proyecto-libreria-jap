 #include <iostream>
//libreria string para poder usar el getline
#include <string>
//libreria vector para el manejo del vector
#include <vector>
//Manejo de archivos txt
#include <fstream>
using namespace std;
class Libro{
protected:
	string Codigo_libro;
	string Titulo_libro;
	string Autor_libro;
	string  Categoria_libro;
	int Cantidad_Mismo_libro;
	float Precio_libro;
public:
    // Constructor por defecto
    Libro();
    // Constructor con parámetros
    Libro(string, string, string, string, int, float);
    // Método para imprimir los detalles del libro
    void imprimirLibro();   
    //los métodos set
    void setCodigoLibro(string codigo) {
        Codigo_libro = codigo;
    }

    void setTituloLibro(string titulo) {
        Titulo_libro = titulo;
    }

    void setAutorLibro(string autor) {
        Autor_libro = autor;
    }

    void setCategoriaLibro(string categoria) {
        Categoria_libro = categoria;
    }

    void setCantidadMismoLibro(int cantidad) {
        Cantidad_Mismo_libro = cantidad;
    }

    void setPrecioLibro(float precio) {
        Precio_libro = precio;
    }

    // Métodos get
    string getCodigoLibro() {
        return Codigo_libro;
    }

    string getTituloLibro() {
        return Titulo_libro;
    }

    string getAutorLibro() {
        return Autor_libro;
    }

    string getCategoriaLibro() {
        return Categoria_libro;
    }

    int getCantidadMismoLibro() {
        return Cantidad_Mismo_libro;
    }

    float getPrecioLibro() {
        return Precio_libro;
    }
};
//metodos de la clase libro
Libro::Libro(){
    Codigo_libro = "";
        Titulo_libro = "";
        Autor_libro = "";
        Categoria_libro = "";
        Cantidad_Mismo_libro = 0;
        Precio_libro = 0.0;
}
Libro::Libro(string codigo, string titulo, string autor, string categoria, int cantidad, float precio) {
    Codigo_libro = codigo;
    Titulo_libro = titulo;
    Autor_libro = autor;
    Categoria_libro = categoria;
    Cantidad_Mismo_libro = cantidad;
    Precio_libro = precio;

}
void Libro::imprimirLibro() {
    cout << "\nDETALLES DEL LIBRO" << endl;
    cout << "Código: " << Codigo_libro << endl;
    cout << "Título: " << Titulo_libro << endl;
    cout << "Autor: " << Autor_libro << endl;
    cout << "Categoría: " << Categoria_libro << endl;
    cout << "Cantidad: " << Cantidad_Mismo_libro << endl;
    cout << "Precio: $" << Precio_libro << endl;
    cout << "************************************" << endl;
}

class Persona {
protected:
    string DNI;
    string Nombres;
    string Apellidos;

public:
    // Constructor por defecto
    Persona();
    // Constructor con parámetros
    Persona(string, string, string );
    //metodo para imprimir datos de la persona
    void imprimirDatosPersona();

    // Métodos set y get para DNI
    void setDNI(string dni) {
        DNI = dni;
    }

    string getDNI() {
        return DNI;
    }

    // Métodos set y get para Nombres
    void setNombres(string nombres) {
        Nombres = nombres;
    }

    string getNombres() {
        return Nombres;
    }

    // Métodos set y get para Apellidos
    void setApellidos(string apellidos) {
        Apellidos = apellidos;
    }

    string getApellidos() {
        return Apellidos;
    }
};
//metodos de la clase persona
Persona::Persona() {
    DNI = "";
    Nombres = "";
    Apellidos = "";
}
Persona::Persona(string dni, string nombres, string apellidos) {
    DNI = dni;
    Nombres = nombres;
    Apellidos = apellidos;
}
void Persona::imprimirDatosPersona() {
    cout << "DNI: " << DNI << endl;
    cout << "Nombres: " << Nombres << endl;
    cout << "Apellidos: " << Apellidos << endl;
}

//creamos el arreglo de libros como variable global
vector<Libro> Libros;
//declaramos los protipos de las funciones
int Menu();
int SubMenu_Listado();
int MenuEliminar_Segun();
void agregarLibroAlmacen();
void  Imprimir_Listado_Libros();
bool Codigo_Autor_Categoria_Libro_Existe(string, int);
void Buscar_Mostrar_Libro(string,int);
void Modificar_Libro(string);
void eliminar_Libro_Por_Codigo_Autor_o_Categoria(string,int);
int MenuVender_libro();
void Restar_de_la_galeria(string,int);
void Imprimir_Boleta(Libro,int,Persona);
void Vender_Libro();
void Guardar_Galeria_TXT();
void Cargar_Galeria_TXT();


int main() {
    //llamamos a la fucion cargar txt al iniciar el programa
    Cargar_Galeria_TXT();
    //variables para el ingreso de una cadena, para su busqueda ya sea codigo,autor o categoria
    string cadena;
    //variable para que diga si el libro existe o no, que es buscado por codigo
    bool existe = false;
    //variables para la opciones
    int op_Menu = 0, op_SubMenu = 0, op_eliminar = 0;
    do {
        //menu principal
        system("cls");
        op_Menu = Menu();
        switch (op_Menu) {
        case 1:               
            do {
                //limpiamos pantalla
                system("cls");
                //sub menu 
                op_SubMenu = SubMenu_Listado();
                switch (op_SubMenu) {
                case 1:
                    agregarLibroAlmacen();
                    Guardar_Galeria_TXT();
                    break;
                case 2:
                    //primero preguntamos si almenos hay un libro disponible
                    if (Libros.size() > 0) {
                        //procedimiento para modificar un libro
                        existe = false;
                        Imprimir_Listado_Libros();
                        cout << "\ningresar codigo del libro que desea modificar" << endl;
                        cout << "codigo: ";
                        cin >> cadena;
                        //ponemos 1, ya que solo necesitamos que busque por el codigo
                        //y en la funcion tenems implementamo 3 metodos de busqueda(1. codigo  2.autor  3.categoria)
                        existe = Codigo_Autor_Categoria_Libro_Existe(cadena, 1);
                        if (existe == true) {
                            //implementamos el modificar un libro
                            //ponemos 1, ya que solo necesitamos que muestre por el codigo
                            system("cls");
                            Buscar_Mostrar_Libro(cadena, 1);
                            Modificar_Libro(cadena);
                            Guardar_Galeria_TXT();
                            system("pause");
                        }
                        else {
                            system("cls");
                            cout << "ERROR!!! EL CODIGO NO EXISTE" << endl;
                            system("pause");
                        }
                    }
                    else {
                        //limpiamos pantalla
                        system("cls");
                        cout << "LIBRERIA VACIA" << endl;
                        system("pause");
                    }
                    break;
                case 3:
                    //primero preguntamos si almenos hay un libro disponible
                    if (Libros.size() > 0) {
                        //procedimiento para eliminar un libro
                        do {
                            //sub sub menu para eliminar segun sea: codigo, autor, categoria
                            op_eliminar = MenuEliminar_Segun();
                            switch (op_eliminar) {
                            case 1:
                                existe = false;
                                Imprimir_Listado_Libros();
                                cout << "\nINGRESAR EL CODIGO DEL LIBRO QUE DESEA ELIMINAR..." << endl;
                                cout << "CODIGO: ";
                                cin >> cadena;
                                existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op_eliminar);
                                if (existe == true) {
                                    //ponemos op_eliminar controla los 3 metodos de busqueda que tenemos implementados en la funcion (1. codigo  2.autor  3.categoria)
                                    system("cls");
                                    cout << "LIBRO(S) A ELIMINAR" << endl;
                                    Buscar_Mostrar_Libro(cadena, op_eliminar);
                                    eliminar_Libro_Por_Codigo_Autor_o_Categoria(cadena, op_eliminar);
                                    Imprimir_Listado_Libros();
                                    Guardar_Galeria_TXT();
                                    system("pause");
                                }
                                else {
                                    system("cls");
                                    cout << "ERROR!!! EL CODIGO NO EXISTE" << endl;
                                    system("pause");
                                }
                                break;
                            case 2:
                                existe = false;
                                Imprimir_Listado_Libros();
                                cout << "\nINGRESAR EL NOMBRE DEL AUTOR DE LOS LIBROS QUE DESEA ELIMINAR..." << endl;
                                cout << "NOMBRE: ";
                                cin.ignore();
                                getline(cin, cadena);
                                existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op_eliminar);
                                if (existe == true) {
                                    //ponemos op_eliminar controla los 3 metodos de busqueda que tenemos implementados en la funcion (1. codigo  2.autor  3.categoria)
                                    system("cls");
                                    cout << "LIBRO(S) A ELIMINAR" << endl;
                                    Buscar_Mostrar_Libro(cadena, op_eliminar);
                                    do {
                                        existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op_eliminar);
                                        if (existe == true) {
                                            eliminar_Libro_Por_Codigo_Autor_o_Categoria(cadena, op_eliminar);
                                        }
                                    } while (existe == true);
                                    Imprimir_Listado_Libros();
                                    Guardar_Galeria_TXT();
                                    system("pause");
                                }
                                else {
                                    system("cls");
                                    cout << "ERROR!!! EL AUTOR NO EXISTE" << endl;
                                    system("pause");
                                }
                                break;
                            case 3:
                                existe = false;
                                Imprimir_Listado_Libros();
                                cout << "\nINGRESAR LA CATEGORIA DE LOS LIBROS QUE DESEA ELIMINAR..." << endl;
                                cout << "CATEGORIA: ";
                                cin.ignore();
                                getline(cin, cadena);
                                existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op_eliminar);
                                if (existe == true) {
                                    //ponemos op_eliminar controla los 3 metodos de busqueda que tenemos implementados en la funcion (1. codigo  2.autor  3.categoria)
                                    system("cls");
                                    cout << "LIBRO(S) A ELIMINAR" << endl;
                                    Buscar_Mostrar_Libro(cadena, op_eliminar);
                                    do {
                                        existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op_eliminar);
                                        if (existe == true) {
                                            eliminar_Libro_Por_Codigo_Autor_o_Categoria(cadena, op_eliminar);
                                        }
                                    } while (existe == true);
                                    Imprimir_Listado_Libros();
                                    Guardar_Galeria_TXT();
                                    system("pause");
                                }
                                else {
                                    system("cls");
                                    cout << "ERROR!!! LA CATEGORIA NO EXISTE" << endl;
                                    system("pause");
                                }
                                break;
                            }
                        } while (op_eliminar != 4);
                    }
                    else {
                        //limpiamos pantalla
                        system("cls");
                        cout << "LIBRERIA VACIA" << endl;
                        system("pause");
                    }
                    break;
                case 4:
                    //limpiamos pantalla
                    system("cls");
                    //vemos el listado de libros
                    if (Libros.size() > 0) {
                        Imprimir_Listado_Libros();
                        system("pause");
                    }
                    else {
                        //limpiamos pantalla
                        system("cls");
                        cout << "LIBRERIA VACIA" << endl;
                        system("pause");
                    }
                    break;
                }
            } while (op_SubMenu != 5);
            break;
        case 2:
            Vender_Libro();
            break;
        }
    } while (op_Menu != 3);


	return 0;
}

//funciones fuera de las clases
int Menu() {
    string op;
    int numero;
    do {
        cout << "MENU DE OPCIONES" << endl;
        cout << "[1]Entrar a la galeria de libros" << endl;
        cout << "[2]Vender un libro" << endl;
        cout << "[3]Salir" << endl;;
        cin >> op;
        bool esNumero = true;
        for (char c : op) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            numero = stoi(op);
            if (numero >= 1 && numero <= 3) {
                break;
            }
        }
    } while (true);
    
    return numero;
}
int SubMenu_Listado() {
    string op;
    int numero;
    do {
        cout << "OPCIONES DEL LISTADO DE LIBROS" << endl;
        cout << "[1]Agregar nuevo libro" << endl;
        cout << "[2]Modificar Libro" << endl;
        cout << "[3]Eliminar libro" << endl;
        cout << "[4]Ver listado de libros" << endl;
        cout << "[5]Salir" << endl;
        cin >> op;
        bool esNumero = true;
        for (char c : op) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            numero = stoi(op);
            if (numero >= 1 && numero <= 5) {
                break;
            }
        }
    } while (true);
    return numero;
}
int MenuEliminar_Segun() {
    string op;
    int numero;
    do {
        cout << "MENU ELIMINAR..." << endl;
        cout << "[1]Por codigo" << endl;
        cout << "[2]Por Autor" << endl;
        cout << "[3]Por Categoria" << endl;
        cout << "[4]salir" << endl;
        cin >> op;
        bool esNumero = true;
        for (char c : op) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            numero = std::stoi(op);
            if (numero >= 1 && numero <= 4) {
                break;
            }
        }
    } while (true);
    return numero;
}

void agregarLibroAlmacen() {
    string Codigo;
    string Titulo;
    string Autor;
    string  Categoria;
    string cadena;//manejo de excepciones
    int cantidad;
    float Precio;
    bool existe = false;
    //creamos un libro temporal con el que trabajaremos al agregar nuevo libro
    Libro Libro_Temporal;
    cout << "Ingrese los detalles del libro " << Libros.size() + 1 << ":" << endl;
    do {
        cout << "Codigo: ";
        cin >> Codigo;
        //llamamos a la funcion para que reviseque el codigo existe o no 
        //asi controlar y pedir nuevamente si es que ya existe
        existe = Codigo_Autor_Categoria_Libro_Existe(Codigo, 1);
        //si existe es true quiere decir que existe, y vuelve a pedir
    } while (existe == true);
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, Titulo);
    cout << "Autor: ";
    getline(cin, Autor);
    cout << "Categoria: ";
    getline(cin, Categoria);
    do {
        cout << "Cantidad: ";
        cin >> cadena;
        bool esNumero = true;
        for (char c : cadena) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            cantidad = stoi(cadena);
            if (cantidad >= 1) {
                break;
            }
        }
    } while (true);
    do{
        cout << "Precio: ";
        cin >> cadena;
        bool esNumero = true;
        for (char c : cadena) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            Precio = stoi(cadena);
            if (Precio >= 1) {
                break;
            }
        }
    } while (true);    
    Libro_Temporal.setCodigoLibro(Codigo);
    Libro_Temporal.setTituloLibro(Titulo);
    Libro_Temporal.setAutorLibro(Autor);
    Libro_Temporal.setCategoriaLibro(Categoria);
    Libro_Temporal.setCantidadMismoLibro(cantidad);
    Libro_Temporal.setPrecioLibro(Precio);
    Libros.push_back(Libro_Temporal);
}
//imprime la galeria de libros completa
void  Imprimir_Listado_Libros() {
    cout << "LISTADO DE LIBROS DISPONIBLES" << endl;
    for (int i = 0; i < Libros.size(); i++) {
        Libros[i].imprimirLibro();
    }
}

//booleanos que nos retorna verdadero si el codigo, autor o categoria existe
//la condicion es segun la opcion que elije el vendedor en el menu
//1. codigo  2.autor  3.categoria
bool Codigo_Autor_Categoria_Libro_Existe(string codigo, int condicion) {
    bool Existe = false;
    if (condicion == 1) {
        for (int i = 0; i < Libros.size(); i++) {
            if (Libros[i].getCodigoLibro() == codigo) {
                Existe = true;
            }
        }
    }
    if (condicion == 2) {
        for (int i = 0; i < Libros.size(); i++) {
            if (Libros[i].getAutorLibro() == codigo) {
                Existe = true;
            }
        }
    }
    if (condicion == 3) {
        for (int i = 0; i < Libros.size(); i++) {
            if (Libros[i].getCategoriaLibro() == codigo) {
                Existe = true;
            }
        }
    }
    return Existe;
}

//funcion que busca un libro y lo imprimie, y en caso de ser mas de 1, imprime todos
//la condicion es segun la opcion que elije el vendedor en el menu
//1. codigo  2.autor  3.categoria
void Buscar_Mostrar_Libro(string cadena, int condicion) {
    //condicion 1, muestra segund el codigo igresado
    if (condicion == 1) {
        for (int i = 0; i < Libros.size(); i++) {
            if (Libros[i].getCodigoLibro() == cadena) {
                Libros[i].imprimirLibro();
            }
        }
    }
    //condicion 2, muestra segun el autor determinado
    if (condicion == 2) {
        for (int i = 0; i < Libros.size(); i++) {
            if (Libros[i].getAutorLibro() == cadena) {
                Libros[i].imprimirLibro();
            }
        }
    }
    //condiion 3, muestra segun la categoria determinada
    if (condicion == 3) {
        for (int i = 0; i < Libros.size(); i++) {
            if (Libros[i].getCategoriaLibro() == cadena) {
                Libros[i].imprimirLibro();
            }
        }
    }
}
void Modificar_Libro(string codigo) {
    
    string Titulo;
    string Autor;
    string  Categoria;
    string cadena;//manejo de excepciones
    int Cantidad;
    float Precio;
    for (int i = 0; i < Libros.size(); i++) {
        if (Libros[i].getCodigoLibro() == codigo) {
            cout << "MODIFICAR DETALLES DEL LIBRO" << endl;;
            cout << "Titulo: ";
            cin.ignore();
            getline(cin, Titulo);
            cout << "Autor: ";
            getline(cin, Autor);
            cout << "Categoria: ";
            getline(cin, Categoria);
            do {
                cout << "Cantidad: ";
                cin >> cadena;
                bool esNumero = true;
                for (char c : cadena) {
                    if (!isdigit(c)) {
                        esNumero = false;
                        break;
                    }
                }

                if (esNumero) {
                    Cantidad = stoi(cadena);
                    if (Cantidad >= 1) {
                        break;
                    }
                }
            } while (true);
            do {
                cout << "Precio: ";
                cin >> cadena;
                bool esNumero = true;
                for (char c : cadena) {
                    if (!isdigit(c)) {
                        esNumero = false;
                        break;
                    }
                }

                if (esNumero) {
                    Precio = stoi(cadena);
                    if (Precio >= 1) {
                        break;
                    }
                }
            } while (true);
            Libros[i].setTituloLibro(Titulo);
            Libros[i].setAutorLibro(Autor);
            Libros[i].setCategoriaLibro(Categoria);
            Libros[i].setCantidadMismoLibro(Cantidad);
            Libros[i].setPrecioLibro(Precio);
        }
    }
}
void eliminar_Libro_Por_Codigo_Autor_o_Categoria(string cadena, int condicion) {
    // Buscar el libro y eliminarlo del vector
    //it = Libros.begin(); it != Libros.end(), lo utilizamos para para iterar sobre todos los elementos del vector "Libros"
    if (condicion == 1) {
        for (auto iterador = Libros.begin(); iterador != Libros.end(); ++iterador) {
            // para obtener el código de un libro a través de un iterador
            if (iterador->getCodigoLibro() == cadena) {
                Libros.erase(iterador);
                break;
            }
        }
    }
    if (condicion == 2) {
        for (auto iterador = Libros.begin(); iterador != Libros.end(); ++iterador) {
            // para obtener el código de un libro a través de un iterador
            if (iterador->getAutorLibro() == cadena) {
                Libros.erase(iterador);
                break;
            }
        }
    }
    if (condicion == 3) {
        for (auto iterador = Libros.begin(); iterador != Libros.end(); ++iterador) {
            // para obtener el código de un libro a través de un iterador
            if (iterador->getCategoriaLibro() == cadena) {
                Libros.erase(iterador);
                break;
            }
        }
    }
    
}


//FUNCIONES PARA LA SECION VENDER LIBRO
int MenuVender_libro() {
    string op;
    int numero;
    do {
        cout << "MENU VENDER LIBRO" << endl;
        cout << "[1]Mostrar toda la galeria de libros" << endl;
        cout << "[2]Mostrar segun autor determinado" << endl;
        cout << "[3]Mostar segun categoria determinada" << endl;
        cout << "[4]Salir" << endl;
        cin >> op;
        bool esNumero = true;
        for (char c : op) {
            if (!isdigit(c)) {
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            numero = stoi(op);
            if (numero >= 1 && numero <= 4) {
                break;
            }
        }
    } while (true);
    return numero;
}
//creamos a la fucion vender libro

//esta funcion restara la cantidad de libros, y en caso se compraron todas la existencias, la elimina
void Restar_de_la_galeria(string codigo, int cant) {
    int temporal=0;
    for (int i = 0; i < Libros.size(); i++) {
        if (Libros[i].getCodigoLibro() == codigo) {
            if (Libros[i].getCantidadMismoLibro() > cant) {
                temporal = Libros[i].getCantidadMismoLibro();
                temporal = temporal - cant;
                Libros[i].setCantidadMismoLibro(temporal);
            }
            else
            {
                //eliminamos el libro, y la condicion 1 es para que lo elimine por codigo
                eliminar_Libro_Por_Codigo_Autor_o_Categoria(codigo, 1);
            }
        }
    }
}
void Imprimir_Boleta(Libro libro, int cantidad,Persona cliente) {
    system("cls");
    cout << "            BOLETA DE VENTA"  << endl;
    cliente.imprimirDatosPersona();
    cout << "\nDETALLES DEL LIBRO" << endl;
    cout << "Codigo: " << libro.getCodigoLibro() << endl;
    cout << "Titulo: " << libro.getTituloLibro() << endl;
    cout << "Autor: " << libro.getAutorLibro() << endl;
    cout << "Categoria: " << libro.getCategoriaLibro() << endl;
    cout << "Cantidad: " << libro.getCantidadMismoLibro() << endl;
    cout << "Precio: $" << libro.getPrecioLibro() << endl;
    cout << "TOTAL A PAGAR: $" << libro.getCantidadMismoLibro() * libro.getPrecioLibro() << endl;
    cout << "************************************" << endl;
}
void Vender_Libro() {
    //declaramos a nuestro cliente
    Persona cliente;
    Libro Libro_Vendido;
    string DNI;
    string Nombres;
    string Apellidos;
    string Manejo_Cadena;//para la exceociones del ingreso de numero
    int op = 0, op2 = 0, cant = 0;
    bool existe;
    //al agregar la cantidad que deseamos comprar, tenemos que calcular si esa canidad esta disponible
    bool Cantidad_Disponible;
    string cadena;
    do {
        system("cls");
        op = MenuVender_libro();
        switch (op) {
        case 1:
            system("cls");
            //primero preguntamos si almenos hay un libro disponible
            if (Libros.size() > 0) {
                Imprimir_Listado_Libros();
                cout << "\nINGRESAR EL CODIGO DEL LIBRO QUE DESEA VENDER..." << endl;
                cout << "CODIGO: ";
                cin >> cadena;
                existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op);
                if (existe == true) {
                    system("cls");
                    cout << "LIBRO A VENDER" << endl;
                    Buscar_Mostrar_Libro(cadena, op);
                    do {
                        Cantidad_Disponible = false;                        
                        do {
                            cout << "Cantidad a vender" << endl;
                            cin >> Manejo_Cadena;
                            bool esNumero = true;
                            for (char c : Manejo_Cadena) {
                                if (!isdigit(c)) {
                                    esNumero = false;
                                    break;
                                }
                            }

                            if (esNumero) {
                                cant = stoi(Manejo_Cadena);
                                if (cant >= 1) {
                                    break;
                                }
                            }
                        } while (true);
                        for (int i = 0; i < Libros.size(); i++) {
                            if (Libros[i].getCodigoLibro() == cadena) {
                                if (Libros[i].getCantidadMismoLibro() >= cant) {
                                    Cantidad_Disponible = true;
                                }
                                else {
                                    cout << "cantidad no disponible" << endl;
                                }
                            }
                        }
                    } while (Cantidad_Disponible == false);
                    
                    do {
                        cout << "REALIZAR VENTA?" << endl;
                        cout << "[1]Si" << endl;
                        cout << "[2]No" << endl;
                        cin >> Manejo_Cadena;
                        bool esNumero = true;
                        for (char c : Manejo_Cadena) {
                            if (!isdigit(c)) {
                                esNumero = false;
                                break;
                            }
                        }
                        if (esNumero) {
                            op2 = stoi(Manejo_Cadena);
                            if (op2 >= 1 && op2 <= 2) {
                                break;
                            }
                        }
                    } while (true);
                    if (op2 == 1) {
                        cout << "DATOS DEL CLIENTE" << endl;
                        cout << "DNI : ";
                        cin >> DNI;
                        cin.ignore();
                        cout << "NOMBRES : ";
                        getline(cin, Nombres);
                        cout << "APELLIDOS : ";
                        getline(cin, Apellidos);
                        cliente.setDNI(DNI);
                        cliente.setNombres(Nombres);
                        cliente.setApellidos(Apellidos);
                        for (int i = 0; i < Libros.size(); i++) {
                            if (Libros[i].getCodigoLibro() == cadena) {
                                Libro_Vendido = Libros[i];
                            }
                        }
                        //cambiamos la cantidas a la cantidas comprada para hacer el calculo de la venta
                        Libro_Vendido.setCantidadMismoLibro(cant);
                        Imprimir_Boleta(Libro_Vendido, cant, cliente);
                        Restar_de_la_galeria(cadena, cant);//codigo,cantidad vendida
                        Guardar_Galeria_TXT();
                        system("pause");
                    }
                    else {
                        cout << "VENTA CANCELADA" << endl;
                        system("pause");
                    }
                }
                else {
                    system("cls");
                    cout << "ERROR!!! EL CODIGO NO EXISTE" << endl;
                    system("pause");
                }
            }
            else {
                cout << "LIBRERIA VACIA" << endl;
                system("pause");
            }
            break;
        case 2:
            system("cls");
            //primero preguntamos si almenos hay un libro disponible
            if (Libros.size() > 0) {
                cout << "\nINGRESAR EL NOMBRE DEL AUTOR QUE DESEA VER SUS LIBROS..." << endl;
                cout << "NOMBRE: ";
                cin.ignore();
                getline(cin, cadena);
                existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op);
                if (existe == true) {
                    //mostramos los libros por autor que ingresamos
                    Buscar_Mostrar_Libro(cadena, op);
                    //ingresamos el codigo del libro que queremos vender
                    cout << "\nINGRESAR EL CODIGO DEL LIBRO QUE DESEA VENDER..." << endl;
                    cout << "CODIGO: ";
                    cin >> cadena;
                    //colocamos 1 para que busque segun codigo
                    existe = Codigo_Autor_Categoria_Libro_Existe(cadena, 1);
                    //si ingresamos un codigo de la lista que es valido, hace la venta
                    if (existe == true) {
                        system("cls");
                        cout << "LIBRO A VENDER" << endl;
                        Buscar_Mostrar_Libro(cadena, 1);
                        do {
                            Cantidad_Disponible = false;
                            do {
                                cout << "Cantidad a vender" << endl;
                                cin >> Manejo_Cadena;
                                bool esNumero = true;
                                for (char c : Manejo_Cadena) {
                                    if (!isdigit(c)) {
                                        esNumero = false;
                                        break;
                                    }
                                }

                                if (esNumero) {
                                    cant = stoi(Manejo_Cadena);
                                    if (cant >= 1) {
                                        break;
                                    }
                                }
                            } while (true);
                            for (int i = 0; i < Libros.size(); i++) {
                                if (Libros[i].getCodigoLibro() == cadena) {
                                    if (Libros[i].getCantidadMismoLibro() >= cant) {
                                        Cantidad_Disponible = true;
                                    }
                                    else {
                                        cout << "cantidad no disponible" << endl;
                                    }
                                }
                            }
                        } while (Cantidad_Disponible == false);
                        do {
                            cout << "REALIZAR VENTA?" << endl;
                            cout << "[1]Si" << endl;
                            cout << "[2]No" << endl;
                            cin >> Manejo_Cadena;
                            bool esNumero = true;
                            for (char c : Manejo_Cadena) {
                                if (!isdigit(c)) {
                                    esNumero = false;
                                    break;
                                }
                            }
                            if (esNumero) {
                                op2 = stoi(Manejo_Cadena);
                                if (op2 >= 1 && op2 <= 2) {
                                    break;
                                }
                            }
                        } while (true);
                        if (op2 == 1) {
                            //colocamos 1 ya que cadena esta trabajando con el codigo
                            //y nuestra funcion e la condicion 1 elimina por codigo
                            cout << "DATOS DEL CLIENTE" << endl;
                            cout << "DNI : ";
                            cin >> DNI;
                            cin.ignore();
                            cout << "NOMBRES : ";
                            getline(cin, Nombres);
                            cout << "APELLIDOS : " << endl;
                            getline(cin, Apellidos);
                            cliente.setDNI(DNI);
                            cliente.setNombres(Nombres);
                            cliente.setApellidos(Apellidos);
                            for (int i = 0; i < Libros.size(); i++) {
                                if (Libros[i].getCodigoLibro() == cadena) {
                                    Libro_Vendido = Libros[i];
                                }
                            }
                            //cambiamos la cantidas a la cantidas comprada para hacer el calculo de la venta
                            Libro_Vendido.setCantidadMismoLibro(cant);
                            Imprimir_Boleta(Libro_Vendido, cant, cliente);
                            Restar_de_la_galeria(cadena, cant);
                            Guardar_Galeria_TXT();
                            system("pause");
                        }
                        else {
                            cout << "VENTA CANCELADA" << endl;
                            system("pause");
                        }
                    }
                    else {
                        system("cls");
                        cout << "ERROR!!! EL CODIGO NO EXISTE" << endl;
                        system("pause");
                    }
                }
                else {
                    system("cls");
                    cout << "ERROR!!! EL AUTOR NO EXISTE" << endl;
                    system("pause");
                }
            }
            else {
                cout << "LIBRERIA VACIA" << endl;
                system("pause");
            }
            break;
        case 3:
            system("cls");
            //primero preguntamos si almenos hay un libro disponible
            if (Libros.size() > 0) {
                cout << "\nINGRESAR EL NOMBRE DE LA CATEGORIA QUE DESEA VER SUS LIBROS..." << endl;
                cout << "CATEGORIA: ";
                cin.ignore();
                getline(cin, cadena);
                existe = Codigo_Autor_Categoria_Libro_Existe(cadena, op);
                if (existe == true) {
                    //mostramos los libros por categoria que ingresamos
                    Buscar_Mostrar_Libro(cadena, op);
                    //ingresamos el codigo del libro que queremos vender
                    cout << "\nINGRESAR EL CODIGO DEL LIBRO QUE DESEA VENDER..." << endl;
                    cout << "CODIGO: ";
                    cin >> cadena;
                    //colocamos 1 para que busque segun codigo
                    existe = Codigo_Autor_Categoria_Libro_Existe(cadena, 1);
                    //si ingresamos un codigo de la lista que es valido, hace la venta
                    if (existe == true) {
                        system("cls");
                        cout << "LIBRO A VENDER" << endl;
                        Buscar_Mostrar_Libro(cadena, 1);
                        do {
                            Cantidad_Disponible = false;
                            do {
                                cout << "Cantidad a vender" << endl;
                                cin >> Manejo_Cadena;
                                bool esNumero = true;
                                for (char c : Manejo_Cadena) {
                                    if (!isdigit(c)) {
                                        esNumero = false;
                                        break;
                                    }
                                }

                                if (esNumero) {
                                    cant = stoi(Manejo_Cadena);
                                    if (cant >= 1) {
                                        break;
                                    }
                                }
                            } while (true);
                            for (int i = 0; i < Libros.size(); i++) {
                                if (Libros[i].getCodigoLibro() == cadena) {
                                    if (Libros[i].getCantidadMismoLibro() >= cant) {
                                        Cantidad_Disponible = true;
                                    }
                                    else {
                                        cout << "cantidad no disponible" << endl;
                                    }
                                }
                            }
                        } while (Cantidad_Disponible == false);
                        do {
                            cout << "REALIZAR VENTA?" << endl;
                            cout << "[1]Si" << endl;
                            cout << "[2]No" << endl;
                            cin >> Manejo_Cadena;
                            bool esNumero = true;
                            for (char c : Manejo_Cadena) {
                                if (!isdigit(c)) {
                                    esNumero = false;
                                    break;
                                }
                            }
                            if (esNumero) {
                                op2 = stoi(Manejo_Cadena);
                                if (op2 >= 1 && op2 <= 2) {
                                    break;
                                }
                            }
                        } while (true);
                        if (op2 == 1) {
                            //colocamos 1 ya que cadena esta trabajando con el codigo
                            //y nuestra funcion e la condicion 1 elimina por codigo
                            cout << "DATOS DEL CLIENTE" << endl;
                            cout << "DNI : ";
                            cin >> DNI;
                            cin.ignore();
                            cout << "NOMBRES : ";
                            getline(cin,Nombres);
                            cout << "APELLIDOS : " << endl;
                            getline(cin, Apellidos);
                            cliente.setDNI(DNI);
                            cliente.setNombres(Nombres);
                            cliente.setApellidos(Apellidos);
                            for (int i = 0; i < Libros.size(); i++) {
                                if (Libros[i].getCodigoLibro() == cadena) {
                                    Libro_Vendido = Libros[i];
                                }
                            }
                            //cambiamos la cantidas a la cantidas comprada para hacer el calculo de la venta
                            Libro_Vendido.setCantidadMismoLibro(cant);
                            Imprimir_Boleta(Libro_Vendido, cant, cliente);
                            Restar_de_la_galeria(cadena, cant);
                            Guardar_Galeria_TXT();
                            system("pause");
                        }
                        else {
                            cout << "VENTA CANCELADA" << endl;
                            system("pause");
                        }
                    }
                    else {
                        system("cls");
                        cout << "ERROR!!! EL CODIGO NO EXISTE" << endl;
                        system("pause");
                    }
                }
                else {
                    system("cls");
                    cout << "ERROR!!! LA CATEGORIA NO EXISTE" << endl;
                    system("pause");
                }
            }
            else {
                cout << "LIBRERIA VACIA" << endl;
                system("pause");
            }
            break;
        }
    } while (op != 4);
}
/*
void Guardar_Galeria_TXT() {
    //Guardar los productos del arreglo al txt
    ofstream Libreria;
    Libreria.open("Libros.txt", ios::app);
    if (Libreria.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        for (int i = 0; i < Libros.size(); i++) {
            Libreria << "DETALLES DEL LIBRO " << i + 1 << "\n";
            Libreria << "Código:" << Libros[i].getCodigoLibro() << "-";
            Libreria << "Título:" << Libros[i].getTituloLibro() << "-";
            Libreria << "Autor:" << Libros[i].getAutorLibro() << "-";
            Libreria << "Categoría:" << Libros[i].getCategoriaLibro() << "-";
            Libreria << "Cantidad:" << Libros[i].getCantidadMismoLibro() << "-";
            Libreria << "Precio $:" << Libros[i].getPrecioLibro() << "\n";
        }
    }
    Libreria.close();
    //eliminamos el antiguo txt
    remove("Libreria.txt");
    //renombramos nuestro txt temporal como el antigua
    rename("Libros.txt", "Libreria.txt");
}
void Cargar_Galeria_TXT() {
    Libro Libro_Temporal;
    //Si el archivo Vehiculo existe
    ifstream Libreria;
    string Cadena;
    Libreria.open("Libreria.txt", ios::in);//abrimos el archivo
    //preguntamos si se abrio correctamente el archivo
    if (Libreria.fail()) {
        cout << "No se pudo abrir el archivo  Almacen.txt, o no existe." << endl;
    }
    else {
        cout << "se pudo abrir el archivo Almacen.txt" << endl;
    }
    //si el archivo se pudo abrir?
    if (Libreria.is_open()) {
        int line_number = 0;
        while (getline(Libreria, Cadena)) {
            line_number++;
            if (line_number % 2 == 0) {
                //Funcion para separar en la variable token, los caracteres hasta el separador "|"
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                //el primer token es el msj de "codigo" asi que no se almacena
                token = strtok(NULL, "-");//este token es el valor de "codigo" asi que se almacena
                Libro_Temporal.setCodigoLibro(token);
                token = strtok(NULL, ":");//este token es el msj "Titulo" asi que no se almacena
                token = strtok(NULL, "-");//este token es el valor de "titulo" asi que se almacena
                Libro_Temporal.setTituloLibro(token);
                token = strtok(NULL, ":");//este token es el msj "Autor" asi que no se almacena
                token = strtok(NULL, "-");//este token es el valor de "Autor" asi que se almacena
                Libro_Temporal.setAutorLibro(token);
                token = strtok(NULL, ":");//este token es el msj "Categoria" asi que no se almacena
                token = strtok(NULL, "-");//este token es el valor de "Categoria" asi que se almacena
                Libro_Temporal.setCategoriaLibro(token);
                token = strtok(NULL, ":");//este token es el msj "Cantidad" asi que no se almacena
                token = strtok(NULL, "-");//este token es el valor de "Cantidad" asi que se almacena
                Libro_Temporal.setCantidadMismoLibro(atoi(token));
                token = strtok(NULL, ":");//este token es el msj "Precio" asi que no se almacena
                token = strtok(NULL, "-");//este token es el valor de "Precio" asi que se almacena
                Libro_Temporal.setPrecioLibro(stof(token));
                Libros.push_back(Libro_Temporal);
            }
        }
    }
}

*/

void Guardar_Galeria_TXT() {
    //Guardar los productos del arreglo al txt
    ofstream Libreria;
    Libreria.open("Libros.txt", ios::app);
    if (Libreria.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        for (int i = 0; i < Libros.size(); i++) {
            Libreria << "DETALLES DEL LIBRO " <<i+1<<"\n";
            Libreria << "Código:" << Libros[i].getCodigoLibro() << "\n";
            Libreria << "Título:" << Libros[i].getTituloLibro() << "\n";
            Libreria << "Autor:" << Libros[i].getAutorLibro() << "\n";
            Libreria << "Categoría:" << Libros[i].getCategoriaLibro() << "\n";
            Libreria << "Cantidad:" << Libros[i].getCantidadMismoLibro() << "\n";
            Libreria << "Precio $:" << Libros[i].getPrecioLibro() << "\n";
        }        
    }
    Libreria.close();
    //eliminamos el antiguo txt
    remove("Libreria.txt");
    //renombramos nuestro txt temporal como el antigua
    rename("Libros.txt", "Libreria.txt");
}
void Cargar_Galeria_TXT() {
    Libro Libro_Temporal;
    //Si el archivo Vehiculo existe
    ifstream Libreria;
    string Cadena;
    Libreria.open("Libreria.txt", ios::in);//abrimos el archivo
    //preguntamos si se abrio correctamente el archivo
    if (Libreria.fail()) {
        cout << "No se pudo abrir el archivo  Almacen.txt, o no existe." << endl;
    }
    else {
        cout << "se pudo abrir el archivo Almacen.txt" << endl;
    }
    //si el archivo se pudo abrir?
    if (Libreria.is_open()) {
        int line_number = 0;
        while (getline(Libreria, Cadena)) {
            line_number++;
            if (line_number>1) {
                //Funcion para separar la linea en tokens, buscamos el separados ":"
                char* token = strtok(const_cast<char*>(Cadena.c_str()), ":");
                //separa jasta : pero no hcaemos nada con ese token
                if (line_number == 2) {
                    token = strtok(NULL, "\n");//este token es el valor de "codigo" asi que se almacena
                    Libro_Temporal.setCodigoLibro(token);
                }
                if (line_number == 3) {
                    token = strtok(NULL, "\n");//este token es el valor de "titulo" asi que se almacena
                    Libro_Temporal.setTituloLibro(token);
                }
                if (line_number == 4) {
                    token = strtok(NULL, "\n");//este token es el valor de "Autor" asi que se almacena
                    Libro_Temporal.setAutorLibro(token);
                }
                if (line_number == 5) {
                    token = strtok(NULL, "\n");//este token es el valor de "Categoria" asi que se almacena
                    Libro_Temporal.setCategoriaLibro(token);
                }
                if (line_number == 6) {
                    token = strtok(NULL, "\n");//este token es el valor de "Cantidad" asi que se almacena
                    Libro_Temporal.setCantidadMismoLibro(atoi(token));
                }
                if (line_number == 7) {
                    token = strtok(NULL, "\n");//este token es el valor de "Precio" asi que se almacena
                    Libro_Temporal.setPrecioLibro(stof(token));
                    Libros.push_back(Libro_Temporal);
                    line_number = 0;
                }
            }
                
            
        }
    }
}