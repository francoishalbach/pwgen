//Francois Halbach CISA 4302

#include <iostream>
#include <ctime>

using namespace std;

int main ()
{
	//Declare variable for password length
	int PWLength;
	
	//Prompt for password length.
		cout << "Enter the desired password length between 3 and 30: \n";
		cin >> PWLength;
		
	//Prompt for pw length as long as not the right size
	while (PWLength < 3 or PWLength > 30)
		{
		//Prompt for password length.
		cout << "Please verify input. Must be between 3 and 30: \n";
		cin >> PWLength;
		}
		
	//Randomize rand
	srand((unsigned)time(NULL));
		
	//Generate 3 arrays of 10 characters, digits, special characters.
	int digArray[10];
	for (int x=0; x<10; x++)
		{
		char digits[] = "0123456789";
		char tempDig = digits[rand() % 10];
		digArray[x] = tempDig;
		}
	
	int sCharArray[10];
	for (int x=0; x<10; x++)
		{
		char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char tempSChar = letters[rand() % 52];
		sCharArray[x] = tempSChar;
		}

	int charArray[10];
	for (int x=0; x<10; x++)
		{
		char characters[] = "`~!@#$%^&*()-_=+<>,./?;:";
		char tempChar = characters[rand() % 24];
		charArray[x] = tempChar;
		}
		
	//Generate right length password composed of characters from above arrays.
	int y=0;
	int genPass[PWLength];
	int loopReps = PWLength/3;
	int loopRem = PWLength%3;
	for (int x=0; x<loopReps; x++)
		{
		genPass[y] = digArray[x];
		y++;
		genPass[y] = sCharArray[x];
		y++;
		genPass[y] = charArray[x];
		y++;
		}
	
	for (int x=0; x<loopRem; x++)
		{
		char remdigits[] = "0123456789";
		char tempRemDig = remdigits[rand() % 10];
		genPass[y] = tempRemDig;
		y++;
		}
	
	//Print password.
	cout << "Your randomly generated password is: ";
	for  (int x=0; x<PWLength; x++)
		{
		cout << (char) genPass[x];
		}

	//Freeze window, terminate program
	system("pause");
	return 0;
}
 
