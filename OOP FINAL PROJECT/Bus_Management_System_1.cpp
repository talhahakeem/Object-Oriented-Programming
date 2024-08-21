#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
class ManagementSystem
{
public:
    virtual void menu() = 0; // Pure virtual function
};
class Bus : public ManagementSystem
{
private:
    string b_no, b_name, d_name;
    int b_seats;
public:
    void menu() override;
    void new_bus();
    void bus_details();
    void single_bus();
    void all_buses();
};
void Bus::menu()
{
    a:
    system("cls");
    int option;
    cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
    cout << "\n\n\t\t\t\t\t 1.ADD BUS RECORD" << endl;
    cout << "\t\t\t\t\t 2.VIEW BUSES DETAIL" << endl;
    cout << "\t\t\t\t\t 3.EXIT" << endl;
    cout << "\n\t\t\t\t\t Please Select An Option:";
    cin >> option;
    switch (option)
    {
    case 1:
        new_bus();
        break;
    case 2:
        bus_details();
        break;
    case 3:
        return ;
    default:
        cout << "\n\t\t\t\t\t Invalid Option...Please Try Again..." << endl;
    }
    getch();
    goto a;
}
void Bus::new_bus()
{
    b:
    system("cls");
    cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
    fstream file;
    string t_no, tb_name, td_name;
    int t_seats, found = 0;
    cout << "\n\n Bus No : ";
    cin >> b_no;
    cout << "\n\n Bus Name : ";
    cin >> b_name;
    cout << "\n\n Total Seats : ";
    cin >> b_seats;
    cout << "\n\n Driver Name : ";
    cin >> d_name;
    file.open("bus.txt", ios::in);
    if (!file)
    {
        file.open("bus.txt", ios::app | ios::out);
        file << b_no << " " << b_name << " " << b_seats << " " << d_name << "\n";
        file.close();
    }
    else
    {
        file >> t_no >> tb_name >> t_seats >> td_name;
        while (!file.eof())
        {
            if (b_no == t_no)
            {
                found++;
            }
            file >> t_no >> tb_name >> t_seats >> td_name;
        }
        file.close();
        if (found == 0)
        {
            file.open("bus.txt", ios::app | ios::out);
            file << b_no << " " << b_name << " " << b_seats << " " << d_name << "\n";
            file.close();
        }
        else
        {
            cout << "\n\n Duplicate Record Found...";
            getch();
            goto b;
        }
    }
    cout << "\n New Bus Inserted Successfully....";
}
void Bus::bus_details()
{
    a:
    system("cls");
    int option;
    cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
    cout << "\n\n\t\t\t\t\t\t  1.Single Bus Record";
    cout << "\n\n\t\t\t\t\t\t  2.All Buses Record";
    cout << "\n\n\t\t\t\t\t\t  3.Go Back";
    cout << "\n\n\t\t\t\t\t\t  Select Your Option:";
    cin >> option;
    switch (option)
    {
    case 1:
        single_bus();
        break;
    case 2:
        all_buses();
        break;
    case 3:
        menu();
    default:
        cout << "\n\n Invalid Option...Please Try Again...";
    }
    getch();
    goto a;
}

