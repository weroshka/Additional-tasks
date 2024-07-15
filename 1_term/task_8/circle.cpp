#include <circle.hpp>

namespace veroshka
{
	Circle::Circle(Point M, int R)
	{
		m_M = M;
		m_R = R;
	}

	Circle::~Circle()
	{
		std::cout << "Destructor works!" << std::endl;
	}

	double Circle::Square()
	{
		return m_R * m_R * PI;
	}

	double Circle::Perimeter()
	{
		return 2 * PI * m_R;
	}

	void Circle::SetR(int R)
	{
		m_R = R;
		if (R <= 0)
		{
			std::cout << "R<=0" << std::endl;
			m_R = 25;
		}
	}
}