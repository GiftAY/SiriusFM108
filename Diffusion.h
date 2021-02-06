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



class DiffusionOU{
	private:
		double const m_kappa;
		double const m_theta;
		double const m_sigma;

	public:
		double mu(double a_s, double a_t) const {return m_kappa*(m_theta-a_s);}
		double sigma(double a_s, double a_t) const {return (a_s<0)?0:m_sigma*a_s;}
		//double kappa(double a_s, double a_t) const {return (a_s<0)?0:m_kappa*a_s;}
		DiffusionOU(double a_kappa, double a_theta, double a_sigma)
		:m_kappa(a_kappa), m_theta(a_theta), m_sigma(a_sigma)
		{
			if (a_sigma<0) throw std::invalid_argument("must be positive");
			if (a_kappa<0) throw std::invalid_argument("must be positive");
		}

};

class DiffusionL{
	private:
		double const m_mu;
		double const m_sigma_0;
		double const m_sigma_1;
		double const m_sigma_2;

	public:
		double sigma(double a_s, double a_t) const {return (m_sigma_0<0 || m_sigma_2<0 || m_sigma_1*m_sigma_1-4*m_sigma_2*m_sigma_0>=0)?0:(m_sigma_0+m_sigma_1*a_s+m_sigma_2*a_s*a_s);}
		double mu(double a_s, double a_t) const {return m_mu*a_s;}

		DiffusionL(double a_mu, double a_sigma_0, double a_sigma_1, double a_sigma_2)
		:m_mu(a_mu), m_sigma_0(a_sigma_0), m_sigma_1(a_sigma_1), m_sigma_2(a_sigma_2)
		{
			if (a_sigma_0<0) throw std::invalid_argument("must be positive");
			if (a_sigma_2<0) throw std::invalid_argument("must be positive");
			if (a_sigma_1*a_sigma_1-4*a_sigma_2*a_sigma_0>=0)throw std::invalid_argument("must be positive");

		}
		
		
};

class DiffusionCIR{
	private:
		double const m_kappa;
		double const m_theta;
		double const m_sigma;

	public:
		double mu(double a_s, double a_t) const {return m_kappa*(m_theta-a_s);}
		double sigma(double a_s, double a_t) const {return m_sigma*sqrt(a_s);}
		DiffusionCIR(double a_kappa, double a_theta, double a_sigma)
		:m_kappa(a_kappa), m_theta(a_theta), m_sigma(a_sigma)
		{
			if (a_sigma<0) throw std::invalid_argument("must be positive");
			if (a_kappa<0) throw std::invalid_argument("must be positive");
			if (a_theta<0) throw std::invalid_argument("must be positive");
		}
};


class DiffusionCEV{
	private:
		double const m_sigma;
		double const m_mu;
		double const m_beta;

	public:
		double mu(double a_s, double a_t) const {return m_mu*a_s;}
		double sigma(double a_s, double a_t) const {return m_sigma*pow(a_s, m_beta);}
		DiffusionCEV(double a_sigma, double a_mu, double a_beta)
		:m_sigma(a_sigma), m_mu(a_mu), m_beta(a_beta)
		{
			if (a_sigma<0) throw std::invalid_argument("must be positive");
			if (a_beta<0) throw std::invalid_argument("must be positive");
		}
};







}