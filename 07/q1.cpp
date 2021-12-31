#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;

public:
    Car(int gas)
        : gasolineGauge(gas)
    {
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;

public:
    HybridCar(int gas, int hybrid)
        : Car(gas), electricGauge(hybrid)
    {
    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;

public:
    HybridWaterCar(int gas, int hybrid, int water)
        : HybridCar(gas, hybrid), waterGauge(water)
    {
    }
    void ShowCurrentGauge()
    {
        cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
        cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
        cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
    }
};