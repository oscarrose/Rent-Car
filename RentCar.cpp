#include <iostream>
#include <stdio.h>
#include <fstream>
#include "VariadicTable.h"
#include <string.h>
#include <iomanip>
using namespace std;
//structure the data

struct Autos
{
	int id;
	string Matricula;
	string Modelo;
	string Marca;
	//float CostePorDia;
	string Estado; //(Alquilado, Disponible, Mantenimiento)
};

// Function prototypes
void registerAuto();
int idAuto();
bool ValidarMatricula(string matricula);
void MostrarAutos(int id, string matricula);

// Main program

int main(int argc, char **argv)
{

	//registerAuto();
	MostrarAutos(0,"");
	return 0;
}

// Function definitions

//metodo para registrar los autos
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

		//string getMatricula= dataAuto.Matricula;

		if (!ValidarMatricula(dataAuto.Matricula))
		{
			dataAuto.id = idAuto();

			cout << "Introduce el modelo del auto: ";
			cin >> dataAuto.Modelo;

			cout << "Introduce la marca del auto: ";
			cin >> dataAuto.Marca;

			//cout << "Introduce el coste por dia del auto: ";
			//cin >> dataAuto.CostePorDia;

			archivoAuto << endl;
			archivoAuto << dataAuto.id << " " << dataAuto.Matricula << " " << dataAuto.Modelo << " " << dataAuto.Marca << " " << dataAuto.Estado << "Disponible";
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

	struct Autos dataAuto;
	ifstream buscar;

	int id = 1;

	buscar.open("Autos.txt");
	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	//buscar>>dataAuto.CostePorDia;
	buscar >> dataAuto.Estado;

	while (!buscar.eof())
	{
		buscar >> dataAuto.id;
		buscar >> dataAuto.Matricula;
		buscar >> dataAuto.Modelo;
		buscar >> dataAuto.Marca;
		//buscar>>dataAuto.CostePorDia;
		buscar >> dataAuto.Estado;
		id++;
	}

	buscar.close();
	return id;
}

//motodo para validar la matricula
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
	//buscar>>dataAuto.CostePorDia;
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
		//buscar>>dataAuto.CostePorDia;
		buscar >> dataAuto.Estado;
	}
	buscar.close();
	return existe;
}

//metodo para mostrar los autos
void MostrarAutos(int id, string matricula)
{

	ifstream buscar;
	struct Autos dataAuto;

	buscar.open("Autos.txt");

	buscar >> dataAuto.id;
	buscar >> dataAuto.Matricula;
	buscar >> dataAuto.Modelo;
	buscar >> dataAuto.Marca;
	//buscar>>dataAuto.CostePorDia;
	buscar >> dataAuto.Estado;

	if (buscar.fail())
	{
		cout << "No hay autos registrados" << endl;
	}else{
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

				if (dataAuto.id == id)
				{
					cout << "ID: " << dataAuto.id << endl;
					cout << "Matricula: " << dataAuto.Matricula << endl;
					cout << "Modelo: " << dataAuto.Modelo << endl;
					cout << "Marca: " << dataAuto.Marca << endl;
					//cout << "Coste por dia: " << dataAuto.CostePorDia << endl;
					cout << "Estado: " << dataAuto.Estado << endl;
					break;
				}
				else if (dataAuto.Matricula == matricula)
				{
					cout << "ID: " << dataAuto.id << endl;
					cout << "Matricula: " << dataAuto.Matricula << endl;
					cout << "Modelo: " << dataAuto.Modelo << endl;
					cout << "Marca: " << dataAuto.Marca << endl;
					//cout << "Coste por dia: " << dataAuto.CostePorDia <<endl;
					cout << "Estado: " << dataAuto.Estado << endl;
					break;
				}
				else
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
				//buscar>>dataAuto.CostePorDia;
				buscar >> dataAuto.Estado;
			}
			buscar.close();
			system("pause");
}
		