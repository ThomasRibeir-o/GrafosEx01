#include<iostream>

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

int* getFornecedores(int fornecedoresSize){

    int* fornecedores = new int[fornecedoresSize];

    return fornecedores;
}

int* getConsumidores(int consumidoresSize){

    int* consumidores = new int[consumidoresSize];

    return consumidores;
}

int* fillFornecedores(int* fornecedores, int fornecedores){
    for
}

bool balanceamento(int fornecedores, int consumidores){
    
}

int** getMatriz(int fornecedores, int consumidores){

    int** matriz = new int*[consumidores] ;
    for(int i = 0; i < consumidores; i++){
        matriz[i] = new int[fornecedores];
    }

    return matriz;
}

int** fillMatriz(int fornecedores, int consumidores, int** matriz){

    for(int i = 0; i < fornecedores; i++){
        for(int l = 0; l < consumidores; i++){
            cout << "informe o custo" << endl;
            cin >> matriz[i][l];
        }
    }

    return matriz;

}

int main(){

    int fornecedoresSize = getFornecedoresSize();
    int consumidoresSize = getConsumidoresSize();

    int* fornecedores = getFornecedores(fornecedoresSize);
    int* consumidores = getConsumidores(consumidoresSize);

    int** matriz = getMatriz(fornecedores, consumidores);


    return 0;
}