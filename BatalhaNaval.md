🛥️ Desafio Batalha Naval – Nível Novato
O Desafio Batalha Naval – Nível Novato é uma atividade introdutória de programação em linguagem C, criada para praticar o uso de vetores e matrizes bidimensionais.
O objetivo é representar um tabuleiro de Batalha Naval 10x10 com dois navios posicionados manualmente e exibir o resultado no console.

🎯 Objetivos do Desafio
Representar um tabuleiro 10x10 usando uma matriz bidimensional.

Posicionar dois navios no tabuleiro:

Um horizontalmente.

Outro verticalmente.

Exibir o tabuleiro completo no console:

0 representa água.

3 representa parte de um navio.

🧩 Funcionalidades Implementadas
O tabuleiro é inicializado com 0 em todas as posições.

Dois navios ocupam 3 posições cada no tabuleiro.

As posições iniciais dos navios são definidas diretamente no código.

O programa garante que:

Os navios ficam dentro dos limites do tabuleiro.

Não há sobreposição entre eles.

O resultado final é exibido de forma organizada e legível no console.

🖥️ Exemplo de Saída
text
=== TABULEIRO BATALHA NAVAL ===
0 = água | 3 = navio

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 3 3 3 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
🧠 Conceitos Trabalhados
Declaração e inicialização de matrizes.

Estruturas de repetição (for).

Manipulação de índices em arrays bidimensionais.

Impressão formatada no console com printf.

⚙️ Como Executar
Compile o código com:

text
gcc batalha_naval.c -o batalha
Execute o programa:

text
./batalha
💡 Estrutura do Código
Seção	Descrição
Declaração da matriz	Cria e inicializa o tabuleiro 10x10 com zeros
Posicionamento dos navios	Define coordenadas e preenche o tabuleiro com valor 3
Exibição	Mostra o tabuleiro completo no console
🧾 Requisitos
Linguagem: C

Bibliotecas: apenas stdio.h

Entrada: definida manualmente no código

Saída: exibição do tabuleiro completo no console

🚀 Próximos Passos
Após concluir o Nível Novato, os próximos níveis do desafio incluem:

Nível Aventureiro: tabuleiro expandido com posicionamentos diagonais.

Nível Mestre: habilidades especiais (cone, cruz e octaedro) utilizando padrões em matrizes.

👩‍💻 Autor
Desenvolvido como parte do projeto educacional MateCheck – Cursos-TI, voltado para o aprendizado prático de lógica e programação em C.