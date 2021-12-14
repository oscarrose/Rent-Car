#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "StructsAndMethods.cpp"
using namespace std;


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
    	cout<<"2. Consultar vehiculos";
    	
    	gotoxy(10,6);
    	cout<<"3. Consultar por ID";
    	
    	gotoxy(10,7);
    	cout<<"4. Consultar por matricula";
 
    	gotoxy(10,8);
    	cout<<"5. Modificar vehiculo";
 
    	gotoxy(10,9);
    	cout<<"6. Iniciar Mantenimiento"; 
    	
    	gotoxy(10,10);
    	cout<<"7. Terminar mantenimiento";
		
		gotoxy(10,11);
    	cout<<"8. Regresar";  
    
    	tecla = getch();
 
    	if (tecla == 72 && (opcionSeleccionada >=2 && opcionSeleccionada <=8))
		{
    	
 			opcionSeleccionada--;
    	}
    
    	else if (tecla == 80 && (opcionSeleccionada >=1 && opcionSeleccionada <=7))
		{
 
        	opcionSeleccionada++;
    	}
    
		else if (tecla == 13)
		{
        	if(opcionSeleccionada == 1){
        		system("cls");
            	registerAuto();
        	}
        
			else if(opcionSeleccionada == 2){
				system("cls");
            	MostrarAutos();
        	}
        	
        	else if(opcionSeleccionada == 3){
				system("cls");
				int id;
				cout << "Ingresar ID: ";
				cin >> id;
            	MostrarAutosId(id);
        	}
        	
        	else if(opcionSeleccionada == 4){
				system("cls");
				string matricula;
				cout << "Ingresar matricula: ";
				cin >> matricula;
            	MostrarAutosMatricula(matricula);
        	}
        
			else if(opcionSeleccionada == 5){
				system("cls");
            	ModificarAuto();
        	}
        	
        	else if(opcionSeleccionada == 6){
            	cout<<"Inicio mantenimiento";
            	break;
        	}
        	
        	else if(opcionSeleccionada == 7){
            	cout<<"Fin mantenimiento";
            	break;
        	}
        
			else if(opcionSeleccionada == 8){
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
    	cout<<"5. Devolver vehiculo";
		
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
            	system("cls");
            	AlquilerRegistrar();
        	}
        
			else if(opcionSeleccionada == 2){
            	
            	AlquilerConsultar();
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
    	cout<<"3. Gestionar alquileres";
 
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



