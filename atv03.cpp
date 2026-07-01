#include<iostream>

using namespace std;

int getFornecedores(){

    int fornecedores;
    cout << "informe a quantidade de fornecedores" << endl;
    cin >> fornecedores;

    return fornecedores;
}

int getConsumidores(){

    int consumidores;
    cout << "informe a quantidade de consumidores" << endl;
    cin >> consumidores;

    return consumidores;
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

}

int main(){

    int fornecedores = getFornecedores();
    int consumidores = getConsumidores();

    int** matriz = getMatriz(fornecedores, consumidores);


    return 0;
}