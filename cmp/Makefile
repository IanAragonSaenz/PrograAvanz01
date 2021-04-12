
main: ../src/main.c ../lib/src/data.h
	gcc -fPIC -c ../lib/src/consulta.c -o ../lib/dinamica/consulta.o
	gcc -fPIC -c ../lib/src/data.c -o ../lib/dinamica/data.o
	gcc -fPIC -c ../lib/src/menu.c -o ../lib/dinamica/menu.o
	gcc -fPIC -c ../lib/src/kardex.c -o ../lib/dinamica/kardex.o
	gcc -fPIC -c ../lib/src/fechaGraduacion.c -o ../lib/dinamica/fechaGraduacion.o
	gcc -fPIC -c ../lib/src/numeroAlumnos.c -o ../lib/dinamica/numeroAlumnos.o
	gcc -fPIC -c ../lib/src/nombreAlumnos.c -o ../lib/dinamica/nombreAlumnos.o
	gcc -shared -o ../lib/dinamica/libquery.so ../lib/dinamica/*.o
	gcc ../src/main.c /home/kali/Desktop/PrograAvanz01/lib/dinamica/libquery.so -o ../bin/main
	
clean: 
	rm ../lib/dinamica/*.o ../lib/dinamica/*.so ../bin/main
