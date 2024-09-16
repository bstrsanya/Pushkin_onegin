all:
	g++ -Iinclude src/*.cpp -o main
	.\main
	

# -I/include 
#g++ onegin.cpp CompareStr.cpp SortStr.cpp CounterStr.cpp AddrBeginLine.cpp RecordFile.cpp ReadFile.cpp -o main