#include <iostream>
using namespace  std;

class Ship{
    string Shipname;
    string Shipyear;
public:
    Ship(string Shipname, string Shipyear){
        this->Shipname=Shipname;
        this->Shipyear=Shipyear;
    }

    Ship() {
        Shipname="", Shipyear="";
    }

    string getShipname(){
        return Shipname;
    }

    string getShipyear(){
        return Shipyear;
    }

    void setShipname(string in){
        Shipname=in;
    }

    void setShipyear(string in){
        Shipyear=in;
    }

    virtual void print(){
        cout<<"SHIP\n";
        cout<<"Ship name " << getShipname()<<"\n";
        cout<<"Shp year "<<getShipyear()<<"\n\n";
    }
};

class CruiseShip:public Ship{
    int maxPassengers;
public:
    CruiseShip(string Shipname, int maxPassengers){
        this->setShipname(Shipname);
        this->maxPassengers=maxPassengers;
    }
    CruiseShip(){
        maxPassengers=0;
    }

    int getmaxPassengers(){
        return maxPassengers;
    }

    void setmaxPassengers(int in){
        maxPassengers=in;
    }

    void print(){
        cout << "CRUISESHIP\n";
        cout<<"Ship name "<<getShipname()<<"\n";
        cout<<"Maximum number of passengers "<<getmaxPassengers()<<"\n\n";
    }
};

class CargoShip:public Ship{
    int cargoCapacity;
public:
    CargoShip(string Shipname ,int cargoCapacity){
        this->setShipname(Shipname);
        this->cargoCapacity=cargoCapacity;
    }

    CargoShip(){
        cargoCapacity=0;
    }

    int getcargoCapacity(){
        return cargoCapacity;
    }

    void setcargoCapacity(int in){
        cargoCapacity=in;
    }

    void print (){
        cout<<"CARGOSHIP\n";
        cout <<"Ship name "<<getShipname()<<"\n";
        cout<<"Ship cargo capacity "<<getcargoCapacity()<<"\n\n";
    }
};

int main()
{
    Ship* s[3];

    Ship s1("Ammar ship", "2022");
    CruiseShip crs("Ammar cruise", 10);
    CargoShip cas("Ammar cargo" , 10);

    s[0]  = &s1;
    s[1] = &crs;
    s[2] = &cas;


    for (int i = 0; i < 3; ++i) {
        s[i]->print();
    }

    return 0;
}