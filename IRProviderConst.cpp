#include<cstdlib>
#include<cstdio>
#include"IRProviderConst.h"
namespace SiriusFm
{

	IRProvider<IRModeE::Const>::IRProvider(char const* a_file){

	/*if(a_file == nullptr || *a_file =='\0')
		return;*/

	FILE *fp = fopen("File.txt", "r");
		char buff[128] = {0};
		char name[4] = {0};
	if(a_file == nullptr || *a_file =='\0')
		return;

		
		//while(fgets(buff,128, fp) != nullptr){
		while(!feof(fp))
		{	
			fgets(buff,128, fp);
			for(int i=0; i<3; ++i){
				name[i] = buff[i];
			}
			m_IRs[int(str2Ccye(name))]= atof(buff+4);
		}
		fclose(fp);
	}
}

