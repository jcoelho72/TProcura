@page teste_jogo_do_galo Procuras Adversas, Teste Jogo do Galo

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_adversas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Adversas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <a href="tutorial_adversaslit.html" style="color:#9cf;">📖 Literatura</a>
    <a href="tutorial_adversas5a.html" style="color:#9cf;">👓 Introdução</a>
    <a href="tutorial_adversas5b.html" style="color:#9cf;">👓 MiniMax</a>
    <a href="tutorial_adversas5c.html" style="color:#9cf;">👓 Monte Carlo</a>
    <a href="tutorial_galominimax.html" style="color:#9cf;">✏️ Galo MiniMax</a>
    <a href="tutorial_galoalfabeta.html" style="color:#9cf;">✏️ Galo alfa/beta</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">💻 Jogo do Galo</span>
    <a href="teste_jogo_em_linha.html" style="color:#9cf;">💻 Jogo em Linha</a>
  </div>
</div>


\endhtmlonly


Execução de exemplo com base no problema do Jogo do Galo.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraAdversa, e execute.
No Linux na pasta `.../TProcura/Adversa/Teste$` execute `make` seguido de `./bin/Release/TProcuraAdversa`

## Sumário

- [Ação 1 - Ver instâncias](#jdg-a1)
- [Ação 2 - Explorar sucessores](#jdg-a2)
- [Ação 3 - MiniMax](#jdg-a3)
- [Ação 4 - MiniMax com cortes Alfa/Beta](#jdg-a4)
- [Ação 5 - Explorar todo o espaço de estados](#jdg-a5)
- [Ação 6 - Testes Empíricos](#jdg-a6)


\htmlonly
<pre>
┌─ Teste TProcuraAdversa ──────┐
│ 1 - Jogo do Galo             │
│ 2 - Jogo Em Linha            │
└──────────────────────────────┘
Opção: <span class="entrada">1</span>
</pre>
\endhtmlonly

![Jogo do Galo - cada jogador joga numa casa na sua vez, ganha quem faz 3 em linha](docs/images/jdg.png)


\anchor jdg-a1
## Ação 1 - Ver instâncias

Vamos entrar no Jogo do Galo, insira: **1.**

\htmlonly
<pre>
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 . . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   <span style="color:gray">Instância</span>  │ 2 🔍  <span style="color:gray">Explorar</span> │ 3 ⚙   <span style="color:gray">Parâmetros</span>    │ 4 ✔  <span style="color:gray">Solução</span> │
│ 5 ⚖   <span style="color:gray">Indicadores</span> │ 6 ►   <span style="color:gray">Executar</span> │ 7 🛠️  <span style="color:gray">Configurações</span> │ 8 🧪  <span style="color:gray">Teste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly

Este é o estado vazio do tabuleiro do Jogo do Galo. Temos um tabuleiro de 3x3, 
e cada jogador ocupa uma casa livre na sua 
vez de jogar. O objetivo é colocar 3 marcas seguidas.

Este problema é um jogo, pelo que requer a procura adversa. 
Há no entanto muitos parâmetros comuns com as procuras construtivas
de agente único. Temos aqui como parâmetro base, a ordenação, que tem o valor 2. 
Este parâmetro permite que estados repetidos que já tenham sido analisados num nível igual ou superior ao requerido, 
possam ser reutilizados em vez de chamar novamente a procura. 
Esta é a opção equivalente a ignorar estados repetidos, que não deve ser ativada no âmbito das procuras adversas, já que
um movimento num dado estado tem de ser considerado, mesmo que tenha ocorrido em outro local.
Podemos é não recalcular tudo novamente para o estado repetido, guardando o resultado e nível de 
profundidade realizadas, para reutilizar assim que o estado seja analisado novamente.

Temos também a poda heurística, e poda cega, de modo a eliminar sucessores pelo seu 
valor heurístico, ou simplesmente de forma aleatória (cega). 
Estes parâmetros podem ser necessários em jogos cuja ramificação
seja muito elevada, não fazendo tanto sentido para situações de procura não adversa.

Em tudo o resto estamos em situação idêntica, embora os algoritmos sejam distintos. 
Temos por omissão o algoritmo MiniMax alfa/beta.

Insira: **1.** para inicialiar novo jogo.


\htmlonly
<pre>
Opção: <span class="entrada">1</span>
Jogo do Galo
...
  A B C
1 . . . 1 
2 . . . 2 
3 . . . 3 
  A B C
...
Opção: 
</pre>
\endhtmlonly

Podemos ver que há apenas uma instância, com o tabuleiro inicial. 
Podemos ver a borda do tabuleiro com indicação da coluna em letras, 
e linhas em números. Cada casa fica identificada de forma unívoca.


\anchor jdg-a2
## Ação 2 - Explorar sucessores

Vamos entrar na exploração manual. Insira: **2; a2; b2.**

\htmlonly
<pre>
Opção: <span class="entrada">2</span>
═╤═ 💰 g:0 ⚖  1|9|4 ═══
 │   A B C
 │ 1 . . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
 │ └─ ⚡  ──── a1 b1 c1 a2 b2 c2 a3 b3 c3
🔍 Sucessor [1-9, ação(ões), exe]: <span class="entrada">a2</span>
┌─ ✔  ────────────────
│ Executadas 1 ações. 
└─────────────────────
═╤═ 💰 g:0 ⚖  3|26|9 ═══
 │   A B C
 │ 1 . . . 1 
 │ 2 x . . 2 
 │ 3 . . . 3 
 │   A B C
 │ └─ ⚡  ──── a1 b1 c1 b2 c2 a3 b3 c3
🔍 Sucessor [1-8, ação(ões), exe]: <span class="entrada">b2</span>
┌─ ✔  ────────────────
│ Executadas 1 ações. 
└─────────────────────
═╤═ 💰 g:0 ⚖  5|41|13 ═══
 │   A B C
 │ 1 . . . 1 
 │ 2 x o . 2 
 │ 3 . . . 3 
 │   A B C
 │ └─ ⚡  ──── a1 b1 c1 c2 a3 b3 c3
🔍 Sucessor [1-7, ação(ões), exe]: 
</pre>
\endhtmlonly

A cada momento são mostradas as ações possíveis, correspondendo às casas livres para jogar.
Cada jogador deixa a sua marca à vez. Vamos verificar se o jogo deteta vitória.
Introduza: **a3 c1 a1.**


\htmlonly
<pre>
🔍 Sucessor [1-7, ação(ões), exe]: <span class="entrada">a3 c1 a1</span>
┌─ ✔  ────────────────
│ Executadas 3 ações. 
└─────────────────────
═╤═ 💰 g:0 🎯 h:-1000 ⚖  8|59|14 ═══
 │   A B C
 │ 1 x . o 1 
 │ 2 x o . 2 
 │ 3 x . . 3 
 │   A B C
 │ └─ ⚡  ────
┌─ ⛔  ───────────────
│ Sem sucessores.    
└────────────────────
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . o 1 
 │ 2 x o . 2 
 │ 3 x . . 3 
 │   A B C
...
Opção: 

</pre>
\endhtmlonly

O jogo terminou com sucesso, vitória X, pelo que não há mais sucessores.

O jogo tem 3 simetrias, vamos agora ver como fica esta exploração com a remoção de estados repetidos.
Insira: **3; 8; 3; *ENTER*; 1; 2.**

\htmlonly
<pre>
Opção: <span class="entrada">2</span>
═╤═ 💰 g:0 ⚖  1|3|4 ═══
 │   A B C
 │ 1 . . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
 │ └─ ⚡  ──── a1 b1 b2
🔍 Sucessor [1-3, ação(ões), exe]: 
</pre>
\endhtmlonly

Em vez das 9 possíveis ações, restam 3 ações, a1, b1 e b2. 
Todas as outras ações conduzem a estados que podem ser convertidos nestes, com uma ou mais de 3 simetrias:
horizontal, vertical, diagonal. Assim, não é necessário explorá-los. 

Insira: **2; *ENTER*.**

\htmlonly
<pre>
🔍 Sucessor [1-3, ação(ões), exe]: <span class="entrada">2</span>
┌─ ✔  ───────────────
│ Ação executada.    
└────────────────────
═╤═ 💰 g:0 ⚖  2|8|9 ═══
 │   A B C
 │ 1 . x . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
 │ └─ ⚡  ──── a1 a2 b2 a3 b3
🔍 Sucessor [1-5, ação(ões), exe]: <span class="entrada">↵</span>
</pre>
\endhtmlonly

Temos agora a1, mas não c1 (obtido por simetria vertical). Do mesmmo modo temos a2, mas não c2, e a3 mas não c3.
Já b2 e b3 não têm estados simétricos. 

Assim, reduzimos consideravelmente a ramificação inicial, bem como os estados existentes no geral.

No entanto, tal como referido na ação 1, não podemos ignorar repetidos, 
já que podemos estar a eliminar alternativas importantes
num estado, apenas porque ocorrem em outro. 
Mas com este teste podemos ver a importância das simetrias.

O parâmetro de estados repetidos deve ficar nas procuras adversas em igonrar, e o de ordenação em 2.

Note que se quisermos jogar contra o computador, 
podemos utilizar a ação "exe" para que o computador jogue com o algoritmo atual.


\anchor jdg-a3
## Ação 3 - MiniMax

Vamos começar por ver o MiniMax neste formato, ignorando estados repetidos, 
com informação de debug completa, vendo todos os estados, e nível de profundidade 2,
e com P12(Ordenar)=0.
Insira: **1; 3; 1; 1; 2; 4; 6; 1; 7; 2; 8; 1; 12; 0; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├□═╤═ 💰 g:0  ═══
 │   A B C
 │ 1 . . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|9 ═══ ⚡ a1
 │  │   A B C
 │  │ 1 x . . 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■ 0
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  1|9|1 ═══ ⚡ b1
 │  │   A B C
 │  │ 1 . x . 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 3 💰 g:1 ⚖  1|9|2 ═══ ⚡ c1
 │  │   A B C
 │  │ 1 . . x 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 4 💰 g:1 ⚖  1|9|3 ═══ ⚡ a2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 x . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 5 💰 g:1 ⚖  1|9|4 ═══ ⚡ b2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . x . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 6 💰 g:1 ⚖  1|9|5 ═══ ⚡ c2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . x 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 7 💰 g:1 ⚖  1|9|6 ═══ ⚡ a3
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . . 2 
 │  │ 3 x . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 8 💰 g:1 ⚖  1|9|7 ═══ ⚡ b3
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . . 2 
 │  │ 3 . x . 3 
 │  │   A B C
 │  │ 🍃 0
 │  └■═╤═ 🔖 9 💰 g:1 ⚖  1|9|8 ═══ ⚡ c3
 │      A B C
 │    1 . . . 1 
 │    2 . . . 2 
 │    3 . . x 3 
 │      A B C
 │    🍃 0
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>2 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱    ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 2 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 0 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 9 | <span style="color:gray">I4(IND_EXPANSOES):</span> 1 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 9 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos ver a árvore de procura, que há 9 estados gerados, embora apenas 3 sejam distintos
a menos das 3 simetrias. 

A heurística neste problema é a deteção de estado final, pelo que vemos 0 como valor de cada ramo final. 

Vamos agora colocar P14(Ordenar): 2, e repetir a procura. Insira: **1; 3; 12; 2; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├□═╤═ 💰 g:0  ═══
 │   A B C
 │ 1 . . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|9 ═══ ⚡ a1
 │  │   A B C
 │  │ 1 x . . 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■ 0
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  1|9 ═══ ⚡ b1
 │  │   A B C
 │  │ 1 . x . 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 3 💰 g:1 ⚖  1|9 ═══ ⚡ c1
 │  │   A B C
 │  │ 1 . . x 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 4 💰 g:1 ⚖  1|9 ═══ ⚡ a2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 x . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 5 💰 g:1 ⚖  1|9 ═══ ⚡ b2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . x . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 🍃 0
 │  ├■═╤═ 🔖 6 💰 g:1 ⚖  1|9 ═══ ⚡ c2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . x 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 7 💰 g:1 ⚖  1|9 ═══ ⚡ a3
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . . 2 
 │  │ 3 x . . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 8 💰 g:1 ⚖  1|9 ═══ ⚡ b3
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . . 2 
 │  │ 3 . x . 3 
 │  │   A B C
 │  │ 💾 0
 │  └■═╤═ 🔖 9 💰 g:1 ⚖  1|9 ═══ ⚡ c3
 │      A B C
 │    1 . . . 1 
 │    2 . . . 2 
 │    3 . . x 3 
 │      A B C
 │    💾 0 HT: reutilização 3.00 vezes 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>2 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   3ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 2 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 3 | <span style="color:gray">I3(Iterações):</span> 0 | <span style="color:gray">I4(IND_EXPANSOES):</span> 1 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 9 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

A procura foi realizada, existindo agora apenas 3 avaliações, já que apenas 3 estados novos foram gerados. 
Outros estados foram gerados, mas são iguais a menos de operações de simetria.

Na árvore de procura esses estados não desaparecem, mas a árvore é podada.
Se o estado já foi analisado nesse nível (ou com mais profundidade), reutiliza-se o valor em vez de expandir o estado.
Assim aparecem na árvore como o ícon da disquete (`💾`), tendo o seu valor sido obtido da memória.

Vamos continuar, mas reduzindo o nível de debug para detalhe, e ver ações para 4, e aumentando o nível da procura para 3. 
Insira: **3; 2; 3; 7; 3; 6; 4; *ENTER*; 6.**  

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══
 │  ├□═╤═ 🔖 8 💰 g:1 ⚖  1|8|5 ═══ ⚡ c3
 │  │  ├■═╤═ 🔖 9 💰 g:2 ⚖  2|15|5 ═══ ⚡ b1
 │  │  │   A B C
 │  │  │ 1 x x . 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■ 0
 │  │  ├■═╤═ 🔖 10 💰 g:2 ⚖  2|15|6 ═══ ⚡ c1
 │  │  │   A B C
 │  │  │ 1 x . x 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 11 💰 g:2 ⚖  2|15|7 ═══ ⚡ a2 ─── 💾 0
 │  │  ├■═╤═ 🔖 12 💰 g:2 ⚖  2|15|7 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . x . 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 13 💰 g:2 ⚖  2|15|8 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . . x 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 14 💰 g:2 ⚖  2|15|9 ═══ ⚡ a3 ─── 💾 0
 │  │  └■═╤═ 🔖 15 💰 g:2 ⚖  2|15|9 ═══ ⚡ b3 ─── 💾 0
 │  ├□ 0
 │  ├□═╤═ 🔖 7 💰 g:1 ⚖  2|15|9 ═══ ⚡ b3
 │  │  ├■═╤═ 🔖 16 💰 g:2 ⚖  3|22|9 ═══ ⚡ b1
 │  │  │   A B C
 │  │  │ 1 x x . 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . o . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■ 0
 │  │  ├■═╤═ 🔖 17 💰 g:2 ⚖  3|22|10 ═══ ⚡ c1
 │  │  │   A B C
 │  │  │ 1 x . x 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . o . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 18 💰 g:2 ⚖  3|22|11 ═══ ⚡ a2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 x . . 2 
 │  │  │ 3 . o . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 19 💰 g:2 ⚖  3|22|12 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . x . 2 
 │  │  │ 3 . o . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 20 💰 g:2 ⚖  3|22|13 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . . x 2 
 │  │  │ 3 . o . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 21 💰 g:2 ⚖  3|22|14 ═══ ⚡ a3
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 x o . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  └■═╤═ 🔖 22 💰 g:2 ⚖  3|22|15 ═══ ⚡ c3
 │  │      A B C
 │  │    1 x . . 1 
 │  │    2 . . . 2 
 │  │    3 . o x 3 
 │  │      A B C ─── 🍃 0
 │  ├□═╤═ 🔖 2 💰 g:1 ⚖  3|22|16 ═══ ⚡ c1
 │  │  ├■═╤═ 🔖 23 💰 g:2 ⚖  4|29|16 ═══ ⚡ b1
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■ 0
 │  │  ├■═╤═ 🔖 24 💰 g:2 ⚖  4|29|17 ═══ ⚡ a2
 │  │  │   A B C
 │  │  │ 1 x . o 1 
 │  │  │ 2 x . . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 25 💰 g:2 ⚖  4|29|18 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x . o 1 
 │  │  │ 2 . x . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 26 💰 g:2 ⚖  4|29|19 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x . o 1 
 │  │  │ 2 . . x 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 27 💰 g:2 ⚖  4|29|20 ═══ ⚡ a3 ─── 💾 0
 │  │  ├■═╤═ 🔖 28 💰 g:2 ⚖  4|29|20 ═══ ⚡ b3
 │  │  │   A B C
 │  │  │ 1 x . o 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . x . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  └■═╤═ 🔖 29 💰 g:2 ⚖  4|29|21 ═══ ⚡ c3
 │  │      A B C
 │  │    1 x . o 1 
 │  │    2 . . . 2 
 │  │    3 . . x 3 
 │  │      A B C ─── 🍃 0
 │  ├□═╤═ 🔖 3 💰 g:1 ⚖  4|29|22 ═══ ⚡ a2
 │  │  ├■═╤═ 🔖 30 💰 g:2 ⚖  5|36|22 ═══ ⚡ b1
 │  │  │   A B C
 │  │  │ 1 x x . 1 
 │  │  │ 2 o . . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■ 0
 │  │  ├■═╤═ 🔖 31 💰 g:2 ⚖  5|36|23 ═══ ⚡ c1 ─── 💾 0
 │  │  ├■═╤═ 🔖 32 💰 g:2 ⚖  5|36|23 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 o x . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 33 💰 g:2 ⚖  5|36|24 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 o . x 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 34 💰 g:2 ⚖  5|36|25 ═══ ⚡ a3
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 o . . 2 
 │  │  │ 3 x . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 35 💰 g:2 ⚖  5|36|26 ═══ ⚡ b3
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 o . . 2 
 │  │  │ 3 . x . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  └■═╤═ 🔖 36 💰 g:2 ⚖  5|36|27 ═══ ⚡ c3
 │  │      A B C
 │  │    1 x . . 1 
 │  │    2 o . . 2 
 │  │    3 . . x 3 
 │  │      A B C ─── 🍃 0
 │  ├□═╤═ 🔖 4 💰 g:1 ⚖  5|36|28 ═══ ⚡ b2
 │  │  ├■═╤═ 🔖 37 💰 g:2 ⚖  6|43|28 ═══ ⚡ b1
 │  │  │   A B C
 │  │  │ 1 x x . 1 
 │  │  │ 2 . o . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■ 0
 │  │  ├■═╤═ 🔖 38 💰 g:2 ⚖  6|43|29 ═══ ⚡ c1
 │  │  │   A B C
 │  │  │ 1 x . x 1 
 │  │  │ 2 . o . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 39 💰 g:2 ⚖  6|43|30 ═══ ⚡ a2 ─── 💾 0
 │  │  ├■═╤═ 🔖 40 💰 g:2 ⚖  6|43|30 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . o x 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C ─── 🍃 0
 │  │  ├■═╤═ 🔖 41 💰 g:2 ⚖  6|43|31 ═══ ⚡ a3 ─── 💾 0
 │  │  ├■═╤═ 🔖 42 💰 g:2 ⚖  6|43|31 ═══ ⚡ b3 ─── 💾 0
 │  │  └■═╤═ 🔖 43 💰 g:2 ⚖  6|43|31 ═══ ⚡ c3
 │  │      A B C
 │  │    1 x . . 1 
 │  │    2 . o . 2 
 │  │    3 . . x 3 
 │  │      A B C ─── 🍃 0
 │  ├□═╤═ 🔖 5 💰 g:1 ⚖  6|43|32 ═══ ⚡ c2 ─── 💾 0
 │  ├□═╤═ 🔖 6 💰 g:1 ⚖  6|43|32 ═══ ⚡ a3 ─── 💾 0
 │  └□═╤═ 🔖 1 💰 g:1 ⚖  6|43|32 ═══ ⚡ b1 ─── 💾 0 HT: reutilização 0.58 vezes 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>3 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>3 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   4ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> DETALHE | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 3 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . o 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 4 | <span style="color:gray">I3(Iterações):</span> 32 | <span style="color:gray">I4(IND_EXPANSOES):</span> 6 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 43 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

No nível de detalhe vemos os estados folha, mas não os estados intermédios.

Continuamos com avaliações todas com heurística nula, pelo que para o algoritmo é indiferente qualquer opção.
Podemos ver que as disquetes aparecem, o que significa que poupam ramos da árvore.
Por exemplo, a ação a2 não foi explorada no estado 11,
porque a ação b1 conduz ao mesmo estado e já tinha sido explorada no estado 9.

Vamos agora executar mais algumas jogadas, e ver a execução final com debug a 4. 

Insira: **6; 6; 3; 2; 4; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├□═╤═ 💰 g:0  ═══
 │   A B C
 │ 1 x x o 1 
 │ 2 . . . 2 
 │ 3 . . o 3 
 │   A B C
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|5|5 ═══ ⚡ a2
 │  │   A B C
 │  │ 1 x x o 1 
 │  │ 2 x . . 2 
 │  │ 3 . . o 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 6 💰 g:2 ⚖  2|9|5 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 x o . 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0
 │  │  ├□═╤═ 🔖 7 💰 g:2 ⚖  2|9|6 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 x . o 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C
 │  │  │ 🍃 998
 │  │  ├□ 998
 │  │  └─ ☗ 1 { 🔖 8 🔖 9 } 
 │  ├■ 998
 │  ├■═╤═ 🔖 4 💰 g:1 ⚖  2|9|7 ═══ ⚡ a3
 │  │   A B C
 │  │ 1 x x o 1 
 │  │ 2 . . . 2 
 │  │ 3 x . o 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 10 💰 g:2 ⚖  3|13|7 ═══ ⚡ a2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 o . . 2 
 │  │  │ 3 x . o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0
 │  │  ├□═╤═ 🔖 11 💰 g:2 ⚖  3|13|8 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 . o . 2 
 │  │  │ 3 x . o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□═╤═ 🔖 12 💰 g:2 ⚖  3|13|9 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 . . o 2 
 │  │  │ 3 x . o 3 
 │  │  │   A B C
 │  │  │ 🍃 998
 │  │  ├□ 998
 │  │  └─ ☗ 1 { 🔖 13 } 
 │  ├■═╤═ 🔖 3 💰 g:1 ⚖  3|13|10 ═══ ⚡ c2
 │  │   A B C
 │  │ 1 x x o 1 
 │  │ 2 . . x 2 
 │  │ 3 . . o 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 14 💰 g:2 ⚖  4|17|10 ═══ ⚡ a2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 o . x 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0
 │  │  ├□═╤═ 🔖 15 💰 g:2 ⚖  4|17|11 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 . o x 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□═╤═ 🔖 16 💰 g:2 ⚖  4|17|12 ═══ ⚡ a3
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 . . x 2 
 │  │  │ 3 o . o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  └□═╤═ 🔖 17 💰 g:2 ⚖  4|17|13 ═══ ⚡ b3
 │  │      A B C
 │  │    1 x x o 1 
 │  │    2 . . x 2 
 │  │    3 . o o 3 
 │  │      A B C
 │  │    🍃 0
 │  ├■ 0
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  4|17|14 ═══ ⚡ b2
 │  │   A B C
 │  │ 1 x x o 1 
 │  │ 2 . x . 2 
 │  │ 3 . . o 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 18 💰 g:2 ⚖  5|21|14 ═══ ⚡ a2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 o x . 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0
 │  │  ├□═╤═ 🔖 19 💰 g:2 ⚖  5|21|15 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 . x o 2 
 │  │  │ 3 . . o 3 
 │  │  │   A B C
 │  │  │ 🍃 998
 │  │  ├□ 998
 │  │  └─ ☗ 1 { 🔖 20 🔖 21 } 
 │  └■═╤═ 🔖 5 💰 g:1 ⚖  5|21|16 ═══ ⚡ b3
 │      A B C
 │    1 x x o 1 
 │    2 . . . 2 
 │    3 . x o 3 
 │      A B C
 │     ├□═╤═ 🔖 22 💰 g:2 ⚖  6|25|16 ═══ ⚡ a2
 │     │   A B C
 │     │ 1 x x o 1 
 │     │ 2 o . . 2 
 │     │ 3 . x o 3 
 │     │   A B C
 │     │ 🍃 0
 │     ├□ 0
 │     ├□═╤═ 🔖 23 💰 g:2 ⚖  6|25|17 ═══ ⚡ b2
 │     │   A B C
 │     │ 1 x x o 1 
 │     │ 2 . o . 2 
 │     │ 3 . x o 3 
 │     │   A B C
 │     │ 🍃 0
 │     ├□═╤═ 🔖 24 💰 g:2 ⚖  6|25|18 ═══ ⚡ c2
 │     │   A B C
 │     │ 1 x x o 1 
 │     │ 2 . . o 2 
 │     │ 3 . x o 3 
 │     │   A B C
 │     │ 🍃 998
 │     ├□ 998
 │     └─ ☗ 1 { 🔖 25 }  HT: reutilização 0.25 vezes 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>3 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   5ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 3 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x x o 1 
 │ 2 . . x 2 
 │ 3 . . o 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 5 | <span style="color:gray">I3(Iterações):</span> 19 | <span style="color:gray">I4(IND_EXPANSOES):</span> 6 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 25 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos ver que a árvore de procura já interseta posições em que há vitória de O, sendo o valor de +infinito
(`🍃 998`). 
O infinito é por omissão 1000. O X é o primeiro a jogar, e em SolucaoVazia() é indicado que o 
primeiro a jogar procura minimizar o jogo.
O valor dos estados em que O ganha é 998 e não 1000. 
Ao valor do infinito é subtraído o número de jogadas desde a jogada atual.
Esta ação tem o efeito de uma derrota de X que seja mais uma jogada, tenha valor inferior a 998. 
Como O pretende maximizar, prefere sempre as vitórias mais curtas, tal como o X, 
e ambos preferem as derrotas mais longas.

Após um valor destes ser identificado, existe um ícon com uma indicação de vitória/derrota a determinado número de jogadas
(`☗ 1 { 🔖 8 🔖 9 }`).
Os sucessores que ainda faltavam analisar são cortados, atendendo a que o jogador com a vez já ganhou neste ramo.

Notar ainda para a frase final: "HT: reutilização 0.25 vezes". 
Após terminar a execução a hashtable é limpa, e
é verificado nessa altura quantas vezes em média,
um estado guardado foi reutilizado, 
poupando assim uma execução do algoritmo para esse estado.


\anchor jdg-a4
## Ação 4 - MiniMax com cortes Alfa/Beta

Vamos agora ver como se comporta a procura da ação anterior, se ativarmos os cortes alfa/beta.
Insira: **1; 3; 1; 2; 2; 4; 6; 1; 7; 3; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├□═╤═ 💰 g:0  ═══ α=-1000 β=1000 ═══
 │   A B C
 │ 1 . . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|9|3 ═══ α=-1000 β=1000 ═══ ⚡ a1
 │  │   A B C
 │  │ 1 x . . 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 10 💰 g:2 ⚖  2|17|3 ═══ α=-1000 β=1000 ═══ ⚡ b1
 │  │  │   A B C
 │  │  │ 1 x o . 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0 → α
 │  │  ├□═╤═ 🔖 11 💰 g:2 ⚖  2|17|4 ═══ α=0 β=1000 ═══ ⚡ c1
 │  │  │   A B C
 │  │  │ 1 x . o 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□═╤═ 🔖 12 💰 g:2 ⚖  2|17|5 ═══ α=0 β=1000 ═══ ⚡ a2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 o . . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C
 │  │  │ 💾 0
 │  │  ├□═╤═ 🔖 13 💰 g:2 ⚖  2|17|5 ═══ α=0 β=1000 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . o . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□═╤═ 🔖 14 💰 g:2 ⚖  2|17|6 ═══ α=0 β=1000 ═══ ⚡ c2
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . . o 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□═╤═ 🔖 15 💰 g:2 ⚖  2|17|7 ═══ α=0 β=1000 ═══ ⚡ a3
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 o . . 3 
 │  │  │   A B C
 │  │  │ 💾 0
 │  │  ├□═╤═ 🔖 16 💰 g:2 ⚖  2|17|7 ═══ α=0 β=1000 ═══ ⚡ b3
 │  │  │   A B C
 │  │  │ 1 x . . 1 
 │  │  │ 2 . . . 2 
 │  │  │ 3 . o . 3 
 │  │  │   A B C
 │  │  │ 💾 0
 │  │  └□═╤═ 🔖 17 💰 g:2 ⚖  2|17|7 ═══ α=0 β=1000 ═══ ⚡ c3
 │  │      A B C
 │  │    1 x . . 1 
 │  │    2 . . . 2 
 │  │    3 . . o 3 
 │  │      A B C
 │  │    🍃 0
 │  ├■ 0 → β
 │  ├■═╤═ 🔖 7 💰 g:1 ⚖  2|17|8 ═══ α=-1000 β=0 ═══ ⚡ a3
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . . 2 
 │  │ 3 x . . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 6 💰 g:1 ⚖  2|17|8 ═══ α=-1000 β=0 ═══ ⚡ c2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . x 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 18 💰 g:2 ⚖  3|25|8 ═══ α=-1000 β=0 ═══ ⚡ a1
 │  │  │   A B C
 │  │  │ 1 o . . 1 
 │  │  │ 2 . . x 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0
 │  │  └─🪓 β(0) { 🔖 19 🔖 20 🔖 21 🔖 22 🔖 23 🔖 24 🔖 25 } 
 │  ├■═╤═ 🔖 8 💰 g:1 ⚖  3|25|9 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . . . 2 
 │  │ 3 . x . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 5 💰 g:1 ⚖  3|25|9 ═══ α=-1000 β=0 ═══ ⚡ b2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 . x . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 26 💰 g:2 ⚖  4|33|9 ═══ α=-1000 β=0 ═══ ⚡ a1
 │  │  │   A B C
 │  │  │ 1 o . . 1 
 │  │  │ 2 . x . 2 
 │  │  │ 3 . . . 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0
 │  │  └─🪓 β(0) { 🔖 27 🔖 28 🔖 29 🔖 30 🔖 31 🔖 32 🔖 33 } 
 │  ├■═╤═ 🔖 3 💰 g:1 ⚖  4|33|10 ═══ α=-1000 β=0 ═══ ⚡ c1
 │  │   A B C
 │  │ 1 . . x 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  4|33|10 ═══ α=-1000 β=0 ═══ ⚡ b1
 │  │   A B C
 │  │ 1 . x . 1 
 │  │ 2 . . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 💾 0
 │  ├■═╤═ 🔖 4 💰 g:1 ⚖  4|33|10 ═══ α=-1000 β=0 ═══ ⚡ a2
 │  │   A B C
 │  │ 1 . . . 1 
 │  │ 2 x . . 2 
 │  │ 3 . . . 3 
 │  │   A B C
 │  │ 💾 0
 │  └■═╤═ 🔖 9 💰 g:1 ⚖  4|33|10 ═══ α=-1000 β=0 ═══ ⚡ c3
 │      A B C
 │    1 . . . 1 
 │    2 . . . 2 
 │    3 . . x 3 
 │      A B C
 │    💾 0 HT: reutilização 1.64 vezes 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>3 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   4ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 3
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 4 | <span style="color:gray">I3(Iterações):</span> 10 | <span style="color:gray">I4(IND_EXPANSOES):</span> 4 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 33 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Temos na procura dois cortes beta. Vamos ver com atenção:
- o primeiro ramo, estado 1, com X em a1 foi explorado por completo
- no entanto, mesmo nesse ramo houve estados obtidos por memória (`💾`), os com simetria em diagonal (12, 15, 16)
- logo após a primeira avaliação aparece `├□ 0 → α`. Significa que alfa, que tinha o valor -1000, fica atualizado com o valor 0
- no final desse ramo aparece `├■ 0 → β`. Significa que beta (que minimiza) tem uma alternativa explorada (o estado 1) que garante pelo menos 0.
- o estado 7 é igual ao estado 1, foi obtido por memória
- O estado 6, o ramo com X em c2, vamos dar a um estado de valor 0 (estado 18). Assim, para c2, temos o adversário que pode obter 0, mas para isso X vai para o ramo anterior e obtém 0, pelo que este ramo pode ser cortado
- Notar no corte do estado: `└─🪓 β(0) { 🔖19 🔖20 🔖21 🔖22 🔖23 🔖24 🔖25 }`. Houve com este corte vários estados que nem chegam a ser analisados
- O estado 8 com X em b3 é obtido por memória, igual ao estado 6
- o estado 5 com X em b2 é o único que falta explorar, e ocorre exatamente o mesmo que no estado 6, após se explorar um ramo, sabe-se que o adversário pode obter 0, pelo que não mais interessa.
- assim, apenas o ramo do estado 1 é que foi explorado completamente

Como resultado dos cortes, temos menos avaliações. No entanto, no caso da avaliação ser obtida através de corte, é registado que o valor é
um valor máximo ou mínimo, mas não exato. Por vezes não pode ser utilizado devido ao corte. Assim, poderá por vezes
ser compensador não ter o alfa/beta para memorizar os valores exatos. De um modo geral, se a ramificação é alta,
deverá ser sempre vantajoso ter os cortes alfa/beta, se a ramificação é baixa, pode ser compensador
não ter o alfa/beta de modo a que fiquem memorizados estado com o valor exato.

Vamos avaçar para o momento em que há estados finais visiveis.
Insira: **6; 6; 6; 6; 6; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├□═╤═ 💰 g:0  ═══ α=-1000 β=1000 ═══
 │   A B C
 │ 1 x x o 1 
 │ 2 . . x 2 
 │ 3 . o o 3 
 │   A B C
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|3|3 ═══ α=-1000 β=1000 ═══ ⚡ a2
 │  │   A B C
 │  │ 1 x x o 1 
 │  │ 2 x . x 2 
 │  │ 3 . o o 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 4 💰 g:2 ⚖  2|5|3 ═══ α=-1000 β=1000 ═══ ⚡ b2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 x o x 2 
 │  │  │ 3 . o o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0 → α
 │  │  └□═╤═ 🔖 5 💰 g:2 ⚖  2|5|4 ═══ α=0 β=1000 ═══ ⚡ a3
 │  │      A B C
 │  │    1 x x o 1 
 │  │    2 x . x 2 
 │  │    3 o o o 3 
 │  │      A B C
 │  │    🍃 998
 │  │  ├□ 998
 │  ├■ 998 → β
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  2|5|5 ═══ α=-1000 β=998 ═══ ⚡ b2
 │  │   A B C
 │  │ 1 x x o 1 
 │  │ 2 . x x 2 
 │  │ 3 . o o 3 
 │  │   A B C
 │  │  ├□═╤═ 🔖 6 💰 g:2 ⚖  3|7|5 ═══ α=-1000 β=998 ═══ ⚡ a2
 │  │  │   A B C
 │  │  │ 1 x x o 1 
 │  │  │ 2 o x x 2 
 │  │  │ 3 . o o 3 
 │  │  │   A B C
 │  │  │ 🍃 0
 │  │  ├□ 0 → α
 │  │  └□═╤═ 🔖 7 💰 g:2 ⚖  3|7|6 ═══ α=0 β=998 ═══ ⚡ a3
 │  │      A B C
 │  │    1 x x o 1 
 │  │    2 . x x 2 
 │  │    3 o o o 3 
 │  │      A B C
 │  │    🍃 998
 │  │  ├□ 998
 │  └■═╤═ 🔖 3 💰 g:1 ⚖  3|7|7 ═══ α=-1000 β=998 ═══ ⚡ a3
 │      A B C
 │    1 x x o 1 
 │    2 . . x 2 
 │    3 x o o 3 
 │      A B C
 │     ├□═╤═ 🔖 8 💰 g:2 ⚖  4|9|7 ═══ α=-1000 β=998 ═══ ⚡ a2
 │     │   A B C
 │     │ 1 x x o 1 
 │     │ 2 o . x 2 
 │     │ 3 x o o 3 
 │     │   A B C
 │     │ 🍃 0
 │     ├□ 0 → α
 │     └□═╤═ 🔖 9 💰 g:2 ⚖  4|9|8 ═══ α=0 β=998 ═══ ⚡ b2
 │         A B C
 │       1 x x o 1 
 │       2 . o x 2 
 │       3 x o o 3 
 │         A B C
 │       🍃 0
 │  ├■ 0 HT: reutilização 0.30 vezes 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>3 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   3ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 3
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x x o 1 
 │ 2 . . x 2 
 │ 3 x o o 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 3 | <span style="color:gray">I3(Iterações):</span> 9 | <span style="color:gray">I4(IND_EXPANSOES):</span> 4 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 9 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Neste caso não tivemos um corte alfa/beta, dado que o melhor ramo foi expandido no final.

Assim, na procura iterativa é importante ordenar os estados por ordem de valor, de modo a que os melhores estados sejam analisados primeiro
e possam potenciar o número de cortes. 

Naturalmente que estes cortes tornam-se mais significativos em árvores de procura maiores.

\anchor jdg-a5
## Ação 5 - Explorar todo o espaço de estados

Vamos agora procurar explorar todo o espaço de estados, o que é possível apenas porque este jogo tem dimensões reduzidas.
Para que a hashtable não poupe demasiados estados, vamos nesta ação arrancar com o programa em cada teste.

Vamos começar com o MiniMax, sem a ordenação. Vamos colocar o limite a 20, para não interferir
Após reiniciar, insira: **1; 3; 1; 1; 7; 20; 12; 0; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>0 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>20 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   139ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 20 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 0 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 139 | <span style="color:gray">I3(Iterações):</span> 113416 | <span style="color:gray">I4(IND_EXPANSOES):</span> 155758 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 318517 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos ver que há 318517 estados gerados, um valor reduzido para os tempos atuais.
O resultado do jogo é um empate.

Vamos agora ver o efeito da ordenação. 
Após arrancar, insira:  **1; 3; 1; 1; 7; 20; 12; 2; *ENTER*; 6.**


\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>0 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>20 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   23ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 20 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 23 | <span style="color:gray">I3(Iterações):</span> 826 | <span style="color:gray">I4(IND_EXPANSOES):</span> 624 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 2299 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

O número de estados gerados é consideravelmente inferior, ficando em apenas 2299 estados.

Vamos agora procurar ver o impacto dos cortes alfa/beta, na versão sem ordenação.
Após arrancar, insira:  **1; 3; 1; 2; 7; 20; 12; 0; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>0 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>20 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   11ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 20
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 0
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 11 | <span style="color:gray">I3(Iterações):</span> 7848 | <span style="color:gray">I4(IND_EXPANSOES):</span> 11750 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 27362 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

O número de estados gerados é de 27362, em vez de 318517 para o MiniMax sem cortes alfa/beta.
Podemos observar um grande ganho. Vamos agora ver qual o resultado do alfa/beta com ordenação.
Após arrancar, insira:  **1; 3; 1; 2; 7; 20; 12; 2; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>0 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>20 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   20ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 20
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 20 | <span style="color:gray">I3(Iterações):</span> 700 | <span style="color:gray">I4(IND_EXPANSOES):</span> 425 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 1465 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Os estados gerados ficam em 1465, contra 2299 sem cortes alfa/beta, cerca de metade. 
Em termos de avaliações temos 700, enquanto sem cortes alfa/beta temos 826.

Com o nível de debug a 2, podemos ver toda a árvore, com uma linha por cada estado expandido.
Após arrancar insira:  **1; 3; 1; 2; 2; 2; 7; 20; 12; 2; *ENTER*; 6.**

<details>
  <summary>Ver árvore completa do Jogo do Galo (com cortes alfa/beta)</summary>

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├□═╤═ 💰 g:0  ═══ α=-1000 β=1000 ═══
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|9|3 ═══ α=-1000 β=1000 ═══ ⚡ a1
 │  │  ├□═╤═ 🔖 17 💰 g:2 ⚖  2|17|8 ═══ α=-1000 β=1000 ═══ ⚡ c3
 │  │  │  ├■═╤═ 🔖 18 💰 g:3 ⚖  3|24|12 ═══ α=-1000 β=1000 ═══ ⚡ b1
 │  │  │  │  ├□═╤═ 🔖 30 💰 g:4 ⚖  4|30|18 ═══ α=-1000 β=1000 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 31 💰 g:5 🎯 h:-1000 ⚖  5|35|23 ═══ α=-1000 β=1000 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 34 🔖 33 🔖 32 🔖 35 } 
 │  │  │  │  ├□ -995 → α
 │  │  │  │  ├□═╤═ 🔖 29 💰 g:4 ⚖  5|35|23 ═══ α=-995 β=1000 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 36 💰 g:5 🎯 h:-1000 ⚖  6|40|28 ═══ α=-995 β=1000 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 39 🔖 38 🔖 37 🔖 40 } 
 │  │  │  │  ├□═╤═ 🔖 26 💰 g:4 ⚖  6|40|28 ═══ α=-995 β=1000 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 41 💰 g:5 🎯 h:-1000 ⚖  7|45|33 ═══ α=-995 β=1000 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 44 🔖 43 🔖 42 🔖 45 } 
 │  │  │  │  ├□═╤═ 🔖 27 💰 g:4 ⚖  7|45|33 ═══ α=-995 β=1000 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 46 💰 g:5 🎯 h:-1000 ⚖  8|50|38 ═══ α=-995 β=1000 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 49 🔖 48 🔖 47 🔖 50 } 
 │  │  │  │  ├□═╤═ 🔖 28 💰 g:4 ⚖  8|50|38 ═══ α=-995 β=1000 ═══ ⚡ c2
 │  │  │  │  │  ├■═╤═ 🔖 51 💰 g:5 🎯 h:-1000 ⚖  9|55|42 ═══ α=-995 β=1000 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 54 🔖 53 🔖 52 🔖 55 } 
 │  │  │  │  └□═╤═ 🔖 25 💰 g:4 ⚖  9|55|42 ═══ α=-995 β=1000 ═══ ⚡ c1
 │  │  │  │     ├■═╤═ 🔖 56 💰 g:5 ⚖  10|60|46 ═══ α=-995 β=1000 ═══ ⚡ a2
 │  │  │  │     │  ├□═╤═ 🔖 62 💰 g:6 🎯 h:1000 ⚖  11|64|50 ═══ α=-995 β=1000 ═══ ⚡ c2 ─── 🍃 994
 │  │  │  │     │  ├□ 994 ─── ☗ 5 { 🔖 63 🔖 64 🔖 61 } 
 │  │  │  │     ├■ 994 → β
 │  │  │  │     ├■═╤═ 🔖 59 💰 g:5 ⚖  11|64|50 ═══ α=-995 β=994 ═══ ⚡ a3
 │  │  │  │     │  ├□═╤═ 🔖 67 💰 g:6 🎯 h:1000 ⚖  12|68|54 ═══ α=-995 β=994 ═══ ⚡ c2 ─── 🍃 994
 │  │  │  │     │  ├□ 994 ─── ☗ 5 { 🔖 68 🔖 66 🔖 65 } 
 │  │  │  │     ├■═╤═ 🔖 58 💰 g:5 ⚖  12|68|54 ═══ α=-995 β=994 ═══ ⚡ c2
 │  │  │  │     │  ├□═╤═ 🔖 72 💰 g:6 ⚖  13|72|58 ═══ α=-995 β=994 ═══ ⚡ b3
 │  │  │  │     │  │  ├■═╤═ 🔖 73 💰 g:7 ⚖  14|75|61 ═══ α=-995 β=994 ═══ ⚡ a2
 │  │  │  │     │  │  │  ├□═╤═ 🔖 77 💰 g:8 🎯 h:1000 ⚖  15|77|63 ═══ α=-995 β=994 ═══ ⚡ a3 ─── 🍃 992
 │  │  │  │     │  │  │  ├□ 992 ─── ☗ 7 { 🔖 76 } 
 │  │  │  │     │  │  ├■ 992 → β
 │  │  │  │     │  │  ├■═╤═ 🔖 74 💰 g:7 ⚖  15|77|63 ═══ α=-995 β=992 ═══ ⚡ b2
 │  │  │  │     │  │  │  ├□═╤═ 🔖 79 💰 g:8 🎯 h:1000 ⚖  16|79|65 ═══ α=-995 β=992 ═══ ⚡ a3 ─── 🍃 992
 │  │  │  │     │  │  │  ├□ 992 ─── ☗ 7 { 🔖 78 } 
 │  │  │  │     │  │  └■═╤═ 🔖 75 💰 g:7 ⚖  16|79|65 ═══ α=-995 β=992 ═══ ⚡ a3
 │  │  │  │     │  │     ├□═╤═ 🔖 81 💰 g:8 ⚖  17|81|67 ═══ α=-995 β=992 ═══ ⚡ b2
 │  │  │  │     │  │     │  └■═╤═ 🔖 82 💰 g:9 🎯 h:-1000 ⚖  18|82|68 ═══ α=-995 β=992 ═══ ⚡ a2 ─── 🍃 -991
 │  │  │  │     │  │     │  ├■ -991
 │  │  │  │     │  │     ├□ -991 → α
 │  │  │  │     │  │     └□═╤═ 🔖 80 💰 g:8 ⚖  18|82|68 ═══ α=-991 β=992 ═══ ⚡ a2
 │  │  │  │     │  │        └■═╤═ 🔖 83 💰 g:9 ⚖  19|83|69 ═══ α=-991 β=992 ═══ ⚡ b2 ─── 🍃 0
 │  │  │  │     │  │        ├■ 0
 │  │  │  │     │  │     ├□ 0
 │  │  │  │     │  │  ├■ 0
 │  │  │  │     │  ├□ 0 → α
 │  │  │  │     │  ├□═╤═ 🔖 71 💰 g:6 ⚖  19|83|69 ═══ α=0 β=994 ═══ ⚡ a3
 │  │  │  │     │  │  ├■═╤═ 🔖 84 💰 g:7 ⚖  20|86|72 ═══ α=0 β=994 ═══ ⚡ a2
 │  │  │  │     │  │  │  ├□═╤═ 🔖 87 💰 g:8 🎯 h:1000 ⚖  21|88|73 ═══ α=0 β=994 ═══ ⚡ b2 ─── 🍃 992
 │  │  │  │     │  │  │  ├□ 992 ─── ☗ 7 { 🔖 88 } 
 │  │  │  │     │  │  ├■ 992 → β
 │  │  │  │     │  │  ├■═╤═ 🔖 85 💰 g:7 ⚖  21|88|73 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │     │  │  │  ├□═╤═ 🔖 90 💰 g:8 🎯 h:992 ⚖  22|90|74 ═══ α=0 β=992 ═══ ⚡ b3 ─── 💾 992
 │  │  │  │     │  │  │  ├□ 992 ─── ☗ 7 { 🔖 89 } 
 │  │  │  │     │  │  └■═╤═ 🔖 86 💰 g:7 ⚖  22|90|74 ═══ α=0 β=992 ═══ ⚡ b3
 │  │  │  │     │  │     ├□═╤═ 🔖 92 💰 g:8 🎯 h:1000 ⚖  23|92|76 ═══ α=0 β=992 ═══ ⚡ b2 ─── 🍃 992
 │  │  │  │     │  │     ├□ 992 ─── ☗ 7 { 🔖 91 } 
 │  │  │  │     │  ├□ 992 → α
 │  │  │  │     │  ├□═╤═ 🔖 70 💰 g:6 ⚖  23|92|76 ═══ α=992 β=994 ═══ ⚡ b2
 │  │  │  │     │  │  ├■═╤═ 🔖 93 💰 g:7 ⚖  24|95|79 ═══ α=992 β=994 ═══ ⚡ a2
 │  │  │  │     │  │  │  ├□═╤═ 🔖 96 💰 g:8 🎯 h:992 ⚖  25|97|79 ═══ α=992 β=994 ═══ ⚡ a3 ─── 💾 992
 │  │  │  │     │  │  │  ├□ 992 ─── ☗ 7 { 🔖 97 } 
 │  │  │  │     │  │  ├■ 992 ─── 🪓 α(992) { 🔖 94 🔖 95 } 
 │  │  │  │     │  └□═╤═ 🔖 69 💰 g:6 ⚖  25|97|79 ═══ α=992 β=994 ═══ ⚡ a2
 │  │  │  │     │     ├■═╤═ 🔖 98 💰 g:7 ⚖  26|100|82 ═══ α=992 β=994 ═══ ⚡ b2
 │  │  │  │     │     │  ├□═╤═ 🔖 102 💰 g:8 ⚖  27|102|82 ═══ α=992 β=994 ═══ ⚡ b3
 │  │  │  │     │     │  │  └■═╤═ 🔖 103 💰 g:9 ⚖  28|103|82 ═══ α=992 β=994 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │     │     │  │  ├■ 0
 │  │  │  │     │     │  ├□ 0
 │  │  │  │     │     │  └□═╤═ 🔖 101 💰 g:8 ⚖  28|103|82 ═══ α=992 β=994 ═══ ⚡ a3
 │  │  │  │     │     │     └■═╤═ 🔖 104 💰 g:9 🎯 h:-1000 ⚖  29|104|83 ═══ α=992 β=994 ═══ ⚡ b3 ─── 🍃 -991
 │  │  │  │     │     │     ├■ -991
 │  │  │  │     │     ├■ 0 ─── 🪓 α(992) { 🔖 99 🔖 100 } 
 │  │  │  │     ├■ 992 → β
 │  │  │  │     ├■═╤═ 🔖 57 💰 g:5 ⚖  29|104|83 ═══ α=-995 β=992 ═══ ⚡ b2
 │  │  │  │     │  ├□═╤═ 🔖 106 💰 g:6 🎯 h:1000 ⚖  30|108|87 ═══ α=-995 β=992 ═══ ⚡ c2 ─── 🍃 994
 │  │  │  │     │  ├□ 994 ─── ☗ 5 { 🔖 107 🔖 108 🔖 105 } 
 │  │  │  │     └■═╤═ 🔖 60 💰 g:5 ⚖  30|108|87 ═══ α=-995 β=992 ═══ ⚡ b3
 │  │  │  │        ├□═╤═ 🔖 111 💰 g:6 🎯 h:1000 ⚖  31|112|91 ═══ α=-995 β=992 ═══ ⚡ c2 ─── 🍃 994
 │  │  │  │        ├□ 994 ─── ☗ 5 { 🔖 112 🔖 110 🔖 109 } 
 │  │  │  │  ├□ 992
 │  │  │  ├■ 992 → β
 │  │  │  ├■═╤═ 🔖 22 💰 g:3 ⚖  31|112|91 ═══ α=-1000 β=992 ═══ ⚡ c2
 │  │  │  │  ├□═╤═ 🔖 118 💰 g:4 ⚖  32|118|97 ═══ α=-1000 β=992 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 119 💰 g:5 ⚖  33|123|100 ═══ α=-1000 β=992 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 127 💰 g:6 🎯 h:1000 ⚖  34|127|103 ═══ α=-1000 β=992 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 126 🔖 125 🔖 124 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 122 💰 g:5 ⚖  34|127|103 ═══ α=-1000 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 131 💰 g:6 🎯 h:1000 ⚖  35|131|107 ═══ α=-1000 β=992 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 130 🔖 129 🔖 128 } 
 │  │  │  │  │  ├■═╤═ 🔖 121 💰 g:5 ⚖  35|131|107 ═══ α=-1000 β=992 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 135 💰 g:6 🎯 h:994 ⚖  36|135|110 ═══ α=-1000 β=992 ═══ ⚡ a3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 134 🔖 133 🔖 132 } 
 │  │  │  │  │  ├■═╤═ 🔖 120 💰 g:5 ⚖  36|135|110 ═══ α=-1000 β=992 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 139 💰 g:6 🎯 h:994 ⚖  37|139|113 ═══ α=-1000 β=992 ═══ ⚡ a3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 138 🔖 137 🔖 136 } 
 │  │  │  │  │  └■═╤═ 🔖 123 💰 g:5 ⚖  37|139|113 ═══ α=-1000 β=992 ═══ ⚡ a3
 │  │  │  │  │     ├□═╤═ 🔖 143 💰 g:6 ⚖  38|143|117 ═══ α=-1000 β=992 ═══ ⚡ b2
 │  │  │  │  │     │  ├■═╤═ 🔖 146 💰 g:7 🎯 h:-1000 ⚖  39|146|120 ═══ α=-1000 β=992 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 145 🔖 144 } 
 │  │  │  │  │     ├□ -993 → α
 │  │  │  │  │     ├□═╤═ 🔖 142 💰 g:6 ⚖  39|146|120 ═══ α=-993 β=992 ═══ ⚡ a2
 │  │  │  │  │     │  ├■═╤═ 🔖 147 💰 g:7 ⚖  40|149|123 ═══ α=-993 β=992 ═══ ⚡ b1
 │  │  │  │  │     │  │  ├□═╤═ 🔖 151 💰 g:8 ⚖  41|151|124 ═══ α=-993 β=992 ═══ ⚡ b2
 │  │  │  │  │     │  │  │  └■═╤═ 🔖 152 💰 g:9 🎯 h:-1000 ⚖  42|152|125 ═══ α=-993 β=992 ═══ ⚡ c1 ─── 🍃 -991
 │  │  │  │  │     │  │  │  ├■ -991
 │  │  │  │  │     │  │  ├□ -991 → α
 │  │  │  │  │     │  │  └□═╤═ 🔖 150 💰 g:8 ⚖  42|152|125 ═══ α=-991 β=992 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │     │  │  ├□ 0
 │  │  │  │  │     │  ├■ 0 → β
 │  │  │  │  │     │  ├■═╤═ 🔖 148 💰 g:7 ⚖  42|152|125 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │     │  │  ├□═╤═ 🔖 154 💰 g:8 ⚖  43|154|127 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │     │  │  │  └■═╤═ 🔖 155 💰 g:9 🎯 h:-991 ⚖  44|155|127 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 -991
 │  │  │  │  │     │  │  │  ├■ -991
 │  │  │  │  │     │  │  ├□ -991 → α
 │  │  │  │  │     │  │  └□═╤═ 🔖 153 💰 g:8 ⚖  44|155|127 ═══ α=-991 β=0 ═══ ⚡ b1
 │  │  │  │  │     │  │     └■═╤═ 🔖 156 💰 g:9 🎯 h:-1000 ⚖  45|156|128 ═══ α=-991 β=0 ═══ ⚡ b2 ─── 🍃 -991
 │  │  │  │  │     │  │     ├■ -991
 │  │  │  │  │     │  ├■ -991 → β
 │  │  │  │  │     │  └■═╤═ 🔖 149 💰 g:7 ⚖  45|156|128 ═══ α=-993 β=-991 ═══ ⚡ b2
 │  │  │  │  │     │     ├□═╤═ 🔖 158 💰 g:8 ⚖  46|158|130 ═══ α=-993 β=-991 ═══ ⚡ c1
 │  │  │  │  │     │     │  └■═╤═ 🔖 159 💰 g:9 ⚖  47|159|130 ═══ α=-993 β=-991 ═══ ⚡ b1 ─── 💾 0
 │  │  │  │  │     │     │  ├■ 0
 │  │  │  │  │     │     ├□ 0 ─── 🪓 β(-991) { 🔖 157 } 
 │  │  │  │  │     ├□ -991 → α
 │  │  │  │  │     ├□═╤═ 🔖 141 💰 g:6 ⚖  47|159|130 ═══ α=-991 β=992 ═══ ⚡ c1
 │  │  │  │  │     │  ├■═╤═ 🔖 161 💰 g:7 🎯 h:-1000 ⚖  48|162|132 ═══ α=-991 β=992 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 160 🔖 162 } 
 │  │  │  │  │     └□═╤═ 🔖 140 💰 g:6 ⚖  48|162|132 ═══ α=-991 β=992 ═══ ⚡ b1
 │  │  │  │  │        ├■═╤═ 🔖 164 💰 g:7 🎯 h:-1000 ⚖  49|165|135 ═══ α=-991 β=992 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │        ├■ -993 ─── ☖ 6 { 🔖 163 🔖 165 } 
 │  │  │  │  │  ├■ -991
 │  │  │  │  ├□ -991 → α
 │  │  │  │  ├□═╤═ 🔖 117 💰 g:4 ⚖  49|165|135 ═══ α=-991 β=992 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 166 💰 g:5 ⚖  50|170|137 ═══ α=-991 β=992 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 174 💰 g:6 🎯 h:994 ⚖  51|174|139 ═══ α=-991 β=992 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 171 🔖 173 🔖 172 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 169 💰 g:5 ⚖  51|174|139 ═══ α=-991 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 178 💰 g:6 🎯 h:994 ⚖  52|178|142 ═══ α=-991 β=992 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 177 🔖 176 🔖 175 } 
 │  │  │  │  │  ├■═╤═ 🔖 170 💰 g:5 ⚖  52|178|142 ═══ α=-991 β=992 ═══ ⚡ b3
 │  │  │  │  │  │  ├□═╤═ 🔖 182 💰 g:6 ⚖  53|182|146 ═══ α=-991 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 183 💰 g:7 ⚖  54|185|147 ═══ α=-991 β=992 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 186 💰 g:8 🎯 h:992 ⚖  55|187|148 ═══ α=-991 β=992 ═══ ⚡ c1 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 187 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 184 💰 g:7 ⚖  55|187|148 ═══ α=-991 β=992 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 188 💰 g:8 ⚖  56|189|149 ═══ α=-991 β=992 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 190 💰 g:9 ⚖  57|190|150 ═══ α=-991 β=992 ═══ ⚡ a2 ─── 🍃 0
 │  │  │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  │  ├□ 0 → α
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 189 💰 g:8 🎯 h:-991 ⚖  57|190|150 ═══ α=0 β=992 ═══ ⚡ a2 ─── 💾 -991
 │  │  │  │  │  │  │  ├■ 0 → β
 │  │  │  │  │  │  │  └■═╤═ 🔖 185 💰 g:7 ⚖  57|190|150 ═══ α=-991 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │     ├□═╤═ 🔖 192 💰 g:8 🎯 h:992 ⚖  58|192|151 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 992
 │  │  │  │  │  │  │     ├□ 992 ─── ☗ 7 { 🔖 191 } 
 │  │  │  │  │  │  ├□ 0 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 181 💰 g:6 ⚖  58|192|151 ═══ α=0 β=992 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 193 💰 g:7 ⚖  59|195|153 ═══ α=0 β=992 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 197 💰 g:8 ⚖  60|197|153 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 198 💰 g:9 🎯 h:-991 ⚖  61|198|153 ═══ α=0 β=992 ═══ ⚡ c1 ─── 💾 -991
 │  │  │  │  │  │  │  │  │  ├■ -991
 │  │  │  │  │  │  │  │  ├□ -991
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 196 💰 g:8 ⚖  61|198|153 ═══ α=0 β=992 ═══ ⚡ c1
 │  │  │  │  │  │  │  │     └■═╤═ 🔖 199 💰 g:9 🎯 h:-991 ⚖  62|199|153 ═══ α=0 β=992 ═══ ⚡ b2 ─── 💾 -991
 │  │  │  │  │  │  │  │     ├■ -991
 │  │  │  │  │  │  │  ├■ -991 ─── 🪓 α(0) { 🔖 194 🔖 195 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 180 💰 g:6 ⚖  62|199|153 ═══ α=0 β=992 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 202 💰 g:7 ⚖  63|202|154 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 204 💰 g:8 ⚖  64|204|155 ═══ α=0 β=992 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 205 💰 g:9 🎯 h:-991 ⚖  65|205|155 ═══ α=0 β=992 ═══ ⚡ b1 ─── 💾 -991
 │  │  │  │  │  │  │  │  │  ├■ -991
 │  │  │  │  │  │  │  │  ├□ -991
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 203 💰 g:8 ⚖  65|205|155 ═══ α=0 β=992 ═══ ⚡ b1 ─── 💾 -991
 │  │  │  │  │  │  │  ├■ -991 ─── 🪓 α(0) { 🔖 201 🔖 200 } 
 │  │  │  │  │  │  └□═╤═ 🔖 179 💰 g:6 ⚖  65|205|155 ═══ α=0 β=992 ═══ ⚡ b1
 │  │  │  │  │  │     ├■═╤═ 🔖 206 💰 g:7 ⚖  66|208|156 ═══ α=0 β=992 ═══ ⚡ c1
 │  │  │  │  │  │     │  ├□═╤═ 🔖 210 💰 g:8 ⚖  67|210|157 ═══ α=0 β=992 ═══ ⚡ b2 ─── 💾 0
 │  │  │  │  │  │     │  ├□ 0
 │  │  │  │  │  │     │  └□═╤═ 🔖 209 💰 g:8 ⚖  67|210|157 ═══ α=0 β=992 ═══ ⚡ a2
 │  │  │  │  │  │     │     └■═╤═ 🔖 211 💰 g:9 ⚖  68|211|158 ═══ α=0 β=992 ═══ ⚡ b2 ─── 🍃 0
 │  │  │  │  │  │     │     ├■ 0
 │  │  │  │  │  │     ├■ 0 ─── 🪓 α(0) { 🔖 207 🔖 208 } 
 │  │  │  │  │  ├■ 0 → β
 │  │  │  │  │  ├■═╤═ 🔖 167 💰 g:5 🎯 h:994 ⚖  68|211|158 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 994
 │  │  │  │  │  └■═╤═ 🔖 168 💰 g:5 🎯 h:994 ⚖  68|211|158 ═══ α=-991 β=0 ═══ ⚡ a2 ─── 💾 994
 │  │  │  │  ├□ 0 → α
 │  │  │  │  ├□═╤═ 🔖 114 💰 g:4 ⚖  68|211|158 ═══ α=0 β=992 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 214 💰 g:5 ⚖  69|216|160 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 220 💰 g:6 ⚖  70|220|162 ═══ α=0 β=992 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 222 💰 g:7 🎯 h:-1000 ⚖  71|223|163 ═══ α=0 β=992 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 223 🔖 221 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 219 💰 g:6 ⚖  71|223|163 ═══ α=0 β=992 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 225 💰 g:7 🎯 h:-1000 ⚖  72|226|164 ═══ α=0 β=992 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 226 🔖 224 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 218 💰 g:6 ⚖  72|226|164 ═══ α=0 β=992 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 227 💰 g:7 ⚖  73|229|165 ═══ α=0 β=992 ═══ ⚡ b1 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0 ─── 🪓 α(0) { 🔖 228 🔖 229 } 
 │  │  │  │  │  │  ├□ 0
 │  │  │  │  │  │  └□═╤═ 🔖 217 💰 g:6 ⚖  73|229|165 ═══ α=0 β=992 ═══ ⚡ b1
 │  │  │  │  │  │     ├■═╤═ 🔖 230 💰 g:7 🎯 h:-1000 ⚖  74|232|166 ═══ α=0 β=992 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │     ├■ -993 ─── ☖ 6 { 🔖 231 🔖 232 } 
 │  │  │  │  │  ├■ 0 ─── 🪓 α(0) { 🔖 215 🔖 216 🔖 213 🔖 212 } 
 │  │  │  │  ├□═╤═ 🔖 115 💰 g:4 ⚖  74|232|166 ═══ α=0 β=992 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 233 💰 g:5 ⚖  75|237|170 ═══ α=0 β=992 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 241 💰 g:6 ⚖  76|241|171 ═══ α=0 β=992 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 242 💰 g:7 🎯 h:-1000 ⚖  77|244|173 ═══ α=0 β=992 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 243 🔖 244 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 240 💰 g:6 ⚖  77|244|173 ═══ α=0 β=992 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 245 💰 g:7 🎯 h:-1000 ⚖  78|247|175 ═══ α=0 β=992 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 247 🔖 246 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 239 💰 g:6 ⚖  78|247|175 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 248 💰 g:7 🎯 h:-1000 ⚖  79|250|178 ═══ α=0 β=992 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 249 🔖 250 } 
 │  │  │  │  │  │  └□═╤═ 🔖 238 💰 g:6 ⚖  79|250|178 ═══ α=0 β=992 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  ├□ 0
 │  │  │  │  │  ├■ 0 ─── 🪓 α(0) { 🔖 236 🔖 235 🔖 234 🔖 237 } 
 │  │  │  │  ├□═╤═ 🔖 116 💰 g:4 ⚖  79|250|178 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 251 💰 g:5 ⚖  80|255|182 ═══ α=0 β=992 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 256 💰 g:6 🎯 h:992 ⚖  81|259|182 ═══ α=0 β=992 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 261 💰 g:7 ⚖  82|262|182 ═══ α=0 β=992 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0 ─── 🪓 α(0) { 🔖 260 🔖 262 } 
 │  │  │  │  │  │  ├□ 0
 │  │  │  │  │  │  ├□═╤═ 🔖 258 💰 g:6 ⚖  82|262|182 ═══ α=0 β=992 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 263 💰 g:7 🎯 h:-1000 ⚖  83|265|184 ═══ α=0 β=992 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 264 🔖 265 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 259 💰 g:6 ⚖  83|265|184 ═══ α=0 β=992 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 266 💰 g:7 🎯 h:-1000 ⚖  84|268|186 ═══ α=0 β=992 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 267 🔖 268 } 
 │  │  │  │  │  │  └□═╤═ 🔖 257 💰 g:6 🎯 h:-993 ⚖  84|268|186 ═══ α=0 β=992 ═══ ⚡ a2 ─── 💾 -993
 │  │  │  │  │  ├■ 0 ─── 🪓 α(0) { 🔖 254 🔖 253 🔖 252 🔖 255 } 
 │  │  │  │  └□═╤═ 🔖 113 💰 g:4 ⚖  84|268|186 ═══ α=0 β=992 ═══ ⚡ b1
 │  │  │  │     ├■═╤═ 🔖 269 💰 g:5 ⚖  85|273|189 ═══ α=0 β=992 ═══ ⚡ c1
 │  │  │  │     │  ├□═╤═ 🔖 277 💰 g:6 ⚖  86|277|191 ═══ α=0 β=992 ═══ ⚡ b3
 │  │  │  │     │  │  ├■═╤═ 🔖 278 💰 g:7 ⚖  87|280|193 ═══ α=0 β=992 ═══ ⚡ a2
 │  │  │  │     │  │  │  ├□═╤═ 🔖 282 💰 g:8 🎯 h:1000 ⚖  88|282|195 ═══ α=0 β=992 ═══ ⚡ a3 ─── 🍃 992
 │  │  │  │     │  │  │  ├□ 992 ─── ☗ 7 { 🔖 281 } 
 │  │  │  │     │  │  ├■ 992
 │  │  │  │     │  │  ├■═╤═ 🔖 279 💰 g:7 ⚖  88|282|195 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │     │  │  │  ├□═╤═ 🔖 284 💰 g:8 🎯 h:1000 ⚖  89|284|197 ═══ α=0 β=992 ═══ ⚡ a3 ─── 🍃 992
 │  │  │  │     │  │  │  ├□ 992 ─── ☗ 7 { 🔖 283 } 
 │  │  │  │     │  │  └■═╤═ 🔖 280 💰 g:7 ⚖  89|284|197 ═══ α=0 β=992 ═══ ⚡ a3
 │  │  │  │     │  │     ├□═╤═ 🔖 286 💰 g:8 🎯 h:1000 ⚖  90|286|198 ═══ α=0 β=992 ═══ ⚡ b2 ─── 🍃 992
 │  │  │  │     │  │     ├□ 992 ─── ☗ 7 { 🔖 285 } 
 │  │  │  │     │  ├□ 992 ─── 🪓 β(992) { 🔖 276 🔖 275 🔖 274 } 
 │  │  │  │     ├■ 992
 │  │  │  │     ├■═╤═ 🔖 272 💰 g:5 ⚖  90|286|198 ═══ α=0 β=992 ═══ ⚡ a3
 │  │  │  │     │  ├□═╤═ 🔖 288 💰 g:6 ⚖  91|290|200 ═══ α=0 β=992 ═══ ⚡ a2
 │  │  │  │     │  │  ├■═╤═ 🔖 291 💰 g:7 ⚖  92|293|203 ═══ α=0 β=992 ═══ ⚡ c1
 │  │  │  │     │  │  │  ├□═╤═ 🔖 294 💰 g:8 ⚖  93|295|204 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │     │  │  │  │  └■═╤═ 🔖 296 💰 g:9 ⚖  94|296|205 ═══ α=0 β=992 ═══ ⚡ b3 ─── 🍃 0
 │  │  │  │     │  │  │  │  ├■ 0
 │  │  │  │     │  │  │  ├□ 0
 │  │  │  │     │  │  │  └□═╤═ 🔖 295 💰 g:8 🎯 h:-991 ⚖  94|296|205 ═══ α=0 β=992 ═══ ⚡ b3 ─── 💾 -991
 │  │  │  │     │  │  ├■ 0 ─── 🪓 α(0) { 🔖 292 🔖 293 } 
 │  │  │  │     │  ├□ 0
 │  │  │  │     │  ├□═╤═ 🔖 289 💰 g:6 ⚖  94|296|205 ═══ α=0 β=992 ═══ ⚡ b2
 │  │  │  │     │  │  ├■═╤═ 🔖 298 💰 g:7 🎯 h:-1000 ⚖  95|299|208 ═══ α=0 β=992 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │     │  │  ├■ -993 ─── ☖ 6 { 🔖 297 🔖 299 } 
 │  │  │  │     │  ├□═╤═ 🔖 290 💰 g:6 🎯 h:-993 ⚖  95|299|208 ═══ α=0 β=992 ═══ ⚡ b3 ─── 💾 -993
 │  │  │  │     │  └□═╤═ 🔖 287 💰 g:6 🎯 h:-993 ⚖  95|299|208 ═══ α=0 β=992 ═══ ⚡ c1 ─── 💾 -993
 │  │  │  │     ├■ 0 ─── 🪓 α(0) { 🔖 271 🔖 270 🔖 273 } 
 │  │  │  ├■ 0 → β
 │  │  │  ├■═╤═ 🔖 23 💰 g:3 ⚖  95|299|208 ═══ α=-1000 β=0 ═══ ⚡ a3
 │  │  │  │  ├□═╤═ 🔖 305 💰 g:4 ⚖  96|305|214 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 308 💰 g:5 🎯 h:-995 ⚖  97|310|216 ═══ α=-1000 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 310 🔖 309 🔖 307 🔖 306 } 
 │  │  │  │  ├□ -995 → α
 │  │  │  │  ├□═╤═ 🔖 304 💰 g:4 ⚖  97|310|216 ═══ α=-995 β=0 ═══ ⚡ c2
 │  │  │  │  │  ├■═╤═ 🔖 313 💰 g:5 🎯 h:-995 ⚖  98|315|217 ═══ α=-995 β=0 ═══ ⚡ a2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 314 🔖 311 🔖 312 🔖 315 } 
 │  │  │  │  ├□═╤═ 🔖 301 💰 g:4 ⚖  98|315|217 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 317 💰 g:5 🎯 h:-995 ⚖  99|320|218 ═══ α=-995 β=0 ═══ ⚡ a2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 318 🔖 319 🔖 316 🔖 320 } 
 │  │  │  │  ├□═╤═ 🔖 302 💰 g:4 ⚖  99|320|218 ═══ α=-995 β=0 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 321 💰 g:5 ⚖  100|325|220 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 329 💰 g:6 ⚖  101|329|223 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 330 💰 g:7 🎯 h:-1000 ⚖  102|332|225 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 331 🔖 332 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 328 💰 g:6 ⚖  102|332|225 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 333 💰 g:7 🎯 h:-1000 ⚖  103|335|227 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 334 🔖 335 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 327 💰 g:6 ⚖  103|335|227 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 336 💰 g:7 🎯 h:-1000 ⚖  104|338|229 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 337 🔖 338 } 
 │  │  │  │  │  │  └□═╤═ 🔖 326 💰 g:6 ⚖  104|338|229 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │     ├■═╤═ 🔖 339 💰 g:7 ⚖  105|341|231 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │     │  ├□═╤═ 🔖 342 💰 g:8 🎯 h:992 ⚖  106|343|232 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 992
 │  │  │  │  │  │     │  ├□ 992 ─── ☗ 7 { 🔖 343 } 
 │  │  │  │  │  │     ├■ 992
 │  │  │  │  │  │     ├■═╤═ 🔖 340 💰 g:7 ⚖  106|343|232 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │     │  ├□═╤═ 🔖 345 💰 g:8 ⚖  107|345|232 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 0
 │  │  │  │  │  │     │  ├□ 0 ─── 🪓 β(0) { 🔖 344 } 
 │  │  │  │  │  │     ├■ 0
 │  │  │  │  │  │     └■═╤═ 🔖 341 💰 g:7 ⚖  107|345|232 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │  │  │  │        ├□═╤═ 🔖 347 💰 g:8 🎯 h:992 ⚖  108|347|233 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 992
 │  │  │  │  │  │        ├□ 992 ─── ☗ 7 { 🔖 346 } 
 │  │  │  │  │  │  ├□ 0
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 324 💰 g:5 ⚖  108|347|233 ═══ α=-995 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  ├□═╤═ 🔖 348 💰 g:6 ⚖  109|351|235 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 352 💰 g:7 ⚖  110|354|235 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 355 💰 g:8 ⚖  111|356|235 ═══ α=-995 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 357 💰 g:9 ⚖  112|357|235 ═══ α=-995 β=0 ═══ ⚡ b3 ─── 🍃 0
 │  │  │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 356 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 353 💰 g:7 ⚖  112|357|235 ═══ α=-995 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 359 💰 g:8 ⚖  113|359|235 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 360 💰 g:9 🎯 h:-991 ⚖  114|360|235 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 🍃 -991
 │  │  │  │  │  │  │  │  │  ├■ -991
 │  │  │  │  │  │  │  │  ├□ -991 → α
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 358 💰 g:8 ⚖  114|360|235 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0
 │  │  │  │  │  │  │  └■═╤═ 🔖 354 💰 g:7 ⚖  114|360|235 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │     ├□═╤═ 🔖 362 💰 g:8 ⚖  115|362|236 ═══ α=-995 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │     │  └■═╤═ 🔖 363 💰 g:9 ⚖  116|363|236 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 🍃 0
 │  │  │  │  │  │  │     │  ├■ 0
 │  │  │  │  │  │  │     ├□ 0 ─── 🪓 β(0) { 🔖 361 } 
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 350 🔖 349 🔖 351 } 
 │  │  │  │  │  ├■═╤═ 🔖 323 💰 g:5 ⚖  116|363|236 ═══ α=-995 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 367 💰 g:6 ⚖  117|367|240 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 369 💰 g:7 🎯 h:-1000 ⚖  118|370|241 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 368 🔖 370 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 366 💰 g:6 ⚖  118|370|241 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 372 💰 g:7 🎯 h:-1000 ⚖  119|373|242 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 371 🔖 373 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 365 💰 g:6 ⚖  119|373|242 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 375 💰 g:7 ⚖  120|376|242 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 378 💰 g:8 ⚖  121|378|242 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 377 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 374 💰 g:7 🎯 h:992 ⚖  121|378|242 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 992
 │  │  │  │  │  │  │  └■═╤═ 🔖 376 💰 g:7 🎯 h:992 ⚖  121|378|242 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 992
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 364 } 
 │  │  │  │  │  ├■═╤═ 🔖 322 💰 g:5 ⚖  121|378|242 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 382 💰 g:6 ⚖  122|382|246 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 383 💰 g:7 🎯 h:-993 ⚖  123|385|246 ═══ α=-995 β=0 ═══ ⚡ b1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 384 🔖 385 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 381 💰 g:6 ⚖  123|385|246 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 386 💰 g:7 🎯 h:-993 ⚖  124|388|246 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 387 🔖 388 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 380 💰 g:6 ⚖  124|388|246 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 389 💰 g:7 🎯 h:-993 ⚖  125|391|247 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 390 🔖 391 } 
 │  │  │  │  │  │  └□═╤═ 🔖 379 💰 g:6 ⚖  125|391|247 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │     ├■═╤═ 🔖 392 💰 g:7 🎯 h:-1000 ⚖  126|394|248 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 -993
 │  │  │  │  │  │     ├■ -993 ─── ☖ 6 { 🔖 393 🔖 394 } 
 │  │  │  │  │  ├■ -993 → β
 │  │  │  │  │  └■═╤═ 🔖 325 💰 g:5 🎯 h:992 ⚖  126|394|248 ═══ α=-995 β=-993 ═══ ⚡ b3 ─── 💾 992
 │  │  │  │  ├□ -993 → α
 │  │  │  │  ├□═╤═ 🔖 303 💰 g:4 ⚖  126|394|248 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 397 💰 g:5 🎯 h:-995 ⚖  127|399|249 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 398 🔖 395 🔖 396 🔖 399 } 
 │  │  │  │  └□═╤═ 🔖 300 💰 g:4 ⚖  127|399|249 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │     ├■═╤═ 🔖 401 💰 g:5 🎯 h:-995 ⚖  128|404|250 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 -995
 │  │  │  │     ├■ -995 ─── ☖ 4 { 🔖 400 🔖 402 🔖 403 🔖 404 } 
 │  │  │  ├■ -993 → β
 │  │  │  ├■═╤═ 🔖 21 💰 g:3 ⚖  128|404|250 ═══ α=-1000 β=-993 ═══ ⚡ b2
 │  │  │  │  ├□═╤═ 🔖 410 💰 g:4 ⚖  129|410|253 ═══ α=-1000 β=-993 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 411 💰 g:5 ⚖  130|415|253 ═══ α=-1000 β=-993 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 419 💰 g:6 🎯 h:1000 ⚖  131|419|256 ═══ α=-1000 β=-993 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 418 🔖 417 🔖 416 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 413 💰 g:5 ⚖  131|419|256 ═══ α=-1000 β=-993 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 423 💰 g:6 🎯 h:994 ⚖  132|423|258 ═══ α=-1000 β=-993 ═══ ⚡ a3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 422 🔖 421 🔖 420 } 
 │  │  │  │  │  ├■═╤═ 🔖 412 💰 g:5 ⚖  132|423|258 ═══ α=-1000 β=-993 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 427 💰 g:6 🎯 h:1000 ⚖  133|427|261 ═══ α=-1000 β=-993 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 426 🔖 425 🔖 424 } 
 │  │  │  │  │  ├■═╤═ 🔖 415 💰 g:5 ⚖  133|427|261 ═══ α=-1000 β=-993 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 431 💰 g:6 ⚖  134|431|263 ═══ α=-1000 β=-993 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 433 💰 g:7 🎯 h:-1000 ⚖  135|434|266 ═══ α=-1000 β=-993 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 434 🔖 432 } 
 │  │  │  │  │  │  ├□ -993 ─── 🪓 β(-993) { 🔖 429 🔖 428 🔖 430 } 
 │  │  │  │  │  ├■ -993
 │  │  │  │  │  └■═╤═ 🔖 414 💰 g:5 🎯 h:994 ⚖  135|434|266 ═══ α=-1000 β=-993 ═══ ⚡ c2 ─── 💾 994
 │  │  │  │  ├□ -993 ─── 🪓 β(-993) { 🔖 409 🔖 406 🔖 407 🔖 408 🔖 405 } 
 │  │  │  ├■═╤═ 🔖 19 💰 g:3 ⚖  135|434|266 ═══ α=-1000 β=-993 ═══ ⚡ c1 ─── 💾 -993
 │  │  │  ├■═╤═ 🔖 20 💰 g:3 ⚖  135|434|266 ═══ α=-1000 β=-993 ═══ ⚡ a2 ─── 💾 992
 │  │  │  └■═╤═ 🔖 24 💰 g:3 ⚖  135|434|266 ═══ α=-1000 β=-993 ═══ ⚡ b3 ─── 💾 0
 │  │  ├□ -993 → α
 │  │  ├□═╤═ 🔖 16 💰 g:2 ⚖  135|434|266 ═══ α=-993 β=1000 ═══ ⚡ b3
 │  │  │  ├■═╤═ 🔖 435 💰 g:3 ⚖  136|441|273 ═══ α=-993 β=1000 ═══ ⚡ b1
 │  │  │  │  ├□═╤═ 🔖 442 💰 g:4 ⚖  137|447|278 ═══ α=-993 β=1000 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 448 💰 g:5 ⚖  138|452|282 ═══ α=-993 β=1000 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 456 💰 g:6 ⚖  139|456|285 ═══ α=-993 β=1000 ═══ ⚡ c3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 459 💰 g:7 🎯 h:-993 ⚖  140|459|286 ═══ α=-993 β=1000 ═══ ⚡ a3 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 457 🔖 458 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 455 💰 g:6 ⚖  140|459|286 ═══ α=-993 β=1000 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 460 💰 g:7 ⚖  141|462|289 ═══ α=-993 β=1000 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 464 💰 g:8 🎯 h:1000 ⚖  142|464|291 ═══ α=-993 β=1000 ═══ ⚡ c3 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 463 } 
 │  │  │  │  │  │  │  ├■ 992 → β
 │  │  │  │  │  │  │  ├■═╤═ 🔖 461 💰 g:7 ⚖  142|464|291 ═══ α=-993 β=992 ═══ ⚡ c2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 465 💰 g:8 🎯 h:1000 ⚖  143|466|292 ═══ α=-993 β=992 ═══ ⚡ b2 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 466 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 462 💰 g:7 ⚖  143|466|292 ═══ α=-993 β=992 ═══ ⚡ c3
 │  │  │  │  │  │  │     ├□═╤═ 🔖 467 💰 g:8 🎯 h:1000 ⚖  144|468|294 ═══ α=-993 β=992 ═══ ⚡ b2 ─── 🍃 992
 │  │  │  │  │  │  │     ├□ 992 ─── ☗ 7 { 🔖 468 } 
 │  │  │  │  │  │  ├□ 992 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 454 💰 g:6 ⚖  144|468|294 ═══ α=992 β=1000 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 470 💰 g:7 🎯 h:-993 ⚖  145|471|296 ═══ α=992 β=1000 ═══ ⚡ a3 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 469 🔖 471 } 
 │  │  │  │  │  │  └□═╤═ 🔖 453 💰 g:6 ⚖  145|471|296 ═══ α=992 β=1000 ═══ ⚡ b2
 │  │  │  │  │  │     ├■═╤═ 🔖 473 💰 g:7 🎯 h:-993 ⚖  146|474|298 ═══ α=992 β=1000 ═══ ⚡ a3 ─── 💾 -993
 │  │  │  │  │  │     ├■ -993 ─── ☖ 6 { 🔖 472 🔖 474 } 
 │  │  │  │  │  ├■ 992 → β
 │  │  │  │  │  ├■═╤═ 🔖 451 💰 g:5 ⚖  146|474|298 ═══ α=-993 β=992 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 478 💰 g:6 ⚖  147|478|299 ═══ α=-993 β=992 ═══ ⚡ c3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 479 💰 g:7 🎯 h:-993 ⚖  148|481|300 ═══ α=-993 β=992 ═══ ⚡ a2 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 480 🔖 481 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 477 💰 g:6 ⚖  148|481|300 ═══ α=-993 β=992 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 482 💰 g:7 🎯 h:-993 ⚖  149|484|302 ═══ α=-993 β=992 ═══ ⚡ a2 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 483 🔖 484 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 476 💰 g:6 ⚖  149|484|302 ═══ α=-993 β=992 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 485 💰 g:7 🎯 h:-993 ⚖  150|487|303 ═══ α=-993 β=992 ═══ ⚡ a2 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 486 🔖 487 } 
 │  │  │  │  │  │  └□═╤═ 🔖 475 💰 g:6 ⚖  150|487|303 ═══ α=-993 β=992 ═══ ⚡ a2
 │  │  │  │  │  │     ├■═╤═ 🔖 488 💰 g:7 ⚖  151|490|305 ═══ α=-993 β=992 ═══ ⚡ b2
 │  │  │  │  │  │     │  ├□═╤═ 🔖 492 💰 g:8 ⚖  152|492|305 ═══ α=-993 β=992 ═══ ⚡ c3
 │  │  │  │  │  │     │  │  └■═╤═ 🔖 493 💰 g:9 ⚖  153|493|305 ═══ α=-993 β=992 ═══ ⚡ c2 ─── 💾 0
 │  │  │  │  │  │     │  │  ├■ 0
 │  │  │  │  │  │     │  ├□ 0 → α
 │  │  │  │  │  │     │  └□═╤═ 🔖 491 💰 g:8 ⚖  153|493|305 ═══ α=0 β=992 ═══ ⚡ c2
 │  │  │  │  │  │     │     └■═╤═ 🔖 494 💰 g:9 🎯 h:-1000 ⚖  154|494|306 ═══ α=0 β=992 ═══ ⚡ c3 ─── 🍃 -991
 │  │  │  │  │  │     │     ├■ -991
 │  │  │  │  │  │     ├■ 0 → β
 │  │  │  │  │  │     ├■═╤═ 🔖 489 💰 g:7 ⚖  154|494|306 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 0
 │  │  │  │  │  │     └■═╤═ 🔖 490 💰 g:7 ⚖  154|494|306 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │        ├□═╤═ 🔖 496 💰 g:8 ⚖  155|496|308 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │        │  └■═╤═ 🔖 497 💰 g:9 🎯 h:-991 ⚖  156|497|308 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 -991
 │  │  │  │  │  │        │  ├■ -991
 │  │  │  │  │  │        ├□ -991 → α
 │  │  │  │  │  │        └□═╤═ 🔖 495 💰 g:8 ⚖  156|497|308 ═══ α=-991 β=0 ═══ ⚡ b2
 │  │  │  │  │  │           └■═╤═ 🔖 498 💰 g:9 ⚖  157|498|309 ═══ α=-991 β=0 ═══ ⚡ c2 ─── 🍃 0
 │  │  │  │  │  │           ├■ 0
 │  │  │  │  │  │        ├□ 0
 │  │  │  │  │  │  ├□ 0
 │  │  │  │  │  ├■ 0 → β
 │  │  │  │  │  ├■═╤═ 🔖 450 💰 g:5 ⚖  157|498|309 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  ├□═╤═ 🔖 502 💰 g:6 ⚖  158|502|312 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 501 🔖 500 🔖 499 } 
 │  │  │  │  │  ├■═╤═ 🔖 449 💰 g:5 ⚖  158|502|312 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 506 💰 g:6 ⚖  159|506|315 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 507 💰 g:7 ⚖  160|509|315 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 510 💰 g:8 🎯 h:1000 ⚖  161|511|316 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 511 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 509 💰 g:7 ⚖  161|511|316 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 513 💰 g:8 🎯 h:1000 ⚖  162|513|317 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 512 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 508 💰 g:7 🎯 h:992 ⚖  162|513|317 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 992
 │  │  │  │  │  │  ├□ 992 ─── 🪓 β(0) { 🔖 505 🔖 504 🔖 503 } 
 │  │  │  │  │  └■═╤═ 🔖 452 💰 g:5 ⚖  162|513|317 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │     ├□═╤═ 🔖 517 💰 g:6 ⚖  163|517|321 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │     │  ├■═╤═ 🔖 519 💰 g:7 🎯 h:-1000 ⚖  164|520|323 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 520 🔖 518 } 
 │  │  │  │  │     ├□ -993
 │  │  │  │  │     ├□═╤═ 🔖 516 💰 g:6 ⚖  164|520|323 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │     │  ├■═╤═ 🔖 522 💰 g:7 🎯 h:-1000 ⚖  165|523|324 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 521 🔖 523 } 
 │  │  │  │  │     ├□═╤═ 🔖 515 💰 g:6 ⚖  165|523|324 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │     │  ├■═╤═ 🔖 524 💰 g:7 ⚖  166|526|325 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │     │  │  ├□═╤═ 🔖 528 💰 g:8 🎯 h:992 ⚖  167|528|326 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 992
 │  │  │  │  │     │  │  ├□ 992 ─── ☗ 7 { 🔖 527 } 
 │  │  │  │  │     │  ├■ 992
 │  │  │  │  │     │  ├■═╤═ 🔖 525 💰 g:7 ⚖  167|528|326 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │     │  │  ├□═╤═ 🔖 530 💰 g:8 🎯 h:1000 ⚖  168|530|328 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 🍃 992
 │  │  │  │  │     │  │  ├□ 992 ─── ☗ 7 { 🔖 529 } 
 │  │  │  │  │     │  └■═╤═ 🔖 526 💰 g:7 ⚖  168|530|328 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │     │     ├□═╤═ 🔖 532 💰 g:8 ⚖  169|532|329 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │     │     │  └■═╤═ 🔖 533 💰 g:9 🎯 h:-1000 ⚖  170|533|330 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -991
 │  │  │  │  │     │     │  ├■ -991
 │  │  │  │  │     │     ├□ -991 → α
 │  │  │  │  │     │     └□═╤═ 🔖 531 💰 g:8 ⚖  170|533|330 ═══ α=-991 β=0 ═══ ⚡ a2 ─── 💾 0
 │  │  │  │  │     │     ├□ 0
 │  │  │  │  │     │  ├■ 0
 │  │  │  │  │     ├□ 0 ─── 🪓 β(0) { 🔖 514 } 
 │  │  │  │  ├□ 0 → α
 │  │  │  │  ├□═╤═ 🔖 446 💰 g:4 ⚖  170|533|330 ═══ α=0 β=1000 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 534 💰 g:5 🎯 h:-995 ⚖  171|538|334 ═══ α=0 β=1000 ═══ ⚡ c1 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 537 🔖 536 🔖 535 🔖 538 } 
 │  │  │  │  ├□═╤═ 🔖 443 💰 g:4 ⚖  171|538|334 ═══ α=0 β=1000 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 539 💰 g:5 🎯 h:-1000 ⚖  172|543|339 ═══ α=0 β=1000 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 542 🔖 541 🔖 540 🔖 543 } 
 │  │  │  │  ├□═╤═ 🔖 444 💰 g:4 ⚖  172|543|339 ═══ α=0 β=1000 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 544 💰 g:5 🎯 h:-1000 ⚖  173|548|344 ═══ α=0 β=1000 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 547 🔖 546 🔖 545 🔖 548 } 
 │  │  │  │  ├□═╤═ 🔖 445 💰 g:4 ⚖  173|548|344 ═══ α=0 β=1000 ═══ ⚡ c2
 │  │  │  │  │  ├■═╤═ 🔖 549 💰 g:5 🎯 h:-995 ⚖  174|553|348 ═══ α=0 β=1000 ═══ ⚡ c1 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 552 🔖 551 🔖 550 🔖 553 } 
 │  │  │  │  └□═╤═ 🔖 447 💰 g:4 🎯 h:-995 ⚖  174|553|348 ═══ α=0 β=1000 ═══ ⚡ c3 ─── 💾 -995
 │  │  │  ├■ 0 → β
 │  │  │  ├■═╤═ 🔖 439 💰 g:3 ⚖  174|553|348 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  ├□═╤═ 🔖 554 💰 g:4 ⚖  175|559|353 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  ├■═╤═ 🔖 560 💰 g:5 ⚖  176|564|358 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 566 💰 g:6 🎯 h:1000 ⚖  177|568|360 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 568 🔖 565 🔖 567 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 563 💰 g:5 ⚖  177|568|360 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 571 💰 g:6 🎯 h:1000 ⚖  178|572|362 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 570 🔖 572 🔖 569 } 
 │  │  │  │  │  ├■═╤═ 🔖 562 💰 g:5 ⚖  178|572|362 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 576 💰 g:6 ⚖  179|576|365 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 578 💰 g:7 🎯 h:-1000 ⚖  180|579|366 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 579 🔖 577 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 575 💰 g:6 ⚖  180|579|366 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 581 💰 g:7 🎯 h:-1000 ⚖  181|582|368 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 582 🔖 580 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 574 💰 g:6 ⚖  181|582|368 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 585 💰 g:7 🎯 h:-1000 ⚖  182|585|371 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 584 🔖 583 } 
 │  │  │  │  │  │  └□═╤═ 🔖 573 💰 g:6 ⚖  182|585|371 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │     ├■═╤═ 🔖 586 💰 g:7 🎯 h:-1000 ⚖  183|588|373 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │     ├■ -993 ─── ☖ 6 { 🔖 588 🔖 587 } 
 │  │  │  │  │  ├■ -993 ─── 🪓 α(-993) { 🔖 561 🔖 564 } 
 │  │  │  │  ├□ -993
 │  │  │  │  ├□═╤═ 🔖 558 💰 g:4 ⚖  183|588|373 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 589 💰 g:5 ⚖  184|593|376 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 597 💰 g:6 🎯 h:994 ⚖  185|597|378 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 596 🔖 595 🔖 594 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 592 💰 g:5 ⚖  185|597|378 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 601 💰 g:6 🎯 h:994 ⚖  186|601|380 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 600 🔖 599 🔖 598 } 
 │  │  │  │  │  ├■═╤═ 🔖 591 💰 g:5 ⚖  186|601|380 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 605 💰 g:6 🎯 h:994 ⚖  187|605|383 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 604 🔖 603 🔖 602 } 
 │  │  │  │  │  ├■═╤═ 🔖 590 💰 g:5 ⚖  187|605|383 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 609 💰 g:6 🎯 h:994 ⚖  188|609|385 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 608 🔖 607 🔖 606 } 
 │  │  │  │  │  └■═╤═ 🔖 593 💰 g:5 ⚖  188|609|385 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │     ├□═╤═ 🔖 613 💰 g:6 ⚖  189|613|389 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │     │  ├■═╤═ 🔖 615 💰 g:7 🎯 h:-1000 ⚖  190|616|392 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 614 🔖 616 } 
 │  │  │  │  │     ├□ -993
 │  │  │  │  │     ├□═╤═ 🔖 612 💰 g:6 ⚖  190|616|392 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │     │  ├■═╤═ 🔖 618 💰 g:7 🎯 h:-1000 ⚖  191|619|395 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 619 🔖 617 } 
 │  │  │  │  │     ├□═╤═ 🔖 611 💰 g:6 ⚖  191|619|395 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │     │  ├■═╤═ 🔖 622 💰 g:7 🎯 h:-1000 ⚖  192|622|397 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 621 🔖 620 } 
 │  │  │  │  │     └□═╤═ 🔖 610 💰 g:6 ⚖  192|622|397 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │        ├■═╤═ 🔖 625 💰 g:7 🎯 h:-1000 ⚖  193|625|398 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 -993
 │  │  │  │  │        ├■ -993 ─── ☖ 6 { 🔖 623 🔖 624 } 
 │  │  │  │  │  ├■ -993
 │  │  │  │  ├□═╤═ 🔖 555 💰 g:4 ⚖  193|625|398 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 626 💰 g:5 ⚖  194|630|402 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 0
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 629 💰 g:5 ⚖  194|630|402 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 632 💰 g:6 ⚖  195|634|404 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 635 💰 g:7 ⚖  196|637|405 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 636 💰 g:7 ⚖  196|637|405 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 639 💰 g:8 ⚖  197|639|405 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 638 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 637 💰 g:7 ⚖  197|639|405 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │     ├□═╤═ 🔖 641 💰 g:8 ⚖  198|641|405 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │     │  └■═╤═ 🔖 642 💰 g:9 ⚖  199|642|405 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 0
 │  │  │  │  │  │  │     │  ├■ 0
 │  │  │  │  │  │  │     ├□ 0 ─── 🪓 β(0) { 🔖 640 } 
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 633 🔖 634 🔖 631 } 
 │  │  │  │  │  ├■═╤═ 🔖 628 💰 g:5 ⚖  199|642|405 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 644 💰 g:6 ⚖  200|646|406 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 649 💰 g:7 🎯 h:-1000 ⚖  201|649|408 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 648 🔖 647 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 645 💰 g:6 ⚖  201|649|408 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 651 💰 g:7 🎯 h:-1000 ⚖  202|652|410 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 652 🔖 650 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 646 💰 g:6 🎯 h:-993 ⚖  202|652|410 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 -993
 │  │  │  │  │  │  └□═╤═ 🔖 643 💰 g:6 🎯 h:-993 ⚖  202|652|410 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 -993
 │  │  │  │  │  ├■ -993 ─── 🪓 α(-993) { 🔖 627 🔖 630 } 
 │  │  │  │  ├□═╤═ 🔖 556 💰 g:4 ⚖  202|652|410 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 653 💰 g:5 ⚖  203|657|412 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 658 💰 g:6 ⚖  204|661|413 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 662 💰 g:7 ⚖  205|664|414 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 666 💰 g:8 ⚖  206|666|415 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 667 💰 g:9 ⚖  207|667|415 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 665 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 663 💰 g:7 ⚖  207|667|415 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  │  └■═╤═ 🔖 664 💰 g:7 ⚖  207|667|415 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │     ├□═╤═ 🔖 669 💰 g:8 ⚖  208|669|416 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │     │  └■═╤═ 🔖 670 💰 g:9 🎯 h:-1000 ⚖  209|670|417 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 -991
 │  │  │  │  │  │  │     │  ├■ -991
 │  │  │  │  │  │  │     ├□ -991 → α
 │  │  │  │  │  │  │     └□═╤═ 🔖 668 💰 g:8 ⚖  209|670|417 ═══ α=-991 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │        └■═╤═ 🔖 671 💰 g:9 ⚖  210|671|417 ═══ α=-991 β=0 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  │        ├■ 0
 │  │  │  │  │  │  │     ├□ 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 660 🔖 659 🔖 661 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 656 💰 g:5 ⚖  210|671|417 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 672 💰 g:6 ⚖  211|675|418 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 676 💰 g:7 ⚖  212|678|419 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 679 💰 g:8 🎯 h:1000 ⚖  213|680|420 ═══ α=-993 β=0 ═══ ⚡ b2 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 680 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 677 💰 g:7 ⚖  213|680|420 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 682 💰 g:8 🎯 h:-991 ⚖  214|682|420 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 -991
 │  │  │  │  │  │  │  │  ├□ -991 → α
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 681 💰 g:8 🎯 h:-991 ⚖  214|682|420 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 -991
 │  │  │  │  │  │  │  ├■ -991 → β
 │  │  │  │  │  │  │  └■═╤═ 🔖 678 💰 g:7 ⚖  214|682|420 ═══ α=-993 β=-991 ═══ ⚡ c3 ─── 💾 992
 │  │  │  │  │  │  ├□ -991 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 674 💰 g:6 ⚖  214|682|420 ═══ α=-991 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 683 💰 g:7 ⚖  215|685|423 ═══ α=-991 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 686 💰 g:8 ⚖  216|687|423 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 687 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 684 💰 g:7 ⚖  216|687|423 ═══ α=-991 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 688 💰 g:8 🎯 h:992 ⚖  217|689|423 ═══ α=-991 β=0 ═══ ⚡ b1 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 689 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 685 💰 g:7 ⚖  217|689|423 ═══ α=-991 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │     ├□═╤═ 🔖 690 💰 g:8 🎯 h:992 ⚖  218|691|423 ═══ α=-991 β=0 ═══ ⚡ b1 ─── 💾 992
 │  │  │  │  │  │  │     ├□ 992 ─── ☗ 7 { 🔖 691 } 
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 673 🔖 675 } 
 │  │  │  │  │  ├■═╤═ 🔖 655 💰 g:5 ⚖  218|691|423 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 695 💰 g:6 ⚖  219|695|423 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 696 💰 g:7 ⚖  220|698|423 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 700 💰 g:8 🎯 h:1000 ⚖  221|700|424 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 699 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 697 💰 g:7 ⚖  221|700|424 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 702 💰 g:8 🎯 h:992 ⚖  222|702|424 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 701 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 698 💰 g:7 ⚖  222|702|424 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 694 🔖 693 🔖 692 } 
 │  │  │  │  │  ├■═╤═ 🔖 654 💰 g:5 ⚖  222|702|424 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 703 💰 g:6 ⚖  223|706|425 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 709 💰 g:7 🎯 h:-1000 ⚖  224|709|426 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 707 🔖 708 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 705 💰 g:6 ⚖  224|709|426 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 710 💰 g:7 🎯 h:-1000 ⚖  225|712|427 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 712 🔖 711 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 704 💰 g:6 ⚖  225|712|427 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 713 💰 g:7 🎯 h:-1000 ⚖  226|715|429 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 715 🔖 714 } 
 │  │  │  │  │  │  └□═╤═ 🔖 706 💰 g:6 🎯 h:-993 ⚖  226|715|429 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 -993
 │  │  │  │  │  ├■ -993 ─── 🪓 α(-993) { 🔖 657 } 
 │  │  │  │  ├□═╤═ 🔖 557 💰 g:4 ⚖  226|715|429 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 716 💰 g:5 ⚖  227|720|433 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 721 💰 g:6 ⚖  228|724|433 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 725 💰 g:7 ⚖  229|727|433 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 728 💰 g:8 🎯 h:992 ⚖  230|729|433 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 729 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 726 💰 g:7 ⚖  230|729|433 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 730 💰 g:8 ⚖  231|731|433 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 731 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  └■═╤═ 🔖 727 💰 g:7 🎯 h:992 ⚖  231|731|433 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 992
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 723 🔖 722 🔖 724 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 719 💰 g:5 ⚖  231|731|433 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 732 💰 g:6 🎯 h:994 ⚖  232|735|433 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 734 🔖 733 🔖 735 } 
 │  │  │  │  │  ├■═╤═ 🔖 718 💰 g:5 ⚖  232|735|433 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 736 💰 g:6 🎯 h:1000 ⚖  233|739|435 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 738 🔖 739 🔖 737 } 
 │  │  │  │  │  ├■═╤═ 🔖 717 💰 g:5 ⚖  233|739|435 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 740 💰 g:6 🎯 h:994 ⚖  234|743|435 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 742 🔖 743 🔖 741 } 
 │  │  │  │  │  └■═╤═ 🔖 720 💰 g:5 ⚖  234|743|435 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │     ├□═╤═ 🔖 744 💰 g:6 🎯 h:1000 ⚖  235|747|438 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 994
 │  │  │  │  │     ├□ 994 ─── ☗ 5 { 🔖 746 🔖 745 🔖 747 } 
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 559 } 
 │  │  │  ├■═╤═ 🔖 440 💰 g:3 ⚖  235|747|438 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  ├□═╤═ 🔖 748 💰 g:4 ⚖  236|753|443 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  ├■═╤═ 🔖 755 💰 g:5 🎯 h:-1000 ⚖  237|758|446 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 754 🔖 756 🔖 758 🔖 757 } 
 │  │  │  │  ├□ -995
 │  │  │  │  ├□═╤═ 🔖 752 💰 g:4 ⚖  237|758|446 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  ├■═╤═ 🔖 761 💰 g:5 🎯 h:-995 ⚖  238|763|449 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 759 🔖 762 🔖 760 🔖 763 } 
 │  │  │  │  ├□═╤═ 🔖 749 💰 g:4 ⚖  238|763|449 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 765 💰 g:5 🎯 h:-1000 ⚖  239|768|451 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 768 🔖 766 🔖 767 🔖 764 } 
 │  │  │  │  ├□═╤═ 🔖 750 💰 g:4 ⚖  239|768|451 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 769 💰 g:5 ⚖  240|773|453 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 774 💰 g:6 ⚖  241|777|454 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 775 🔖 776 🔖 777 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 772 💰 g:5 ⚖  241|777|454 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 0
 │  │  │  │  │  ├■═╤═ 🔖 771 💰 g:5 ⚖  241|777|454 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 778 💰 g:6 ⚖  242|781|457 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 782 💰 g:7 🎯 h:-1000 ⚖  243|784|458 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 784 🔖 783 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 780 💰 g:6 ⚖  243|784|458 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 786 💰 g:7 🎯 h:-1000 ⚖  244|787|459 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 787 🔖 785 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 779 💰 g:6 ⚖  244|787|459 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 790 💰 g:7 🎯 h:-993 ⚖  245|790|459 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 789 🔖 788 } 
 │  │  │  │  │  │  └□═╤═ 🔖 781 💰 g:6 🎯 h:-993 ⚖  245|790|459 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 -993
 │  │  │  │  │  ├■ -993 ─── 🪓 α(-993) { 🔖 770 🔖 773 } 
 │  │  │  │  ├□ -993
 │  │  │  │  ├□═╤═ 🔖 751 💰 g:4 ⚖  245|790|459 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 793 💰 g:5 🎯 h:-1000 ⚖  246|795|462 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 791 🔖 792 🔖 795 🔖 794 } 
 │  │  │  │  └□═╤═ 🔖 753 💰 g:4 🎯 h:-995 ⚖  246|795|462 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 -995
 │  │  │  ├■ -993 ─── 🪓 α(-993) { 🔖 438 🔖 436 🔖 437 🔖 441 } 
 │  │  ├□═╤═ 🔖 11 💰 g:2 ⚖  246|795|462 ═══ α=-993 β=1000 ═══ ⚡ c1
 │  │  │  ├■═╤═ 🔖 800 💰 g:3 🎯 h:-993 ⚖  247|802|468 ═══ α=-993 β=1000 ═══ ⚡ a3 ─── 💾 -993
 │  │  │  ├■ -993 ─── 🪓 α(-993) { 🔖 796 🔖 801 🔖 799 🔖 797 🔖 798 🔖 802 } 
 │  │  ├□═╤═ 🔖 12 💰 g:2 ⚖  247|802|468 ═══ α=-993 β=1000 ═══ ⚡ a2
 │  │  │  ├■═╤═ 🔖 804 💰 g:3 🎯 h:-993 ⚖  248|809|474 ═══ α=-993 β=1000 ═══ ⚡ c1 ─── 💾 -993
 │  │  │  ├■ -993 ─── 🪓 α(-993) { 🔖 803 🔖 807 🔖 806 🔖 805 🔖 808 🔖 809 } 
 │  │  ├□═╤═ 🔖 13 💰 g:2 ⚖  248|809|474 ═══ α=-993 β=1000 ═══ ⚡ b2
 │  │  │  ├■═╤═ 🔖 810 💰 g:3 ⚖  249|816|478 ═══ α=-993 β=1000 ═══ ⚡ b1
 │  │  │  │  ├□═╤═ 🔖 817 💰 g:4 ⚖  250|822|482 ═══ α=-993 β=1000 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 823 💰 g:5 ⚖  251|827|486 ═══ α=-993 β=1000 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 829 💰 g:6 🎯 h:1000 ⚖  252|831|488 ═══ α=-993 β=1000 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 831 🔖 828 🔖 830 } 
 │  │  │  │  │  ├■ 994 → β
 │  │  │  │  │  ├■═╤═ 🔖 826 💰 g:5 ⚖  252|831|488 ═══ α=-993 β=994 ═══ ⚡ b3
 │  │  │  │  │  │  ├□═╤═ 🔖 834 💰 g:6 🎯 h:1000 ⚖  253|835|490 ═══ α=-993 β=994 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 835 🔖 833 🔖 832 } 
 │  │  │  │  │  ├■═╤═ 🔖 825 💰 g:5 ⚖  253|835|490 ═══ α=-993 β=994 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 839 💰 g:6 ⚖  254|839|490 ═══ α=-993 β=994 ═══ ⚡ c3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 840 💰 g:7 🎯 h:-993 ⚖  255|842|491 ═══ α=-993 β=994 ═══ ⚡ a2 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 841 🔖 842 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 837 💰 g:6 ⚖  255|842|491 ═══ α=-993 β=994 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 843 💰 g:7 🎯 h:-993 ⚖  256|845|492 ═══ α=-993 β=994 ═══ ⚡ a2 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 844 🔖 845 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 836 💰 g:6 ⚖  256|845|492 ═══ α=-993 β=994 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 846 💰 g:7 ⚖  257|848|493 ═══ α=-993 β=994 ═══ ⚡ c2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 850 💰 g:8 ⚖  258|850|493 ═══ α=-993 β=994 ═══ ⚡ c3 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 → α
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 849 💰 g:8 ⚖  258|850|493 ═══ α=0 β=994 ═══ ⚡ b3
 │  │  │  │  │  │  │  │     └■═╤═ 🔖 851 💰 g:9 ⚖  259|851|493 ═══ α=0 β=994 ═══ ⚡ c3 ─── 🍃 0
 │  │  │  │  │  │  │  │     ├■ 0
 │  │  │  │  │  │  │  ├■ 0 → β
 │  │  │  │  │  │  │  ├■═╤═ 🔖 847 💰 g:7 ⚖  259|851|493 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 852 💰 g:8 🎯 h:1000 ⚖  260|853|493 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 853 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 848 💰 g:7 ⚖  260|853|493 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │     ├□═╤═ 🔖 854 💰 g:8 🎯 h:992 ⚖  261|855|493 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 992
 │  │  │  │  │  │  │     ├□ 992 ─── ☗ 7 { 🔖 855 } 
 │  │  │  │  │  │  ├□ 0 → α
 │  │  │  │  │  │  └□═╤═ 🔖 838 💰 g:6 🎯 h:-993 ⚖  261|855|493 ═══ α=0 β=994 ═══ ⚡ b3 ─── 💾 -993
 │  │  │  │  │  ├■ 0 → β
 │  │  │  │  │  ├■═╤═ 🔖 824 💰 g:5 ⚖  261|855|493 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  ├□═╤═ 🔖 857 💰 g:6 🎯 h:1000 ⚖  262|859|495 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 859 🔖 858 🔖 856 } 
 │  │  │  │  │  └■═╤═ 🔖 827 💰 g:5 ⚖  262|859|495 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │     ├□═╤═ 🔖 862 💰 g:6 🎯 h:1000 ⚖  263|863|498 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │     ├□ 994 ─── ☗ 5 { 🔖 863 🔖 861 🔖 860 } 
 │  │  │  │  ├□ 0 → α
 │  │  │  │  ├□═╤═ 🔖 818 💰 g:4 ⚖  263|863|498 ═══ α=0 β=1000 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 864 💰 g:5 🎯 h:-995 ⚖  264|868|501 ═══ α=0 β=1000 ═══ ⚡ c1 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 867 🔖 866 🔖 865 🔖 868 } 
 │  │  │  │  ├□═╤═ 🔖 819 💰 g:4 ⚖  264|868|501 ═══ α=0 β=1000 ═══ ⚡ c2
 │  │  │  │  │  ├■═╤═ 🔖 869 💰 g:5 🎯 h:-995 ⚖  265|873|502 ═══ α=0 β=1000 ═══ ⚡ c1 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 873 🔖 870 🔖 872 🔖 871 } 
 │  │  │  │  ├□═╤═ 🔖 820 💰 g:4 ⚖  265|873|502 ═══ α=0 β=1000 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 874 💰 g:5 🎯 h:-995 ⚖  266|878|505 ═══ α=0 β=1000 ═══ ⚡ c1 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 877 🔖 876 🔖 878 🔖 875 } 
 │  │  │  │  ├□═╤═ 🔖 821 💰 g:4 🎯 h:-995 ⚖  266|878|505 ═══ α=0 β=1000 ═══ ⚡ b3 ─── 💾 -995
 │  │  │  │  └□═╤═ 🔖 822 💰 g:4 🎯 h:-995 ⚖  266|878|505 ═══ α=0 β=1000 ═══ ⚡ c3 ─── 💾 -995
 │  │  │  ├■ 0 → β
 │  │  │  ├■═╤═ 🔖 814 💰 g:3 ⚖  266|878|505 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  ├□═╤═ 🔖 881 💰 g:4 ⚖  267|884|507 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 885 💰 g:5 ⚖  268|889|508 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 891 💰 g:6 🎯 h:994 ⚖  269|893|508 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 892 🔖 890 🔖 893 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 888 💰 g:5 ⚖  269|893|508 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  │  ├■═╤═ 🔖 887 💰 g:5 ⚖  269|893|508 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  ├□═╤═ 🔖 897 💰 g:6 ⚖  270|897|508 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 898 💰 g:7 ⚖  271|900|508 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 901 💰 g:8 ⚖  272|902|508 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 902 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 899 💰 g:7 ⚖  272|902|508 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 903 💰 g:8 ⚖  273|904|508 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 905 💰 g:9 ⚖  274|905|508 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 🍃 0
 │  │  │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 904 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 900 💰 g:7 ⚖  274|905|508 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 896 🔖 895 🔖 894 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 886 💰 g:5 ⚖  274|905|508 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 907 💰 g:6 🎯 h:1000 ⚖  275|909|511 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 908 🔖 906 🔖 909 } 
 │  │  │  │  │  └■═╤═ 🔖 889 💰 g:5 ⚖  275|909|511 ═══ α=-993 β=0 ═══ ⚡ c3 ─── 💾 994
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 882 🔖 880 🔖 884 🔖 883 🔖 879 } 
 │  │  │  ├■═╤═ 🔖 815 💰 g:3 ⚖  275|909|511 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │  │  ├□═╤═ 🔖 915 💰 g:4 ⚖  276|915|515 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │  │  │  ├■═╤═ 🔖 916 💰 g:5 ⚖  277|920|515 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 924 💰 g:6 ⚖  278|924|517 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 925 💰 g:7 🎯 h:-1000 ⚖  279|927|518 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 926 🔖 927 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 923 💰 g:6 ⚖  279|927|518 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 928 💰 g:7 🎯 h:-993 ⚖  280|930|518 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 929 🔖 930 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 922 💰 g:6 ⚖  280|930|518 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 931 💰 g:7 🎯 h:-993 ⚖  281|933|518 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 932 🔖 933 } 
 │  │  │  │  │  │  └□═╤═ 🔖 921 💰 g:6 ⚖  281|933|518 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │     ├■═╤═ 🔖 934 💰 g:7 ⚖  282|936|518 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │     │  ├□═╤═ 🔖 937 💰 g:8 🎯 h:1000 ⚖  283|938|519 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 🍃 992
 │  │  │  │  │  │     │  ├□ 992 ─── ☗ 7 { 🔖 938 } 
 │  │  │  │  │  │     ├■ 992
 │  │  │  │  │  │     ├■═╤═ 🔖 936 💰 g:7 ⚖  283|938|519 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │     │  ├□═╤═ 🔖 940 💰 g:8 🎯 h:1000 ⚖  284|940|520 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 🍃 992
 │  │  │  │  │  │     │  ├□ 992 ─── ☗ 7 { 🔖 939 } 
 │  │  │  │  │  │     └■═╤═ 🔖 935 💰 g:7 🎯 h:992 ⚖  284|940|520 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 992
 │  │  │  │  │  │  ├□ 992
 │  │  │  │  │  ├■ 992
 │  │  │  │  │  ├■═╤═ 🔖 919 💰 g:5 ⚖  284|940|520 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  ├□═╤═ 🔖 944 💰 g:6 ⚖  285|944|521 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 943 🔖 942 🔖 941 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 918 💰 g:5 ⚖  285|944|521 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 948 💰 g:6 🎯 h:992 ⚖  286|948|521 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 950 💰 g:7 ⚖  287|951|521 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 949 💰 g:7 🎯 h:992 ⚖  287|951|521 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 952 💰 g:8 🎯 h:992 ⚖  288|953|521 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 953 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 951 💰 g:7 🎯 h:992 ⚖  288|953|521 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 992
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 947 🔖 946 🔖 945 } 
 │  │  │  │  │  ├■═╤═ 🔖 917 💰 g:5 ⚖  288|953|521 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 957 💰 g:6 ⚖  289|957|522 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 958 💰 g:7 🎯 h:-993 ⚖  290|960|522 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 959 🔖 960 } 
 │  │  │  │  │  │  ├□ -993
 │  │  │  │  │  │  ├□═╤═ 🔖 954 💰 g:6 ⚖  290|960|522 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 956 🔖 955 } 
 │  │  │  │  │  └■═╤═ 🔖 920 💰 g:5 ⚖  290|960|522 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 914 🔖 911 🔖 912 🔖 913 🔖 910 } 
 │  │  │  ├■═╤═ 🔖 813 💰 g:3 ⚖  290|960|522 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 0
 │  │  │  ├■═╤═ 🔖 811 💰 g:3 ⚖  290|960|522 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  ├■═╤═ 🔖 812 💰 g:3 ⚖  290|960|522 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 0
 │  │  │  └■═╤═ 🔖 816 💰 g:3 ⚖  290|960|522 ═══ α=-993 β=0 ═══ ⚡ c3
 │  │  │     ├□═╤═ 🔖 966 💰 g:4 ⚖  291|966|525 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │     │  ├■═╤═ 🔖 967 💰 g:5 ⚖  292|971|525 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │     │  │  ├□═╤═ 🔖 975 💰 g:6 ⚖  293|975|527 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │     │  │  │  ├■═╤═ 🔖 976 💰 g:7 🎯 h:-1000 ⚖  294|978|529 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │     │  │  │  ├■ -993 ─── ☖ 6 { 🔖 977 🔖 978 } 
 │  │  │     │  │  ├□ -993
 │  │  │     │  │  ├□═╤═ 🔖 974 💰 g:6 ⚖  294|978|529 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │     │  │  │  ├■═╤═ 🔖 979 💰 g:7 🎯 h:-1000 ⚖  295|981|531 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │     │  │  │  ├■ -993 ─── ☖ 6 { 🔖 980 🔖 981 } 
 │  │  │     │  │  ├□═╤═ 🔖 973 💰 g:6 ⚖  295|981|531 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │     │  │  │  ├■═╤═ 🔖 982 💰 g:7 🎯 h:-1000 ⚖  296|984|532 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │     │  │  │  ├■ -993 ─── ☖ 6 { 🔖 983 🔖 984 } 
 │  │  │     │  │  └□═╤═ 🔖 972 💰 g:6 ⚖  296|984|532 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │     │  │  ├□ 0
 │  │  │     │  ├■ 0
 │  │  │     │  ├■═╤═ 🔖 969 💰 g:5 ⚖  296|984|532 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │     │  │  ├□═╤═ 🔖 985 💰 g:6 🎯 h:1000 ⚖  297|988|534 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 994
 │  │  │     │  │  ├□ 994 ─── ☗ 5 { 🔖 988 🔖 986 🔖 987 } 
 │  │  │     │  ├■═╤═ 🔖 968 💰 g:5 ⚖  297|988|534 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │     │  │  ├□═╤═ 🔖 989 💰 g:6 🎯 h:1000 ⚖  298|992|537 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 994
 │  │  │     │  │  ├□ 994 ─── ☗ 5 { 🔖 991 🔖 992 🔖 990 } 
 │  │  │     │  ├■═╤═ 🔖 970 💰 g:5 🎯 h:994 ⚖  298|992|537 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 994
 │  │  │     │  └■═╤═ 🔖 971 💰 g:5 🎯 h:994 ⚖  298|992|537 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 994
 │  │  │     ├□ 0 ─── 🪓 β(0) { 🔖 965 🔖 962 🔖 963 🔖 964 🔖 961 } 
 │  │  ├□ 0 → α
 │  │  ├□═╤═ 🔖 14 💰 g:2 ⚖  298|992|537 ═══ α=0 β=1000 ═══ ⚡ c2 ─── 💾 -993
 │  │  ├□═╤═ 🔖 15 💰 g:2 ⚖  298|992|537 ═══ α=0 β=1000 ═══ ⚡ a3 ─── 💾 -993
 │  │  └□═╤═ 🔖 10 💰 g:2 ⚖  298|992|537 ═══ α=0 β=1000 ═══ ⚡ b1 ─── 💾 -993
 │  ├■ 0 → β
 │  ├■═╤═ 🔖 7 💰 g:1 ⚖  298|992|537 ═══ α=-1000 β=0 ═══ ⚡ a3 ─── 💾 0
 │  ├■═╤═ 🔖 6 💰 g:1 ⚖  298|992|537 ═══ α=-1000 β=0 ═══ ⚡ c2
 │  │  ├□═╤═ 🔖 1000 💰 g:2 ⚖  299|1000|542 ═══ α=-1000 β=0 ═══ ⚡ c3
 │  │  │  ├■═╤═ 🔖 1001 💰 g:3 ⚖  300|1007|546 ═══ α=-1000 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │  ├■ 0
 │  │  │  ├■═╤═ 🔖 1005 💰 g:3 ⚖  300|1007|546 ═══ α=-1000 β=0 ═══ ⚡ b2
 │  │  │  │  ├□═╤═ 🔖 1013 💰 g:4 ⚖  301|1013|552 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 1017 💰 g:5 🎯 h:-1000 ⚖  302|1018|556 ═══ α=-1000 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1016 🔖 1018 🔖 1015 🔖 1014 } 
 │  │  │  │  ├□ -995 → α
 │  │  │  │  ├□═╤═ 🔖 1012 💰 g:4 ⚖  302|1018|556 ═══ α=-995 β=0 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 1022 💰 g:5 🎯 h:-1000 ⚖  303|1023|559 ═══ α=-995 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1020 🔖 1023 🔖 1021 🔖 1019 } 
 │  │  │  │  ├□═╤═ 🔖 1009 💰 g:4 ⚖  303|1023|559 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  ├■═╤═ 🔖 1026 💰 g:5 🎯 h:-1000 ⚖  304|1028|562 ═══ α=-995 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1027 🔖 1024 🔖 1025 🔖 1028 } 
 │  │  │  │  ├□═╤═ 🔖 1010 💰 g:4 ⚖  304|1028|562 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 1031 💰 g:5 🎯 h:-1000 ⚖  305|1033|563 ═══ α=-995 β=0 ═══ ⚡ a2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1032 🔖 1029 🔖 1030 🔖 1033 } 
 │  │  │  │  ├□═╤═ 🔖 1011 💰 g:4 ⚖  305|1033|563 ═══ α=-995 β=0 ═══ ⚡ a2
 │  │  │  │  │  ├■═╤═ 🔖 1034 💰 g:5 ⚖  306|1038|565 ═══ α=-995 β=0 ═══ ⚡ a1
 │  │  │  │  │  │  ├□═╤═ 🔖 1042 💰 g:6 ⚖  307|1042|566 ═══ α=-995 β=0 ═══ ⚡ b3 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1041 🔖 1040 🔖 1039 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 1037 💰 g:5 ⚖  307|1042|566 ═══ α=-995 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 1046 💰 g:6 ⚖  308|1046|568 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1049 💰 g:7 🎯 h:-993 ⚖  309|1049|569 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1048 🔖 1047 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 1045 💰 g:6 ⚖  309|1049|569 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1050 💰 g:7 ⚖  310|1052|570 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1051 💰 g:7 ⚖  310|1052|570 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1054 💰 g:8 ⚖  311|1054|571 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 1055 💰 g:9 ⚖  312|1055|571 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1053 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 1052 💰 g:7 ⚖  312|1055|571 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │     ├□═╤═ 🔖 1057 💰 g:8 ⚖  313|1057|571 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │     │  └■═╤═ 🔖 1058 💰 g:9 ⚖  314|1058|571 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │  │  │  │  │     │  ├■ 0
 │  │  │  │  │  │  │     ├□ 0 ─── 🪓 β(0) { 🔖 1056 } 
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1043 🔖 1044 } 
 │  │  │  │  │  ├■═╤═ 🔖 1038 💰 g:5 ⚖  314|1058|571 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  ├□═╤═ 🔖 1062 💰 g:6 ⚖  315|1062|575 ═══ α=-995 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1064 💰 g:7 🎯 h:-1000 ⚖  316|1065|576 ═══ α=-995 β=0 ═══ ⚡ b1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1063 🔖 1065 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 1061 💰 g:6 ⚖  316|1065|576 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1067 💰 g:7 🎯 h:-1000 ⚖  317|1068|577 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1066 🔖 1068 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 1060 💰 g:6 ⚖  317|1068|577 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1069 💰 g:7 ⚖  318|1071|578 ═══ α=-993 β=0 ═══ ⚡ a1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1073 💰 g:8 ⚖  319|1073|579 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 1074 💰 g:9 ⚖  320|1074|579 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 0
 │  │  │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1072 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1070 💰 g:7 ⚖  320|1074|579 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  └■═╤═ 🔖 1071 💰 g:7 ⚖  320|1074|579 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1059 } 
 │  │  │  │  │  ├■═╤═ 🔖 1035 💰 g:5 ⚖  320|1074|579 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 1078 💰 g:6 ⚖  321|1078|582 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1080 💰 g:7 ⚖  322|1081|582 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1083 💰 g:8 🎯 h:992 ⚖  323|1083|582 ═══ α=-995 β=0 ═══ ⚡ a3 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1082 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1081 💰 g:7 ⚖  323|1083|582 ═══ α=-995 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1085 💰 g:8 ⚖  324|1085|583 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1084 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  └■═╤═ 🔖 1079 💰 g:7 🎯 h:992 ⚖  324|1085|583 ═══ α=-995 β=0 ═══ ⚡ a1 ─── 💾 992
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1077 🔖 1075 🔖 1076 } 
 │  │  │  │  │  └■═╤═ 🔖 1036 💰 g:5 🎯 h:992 ⚖  324|1085|583 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 💾 992
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1008 } 
 │  │  │  ├■═╤═ 🔖 1006 💰 g:3 ⚖  324|1085|583 ═══ α=-1000 β=0 ═══ ⚡ a3
 │  │  │  │  ├□═╤═ 🔖 1091 💰 g:4 ⚖  325|1091|586 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 1092 💰 g:5 🎯 h:-991 ⚖  326|1096|589 ═══ α=-1000 β=0 ═══ ⚡ a1 ─── 💾 -991
 │  │  │  │  │  ├■ -991 → β
 │  │  │  │  │  ├■═╤═ 🔖 1095 💰 g:5 ⚖  326|1096|589 ═══ α=-1000 β=-991 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 1100 💰 g:6 ⚖  327|1100|593 ═══ α=-1000 β=-991 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1101 💰 g:7 🎯 h:-993 ⚖  328|1103|594 ═══ α=-1000 β=-991 ═══ ⚡ a1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1102 🔖 1103 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 1099 💰 g:6 ⚖  328|1103|594 ═══ α=-993 β=-991 ═══ ⚡ c1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1104 💰 g:7 🎯 h:-993 ⚖  329|1106|594 ═══ α=-993 β=-991 ═══ ⚡ a1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1106 🔖 1105 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 1098 💰 g:6 ⚖  329|1106|594 ═══ α=-993 β=-991 ═══ ⚡ b1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1107 💰 g:7 🎯 h:-993 ⚖  330|1109|594 ═══ α=-993 β=-991 ═══ ⚡ a1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1109 🔖 1108 } 
 │  │  │  │  │  │  └□═╤═ 🔖 1097 💰 g:6 ⚖  330|1109|594 ═══ α=-993 β=-991 ═══ ⚡ a1
 │  │  │  │  │  │     ├■═╤═ 🔖 1112 💰 g:7 🎯 h:-1000 ⚖  331|1112|597 ═══ α=-993 β=-991 ═══ ⚡ b2 ─── 🍃 -993
 │  │  │  │  │  │     ├■ -993 ─── ☖ 6 { 🔖 1111 🔖 1110 } 
 │  │  │  │  │  ├■ -993 → β
 │  │  │  │  │  ├■═╤═ 🔖 1094 💰 g:5 ⚖  331|1112|597 ═══ α=-1000 β=-993 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 1116 💰 g:6 ⚖  332|1116|599 ═══ α=-1000 β=-993 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1117 💰 g:7 ⚖  333|1119|599 ═══ α=-1000 β=-993 ═══ ⚡ a1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1120 💰 g:8 🎯 h:992 ⚖  334|1121|599 ═══ α=-1000 β=-993 ═══ ⚡ b1 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1121 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1118 💰 g:7 ⚖  334|1121|599 ═══ α=-1000 β=-993 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1122 💰 g:8 🎯 h:992 ⚖  335|1123|599 ═══ α=-1000 β=-993 ═══ ⚡ a1 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1123 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 1119 💰 g:7 ⚖  335|1123|599 ═══ α=-1000 β=-993 ═══ ⚡ a2
 │  │  │  │  │  │  │     ├□═╤═ 🔖 1125 💰 g:8 🎯 h:1000 ⚖  336|1125|601 ═══ α=-1000 β=-993 ═══ ⚡ b1 ─── 🍃 992
 │  │  │  │  │  │  │     ├□ 992 ─── ☗ 7 { 🔖 1124 } 
 │  │  │  │  │  │  ├□ 992 ─── 🪓 β(-993) { 🔖 1114 🔖 1113 🔖 1115 } 
 │  │  │  │  │  ├■═╤═ 🔖 1093 💰 g:5 ⚖  336|1125|601 ═══ α=-1000 β=-993 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 1129 💰 g:6 ⚖  337|1129|604 ═══ α=-1000 β=-993 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1130 💰 g:7 ⚖  338|1132|604 ═══ α=-1000 β=-993 ═══ ⚡ a1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1134 💰 g:8 🎯 h:-991 ⚖  339|1134|604 ═══ α=-1000 β=-993 ═══ ⚡ a2 ─── 💾 -991
 │  │  │  │  │  │  │  │  ├□ -991 ─── 🪓 β(-993) { 🔖 1133 } 
 │  │  │  │  │  │  │  ├■ -991
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1132 💰 g:7 ⚖  339|1134|604 ═══ α=-1000 β=-993 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1135 💰 g:8 🎯 h:1000 ⚖  340|1136|605 ═══ α=-1000 β=-993 ═══ ⚡ a1 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1136 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 1131 💰 g:7 🎯 h:992 ⚖  340|1136|605 ═══ α=-1000 β=-993 ═══ ⚡ c1 ─── 💾 992
 │  │  │  │  │  │  ├□ -991 ─── 🪓 β(-993) { 🔖 1128 🔖 1126 🔖 1127 } 
 │  │  │  │  │  └■═╤═ 🔖 1096 💰 g:5 ⚖  340|1136|605 ═══ α=-1000 β=-993 ═══ ⚡ b2
 │  │  │  │  │     ├□═╤═ 🔖 1137 💰 g:6 ⚖  341|1140|606 ═══ α=-1000 β=-993 ═══ ⚡ a1
 │  │  │  │  │     │  ├■═╤═ 🔖 1142 💰 g:7 🎯 h:-1000 ⚖  342|1143|608 ═══ α=-1000 β=-993 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │     │  ├■ -993 ─── ☖ 6 { 🔖 1143 🔖 1141 } 
 │  │  │  │  │     ├□ -993 ─── 🪓 β(-993) { 🔖 1139 🔖 1140 🔖 1138 } 
 │  │  │  │  ├□ -993 → α
 │  │  │  │  ├□═╤═ 🔖 1090 💰 g:4 ⚖  342|1143|608 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 1144 💰 g:5 ⚖  343|1148|609 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 1145 💰 g:5 ⚖  343|1148|609 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 1149 💰 g:6 🎯 h:1000 ⚖  344|1152|612 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1151 🔖 1150 🔖 1152 } 
 │  │  │  │  │  ├■═╤═ 🔖 1147 💰 g:5 ⚖  344|1152|612 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 1153 💰 g:6 🎯 h:1000 ⚖  345|1156|613 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1154 🔖 1155 🔖 1156 } 
 │  │  │  │  │  ├■═╤═ 🔖 1146 💰 g:5 🎯 h:994 ⚖  345|1156|613 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 994
 │  │  │  │  │  └■═╤═ 🔖 1148 💰 g:5 🎯 h:994 ⚖  345|1156|613 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1088 🔖 1089 🔖 1086 🔖 1087 } 
 │  │  │  ├■═╤═ 🔖 1004 💰 g:3 ⚖  345|1156|613 ═══ α=-1000 β=0 ═══ ⚡ a2
 │  │  │  │  ├□═╤═ 🔖 1162 💰 g:4 ⚖  346|1162|619 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 1166 💰 g:5 🎯 h:-995 ⚖  347|1167|620 ═══ α=-1000 β=0 ═══ ⚡ b2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1167 🔖 1164 🔖 1165 🔖 1163 } 
 │  │  │  │  ├□ -995 → α
 │  │  │  │  ├□═╤═ 🔖 1161 💰 g:4 ⚖  347|1167|620 ═══ α=-995 β=0 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 1171 💰 g:5 🎯 h:-995 ⚖  348|1172|622 ═══ α=-995 β=0 ═══ ⚡ b2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1169 🔖 1172 🔖 1170 🔖 1168 } 
 │  │  │  │  ├□═╤═ 🔖 1158 💰 g:4 ⚖  348|1172|622 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  ├■═╤═ 🔖 1175 💰 g:5 🎯 h:-995 ⚖  349|1177|624 ═══ α=-995 β=0 ═══ ⚡ b2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1176 🔖 1173 🔖 1174 🔖 1177 } 
 │  │  │  │  ├□═╤═ 🔖 1159 💰 g:4 ⚖  349|1177|624 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 1180 💰 g:5 🎯 h:-995 ⚖  350|1182|625 ═══ α=-995 β=0 ═══ ⚡ b2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1181 🔖 1178 🔖 1179 🔖 1182 } 
 │  │  │  │  ├□═╤═ 🔖 1160 💰 g:4 ⚖  350|1182|625 ═══ α=-995 β=0 ═══ ⚡ b2
 │  │  │  │  │  ├■═╤═ 🔖 1183 💰 g:5 ⚖  351|1187|627 ═══ α=-995 β=0 ═══ ⚡ a1
 │  │  │  │  │  │  ├□═╤═ 🔖 1190 💰 g:6 🎯 h:992 ⚖  352|1191|627 ═══ α=-995 β=0 ═══ ⚡ a3 ─── 💾 992
 │  │  │  │  │  │  ├□ 992 ─── 🪓 β(0) { 🔖 1191 🔖 1189 🔖 1188 } 
 │  │  │  │  │  ├■ 992
 │  │  │  │  │  ├■═╤═ 🔖 1187 💰 g:5 ⚖  352|1191|627 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  ├□═╤═ 🔖 1192 💰 g:6 🎯 h:1000 ⚖  353|1195|631 ═══ α=-995 β=0 ═══ ⚡ a1 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1194 🔖 1195 🔖 1193 } 
 │  │  │  │  │  ├■═╤═ 🔖 1184 💰 g:5 ⚖  353|1195|631 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 1196 💰 g:6 🎯 h:1000 ⚖  354|1199|634 ═══ α=-995 β=0 ═══ ⚡ a1 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1198 🔖 1199 🔖 1197 } 
 │  │  │  │  │  ├■═╤═ 🔖 1186 💰 g:5 🎯 h:994 ⚖  354|1199|634 ═══ α=-995 β=0 ═══ ⚡ a3 ─── 💾 994
 │  │  │  │  │  └■═╤═ 🔖 1185 💰 g:5 🎯 h:994 ⚖  354|1199|634 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 💾 994
 │  │  │  │  ├□ 992 ─── 🪓 β(0) { 🔖 1157 } 
 │  │  │  ├■═╤═ 🔖 1002 💰 g:3 ⚖  354|1199|634 ═══ α=-1000 β=0 ═══ ⚡ b1
 │  │  │  │  ├□═╤═ 🔖 1205 💰 g:4 ⚖  355|1205|640 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 1210 💰 g:5 🎯 h:-991 ⚖  356|1210|640 ═══ α=-1000 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 1211 💰 g:6 ⚖  357|1214|640 ═══ α=-1000 β=0 ═══ ⚡ a1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1216 💰 g:7 ⚖  358|1217|640 ═══ α=-1000 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1219 💰 g:8 🎯 h:992 ⚖  359|1219|641 ═══ α=-1000 β=0 ═══ ⚡ b2 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1218 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1217 💰 g:7 ⚖  359|1219|641 ═══ α=-1000 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1221 💰 g:8 ⚖  360|1221|642 ═══ α=-1000 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 1222 💰 g:9 🎯 h:-1000 ⚖  361|1222|643 ═══ α=-1000 β=0 ═══ ⚡ c1 ─── 🍃 -991
 │  │  │  │  │  │  │  │  │  ├■ -991
 │  │  │  │  │  │  │  │  ├□ -991 → α
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 1220 💰 g:8 ⚖  361|1222|643 ═══ α=-991 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │     └■═╤═ 🔖 1223 💰 g:9 🎯 h:-1000 ⚖  362|1223|644 ═══ α=-991 β=0 ═══ ⚡ a2 ─── 🍃 -991
 │  │  │  │  │  │  │  │     ├■ -991
 │  │  │  │  │  │  │  ├■ -991 → β
 │  │  │  │  │  │  │  └■═╤═ 🔖 1215 💰 g:7 🎯 h:992 ⚖  362|1223|644 ═══ α=-1000 β=-991 ═══ ⚡ c1 ─── 💾 992
 │  │  │  │  │  │  ├□ -991 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 1213 💰 g:6 ⚖  362|1223|644 ═══ α=-991 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1224 💰 g:7 ⚖  363|1226|644 ═══ α=-991 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1225 💰 g:7 ⚖  363|1226|644 ═══ α=-991 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1228 💰 g:8 ⚖  364|1228|644 ═══ α=-991 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 1229 💰 g:9 🎯 h:-991 ⚖  365|1229|644 ═══ α=-991 β=0 ═══ ⚡ a1 ─── 💾 -991
 │  │  │  │  │  │  │  │  │  ├■ -991
 │  │  │  │  │  │  │  │  ├□ -991
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 1227 💰 g:8 ⚖  365|1229|644 ═══ α=-991 β=0 ═══ ⚡ a1
 │  │  │  │  │  │  │  │     └■═╤═ 🔖 1230 💰 g:9 🎯 h:-991 ⚖  366|1230|644 ═══ α=-991 β=0 ═══ ⚡ b2 ─── 💾 -991
 │  │  │  │  │  │  │  │     ├■ -991
 │  │  │  │  │  │  │  ├■ -991 ─── 🪓 α(-991) { 🔖 1226 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 1214 💰 g:6 🎯 h:-991 ⚖  366|1230|644 ═══ α=-991 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1231 💰 g:7 🎯 h:-991 ⚖  367|1233|644 ═══ α=-991 β=0 ═══ ⚡ a1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1235 💰 g:8 🎯 h:-991 ⚖  368|1235|644 ═══ α=-991 β=0 ═══ ⚡ a2 ─── 💾 -991
 │  │  │  │  │  │  │  │  ├□ -991
 │  │  │  │  │  │  │  │  └□═╤═ 🔖 1234 💰 g:8 🎯 h:-991 ⚖  368|1235|644 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 -991
 │  │  │  │  │  │  │  ├■ -991 ─── 🪓 α(-991) { 🔖 1232 🔖 1233 } 
 │  │  │  │  │  │  └□═╤═ 🔖 1212 💰 g:6 🎯 h:-991 ⚖  368|1235|644 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 -991
 │  │  │  │  │  ├■ -991 → β
 │  │  │  │  │  ├■═╤═ 🔖 1209 💰 g:5 ⚖  368|1235|644 ═══ α=-1000 β=-991 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 1239 💰 g:6 🎯 h:1000 ⚖  369|1239|645 ═══ α=-1000 β=-991 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1238 🔖 1236 🔖 1237 } 
 │  │  │  │  │  ├■═╤═ 🔖 1208 💰 g:5 ⚖  369|1239|645 ═══ α=-1000 β=-991 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 1243 💰 g:6 🎯 h:1000 ⚖  370|1243|648 ═══ α=-1000 β=-991 ═══ ⚡ a3 ─── 🍃 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1242 🔖 1241 🔖 1240 } 
 │  │  │  │  │  ├■═╤═ 🔖 1207 💰 g:5 ⚖  370|1243|648 ═══ α=-1000 β=-991 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 1247 💰 g:6 🎯 h:994 ⚖  371|1247|648 ═══ α=-1000 β=-991 ═══ ⚡ a3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1244 🔖 1246 🔖 1245 } 
 │  │  │  │  │  └■═╤═ 🔖 1206 💰 g:5 🎯 h:994 ⚖  371|1247|648 ═══ α=-1000 β=-991 ═══ ⚡ a1 ─── 💾 994
 │  │  │  │  ├□ -991 → α
 │  │  │  │  ├□═╤═ 🔖 1204 💰 g:4 ⚖  371|1247|648 ═══ α=-991 β=0 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 1250 💰 g:5 ⚖  372|1252|648 ═══ α=-991 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 1256 💰 g:6 🎯 h:994 ⚖  373|1256|649 ═══ α=-991 β=0 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1255 🔖 1254 🔖 1253 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 1251 💰 g:5 ⚖  373|1256|649 ═══ α=-991 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  ├□═╤═ 🔖 1260 💰 g:6 🎯 h:994 ⚖  374|1260|651 ═══ α=-991 β=0 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1259 🔖 1258 🔖 1257 } 
 │  │  │  │  │  ├■═╤═ 🔖 1252 💰 g:5 ⚖  374|1260|651 ═══ α=-991 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  ├□═╤═ 🔖 1264 💰 g:6 ⚖  375|1264|652 ═══ α=-991 β=0 ═══ ⚡ b2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1267 💰 g:7 ⚖  376|1267|653 ═══ α=-991 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1269 💰 g:8 🎯 h:1000 ⚖  377|1269|654 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 🍃 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1268 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1266 💰 g:7 🎯 h:992 ⚖  377|1269|654 ═══ α=-991 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1270 💰 g:8 🎯 h:992 ⚖  378|1271|654 ═══ α=-991 β=0 ═══ ⚡ a1 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1271 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 1265 💰 g:7 🎯 h:992 ⚖  378|1271|654 ═══ α=-991 β=0 ═══ ⚡ a1 ─── 💾 992
 │  │  │  │  │  │  ├□ 992 ─── 🪓 β(0) { 🔖 1263 🔖 1262 🔖 1261 } 
 │  │  │  │  │  ├■ 992
 │  │  │  │  │  ├■═╤═ 🔖 1249 💰 g:5 🎯 h:994 ⚖  378|1271|654 ═══ α=-991 β=0 ═══ ⚡ c1 ─── 💾 994
 │  │  │  │  │  └■═╤═ 🔖 1248 💰 g:5 🎯 h:994 ⚖  378|1271|654 ═══ α=-991 β=0 ═══ ⚡ a1 ─── 💾 994
 │  │  │  │  ├□ 992 ─── 🪓 β(0) { 🔖 1201 🔖 1202 🔖 1203 🔖 1200 } 
 │  │  │  ├■═╤═ 🔖 1003 💰 g:3 ⚖  378|1271|654 ═══ α=-1000 β=0 ═══ ⚡ c1
 │  │  │  │  ├□═╤═ 🔖 1276 💰 g:4 🎯 h:992 ⚖  379|1277|657 ═══ α=-1000 β=0 ═══ ⚡ a3 ─── 💾 992
 │  │  │  │  ├□ 992 ─── 🪓 β(0) { 🔖 1277 🔖 1273 🔖 1274 🔖 1275 🔖 1272 } 
 │  │  │  └■═╤═ 🔖 1007 💰 g:3 ⚖  379|1277|657 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │     ├□═╤═ 🔖 1283 💰 g:4 ⚖  380|1283|660 ═══ α=-1000 β=0 ═══ ⚡ a3
 │  │  │     │  ├■═╤═ 🔖 1284 💰 g:5 ⚖  381|1288|660 ═══ α=-1000 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │     │  ├■ 0
 │  │  │     │  ├■═╤═ 🔖 1287 💰 g:5 ⚖  381|1288|660 ═══ α=-1000 β=0 ═══ ⚡ a2
 │  │  │     │  │  ├□═╤═ 🔖 1292 💰 g:6 ⚖  382|1292|661 ═══ α=-1000 β=0 ═══ ⚡ b2
 │  │  │     │  │  │  ├■═╤═ 🔖 1293 💰 g:7 🎯 h:992 ⚖  383|1295|661 ═══ α=-1000 β=0 ═══ ⚡ a1 ─── 💾 992
 │  │  │     │  │  │  ├■ 992
 │  │  │     │  │  │  ├■═╤═ 🔖 1294 💰 g:7 🎯 h:992 ⚖  383|1295|661 ═══ α=-1000 β=0 ═══ ⚡ b1 ─── 💾 992
 │  │  │     │  │  │  └■═╤═ 🔖 1295 💰 g:7 🎯 h:992 ⚖  383|1295|661 ═══ α=-1000 β=0 ═══ ⚡ c1 ─── 💾 992
 │  │  │     │  │  ├□ 992 ─── 🪓 β(0) { 🔖 1291 🔖 1290 🔖 1289 } 
 │  │  │     │  ├■═╤═ 🔖 1288 💰 g:5 ⚖  383|1295|661 ═══ α=-1000 β=0 ═══ ⚡ b2
 │  │  │     │  │  ├□═╤═ 🔖 1296 💰 g:6 ⚖  384|1299|662 ═══ α=-1000 β=0 ═══ ⚡ a1
 │  │  │     │  │  │  ├■═╤═ 🔖 1300 💰 g:7 🎯 h:-1000 ⚖  385|1302|664 ═══ α=-1000 β=0 ═══ ⚡ b1 ─── 🍃 -993
 │  │  │     │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1302 🔖 1301 } 
 │  │  │     │  │  ├□ -993 → α
 │  │  │     │  │  ├□═╤═ 🔖 1298 💰 g:6 ⚖  385|1302|664 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │     │  │  │  ├■═╤═ 🔖 1304 💰 g:7 🎯 h:-1000 ⚖  386|1305|664 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 🍃 -993
 │  │  │     │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1305 🔖 1303 } 
 │  │  │     │  │  ├□═╤═ 🔖 1299 💰 g:6 🎯 h:-993 ⚖  386|1305|664 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 -993
 │  │  │     │  │  └□═╤═ 🔖 1297 💰 g:6 🎯 h:-993 ⚖  386|1305|664 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 -993
 │  │  │     │  ├■ -993 → β
 │  │  │     │  ├■═╤═ 🔖 1285 💰 g:5 🎯 h:992 ⚖  386|1305|664 ═══ α=-1000 β=-993 ═══ ⚡ b1 ─── 💾 992
 │  │  │     │  └■═╤═ 🔖 1286 💰 g:5 🎯 h:992 ⚖  386|1305|664 ═══ α=-1000 β=-993 ═══ ⚡ c1 ─── 💾 992
 │  │  │     ├□ -993 → α
 │  │  │     ├□═╤═ 🔖 1282 💰 g:4 ⚖  386|1305|664 ═══ α=-993 β=0 ═══ ⚡ b2
 │  │  │     │  ├■═╤═ 🔖 1306 💰 g:5 ⚖  387|1310|664 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 💾 0
 │  │  │     │  ├■ 0
 │  │  │     │  ├■═╤═ 🔖 1309 💰 g:5 🎯 h:994 ⚖  387|1310|664 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 994
 │  │  │     │  ├■═╤═ 🔖 1308 💰 g:5 🎯 h:994 ⚖  387|1310|664 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 994
 │  │  │     │  ├■═╤═ 🔖 1307 💰 g:5 🎯 h:994 ⚖  387|1310|664 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 994
 │  │  │     │  └■═╤═ 🔖 1310 💰 g:5 🎯 h:994 ⚖  387|1310|664 ═══ α=-993 β=0 ═══ ⚡ a3 ─── 💾 994
 │  │  │     ├□ 0 ─── 🪓 β(0) { 🔖 1279 🔖 1280 🔖 1281 🔖 1278 } 
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 999 🔖 994 🔖 995 🔖 996 🔖 997 🔖 998 🔖 993 } 
 │  ├■═╤═ 🔖 8 💰 g:1 ⚖  387|1310|664 ═══ α=-1000 β=0 ═══ ⚡ b3 ─── 💾 0
 │  ├■═╤═ 🔖 5 💰 g:1 ⚖  387|1310|664 ═══ α=-1000 β=0 ═══ ⚡ b2
 │  │  ├□═╤═ 🔖 1318 💰 g:2 ⚖  388|1318|666 ═══ α=-1000 β=0 ═══ ⚡ c3
 │  │  │  ├■═╤═ 🔖 1319 💰 g:3 🎯 h:-993 ⚖  389|1325|667 ═══ α=-1000 β=0 ═══ ⚡ a1
 │  │  │  │  ├□═╤═ 🔖 1326 💰 g:4 ⚖  390|1331|667 ═══ α=-1000 β=0 ═══ ⚡ b1
 │  │  │  │  │  ├■═╤═ 🔖 1332 💰 g:5 ⚖  391|1336|667 ═══ α=-1000 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 1335 💰 g:5 ⚖  391|1336|667 ═══ α=-1000 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 1340 💰 g:6 ⚖  392|1340|667 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1341 💰 g:7 🎯 h:-1000 ⚖  393|1343|669 ═══ α=-1000 β=0 ═══ ⚡ c1 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1342 🔖 1343 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 1339 💰 g:6 ⚖  393|1343|669 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1345 💰 g:7 🎯 h:-1000 ⚖  394|1346|670 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1344 🔖 1346 } 
 │  │  │  │  │  │  ├□═╤═ 🔖 1338 💰 g:6 ⚖  394|1346|670 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1347 💰 g:7 🎯 h:-993 ⚖  395|1349|670 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1348 🔖 1349 } 
 │  │  │  │  │  │  └□═╤═ 🔖 1337 💰 g:6 ⚖  395|1349|670 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │     ├■═╤═ 🔖 1350 💰 g:7 🎯 h:-1000 ⚖  396|1352|671 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 🍃 -993
 │  │  │  │  │  │     ├■ -993 ─── ☖ 6 { 🔖 1351 🔖 1352 } 
 │  │  │  │  │  ├■ -993 → β
 │  │  │  │  │  ├■═╤═ 🔖 1334 💰 g:5 ⚖  396|1352|671 ═══ α=-1000 β=-993 ═══ ⚡ c2
 │  │  │  │  │  │  ├□═╤═ 🔖 1354 💰 g:6 ⚖  397|1356|671 ═══ α=-1000 β=-993 ═══ ⚡ a2
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1357 💰 g:7 ⚖  398|1359|671 ═══ α=-1000 β=-993 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1358 💰 g:7 ⚖  398|1359|671 ═══ α=-1000 β=-993 ═══ ⚡ a3 ─── 💾 0
 │  │  │  │  │  │  │  └■═╤═ 🔖 1359 💰 g:7 ⚖  398|1359|671 ═══ α=-1000 β=-993 ═══ ⚡ b3 ─── 💾 0
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(-993) { 🔖 1355 🔖 1356 🔖 1353 } 
 │  │  │  │  │  ├■═╤═ 🔖 1333 💰 g:5 ⚖  398|1359|671 ═══ α=-1000 β=-993 ═══ ⚡ a2
 │  │  │  │  │  │  ├□═╤═ 🔖 1363 💰 g:6 ⚖  399|1363|672 ═══ α=-1000 β=-993 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1366 💰 g:7 🎯 h:-1000 ⚖  400|1366|672 ═══ α=-1000 β=-993 ═══ ⚡ a3 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1365 🔖 1364 } 
 │  │  │  │  │  │  ├□ -993 ─── 🪓 β(-993) { 🔖 1362 🔖 1361 🔖 1360 } 
 │  │  │  │  │  └■═╤═ 🔖 1336 💰 g:5 ⚖  400|1366|672 ═══ α=-1000 β=-993 ═══ ⚡ b3 ─── 💾 0
 │  │  │  │  ├□ -993 → α
 │  │  │  │  ├□═╤═ 🔖 1330 💰 g:4 ⚖  400|1366|672 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  ├■═╤═ 🔖 1367 💰 g:5 ⚖  401|1371|672 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 1375 💰 g:6 🎯 h:994 ⚖  402|1375|672 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1374 🔖 1373 🔖 1372 } 
 │  │  │  │  │  ├■ 994
 │  │  │  │  │  ├■═╤═ 🔖 1371 💰 g:5 ⚖  402|1375|672 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  ├□═╤═ 🔖 1376 💰 g:6 ⚖  403|1379|672 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1380 💰 g:7 ⚖  404|1382|672 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1381 💰 g:7 ⚖  404|1382|672 ═══ α=-993 β=0 ═══ ⚡ a2
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1384 💰 g:8 ⚖  405|1384|672 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │  │  │  └■═╤═ 🔖 1385 💰 g:9 ⚖  406|1385|672 ═══ α=-993 β=0 ═══ ⚡ c1 ─── 🍃 0
 │  │  │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1383 } 
 │  │  │  │  │  │  │  └■═╤═ 🔖 1382 💰 g:7 ⚖  406|1385|672 ═══ α=-993 β=0 ═══ ⚡ c2
 │  │  │  │  │  │  │     ├□═╤═ 🔖 1387 💰 g:8 ⚖  407|1387|672 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 0
 │  │  │  │  │  │  │     ├□ 0 ─── 🪓 β(0) { 🔖 1386 } 
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1378 🔖 1379 🔖 1377 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 1368 💰 g:5 ⚖  407|1387|672 ═══ α=-993 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 1391 💰 g:6 🎯 h:994 ⚖  408|1391|672 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1388 🔖 1390 🔖 1389 } 
 │  │  │  │  │  ├■═╤═ 🔖 1370 💰 g:5 🎯 h:994 ⚖  408|1391|672 ═══ α=-993 β=0 ═══ ⚡ c2 ─── 💾 994
 │  │  │  │  │  └■═╤═ 🔖 1369 💰 g:5 🎯 h:994 ⚖  408|1391|672 ═══ α=-993 β=0 ═══ ⚡ a2 ─── 💾 994
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1327 🔖 1328 🔖 1329 🔖 1331 } 
 │  │  │  ├■ 0
 │  │  │  ├■═╤═ 🔖 1323 💰 g:3 ⚖  408|1391|672 ═══ α=-1000 β=0 ═══ ⚡ c2 ─── 💾 0
 │  │  │  ├■═╤═ 🔖 1324 💰 g:3 ⚖  408|1391|672 ═══ α=-1000 β=0 ═══ ⚡ a3
 │  │  │  │  ├□═╤═ 🔖 1397 💰 g:4 ⚖  409|1397|677 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 1400 💰 g:5 🎯 h:-1000 ⚖  410|1402|680 ═══ α=-1000 β=0 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1398 🔖 1402 🔖 1399 🔖 1401 } 
 │  │  │  │  ├□ -995 → α
 │  │  │  │  ├□═╤═ 🔖 1396 💰 g:4 ⚖  410|1402|680 ═══ α=-995 β=0 ═══ ⚡ c2
 │  │  │  │  │  ├■═╤═ 🔖 1405 💰 g:5 🎯 h:-995 ⚖  411|1407|680 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1406 🔖 1407 🔖 1404 🔖 1403 } 
 │  │  │  │  ├□═╤═ 🔖 1393 💰 g:4 ⚖  411|1407|680 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  ├■═╤═ 🔖 1409 💰 g:5 🎯 h:-1000 ⚖  412|1412|682 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1408 🔖 1411 🔖 1410 🔖 1412 } 
 │  │  │  │  ├□═╤═ 🔖 1394 💰 g:4 ⚖  412|1412|682 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1395 🔖 1392 } 
 │  │  │  ├■═╤═ 🔖 1322 💰 g:3 ⚖  412|1412|682 ═══ α=-1000 β=0 ═══ ⚡ a2
 │  │  │  │  ├□═╤═ 🔖 1418 💰 g:4 ⚖  413|1418|687 ═══ α=-1000 β=0 ═══ ⚡ b3
 │  │  │  │  │  ├■═╤═ 🔖 1422 💰 g:5 🎯 h:-995 ⚖  414|1423|688 ═══ α=-1000 β=0 ═══ ⚡ c2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1420 🔖 1423 🔖 1421 🔖 1419 } 
 │  │  │  │  ├□ -995 → α
 │  │  │  │  ├□═╤═ 🔖 1414 💰 g:4 ⚖  414|1423|688 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  ├■═╤═ 🔖 1426 💰 g:5 🎯 h:-995 ⚖  415|1428|689 ═══ α=-995 β=0 ═══ ⚡ c2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1424 🔖 1427 🔖 1425 🔖 1428 } 
 │  │  │  │  ├□═╤═ 🔖 1415 💰 g:4 ⚖  415|1428|689 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  ├■═╤═ 🔖 1431 💰 g:5 🎯 h:-995 ⚖  416|1433|689 ═══ α=-995 β=0 ═══ ⚡ c2 ─── 💾 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1432 🔖 1429 🔖 1430 🔖 1433 } 
 │  │  │  │  ├□═╤═ 🔖 1413 💰 g:4 ⚖  416|1433|689 ═══ α=-995 β=0 ═══ ⚡ a1
 │  │  │  │  │  ├■═╤═ 🔖 1436 💰 g:5 🎯 h:-1000 ⚖  417|1438|694 ═══ α=-995 β=0 ═══ ⚡ c2 ─── 🍃 -995
 │  │  │  │  │  ├■ -995 ─── ☖ 4 { 🔖 1437 🔖 1434 🔖 1435 🔖 1438 } 
 │  │  │  │  ├□═╤═ 🔖 1416 💰 g:4 ⚖  417|1438|694 ═══ α=-995 β=0 ═══ ⚡ c2
 │  │  │  │  │  ├■═╤═ 🔖 1441 💰 g:5 ⚖  418|1443|694 ═══ α=-995 β=0 ═══ ⚡ c1
 │  │  │  │  │  │  ├□═╤═ 🔖 1447 💰 g:6 ⚖  419|1447|695 ═══ α=-995 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1450 💰 g:7 🎯 h:-1000 ⚖  420|1450|696 ═══ α=-995 β=0 ═══ ⚡ a3 ─── 🍃 -993
 │  │  │  │  │  │  │  ├■ -993 ─── ☖ 6 { 🔖 1449 🔖 1448 } 
 │  │  │  │  │  │  ├□ -993 → α
 │  │  │  │  │  │  ├□═╤═ 🔖 1446 💰 g:6 ⚖  420|1450|696 ═══ α=-993 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1452 💰 g:7 ⚖  421|1453|696 ═══ α=-993 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1455 💰 g:8 🎯 h:992 ⚖  422|1455|697 ═══ α=-993 β=0 ═══ ⚡ b3 ─── 💾 992
 │  │  │  │  │  │  │  │  ├□ 992 ─── ☗ 7 { 🔖 1454 } 
 │  │  │  │  │  │  │  ├■ 992
 │  │  │  │  │  │  │  ├■═╤═ 🔖 1453 💰 g:7 ⚖  422|1455|697 ═══ α=-993 β=0 ═══ ⚡ b3
 │  │  │  │  │  │  │  │  ├□═╤═ 🔖 1457 💰 g:8 ⚖  423|1457|697 ═══ α=-993 β=0 ═══ ⚡ b1 ─── 💾 0
 │  │  │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1456 } 
 │  │  │  │  │  │  │  ├■ 0
 │  │  │  │  │  │  │  └■═╤═ 🔖 1451 💰 g:7 🎯 h:992 ⚖  423|1457|697 ═══ α=-993 β=0 ═══ ⚡ a1 ─── 💾 992
 │  │  │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1445 🔖 1444 } 
 │  │  │  │  │  ├■ 0
 │  │  │  │  │  ├■═╤═ 🔖 1440 💰 g:5 ⚖  423|1457|697 ═══ α=-995 β=0 ═══ ⚡ b1
 │  │  │  │  │  │  ├□═╤═ 🔖 1459 💰 g:6 🎯 h:994 ⚖  424|1461|698 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1460 🔖 1461 🔖 1458 } 
 │  │  │  │  │  ├■═╤═ 🔖 1442 💰 g:5 ⚖  424|1461|698 ═══ α=-995 β=0 ═══ ⚡ a3
 │  │  │  │  │  │  ├□═╤═ 🔖 1464 💰 g:6 🎯 h:994 ⚖  425|1465|700 ═══ α=-995 β=0 ═══ ⚡ c1 ─── 💾 994
 │  │  │  │  │  │  ├□ 994 ─── ☗ 5 { 🔖 1465 🔖 1463 🔖 1462 } 
 │  │  │  │  │  ├■═╤═ 🔖 1439 💰 g:5 🎯 h:994 ⚖  425|1465|700 ═══ α=-995 β=0 ═══ ⚡ a1 ─── 💾 994
 │  │  │  │  │  └■═╤═ 🔖 1443 💰 g:5 🎯 h:994 ⚖  425|1465|700 ═══ α=-995 β=0 ═══ ⚡ b3 ─── 💾 994
 │  │  │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1417 } 
 │  │  │  ├■═╤═ 🔖 1320 💰 g:3 ⚖  425|1465|700 ═══ α=-1000 β=0 ═══ ⚡ b1 ─── 💾 0
 │  │  │  ├■═╤═ 🔖 1321 💰 g:3 ⚖  425|1465|700 ═══ α=-1000 β=0 ═══ ⚡ c1 ─── 💾 0
 │  │  │  └■═╤═ 🔖 1325 💰 g:3 ⚖  425|1465|700 ═══ α=-1000 β=0 ═══ ⚡ b3 ─── 💾 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 1317 🔖 1312 🔖 1313 🔖 1314 🔖 1315 🔖 1316 🔖 1311 } 
 │  ├■═╤═ 🔖 3 💰 g:1 ⚖  425|1465|700 ═══ α=-1000 β=0 ═══ ⚡ c1 ─── 💾 0
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  425|1465|700 ═══ α=-1000 β=0 ═══ ⚡ b1 ─── 💾 0
 │  ├■═╤═ 🔖 4 💰 g:1 ⚖  425|1465|700 ═══ α=-1000 β=0 ═══ ⚡ a2 ─── 💾 0
 │  └■═╤═ 🔖 9 💰 g:1 ⚖  425|1465|700 ═══ α=-1000 β=0 ═══ ⚡ c3 ─── 💾 0
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>2 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>20 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0
═╧═ 🏁  Execução terminada ⏱   16ms  ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> PASSOS | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 20
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
 │   A B C
 │ 1 x . . 1 
 │ 2 . . . 2 
 │ 3 . . . 3 
 │   A B C
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 16 | <span style="color:gray">I3(Iterações):</span> 700 | <span style="color:gray">I4(IND_EXPANSOES):</span> 425 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 1465 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

