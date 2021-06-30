#include <iostream>
using namespace std;

class ArrayLIST
{

	int* ptr1;
	int* ptr2;


public:
	
	void MostFrequentElementInSubArray()
	{
		int Right{};
		int Left{};
		int Freq;
		int Arr[] = { 2,2,3,3,3,4,5,6 };
		int ArrLength = *(&Arr + 1) - Arr;
		
		cout << "Enter the length of Array:  " << ArrLength << endl;
		
		cout << "Enter the starting element of array: \n";
		cin >> Left;
		
		cout << "Enter the ending point of array: \n";
		cin >> Right;
		cout << endl;
		
		cout << "Enter the frequency: \n";
		cin >> Freq;

		if (Left >= 0 && Right >= Left && Right < ArrLength)
		{
			if (2 * Freq >= Right - Left + 1)
			{
				ptr1 = Arr;
				ptr2 = Arr;
				cout << *ptr1 << endl;
				cout << "The array you are dealing with:  \n";
				for (int i = 0; i < 5; i++)
				{
					ptr2++;
					cout << *ptr2 << endl;

				}

				(*ptr1 + Left);


				for (int i = 0; i <= Right - Left; i++)
				{
					(*ptr1 + Left + i);
				}

				int* Arr2 = new int[Right - Left + 1];
				
				for (int i = 0; i <= Right - Left + 1; i++)
				{
				
					*(Arr2 + i) = *(ptr1 + Left + i);
				
				}
				
				int z = 0;
				int j = 0;
				int count = 1;
				int Temp;
				Temp = *Arr2;

				for (int i = 0; i <= Right - Left; i++)
				{
					Temp = *(Arr2 + i);
					
					for (int j = i + 1; j <= Right - 1; j++)
					{
						
						if (Temp == *(Arr2 + j))
						{
							count++;
						}
						count >= Freq;
					
					}
				
				}
				
				int* Arr3 = new int(Right - Left + 1);

				for (int i = 0; i < Right - Left; i++)
				{
				
					*(Arr + 3) = Temp;
					z++;
				
				}

			}
		}
	}

	

};



int main()
{
	
	ArrayLIST Obj;
	Obj.MostFrequentElementInSubArray();
	return 0;

}