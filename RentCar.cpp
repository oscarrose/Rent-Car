#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;



//Structs
struct Clientes
{
	int CodigoCliente;	
	string Nombre;
	string Apellido;
	string Cedula;
	string Telefono;
	string FechaNacimiento;
	string Direccion;
};

struct Autos
{
	int Codigo;
	string Matricula;
	string Modelo;
	string Marca;
	string Estado;
};

struct Alquiler
{
	int CodigoAlquiler;
	string CedulaCliente;
	string FechaAlquiler;
	string Estado;
};

struct DetalleAlquiler
{
	int CodigoDetalle;
	int CodigoAlquiler;
	string MatriculaVehiculo;
	float PrecioPorDia;
	int DiasAlquiler;
	int DiasAtraso;
};



//Consulta de clientes
void consultarClientes()
{
	system("cls");
	
	struct Clientes cli;
	ifstream archivo;
	
	archivo.open("clientes.txt");
	archivo>>cli.CodigoCliente;
    archivo>>cli.Nombre;
    archivo>>cli.Apellido;
    archivo>>cli.Cedula;
    archivo>>cli.Telefono;
    archivo>>cli.FechaNacimiento;
    archivo>>cli.Direccion;
    
    while(!archivo.eof())
    {
        cout << "Codigo: " << cli.CodigoCliente << endl;
        cout << "Nombre: " << cli.Nombre << endl;
        cout << "Apellido: " << cli.Apellido << endl;
    	cout << "Cedula: " << cli.Cedula << endl;
    	cout << "Telefono: " << cli.Telefono << endl;
    	cout << "FechaNacimiento: " << cli.FechaNacimiento << endl;
    	cout << "Direccion: " << cli.Direccion << endl << endl;
                            
		archivo>>cli.CodigoCliente;
    	archivo>>cli.Nombre;
    	archivo>>cli.Apellido;
    	archivo>>cli.Cedula;
    	archivo>>cli.Telefono;
    	archivo>>cli.FechaNacimiento;
    	archivo>>cli.Direccion;
    }
    
	archivo.close();
	getch();
}


//Modificar cliente
void modificarClientes()
{
	ifstream archivo;
	ofstream auxiliar;
	struct Clientes c;
	string cedulaBuscar;
	
	archivo.open("clientes.txt", ios::in);
	auxiliar.open("auxiliar.txt", ios::out);
	
	consultarClientes();
	cout << "Ingresa la cedula del cliente a modificar: ";
	cin >> cedulaBuscar;
	
	archivo>>c.CodigoCliente;
    archivo>>c.Nombre;
    archivo>>c.Apellido;
    archivo>>c.Cedula;
    archivo>>c.Telefono;
    archivo>>c.FechaNacimiento;
    archivo>>c.Direccion;
	
	while(!archivo.eof()){
    
        if(c.Cedula == cedulaBuscar)
		{
            
            cout << endl << "Introduzca el nombre:  ";
            cin >> c.Nombre;
            cout << "Introduzca el apellido: ";
            cin >> c.Apellido;
            cout <<"Introduzca el telefono: ";
            cin >> c.Telefono;
            cout <<"Introduzca la fecha de nacimiento: ";
            cin >> c.FechaNacimiento;
            cout <<"Introduzca la direccion: ";
            cin >> c.Direccion;
    
			auxiliar<<endl;
            auxiliar<<c.CodigoCliente;
            auxiliar<<endl;
            auxiliar<<c.Nombre;
            auxiliar<<endl;
            auxiliar<<c.Apellido;
            auxiliar<<endl;
            auxiliar<<c.Cedula;
            auxiliar<<endl;
            auxiliar<<c.Telefono;
            auxiliar<<endl;
            auxiliar<<c.FechaNacimiento;
            auxiliar<<endl;
            auxiliar<<c.Direccion;
            auxiliar<<endl;

        }
        else
        {
        	
        	auxiliar<<endl;
            auxiliar<<c.CodigoCliente;
            auxiliar<<endl;
            auxiliar<<c.Nombre;
            auxiliar<<endl;
            auxiliar<<c.Apellido;
            auxiliar<<endl;
            auxiliar<<c.Cedula;
            auxiliar<<endl;
            auxiliar<<c.Telefono;
            auxiliar<<endl;
            auxiliar<<c.FechaNacimiento;
            auxiliar<<endl;
            auxiliar<<c.Direccion;
            auxiliar<<endl;
        	
        }
    
    
		archivo>>c.CodigoCliente;
    	archivo>>c.Nombre;
    	archivo>>c.Apellido;
    	archivo>>c.Cedula;
    	archivo>>c.Telefono;
    	archivo>>c.FechaNacimiento;
    	archivo>>c.Direccion;
    }
    
    archivo.close();
    auxiliar.close();    
    
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
	
}


