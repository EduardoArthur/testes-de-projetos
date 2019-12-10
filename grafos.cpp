#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int Mat[MAXN][MAXN],Mat_nova[MAXN][MAXN];
int tam_f=0,n,numv=0,k=0;
vector<vector<int> > F;
int cor[MAXN], vis[MAXN], C[MAXN]; 


//Cria matriz
int Fill_Matriz(int n){
    int x,y;
    bool verificado = false;
    memset(Mat,0,sizeof(Mat));
    memset(cor, -1, sizeof(cor));
    do{
        cout << "Digite as arestas:" << endl;
        cin >> x >> y;
        cin.clear();
		fflush(stdin);
        if(x > 0 && y > 0 && x <= n && y <= n){
            Mat[x-1][y-1]=1;
            Mat[y-1][x-1]=1;
        }     
    }while(x > 0 || y > 0);
}

//Imprime Matriz
int Print(int M[1010][1010], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

//Salva arquivo
int Save_File(int n,int M[1010][1010],string filename){

    fstream myFile;
    myFile.open(filename, fstream::out);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            myFile << M[i][j] << " ";
        }
        myFile << endl;
    }
    myFile.close();
}

//Carrega arquivo
int Read_File(string filename){
    
    char c;
    int tmp;
    vector<int> aux;
    tam_f = 0;n = 0;
    ifstream myFile;
    myFile.open(filename);
    memset(Mat,0,sizeof(Mat));
    memset(cor, -1, sizeof(cor));

    myFile.get(c);
    while(myFile){
        while(c != '\n') {
            if(isdigit(c)){
                tmp = c - 48 ;
                aux.push_back(tmp); 
                tam_f++;
            } 
            myFile.get(c); 
        }
        F.push_back(aux);
        aux.clear();
        myFile.get(c);
    }
    tam_f = sqrt(tam_f);
    for(int i=0; i<tam_f;i++) {
        for(int j=0;j<tam_f;j++) Mat[i][j] = F[i][j];
    }
    F.clear();
    myFile.close();
    n = tam_f;
}

// Verifica bipartido
void colore(int x){ 
	
	cor[x] = 0; 
	
	vector<int> fila; 
	fila.push_back(x); 
	
	int pos = 0; 
	
	while(pos < (int)fila.size()){ 
		
		int atual = fila[pos]; 
		pos++;
        for(int j = 0; j < n; j++){
            if(Mat[atual][j]){
                if(cor[j] == -1){ 
                    cor[j] = 1 - cor[atual]; 			
                    fila.push_back(j); 
                }
            }
		}
	}
}

bool checa_bipartido(){
	
	for(int i = 0;i < n;i++){
		if(cor[i] == -1){       
			colore(i);         
		}
	}
	
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(Mat[i][j]){
			    if(cor[i] == cor[j]){
					return false;
				} 
            }
		}
	}
	
	return true; 
}

//Gera grafos

int n_cubo(int x){
    int tam_cubo = pow(2,x);
    memset(Mat_nova,0,sizeof(Mat_nova));

    if(x==0){
		Mat_nova[0][0] = 0;
	}else if(x==1){
        Mat_nova[0][0]=0;
        Mat_nova[0][1]=1;
        Mat_nova[1][0]=1;
        Mat_nova[1][1]=0;
    }else{
        int p = tam_cubo/2;
        n_cubo(x-1);
        for(int i=0;i<=p;i++){
            for(int j=0;j<=p;j++){
                Mat_nova[i+p][j+p] = Mat_nova[i][j];
            }
        }
        for(int i=0;i<tam_cubo;i++){
			Mat_nova[tam_cubo-i-1][i] = 1;
		}
    }
}

int Kn(int x){
    memset(Mat_nova,0,sizeof(Mat_nova));
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i==j){
				Mat_nova[i][j]=0;
			}else{
				Mat_nova[i][j]=1;
			}
        }
    }
}

int Pn(int x){
    memset(Mat_nova,0,sizeof(Mat_nova));
    for(int i=0;i<x;i++) {
        if(i != x-1){
			Mat_nova[i][i+1] = 1;
		}
        if(i != 0){
			Mat_nova[i][i-1] = 1;
		}
    }
}

