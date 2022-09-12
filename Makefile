CXXFLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef       \
		 -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations     \
		 -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++       \
		 -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion  \
		 -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2        \
		 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers       \
		 -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
		 -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel          \
		 -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.o string/string.o IO/io.o sort/sort.o
	g++ $(CXXFLAGS) main.o string/string.o IO/io.o sort/sort.o -o sortfile.exe

main.o: main.cpp
	g++ $(CXXFLAGS) main.cpp -c -o main.o

string/string.o : string/string.cpp
	g++ $(CXXFLAGS) string/string.cpp -c -o string/string.o

IO/io.o: IO/io.cpp
	g++ $(CXXFLAGS) IO/io.cpp -c -o IO/io.o

sort/sort.o: sort/sort.cpp
	g++ $(CXXFLAGS) sort/sort.cpp -c -o sort/sort.o