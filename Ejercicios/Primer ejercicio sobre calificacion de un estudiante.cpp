// Isaac Laguna 31.028.102
#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue>
#include <cmath>
// Librerias
using namespace std; //Permite el uso de espacios de nombres std

struct ntas_estudiante{ // Declaracion de estructura de datos
	int nota1primercorte;
	int nota2primercorte;
	int nota3primercorte;
	int notaprimercorte;
	int notasegundocorte;
	int notatercercorte;
	int notatotalequivalente;
	int notaequivalente_pts;
	string notaequivalente_letras;
}; // Fin de declaracion de estructura de datos

ntas_estudiante Estudiantes;
int opcion;

// Uso de metodos
void TotalPrimerCorte(){ 
	do{
		cout << "Ingrese nota de primer examen del primer corte: " << endl;
		cin >> Estudiantes.nota1primercorte;
		if (Estudiantes.nota1primercorte > 25){
			cout << "La nota ingresada no puede ser mayor de 25" << endl;
		}
	}while (Estudiantes.nota1primercorte > 25);
	
	do{
		cout << "Ingrese nota de segundo examen del primer corte: " << endl;
		cin >> Estudiantes.nota2primercorte;
		if (Estudiantes.nota2primercorte > 25){
			cout << "La nota ingresada no puede ser mayor de 25" << endl;
		}
	} while (Estudiantes.nota2primercorte > 25);
	
	do{
		cout << "Ingrese nota de tercer examen del primer corte: " << endl;
		cin >> Estudiantes.nota3primercorte;
		if (Estudiantes.nota3primercorte > 25){
			cout << "La nota ingresada no puede ser mayor de 25" << endl;
		}
	} while (Estudiantes.nota3primercorte > 25);
	
	Estudiantes.notaprimercorte = Estudiantes.nota1primercorte + Estudiantes.nota2primercorte + Estudiantes.nota3primercorte;
	system ("cls");
}

void TotalSegundoCorte(){
	do{
		cout << "Ingrese nota de evaluacion continua del segundo corte:" << endl;
		cin >> Estudiantes.notasegundocorte;
		if (Estudiantes.notasegundocorte > 10){
			cout << "La nota ingresada no puede ser mayor de 10" << endl;
		}
	}while (Estudiantes.notasegundocorte > 10);
	system ("cls");
}

void TotalTercerCorte(){
	do{
		cout << "Ingrese nota de trabajos continuos del tercer corte:" << endl;
		cin >> Estudiantes.notatercercorte;
		if (Estudiantes.notatercercorte > 15){
			cout << "La nota ingresada no puede ser mayor de 15" << endl;
		}
	}while (Estudiantes.notatercercorte > 15);
	system ("cls");
}
// Fin de uso de metodos

int main(){ // Inicio de main
	queue <ntas_estudiante> colaEstudiantes; // Declaracion de cola queue
	ntas_estudiante notaNueva;
	do{ //Inicio de bucle do while
		cout << "---------REGISTROS DE ESTUDIANTES---------" << endl;
		cout << "|1. Ingresar estudiante                  |" << endl;
		cout << "|2. Calificaciones de estudiante         |" << endl;
		cout << "|3. Sumatoria de califaciones            |" << endl;
		cout << "|4. Salir del programa                   |" << endl;
		cout << "------------------------------------------" << endl;
		cout << "Ingrese una opcion" << endl;
		cin >> opcion;
		system ("cls");
		switch (opcion){ // Inicio de switch
			case 1:
				if (!colaEstudiantes.empty()){
					cout << "No puedes ingresar otro estudiante ya que se encuentra uno en el registro..." << endl;
					}
				else{
					TotalPrimerCorte();
					TotalSegundoCorte();
					TotalTercerCorte();
					colaEstudiantes.push({Estudiantes.nota1primercorte, Estudiantes.nota2primercorte, Estudiantes.nota3primercorte, Estudiantes.notaprimercorte, Estudiantes.notasegundocorte, Estudiantes.notatercercorte, Estudiantes.notatotalequivalente, Estudiantes.notaequivalente_pts, Estudiantes.notaequivalente_letras});
					notaNueva = colaEstudiantes.front();
				} 
			// Realizar la acción correspondiente a la opción 1
			break;
			
			case 2:
				if (!colaEstudiantes.empty()){
				cout << "NOTAS DE ESTUDIANTE" << endl;
				cout << "--------------------" << endl;
				cout << "Primer corte: " << notaNueva.notaprimercorte << endl;
				cout << "--------------------" << endl;
				cout << "Segundo corte: " << notaNueva.notasegundocorte << endl;
				cout << "--------------------" << endl;
				cout << "Tercer corte: " << notaNueva.notatercercorte << endl;
				cout << "--------------------" << endl;
				}
				else{
					cout << "No se encuentra ningun estudiante registrado" << endl;
				}
			// Realizar la acción correspondiente a la opción 2
			break;
			
			case 3:
				if (!colaEstudiantes.empty()){
					notaNueva.notatotalequivalente = notaNueva.notaprimercorte + notaNueva.notasegundocorte + notaNueva.notatercercorte;
					cout << "El estudiante cuenta con un total de notas de todo el semestre de: " << notaNueva.notatotalequivalente << " ptos." << endl;
					notaNueva.notaequivalente_pts = notaNueva.notatotalequivalente / 5;
					cout << "Que equivaldria a: " << notaNueva.notaequivalente_pts << " ptos." << endl;
		
					if (notaNueva.notatotalequivalente >= 78){
						notaNueva.notaequivalente_letras = 'A';
						cout <<	"El estudiante obtuvo un rendimiento excelente con literal: " << notaNueva.notaequivalente_letras << endl;
					}
					else if (notaNueva.notatotalequivalente >= 63 && notaNueva.notatotalequivalente < 78){
						notaNueva.notaequivalente_letras = 'B';
						cout <<	"El estudiante obtuvo un rendimiento muy bueno con literal: " << notaNueva.notaequivalente_letras << endl;
					}
					else if (notaNueva.notatotalequivalente >= 48 && notaNueva.notatotalequivalente < 63){
						notaNueva.notaequivalente_letras = 'C';
						cout <<	"El estudiante obtuvo un rendimiento bueno con literal: " << notaNueva.notaequivalente_letras << endl;
					}
					else if (notaNueva.notatotalequivalente < 48){
						notaNueva.notaequivalente_letras = 'D';
						cout << "El estudiante no aprobo la materia con literal: " << notaNueva.notaequivalente_letras << endl;
					}
				}
				else{
					cout << "No se encuentra ningun estudiante registrado" << endl;
				}	
				colaEstudiantes.pop();
			// Realizar la acción correspondiente a la opción 3
			break;
			
			case 4:
				cout << "Saliendo del programa..." << endl;
			// Realizar la acción correspondiente a la opción 4
			break;
		} // Fin de switch
	} while (opcion != 4); // Fin de bucle do while
return 0;
} // Fin de main
