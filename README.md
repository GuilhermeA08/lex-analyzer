# lex-analyzer

Analisador léxico para substrato da linguagem OWL2 (Formato Manchester Syntax).

Antes de executar, tenha certeza de ter instalado todas as dependências necessárias.

- g++
- Make
- CMake
- Flex

O código foi testado e executado no sistema operacional Linux, caso possível, ao tentar executar o projeto, estar também utilizando o mesmo sistema operacional.

Foi utilizado também o ambiente Visual Studio Code, se possível utiliza-lo também para que possíveis dúvidas possam ser sanadas caso venham a surgir.

Para executar o código, na parte superior da tela, seguir a sequência:

Terminal > Run Task/Executar Tarefa > cmake.
Terminal > Run Task/Executar Tarefa > make.

Primeiro execute a tarefa cmake, e após concluir com sucesso, executar a tarefa make.

Em seguida, ele irá gerar um executável dentro da pasta Build, com o nome **"sample"**.

Para executar, você pode colocar o código **./sample < ../test.txt**, dentro do arquivo test.txt será o código a ser analisado, caso queira testar algum diferente, basta modificá-lo, e executar o comando novamente.
