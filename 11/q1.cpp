#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum)
        :bullet(bnum)
    { }
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;
public:
    Police(int bnum,int bcuff)
        :handcuffs(bcuff)
    {
        if(bnum>0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police&ref)
    {
        handcuffs = ref.handcuffs;
        if(ref.pistol == NULL)
            pistol = NULL;
        else
            pistol = new Gun(*(ref.pistol));
    }
    Police&operator=(const Police&ref)
    {
        if(pistol!=NULL)
            delete pistol;
        if(ref.pistol == NULL)
            pistol = NULL;
        else
            pistol = new Gun(*(ref.pistol));

        handcuffs = ref.handcuffs;
        return *this;
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol==NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }
    ~Police()
    {
        if(pistol!=NULL)
            delete pistol;
    }
};