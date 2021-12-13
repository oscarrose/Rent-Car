#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
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

struct Autos
{
	int id;
	string Matricula;
	string Modelo;
	string Marca;
	string Estado;
};

// Function prototypes
void registerAuto();
int idAuto();
bool ValidarMatricula(string matricula);
void MostrarAutos();
void MostrarAutosId(int id);
void MostrarAutosMatricula(string matricula);
void MostrarAutosEstado(string estado);
void ModiAuto(int id);
void ModificarAuto();
bool AutoEstado(int id);
void consultarClientes();
void modificarClientes();
bool validarCedula(string cedula);
int incrementoCodigoCliente();
void registrarClientes();


// Function definitions

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


// metodo para registrar los autos
void registerAuto()
{
	try
	{
		cout << "Registro de Automoviles" << endl;

		struct Autos dataAuto;
		ofstream archivoAuto;

		archivoAuto.open("Autos.txt", ios::app);

		cout << "Introduce la matricula del auto: ";
		cin >> dataAuto.Matricula;

		if (!ValidarMatricula(dataAuto.Matricula))
		{
			dataAuto.id = idAuto();

			cout << "Introduce el modelo del auto: ";
			cin >> dataAuto.Modelo;

			cout << "Introduce la marca del auto: ";
			cin >> dataAuto.Marca;

			archivoAuto << endl;
			archivoAuto << dataAuto.id << " " << dataAuto.Matricula << " " << dataAuto.Modelo << " " << dataAuto.Marca << " " << dataAuto.Estado << "disponible";
			archivoAuto.close();
			cout << "Auto registrado correctamente" << endl;
		}
		else
		{

			cout << "Matricula existe" << endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	system("pause");
}

// metodo para generar el id del auto
int idAuto()
{
	int id = 1;
	struct Autos dataAuto;
	ifstream buscar;

	buscar.open("Autos.txt");
	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	buscar >> dataAuto.Estado;

	while (!buscar.fail())
	{
		buscar >> dataAuto.id;
		buscar >> dataAuto.Matricula;
		buscar >> dataAuto.Modelo;
		buscar >> dataAuto.Marca;
		buscar >> dataAuto.Estado;
		id=id+1;
	}
	buscar.close();
	return id;
}

// motodo para validar la matricula
bool ValidarMatricula(string matricula)
{

	bool existe = false;

	struct Autos dataAuto;
	ifstream buscar;

	buscar.open("Autos.txt");

	if (buscar.fail())
	{
		return existe;
	}

	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	buscar >> dataAuto.Estado;

	while (!buscar.eof() || existe == true)
	{
		if (dataAuto.Matricula == matricula)
		{
			existe = true;
			break;
		}

		buscar >> dataAuto.id;
		buscar >> dataAuto.Matricula;
		buscar >> dataAuto.Modelo;
		buscar >> dataAuto.Marca;
		buscar >> dataAuto.Estado;
	}
	buscar.close();
	return existe;
}

// metodo para mostrar los autos
void MostrarAutos()
{

	system("cls");
	ifstream buscar;
	struct Autos dataAuto;

	buscar.open("Autos.txt");

	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	buscar >> dataAuto.Estado;

	if (buscar.fail())
	{
		cout << "No hay autos registrados" << endl;
	}
	else
	{
		cout << "Listado de Automoviles" << endl;
	}

	cout
		<< left
		<< setw(10)
		<< "Id"
		<< left
		<< setw(12)
		<< "Matricula"
		<< left
		<< setw(10)
		<< "Modelo"
		<< left
		<< setw(10)
		<< "Marca"
		<< setw(10)
		<< "Estado"
		<< endl;

	while (!buscar.fail())
	{
		/*cout <<"Id: "<< dataAuto.id << endl;
		cout <<"Matricula: "<< dataAuto.Matricula << endl;
		cout <<"Modelo: "<< dataAuto.Modelo << endl;
		cout <<"Marca: "<< dataAuto.Marca << endl;
		cout <<"Estado: "<< dataAuto.Estado << endl;
		cout << endl;*/

		cout
			<< left
			<< setw(10)
			<< dataAuto.id
			<< left
			<< setw(12)
			<< dataAuto.Matricula
			<< left
			<< setw(10)
			<< dataAuto.Modelo
			<< left
			<< setw(10)
			<< dataAuto.Marca
			<< setw(10)
			<< dataAuto.Estado
			<< endl;

		buscar >> dataAuto.id;
		buscar >> dataAuto.Matricula;
		buscar >> dataAuto.Modelo;
		buscar >> dataAuto.Marca;
		buscar >> dataAuto.Estado;
	}
	buscar.close();
	system("pause");
}

void MostrarAutosId(int id)
{
	system("cls");
	ifstream buscar;
	struct Autos dataAuto;

	buscar.open("Autos.txt");

	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	buscar >> dataAuto.Estado;

	if (buscar.fail())
	{
		cout << "No hay autos registrados" << endl;
	}
	else
	{
		cout << "Listado de Automoviles" << endl;
	}
	cout
		<< left
		<< setw(10)
		<< "Id"
		<< left
		<< setw(12)
		<< "Matricula"
		<< left
		<< setw(10)
		<< "Modelo"
		<< left
		<< setw(10)
		<< "Marca"
		<< setw(10)
		<< "Estado"
		<< endl;
	while (!buscar.eof() + 1)
	{
		if (dataAuto.id == id)
		{
			cout
				<< left
				<< setw(10)
				<< dataAuto.id
				<< left
				<< setw(12)
				<< dataAuto.Matricula
				<< left
				<< setw(10)
				<< dataAuto.Modelo
				<< left
				<< setw(10)
				<< dataAuto.Marca
				<< setw(10)
				<< dataAuto.Estado
				<< endl;
			break;
		}
		buscar >> dataAuto.id;
		buscar >> dataAuto.Matricula;
		buscar >> dataAuto.Modelo;
		buscar >> dataAuto.Marca;
		buscar >> dataAuto.Estado;
	}
	buscar.close();
	system("pause");
}

void MostrarAutosMatricula(string matricula)
{

	system("cls");
	ifstream buscar;
	struct Autos dataAuto;

	buscar.open("Autos.txt");

	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	buscar >> dataAuto.Estado;

	if (buscar.fail())
	{
		cout << "No hay autos registrados" << endl;
	}
	else
	{
		cout << "Listado de Automoviles" << endl;
	}
	cout
		<< left
		<< setw(10)
		<< "Id"
		<< left
		<< setw(12)
		<< "Matricula"
		<< left
		<< setw(10)
		<< "Modelo"
		<< left
		<< setw(10)
		<< "Marca"
		<< setw(10)
		<< "Estado"
		<< endl;
	while (!buscar.eof() + 1)
	{
		if (dataAuto.Matricula == matricula)
		{
			cout
				<< left
				<< setw(10)
				<< dataAuto.id
				<< left
				<< setw(12)
				<< dataAuto.Matricula
				<< left
				<< setw(10)
				<< dataAuto.Modelo
				<< left
				<< setw(10)
				<< dataAuto.Marca
				<< setw(10)
				<< dataAuto.Estado
				<< endl;
			break;
		}
		buscar >> dataAuto.id;
		buscar >> dataAuto.Matricula;
		buscar >> dataAuto.Modelo;
		buscar >> dataAuto.Marca;
		buscar >> dataAuto.Estado;
	}
	buscar.close();
	system("pause");
}

void MostrarAutosEstado(string estado)
{
	system("cls");
	ifstream buscar;
	struct Autos dataAuto;

	buscar.open("Autos.txt");

	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	buscar >> dataAuto.Estado;

	if (buscar.fail())
	{
		cout << "No hay autos registrados" << endl;
	}
	else
	{
		cout << "Listado de Automoviles" << endl;
	}
	cout
		<< left
		<< setw(10)
		<< "Id"
		<< left
		<< setw(12)
		<< "Matricula"
		<< left
		<< setw(10)
		<< "Modelo"
		<< left
		<< setw(10)
		<< "Marca"
		<< setw(10)
		<< "Estado"
		<< endl;
	while (!buscar.eof())
	{
		if (dataAuto.Estado == estado)
		{
			cout
				<< left
				<< setw(10)
				<< dataAuto.id
				<< left
				<< setw(12)
				<< dataAuto.Matricula
				<< left
				<< setw(10)
				<< dataAuto.Modelo
				<< left
				<< setw(10)
				<< dataAuto.Marca
				<< setw(10)
				<< dataAuto.Estado
				<< endl;
		}
		buscar >> dataAuto.id;
		buscar >> dataAuto.Matricula;
		buscar >> dataAuto.Modelo;
		buscar >> dataAuto.Marca;
		buscar >> dataAuto.Estado;
	}
	buscar.close();
	system("pause");
}

void ModificarAuto()
{
	Autos dataAuto;
	ifstream archivo;
	ofstream axuAuto;
	int BuscarId;

	archivo.open("Autos.txt", ios::in);

	axuAuto.open("auxAutos.txt", ios::out);

	MostrarAutos();

	cout << "Ingrese el id del auto a modificar: ";
	cin >> BuscarId;

	archivo >> dataAuto.id;
	archivo >> dataAuto.Matricula;
	archivo >> dataAuto.Modelo;
	archivo >> dataAuto.Marca;
	archivo >> dataAuto.Estado;

	while (!archivo.eof())
	{

		if (dataAuto.id == BuscarId)
		{

			cout << "Ingrese la nueva matricula: ";
			cin >> dataAuto.Matricula;
			cout << "Ingrese el nuevo modelo: ";
			cin >> dataAuto.Modelo;
			cout << "Ingrese la nueva marca: ";
			cin >> dataAuto.Marca;

		

			axuAuto << dataAuto.id << " " << dataAuto.Matricula << " " << dataAuto.Modelo << " " << dataAuto.Marca<< " " << dataAuto.Estado << endl;
		}
		else
		{

	

			axuAuto << dataAuto.id << "" << dataAuto.Matricula << " " << dataAuto.Modelo << " " << dataAuto.Marca << " " << dataAuto.Estado << endl;
		}
		archivo >> dataAuto.id;
		archivo >> dataAuto.Matricula;
		archivo >> dataAuto.Modelo;
		archivo >> dataAuto.Marca;
		archivo >> dataAuto.Estado;
	}
	archivo.close();
	axuAuto.close();

	remove("Autos.txt");
	rename("auxAutos.txt", "Autos.txt");
	cout << "Vehiculo modificado con exito" << endl;
	system("pause");
}

bool AutoEstado( int id)
{
	Autos dataAuto;
	ifstream archivo;
	ofstream axuAuto;

	bool cambiado;

	archivo.open("Autos.txt", ios::in);

	axuAuto.open("auxAutos.txt", ios::out);

	archivo >> dataAuto.id;
	archivo >> dataAuto.Matricula;
	archivo >> dataAuto.Modelo;
	archivo >> dataAuto.Marca;
	archivo >> dataAuto.Estado;

	while (!archivo.eof())
	{

		if (dataAuto.id ==id)
		{

			dataAuto.Estado = "Alquilado";

			axuAuto << dataAuto.id << " " << dataAuto.Matricula << " " << dataAuto.Modelo << " " << dataAuto.Marca<< " " << dataAuto.Estado << endl;
			cambiado=true;
			
		}
		if (dataAuto.id != id)
		{

			axuAuto << dataAuto.id << "" << dataAuto.Matricula << " " << dataAuto.Modelo << " " << dataAuto.Marca << " " << dataAuto.Estado << endl;
		}
		archivo >> dataAuto.id;
		archivo >> dataAuto.Matricula;
		archivo >> dataAuto.Modelo;
		archivo >> dataAuto.Marca;
		archivo >> dataAuto.Estado;
	}
	archivo.close();
	axuAuto.close();

	remove("Autos.txt");
	rename("auxAutos.txt", "Autos.txt");

	if	(cambiado)
	{
		return true;
	}
	else
	{
		return false;
	}
}
