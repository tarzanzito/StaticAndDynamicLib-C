#
# Windows or MSYS2 
#

rm -f other.o
rm -f math.o
rm -f main.o

rm -f libother.dll
rm -f libmath.dll

#other
#-----
gcc -c -fPIC -o other.o other.c 
gcc -shared -o libother.dll other.o -DBUILD_DLL_EXPORT

#math
#----
gcc -c -fPIC -o math.o math.c 
gcc -shared -o libmath.dll math.o -DBUILD_DLL_EXPORT 

#main
#----
gcc -c -o main.o main.c
gcc main.o -o main -L. -lmath -lother 

cp -f libother.dll ../Tests
cp -f libmath.dll ../Tests
cp -f main.exe  ../Tests
