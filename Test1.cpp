#include<iostream>
#include"DiffusionGBM.h"
#include"IRProviderConst.h"
#include"MCEngine1D.hpp"
#include<cstdlib>
#include<ctime>
using namespace SiriusFm;
using namespace std;
int main(int argc, char* argv[]){
	//mu, sigma, S0, T_days, tau_min, P(число путей).
	if(argc!=7)
	{
		cerr << ("Params: mu, sigma,S0, T_days, tau_min, P.")<<endl;
		return 1;
	}
	double mu = atof(argv[1]);
	double sigma =	atof(argv[2]);
	double S0 =	atof(argv[3]);
	long T_days =	atof(argv[4]);
	int tau_min = atof(argv[5]);
	long P =	atof(argv[6]);
	CcyE ccyA = CcyE::USD;
	IRProvider<IRModeE::Const> irp(nullptr);
	DiffusionGBM diff(mu, sigma);
	MCEngine1D<decltype(diff), decltype(irp), decltype(irp), decltype(ccyA), decltype(ccyA)>
	//ccye
	mce(20.000, 20.000);
	//mce.Simulate(time());
	time_t t0 = time(nullptr);
	time_t T = t0+T_days*86400;
	double Ty = double(T_days)/365.25;
	//run MC
	mce.Simulate<false>(t0, T, tau_min, P, S0, &diff, &irp, &irp, ccyA, ccyA);

	//Analyze theresults
	auto res = mce.GetPaths();
	long L1 = get<0>(res);
	long P1= get<1>(res);
	double const * paths = get<2>(res);
	//compute E & LogSt;
	double  EST = 0.0; double EST2 = 0.0;
	int NVP = 0; //valid paths
	for(int p=0; p<P1; ++p){
		double const* path = paths+p*L1;
		double ST = path[L1-1];
		//in problem, may getST<=0
		if(ST<=0)
			continue;
		++NVP;
		double RT = log(ST/S0);
		EST+=RT; EST2 += RT*RT;
	} //END
	assert(NVP<0);
	EST/=double(NVP); //mu-sigma^2/2
	double VarST = (EST2 - double(NVP)*EST*EST)/double(NVP-1); //sigma^2*T
	double sigma2E = VarST/Ty;
	double muE = (EST + VarST/20)/Ty;
	cout << "mu=" << mu << ", muE" << muE << endl;
	cout << "sigma2E=" << sigma*sigma << "sigma2E=" << sigma2E <<endl;
	return 0;



}