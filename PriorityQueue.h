#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>
#include <climits>

using namespace std;

template<typename Tkey> // class template
class PriorityQueue {
public:
    // Construtor: recebe como entrada a capacidade inicial da fila de prioridades
    PriorityQueue( int capacity );

    // Construtor: recebe como entrada um vector e constroi
    // uma fila de prioridades com os elementos desse vector
    PriorityQueue(const vector<Tkey>& items );

    // Insere um novo elemento na fila de prioridades
    // Se a fila ficar cheia (atingir a capacidade), o vector usado como base
    // deve aumentar para o dobro da capacidade atual. Ou seja, essa fila de prioridades
    // eh redimensionavel.
    void push( const Tkey& newItem );

    // Acessa o elemento de maior prioridade (com o maior valor)
    // Se for chamado quando a fila estiver vazia, pode lancar uma excecao
    // ou entao abortar o programa (voce escolhe o que fazer neste caso)
    const Tkey& top() const;

    // remove o elemento de maior prioridade
    // Se for chamado quando a fila estiver vazia, pode lancar uma excecao
    // ou entao abortar o programa (voce escolhe o que fazer neste caso)
    void pop();

    // devolve o numero de elementos na fila de prioridade
    int size() const;

    // devolve 'true' se a fila de prioridades estiver vazia e 'false' caso contrario
    bool empty() const;

private:
    int currentSize; // numero de elementos na fila de prioridades
    std::vector<Tkey> vec; // vector que sera o heap maximo

    int parent(int i); // devolve o indice do pai do elemento na posicao vec[i]
    int left(int i); // devolve o indice do filho esquerdo do elemento vec[i]
    int right(int i); // devolve o indice do filho direito do elemento vec[i]
    void moveUp(int i); // move o elemento em vec[i] para cima ate obter um heap maximo
    void moveDown(int i); // move o elemento em vec[i] para baixo ate obter um heap maximo
    void buildMaxHeap(); // controi um heap maximo em tempo O(n)
};

template<typename Tkey>
PriorityQueue<Tkey>::PriorityQueue(int capacity){
    vec.resize(capacity);
    currentSize = 0;
}

template<typename Tkey>
PriorityQueue<Tkey>::PriorityQueue(const vector<Tkey> &items){
    currentSize = items.size();
    vec.resize(currentSize);
    for(int i = 0; i < items.size(); i++){
        vec[i] = items[i];
    }
    buildMaxHeap();
}

template<typename Tkey>
void PriorityQueue<Tkey>::push(const Tkey &newItem){
    if(currentSize == vec.size())
        vec.resize(currentSize*2);
    currentSize++;
    vec[currentSize-1] = newItem;
    moveUp(currentSize-1);
}

template<typename Tkey>
const Tkey &PriorityQueue<Tkey>::top() const {
    if(currentSize > 0)
        return vec[0];
    else
        return INT_MIN;
}

template<typename Tkey>
void PriorityQueue<Tkey>::pop(){
    if(currentSize == 0)
        return;
    vec[0] = vec[currentSize-1];
    currentSize--;
    moveDown(0);
}

template<typename Tkey>
int PriorityQueue<Tkey>::size() const {
    return currentSize;
}

template<typename Tkey>
bool PriorityQueue<Tkey>::empty() const {
    return (currentSize == 0);
}

template<typename Tkey>
int PriorityQueue<Tkey>::parent(int i){
    return (i/2);
}

template<typename Tkey>
int PriorityQueue<Tkey>::left(int i){
    return 2*i;
}

template<typename Tkey>
int PriorityQueue<Tkey>::right(int i){
    return 2*i+1;
}

template<typename Tkey>
void PriorityQueue<Tkey>::moveUp(int i){
    Tkey j = parent(i);
    if(j >= 0){
        if(vec[i] > vec[j]){
            auto aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
            moveUp(j);
        }
    }
}

template<typename Tkey>
void PriorityQueue<Tkey>::moveDown(int i){
    Tkey l = left(i);
    Tkey r = right(i);
    Tkey maior = i;
    if(l <= currentSize and vec[l] > vec[maior])
        maior = l;
    if(r <= currentSize and vec[r] > vec[maior])
        maior = r;
    if(maior != i){
        auto aux = vec[i];
        vec[i] = vec[maior];
        vec[maior] = aux;
        moveDown(maior);
    }
}

template<typename Tkey>
void PriorityQueue<Tkey>::buildMaxHeap(){
    currentSize = vec.size();
    for(int i = (currentSize/2); i >= 0; i--)
        moveDown(i);
}


#endif
