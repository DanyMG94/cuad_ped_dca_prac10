OBJ=main.o tcomplejo.o tvectorcom.o tlistacom.o
OB1=main.cpp tcomplejo.h tvectorcom.h tlistacom.h
OB2=tcomplejo.h tcomplejo.cpp tlistacom.cpp
OB3=tvectorcom.h tvectorcom.cpp
OB4=tlistacom.h tlistacom.cpp
COMP=g++
OPC=-g

main: $(OBJ)
	$(COMP) $(OPC) $(OBJ) -o main

main.o: $(OB1)
	$(COMP) $(OPC) -c main.cpp

tcomplejo.o: $(OB2)
	$(COMP) $(OPC) -c tcomplejo.cpp
	
tvectorcom.o: $(OB3)
	$(COMP) $(OPC) -c tvectorcom.cpp

tlistacom.o: $(OB4)
	$(COMP) $(OPC) -c tlistacom.cpp
