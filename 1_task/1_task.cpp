#include <iostream>

bool Recurtion(float n)
{
	if (n <= 0)
		return false;

	// 1.терминирующее условие 
	
	if (n == 1)
		return true;

	// 2. вызов функции с изменяющимся аргументом 

	return (Recurtion(n / 2));
}

int main()
{
	float n;
	std::cin >> n;
	
	
	if (Recurtion(n))
		std::cout << n << " is an integer power of two";

	else
		std::cout << n << " is NOT an integer power of two";
}