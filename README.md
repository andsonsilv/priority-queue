# Priority-Queue
[priority-queue] Implementando uma fila com prioridades

Imagine um conjunto S de números. Os elementos de S são às vezes chamados chaves ou prioridades (especialmente se há outros dados associados a cada elemento de S). Uma fila-com-prioridades (ou fila priorizada, ou priority queue) é um tipo abstrato de dados que permite executar as seguintes operações sobre S:

- encontrar um elemento máximo de S,
- extrair um elemento máximo de S,
- inserir um novo número em S,
- aumentar o valor de um elemento de S,
- diminuir o valor de um elemento de S.

Há uma variante dessa definição em que máximo é substituído por mínimo. Para distinguir uma variante da outra, diremos que a primeira é uma fila-com-prioridades decrescente (ou de máximo) e a segunda é uma fila-com-prioridades crescente (ou de mínimo).

Filas-com-prioridades (crescentes e descrescentes) têm um papel fundamental na implementação eficiente de diversos algoritmos célebres, como o algoritmo Heapsort, o algoritmo de Dijkstra, o algoritmo de Prim, e o algoritmo de Huffman.

Não é difícil imaginar maneiras de implementar uma fila-com-prioridades. Nas implementações mais óbvias, algumas das operações ficam rápidas mas as outras ficam lentas. O desafio é inventar uma implementação em que todas as operações sejam rápidas.

Neste caso, foi implementado uma fila com prioridades decrescente usando como estrutura de dados base um heap máximo. Template de classe também foi utilizado.

Testes encontram-se na pasta 'testes'.
