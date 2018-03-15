//============================================================================
// Name        : Lab5.cpp
// Author      : Zach Taylor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <string.h>
#include <cstring>
#include <iomanip>
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
			void Save_file();
			void Help();
};
Signal::Signal(int filenum)
{
	char name[30];
	int placehold;
	ifstream input;
	if(!input.is_open())
   	{
   		cerr << "Unable to open file when writing" << endl;
   	}
   	sprintf(name, "Raw_data_%02d.txt",filenum);
   	input.open(name);
   	input >> length;
   	input >> maximumvalue;
	cout<< "\t" << length << " " << maximumvalue << endl; //print length and max
   	for(int j = 0; j < length; j++)
   	{
   		input >> placehold;
   		rawdata.push_back(placehold);
   		cout << j << "\t" << placehold << endl;

   	}
   	input.close();

}
Signal::Signal()
{
	char name[30];
	int placehold;
	ifstream input;
	sprintf(name, "Raw_data_01.txt");
	input.open(name);
	input >> length;
	input >> maximumvalue;
	cout <<"\t" << length << " " << maximumvalue << endl; //print length and max
	for(int i = 0; i < length; i++)
   	{
   		input >> placehold;
   		rawdata.push_back(placehold);
   		cout << "\t" << placehold << endl;

   	}
}
void Signal::offset(int off, Signal s)
{
	for(int i = 0; i < s.rawdata.size(); i++ )
	{
		int placehold = s.rawdata[i];
		placehold = placehold + off;
		cout << "\t" << placehold << endl;
		s.moddata.push_back(placehold);
	}
}
Signal::Signal(string filename)
{

}

int main(int argc, const char *argv[])
{
	int filenum = 0, off = 0, scale = 0; //Input options
	int getstats = 0, getcen = 0, getnorm = 0; //Options
	for(int i = 0; i < argc; i++)
	{
		if(!strcmp(argv[i], "-S"))
		{
			getstats =1;
		}
		if(!strcmp(argv[i], "-C"))
		{
			getcen = 1;
		}
		if(!strcmp(argv[i], "-N"))
		{
			getnorm = 1;
		}
		if(!strcmp(argv[i],"-n"))
		{
			if(argv[i+1] == NULL) // check to make sure a number is given
			{
				cout << "You have chosen the default file" << endl;
				Signal S2;
			}
			else
			{
				filenum = atoi(argv[i+1]);
			}
		}
		if(!strcmp(argv[i],"-o"))
		{
			if(argv[i+1] == NULL)
			{
				cout << "This is an incorrect input" << endl;
			}
			off = atoi(argv[i+1]);
		}

	}
	Signal S1(filenum);
	if(off != 0)
	{
		S1.offset(off,S1);
	}

	return 0;
}