void Bus::single_bus()
{
    system("cls");
    string t_no;
    int found = 0;
    fstream file;
    cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Not Found...";
    }
    else
    {
        cout << "\n\n Bus No:";
        cin >> t_no;
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            if (t_no == b_no)
            {
                system("cls");
                cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
                cout << "\n\n\t\t\t BUS NUMBER.\t\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
                cout << "\n\t\t\t    " << b_no << "\t\t  " << b_name << "\t\t    " << b_seats << "\t\t    " << d_name << endl;
                found++;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n Invalid Bus No...";
        }
    }
}
void Bus::all_buses()
{
    system("cls");
    fstream file;
    cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Not Found...";
    }
    else
    {
        cout << "\n\n\t\t\t BUS NUMBER.\t\tBUS NAME\tNO. OF SEATS\tDRIVER NAME" << endl;
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            cout << "\t\t\t    " << b_no << "\t\t  " << b_name << "\t\t    " << b_seats << "\t\t    " << d_name << endl;
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
    }
}
class Booking_System: public ManagementSystem
{
private:
    string b_no, b_name, d_name;
    int b_seats;
public:
    void menu() override;
    void booking();
    void show_booking();
};
void Booking_System::menu()
{
    a:
    system("cls");
    int option;
    cout << "\n\t\t\t\t\t --------BookING MANAGEMENT SYSTEM--------"<<endl;
    cout << "\t\t\t\t\t 1.BOOKING" << endl;
    cout << "\t\t\t\t\t 2.SHOW ALL BOOKING RECORD" << endl;
    cout << "\t\t\t\t\t 3.EXIT" << endl;
    cout << "\n\t\t\t\t\t Please Select An Option:";
    cin >> option;
    switch (option)
    {
    case 1:
        booking();
        break;
    case 2:
        show_booking();
        break;
    case 3:
        return ;
    default:
        cout << "\n\t\t\t\t\t Invalid Option...Please Try Again..." << endl;
    }
    getch();
    goto a;
}
void Booking_System::booking()
{
p:
    system("cls");
    fstream file;
    int found = 0, s_no, seats, count = 0, s_s_no, ss_no[25], i = 0, s_amount, total_amount = 0, r_amount;
    string t_no, s_b_no, customer_name, phone, from, to;
    char x;
    cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error.......";
    }
    else
    {
        cout << "\n\n Bus No:";
        cin >> t_no;
        file.close();
        file.open("seat.txt", ios::in);
        if (file)
        {
            file >> s_b_no >> s_s_no;
            while (!file.eof())
            {
                if (t_no == s_b_no)
                {
                    count++;
                }
                file >> s_b_no >> s_s_no;
            }
            file.close();
        }
        file.open("bus.txt", ios::in);
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            if (t_no == b_no)
            {
                seats = b_seats;
                found++;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        if (seats - count == 0)
        {
            cout << "\n\n All Seats Are Reserved";
        }
        else if (found == 1)
        {
            do
            {
            h:
                cout << "\n\n Seat No:";
                cin >> s_no;
                if (s_no > seats)
                {
                    cout << "\n\n Seat No. Is InValid..... Please Try Another";
                    goto h;
                }
                file.open("seat.txt", ios::in);
                if (!file)
                {
                    file.open("seat.txt", ios::app | ios::out);
                    file << t_no << " " << s_no << "\n";
                    file.close();
                }
                else
                {
                    file >> s_b_no >> s_s_no;
                    while (!file.eof())
                    {
                        if (t_no == s_b_no && s_no == s_s_no)
                        {
                            cout << "\n\n Seat is already reserved.... Please Try Another";
                            file.close();
                            goto h;
                        }
                        file >> s_b_no >> s_s_no;
                    }
                    file.close();
                    file.open("seat.txt", ios::app | ios::out);
                    file << t_no << " " << s_no << "\n";
                    file.close();
                }
                ss_no[i] = s_no;
                i++;
                cout << "\n\n Booking Another Seat (Y/N):";
                cin >> x;
            } while (x == 'Y' || x == 'y');
            system("cls");
            cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
            cout << "\n\n Customer Name: ";
            cin >> customer_name;
            cout << "\n\n Customer Phone No: ";
            cin >> phone;
            cout << "\n\n From: ";
            cin >> from;
            cout << "\n\n To: ";
            cin >> to;
            cout << "\n\n Single Seat Amount: ";
            cin >> s_amount;
            total_amount = s_amount * i;
            cout << "\n\n Total Amount:    " << total_amount << endl;
            cout << "\n\n Recieved Amount:  ";
            cin >> r_amount;
            file.open("customer.txt", ios::app | ios::in);
            file << customer_name << " " << t_no << " " << phone << " " << i << " " << total_amount << "\n";
            file.close();
            system("cls");
            cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
            cout << "\n\n\t\t\t\t\t\t    ***************";
            cout << "\n\n\t\t\t\t\t       <---BOOKING INFORMATION--->";
            cout << "\n\n\t\t\t\t\t\t    ***************";
            cout << "\n\t\t\t\t\t Name:	 			" << customer_name;
            cout << "\n\t\t\t\t\t From:	 			" << from;
            cout << "\n\t\t\t\t\t To: 				" << to;
            cout << "\n\t\t\t\t\t Total Seats: 			" << i;
            cout << "\n\t\t\t\t\t Reserved Seats: 		";
            for (int a = 0; a < i; a++)
            {
                if (a != 0)
                    cout << " , ";
                cout << ss_no[a];
            }
            cout << "\n\t\t\t\t\t Single Seat Amount: 		" << s_amount;
            cout << "\n\t\t\t\t\t Total Seat Amount: 		" << total_amount;
            cout << "\n\t\t\t\t\t Recieved Amount: 		" << r_amount;
            cout << "\n\t\t\t\t\t Return Amount: 		" << r_amount - total_amount;
            cout << "\n\n\t\t\t\t\t\t    ***************";
            cout << "\n\n\t\t\t\t\t\t Thank You For Booking";
            cout << "\n\n\t\t\t\t\t\t    ***************";
        }
        else
        {
            cout << "\n\n Bus No is Invalid Please try again later..... ";
            getch();
            goto p;
        }
    }
}
void Booking_System::show_booking()
{
    system("cls");
    fstream file;
    int t_seats, t_amount, found = 0;
    string name, phone, no;
    cout << "\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
    file.open("customer.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\t\t\t\t\t File Opening Error....";
    }
    else
    {
        file >> name >> no >> phone >> t_seats >> t_amount;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t\t\t =======================================";
            cout << "\n\n\n\t\t\t\t\t\t Customer Name:" << name;
            cout << "\n\n\t\t\t\t\t\t Bus No:" << no;
            cout << "\n\n\t\t\t\t\t\t Phone No:" << phone;
            cout << "\n\n\t\t\t\t\t\t Reserved Seats:" << t_seats;
            cout << "\n\n\t\t\t\t\t\t Total Amount:" << t_amount;
            cout << "\n\n\t\t\t\t\t =======================================";
            found++;
            file >> name >> no >> phone >> t_seats >> t_amount;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n\t\t\t\t\t No Booking Record Found...";
        }
    }
}
int main()
{
    system("color F0");
    ManagementSystem *system_ptr;
    Bus bus_system;
    Booking_System booking_system;
    int choice;
    do {
        system("cls");
        cout << "\n\t\t\t\t\t--------WELCOME TO BUS MANAGEMENT SYSTEM--------" << endl;
        cout << "\n\t\t\t\t\tChoose a system to interact with: \n";
        cout << "\n\t\t\t\t\t1. Bus Details \n";
        cout << "\n\t\t\t\t\t2. Booking Details \n";
        cout << "\n\t\t\t\t\t3. Exit\n";
        cout << "\n\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                system_ptr = &bus_system;
                system_ptr->menu();
                break;
            case 2:
                system_ptr = &booking_system;
                system_ptr->menu();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                getch();
        }
    } while (choice != '3');
    return 0;
}