</details>

O problema sendo pequeno, não faz sentido fazer uma heurística.

\anchor jdg-a6
## Ação 6 - Testes Empíricos

Embora a estratégia de jogo seja fácil de obter, vamos simular um torneio para demonstrar a possibilidade de
comparar parâmetros distintos.

O único parâmetro que faz diferença, atendendo a que os tempos de execução são muito rápidos, é a profundidade da procura.
Vamos colocar em competição várias configurações a diferentes profundidades, e pretendemos conseguir observar
maior desempenho nas procuras de maior profundidade.

Temos também de ter o cuidado de desligar a utilização das hashtables, 
para observer sem perturbações o ganho da profundidade.

Insira: 
- **1; 7; P1=1 P2=4 P12=0 P7=20,7,5,3; -1; *ENTER*.**

Apagamos a configuração 1 dado que tinha o valor de omissão P7=0.

\htmlonly
<pre>
Opção: <span class="entrada">7</span>
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>0 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─  ⭐ atual
═╧═══════════════════
┌─ 📖 Sintaxe comando ──────────────────────────────────────────────────
│    id / -id <span style="color:gray">- Seleciona configuração como atual ou apaga 'id'</span>
│    Pk = <conj.> <span style="color:gray">- Varia Pk na configuração atual (gera N configs)</span>
│    Pk = <conj.> x Pw = <conj.> <span style="color:gray">- produto externo (gera NxM configs)</span>
│  <span style="color:gray">Sintaxe de <conj.> :</span> A,B,C | A:B | A:B:C                   
└──────────────────────────────────────────────────────────────────────
✏️ Comando: <span class="entrada">P1=1 P2=4 P12=0 P7=20,7,5,3</span>
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P7=</span>0 ⭐ atual
 ├─ ⚙  [2] ─ <span style="color:gray">P7=</span>3
 ├─ ⚙  [3] ─ <span style="color:gray">P7=</span>5
 ├─ ⚙  [4] ─ <span style="color:gray">P7=</span>7
 ├─ ⚙  [5] ─ <span style="color:gray">P7=</span>20
