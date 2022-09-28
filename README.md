<p align="center">
  <a href="https://unform.dev">
    <img src="https://cdn.discordapp.com/attachments/825163410499960882/954045448568582184/unknown.png" height="325" width="700" alt="Unform" />
  </a>
</p>


Mastermind é um jogo que ficou muito famoso das décadas de 70 e 80 que voltou a tona no ano de 2022 após o sucesso do jogo digital "Wordle". Este trabalho é uma variação do jogo Mastermind para ser jogado em computadores.

## Como jogar?
---


Existem dois papéis para os jogadores no Mastermind, o **Codemaker** e o **Codebreaker**. É dever do **Codemaker** criar uma sequência de cores secreta que o **Codebreaker** tentará adivinhar com a menor quantidade de turnos possível, realizando palpites de sequências em cada turno. A cada palpite, o **Codemaker** retorna uma sequência com o mesmo número de peças da sequência a ser descoberta, indicando quão correto está o palpite dado.

## Modos de Jogo
---

O jogo possui suporte para jogar sozinho ou em 2 pessoas. No modo *Singleplayer* o computador fará o papél de **Codemaker**, e o jogador poderá escolher dentre vários niveis de dificuldade e até mesmo criar sua dificuldade personalizada. No modo *Multiplayer*, por sua vez, um jogador fará o papél de **Codemaker** criando uma senha, e o outro fará o papél de **Codebreaker** e tentará descobri-la.

## Guia de jogo
---

No modo *Singleplayer* estão disponíveis 4 tipos de dificuldade predefinidas sendo elas:


* Dificuldade Fácil:
  - 4 Cores possíveis
  - Senha de tamanho 4
  - 10 Palpites no máximo
  - Cores não repetem
---
* Dificuldade Média:
  - 6 Cores possíveis
  - Senha de tamanho 5
  - 8 Palpites no máximo
  - Cores não repetem
---
* Dificuldade Difícil 
  - 8 Cores possíveis
  - Senha de tamanho 6
  - 6 Palpites no máximo
  - Cores podem repetir
---
* Dificuldade Impossível
  - 10 Cores possíveis
  - Senha de tamanho 6
  - 4 Palpites no máximo
  - Cores podem repetir
---
  
E um modo de dificuldade personalizada onde o jogador pode escolher:

  - Número de cores possível (4 a 10)
  - Tamanho da senha (4 a 6)
  - Número máximo de palpites (4 a 10)
  - Se pode ou não haver cores repetidas

As senhas são formadas a partir de 10 cores possíveis sendo elas: <font color=red>vermelho</font>, <font color=blue>azul</font>, <font color=green>verde</font>, <font color=#ffbf00>amarelo</font>, <font color=purple>roxo</font>, <font color=darkorange>laranja</font>, <font color=#DA70D6>rosa</font>, <font color=darkcyan>ciano</font>, <font color=brown>marrom</font>, <font color=briek>bordô</font>.

Após o **Codebreaker** realizar seu palpite, o jogo retorna uma sequência de tamanho igual ao palpite, cada posição da sequência possuirá uma cor de resposta
* <font color=gray>**Cinza**</font> - *Posição* e *Cor* errada
* Branco - *Cor* certa em *posição* errada
* **Preto** - *Cor* e *Posição* Certas


## Pré-requisitos
---

Para jogar é nescessário que o usuário possua:


* [CMake](https://pt.wikipedia.org/wiki/CMake)
* [MinGW](https://pt.wikipedia.org/wiki/MinGW)
* g++(Compilador de C++)
* Executar programa em terminal do Linux


## Instalação
---

   
Instalação do jogo:
1. Baixar os arquivos
2. Extrair os arquivos irá gerar a pasta jogo
3. Executar o jogo com o CMakeLists.txt disponivel dentro da pasta por meio do terminal do Linux

## Construído com
---

* [Visual Sutio Code](https://code.visualstudio.com) - Usado para programar
* [GitHub](https://github.com) - Gerenciamento 
* [Discord](https://discord.com) - Compartilhamento de codigos e referências

##  Autores
---

* **Cassio Vitor Duvoisin** - *(20203991)* - [Instagram](https://www.instagram.com/cassio_duvoisin/)
* **Guilherme Arthur Allebrandt Schunemann** - *(20203481)* - [Instagram](https://www.instagram.com/guiarthur.as/)
  


## Expressões de gratidão
---
* Gostariamos de agradecer nosso querido professor e orientador Gian Ricardo Berkenbrock por todo o suporte e atenção fornecidos durante o período, estendemos o convite para uma cervejinha 🍺 de comemoração quando estivermos em Joinville.
* Também gostariamos de agradecer aos nossos colégas de engenharia: Caio Vinicius Peixoto Pedrosa, Eduardo Schvinn, Davi Ferreira e Matheus Nunes Franco, pelo auxílio em duvidas pontuais, e pelo apoio motivacional. PRA CIMA DELES!!! 


---