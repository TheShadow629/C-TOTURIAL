#ifndef WEATHER_DATA_H_INCLUDED
#define WEATHER_DATA_H_INCLUDED


#include<iostream>
using namespace std;

class Weather_Data//weather data
{
public:
    string getWAST()
    {
        return WAST;
    }
    void setWAST(string wast)
    {
        this->WAST = wast;
    }

    string getDP()
    {
        return DP;
    }
    void setDP(string DP)
    {
        this->DP = DP;
    }


    string getDta()
    {
        return Dta;
    }
    void setDta(string Dta)
    {
        this->Dta = Dta;
    }

    string getDts()
    {
        return Dta;
    }
    void setDts(string Dts)
    {
        this->Dts = Dts;
    }

    string getEV()
    {
        return EV;
    }
    void setEV(string Dts)
    {
        this->EV = Dts;
    }

    string getQFE()
    {
        return QFE;
    }
    void setQFE(string Dts)
    {
        this->QFE = Dts;
    }

    string getQFF()
    {
        return QFE;
    }
    void setQFF(string Dts)
    {
        this->QFF = Dts;
    }

    string getQNH()
    {
        return QNH;
    }
    void setQNH(string Dts)
    {
        this->QNH = Dts;
    }

    string getRF()
    {
        return RF;
    }
    void setRF(string Dts)
    {
        this->RF = Dts;
    }

    string getRH()
    {
        return RH;
    }
    void setRH(string Dts)
    {
        this->RH = Dts;
    }

    string getS()
    {
        return S;
    }
    void setS(string Dts)
    {
        this->S = Dts;
    }

    string getSR()
    {
        return SR;
    }
    void setSR(string Dts)
    {
        this->SR = Dts;
    }

    string getST1()
    {
        return ST1;
    }
    void setST1(string Dts)
    {
        this->ST1 = Dts;
    }

    string getST2()
    {
        return ST2;
    }
    void setST2(string Dts)
    {
        this->ST2 = Dts;
    }

    string getST3()
    {
        return ST3;
    }
    void setST3(string Dts)
    {
        this->ST3 = Dts;
    }

    string getST4()
    {
        return ST4;
    }
    void setST4(string Dts)
    {
        this->ST4 = Dts;
    }

    string getSx()
    {
        return Sx;
    }
    void setSx(string Dts)
    {
        this->Sx = Dts;
    }

    string getT()
    {
        return T;
    }
    void setT(string Dts)
    {
        this->T = Dts;
    }
public:
    string WAST;
    string DP;
    string Dta;
    string Dts;
    string EV;
    string QFE;
    string QFF;
    string QNH;
    string RF;
    string RH;
    string S;
    string SR;
    string ST1;
    string ST2;
    string ST3;
    string ST4;
    string Sx;
    string T;
};


#endif // WEATHER_DATA_H_INCLUDED