═╧═══════════════════
┌─ 📖 Sintaxe comando ──────────────────────────────────────────────────
│    id / -id <span style="color:gray">- Seleciona configuração como atual ou apaga 'id'</span>
│    Pk = <conj.> <span style="color:gray">- Varia Pk na configuração atual (gera N configs)</span>
│    Pk = <conj.> x Pw = <conj.> <span style="color:gray">- produto externo (gera NxM configs)</span>
│  <span style="color:gray">Sintaxe de <conj.> :</span> A,B,C | A:B | A:B:C                   
└──────────────────────────────────────────────────────────────────────
✏️ Comando: <span class="entrada">-1</span>
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P7=</span>3 ⭐ atual
 ├─ ⚙  [2] ─ <span style="color:gray">P7=</span>5
 ├─ ⚙  [3] ─ <span style="color:gray">P7=</span>7
 ├─ ⚙  [4] ─ <span style="color:gray">P7=</span>20
═╧═══════════════════
...
</pre>
\endhtmlonly

Temos 4 configurações. Como a procura é adversa, é necessário duas configurações, ou seja, jogos entre configurações para avaliar.
Assim, em vez da tabela com desempenho individual, há jogos entre todas as configurações, e reportado apenas a tabela de torneio final.

Podemos ainda ver as soluções, que aqui equivale a observar os jogos. 
Como são 4 configurações haverá grande quantidade de jogos, de todos contra todos e de ambas as cores. 
Por outro lado os jogos são muito rápidos. Assim, não vamos querer ver os jogos.
Se existissem vários tabuleiros iniciais, ou vários tamanhos, ou seja, instâncias de jogo, podiamos indicar as instâncias a serem utilizadas. 