int Cn(int x){
    memset(Mat_nova,0,sizeof(Mat_nova));
    for(int i=0;i<x;i++) {
        if(i>0){
			Mat_nova[i][i-1] = 1;
		}
        if(i!=x-1){
			Mat_nova[i][i+1] = 1;
		}
        if(i==0){
			Mat_nova[i][x-1] = 1;
		} 
        if(i==x-1){
			Mat_nova[i][0] = 1;
		}
    }
}

int Wn(int x){
    memset(Mat_nova,0,sizeof(Mat_nova));
    for(int i=0;i<x;i++) {
        if(i>0){
			Mat_nova[i][i-1] = 1;
		}
        if(i!=x-1){
			Mat_nova[i][i+1] = 1;
		}
        if(i==0){
			Mat_nova[i][x-2] = 1;
		} 
        if(i==x-1){
			Mat_nova[i][0] = 1;
		}
        Mat_nova[x][i] = 1;
        Mat_nova[i][x] = 1;
        Mat_nova[x][x] = 0;
    }
}

int Kn1_n2(int x,int y){
    memset(Mat_nova,0,sizeof(Mat_nova));
    int tot=0;
    tot = x+y;
    for(int i=0;i<tot;i++){
        for(int j=0;j<tot;j++){
            if(i!=j){
                if(i<x && j>=x){
					Mat_nova[i][j] = 1;
				}
                if(i>=x && j<x){
					Mat_nova[i][j] = 1;
				}
            }
        }
    }
}

// escolhe o grafo

int escolha_grafo(){
    int opcubo,cubo,op;
    bool ok = false;

	while(opcubo < 1 || opcubo > 5){
    cout << "Escolha o numero referente a opcao desejada" << endl;
    cout << "1 - Gerar N-Cubo(Qn)" << endl;
    cout << "2 - Gerar Completo(Kn) ou Caminho(Pn)" << endl;
    cout << "3 - Gerar Ciclo(Cn) ou Roda(Wn)" << endl;
    cout << "4 - Gerar Um Bipartido Completo(Kn1,n2)" << endl;
    cout << "5 - Voltar" << endl;
    cin >> opcubo;
    cin.clear();
	fflush(stdin);
	}

    switch (opcubo){
        int k;
        
        case 1:
                cout << "Digite o valor de n para gerar o N-Cubo(Qn)" << endl;
                cin >> cubo;
                cin.clear();
				fflush(stdin);
                while(!ok){
                    if (cubo < 0){
                        cout << "N precisa ser maior ou igual a 0" << endl;
                        cout << "Digite o valor de n" << endl;
                        cin >> cubo;
                        cin.clear();
						fflush(stdin);
                    }else{
						ok = true;
					}
                }
                n_cubo(cubo);
                int tam;
                tam = pow(2,cubo);
                Print(Mat_nova,tam);
                break;
            
        case 2: 
				cout << "Escolha o numero referente a opcao desejada" << endl;
                cout << "1 - Um Completo (Kn)" << endl;
                cout << "2 - Um Caminho (Pn)" << endl;
                cout << "3 - Voltar" << endl;
                cin >> op;
                cin.clear();
				fflush(stdin);
                
                switch(op){
                    case 1:
                            cout << "Digite o tamanho do Completo (Kn)" << endl;
                            cin >> k;
                            cin.clear();
							fflush(stdin);
                            while(!ok){   
                                if (k < 1){
                                    cout << "O tamanho tem que ser maior ou igual a 1" << endl;
                                    cout << "Digite um tamanho valido" << endl;
                                    cin >> k;
                                    cin.clear();
									fflush(stdin);
                                }else{
									ok = true;
								}
                            }
                            
                            Kn(k);
                            Print(Mat_nova,k);
                            
                            break;
                    
                    case 2:
                            cout << endl;
                            cout << "Digite o tamanho do Caminho(Pn)" << endl;
                            cin >> k;
							cin.clear();
							fflush(stdin);
                            while(!ok){
                                if (k<1){
                                    cout << "O tamanho tem que ser maior ou igual a 1" << endl;
                                    cout << "Digite um tamanho valido" << endl;
                                    cin >> k;
									cin.clear();
									fflush(stdin);
                                }else{ 
									ok = true;
								}
                            }
                            Pn(k);
                            Print(Mat_nova,k);
                            break;

                    default:
						break;
                    }
                break;
                
        case 3: 
				cout << "Escolha o numero referente a opcao desejada" << endl;
                cout << "1 - Um Ciclo (Cn)" << endl;
                cout << "2 - Um Roda (Wn)" << endl;
                cout << "3 - Voltar" << endl;
                cin >> op;
                cin.clear();
				fflush(stdin);
                switch(op){
                    case 1:
                        cout << "Digite o tamanho do Ciclo (Cn)" << endl;
                        cin >> k;
                        cin.clear();
						fflush(stdin);
                        while(!ok){   
                            if (k < 3){
                                cout << "O tamanho tem que ser maior ou igual a 3" << endl;
                                cout << "Digite um tamanho valido" << endl;
                                cin >> k;
                                cin.clear();
								fflush(stdin);
                            }else{
								ok = true;
							}
                        }
                        Cn(k);
                        Print(Mat_nova,k);
                        break;
                    
                    case 2:
                        cout << "Digite o tamanho da Roda (Wn)" << endl;
                        cin >> k;
                        cin.clear();
						fflush(stdin);
                        while(!ok){   
                            if (k < 3){
                                cout << "O tamanho tem que ser maior ou igual a 3!" << endl;
                                cout << "Digite um tamanho valido" << endl;
                                cin >> k;
                                cin.clear();
								fflush(stdin);
                            }else{
								ok = true;
								break;
							}
                        }
                        Wn(k);
                        Print(Mat_nova,k+1);
                        break;


                    default:
						break;
                }
            break;

        case 4:
                int n1, n2;
                do{
					cout << "Digite o tamanho da parte superior" << endl;
					cin >> n1;
					cin.clear();
					fflush(stdin);
					cout << "Digite o tamanho da parte inferior" << endl;
					cin >> n2;
					cin.clear();
					fflush(stdin);  
                    if (n1<1 && n2<1){
                        cout << "O tamanho de ambos tem que ser maior ou igual a 1" << endl;
                    }else{
						ok = true;
					}
                }while(!ok);
                Kn1_n2(n1,n2);
                Print(Mat_nova,n1+n2);
                break;
        default:
				break;
    }
}

