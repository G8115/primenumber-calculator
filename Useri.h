//t�m� luokka on ohjelman k�ytt�liittym�� varten
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
	gen x;//luokassa k�ytett�v�t oliot gen x ja lukija y
	lukija y;
	void PaaValikko(); //metodi p��valikon tulostamiseen
	void KysyValinta();//metodi sy�tteen lukemiseen
	void GetProcessorName();//internetist� l�ydetty metodi prosessorin nimen saamiseksi
	ifstream tieto;
public:
	Useri();//konstruktori
	~Useri();//tuhoaja
	void Motor();//metodi switch case rakenteelle jota p��valikko k�ytt��
	void tallennaTulos();//tallentaa tuloksen


};
