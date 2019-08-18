#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(){
	int n = 0;
	int x,y,op = -1;
	bool running = true;

	while (n < 1){
			cout << "Digite o numero de vertices:" << endl;
			cin >> n;
			cin.clear();
			fflush(stdin);
			if(n < 1){
				cout << "O numero de vertices deve ser maior que zero" << endl;
			}
	}

	int mat[n+1][n+1] = {0};

	while (x > -1 || y > -1){
		cout << "Digite as arestas:" << endl;
		cin >> x >> y;
		mat[x][y] = 1;
		mat[y][x] = 1;
	}
	for(int i = 1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	while(running){
		op = -1;
		while(op < 1 || op > 6){
			cout << "Escolha o numero referente a opcao desejada" << endl;
			cout << "1 - Criar um novo Grafo" << endl;
			cout << "2 - imprimir Matriz" << endl;
			cout << "3 - Salvar" << endl;
			cout << "4 - Carregar" << endl;
			cout << "5 - Descobrir se eh bipartido" << endl;
			cout << "6 - Encerrar" << endl;

			cin >> op;
			cin.clear();
			fflush(stdin);
		}
		
		switch(op){
			case 1:
				{
				do{
					cout << "Digite o numero de vertices:" << endl;
					cin >> n;
					cin.clear();
					fflush(stdin);
					if(n < 1){
						cout << "O numero de vertices deve ser maior que zero" << endl;
					}
				}while (n < 1);

				mat[n+1][n+1] = {0};

				do{
					cout << "Digite as arestas:" << endl;
					cin >> x >> y;
					mat[x][y] = 1;
					mat[y][x] = 1;
				}while (x > -1 || y > -1);

				break;
				}
			case 2:
				{
				for(int i = 1;i<=n;i++){
					for(int j=1;j<=n;j++){
						cout << mat[i][j] << " ";
					}
					cout << endl;
				}
					
				break;
				
				}
			case 3:
				{
					
				break;
				}
			case 4:
				{
					break;
				}
			default:
			{
				running = false;
				break;
			}
		}

	}
	
	
	return 0;
}
