#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include "grafo.hpp"

using namespace std;

Grafo::Grafo(){

}

void Grafo::inicia_grafo(int v){
    this->v = v;
    adj = new list<vertice>[v]; // Aloca um vetor de lista com tamanho v vértices
}

void Grafo::add_aresta(int v1_nome, int v1_valor, int v2_nome, int v2_valor){
    vertice v1, v2;
    v1.nome = v1_nome;
    v1.valor = v1_valor;
    v2.nome = v2_nome;
    v2.valor = v2_valor;
    adj[v1_nome].push_back(v2);
    adj[v2_nome].push_back(v1);
}

/*
void Grafo::remove_aresta(int v1_nome, int v2_nome){
    vertice v1, v2;
    v1.nome  = v1_nome;
    v2.nome = v2_nome;
    adj[v1.nome].remove(v2);
    adj[v2.nome].remove(v1);
}*/


list<vertice> Grafo::vertices_adj2(int v){
   return adj[v];
}

void Grafo::vertices_adj(int v){
    for(list<vertice>::iterator i = adj[v].begin(); i != adj[v].end(); i++){
        cout << i->nome << " " ;
    }
}

int Grafo::grau_vertice(int v){
    int grau = 0;
    for(list<vertice>::iterator i = adj[v].begin(); i != adj[v].end(); i++){
        grau++;
    }
    return grau;
}

void Grafo::print_grafo(int v){
    for(int i = 0; i < v; i++){
        cout << i << ": ";
        vertices_adj(i);
        cout << endl;
    }
}

void Grafo::deleta_lista(){
    delete [] adj;
}
