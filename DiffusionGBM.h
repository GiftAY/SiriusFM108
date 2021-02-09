#include<stdexcept>
#include<cmath>
namespace SiriusFm
{
class DiffusionGBM{
	private:
		double const m_mu;
		double const m_sigma;
	public:
		double mu(double a_s, double a_t) const {return m_mu*a_s;}
		double sigma(double a_s, double a_t) const {return (a_s<0)?0:m_sigma*a_s;}

		DiffusionGBM(double a_mu, double a_sigma)
			:m_mu(a_mu),
			m_sigma(a_sigma)
		{
			if (a_sigma<0) throw std::invalid_argument("must be positive");
		}

		
};
}