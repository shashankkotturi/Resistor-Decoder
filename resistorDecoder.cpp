#include <iostream>
#include "math.h"

using namespace std;
int main()
{
	char band [13] = {'k', 'n', 'R', 'O', 'Y', 'G', 'B', 'V', 'y', 'W', 'd', 'S', 'N'};
	char bandA, bandB, bandC, bandD;
	
	cout << "Enter the four resistor color codes: ";
	cin >> bandA >> bandB >> bandC >> bandD;
	
	bool validA = false;
	bool validB = false;
	bool validC = false;
	bool validD = false;
	
	int valueA, valueB, valueC;
	double valueD;
	
	double resistance, tolerance;
	for (int i = 0; i < sizeof(band) / sizeof(band[0]); i++)
	{
		if (bandA == band[i] && i < 10)
		{
			valueA = i;
			validA = true;
		}
			
		if (bandB == band[i] && i < 10)
		{			
			valueB = i;		
			validB = true;
		}
			
		if (bandC == band[i] && i < (sizeof(band) / sizeof(band[0]) - 1))
		{
			if (i < 10)				
				valueC = i;
			else if (i == 10)
				valueC = -1;
			else if (i == 11)
				valueC = -2;
			validC = true;
		}
		
		if (bandD == band[i] && i != 0 && i != 3 && i != 4 && i != 9)
		{
			validD = true;
			if (i == 1 || i == 2)
				valueD = i;
			else if (i == 5)
				valueD = 0.5;
			else if (i == 6)
				valueD = 0.25;
			else if (i == 7)
				valueD = 0.1;
			else if (i == 8)
				valueD == 0.05;
			else if (i == 10)
				valueD == 5;
			else if (i == 11)
				valueD = 10;
			else
				valueD = 20;
		}
	}
	
	if (validA == true && validB == true && validC == true && validD == true)
	{
		resistance = ((valueA * 10) + valueB) * pow(10, valueC);
		tolerance = resistance * valueD/100;
		cout << "Resistance is " << resistance << " ohms (+/-" << tolerance << " ohms tolerance)" << endl;
	}

	else
	{
		cerr << "Error: Invalid color code entered!" << endl;
		return -1;
	}
	
	return 0;
}