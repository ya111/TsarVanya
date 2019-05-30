#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<iomanip>
using namespace std;
class transport
{
protected:
    string gos_number;
    string inv_number;
    int year;
    string mark;
    bool remont;
    string description;
public:
    virtual ~transport();
    string get_gn();
    string get_in();
    int get_year();
    void set_remont(bool x);
    string get_mark();
    string get_description();
    virtual void Show();
    virtual void ReadFromFile(ifstream &f);
    virtual void WriteToFile(ofstream &f);
    virtual void input();
};

class traktor: public transport
{
private:
    double ost_resource;
    double ost_resource_max;
    double power;
public:
    ~traktor();
    double get_ost_resource();
    double get_ost_resource_max();
    double get_power();
    void Show();
    void ReadFromFile(ifstream &f);
    void input();
    void WriteToFile(ofstream &f);
    bool check();

};

class bus: public transport
{
private:
    double ost_resource;
    double ost_resource_max;
    double pass_max;
public:
    ~bus();
    double get_ost_resource();
    double get_ost_resource_max();
    double get_pass_max();
    void Show();
    void ReadFromFile(ifstream &f);
    void input();
    void WriteToFile(ofstream &f);
    bool check();

};

class truck: public transport
{
private:
    double ost_resource;
    double ost_resource_max;
    double power;
    double carrying;
public:
    //truck();
    ~truck();
    double get_ost_resource();
    double get_ost_resource_max();
    double get_power();
    double get_carrying();
    void Show();
    void ReadFromFile(ifstream &f);
    void input();
    void WriteToFile(ofstream &f);
    bool check();

};



transport::~transport()
{
   // cout << "Deleted - " << Show() << endl;
}
string transport::get_gn()
{
    return gos_number;
}
string transport::get_in()
{
    return inv_number;
}
string transport::get_mark()
{
    return mark;
}
int transport::get_year()
{
    return year;
}
string transport::get_description()
{
    return description;
}
void transport::set_remont(bool x)
{
    remont = x;
}

void transport::Show()
{

    cout << " | �����: "    << internal << setw(10) << get_mark()
         << " | ��� �����: "    << internal << setw(10) << get_gn()
         << " | ��� �����: " << internal << setw(10) << get_in()
         << " | ���: "    << internal << setw(10) << get_year()
         << " | ��������: "    << internal << setw(15) << get_description();


}
void transport::ReadFromFile(ifstream &f)
{

}
void transport::WriteToFile(ofstream &f)
{

}
void transport::input()
{
    cout << "������� �����: ";
    cin >> mark;
    cout << "������� ��� �����: ";
    cin >> gos_number;
    cout << "������� ��� �����: ";
    cin >> inv_number;
    cout << "������� ���: ";
    cin >> year;
    if (remont == 1)
    {
        cout << "������� ��� ������� (������): ";
        cin >> description;
    } else description="��_���������������";
}

bool transport::check()
{
    return 1;
}
traktor::~traktor()
{
    //cout << "Deleted - " << Show() << endl;
}
double traktor::get_ost_resource()
{
    return ost_resource;
}
double traktor::get_ost_resource_max()
{
    return ost_resource_max;
}
double traktor::get_power()
{
    return power;
}

void traktor::Show()
{
    cout <<" ���������: �������  ";
    transport::Show();
    cout << " | ��� ������: "    << internal << setw(10) << get_ost_resource()
         << " | ��� ������ ����: "    << internal << setw(10) << get_ost_resource_max()
         << " | ��������: " << internal << setw(10) << get_power();


}
void traktor::ReadFromFile(ifstream &f)
{
    f>> mark >> gos_number >> inv_number >> year >> ost_resource >> ost_resource_max >> power>> remont >> description;
}
void traktor::WriteToFile(ofstream &f)
{
    f <<"traktor " << mark << " " << gos_number << " " << inv_number <<" "<< year << " " << ost_resource << " " <<  ost_resource_max << " " << power <<" "<<remont<<" "<<description<< endl;

}
void traktor::input()
{
    transport::input();
    cout << "������� ��� ������: ";
    cin >> ost_resource;
    cout << "������� ��� ������ ����: ";
    cin >> ost_resource_max;
    cout << "������� ��������: ";
    cin >> power;

}
bool traktor::check()
{
    if (ost_resource-ost_resource_max>=0)
    return true;
            else
            return false;
}

