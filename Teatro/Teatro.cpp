#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define FILAS 10
#define COLUMNAS 15

bool verificarAsiento(char asientos[FILAS][COLUMNAS], int fila, char columna) {
    columna = toupper(columna);

    if (fila < 1 || fila > FILAS|| columna < 'A' || columna > 'A' + COLUMNAS - 1) {
        cout << "\nAsiento fuera de rango\n";
        return false;
    }

    if (asientos[fila - 1][columna - 'A'] == 'R') {
        cout << "\nEl asiento esta reservado.\n";
        return true;
    } else {
        cout << "\nEl asiento esta disponible.\n";
        return false;
    }
}

void imprimirAsientos (char asientos[FILAS][COLUMNAS]) 	{
	int i, j;
	printf("   ");
	for (j = 0; j < COLUMNAS; j++)	{
		cout << (char)('A' + j) << "  ";
		
	}
	printf("\n");
	
	for (i = 0; i < FILAS; i++) 	{
        cout << i + 1 << ": ";
		for (j = 0; j < COLUMNAS; j++)	{
            cout << asientos[i][j] << "  ";
		}
		cout<<endl;
	}
}


int main () {
	char asientoConfirmado;
	char salida;
	char respuestaDos;
	char rpt;
	char respuesta;
	bool cerrarPagina = false;
	bool reserva = false;
	bool cancelar = false;
	char asientos [FILAS][COLUMNAS];
	int fila;
	int opcion;
	char columna;
	
	cout << "Bienvenido al teatro del pueblo\n";
	
	for (int i = 0; i < FILAS; i++)	{
		for (int j = 0; j < COLUMNAS; j++)	{
				asientos[i][j] = '_';
		}
	}
	
	while (!cerrarPagina){
		
		cout << "\n---- Menu ----\n";
		cout << "1. Mapa de asientos.\n";
		cout << "2. Realizar una reserva.\n";
		cout << "3. Confirmar reserva.\n";
		cout << "4. Cancelar una reserva.\n";
		cout << "5. Salir.\n"; 
		cin >> opcion;
		switch (opcion){
			case 1:
				cout << "\n";
				cout << "---- Mapa de asientos ----\n";
				imprimirAsientos (asientos);
			break;
			case 2:
				cout << "---- Reservas ----\n" << endl;
				cout << "Ingrese la fila (1 - 10) y la columna (A - O) del asiento a reservar: \n";
				cin >> fila;   	
    			cin >> columna;
				columna = toupper(columna);
		
				if (verificarAsiento(asientos, fila, columna)){
					continue;			
				}
		
				cout << "Desea reservar este asiento? (S/N):";
				cin>>respuesta;
				respuesta = toupper(respuesta);
		
				switch (respuesta) {
            		case 'S':
               	 		asientos[fila - 1][columna - 'A'] = 'R';
                		cout << "\nAsiento reservado temporalmente.\n";
                		imprimirAsientos (asientos);
                	break;
                
            		case 'N':
                		cout << "\nReserva cancelada.\n";
                		imprimirAsientos (asientos);
                	break;
                
            		default:
               	 		cout << "\nMovimientto invalido.\n";
                	break;
        		}
			break;		
			case 3:
			    cout << "\n---- Confirmar reserva ----\n";
			    cout << "Confirmar un solo asiento reservado o todos? (U para uno solo / T para todos)\n";
			    cin >> asientoConfirmado;
			    asientoConfirmado = toupper(asientoConfirmado);
			
			    switch (asientoConfirmado) {
			        case 'U': {
			            cout << "Ingrese la fila (1 - " << FILAS << ") y la columna (A - " << (char)('A' + COLUMNAS - 1) << "):\n";
			            cin >> fila >> columna;
			            columna = toupper(columna);
			
			            // Verificar si el asiento está dentro del rango
			            if (fila < 1 || fila > FILAS || columna < 'A' || columna > 'A' + COLUMNAS - 1) {
			                cout << "\n  Asiento fuera de rango. Intente nuevamente.\n";
			                break; 
			            }
			
			            // Verificar si el asiento está reservado
			            if (asientos[fila - 1][columna - 'A'] == 'R') {
			                cout << "Confirma la reserva del asiento " << fila << columna << "? (S/N): ";
			                cin >> respuestaDos;
			                respuestaDos = toupper(respuestaDos);
			
			                if (respuestaDos == 'S') {
			                    asientos[fila - 1][columna - 'A'] = 'O';
			                    cout << "\n Asiento confirmado como ocupado.\n";
			                } else {
			                    cout << "\n Confirmacion cancelada.\n";
			                }
			            } else {
			                cout << "\n️  El asiento no esta reservado.\n";
			            }
			            imprimirAsientos(asientos);
			            break;
			        }
			
			        case 'T': {
			            bool hayReservas = false;
			
			            for (int i = 0; i < FILAS; i++) {
			                for (int j = 0; j < COLUMNAS; j++) {
			                    if (asientos[i][j] == 'R') {
			                        hayReservas = true;
			                        break;
			                    }
			                }
			                if (hayReservas) break;
			            }
			
			            if (!hayReservas) {
			                cout << "\n  No hay asientos reservados para confirmar.\n";
			                break;
			            }
			
			            cout << "Confirmas la reserva de todos los asientos? (C para confirmar, F para cancelar):\n";
			            cin >> respuestaDos;
			            respuestaDos = toupper(respuestaDos);
			
			            if (respuestaDos == 'C') {
			            	
			                for (int i = 0; i < FILAS; i++) {
			                    for (int j = 0; j < COLUMNAS; j++) {
			                        if (asientos[i][j] == 'R') {
			                            asientos[i][j] = 'O';
			                        }
			                    }
			                }
			                cout << "\nTodas las reservas han sido confirmadas como ocupadas.\n";
			            } else {
			                cout << "\nOperacion cancelada. No se modificaron las reservas.\n";
			            }
			            imprimirAsientos(asientos);
			            break;
			        }
			
			        default:
			            cout << "\nOpción invalida. Intente nuevamente.\n";
			            break;
			    }
			break;

        	case 4:
        		cout << "---- Cancelar reserva ----\n";
        		cout << "Desea cancelar la reserva? (S para confirmar / N para regresar al menu principal)\n";
       			cin >> rpt;
				if (rpt == 's' || rpt == 'S'){
       				for (int i = 0; i < FILAS; i++) {
               	   	 	for (int j = 0; j < COLUMNAS; j++) {
               				if (asientos[i][j] == 'R') {
               	 	   		 	asientos[i][j] = '_';
                       		}
                   		}
               		}
               		cout << "\nReserva cancelada.\n";
               		imprimirAsientos (asientos);
        		}
            break;
            
            case 5:
            	cout << "---- Cerrar pagina ----\n" << endl;
            	cout << " Salir? (S para confirmar / N para regresar al menu principal)\n";
            	cin >> salida;
            	if (salida == 's' || salida == 'S') {
            		cerrarPagina = true;
				}
        	break;
        	
			default:
			 cout << "Opcion denegada o fuera de los parametros. Intente nuevamente."<<endl;
			 break;
    	}
	}
}