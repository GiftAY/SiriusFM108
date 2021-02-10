#pragma once
#include <cmath>
#include <ctime>
#include <stdexcept>
#include <utility>
#include <tuple>
namespace SiriusFM
{
    template <typename Diffusion1D, typename AProvider, typename BProvider, typename AssetClassA, typename AssetClassB>
    class MCEngine1D
    {
        private:
            long const m_MaxL; //Max Path lenght
            long const m_MaxP; //Max N Paths
            double* const m_paths;
            long m_L;
            long m_P;
        public:
            MCEngine1D(long a_MaxL, long a_MaxP)
            :m_MaxL(a_MaxL),
            m_MaxP(a_MaxP),
            m_paths(new double[m_MaxL * m_MaxP]),
            m_L(0),
            m_P(0)
            {
                if(m_MaxL <= 0 || m_MaxP <= 0)
                {
                    throw std::invalid_argument("m_MaxL or m_MaxP <= 0");
                }
            }
            ~MCEngine1D()
            {
                delete[] m_paths;
            }

            MCEngine1D(MCEngine1D const&) = delete;

            MCEngine1D& operator = (MCEngine1D const&) = delete;

            std::tuple <long, long, double const*>
            GetPaths() const
            {
                return ((m_L <= 0) || (m_P <= 0))
                ?std::make_tuple(0, 0, nullptr)
                :std::make_tuple(m_L, m_P, m_paths);
            }

            template <bool>
            void Simulate(time_t a_t0, time_t a_T, int a_tau_min, double a_S0, long a_P, Diffusion1D const* a_diff, AProvider const* a_rateA, BProvider const* a_rateB, AssetClassA a_A, AssetClassB a_B);
    };
}



/*#pragma once
#include<stdexcept>
#include<cstring>
#include<utility>
#include<tuple>
#include<ctime>
namespace SiriusFm
{
	template<typename Diffusion1D, typename AProvider, 
						typename BProvider, typename AssetClassA, typename AssetClassB>
	class MCEngine1D
	{	
	private:
		long const m_MaxL; // max PathLength
		long const m_MaxP; // max NPaths
		double * const m_paths;
		long m_L;
		long m_P;


	public:
		MCEngine1D(long a_MaxL, long a_MaxP)
		:m_MaxL(a_MaxL), m_MaxP(a_MaxP), m_L(0), m_P(0), m_paths(new double[m_MaxL*m_MaxP])
		{
			if(m_MaxL <= 0 || m_MaxP <=0)
				throw std::invalid_argument("must be positive");

		}
		template<bool IsRN>
		void Simulate(time_t a_t0, time_t a_T, int a_tau_min, long a_P, double a_S0,
			Diffusion1D const* a_diff, AProvider const* a_rateA, BProvider const* a_rateB,
			AssetClassA a_A, AssetClassB a_B);
		std::tuple<long, long, double const*>
		GetPaths() const
		{
			return 
			((m_L<=0) || (m_P<=0))?std::make_tuple(0,0,nullptr):std::make_tuple(m_L, m_P, m_paths);
		}


		~MCEngine1D()
		{
			delete[] m_paths;
		}
		MCEngine1D(MCEngine1D const&) = delete;
		MCEngine1D& operator = (MCEngine1D const&) = delete;
	};

	


}*/