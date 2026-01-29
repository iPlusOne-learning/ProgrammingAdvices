#pragma once
#include <iostream>
#include <string>


using namespace std;


class InterfaceCommunication
{


    public:

    virtual void SendEmail(string Titlte, string Body) = 0;
    virtual void SendFax(string Titlte, string Body) = 0;
    virtual void SendSMS(string Titlte, string Body) = 0;
};