Insira: **8; 1; *ENTER*.**

\htmlonly
<pre>
Opção: <span class="entrada">8</span>
┌─ 📖 Sintaxe comando ────────────────────
│  <span style="color:gray">Instâncias:</span> A,B,C | A:B | A : B : C
└────────────────────────────────────────
📄  IDs das instâncias (1 a 1): <span class="entrada">1</span>
🗎  Ficheiro resultados (nada para mostrar no ecrã): <span class="entrada">↵</span>
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P7=</span>3
 ├─ ⚙  [2] ─ <span style="color:gray">P7=</span>5
 ├─ ⚙  [3] ─ <span style="color:gray">P7=</span>7
 ├─ ⚙  [4] ─ <span style="color:gray">P7=</span>20
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:12   📄 Instâncias: 1   🛠️ Configurações: 4   🖥️ Processos: 1.
 ├─ ⏱                 📋 1     📄 1     🛠️ 1     🛠️ 2     🖥️ 1     a1 b1 c1 b2 b3 a2 c2 c3 a3🟰 
 ├─ ⏱ 1ms             📋 2     📄 1     🛠️ 1     🛠️ 3     🖥️ 1     a1 b2 b1 c1 a3 a2 c2 b3 c3🟰 
 ├─ ⏱ 8ms             📋 3     📄 1     🛠️ 1     🛠️ 4     🖥️ 1     a1 b2 b1 c1 a3 a2 c2 b3 c3🟰 
 ├─ ⏱ 34ms            📋 4     📄 1     🛠️ 2     🛠️ 1     🖥️ 1     a1 b1 c1 a2 b2 c2 a3 🏆 ☖ 
 ├─ ⏱ 35ms            📋 5     📄 1     🛠️ 2     🛠️ 3     🖥️ 1     a1 b2 b1 c1 a3 a2 c2 b3 c3🟰 
 ├─ ⏱ 42ms            📋 6     📄 1     🛠️ 2     🛠️ 4     🖥️ 1     a1 b2 b1 c1 a3 a2 c2 b3 c3🟰 
 ├─ ⏱ 64ms            📋 7     📄 1     🛠️ 3     🛠️ 1     🖥️ 1     a1 b1 a2 a3 b2 c1 c2 🏆 ☖ 
 ├─ ⏱ 96ms            📋 8     📄 1     🛠️ 3     🛠️ 2     🖥️ 1     a1 b1 a2 a3 b2 c1 c2 🏆 ☖ 
 ├─ ⏱ 138ms           📋 9     📄 1     🛠️ 3     🛠️ 4     🖥️ 1     a1 b2 b1 c1 a3 a2 c2 b3 c3🟰 
 ├─ ⏱ 166ms           📋 10    📄 1     🛠️ 4     🛠️ 1     🖥️ 1     a1 b1 a2 a3 b2 c1 c2 🏆 ☖ 
 ├─ ⏱ 323ms           📋 11    📄 1     🛠️ 4     🛠️ 2     🖥️ 1     a1 b1 a2 a3 b2 c1 c2 🏆 ☖ 
 ├─ ⏱ 450ms           📋 12    📄 1     🛠️ 4     🛠️ 3     🖥️ 1     a1 b2 b1 c1 a3 a2 c2 b3 c3🟰 
