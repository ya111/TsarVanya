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

    cout << " | Марка: "    << internal << setw(10) << get_mark()
         << " | Гос номер: "    << internal << setw(10) << get_gn()
         << " | Инв номер: " << internal << setw(10) << get_in()
         << " | Год: "    << internal << setw(10) << get_year()
         << " | Описание: "    << internal << setw(15) << get_description();


}
void transport::ReadFromFile(ifstream &f)
{

}
void transport::WriteToFile(ofstream &f)
{

}
void transport::input()
{
    cout << "Введите марку: ";
    cin >> mark;
    cout << "Введите гос номер: ";
    cin >> gos_number;
    cout << "Введите инв номер: ";
    cin >> inv_number;
    cout << "Введите год: ";
    cin >> year;
    if (remont == 1)
    {
        cout << "Введите тип ремонта (слитно): ";
        cin >> description;
    } else description="Не_ремонтировалась";
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
    cout <<" Транспорт: трактор  ";
    transport::Show();
    cout << " | Ост ресурс: "    << internal << setw(10) << get_ost_resource()
         << " | Ост ресурс макс: "    << internal << setw(10) << get_ost_resource_max()
         << " | Мощность: " << internal << setw(10) << get_power();


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
    cout << "Введите ост ресурс: ";
    cin >> ost_resource;
    cout << "Введите ост ресурс макс: ";
    cin >> ost_resource_max;
    cout << "Введите мощность: ";
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
    cout <<" Транспорт: автобус  ";
    transport::Show();
    cout << " | Ост ресурс: "    << internal << setw(10) << get_ost_resource()
         << " | Ост ресурс макс: "    << internal << setw(10) << get_ost_resource_max()
         << " | Пассажировместимость: " << internal << setw(10) << get_pass_max();


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
    cout << "Введите ост ресурс: ";
    cin >> ost_resource;
    cout << "Введите ост ресурс макс: ";
    cin >> ost_resource_max;
    cout << "Введите Пассажировместимость: ";
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
    cout <<" Транспорт: грузовик ";
    transport::Show();
    cout << " | Ост ресурс: "    << internal << setw(10) << get_ost_resource()
         << " | Ост ресурс макс: "    << internal << setw(10) << get_ost_resource_max()
         << " | Мощность: " << internal << setw(10) << get_power()
         << " | Грузоподъемность: " << internal << setw(10) << get_carrying();


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
    cout << "Введите ост ресурс: ";
    cin >> ost_resource;
    cout << "Введите ост ресурс макс: ";
    cin >> ost_resource_max;
    cout << "Введите мощность: ";
    cin >> power;
    cout << "Введите грузоподъемность: ";
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
    vector <transport *> ts; // создаем вектор указателей
    bool isProgramActive = true;
    while (isProgramActive) // пока не поступило сигнала о завершении программы, выполняем код ниже
    {
        cout << "1. Добавить новое ТС\n"
                "2. Добавить ТС после ремонта\n"
                "3. Удалить ТС и вывести информацию о нем\n"
                "4. Вывести все ТС\n"
                "5. Вывести все ТС с остаточным остатком ресурсов менее заданного\n"
                "6. Вывод всех тракторов\n"
                "7. Вывод всех автобусов\n"
                "8. Вывод всех грузовых авто\n"
                "0. Выход из программы\n"
                "9. Добавить ТС из файла\n"
                "10. Добавить ТС в файл\n"
                    "\nВведите номер действия: ";
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
            cout << "Введите тип автомобиля(traktor, bus, truck): ";
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
            cout << "Введите тип автомобиля(traktor, bus, truck): ";
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
                cout << "Введите номер автомобиля в списке : ";
                cin >> id;
                if (id >= ts.size())
                id = -1;
            }
            cout << "Удалили ТС: ";
            ts[id]->Show();
            delete ts[id];     // освобождаем дин.память
            ts.erase(ts.begin() + id);  // удаляем указатель из вектора
            break;
        }
        case 4:
        {
            for (int i = 0; i < ts.size(); i++)
            {
                cout << i << ". ";           // номер
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
                    cout << k << ". ";           // номер
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
                    cout << k << ". ";           // номер
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
                    cout << k << ". ";           // номер
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
                    cout << k << ". ";           // номер
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
