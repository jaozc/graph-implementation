#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "grafo.hpp"

/*
    Turma B (segunda)
    Grupo:
    - Che Fan Pan               -- NUSP: 11200421
    - Joao Gabriel Zanao Costa  -- NUSP: 11234266
*/

using namespace std;

// Funcao que insere no grafo a celula que é adjacente pela direita
void direita_adj(Grafo *grafo, int i, int j, int N, int celula, int celula_adj)
{
    int nome_v_atual = (i*N + j);
    int valor_v_atual = celula;

    int nome_v_adj = (i*N + j+1); // Celula a direita da celula atual
    int valor_v_adj = celula_adj;

    grafo->add_aresta(nome_v_atual, valor_v_atual, nome_v_adj, valor_v_adj);
}

// Funcao que insere no grafo a celula que é adjacente por baixo
void abaixo_adj(Grafo *grafo, int i, int j, int N, int celula, int celula_adj)
{
    int nome_v_atual = (i*N + j);
    int valor_v_atual = celula;

    int nome_v_adj = ((i+1)*N + j); // Celula abaixo da celula atual
    int valor_v_adj = celula_adj;

    grafo->add_aresta(nome_v_atual, valor_v_atual, nome_v_adj, valor_v_adj);
}

int main()
{
    int N, num_vertices;
    
    cin >> N;

    // Total de vertices sera cada celula do tabuleiro (N x N)
    num_vertices = (N*N);

    // Matriz (N x N) que representa o tabuleiro
    int **tabuleiro = new int *[N];
    for(int i = 0; i < N; i++){
        tabuleiro[i] = new int [N];
    }

    // Leitura de cada celula do tabuleiro (0 ou 1)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int celula; // 0 ou 1
            cin >> celula;
            tabuleiro[i][j] = celula;
        }
    }

    // Posicao inicial ( i e j) do pacman e do fantasma
    int i_pac, j_pac, i_fan, j_fan;
    cin >> i_pac >> j_pac;
    cin >> i_fan >> j_fan;

    // Total de movimentos do fantasma
    int nro_mov_fantasma;
    cin >> nro_mov_fantasma;

    // Vetor dos movimentos que o fantasma realiza
    vector<char> movimentos;
    for(int i = 0; i < nro_mov_fantasma; i++){
        char m; // Letra que representa o movimento
        cin >> m;
        movimentos.push_back(m);
    }

    /* Montando o grafo:
       - Cada celula do tabuleiro representa um vertice do grafo.
       - Cada um destes vertices é nomeado de acordo com a expressao:
            - [(linha_atual*num_total_colunas) + coluna_atual]
            - Exemplo para N = 3: 
              - tabuleiro[0][0] == vertice 0
              - tabuleiro[2][1] == vertice 7
       - Ou seja, os vertices serao nomeados de 0 ate (N^2),
         da esquerda pra direta e para baixo.
    */

    Grafo *grafo = new Grafo();
    grafo->inicia_grafo(num_vertices);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // Verifica se nao está na ultima linha ou coluna
            if(i != N-1 && j != N-1){
                direita_adj(grafo, i, j, N, tabuleiro[i][j], tabuleiro[i][j+1]);                       
                abaixo_adj(grafo, i, j, N, tabuleiro[i][j], tabuleiro[i+1][j]);       
        
            }
            else if(i == N-1 && j != N-1){ // Se for a ultima linha do tabuleiro    
                direita_adj(grafo, i, j, N, tabuleiro[i][j], tabuleiro[i][j+1]);                         
            }
            else if(j == N-1 && i != N-1){ // Se for a ultima coluna do tabuleiro    
                abaixo_adj(grafo, i, j, N, tabuleiro[i][j], tabuleiro[i+1][j]);                                   
            }
        
        }
    }

    // Vertice inicial em que o Pacman está
    int v_pac = (i_pac*N + j_pac);
    // Vertice inicial em que o fantasma está
    int v_fan = (i_fan*N + j_fan);

    /*
    cout << "Lista de adjacencia: " << endl;
    grafo->print_grafo(num_vertices);
    */
   
    delete tabuleiro;
    grafo->deleta_lista();

    return 0;
}