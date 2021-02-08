#pragma once
#include<stdexcept>
#include<cstring>
namespace SiriusFm
{
	enum class CcyE
	{
		USD = 0,
		EUR = 1,
		GBP = 2,
		CHF = 3,
		RUB = 4,
		N=5
	
	};
inline char const*CcyE2str(CcyE a_ccy){
	switch(a_ccy){
		case CcyE::USD: return "USD";
		case CcyE::EUR:return "EUR";
		case CcyE::GBP:return "GBP";
		case CcyE::CHF:return "CHF";
		case CcyE::RUB:return "RUB";
		default: throw std::invalid_argument("goodbye_today");

	}
}

inline CcyE str2Ccye (char const* a_ste){
	if(strcmp(a_ste, "USD") == 0)
		return CcyE::USD;
	else if(strcmp(a_ste, "EUR") == 0)
		return CcyE::EUR;
	else if(strcmp(a_ste, "GBP") == 0)
		return CcyE::GBP;
	else if(strcmp(a_ste, "CHF") == 0)
		return CcyE::CHF;
	else if(strcmp(a_ste, "RUB") == 0)
		return CcyE::RUB;
	else throw std::invalid_argument("goodbye_tomorrow");
}
enum class IRModeE{
	Const = 0,
	FwdCurve =1,
	Stoch = 2
};
template <IRModeE IRM>
class IRProvider;
}