#include <iostream>
#include "knight.h"

using namespace std;

	Knight::Knight(int numIn, string nameIn, string questIn, string colorIn) : num(numIn), name(nameIn), quest(questIn), favoriteColor(colorIn) {
            
        }
		
	void Knight:: showAnswers() {
		std::cout  << "Knight number " << num << "; Name: " << name << "; Quest: " << quest << "; Favorite color: " << favoriteColor << endl;
	}

	string Knight::getCSVString() const{
		return to_string(num) + "," + name + "," + quest + "," + favoriteColor + "\n";		
	}


