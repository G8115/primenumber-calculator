#include <ctime>//tarvittavat kirjastot. luoka.h:n include tuo siinä käytetyt kirjastot
#include <thread>
#include <mutex>
#include<algorithm>
#include<fstream>
#include "alkio.h"
using namespace std;
class gen
{
private:
	unsigned int*tarkistin;
	unsigned int paljon;
	unsigned int d;
	double duration;
	mutex juttu;
	vector<unsigned int> default;
	alkio aito;
	vector<alkio*>olo;
	void thread_kaynnistin();//moniydin ajon kaynnistamisen ja uudelleen kutsun helpoittamiseksi
	void generaattori(alkio *olo,int korotus,int monesko);//tätä kutsua varten alkio luokka on olemassa
	void coat(double a,unsigned int b);//mutex:illla toimiva naytolle tulostava funktio jotta multithread
	void asetaTarkistin(alkio*);//muuttaa alkiosta löytyvän vektorin dynaamisesti varattuun int taulukkoon
public:
	int Get_threadCount();
	float Get_duration();
	gen();//konstruktori
	~gen();//dekonstruktori
	void kaynnista();//kaynnistaa algoritmin
	void tallenna();//tallentaa lasketut alkuluvut alkuluvut.bin:iin
};