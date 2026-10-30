       IDENTIFICATION DIVISION.
       PROGRAM-ID. MAIN.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WRK-VALOR1     PIC 9(03) VALUE 150.
       01 WRK-VALOR2     PIC 9(03) VALUE 350.
       01 WRK-TOTAL      PIC 9(04) VALUE ZERO.

       PROCEDURE DIVISION.
       MAIN-PROCEDURE.
           DISPLAY "Calling module..."
           
           CALL 'MODULE' USING WRK-VALOR1 WRK-VALOR2 WRK-TOTAL.
           
           DISPLAY "Result:" WRK-TOTAL
           
           STOP RUN.


      *Compile
      *cobc -x Call_Cobol.cbl

      *compile principal and module in one  executable file
      *cobc -x Call_Cobol.cbl modulo.cbl
      