#include<iostream>
using namespace std;
int main()
{

	char* var = “1232333.3422324234” << endl;
	int length = 2;


	for (int i = 0; i < length; i++) 
	{
		
		if (*var != 0) 
		{

			cout << *var << endl;
			
			var++;
			
			length++;

		}

	}
	cout << length - 2;




	system("pause");
	return 0;
}