🏆  Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|
 1    |  0 |  0 |  0 | -3
 |----|----|----|----|
 2  1 |    |  0 |  0 | -1
 |----|----|----|----|
 3  1 |  1 |    |  0 |  2
 |----|----|----|----|
 4  1 |  1 |  0 |    |  2
 |----|----|----|----|
 │ Tempos: 0.000s 0.006s 0.105s 0.469s 
┌─ ⚙ 🛠️  ─────────────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 0 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
┌─ ⚙ ⚙  [1] ──────────────────────────────────────────────────────────
│ <span style="color:gray">P7(LIMITE):</span> 3
└──────────────────────────────────────────────────────────────────────
┌─ ⚙ ⚙  [2] ──────────────────────────────────────────────────────────
│ <span style="color:gray">P7(LIMITE):</span> 5
└──────────────────────────────────────────────────────────────────────
┌─ ⚙ ⚙  [3] ──────────────────────────────────────────────────────────
│ <span style="color:gray">P7(LIMITE):</span> 7
└──────────────────────────────────────────────────────────────────────
┌─ ⚙ ⚙  [4] ──────────────────────────────────────────────────────────
│ <span style="color:gray">P7(LIMITE):</span> 20
└──────────────────────────────────────────────────────────────────────
═╧═══════════════════
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 581ms ) ═══
Jogo do Galo
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 0 | <span style="color:gray">P13(PODA_HEURISTICA):</span> 0
│ <span style="color:gray">P14(PODA_CEGA):</span> 0
└──────────────────────────────────────────────────────────────────────
  A B C
