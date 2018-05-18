#ifndef TEMPERATURA_H
#define TEMPERATURA_H

class Temperatura
{
public:
    int n;
    
    void setTipo(int tp);
    void setUmidade(int um);
    void setTemp(int t);
    void setPressao (bool pa); // 1)True 0)False
   
    void imp();
    
private:
    int tipo; // 1-Celsius 2-Fahrenheit 3-Kelvin
    int Temp; // Temperatura 
    int Umidade;
    bool Pressao;
};


void Temperatura :: imp()
{
    std::cout << "Tipo de Escala:..............................." << tipo << std::endl;
    std::cout << "Temperatura Ambiente:........................." << Temp << std::endl;
    std::cout << "Umidade Relativa do Ar(%):...................." << Umidade << std::endl;
    std::cout << "Presença ou não de precipitação Atmosférica:.." << Pressao << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
}
 void Temperatura :: setTipo(int tp)
 {
    tipo = tp;
 }
 void Temperatura:: setUmidade(int um)
{
    Umidade = um;
}
void Temperatura :: setTemp(int t)
{
    Temp = t;
}
void Temperatura::setPressao(bool pa)
{
    Pressao = pa;
}

    class Celsius:public Temperatura
    {
    public:
        Celsius();
    };
    Celsius::Celsius()
    {
        setTipo(1);
        setTemp(32);
        setUmidade(90);
        setPressao(true);
    }
    
    
    class Fahrenheit:public Temperatura
    {
    public:
        Fahrenheit();
    };
    Fahrenheit::Fahrenheit()
    {
        setTipo(2);
        setTemp(42);
        setUmidade(13);
        setPressao(true);
    }
    
    
    class Kelvin:public Temperatura
    {
    public:
        Kelvin();
    };
    Kelvin::Kelvin()
    {
        setTipo(3);
        setTemp(342);
        setUmidade(24);
        setPressao(true);
    }
  
#endif /* TEMPERATURA_H */

