#include <iostream>//tarvittavat kirjastot
#include <vector>
#include <algorithm>

using namespace std;

class alkio//kontainerluokka joka helpottaa funktiokutsun tekemistä generaattoriluokassa;
{
public://kaikki luokan arvot julkisia koska niiden manipuloinnin on oltava mahdollisimman yksinkertaista ja nopeaa
	vector<unsigned int>taulukko;
	unsigned int x;
	unsigned int toinenmonta;
	alkio(){x=0;toinenmonta=0;}
	~alkio(){taulukko.clear();}
	void alusta(vector<unsigned int>asd,unsigned int _toinenmonta,unsigned int _x);//asettaa alkion arvot
	void jarjesta();//algorithm kirjaston sort vektorille
};