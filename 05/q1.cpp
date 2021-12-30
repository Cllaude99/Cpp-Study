#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIT,
        MANAGER
    };
}
class NameCard
{
private:
    char *name;
    char *company;
    char *phone;
    int rank;

public:
    NameCard(const char *name, const char *company, const char *phone, int rank)
        : rank(rank)
    {
        this->name = new char[strlen(name) + 1];
        this->company = new char[strlen(company) + 1];
        this->phone = new char[strlen(phone) + 1];

        strcpy(this->name, name);
        strcpy(this->company, company);
        strcpy(this->phone, phone);
    }

    NameCard(const NameCard &ref)
        :rank(ref.rank)
        {
            this->name = new char[strlen(ref.name) + 1];
            this->company = new char[strlen(ref.company) + 1];
            this->phone = new char[strlen(ref.phone) + 1];

            strcpy(this->name, ref.name);
            strcpy(this->company, ref.company);
            strcpy(this->phone, ref.phone);
        }
    void ShowNameCardInfo() const
    {
        cout << "�̸�: " << name << endl;
        cout << "ȸ��: " << company << endl;
        cout << "��ȭ��ȣ: " << phone << endl;

        switch (rank)
        {
        case COMP_POS::CLERK:
            cout << "���" << endl
                 << endl;
            break;
        case COMP_POS::SENIOR:
            cout << "����" << endl
                 << endl;
            break;
        case COMP_POS::ASSIT:
            cout << "�븮" << endl
                 << endl;
            break;
        case COMP_POS::MANAGER:
            cout << "����" << endl
                 << endl;
            break;
        }
    }
    ~NameCard()
    {
        delete[] name;
        delete[] company;
        delete[] phone;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIT);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}