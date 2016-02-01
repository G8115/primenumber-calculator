#include "lukija.h"
lukija::lukija()//konstruktori
{
	
	//eofbit, failbit and badbit are member constants with implementation-defined values that can be combined 
	//(as if with the bitwise OR operator), so that the stream throws when any of the selected error state flags is set.
	tiedosto.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
}
bool lukija::jatkaa()//haluatko jatkaa?
{
	string temp;
	cout<<"Haluatko jatkaa y/n"<<endl;
	cin>>temp;
	if(temp=="y"||temp=="yes"||temp=="Y"||temp=="YES"||temp=="Yes")
	{
		return 1;
	}
	a=0;
	b=0;
	return 0;
}
int lukija::koetalue()//virheen hallintaa varten
{
	try
	{
		lue();
	}
	catch(ifstream::failure e)
	{
		if(!tiedosto.is_open())
		{
			cout<<"ERROR alkuluvut.bin NOT FOUND"<<endl;
			return 0;
		}
		tiedosto.clear();
		tiedosto.seekg(0,ios_base::end);
		int temp=tiedosto.tellg()/sizeof(int);
		if(a<0||b<0||a>temp||b>temp)
		{
			cout<<"ERROR huonot rajat"<<endl;
			if(jatkaa())
			{
				kysyrajat();
				koetalue();
				return 0;
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}
void lukija::kaynnista()//kaynnistaa ohjelmalogiikan
{
	kysyrajat();
	koetalue();
	koetatallentaa();
}
void lukija::kysynimi()//kysyy tiedoston nimen
{
	cout<<"anna tiedoston nimi :";
	cin>>this->nimi;
}
void lukija::kysyrajat()//kysyy mistä luvut luetaan
{
	cout<<"monennestako alkuluvusta moneneteenko";
	cin>>this->a>>this->b;
	if(b<a)
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
}
void lukija::lue()//funktio joka lukee tiedostosta alkuluvut
{
	this->nimi="alkuluvut.bin";
	this->luvut.clear();
	tiedosto.open(this->nimi,ios::binary);
	tiedosto.seekg(a*sizeof(unsigned int));
	for(;tiedosto.read((char*)&x,sizeof(unsigned int))&&a<=b;a++)
	{
		this->luvut.push_back(x);
	}
}
void lukija::talenna()//tallentaa luetut luvut haluttuun txt tiedostoon
{
	int koko=this->luvut.size();
	if(koko==0)
	{
		throw this;
	}
	kysynimi();
	manna.open(nimi);
	if(!manna.is_open())
	{
		throw this;
	}
	else
	{
		//c++11 for loop iteroi automaattisesti vectorin alkioiden yli
		for(int a:luvut)
		{
			manna<<a<<endl;
		}
	}
}
int lukija::koetatallentaa()//virheen hallintaa varten
{
	try
	{
		talenna();
	}
	catch(lukija*)
	{
		if(luvut.size()==0)
		{
			return 0;
		}
		if(!manna.is_open())
		{
			cout<<"ERROR tallennus ei onnistunut"<<endl;
			return 0;
		}
	}
	return 1;
}