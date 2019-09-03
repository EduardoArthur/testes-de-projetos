#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

/*
vector<vector<int>> mat;

void colore(int x){

	cor[x]=0;
	vector<int>fila;
	fila.push_back(x);
	int pos = 0;
	while (pos < (int)fila.size()){
		int atual = fila[pos];
		pos++;
		for(int i=0;i<n;i++){
			if(mat[atual][i]){
				if(cor[i] == -1){
					cor[i] = 1 - cor[atual];
					fila.push_back(i);
				}
			}
		}
	}
	
}


bool bipartido(){
	for(int i=0;i<n;i++){
		if(cor[i] = -1){
			colore(i);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j]){
				if(cor[i] == cor[j]){
					return false;
				}
			}
		}
	}
	return true;
}
*/

int main(){
	int n = 0;
	int x,y,op = -1;
	bool running = true;
	string arquivo;
	vector<vector<int>> mat;

	while (n < 1){
			cout << "Digite o numero de vertices:" << endl;
			cin >> n;
			cin.clear();
			fflush(stdin);
			if(n < 1){
				cout << "O numero de vertices deve ser maior que zero" << endl;
			}
	}

	
	for(int i = 0;i<=n;i++){
		vector<int> tmp;
		for(int j=0;j<=n;j++){
			tmp.push_back(0);
		}
		mat.push_back(tmp);
	}

	while (x > -1 || y > -1){
		cout << "Digite as arestas:" << endl;
		cin >> x >> y;
		if(x > -1 && y > -1  && x <= n && y <= n){
			mat[x][y] = 1;
			mat[y][x] = 1;
		}
		cin.clear();
		fflush(stdin);
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
					mat.clear();
				do{
					cout << "Digite o numero de vertices:" << endl;
					cin >> n;
					cin.clear();
					fflush(stdin);
					if(n < 1){
						cout << "O numero de vertices deve ser maior que zero" << endl;
					}
				}while (n < 1);

				for(int i = 0;i<=n;i++){
					vector<int> tmp;
					for(int j=0;j<=n;j++){
						tmp.push_back(0);
					}
					mat.push_back(tmp);
				}

				do{
					cout << "Digite as arestas:" << endl;
					cin >> x >> y;
					if(x > -1 && y > -1 && x <= n && y <= n){
						mat[x][y] = 1;
						mat[y][x] = 1;
					}
					cin.clear();
					fflush(stdin);
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
					cout << "digite o nome do grafo a ser salvo" << endl;
					cin >> arquivo;
					cin.clear();
					fflush(stdin);
					//FILE *s = fopen("grafosdata.txt","w");
					//fprintf(s,"%s \n",arquivo);
					//fclose(s);
					arquivo = arquivo + ".bin";
					char arq[arquivo.length()+1];
					for (int i = 0; i < sizeof(arq); i++) { 
						arq[i] = arquivo[i];  
					} 
					FILE *f = fopen(arq,"wb");
					fwrite(&n,sizeof(int),1,f);
					for(int i = 0;i<=n;i++){
						for(int j=0;j<=n;j++){
							fwrite(&mat[i][j],sizeof(int), 1 , f);
						}
					}
					fclose(f);
				break;
				}
			case 4:
				{
					mat.clear();
					//string salvos;
					//cout << "Grafos salvos:" << endl;
					//FILE *s = fopen("grafosdata.txt","r");
					//while(fscanf(s, "%s \n",salvos) != EOF){
					//	cout << salvos << endl;
					//}
					//fclose(s);

					cout << "digite o nome do grafo a ser carregado" << endl;
					cin >> arquivo;
					cin.clear();
					fflush(stdin);
					arquivo = arquivo + ".bin";
					char arq[arquivo.length()+1];
					for (int i = 0; i < sizeof(arq); i++) { 
						arq[i] = arquivo[i];  
					} 
					FILE *f = fopen(arq,"rb");
					fread(&n,sizeof(int),1,f);
					for(int i = 0;i<=n;i++){
						for(int j=0;j<=n;j++){
							fread(&mat[i][j],sizeof(int), 1 , f);
						}
					}
					fclose(f);
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
