
#include "libraries/XML.hpp"


XML::XML() {
}

XML::XML(const XML& orig) {
}

XML::~XML() {
}
void XML::gerarDadosXML( int i, float fahrenheit, int celsius, float humidity, int rain)
{
    
     std::string iTemp, celsiusTemp, humidityTemp, fahrenheitTemp;

     //transform numbers into strings
     iTemp = std::to_string(i);
     celsiusTemp = std::to_string(celsius);

     fahrenheitTemp = transformToString(fahrenheit);
     humidityTemp = transformToString(humidity);

     xmlOut += "    <celsius"+iTemp+ "> "+celsiusTemp+" </celsius"+iTemp+">\n   <fahrenheit"+iTemp+">"+fahrenheitTemp+"</fahrenheit"+iTemp+">\n     <humidity"+iTemp+">"+humidityTemp+"</humidity"+iTemp+">\n";

     if(rain)
          xmlOut +="<chuva"+iTemp+">Sem Chuva</chuva"+iTemp+">\n\n";
     else
          xmlOut += "<chuva"+iTemp+">Com Chuva</chuva"+iTemp+">\n\n";
}

void XML::iniciarXML()
{

    xmlOut = "<?xml version=\"1.0\" encoding = \"UTF-8\"?> \n<data>\n\n";

}

std::string XML::getXML()
{

    xmlOut += "</data>";
    return xmlOut;
      
}

std::string XML::transformToString(float n)
{

    //making the number go less precise
    std::ostringstream cutObj1;
    cutObj1 << std::fixed;
    cutObj1 << std::setprecision(1);
    cutObj1 << n;

    return cutObj1.str();
		
}


