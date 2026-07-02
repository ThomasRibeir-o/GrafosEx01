/*
Warshall(A, n)
Entrada:
A → matriz de adjacência n × n
Saída:
R → matriz de alcançabilidade
1. R ← A
2. para k ← 1 até n faça
3. para i ← 1 até n faça
4. para j ← 1 até n faça
5. R[i][j] ← R[i][j] OR (R[i][k] AND R[k][j])
6. fim-para
7. fim-para
8. fim-para
9. retorne R
*/

#include<iostream>
#include<vector>

using namespace std;

int getVertices(){

    int vertices = 0;

    cout << "informe a quantidade de vertices" << endl;
    cin >> vertices;

    return vertices;
}

int getArestas(){

    int arestas = 0;

    cout << "informe a quantidade de arestas" << endl;
    cin >> arestas;

    return arestas;
}

vector<vector<int>> Warshall(/*matriz de adjacencia*/){

}

// vector<vector<int>> getMatriz(int vertices, int arestas){
//     vector<vector<int>> matriz(vertices, vector<int>(arestas, 0));
//     return matriz;
// }

int main(){

    int vertices = getVertices();
    int arestas = getArestas();

    vector<vector<int>> matriz(vertices, vector<int>(arestas, 0));

    return 0;
}