1 . . . 1 
2 . . . 2 
3 . . . 3 
  A B C
...
Opção: 
</pre>
\endhtmlonly

Podemos ver os resultados dos jogos, seguido do torneio, em que as duas primeiras configurações com nível 20 e 7 
são igualmente boas.
Assim, é suficiente procura em profundidade 7 para obter a estratégia vencedora. 
As restantes configurações, à medida que se reduz o nível de profundidade, a qualidade baixa, como seria de esperar.

Notar na informação da linha com os tempos: "Tempos: 0.000s 0.006s 0.105s 0.469s"
Estes tempos são o tempo total de jogo de cada configuração, para todos os jogos. 
Profundidades maiores o tempo é superior.

Vamos ver o resultado deste mesmo torneio em ficheiro CSV.
Insira: **8; 1; Resultados/Galo; 0.**

O ficheiro fica com duas tabelas, a primeira com o resultado dos jogos, duas linhas por cada jogo:

| Jogador | Adversário | Cor | Resultado |
|:---:|:---:|:---:|:---:|
| 0 | 1 | Brancas | 0 |
| 1 | 0 | Pretas | 0 |
| 0 | 2 | Brancas | 0 |
| 2 | 0 | Pretas | 0 |
| 0 | 3 | Brancas | 0 |
| 3 | 0 | Pretas | 0 |
| 1 | 0 | Brancas | 1 |
| 0 | 1 | Pretas | -1 |
| 1 | 2 | Brancas | 0 |
| 2 | 1 | Pretas | 0 |
| 1 | 3 | Brancas | 0 |
| 3 | 1 | Pretas | 0 |
| 2 | 0 | Brancas | 1 |
| 0 | 2 | Pretas | -1 |
| 2 | 1 | Brancas | 1 |
| 1 | 2 | Pretas | -1 |
| 2 | 3 | Brancas | 0 |
| 3 | 2 | Pretas | 0 |
| 3 | 0 | Brancas | 1 |
| 0 | 3 | Pretas | -1 |
| 3 | 1 | Brancas | 1 |
| 1 | 3 | Pretas | -1 |
| 3 | 2 | Brancas | 0 |
| 2 | 3 | Pretas | 0 |

