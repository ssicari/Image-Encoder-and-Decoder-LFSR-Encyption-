#ifndef FibLFSR_H
#define FibLFSR_H
#include <iostream>
#include<string> 
#include<vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class FibLFSR {

public:
	FibLFSR(string seed);
	int step();
	int generate(int k);
	friend ostream& operator<< (ostream& out, const FibLFSR &FibLFSR);
private:
	vector<int> myVector;
};
void transform( sf::Image&, FibLFSR*);

#endif
