//Task: basketball
//Author: Valentina Spasova
#include <iostream>
using namespace std;

int main()
{
    long long int n,p,k;
    cin >> n >> p >> k;
    long long int first = 0; //����� ���� � ��������� ������� ����
    long long int out = 0; //����� �� ������, ����� ������� �� ����� ��� ����������� ���������
    long long int basket = out; //����� �� ������, ����� ������ � ������������ �����
    long long int ost = 0;//����� �� ���������� ����, ����� �� ����� �������� ��� ���������� ���������

    //����� �� ������ � ����� � ��-��-����� �� �
    while (n >= k && basket < p && ost < k-1)
    {
        out = (n + ost)/k;
        ost = (n + ost)%k;
        first++;
        basket += out;
        n = n - out;
    }
    if (basket >= p)
    {
        cout << first << endl << "VOLLEYBALL" << endl;
        return 0;
    }
    if (ost == k-1)
    {
        cout << first+1 << endl << "BASKETBALL" << endl;
        return 0;
    }

    //����� �� ������ � ����� � ��-����� �� �
    long long int last = 0;//��������� ����� �� ���������� ��������� ����
    while (basket < p && last != 1)
    {
        first += (k - ost) / n;
        last = (k - ost) % n;
        if (last >= 1)
        {
            first++;
            ost = n - last;
        }
        else ost = 0;
        n--;
        basket++;
    }
    if (last == 1) cout << first << endl << "BASKETBALL" << endl;
    else cout << first << endl << "VOLLEYBALL" << endl;

return 0;
}
