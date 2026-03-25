#include <iostream>

using namespace std;

int getTamanho(){
        int qntVertices;
        cout << "quantos Vertices tem essa aresta? "<< endl;
        cin >> qntVertices;

        return qntVertices;
}

int *criaGrafo(int qntVertices){//cria e preenche o grafo

    int *grafo = new int[qntVertices];

    //preenchendo o grafo
    for(int i = 0; i > qntVertices; i++){
        cout << "quantas arestas tem o vertice numero " << i + 1 << "? " << endl;
        cin >> grafo[i];
    }
    return grafo;

}

bool verificaImpar(int qntVertices, int *grafo){//verifica quantos vertices tem grau impar
    int contador = 0;
    for(int i = 0; i < qntVertices; i++){
        if(grafo[i] %2 != 0){
            contador ++;
        }
    }
    if(qntVertices%2 != 0){
        return false;
    }
    return true;

}

bool verificaSomatorioPar(int qntVertices, int *grafo){//soma e verifica se é par
    int soma = 0;
    for(int i = 0; i < qntVertices; i++){
        soma += grafo[i];
    }
    if(soma%2 == 0){
        return true;
    }
    return false;
}

void bubbleSortInvertido(int qntVertices, int *grafo){
    bool trocou = false;
    do{
        trocou = false;
        for(int i = 0; i < qntVertices -1; i++){
            if(grafo[i] < grafo[i+1]){
                swap(grafo[i], grafo[i+1]);
                trocou = true;
            }
        }
    }while(trocou);

}

bool regressao(int qntVertices, int *grafo){
    bubbleSortInvertido(qntVertices, grafo);
    
    if(grafo[0] == 0){
        return true;
    }

    int maiorValor = grafo[0];
    if(maiorValor >= qntVertices){
        return false;
    }
    grafo[0] = 0;

    for(int i = 1; i <= maiorValor; i++){
        grafo[i]--;
        if(grafo[i] < 0){
            return false;
        }
    }

    return regressao(qntVertices, grafo);
}

bool verificaGrafo(int qntVertices, int *grafo){//verifica todas as condicoes de existencia e rteorna se o grafo existe ou nao
    if(!verificaImpar(qntVertices, grafo)){
        return false;
    }
    if(!verificaSomatorioPar(qntVertices, grafo)){
        return false;
    }
    if(!regressao(qntVertices, grafo)){
        return false;
    }
    return true;
}

int main(){

    int qntVertices = getTamanho();
    int *grafo = criaGrafo(qntVertices);
    verificaImpar(qntVertices, grafo);
    verificaSomatorioPar(qntVertices, grafo);
    regressao(qntVertices, grafo);

    return 0;
}