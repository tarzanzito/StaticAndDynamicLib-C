       IDENTIFICATION DIVISION.
       PROGRAM-ID. MODULE.
       
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-NUM1        PIC 9(03).
      *  
       LINKAGE SECTION.
       01 LK-NUM1        PIC 9(03).
       01 LK-NUM2        PIC 9(03).
       01 LK-RESULT      PIC 9(04).

       PROCEDURE DIVISION USING LK-NUM1 LK-NUM2 LK-RESULT.
       MAIN-PROCEDURE.

           COMPUTE LK-RESULT = LK-NUM1 + LK-NUM2.
           
           GOBACK.

      *GNU Cobol compile
      *cobc -m module.cbl

      ******************************************
      *DIFFERENCE: GOBACK vs EXIT PROGRAM

      *Comando	     - Comportamento num Subprograma (Módulo)
      *GOBACK	     - Retorna o controlo para o programa que o chamou.
      *EXIT PROGRAM - Retorna o controlo para o programa que o chamou.

      *Comando      - Comportamento no Programa Principal
      *GOBACK       - Termina a execução da aplicação inteira
      *               (igual a STOP RUN).
      *EXIT PROGRAM - Não faz nada (é ignorado e o código continua
      *               na linha seguinte).

      *Comando      - origem / Padrão
      *GOBACK       - Extensão IBM (hoje universal)
      *EXIT PROGRAM - Padrão COBOL (ANSI / ISO) COBOL orignal
