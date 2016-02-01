//Useri luokan toteutukset ja alla headeri include
#include "Useri.h";


Useri::Useri() { //alustajassa alustetaan luokan ainoa muuttuja 0:ksi
	valinta = 0;
	suoritettu = 0;
	tallennettu = 0;
};

void Useri::PaaValikko() {
	//paavalikko metodin tulostus komennot ja alussa toteutetaan metodi joka tuo 
	//prosessorin tiedot ja k‰ytett‰vien threadien lukum‰‰r‰n
	GetProcessorName();
	cout<<"Alkulukugeneraattori"<<endl;
	cout<<"Mittaa tietokoneen prosessorin laskentatehoa"<<endl;
	cout<<"1 Laske alkuluvut"<<endl;
	cout<<"2 Tallenna alkuluvut"<<endl;
	cout<<"3 Lue alkuluvut a:sta b:hen"<<endl;
	cout<<"4 Tulos"<<endl;
	cout<<"5 Tallenna tulos"<<endl;
	cout<<"0 lopeta"<<endl;
};

Useri::~Useri() {
	//dekonstruktori
	x.~gen();
	y.~lukija();
};

void Useri::KysyValinta() {
	//metodi joka kysyy k‰ytt‰j‰lt‰ mit‰ toteutetaan
	PaaValikko();
	cout<<endl;
	cout<<"anna valinta: "<<endl;
	cin>>valinta;
	
};

void Useri::Motor() {
	//switch case moottori joka on osa p‰‰valikkoa
	valinta = 6; //virhevalintaa varten toteutettava sijoitus
	while(valinta) {
	switch (valinta) {
	case 0://lopettaa ohjelman
		break;
	case 1://k‰ynnist‰‰ alkulukulaskimen
		{
			if (!suoritettu)
			{
				//alla tulostus joka selkeytt‰‰ mit‰ v‰liaikatiedot ovat
				cout<<"Kok.aika | Thrd.aika | Alk.kpl | Viim.alk " <<endl; 
				suoritettu = 1;
				x.kaynnista();
				break;
			}
			else
			{
				if (system("CLS")) system("clear");
				cout<<"Alkuluvut laskettu. Valitse tallenna jos haluat tallentaa alkuluvut."<<endl;
				Sleep(2000);
				if (system("CLS")) system("clear");
				break;
			}
		}
	case 2:
		{
			if (suoritettu)
			{
				x.tallenna();
				tallennettu = 1;
				break;
			}
			else
			{
				if (system("CLS")) system("clear");
				cout<<"Laske ensin alkuluvut, jotta voit tallentaa ne."<<endl;
				Sleep(2000);
				if (system("CLS")) system("clear");
				break;
			}
		}
	case 3:
		{
			tieto.open("alkuluvut.bin", ios::binary);
			if(tieto.is_open())
			{
				tieto.close();
				y.kaynnista();
			}
			else
			{
				tieto.close();
				if (system("CLS")) system("clear");
				cout<<"Sinun tulee ensin tallentaa, jotta voit lukea tiedoston"<<endl;
				Sleep(2000);
				if (system("CLS")) system("clear");
			}
			break;
		}
	case 4:
		{
			if(suoritettu)
			{
				cout<<x.Get_duration()<<" sekuntia"<<endl;
				break;
			}
			else
			{
				if (system("CLS")) system("clear");
				cout<<"Laske ensin alkuluvut, jotta voit saada tuloksen."<<endl;
				Sleep(2000);
				if (system("CLS")) system("clear");
				break;
			}
		}
	case 5:
		{
			if (suoritettu)
			{
				tallennaTulos();
				break;
			}
			else
			{
				if (system("CLS")) system("clear");
				cout<<"Laske ensin alkuluvut, jotta voit tallentaa tuloksen."<<endl;
				Sleep(2000);
				if (system("CLS")) system("clear");
				break;
			}
		}
	case 6:
		{
		if (system("CLS")) system("clear");
		break;
		}
	default:
		{
			if (system("CLS")) system("clear");
				cout<<"Vaara valinta!."<<endl;
				Sleep(2000);
				if (system("CLS")) system("clear");
				break;
		}
	

	}
	KysyValinta();
	}
};

void Useri::GetProcessorName()
{
	int CPUInfo[4] = {-1};
	char CPUBrandString[0x40];	
	__cpuid(CPUInfo, 0x80000000);
	unsigned int nExIds = CPUInfo[0];

	memset(CPUBrandString, 0, sizeof(CPUBrandString));

	// Get the information associated with each extended ID.
	for (int i=0x80000000; i<=nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		// Interpret CPU brand string.
		if  (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if  (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if  (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}
	cout<<CPUBrandString<<endl;
	cout<<"Threadeja kaytossa: "<<x.Get_threadCount()<<endl<<endl;

};

void Useri::tallennaTulos() {
	ofstream result;
	int CPUInfo[4] = {-1};
	char CPUBrandString[0x40];	
	__cpuid(CPUInfo, 0x80000000);
	unsigned int nExIds = CPUInfo[0];

	memset(CPUBrandString, 0, sizeof(CPUBrandString));

	// Get the information associated with each extended ID.
	for (int i=0x80000000; i<=nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		// Interpret CPU brand string.
		if  (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if  (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if  (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}
	result.open("result.txt");
	result<<CPUBrandString<<endl<<x.Get_duration()<<endl;
}