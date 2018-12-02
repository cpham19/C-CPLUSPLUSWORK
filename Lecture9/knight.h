#ifndef KNIGHT
#define KNIGHT
#include <string>
#include <vector>

using namespace std;

class Knight{
		
	public:	
		Knight(int numIn, string nameIn, string questIn, string colorIn); 
		void showAnswers();	
		string getCSVString() const;
		
	private:
		int num;
		string name;
		string quest;
		string favoriteColor;	
};

#endif
