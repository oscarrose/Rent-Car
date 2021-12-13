



int main(int argc, char const *argv[])
{
   
    return 0;
}





void MODIFICACION_SECUENCIAL(void) 
{ 
 int no_prod; // Variable local para el numero de producto que desea 
modificar 
 clrscr(); 
 cout << "\n\rMODIFICACION DE REGISTROS DE PRODUCTOS"; 
 alias=fopen("PRODUCTO.SEC","rb+"); // Intenta abrir el archivo 
PRODUCTO.SEC 
 // en modo de lectura/escritura 
 if(alias==NULL) // Valida la existencia del archivo 
 { 
 cout << "\n\n\n\rNo existe el archivo !!!"; 
 cout << "\n\r<<< Oprima cualquier tecla para continuar >>>"; 
 getch(); 
 return; 
 } 
 cout << "\n\n\n\rNumero de producto: "; cin >> no_prod; 
 fread(&Registro,sizeof(Registro),1,alias); 
 // Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
 while(!feof(alias)) // Ciclo mientras no se encuentre el final del 
archivo 
 { 
 if(Registro.no_prod==no_prod) 
 { 
 cout << "\n\rNo Prod Descripcion Cantidad 
Precio Garantia"; 
 cout << "\n\r------------------------------------------------------
------------------"; 
 
printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.no_prod,Registro.descr
ip, 
Registro.cantidad,Registro.precio,Registro.garantia); 
 cout << "\n\n\n\rAnote los nuevos datos ..."; 
 cout << "\n\rDescripcion: "; gets(Registro.descrip); 
 cout << "\n\rCantidad : "; cin >> Registro.cantidad; 
 cout << "\n\rPrecio : "; cin >> Registro.precio; 
 do 
 { 
 cout << "\n\rGarantia : "; Registro.garantia=toupper(getche()); 
 }while(Registro.garantia!='S' && Registro.garantia!='N'); 
 // Es necesario reposicionar el apuntador del archivo al principio 
Manejo de Archivos en Lenguaje C++ 
Ing. Bruno López Takeyas , M.C. 50 
del 
 // registro que desea modificar, ya que al leer un registro, el 
 // apuntador se posiciona en el registro siguiente 
 // La funcion ftell(alias) devuelve la posicion donde se encuentra 
el 
 // apuntador 
 fseek(alias,ftell(alias)-sizeof(Registro),SEEK_SET); 
 fwrite(&Registro,sizeof(Registro),1,alias); // Graba el registro 
con 
 // los nuevos campos 
 fclose(alias); // Cierra el archivo 
 cout << "\n\n\n\rRegistro modificado !!!"; 
 cout << "\n\r<<< Oprima cualquier tecla para continuar >>>"; 
 getch(); 
 return; 
 } 
 fread(&Registro,sizeof(Registro),1,alias); 
 } 
 cout << "\n\rNo se encuentra ese registro !!!"; 
 fclose(alias); // Cierra el archivo 
 cout << "\n\r<<< Oprima cualquier tecla para continuar >>>"; 
 getch(); 
 return; 
} 