#ifndef KNIGHTSTORAGE
#define KNIGHTSTORAGE
#include <string>
#include <vector>

using namespace std;

class KnightStorage{
	public:
		void writeHardCodedKnights();
		vector <Knight> readFromFile();	
	private:
		vector<Knight> knights;
		vector<string> tokenize(string in);	
	};
#endif
