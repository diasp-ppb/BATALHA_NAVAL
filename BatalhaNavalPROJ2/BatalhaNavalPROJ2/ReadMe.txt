Relativamente ao funcionamente geral do programa, atingimos todos os objetivos.
O programa inicia com um menu que tem 4 op��es:
 - Um modo de jogo para dois jogadores, que pede ao utilizador o nome de cada jogador e o respetivo ficheiro 
de configura��o e permite jogarem alternando os turnos.
 - Um modo de jogo contra o CPU, que pede ao utilizador o nome de cada jogador e o respetivo ficheiro 
de configura��o e permite jogar, fazendo o turno do CPU.
 - Um modo de visualiza��o do scoreboard.
 - Sair do jogo.

Foram tomadas precau��es relativas � entrada de dados em todos os momentos.

No caso de ser usado CTRL+Z, na escolha do ficheiro, control + z sai do programa, e em todas a outras 
situacoes, � tratada como entrada invalida e pede-se outra vez o input.

Foram implementadas duas formas de fazer o display (a funcao display e o overload do operador <<).

No caso de nao existir ficheiro ScoreBoard.txt, o utilizador e informado caso tente ver os scores pelo menu
e � criado um novo no caso de isso ser verificado depois do jogo.

Diogo Campos, up201403468, MIEIC 1� Ano, Turma 04 
Pedro Soares, up201404178, MIEIC 1� Ano, Turma 04
Grupo 03