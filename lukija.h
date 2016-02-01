#include"Abstraktitulostin.h"//en jaksa
#include<fstream>
using namespace std;

class lukija:abstraktitulostin//koska virtuaalifunktio ja perintä
{
private:
	int a,b;
	unsigned int x;
	ifstream tiedosto;
	ofstream manna;
	void kysynimi();//kysyy tiedoston nimen
	void kysyrajat();//kysyy mistä luvut luetaan
	void talenna();//tallentaa luetut luvut haluttuun txt tiedostoon
	void lue();//funktio joka lukee tiedostosta alkuluvut
	int koetalue();//virheen hallintaa varten
	int koetatallentaa();//virheen hallintaa varten
	bool jatkaa();//haluatko jatkaa?
public:
	void kaynnista();//kaynnistaa ohjelmalogiikan
	lukija();//konstruktori
	~lukija(){luvut.clear();};//dekonstruktori
};