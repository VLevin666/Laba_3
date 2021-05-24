all: result
	g++ main.o list.o item.o function.o -o result
result: list item function
	g++ main.cpp -c

function: list item
	g++ function.cpp -c

list: item 
	g++ list.cpp -c

item:
	g++ item.cpp -c


