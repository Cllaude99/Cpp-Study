#include <iostream>

int main()
{
    int pay = 50;
    int money;

    while (1)
    {
        std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
        std::cin >> money;
        if(money == -1)
        {
            std::cout << "���α׷��� �����մϴ�." << std::endl;
            break;
        }
        std::cout << "�̹� �� �޿�: " << pay + money * 0.12 << "����" << std::endl;
    }
}