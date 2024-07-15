#include <iostream>
#include "functions.hpp"

int main()
{
	int n;
    int sequence[1000];
    ver::Input(n, sequence);
    ver::Maximum(n, sequence);
    ver::Minimum(n, sequence);
    ver::Sort(n, sequence);
    ver::Output(n, sequence);
    
	return 0;
}