Com esta tabela, pode-se fazer o relatório dinâmico com os resultados do torneio, colocando:
- linhas: Jogador
- colunas: Adversário
- valores: Resultado
- Filtro: Cor=Brancas

| Rótulos de Linha | 0 | 1 | 2 | 3 | Total Geral |
|:---:|:---:|:---:|:---:|:---:|:---:|
|   | 0 | 0 | 0 | 0 | 0 |
| 1 |   | 1 | 0 | 0 | 1 |
| 2 | 1 |   | 1 | 0 | 2 |
| 3 | 1 | 1 |   | 0 | 2 |
| Total Geral | 3 | 2 | 0 | 0 | 5 |

O filtro é necessário para que cada jogo conte uma só vez. Cada jogo está em duas linhas.
Existindo várias instâncias, haverá sempre duas linhas por cada confronto A vs B, com o somatório do resultado em todas as instâncias.

Podemos fazer outras tabelas, como o resultado dos jogos por cor:

| Rótulos de Linha (Jogador) | Brancas | Pretas | Total Geral |
|:---:|:---:|:---:|:---:|
| 0 | 0 | -3 | -3 |
| 1 | 1 | -2 | -1 |
| 2 | 2 | 0 | 2 |
| 3 | 2 | 0 | 2 |
| Total Geral | 5 | -5 | 0 |

