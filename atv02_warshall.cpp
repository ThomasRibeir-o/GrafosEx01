#include<iostream>
 
using namespace std;
 
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
            cout << "existe aresta de " << i+1 << " para " << j+1 << "? (0 = nao, 1 = sim)" << endl;
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
 
int** copiaMatriz(int tamanho, int** original){
 
    int** copia = getMatriz(tamanho);
 
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            copia[i][j] = original[i][j];
        }
    }
 
    return copia;
}
 
int** warshall(int tamanho, int** matriz){
 
    
    int** resultado = copiaMatriz(tamanho, matriz);
 
    for(int k = 0; k < tamanho; k++){
        for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
                resultado[i][j] = resultado[i][j] || (resultado[i][k] && resultado[k][j]);
            }
        }
    }
 
    return resultado;
}
 
int main(){
 
    int tamanho = getTamanho();
 
    int** matriz = getMatriz(tamanho);
    matriz = fillMatriz(tamanho, matriz);
 
    cout << endl << "matriz de adjacencia (A):" << endl;
    printMatriz(tamanho, matriz);
 
    int** r = warshall(tamanho, matriz);
 
    cout << endl << "matriz de alcancabilidade (R) - fecho transitivo:" << endl;
    printMatriz(tamanho, r);
 
    return 0;
}
 
