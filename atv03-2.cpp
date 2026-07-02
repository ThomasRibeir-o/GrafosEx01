#include<iostream>
#include<vector>

using namespace std;

int getFornecedoresSize(){
    
    int fornecedoresSize = 0;

    cout << "informe a quantia de fornecedores" << endl;
    cin >> fornecedoresSize;

    return fornecedoresSize;
}

int getConsumidoresSize(){
    
    int consumidoresSize = 0;

    cout << "informe a quantia de consumidores" << endl;
    cin >> consumidoresSize;

    return consumidoresSize;
}

int fillMatriz(int matriz){

}

int main(){

    int fornecedoresSize = getFornecedoresSize();
    int consumidoresSize = getConsumidoresSize();

    vector<vector<int>> matriz(fornecedoresSize, vector<int>(consumidoresSize, 0));
    matriz = fillMatriz(matriz);


    return 0;
}

    // cout << "Digite os elementos da matriz (" << linhas << "x" << colunas << "):" << endl;
    // for (int i = 0; i < linhas; i++) {
    //     for (int j = 0; j < colunas; j++) {
    //         cout << "Matriz[" << i << "][" << j << "]: ";
    //         cin >> matriz[i][j];
    //     }
    // }

//https://excalidraw.com/#room=b9d0715350a27276e0e7,1rOShd0i2POw5N3VISgxwA