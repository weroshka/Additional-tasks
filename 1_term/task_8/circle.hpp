#pragma once
#define PI acos(-1)
#include <iostream>

namespace veroshka
{

	struct Point
	{
		int x;
		int y;
	};

	class Circle
	{
	public:
		Circle(Point M, int R);
		
		~Circle();
		
		double Square();
		
		double Perimeter();

		void SetR(int R);

		int GetR() { return m_R; }

	private:
		Point m_M;
		int m_R;


	};

}