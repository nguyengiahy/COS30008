#include "UpperCaseString.h"
#include "UpperCaseStringIterator.h"
#include <iostream>
using namespace std;
int main()
{
	UpperCaseString s("Able was I I saw Elba");

	cout << "The string: \"" << s << "\" with size: " << s.size() << endl;

	bool lPalindrome = true;

	UpperCaseStringIterator move_to_right = s.begin();
	UpperCaseStringIterator move_to_left = s.rbegin();
	UpperCaseStringIterator past_left = s.rend();

	while (move_to_left != past_left)
	{
		if (*move_to_right == *move_to_left)
		{
			move_to_right++;
			--move_to_left;
		}
		else
		{
			lPalindrome = false;
			break;
		}
	}

	if (lPalindrome)
		cout << "We have found a palindrome!" << endl;
	else
		cout << "Oops, no palindrome." << endl;

	return 0;
}