// Conectividade

void DFS(int v){
    vis[v] = 1;
    for(int i = 0; i < n; i++){
        if(Mat[v][i]){
            if(!vis[i]){
				DFS(i);
			}
        }
    }
}

void checa_conexo(){
    int comp;
    comp = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            DFS(i);
            comp++;
        } 
    }
    if(comp == 1){
		cout << "Conexo" << endl;
	}else{
		cout << "Nao Conexo" << endl;
	}
}


//Arvore Geradora

int Cria_Arvore(){
    memset(Mat_nova,0,sizeof(Mat_nova));

    for(int i=0;i<n;i++) C[i] = i;


    for(int i=0;i<n;i++){
        if(C[i] == 0){
            for(int j=0;j<n;j++){
                if(C[j] != 0 && Mat[i][j] == 1){
                    Mat_nova[i][j] = 1;
                    C[j] = 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
                Mat_nova[j][i] = Mat_nova[i][j];
            }
        }
    }
}

// Mycielsky

int Mycielsky(int w, int num_crom){

    memset(Mat_nova,0,sizeof(Mat_nova));

    bool ok = false;

    if(w == num_crom) {
        for(int i=0;i<w;i++){
            for(int j=0;j<w;j++){
                if(i==j){
					Mat_nova[i][j] = 0;
				}else{
					Mat_nova[i][j] = 1;
				}
            }
        }
        numv = w;
    }else{
        Mycielsky(w,num_crom-1);
        k = numv;
        numv = 2*numv+1;
        cout << "1: " << k << " " << "2: " << numv << endl;
        for(int i=1;i<=k+1;i++){
            for(int j=1;j<=k+1;j++){
                Mat_nova[i+k][j+k] = Mat_nova[i-1][j-1];
                if(j<=k){
					Mat_nova[i+k][j] = Mat_nova[i-1][j-1];
				}
                if(i<=k){
					Mat_nova[i][j+k] = Mat_nova[i-1][j-1];
				}
            }
        }

        for(int i=0;i<numv;i++){
            for(int j=0;j<numv;j++){
                if(i==0 && j<=k){
					Mat_nova[i][j]=1;
				}
                if(i==0 && j>k){
					Mat_nova[i][j]=0;
				}
                if(j==0 && i<=k){
					Mat_nova[i][j]=1;
				}
                if(j==0 && i>k){
					Mat_nova[i][j]=0;
				}
                if((i>0 && i<k+1) && (j>0 && j<k+1)){
					Mat_nova[i][j]=0;
				}
                if(i==j){
					Mat_nova[i][j]=0;
				}
            }
        }

    }
}

int Call_Mycielsky(){
    int w=0,num_crom=0;
    bool ok = false;

	do{
		cout << "Digite o valor da clique maxima de Mat " << endl;
		cin >> w;
		cin.clear();
		fflush(stdin);
		cout << "Digite o numero cromatico " << endl;
		cin >> num_crom;
		cin.clear();
		fflush(stdin);
		if (w > num_crom) {
            cout << "O numero cromatico tem que ser maior ou igual ao numero da clique" << endl;
        }else{
			ok = true;
			break;
		}
    }while(!ok);
    Mycielsky(w,num_crom);
    if(w == num_crom){
		Print(Mat_nova, w);
	}else{
		Print(Mat_nova, numv);
	}
}



// Main

int main(void){

    int op,cubo,opcubo;
    int w=0,num_crom=0;
    string Filename;
    bool ok = false;
    bool running = true;
	
	while(running){
		op = 0;
		while(op < 1 || op > 10){
		cout << "Escolha o numero referente a opcao desejada" << endl;
		cout << "1  -  Preencher a Matriz" << endl;
		cout << "2  -  Imprimir Matriz" << endl;
		cout << "3  -  Salvar" << endl;
		cout << "4  -  Carregar" << endl;
		cout << "5  -  Descobrir se eh bipartido" << endl;
		cout << "6  -  Gerar Grafos" << endl;
		cout << "7  -  Descobrir se eh conexo" << endl;
		cout << "8  -  Arvore Geradora" << endl;
		cout << "9  -  Grafo de Mycielsky" << endl;
		cout << "10 -  Encerrar" << endl;
		cin >> op;
		cin.clear();
		fflush(stdin);
		}
			switch(op){
				case 1:
					do{
						cout << "Digite o numero de vertices:" << endl;
						cin >> n;
						cin.clear();
						fflush(stdin);
						if(n < 1){
							cout << "O numero de vertices deve ser maior que zero" << endl;
						}
					}while (n < 1);
					Fill_Matriz(n);
					ok = true;
					break;
						

				case 2: 
						cout << endl;
						cout << endl;
						if(ok){
							Print(Mat,n);
						}else{
							cout << "Por favor carregue um grafo salvo ou crie um novo" << endl;
						}
						break;

				case 3: 
						cout << "Digite o nome do arquivo: " << endl;
						cin >> Filename;
						Filename = Filename + ".txt";
						if(ok){
							fstream myFile;
							myFile.open(Filename, fstream::out);

							for(int i=0;i<n;i++){
								for(int j=0;j<n;j++){
									myFile << Mat[i][j] << " ";
								}
								myFile << endl;
							}

							myFile.close();
						}else{
							cout << "Nao existe um grafo para ser salvo" << endl;
						}
						break;

				case 4: 
						cout << "Digite o nome do arquivo: " << endl;
						cin >> Filename;
						Filename = Filename + ".txt";
						Read_File(Filename);
						ok = true;
						break;

				case 5: 
						if(ok){
							if(checa_bipartido()){
								cout << "eh bipartido" << endl;
							}else{
								cout << "nao eh bipartido" << endl;
							} 
						}else{
							cout << "Nao existe matriz preenchida" << endl;
						}
						
						break;

				case 6: 
						escolha_grafo();
						break;


				case 7: 
						
						checa_conexo();					
						break;

				case 8: 
						
						if(ok) {
							Cria_Arvore();
							Print(Mat_nova,n);   
						}else{
							cout << "Nao existe uma matriz preenchida" << endl;
						}
						break;

				case 9: 
						
						Call_Mycielsky();
						break;

				case 10: 
						running = false;
						break;						
		}
	}
	return 0;      
}
