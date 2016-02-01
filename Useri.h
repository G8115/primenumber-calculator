//tämä luokka on ohjelman käyttöliittymää varten
//alla tarvittavat headerit
#include <windows.h>
#include "gen.h"
#include "lukija.h"
#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif
using namespace std;
//alla luokka Useri
class Useri
{
private:
	int valinta;//muuttuja
	bool suoritettu;
	bool tallennettu;
	gen x;//luokassa käytettävät oliot gen x ja lukija y
	lukija y;
	void PaaValikko(); //metodi päävalikon tulostamiseen
	void KysyValinta();//metodi syötteen lukemiseen
	void GetProcessorName();//internetistä löydetty metodi prosessorin nimen saamiseksi
	ifstream tieto;
public:
	Useri();//konstruktori
	~Useri();//tuhoaja
	void Motor();//metodi switch case rakenteelle jota päävalikko käyttää
	void tallennaTulos();//tallentaa tuloksen


};
