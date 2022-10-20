#include <iostream>

using namespace std;

const int N_MARKS = 7;
const int N_FEEL = 5;
const int N_UTILITY = 2;

double Utility(int Feel_Neg, int Feel_Pos, double Rain)
{
	return Rain * Feel_Neg + ((1 - Rain) * Feel_Pos);
}

int main()
{
	string Example[N_MARKS] =
	{
		"-----Example-----",
		"Very good: 10,",
		"Good: 8,",
		"Satisfactory: 6,",
		"Bad: 3,",
		"Very bad: 1.",
		"-----------------"
	};

	string Template[N_MARKS] =
	{
		"---Ratings of sensations---",
		"Very good: ",
		"Good: ",
		"Satisfactory: ",
		"Bad: ",
		"Very bad: ",
		"---------------------------"
	};

	string Info[N_FEEL] =
	{
		"---Info Table---",
		"       Rain Sun",
		"Home    8    3",
		"Forest  1   10",
		"----------------"
	};

	int Marks[N_MARKS - 2];

	int Feel[N_FEEL - 1] = {8, 3, 1, 10};

	double Rain;

	for (int i = 0; i < N_FEEL; i++)
		cout << Info[i] << endl;

	cout << endl;

	for (int i = 0; i < N_MARKS; i++)
		cout << Example[i] << endl;

	cout << endl << "** Fill in according to the sample:" << endl;

	cout << Template[0] << endl;

	for (int i = 1; i < N_MARKS - 1; i++)
	{
		cout << Template[i];
		cin >> Marks[i - 1];
	}

	cout << Template[N_MARKS - 1] << endl << endl; 

	cout << "** Idicate the probability of rain [P(rain) <= 1]:" << endl;
	cout << "P(rain) = ";
	cin >> Rain;
	
	cout << endl << endl << "--------------Utility--------------" << endl;
	cout << "W(home): " << Utility(Feel[0], Feel[1], Rain) << endl;
	cout << "W(forest): " << Utility(Feel[2], Feel[3], Rain) << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "-------Result-------" << endl;
	if (Utility(Feel[0], Feel[1], Rain) < Utility(Feel[2], Feel[3], Rain))
		cout << "Go to the forest :D" << endl;
	else if (Utility(Feel[0], Feel[1], Rain) > Utility(Feel[2], Feel[3], Rain))
		cout << "Stay at home :(" << endl;
	else cout << "The choice is yours! :F" << endl;
	cout << "--------------------" << endl;
}