Podemos ver que os jogadores mais fortes ganharam quando estavam de brancas, e o inverso também, os jogadores
mais fracos só perderam quando estavam de pretas. 
Em termos de jogadores, o jogador 2 e 3 têm os mesmos pontos, pelo que podem ser considerados de força idêntica.

Podemos confirmar que os jogos entre jogadores mais fortes ficaram empatados, ao filtrar a tabela anterior por jogador/adversário 2 ou 3:

| Rótulos de Linha | Brancas | Pretas | Total Geral |
|:---:|:---:|:---:|:---:|
| 2 | 0 | 0 | 0 |
| 3 | 0 | 0 | 0 |
| Total Geral | 0 | 0 | 0 |

Sem o filtro para o Adversário ser 2 ou 3, iriamos obter a pontuação dos jogadores mais fortes, em conjunto com 
os mais fracos, o que poderia medir a eficiência de um jogador a lidar com mais fracos. 
Para saber se um jogador é mais forte que outro, apenas os confrontos entre ambos devem ser utilizados, o chamado match.

A segunda tabela no ficheiro CSV tem as configurações de cada jogador.

| Jogador | P1(Algoritmo) | P2(Debug) | P3(Seed) | P4(Tempo) | P5(Iterações) | P6(Ver) | P7(Limite) | P8(Repetidos) | P9(pesoAStar) | P10(ruido) | P11(baralhar) | P12(Ordenar) | P13(PodaHeuristica) | P14(PodaCega) |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 3 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 1 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 5 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 2 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 7 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 3 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 20 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |

Assim, mantemos a informação completa no ficheiro de resultados, mesmo em torneios, para que se detecte algum erro na configuração, 
e se possa saber exatamente como os resultados foram obtidos.

Como seria de esperar, este ficheiro de resultados poderia ser obtido também em linha de comandos:

\htmlonly
<pre>
PS ...\Teste> TProcuraAdversa 1 -R Resultados/Galo -P P1=1 P12=0 P7=20,7,5,3
</pre>

\endhtmlonly

A linha de comandos continua a ser o modo preferencial quando a implementação está finalizada e se pretende testes empíricos.

Este é no entanto um jogo muito pequeno para explorar, pelo que a sua generalização para os Jogos Em Linha, 
permitirá explorar melhor as particularidades das procuras adversas.

\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_galoalfabeta.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="teste_jogo_em_linha.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
