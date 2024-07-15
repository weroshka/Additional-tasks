#include <iostream>
#include <circle.hpp>
#include <iostream>
#include <circle.hpp>

int main()
{
	veroshka::Point p;
	p.x = 0;
	p.y = 0;
	veroshka::Circle circle(p, 10);
	std::cout << "Initial square " << circle.Square() << std::endl;
	std::cout << "Initial perimeter " << circle.Perimeter() << std::endl;
	circle.SetR(-10);
	std::cout << "R= " << circle.GetR() << std::endl;
	std::cout << "Square is " << circle.Square() << std::endl;
	std::cout << "Perimeter is " << circle.Perimeter() << std::endl;
	return 0;
}
