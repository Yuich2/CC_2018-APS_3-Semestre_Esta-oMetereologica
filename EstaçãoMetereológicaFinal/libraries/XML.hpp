
#ifndef XML_H
#define XML_H

#include <string>
#include <sstream>
#include <iomanip>

using std::string;

class XML {
public:
    XML();
    XML(const XML& orig);
    virtual ~XML();
    void gerarDadosXML( int i, float fahrenheit, int celsius, float humidity, int rain);
    void iniciarXML();
    std::string getXML();
	
private:
    std::string xmlOut;
    std::string transformToString(float n); 
};

#endif /* XML_H */

