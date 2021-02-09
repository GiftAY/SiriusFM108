#pragma once
#include<ctime>
#include"MCEngine1D.h"
namespace SiriusFm
{
inline double YearFrac(time_t a_t)
{
	//Argyear in seconds
	constexpr double SecY = 365.25*86400;
	return 1970.0+double(a_t)/SecY;

}
inline double YearFrac1(time_t a_t)
{
	//Argyear in seconds
	constexpr double SecY = 365.25*86400;
	return double(a_t)/SecY;

}
}