#
# Windows or MSYS2 
#
#NOTE: first time run:./CobolStart.ps1 or ./CobolStart.sh)
#

#Call_C
#------

cobc -x -o Call_C.exe Call_C.cbl -L. -lmath -lother fstatic-call

cp -f Call_C.exe  ../Tests

#Call_Cobol
#-----------

cobc -m module.cbl
cobc -x Call_Cobol.cbl

cp -f module.dll  ../Tests
cp -f Call_Cobol.exe  ../Tests

#join
#cobc -x Call_Cobol.cbl modulo.cbl