bus::~bus()
{
   // cout << "Deleted - " << Show() << endl;
}
double bus::get_ost_resource()
{
    return ost_resource;
}
double bus::get_ost_resource_max()
{
    return ost_resource_max;
}
double bus::get_pass_max()
{
    return pass_max;
}

void bus::Show()
{
    cout <<" ���������: �������  ";
    transport::Show();
    cout << " | ��� ������: "    << internal << setw(10) << get_ost_resource()
         << " | ��� ������ ����: "    << internal << setw(10) << get_ost_resource_max()
         << " | ��������������������: " << internal << setw(10) << get_pass_max();


}
void bus::ReadFromFile(ifstream &f)
{
    f>> mark >> gos_number >> inv_number >> year >> ost_resource >> ost_resource_max >> pass_max>> remont >> description;
}
void bus::WriteToFile(ofstream &f)
{
    f <<"bus " << mark << " " << gos_number << " " << inv_number << " "<< year << " " << ost_resource << " " <<  ost_resource_max << " " << pass_max <<" "<<remont<<" "<<description<< endl;

}
void bus::input()
{
    transport::input();
    cout << "������� ��� ������: ";
    cin >> ost_resource;
    cout << "������� ��� ������ ����: ";
    cin >> ost_resource_max;
    cout << "������� ��������������������: ";
    cin >> pass_max;

}
bool bus::check()
{
    if (ost_resource-ost_resource_max>=0)
    return true;
            else
            return false;
}
truck::~truck()
{
    //cout << "Deleted - " << Show() << endl;
}
double truck::get_ost_resource()
{
    return ost_resource;
}
double truck::get_ost_resource_max()
{
    return ost_resource_max;
}
double truck::get_power()
{
    return power;
}
double truck::get_carrying()
{
    return carrying;
}

