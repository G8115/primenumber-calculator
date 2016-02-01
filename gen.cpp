#include"gen.h"
using namespace std;
gen::gen()//konstruktori
{
	this->paljon=0;
	this->d = thread::hardware_concurrency();//kertoo montako threadia koneen prosessori voi pyörittää yhtäaikaisesti
	this->duration=0;
	this->default.push_back(3);
	this->default.push_back(5);
	this->default.push_back(7);
	this->default.push_back(11);
	this->default.push_back(13);
	this->aito.alusta(default,5,169);
	asetaTarkistin(&aito);
	default.clear();
}
gen::~gen()//dekonstruktori
{
	cout<<"laukesi"<<endl;
	delete [] this->tarkistin;
	this->aito.~alkio();
	olo.clear();
}
void gen::asetaTarkistin(alkio*olio)//tarkistin taulukon maarittamiseksi
{
	delete[] this->tarkistin;//nollataan tarkistin
	this->tarkistin=new unsigned int [olio->taulukko.size()+2];//varataan tarkistimelle tarvittava tila
	tarkistin[0]=1;
	tarkistin[olio->taulukko.size()+1]=olio->taulukko.back()+2;
	for(unsigned int a=1;a<olio->taulukko.size()+1;a++)//for loop joka tallentaa vektorin taulukkoon
		this->tarkistin[a]=olio->taulukko.at(a-1);
}
void gen::kaynnista()//kaynnistaa itse algoritmin
{
	generaattori(&aito,2,1);
	asetaTarkistin(&aito);
	//generaattori(&aito,2,1);
	thread_kaynnistin();
	asetaTarkistin(&aito);
	//generaattori(&aito,2,1);
	thread_kaynnistin();
}
void gen::thread_kaynnistin()//moniydin ajon kaynnistamisen ja uudelleen kutsun helpoittamiseksi
{
	for(unsigned int a=0;a<d;a++)//alustetaan threadeille omat erilliset alkio oliot
	{
		alkio*tmp=new alkio;
		olo.push_back(tmp);
		olo.at(a)->alusta(default,aito.taulukko.size(),aito.taulukko.back()*aito.taulukko.back());
		tmp=NULL;
	}
	thread *langat=new thread[d];	
	for(unsigned int a=0;a<d;a++)
		langat[a]=thread(&gen::generaattori,this,olo.at(a),d*2,a+1);//käynnistetään threadit
	for(unsigned int a=0;a<d;a++)
		(langat+a)->join();//odotetaan jotta threadit lopettavat
	cout<<endl;
	for(unsigned int a=0;a<d;a++)//threadeissa generoidut alkuluvut asetetaan aito.taulukko:on
	{
		aito.taulukko.insert(aito.taulukko.end(),olo.at(a)->taulukko.begin(),olo.at(a)->taulukko.end());
		olo.at(a)->~alkio();
	}
	olo.clear();
	delete[] langat;
	aito.jarjesta();
	aito.x=aito.taulukko.back()*aito.taulukko.back();
	aito.toinenmonta=aito.taulukko.size();
}
void gen::generaattori(alkio *olo,int korotus,int monesko)//Alkuluvut laskeva aliohjelma.
{
	double aika; 
	bool alkuluku;
	int donatello=0;
	clock_t start;
	start=clock();
	int monta=olo->toinenmonta;//alkio olion arvot otetaan paikallisiksi muuttujiksi jotta laskeminen nopeutuisi
	unsigned int x=olo->x;
	
	for(unsigned int a=aito.taulukko.back()+2*monesko;a<x;a+=korotus)
	{
		alkuluku=true;
		donatello=sqrtf(a);
		for(unsigned int b=1;tarkistin[b-1]<donatello;b++)
		{
			if(a%tarkistin[b]==0)// % laskutoimituksen mahdollinen optimointi lisäisi nopeutta
			{
				alkuluku=false;
				b=olo->toinenmonta;
			}
		}
		if(alkuluku)
		{
			monta++;
			olo->taulukko.push_back(a);
			if(monta%100000==0)
			{
				aika=((clock()-start)/(double)CLOCKS_PER_SEC);
				start=clock();
				coat(aika,a);
			}
		}
	}
	olo->x=olo->taulukko.back()*olo->taulukko.back();
	olo->toinenmonta=olo->taulukko.size();
}
void gen::coat(double a,unsigned int b)//mutexattu cout
{
	juttu.lock();
	paljon+=100000;
	duration+=a;
	std::cout<<"                                                     "<<"\r";
	cout<<duration/d<<" | "<<a<<" | "<<paljon<<" | "<<b<<"\r";// \r kirjoittaa edellisten päälle eikä tee uutta riviä.
	juttu.unlock();
}
void gen::tallenna()//kirjoittaa alkuluvut.bin tiedostoon lasketut luvut binäärimuodossa
{
	unsigned int temp=0;
	int koko=aito.taulukko.size();
	ofstream tiedostot("alkuluvut.bin",ios_base::binary);//asetetaan binaarimuotoinen kirjoitusmuoto
	if(!tiedostot.is_open())
		cout<<"ERROR\n";
	cout<<"alkaa...."<<endl;
	tiedostot.seekp(0);//jotta tiedostoon kirjoitetaan alusta alkaen
	//c++11 for loop iteroi vektorin alkioiden yli.
	for(auto a:aito.taulukko)
		tiedostot.write((char*)&a,sizeof(a));
	tiedostot.close();
	cout<<"loppui"<<endl;
}
int gen::Get_threadCount()
{
	return d;
}
float gen::Get_duration() {
	return duration/d;
}
