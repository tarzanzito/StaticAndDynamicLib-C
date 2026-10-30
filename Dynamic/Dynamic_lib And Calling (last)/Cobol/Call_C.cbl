       IDENTIFICATION DIVISION.
       PROGRAM-ID. Hello.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-STRINGS.
          05 WS-NAME         PIC X(8) VALUE "Paulo".
      *   06 WSLIBRARY      PIC X(20) VALUE "libmylib.dll" & X"00".
       O1 WS-COMP-5.
           05 WS-NUM      PIC S9(9) COMP-5 VALUE 12.
           05 WS-NUM-A    PIC S9(9) COMP-5 VALUE 33.
           05 WS-NUM-B    PIC S9(9) COMP-5 VALUE 44.
           05 WS-RESULT   PIC S9(9) COMP-5.
      *
       PROCEDURE DIVISION.

           DISPLAY "--- Inicio do Programa COBOL ---".

      *    NOTA: For C Libraries Int must be COMP-5.

      *    void c_function_ref(int *num); (pointer)
           CALL "c_function_ref"  
               USING BY REFERENCE MY-NUM
      *         RETURNING WS-RESULT
           END-CALL.
           DISPLAY "Valor apos C (Ref): " MY-NUM.

      *    int add(int a, int b); (values)
           CALL "add"  
               USING BY VALUE MY-NUM-A, MY-NUM-B
               RETURNING WS-RESULT
           END-CALL.   
           DISPLAY "Add: " MY-NUM-A " + " MY-NUM-B " = " WS-RESULT.

      *    void printHello(char * msg);
           CALL "printHello"  
               USING BY REFERENCE WS-NAME
           END-CALL.   
           DISPLAY "printHello: " WS-NAME.

           STOP RUN.

      ************************************************
      *
      *Static Lib (REVIEW)
      *- Linux
      *cobc -x -o main main.cbl mystatic.o
      *- Windows
      *cobc -x -o main.exe main.cbl -L. -lmath
      *
      *Dynamic Lib
      *- Linux
      *cobc -x -o main main.cbl -L. -lmath fstatic-call
      *- Windows
      *cobc -x -o main.exe main.cbl -L. -lmath fstatic-call
      *

      *-fstatic-call 
      *-------------
      *O -fstatic-call não transforma a DLL numa biblioteca estática.
      *A DLL continua a ser dinâmica e externa.
      *O que a flag altera é a forma como o executável faz a ligação
      * (binding) com a função em C:
      *
      *  * Sem -fstatic-call (Comportamento Padrão):
      *  O GnuCOBOL assume que qualquer CALL "nome" refere-se a outro
      *  módulo COBOL (um arquivo .coor, .dll ou .so separado) que
      *  será carregado dinamicamente via dlopen() / LoadLibrary()
      *  em tempo de execução. Ele procura literalmente por um arquivo
      *  chamado c_function_ref.dll. Como esse arquivo não existe
      *  (o nome é libmath.dll), o runtime falha com o erro anterior.
      *
      *  * Com -fstatic-call: Você diz ao compilador: "Não procures
      *  este módulo dinamicamente em tempo de execução. Resolve
      *  o símbolo c_function_ref agora, durante a compilação,
      *  usando as tabelas de importação das bibliotecas que passei
      *  no comando (o -lmath)".
      *  O compilador vai à libmath.dll, vê que a função existe lá
      *  dentro, e grava na tabela de importações
      *  (IAT - Import Address Table) do seu .exe que a função
      *  c_function_ref pertence à libmath.dll.
      *  O erro de memória (invalid memory address) que deu a seguir
      *  prova isto: o vínculo com a DLL funcionou e o programa
      *  conseguiu saltar para dentro da função C. O crash atual já
      *  é um problema de sintaxe ou de ponteiros na passagem de dados
      *  entre as duas linguagens.
      *