void truck::Show()
{
    cout <<" ���������: �������� ";
    transport::Show();
    cout << " | ��� ������: "    << internal << setw(10) << get_ost_resource()
         << " | ��� ������ ����: "    << internal << setw(10) << get_ost_resource_max()
         << " | ��������: " << internal << setw(10) << get_power()
         << " | ����������������: " << internal << setw(10) << get_carrying();


}
void truck::ReadFromFile(ifstream &f)
{
    f>> mark >> gos_number >> inv_number >> year >> ost_resource >> ost_resource_max >> power  >> carrying >> remont >> description;
}
void truck::WriteToFile(ofstream &f)
{
    f <<"truck " << mark << " " << gos_number << " " << inv_number <<" " << year << " " << ost_resource << " " <<  ost_resource_max << " " << power << " "  << carrying <<" "<<remont<<" "<<description<< endl;

}
void truck::input()
{
    transport::input();
    cout << "������� ��� ������: ";
    cin >> ost_resource;
    cout << "������� ��� ������ ����: ";
    cin >> ost_resource_max;
    cout << "������� ��������: ";
    cin >> power;
    cout << "������� ����������������: ";
    cin >> carrying;
}
bool truck::check()
{
    if (ost_resource-ost_resource_max>=0)
    return true;
            else
            return false;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    vector <transport *> ts; // ������� ������ ����������
    bool isProgramActive = true;
    while (isProgramActive) // ���� �� ��������� ������� � ���������� ���������, ��������� ��� ����
    {
        cout << "1. �������� ����� ��\n"
                "2. �������� �� ����� �������\n"
                "3. ������� �� � ������� ���������� � ���\n"
                "4. ������� ��� ��\n"
                "5. ������� ��� �� � ���������� �������� �������� ����� ���������\n"
                "6. ����� ���� ���������\n"
                "7. ����� ���� ���������\n"
                "8. ����� ���� �������� ����\n"
                "0. ����� �� ���������\n"
                "9. �������� �� �� �����\n"
                "10. �������� �� � ����\n"
                    "\n������� ����� ��������: ";
        //156790
        int action = -1;
        cin >>action;
        cout << endl;
        switch (action)
        {
        case 0:
        {
            for ( int i = 0; i<ts.size();i++)
            {
                delete ts[i];
            }
            isProgramActive = false;
            break;
        }
        case 1:

        {
            cout << "������� ��� ����������(traktor, bus, truck): ";
            string type;
            cin >> type;
            transport *t=0;
            if (type=="traktor")t=new traktor;
            if (type=="bus")t=new bus;
            if (type=="truck") t=new truck;
            t->set_remont(0);
            t->input();
            ts.push_back(t);
            break;
        }
        case 2:
        {
            cout << "������� ��� ����������(traktor, bus, truck): ";
            string type;
            cin >> type;
            transport *t=0;
            if (type=="traktor")t=new traktor;
            if (type=="bus")t=new bus;
            if (type=="truck") t=new truck;
            t->set_remont(1);
            t->input();
            ts.push_back(t);
            break;
        }
        case 3:
        {
            int id = -1;
            while (id < 0)
            {
                cout << "������� ����� ���������� � ������ : ";
                cin >> id;
                if (id >= ts.size())
                id = -1;
            }
            cout << "������� ��: ";
            ts[id]->Show();
            delete ts[id];     // ����������� ���.������
            ts.erase(ts.begin() + id);  // ������� ��������� �� �������
            break;
        }
        case 4:
        {
            for (int i = 0; i < ts.size(); i++)
            {
                cout << i << ". ";           // �����
                ts[i]->Show();
                cout <<endl;
             }
            break;
        }
        case 5:
        {
            int k=0;
            for ( int i = 0; i < ts.size(); i++)
            {

                if ( ts[i]->check()==false)
                {
                    cout << k << ". ";           // �����
                    ts[i]->Show();
                    k++;
                    cout <<endl;
                }

             }
            break;
        }
        case 6:
        {
            int k=0;
            for ( int i = 0; i < ts.size(); i++)
            {
                traktor* tr = dynamic_cast<traktor*>(ts[i]);
                if (tr)
                {
                    cout << k << ". ";           // �����
                    ts[i]->Show();
                    k++;
                    cout <<endl;
                }
             }
            break;
        }
        case 7:
        {
            int k=0;
            for ( int i = 0; i < ts.size(); i++)
            {
                bus* tr = dynamic_cast<bus*>(ts[i]);
                if (tr)
                {
                    cout << k << ". ";           // �����
                    ts[i]->Show();
                    k++;
                    cout <<endl;
                }
             }
            break;
        }
        case 8:
        {
            int k=0;
            for ( int i = 0; i < ts.size(); i++)
            {
                truck* tr = dynamic_cast<truck*>(ts[i]);
                if (tr)
                {
                    cout << k << ". ";           // �����
                    ts[i]->Show();
                    k++;
                    cout <<endl;
                }
             }
            break;
        }
        case 9:
        {
            ifstream fin("C:/Users/PavelP/input.txt");
           // ifstream fin("E:\input.txt");
            while (!fin.eof())
            {
                string type;
                fin >> type;
                transport *t=0;
                if (type=="traktor") t=new traktor;
                if (type=="bus") t=new bus;
                if (type=="truck") t=new truck;
                if(t)
                {
                    t->ReadFromFile(fin);
                    ts.push_back(t);
                }
            }
            break;
        }
        case 10:
        {
            ofstream fout("C:/Users/PavelP/input.txt");
            for (int i = 0; i<ts.size();++i)
            {
                ts[i]->WriteToFile(fout);
            }
            break;
        }


        }
    }
}
