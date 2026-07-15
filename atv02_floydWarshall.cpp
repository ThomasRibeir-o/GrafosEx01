#include<iostream>
 
using namespace std;
 
const int INFINITO = 999999;
 
int getTamanho(){
 
    int tamanho = 0;
 
    cout << "informe a quantidade de vertices" << endl;
    cin >> tamanho;
 
    return tamanho;
}
 
int** getMatriz(int tamanho){
 
    int** matriz = new int*[tamanho];
    for(int i = 0; i < tamanho; i++){
        matriz[i] = new int[tamanho];
    }
 
    return matriz;
}
 
int** fillMatriz(int tamanho, int** matriz){
 
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
 
            if(i == j){
                matriz[i][j] = 0;
                continue;
            }
 
            cout << "informe o peso da aresta de " << i+1 << " para " << j+1 << " (limite: 999999) " << endl;
            cin >> matriz[i][j];
        }
    }
 
    return matriz;
}
 
void printMatriz(int tamanho, int** matriz){
 
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
 
}
 
int** floydWarshall(int tamanho, int** matriz){
 
    for(int k = 0; k < tamanho; k++){
        for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
                if(matriz[i][k] + matriz[k][j] < matriz[i][j]){
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }
            }
        }
    }
 
    return matriz;
}
 
int main(){
 
    int tamanho = getTamanho();
 
    int** matriz = getMatriz(tamanho);
    matriz = fillMatriz(tamanho, matriz);
 
    cout << endl << "matriz de pesos (P):" << endl;
    printMatriz(tamanho, matriz);
 
    matriz = floydWarshall(tamanho, matriz);
 
    cout << endl << "matriz das menores distancias (D):" << endl;
    printMatriz(tamanho, matriz);
 
    return 0;
}
