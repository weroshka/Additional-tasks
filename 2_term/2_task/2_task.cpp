#include <iostream>
#define N 10

// Algorithm complexity is O(NlogN)

void MERGE_SORT(int a, int b, int *X)
{
	// Borders have closed 
	if (a == b)
		return;

	//Define the middle of sequence
	int m = (a + b) / 2;

	// Call the sorting function for each half in recursive way 
	MERGE_SORT(a, m, X);
	MERGE_SORT(m + 1, b, X);

	// beginning of the first path
	int i = a; 
	// beginnig of the second path
	int j = m + 1; 
	// create an additional array
	int* Y = new int[N]; 

	// for all elements of Y array
	for (int k = a; k <= b; k++)
	{
		//write in Y array the least element of two paths OR the rest of the first way
		if ((j > b) || ((i <= m) && (X[i] < X[j])))
		{
			Y[k] = X[i];
			i++;
		}
		else
		{
			Y[k] = X[j];
			j++;
		}
	}

	//write Y array in X array
	for (int i = a; i <= b; i++)
	{
		X[i] = Y[i];
	}
	
	delete[] Y;
}

int main()
{
	int mas[N];
	for (int i = 0; i < N; i++)
	{
		mas[i] = (rand() % 100);
		std::cout << mas[i] << " ";
	}
	MERGE_SORT(0, N - 1, mas); 

	std::cout << std::endl;
	std::cout << "SORTED ARRAY " << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << mas[i] << " ";
	
	return 0;
}