#include<iostream>
#include<algorithm>

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

int* fillFornecedores(int* fornecedores, int fornecedoresSize){
    for(int i = 0; i < fornecedoresSize; i++){
        cout << "informe a oferta do fornecedor " << i+1 << endl;
        cin >> fornecedores[i];
    }
    return fornecedores;
}

int* fillConsumidores(int* consumidores, int consumidoresSize){
    for(int i = 0; i < consumidoresSize; i++){
        cout << "informe a demanda do consumidor " << i+1 << endl;
        cin >> consumidores[i];
    }
    return consumidores;
}

int somaVetor(int* array, int tamanho){
    int soma = 0;
    for(int i = 0; i< tamanho; i++){
        soma += array[i];
    }
    return soma;
}

bool verifyBalanceamento(int* fornecedores, int fornecedoresSize, int* consumidores, int consumidoresSize){

    int soma = somaVetor(fornecedores, fornecedoresSize) - somaVetor(consumidores, consumidoresSize);

    if(soma == 0){
        cout << "balanceada" << endl;
        return true;
    }else{
        cout << "nao balanceada" << endl;
        return false;
    }
}

int** getMatriz(int fornecedoresSize, int consumidoresSize){

    int** matriz = new int*[fornecedoresSize] ;
    for(int i = 0; i < fornecedoresSize; i++){
        matriz[i] = new int[consumidoresSize];
    }

    return matriz;
}

int** fillMatrizCusto(int fornecedoresSize, int consumidoresSize, int** matriz){

    for(int i = 0; i < fornecedoresSize; i++){
        for(int j = 0; j < consumidoresSize; j++){
            cout << "informe o custo da posicao: " << i+1 << ", " << j+1 << endl;
            cin >> matriz[i][j];
        }
    }

    return matriz;

}

void printMatriz(int fornecedoresSize, int consumidoresSize, int** matriz){
 
    for(int i = 0; i < fornecedoresSize; i++){
        for(int j = 0; j < consumidoresSize; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

}

int** getMatrizAlocacao(int fornecedoresSize, int consumidoresSize){
    
    int** matriz = new int*[fornecedoresSize];
    for(int i = 0; i < fornecedoresSize; i++){
        matriz[i] = new int[consumidoresSize]();
    }

    return matriz;
}

int* copiaVetor(int* original, int tamanho){
    int* copia = new int[tamanho];
    
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            copia[i] = original[i];
        }
    }

    return copia;
}

int** cantoNoroeste(int* fornecedores, int fornecedoresSize, int* consumidores, int consumidoresSize){

    int** alocacao = getMatrizAlocacao(fornecedoresSize, consumidoresSize);

    int i = 0;
    int j = 0;

    int* ofertaCopia =  copiaVetor(fornecedores, fornecedoresSize);
    int* demandaCopia =  copiaVetor(consumidores, consumidoresSize);

    while(i < fornecedoresSize && j < consumidoresSize){
        int alocado = min(ofertaCopia[i], demandaCopia[j]);
        alocacao[i][j] = alocado;

        ofertaCopia[i] -= alocado;
        demandaCopia[j] -= alocado;

        if(ofertaCopia[i] == 0 && i < fornecedoresSize){
            i++;
        }else if(demandaCopia[j] == 0 && j < consumidoresSize){
            j++;
        }else{
            cout << "finalizando canto noroeste" << endl;
            break;
        }

    }

    return alocacao;
}

int getCustoTotal(int fornecedoresSize, int consumidoresSize, int** alocacao, int** custo){
    // percorre as duas matrizes juntas e soma alocacao[i][j] * custo[i][j]
    int soma =0;

    for(int i = 0; i < fornecedoresSize; i++){
        for(int j = 0; j < consumidoresSize; j++){
            soma += alocacao[i][j] * custo[i][j];
        }
    }

    return soma;

}

void getMenorCusto(int fornecedoresSize, int consumidoresSize, int** custo, int* ofertaCopia, int* demandaCopia, int &linhaEscolhida, int &colunaEscolhida){
    int menorCusto = 999999; 
    
    for(int i = 0; i < fornecedoresSize; i++){
        for(int j = 0; j < consumidoresSize; j++){
            if(ofertaCopia[i] > 0 && demandaCopia[j] > 0 && custo[i][j] < menorCusto){
                menorCusto = custo[i][j];
                linhaEscolhida = i;
                colunaEscolhida = j;
            }
        }
    }
}

int** menorCusto(int fornecedoresSize, int consumidoresSize, int* fornecedores, int* consumidores, int** custo){
    int** alocacao = getMatrizAlocacao(fornecedoresSize, consumidoresSize);
    int* ofertaCopia = copiaVetor(fornecedores, fornecedoresSize);
    int* demandaCopia = copiaVetor(consumidores, consumidoresSize);
    
    while(somaVetor(ofertaCopia, fornecedoresSize) > 0){
        int linha = -1;
        int coluna = -1;
        getMenorCusto(fornecedoresSize, consumidoresSize, custo, ofertaCopia, demandaCopia, linha, coluna);

        int alocado = min(ofertaCopia[linha], demandaCopia[coluna]);
        alocacao[linha][coluna] = alocado;

        ofertaCopia[linha] -= alocado;
        demandaCopia[coluna] -= alocado;
    }

    return alocacao;
}

int main(){

    int fornecedoresSize = getFornecedoresSize();
    int consumidoresSize = getConsumidoresSize();

    int* fornecedores = getFornecedores(fornecedoresSize);
    int* consumidores = getConsumidores(consumidoresSize);

    fornecedores = fillFornecedores(fornecedores, fornecedoresSize);
    consumidores = fillConsumidores(consumidores, consumidoresSize);

    bool balanceamento = verifyBalanceamento(fornecedores, fornecedoresSize, consumidores, consumidoresSize);
    if(!balanceamento){
        cout << "encerrando o programa" << endl;
        return 0;
    }

    int** matrizAlocacao = getMatrizAlocacao(fornecedoresSize, consumidoresSize);

    int** matrizCusto = getMatriz(fornecedoresSize, consumidoresSize);
    matrizCusto = fillMatrizCusto(fornecedoresSize, consumidoresSize, matrizCusto);

    //printMatriz(fornecedoresSize, consumidoresSize, matrizCusto);

    int option = 0;
    while(option != -1){
        cout << "informe qual heuristica iremos utilizar" << endl;
        cout << "digite 1 para canto noroeste" << endl;
        cout << "digite 2 para custo minimo" << endl;

        cout << "digite -1 para encerrar" << endl;
        cin >> option;

        if(option == 1){
            matrizAlocacao = cantoNoroeste(fornecedores, fornecedoresSize, consumidores, consumidoresSize);
            printMatriz(fornecedoresSize, consumidoresSize, matrizAlocacao);

            cout << "soma total do canto noroeste:" << endl;
            cout << getCustoTotal(fornecedoresSize, consumidoresSize, matrizAlocacao, matrizCusto) << endl;

        }else if(option == 2){
            matrizAlocacao = menorCusto(fornecedoresSize, consumidoresSize, fornecedores, consumidores, matrizCusto);
            printMatriz(fornecedoresSize, consumidoresSize, matrizAlocacao);

            cout << "soma total do menor custo:" << endl;
            cout << getCustoTotal(fornecedoresSize, consumidoresSize, matrizAlocacao, matrizCusto) << endl;

        }else if(option == -1){

        }else{
            cout << "digite um numero valido" << endl;
        }
    }

    return 0;
}

//https://excalidraw.com/#room=b9d0715350a27276e0e7,1rOShd0i2POw5N3VISgxwA