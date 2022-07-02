bluid: 
	g++ ./src/*.cpp -o opcv.o -I /usr/include/opencv4

run: bluid
		./opcv.o

clean: 
	  rm opcv.o