#pragma once
#include"IRProvider.h"
namespace SiriusFm
{
	template < >
	class IRProvider<IRModeE::Const>
	{

	private:
		double m_IRs[int(CcyE::N)];
	public:
		IRProvider(char const* a_file);
		double r(CcyE a_ccy, double a_t)
		{return m_IRs[int(a_ccy)];}
	};


}