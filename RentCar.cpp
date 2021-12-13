#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
// structure the data

// variable

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

// Main program

int main(int argc, char **argv)
{

	//registerAuto();
	//MostrarAutos();
	// MostrarAutosId(2);
	// MostrarAutosMatricula("frrfr");
	// MostrarAutosEstado("Disponible");
	//ModificarAuto();
	//AutoEstado(2);
	return 0;
}

// Function definitions

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