CC      = g++
LD      = g++

CFLAGS          = -I include/ -c
LDFLAGS         =

DIJKSTRA = dijkstra/main.o lib/graph.o
SPFA = spfa/main.o lib/graph.o
FLOYD = floyd/main.o lib/graph.o
PRIM = prim/main.o lib/graph.o

EXE_FLODER = executable

nop :
	@echo "which target do you want to make? :)"

dijkstra : $(DIJKSTRA)
	$(LD) $(LDFLAGS) -o $(EXE_FLODER)/$@ $(DIJKSTRA)

spfa : $(SPFA)
	$(LD) $(LDFLAGS) -o $(EXE_FLODER)/$@ $(SPFA)

floyd : $(FLOYD)
	$(LD) $(LDFLAGS) -o $(EXE_FLODER)/$@ $(FLOYD)

prim : $(PRIM)
	$(LD) $(LDFLAGS) -o $(EXE_FLODER)/$@ $(PRIM)

dijkstra/main.o : dijkstra/main.cpp include/graph.h
	$(CC) $(CFLAGS) -o $@ $<

spfa/main.o : spfa/main.cpp include/graph.h
	$(CC) $(CFLAGS) -o $@ $<

floyd/main.o : floyd/main.cpp include/graph.h
	$(CC) $(CFLAGS) -o $@ $<

prim/main.o : prim/main.cpp include/graph.h
	$(CC) $(CFLAGS) -o $@ $<

lib/graph.o : lib/graph.cpp include/graph.h
	$(CC) $(CFLAGS) -o $@ $<