bool validarCedula(string cedula)
{
	bool existe = false;

	struct Clientes c;
	ifstream archivo;

	archivo.open("clientes.txt");

	archivo >> c.CodigoCliente;
	archivo >> c.Nombre;
	archivo >> c.Apellido;
	archivo >> c.Cedula;
	archivo >> c.Telefono;
	archivo >> c.FechaNacimiento;
	archivo >> c.Direccion;

	while (!archivo.eof())
	{
		if (c.Cedula == cedula)
		{
			existe = true;
			break;
		}

		archivo >> c.CodigoCliente;
		archivo >> c.Nombre;
		archivo >> c.Apellido;
		archivo >> c.Cedula;
		archivo >> c.Telefono;
		archivo >> c.FechaNacimiento;
		archivo >> c.Direccion;
	}
	
	archivo.close();
	return existe;
}


int incrementoCodigoCliente()
{
	
	struct Clientes c; 
	int codigo = 1; 
	
	ifstream archivo; 
	 
	archivo.open("clientes.txt");
	 
	archivo>>c.CodigoCliente; 
	archivo>>c.Nombre; 
	archivo>>c.Apellido; 
	archivo>>c.Cedula; 
	archivo>>c.Telefono;
	archivo>>c.FechaNacimiento;
	archivo>>c.Direccion; 
	 
	while(!archivo.eof())
	{ 
		archivo>>c.CodigoCliente; 
		archivo>>c.Nombre; 
		archivo>>c.Apellido; 
		archivo>>c.Cedula; 
		archivo>>c.Telefono;
		archivo>>c.FechaNacimiento;
		archivo>>c.Direccion; 
		 
		codigo = codigo + 1;	 
	} 
	 
	archivo.close(); 
	return codigo; 
}


//Registro de clientes
void registrarClientes()
{
	system("cls");
	
	ofstream archivo;
	struct Clientes cli;
	
	cout << "Introduzca la cedula: ";
	cin >> cli.Cedula;
	
	if(validarCedula(cli.Cedula) == false)
	{
		cli.CodigoCliente = incrementoCodigoCliente();
		cout << "Introduzca el Nombre: ";
		cin >> cli.Nombre;
		cout << "Introduzca el Apellido: ";
		cin >> cli.Apellido;
		cout << "Introduzca el telefono: ";
		cin >> cli.Telefono;
		cout << "Introduzca la fecha de Nacimiento: ";
		cin >> cli.FechaNacimiento;
		cout << "Introduzca la direccion: ";
		cin >> cli.Direccion;
	
		archivo.open("clientes.txt", ios::out | ios::app);
		archivo<<cli.CodigoCliente;
		archivo<<endl;
    	archivo<<cli.Nombre;
    	archivo<<endl;
    	archivo<<cli.Apellido;
    	archivo<<endl;
    	archivo<<cli.Cedula;
    	archivo<<endl;
		archivo<<cli.Telefono;
		archivo<<endl;
		archivo<<cli.FechaNacimiento;
		archivo<<endl;
		archivo<<cli.Direccion;
		archivo<<endl;
		archivo.close();
	}
	else
	{
		cout << "La cedula ya existe";
		getch();
	}
	
}


