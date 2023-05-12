# lex-analyzer

Analisador léxico para substrato da linguagem OWL2 (Formato Manchester Syntax).

Caso esteja utilizando o Windows, considere usar o WSL para executar o código.

Se necessário, siga este tutorial: <https://learn.microsoft.com/pt-br/windows/wsl/install>

Instale a distribuição Ubuntu.

Agora siga os passos a seguir para poder executar o código.

- sudo hwclock --hctosys
- sudo apt update -y
- sudo apt install -y g++
- sudo apt install -y make
- sudo apt install -y cmake

Agora, precisamos clonar o repositório do código usando o seguinte comando.

- git clone https://github.com/GuilhermeA08/lex-analyzer.git

Após isso, execute os seguinte comandos.

- cd lex-analyzer/Build/
- chmod +x sample
- ./sample < ../test.txt

O código foi testado e executado no sistema operacional Linux.
