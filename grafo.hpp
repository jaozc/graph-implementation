#ifndef GRAFO_H
#define GRAFO_H

#include <list>

typedef struct vertice{
    int nome;
    int valor;
}vertice;

class Grafo 
{   
    
    private:
        int v;
        bool visitado;
        std::list<vertice> *adj;

    public:
        Grafo();
        void inicia_grafo(int v);
        void add_aresta(int v1_nome, int v1_valor, int v2_nome, int v2_valor);
        void remove_aresta(int v1, int v2);
        std::list<vertice> vertices_adj2(int v);
        void vertices_adj(int v);
        int grau_vertice(int v);
        void print_grafo(int v);
        void deleta_lista();
};

#endif