//Funcion para manejo de coordenadas en la consola
void gotoxy(int x, int y){
    COORD c;
    c.X = x; 
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


//Menu clientes
void menu_clientes()
{
	int opcionSeleccionada = 1;
    int tecla;
    bool menu = true;
    
    while(menu)
	{
		system("cls");
		
		gotoxy(5, 3 + opcionSeleccionada);
    	cout << "==>";
    
	
		gotoxy(10,2);
    	cout<<"Menu Clientes";
	
		gotoxy(10,4);
    	cout<<"1. Registrar cliente";
 
    	gotoxy(10,5);
    	cout<<"2. Consultar cliente";
 
    	gotoxy(10,6);
    	cout<<"3. Modificar cliente";
 
    	gotoxy(10,7);
    	cout<<"4. Regresar"; 
    	
    	tecla = getch();
 
    	if (tecla == 72 && (opcionSeleccionada >=2 && opcionSeleccionada <=4))
		{
    	
 			opcionSeleccionada--;
    	}
    
    	else if (tecla == 80 && (opcionSeleccionada >=1 && opcionSeleccionada <=3))
		{
 
        	opcionSeleccionada++;
    	}
    
		else if (tecla == 13)
		{
        	if(opcionSeleccionada == 1){
            	registrarClientes();
        	}
        
			else if(opcionSeleccionada == 2){
            	consultarClientes();
        	}
        
			else if(opcionSeleccionada == 3){
            	modificarClientes();
        	}
        
			else if(opcionSeleccionada == 4){
				menu = false;
        	}
    	}
	}
}


//Menu vehiculos
void menu_vehiculos()
{
	int opcionSeleccionada = 1;
    int tecla;
    bool menu = true;
    
    while(menu)
	{
		system("cls");
		
		gotoxy(5, 3 + opcionSeleccionada);
    	cout << "==>";
    
	
		gotoxy(10,2);
    	cout<<"Menu Vehiculos";
	
		gotoxy(10,4);
    	cout<<"1. Registrar vehiculo";
 
    	gotoxy(10,5);
    	cout<<"2. Consultar vehiculo";
 
    	gotoxy(10,6);
    	cout<<"3. Modificar vehiculo";
 
    	gotoxy(10,7);
    	cout<<"4. Iniciar Mantenimiento"; 
    	
    	gotoxy(10,8);
    	cout<<"5. Terminar mantenimiento";
		
		gotoxy(10,9);
    	cout<<"6. Regresar";  
    
    	tecla = getch();
 
    	if (tecla == 72 && (opcionSeleccionada >=2 && opcionSeleccionada <=6))
		{
    	
 			opcionSeleccionada--;
    	}
    
    	else if (tecla == 80 && (opcionSeleccionada >=1 && opcionSeleccionada <=5))
		{
 
        	opcionSeleccionada++;
    	}
    
		else if (tecla == 13)
		{
        	if(opcionSeleccionada == 1){
            	cout<<"Registro vehiculos";
            	break;
        	}
        
			else if(opcionSeleccionada == 2){
            	cout<<"Consulta vehiculo";
            	break;
        	}
        
			else if(opcionSeleccionada == 3){
            	cout<<"Modificacion vehiculo";
            	break;
        	}
        	
        	else if(opcionSeleccionada == 4){
            	cout<<"Inicio mantenimiento";
            	break;
        	}
        	
        	else if(opcionSeleccionada == 5){
            	cout<<"Fin mantenimiento";
            	break;
        	}
        
			else if(opcionSeleccionada == 6){
				menu = false;
        	}
    	}
	}
}


//Menu alquileres
void menu_alquileres()
{
	int opcionSeleccionada = 1;
    int tecla;
    bool menu = true;
    
    while(menu)
	{
		system("cls");
		
		gotoxy(5, 3 + opcionSeleccionada);
    	cout << "==>";
    
	
		gotoxy(10,2);
    	cout<<"Menu Alquileres";
	
		gotoxy(10,4);
    	cout<<"1. Registrar alquiler";
 
    	gotoxy(10,5);
    	cout<<"2. Consultar alquiler";
 
    	gotoxy(10,6);
    	cout<<"3. Modificar alquiler";
 
    	gotoxy(10,7);
    	cout<<"4. Cancelar alquiler"; 
    	
    	gotoxy(10,8);
    	cout<<"5. Devolver vehículo";
		
		gotoxy(10,9);
    	cout<<"6. Regresar";  
    
    	tecla = getch();
 
    	if (tecla == 72 && (opcionSeleccionada >=2 && opcionSeleccionada <=6))
		{
    	
 			opcionSeleccionada--;
    	}
    
    	else if (tecla == 80 && (opcionSeleccionada >=1 && opcionSeleccionada <=5))
		{
 
        	opcionSeleccionada++;
    	}
    
		else if (tecla == 13)
		{
        	if(opcionSeleccionada == 1){
            	cout<<"Registro vehiculos";
            	break;
        	}
        
			else if(opcionSeleccionada == 2){
            	cout<<"Consulta alquiler";
            	break;
        	}
        
			else if(opcionSeleccionada == 3){
            	cout<<"Modificacion alquiler";
            	break;
        	}
        	
        	else if(opcionSeleccionada == 4){
            	cout<<"Cancelacion alquiler";
            	break;
        	}
        	
        	else if(opcionSeleccionada == 5){
            	cout<<"Devolucion auto";
            	break;
        	}
        
			else if(opcionSeleccionada == 6){
				menu = false;
        	}
    	}
	}
}


//Menu Principal
void menu_principal()
{
	int opcionSeleccionada = 1;
    int tecla;
    bool menu = true;
    
    while(menu)
	{
		system("cls");
		
		gotoxy(5, 3 + opcionSeleccionada);
    	cout << "==>";
    
	
		gotoxy(10,2);
    	cout<<"Sistema Rent Car";
	
		gotoxy(10,4);
    	cout<<"1. Gestionar clientes";
 
    	gotoxy(10,5);
    	cout<<"2. Gestionar vehiculos";
 
    	gotoxy(10,6);
    	cout<<"3. Gesstionar alquileres";
 
    	gotoxy(10,7);
    	cout<<"4. Salir\n"; 
    
    	tecla = getch();
 
    	if (tecla == 72 && (opcionSeleccionada >=2 && opcionSeleccionada <=4))
		{
    	
 			opcionSeleccionada--;
    	}
    
    	else if (tecla == 80 && (opcionSeleccionada >=1 && opcionSeleccionada <=3))
		{
 
        	opcionSeleccionada++;
    	}
    
		else if (tecla == 13)
		{
        	if(opcionSeleccionada == 1){
            	menu_clientes();
        	}
        
			else if(opcionSeleccionada == 2){
            	menu_vehiculos();
        	}
        
			else if(opcionSeleccionada == 3){
            	menu_alquileres();
        	}
        
			else if(opcionSeleccionada == 4){
				menu = false;
        	}
    	}
	}
}

int main(int argc, char** argv) {
	
	menu_principal();
	
	return 0;
}



