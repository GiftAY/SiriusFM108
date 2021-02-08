#include<iostream>
#include"Diffusion.h"
#include"IRProviderConst.h"
using namespace SiriusFm;
int main()
{
	IRProvider<IRModeE::Const> irp("File.txt");
	std::cout << irp.r(CcyE::RUB, 1) << "\n";
	
}
