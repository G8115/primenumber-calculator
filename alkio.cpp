#include"alkio.h"
void alkio::alusta(vector<unsigned int>asd,unsigned int _toinenmonta,unsigned int _x)//asettaa arvot
{
	taulukko.clear();
	this->toinenmonta=_toinenmonta;
	this->x=_x;
	for(unsigned int a=0;a<asd.size();a++)
		taulukko.push_back(asd.at(a));
}
void alkio::jarjesta()//jarjestaa vectorin
{
	sort(taulukko.begin(),taulukko.end());
}