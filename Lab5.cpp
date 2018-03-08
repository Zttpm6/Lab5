//============================================================================
// Name        : Lab5.cpp
// Author      : Zach Taylor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Signal{
	private:
			int length;
			int maximumvalue;
			int minimumvalue;
			float average;
			vector <int> rawdata;
			vector <int> moddata;

	public:
			Signal();
			Signal(int filenum);
			Signal(string filename);
			void offset(int off, Signal s);
			void scale(int scal,Signal s);
			void center(Signal s);
			void normalize(Signal s);
			void Statistics(Signal s);
			void Sig_info();
			void Save_file(Signal s);
			void Help();
};

int main() {
	cout << "" << endl; // prints 
	return 0;
}
