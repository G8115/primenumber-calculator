#include <string>
#include <iostream>
#include <vector>
class abstraktitulostin//koska virtuaalifunktio ja perint�
{
protected:
	virtual void lue()=0;
	std::string nimi;
	std::vector<unsigned int> luvut;
};