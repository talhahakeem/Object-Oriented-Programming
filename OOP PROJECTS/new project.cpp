#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bus{								//bus class
	private:							//access specifier
		string b_no,b_name,d_name;		
		int b_seats;
	public:
		void menu();					
		void new_bus();
		void bus_details();
		void single_bus();
		void all_buses();
		void update_bus();
		void del_bus();					//member functions
		void bus_route();
		void detail_bus();
		void booking();
		void renew_seats();
		void search_booking();
		void update_booking();
		void del_booking();
		void show_booking();
};
void bus::menu(){						//function for menu
	a:
	system("cls");						//clear screen
	int option;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	cout<<"\n\n\t\t\t\t\t 1.ADD BUS RECORD" << endl;
	cout<<"\t\t\t\t\t 2.VIEW BUSES DETAIL" << endl;
	cout<<"\t\t\t\t\t 3.UPDATE BUS DETAIL" << endl;
	cout<<"\t\t\t\t\t 4.DELETE BUS DETAIL" << endl;
	cout<<"\t\t\t\t\t 5.ROUTES OF BUSES"<<endl;
	cout<<"\t\t\t\t\t 6.BOOKING"<<endl;
	cout<<"\t\t\t\t\t 7.BUS SEATS DETAILS"<<endl;
	cout<<"\t\t\t\t\t 8.SEARCH BOOKING RECORD"<<endl;
	cout<<"\t\t\t\t\t 9.UPDATE BOOKING RECORD"<<endl;
	cout<<"\t\t\t\t\t 10.DELETE BOOKING RECORD"<<endl;
	cout<<"\t\t\t\t\t 11.SHOW ALL BOOKING RECORD"<<endl;
	cout<<"\t\t\t\t\t 12.EXIT"<<endl;
	cout<<"\n\t\t\t\t\t Please Select An Option:";
	cin>>option;
	switch(option){
		case 1:
			new_bus();
			break;
		case 2:
			bus_details();
			break;
		case 3:
			update_bus();
			break;
		case 4:
			del_bus();
			break;
		case 5:
			bus_route();
			break;
		case 6:								//functions calling
			booking();
			break;
		case 7:
			detail_bus();
			break;
		case 8:
			search_booking();
			break;
		case 9:
			update_booking();
			break;
		case 10:
			del_booking();
			break;					
		case 11:
			show_booking();
			break;
		case 12:
			exit(0);
		default:
			cout<<"\n\t\t\t\t\t Invalid Option...Please Try Again..."<<endl;
	}
	getch();
	goto a;
}
void bus::new_bus(){				//function for adding bus
	b:
	system("cls");
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	fstream file;					//object of file
	string t_no,tb_name,td_name;
	int t_seats,found=0;
	cout<<"\n\n Bus No : ";
	cin>>b_no;
	cout<<"\n\n Bus Name : ";
	cin>>b_name;
	cout<<"\n\n Total Seats : ";
	cin>>b_seats;
	cout<<"\n\n Driver Name : ";
	cin>>d_name;
	file.open("bus.txt",ios::in);	//open file for read mode to check record exist in file or not
	if(!file){				//if file dont exist
	
		//add new record
	
		file.open("bus.txt",ios::app | ios::out);		//open file for write and append mode to change value
		file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n"; //data entry in file
		file.close();									//close file
	}	
	else{					//file exist
		file>>t_no>>tb_name>>t_seats>>td_name;			//fetching data from file
		while(!file.eof()){								//loop( execute till data end from file) 
			if(b_no==t_no){								//to check bus and the number user enter match or not
				found++;								//record found in file
			}
			file>>t_no>>tb_name>>t_seats>>td_name;
		}
		file.close();
		if(found==0){									// record does not exist
			file.open("bus.txt",ios::app | ios::out);	//enter record
			file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			file.close();	
		}
		else{											//record exist
			cout<<"\n\n Duplicate Record Found...";
			getch();
			goto b;
		}
	}
	cout<<"\n New Bus Inserted Successfully....";
}
void bus::bus_details(){		//function for chceking buses
	a:
	system("cls");
	int option;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	cout<<"\n\n\t\t\t\t\t\t  1.Single Bus Record";
	cout<<"\n\n\t\t\t\t\t\t  2.All Buses Record";
	cout<<"\n\n\t\t\t\t\t\t  3.Go Back";
	cout<<"\n\n\t\t\t\t\t\t  Select Your Option:";
	cin>>option;
	switch(option){
		case 1:
			single_bus();
			break;
		case 2:
			all_buses();
			break;
		case 3:
			menu();
		default:
			cout<<"\n\n Invalid Option...Please Try Again...";
	}
	getch();
	goto a;
}
void bus::single_bus(){				//function to check single bus record
	system("cls");
	string t_no;
	int found=0;
	fstream file; 
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("bus.txt",ios::in);
	if(!file){
		cout<<"\n\n File Not Found...";
	}
	else{
		cout<<"\n\n Bus No:";
		cin>>t_no;
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof()){
			if(t_no == b_no){
				system("cls");
				cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
				cout<<"\n\n\t\t\t BUS NUMBER.\t\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
				cout<<"\n\t\t\t    "<<b_no<<"\t\t  "<<b_name<<"\t\t    "<<b_seats<<"\t\t    "<<d_name<<endl;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		if(found == 0){
			cout<<"\n\n Invalid Bus No...";
		}
	}
}
void bus::all_buses(){
	system("cls");
	fstream file; 
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("bus.txt",ios::in);
	if(!file){
		cout<<"\n\n File Not Found...";
	}
	else{
		cout<<"\n\n\t\t\t BUS NUMBER.\t\tBUS NAME\tNO. OF SEATS\tDRIVER NAME"<<endl;
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof()){
			cout<<"\t\t\t    "<<b_no<<"\t\t  "<<b_name<<"\t\t    "<<b_seats<<"\t\t    "<<d_name<<endl;
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
	}
}
void bus::update_bus(){
	system("cls");
	fstream file,file1;	//variable of files
	string t_no,n_no,n_name,nd_name;
	int n_seats,found=0;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("bus.txt",ios::in);  //open existing file for read mode
	
	//now check file exist or not 
	
	if(!file){
		cout<<"\n\n File Not Found...";
	}
	else{
		cout<<"\n\n Bus No:";
		cin>>t_no;
		file1.open("bus1.txt",ios::app | ios::out);		//opening new file
		file>>b_no>>b_name>>b_seats>>d_name;		//fetching data from existing file
		while(!file.eof()){
			if(t_no==b_no){
				cout<<"\n\n Enter New Bus Number:";
				cin>>n_no;
				cout<<"\n\n Enter New Bus Name:";
				cin>>n_name;
				cout<<"\n\n Enter New Bus Seats:";
				cin>>n_seats;
				cout<<"\n\n Enter New Bus Driver's Name:";
				cin>>nd_name;
				file1<<n_no<<" "<<n_name<<" "<<n_seats<<" "<<nd_name<<"\n";
				cout<<"\n\n\n BUS RECORD UPDATED SUCCESSFULLY... ";
				found++;
			}
			else{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		file1.close();
		remove("bus.txt");					//built in function to remove file
		rename("bus1.txt","bus.txt");		//built in function to rename file
		if(found==0){				//condition to check the record we want to find found or not
			cout<<"\n\n Invlaid Bus Number...";
		}
	}
}
void bus::del_bus(){
	system("cls");
	fstream file,file1;	//variable of files
	string t_no;
	int found=0;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("bus.txt",ios::in);  //open existing file for read mode
	
	//now check file exist or not 
	
	if(!file){
		cout<<"\n\n File Not Found...";
	}
	else{
		cout<<"\n\n Bus No:";
		cin>>t_no;
		file1.open("bus1.txt",ios::app | ios::out);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof()){
			if(t_no==b_no){
				cout<<"\n\n\n BUS RECORD DELETED SUCCESSFULLY... ";
				found++;
			}
			else{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		file1.close();
		remove("bus.txt");					//built in function to remove file
		rename("bus1.txt","bus.txt");		//built in function to rename file
		if(found==0){				//condition to check the record we want to find found or not
			cout<<"\n\n Invlaid Bus Number...";
		}
	}
}
void bus::bus_route(){              // defining bus routes 
	a:
	system("cls");
	int option;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	cout<<"\n\n\t\t\t\t\t      <------ROUTE DETAILS------>";
	cout<<"\n\n\t\t\t\t\t\t 1. 1st ROUTE DETAILS";
	cout<<"\n\n\t\t\t\t\t\t 2. 2nd ROUTE DETAILS";
	cout<<"\n\n\t\t\t\t\t\t 3. 3rd ROUTE DETAILS";
	cout<<"\n\n\t\t\t\t\t\t 4. 4th ROUTE DETAILS";
	cout<<"\n\n\t\t\t\t\t\t 5. 5th ROUTE DETAILS";
	cout<<"\n\n\t\t\t\t\t\t Enter Your Choice:";
	cin>>option;
	system("cls");
	switch(option){
		case 1:
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			cout<<"\n\n\t\t\t\t\t\t From LAHORE TO FAISALABAD";
			cout<<"\n\t\t\t\t\t     9:00 am ................ 11:00 am";
			cout<<"\n\n\t\t\t\t\t\t  From LAHORE TO KARACHI";
			cout<<"\n\t\t\t\t\t      12:00 am ............ 02:30 am";
			cout<<"\n\n\t\t\t\t\t\t From LAHORE TO GUJRANWALA";
			cout<<"\n\t\t\t\t\t     9:00 am ................. 4:30 pm";
			cout<<"\n\n\t\t\t\t\t\t   From LAHORE TO MULTAN";
			cout<<"\n\t\t\t\t\t       7:00 am ............. 2:00 pm";
			cout<<"\n\n\t\t\t\t\t\t From LAHORE TO ISLAMABAD";
			cout<<"\n\t\t\t\t\t     4:00 am ................ 6:30 am";
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			break;
		case 2:
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			cout<<"\n\n\t\t\t\t\t     From FAISALABAD TO BAHAWALPUR";
		    cout<<"\n\t\t\t\t\t     9:00 am ............ 10:00 am";
		    cout<<"\n\n\t\t\t\t\t      From FAISALABAD TO ISLAMABAD";
		    cout<<"\n\t\t\t\t\t     12:00 am ............. 1:00 am";
		    cout<<"\n\n\t\t\t\t\t       From FAISALABAD TO KARACHI";
			cout<<"\n\t\t\t\t\t     10:00 am ............ 11:00 am";
			cout<<"\n\n\t\t\t\t\t       From FAISALABAD TO LAHORE";
			cout<<"\n\t\t\t\t\t     4:00 am ............ 10:30 am";
			cout<<"\n\n\t\t\t\t\t       From FAISALABAD TO MULTAN";
			cout<<"\n\t\t\t\t\t     5:00 pm ............. 9:30 pm";	
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			break;
		case 3:
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			cout<<"\n\n\t\t\t\t\t        From ISLAMABAD TO LAHORE";
			cout<<"\n\t\t\t\t\t      8:00 am ............ 9:30 am";
			cout<<"\n\n\t\t\t\t\t      From ISLAMABAD TO FAISALABAD";
			cout<<"\n\t\t\t\t\t      12:30 am ........... 2:30 am";
			cout<<"\n\n\t\t\t\t\t        From ISLAMABAD TO MURREE";
			cout<<"\n\t\t\t\t\t      5:00 am ............ 7:30 am";
			cout<<"\n\n\t\t\t\t\t        From ISLAMABAD TO MANSEHRA";
			cout<<"\n\t\t\t\t\t       3:40 am ............ 9:30 am";
			cout<<"\n\n\t\t\t\t\t        From ISLAMABAD TO JEHLUM";
			cout<<"\n\t\t\t\t\t      5:00 am ............ 7:30 am";
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			break;
		case 4:
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			cout<<"\n\n\t\t\t\t\t      From RAWALPINDI TO SIALKOT";
			cout<<"\n\t\t\t\t\t    1:00 pm ............. 10:30 pm";
			cout<<"\n\n\t\t\t\t\t      From RAWALPINDI TO LAHORE";
			cout<<"\n\t\t\t\t\t    8:00 pm ............ 10:30 pm";
			cout<<"\n\n\t\t\t\t\t      From RAWALPINDI TO FAISLABAD";
			cout<<"\n\t\t\t\t\t    5:00 pm ............ 7:30 pm";
			cout<<"\n\n\t\t\t\t\t      From RAWALPINDI TO ISLAMABAD";
			cout<<"\n\t\t\t\t\t    11:00 pm .............. 1:30 pm";
			cout<<"\n\n\t\t\t\t\t      From RAWALPINDI TO MULTAN";
			cout<<"\n\t\t\t\t\t    5:00 pm ............ 10:30 pm";
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			break;
		case 5:
			cout<<"\n\n\t\t\t\t\t\t    ***************";
			cout<<"\n\n\t\t\t\t\t\t From MULTAN TO LAHORE";
			cout<<"\n\t\t\t\t\t     8:00 pm ............ 12:00 am";
			cout<<"\n\n\t\t\t\t\t       From MULTAN TO FAISLABAD";
			cout<<"\n\t\t\t\t\t     11:00 pm ........... 3:30 am";
			cout<<"\n\n\t\t\t\t\t\t From MULTAN TO QUETTA";
			cout<<"\n\t\t\t\t\t     5:00 am ............ 7:30 am";
			cout<<"\n\n\t\t\t\t\t\t From MULTAN TO DASKA";
			cout<<"\n\t\t\t\t\t     3:40 am ............ 6:30 am";
			cout<<"\n\n\t\t\t\t\t       From MULTAN TO GUJRANWALA";
			cout<<"\n\t\t\t\t\t     6:00 pm ............ 11:00 pm";
			break;
		default:
			cout<<"\n\n Invalid Choice...";
			getch();
			goto a;		
	}
}
void bus::booking(){
		p:
		system("cls");
		fstream file;
		int found=0,s_no,seats,count=0,s_s_no,ss_no[25],i=0,s_amount,total_amount=0,r_amount;
		string t_no,s_b_no,customer_name,phone,from,to;
		char x;
		cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
		file.open("bus.txt",ios::in);
		if(!file){
			cout<<"\n\n File Opening Error.......";
		}
		else{
			cout<<"\n\n Bus No:";
			cin>>t_no;
			file.close();
			file.open("seat.txt",ios::in);
		    if(file){
			file>>s_b_no>>s_s_no;
			while(!file.eof()){
				if(t_no == s_b_no){
					count++;
				}
				file>>s_b_no>>s_s_no;
			}
			file.close();
		}
			file.open("bus.txt",ios::in);
			file>>b_no>>b_name>>b_seats>>d_name;
			while(!file.eof()){
					if(t_no == b_no){
						seats = b_seats;
						found++;
					}
				file>>b_no>>b_name>>b_seats>>d_name;
			}
			file.close();
			if(seats-count==0){
				cout<<"\n\n All Seats Are Reserved";
			}
			else if(found == 1){
				do{
					h:
					cout<<"\n\n Seat No:";
					cin>>s_no;
					if(s_no > seats){
						cout<<"\n\n Seat No. Is InValid..... Please Try Another";
						goto h;
					}
					file.open("seat.txt",ios::in);
					if(!file){
						 file.open("seat.txt",ios::app| ios::out);
						 file<<t_no<<" "<<s_no<<"\n";
						 file.close();
					}
					else{
						file>>s_b_no>>s_s_no;
						while(!file.eof()){
							if(t_no == s_b_no && s_no == s_s_no){
								cout<<"\n\n Seat is already reserved.... Please Try Another";
								file.close();
								goto h;
							}
					    	file>>s_b_no>>s_s_no;
						}
						file.close(); 
						file.open("seat.txt",ios::app| ios::out);
						file<<t_no<<" "<<s_no<<"\n";
						file.close();
					}
					ss_no[i] = s_no;
					i++;
					cout<<"\n\n Booking Another Seat (Y/N):";
					cin>>x;	
				}
				while(x == 'Y' || x == 'y'); 
				system("cls");
				cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
				cout<<"\n\n Customer Name: "; 
				cin>>customer_name;
				cout<<"\n\n Customer Phone No: ";
			    cin>>phone;
			    cout<<"\n\n From: ";
			    cin>>from;
			    cout<<"\n\n To: ";
				cin>>to;
			    cout<<"\n\n Single Seat Amount: ";
			    cin>>s_amount;
			    total_amount = s_amount*i;
				cout<<"\n\n Total Amount:    "<<total_amount<<endl;
				cout<<"\n\n Recieved Amount:  ";
				cin>>r_amount;
				file.open("customer.txt",ios::app|ios::in);
				file<<customer_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";
				file.close();
				system("cls");
				cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
				cout<<"\n\n\t\t\t\t\t\t    ***************";				    
				cout<<"\n\n\t\t\t\t\t       <---BOOKING INFORMATION--->";
				cout<<"\n\n\t\t\t\t\t\t    ***************";
				cout<<"\n\t\t\t\t\t Name:	 			"<<customer_name;
				cout<<"\n\t\t\t\t\t From:	 			"<<from;
				cout<<"\n\t\t\t\t\t To: 				"<<to;
				cout<<"\n\t\t\t\t\t Total Seats: 			"<<i;
				cout<<"\n\t\t\t\t\t Reserved Seats: 		";
				for(int a=0;a<i;a++){
					if(a != 0)
					cout<<" , ";
					cout<<ss_no[a];
				}
				cout<<"\n\t\t\t\t\t Single Seat Amount: 		"<<s_amount;
				cout<<"\n\t\t\t\t\t Total Seat Amount: 		"<<total_amount;
				cout<<"\n\t\t\t\t\t Recieved Amount: 		"<<r_amount;
				cout<<"\n\t\t\t\t\t Return Amount: 		"<<r_amount-total_amount;
				cout<<"\n\n\t\t\t\t\t\t    ***************";
				cout<<"\n\n\t\t\t\t\t\t Thank You For Booking";
				cout<<"\n\n\t\t\t\t\t\t    ***************";
			}	
			else{
				cout<<"\n\n Bus No is Invalid Please try again later..... ";
				getch();
				goto p;
			}
		}
	}	
void bus::detail_bus(){
		system("cls");
		fstream file,file1;
		string t_no,s_b_no,s_no;
		int count=0,found=0;
		cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
		file.open("bus.txt",ios::in);
		file1.open("seat.txt",ios::in);
		if(!file || !file1){
			cout<<"\n\n File Opening Error"; 
		}
		else{
			cout<<"\n\n Bus No.";
			cin>>t_no;
			file1>>s_b_no,t_no;
			while(!file1.eof()){
				if(t_no == s_b_no){
				count++;
			}
			file1>>s_b_no,t_no;
		}
		file1.close();
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof()){
			if(t_no == b_no){
				system("cls");
				cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
				cout<<"\n\n\t\t\t\t\t\t    ***************";				    
				cout<<"\n\n\t\t\t\t\t       <----SEATS INFORMATION---->";
				cout<<"\n\n\t\t\t\t\t     Total No Of Seats:		"<<b_seats;
				cout<<"\n\n\t\t\t\t\t     Reserved No Of Seats:	"<<count;
				cout<<"\n\n\t\t\t\t\t     Empty No Of Seats:		"<<b_seats-count;
				found++;
			}
			file>>b_no>>b_name>>b_seats>>d_name;	
		}
			file.close();
			if(found == 0){
				cout<<"\n\n Bus No.Is Invalid";
			}
		}
	}
void bus::search_booking(){
	system("cls");
	fstream file;
	int t_seats,t_amount,found=0;
	string name,t_name,phone,no;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("customer.txt",ios::in);
	if(!file){
		cout<<"\n\n\t\t\t\t\t File Opening Error....";
	}
	else{
		cout<<"\n\n\t\t\t\t\t Customer Name:";
		cin>>t_name;
		file>>name>>no>>phone>>t_seats>>t_amount;	
		while(!file.eof()){
			if(t_name==name){
				if(found==0){
					system("cls");
					cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
				}
				cout<<"\n\n\t\t\t\t\t =======================================";
				cout<<"\n\n\n\t\t\t\t\t\t Customer Name:"<<name;
				cout<<"\n\n\t\t\t\t\t\t Bus No:"<<no;
				cout<<"\n\n\t\t\t\t\t\t Phone No:"<<phone;
				cout<<"\n\n\t\t\t\t\t\t Reserved Seats:"<<t_seats;
				cout<<"\n\n\t\t\t\t\t\t Total Amount:"<<t_amount;
				cout<<"\n\n\t\t\t\t\t =======================================";
				found++;
			}
			file>>name>>no>>phone>>t_seats>>t_amount;
		}
		file.close();
		if(found==0){
			cout<<"\n\n\t\t\t\t\t Customer Name Is Invalid...";
		}
	}
}
void bus::update_booking(){
	system("cls");
	fstream file,file1;
	int t_seats,t_amount,found=0,del_seats,i=0;
	string name,t_name,phone,t_phone,no,del_no;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("customer.txt",ios::in);
	if(!file){
		cout<<"\n\n\t\t\t\t\t File Opening Error....";
	}
	else{
		cout<<"\n\n\t\t\t\t\t Phone Number:";
		cin>>t_phone;
		file>>name>>no>>phone>>t_seats>>t_amount;
		while(!file.eof()){
			if(t_phone==phone){
				file.close();
				file.open("customer.txt",ios::in);
				file1.open("customer1.txt",ios::app|ios::out);
				file>>name>>no>>phone>>t_seats>>t_amount;
				while(!file.eof()){
					if(t_phone==phone){
						del_no=no;
						del_seats=t_seats;
					}
					if(t_phone!=phone){
						file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amount<<"\n";
					}
					file>>name>>no>>phone>>t_seats>>t_amount;	
				}
				file.close();
				file1.close();
				remove("customer.txt");
				rename("customer1.txt","customer.txt");
				file.open("seat.txt",ios::in);
				file1.open("seat1.txt",ios::app|ios::out);
				file>>no>>t_seats;
				while(!file.eof()){
					if(!(del_no==no && i<del_seats)){
						file1<<no<<" "<<t_seats<<"\n";
					}
					file>>no>>t_seats;
				}
				file.close();
				file1.close();
				remove("seat.txt");
				rename("seat1.txt","seat.txt");
				booking();
				cout<<"\n\n\t\t\t\t\t Booking Updated Successfully....";
				found++;
				goto h;
			}
			file>>name>>no>>phone>>t_seats>>t_amount;
		}
		file.close();
		h:
		if(found==0){
			cout<<"\n\n\t\t\t\t\t Phone Number Is Invalid....";
		}
	}
}
void bus::del_booking(){
	system("cls");
	fstream file,file1;
	int t_seats,t_amount,found=0,del_seats,i=0;
	string name,t_name,phone,t_phone,no,del_no;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("customer.txt",ios::in);
	if(!file){
		cout<<"\n\n\t\t\t\t\t File Opening Error....";
	}
	else{
		cout<<"\n\n\t\t\t\t\t Phone Number:";
		cin>>t_phone;
		file>>name>>no>>phone>>t_seats>>t_amount;
		while(!file.eof()){
			if(t_phone==phone){
				file.close();
				file.open("customer.txt",ios::in);
				file1.open("customer1.txt",ios::app|ios::out);
				file>>name>>no>>phone>>t_seats>>t_amount;
				while(!file.eof()){
					if(t_phone==phone){
						del_no=no;
						del_seats=t_seats;
					}
					if(t_phone!=phone){
						file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amount<<"\n";
					}
					file>>name>>no>>phone>>t_seats>>t_amount;	
				}
				file.close();
				file1.close();
				remove("customer.txt");
				rename("customer1.txt","customer.txt");
				file.open("seat.txt",ios::in);
				file1.open("seat1.txt",ios::app|ios::out);
				file>>no>>t_seats;
				while(!file.eof()){
					if(!(del_no==no && i<del_seats)){
						file1<<no<<" "<<t_seats<<"\n";
					}
					file>>no>>t_seats;
				}
				file.close();
				file1.close();
				remove("seat.txt");
				rename("seat1.txt","seat.txt");
				cout<<"\n\n\t\t\t\t\t Booking Deleted Successfully....";
				found++;
				goto h;
			}
			file>>name>>no>>phone>>t_seats>>t_amount;
		}
		file.close();
		h:
		if(found==0){
			cout<<"\n\n\t\t\t\t\t Phone Number Is Invalid....";
		}
	}
}
void bus::show_booking(){
	system("cls");
	fstream file;
	int t_seats,t_amount,found=0;
	string name,phone,no;
	cout<<"\n\t\t\t\t\t --------BUS MANAGEMENT SYSTEM--------";
	file.open("customer.txt",ios::in);
	if(!file){
		cout<<"\n\n\t\t\t\t\t File Opening Error....";
	}
	else{
		file>>name>>no>>phone>>t_seats>>t_amount;	
		while(!file.eof()){
			cout<<"\n\n\t\t\t\t\t =======================================";
				cout<<"\n\n\n\t\t\t\t\t\t Customer Name:"<<name;
				cout<<"\n\n\t\t\t\t\t\t Bus No:"<<no;
				cout<<"\n\n\t\t\t\t\t\t Phone No:"<<phone;
				cout<<"\n\n\t\t\t\t\t\t Reserved Seats:"<<t_seats;
				cout<<"\n\n\t\t\t\t\t\t Total Amount:"<<t_amount;
				cout<<"\n\n\t\t\t\t\t =======================================";
			found++;
			file>>name>>no>>phone>>t_seats>>t_amount;
		}
		file.close();
		if(found==0){
			cout<<"\n\n\t\t\t\t\t No Booking Record Found...";
		}
	}
}
void reset(){
	system("cls");
	cout<<"\n\t\t\t\t\t --------RESET PASSWORD--------";
	bus b;
	string new_e,n_pass,p_no;
	cout<<"\n\n\t\t\t\t\t Enter Your Email:";
	cin>>new_e;
	cout<<"\n\n\t\t\t\t\t Enter Your Number:";
	cin>>p_no;
	if(new_e=="mohsin@superior" && p_no=="0125"){
		cout<<"\n\n\t\t\t\t\t Enter Your New Password:";
		cin>>n_pass;
		cout<<"\n\n\n\t\t\t\t\t\t      Loading";
		for(int i=1;i<=5;i++){
			Sleep(500);
			cout<<".";
		}
		b.menu();
	}
	else{
		cout<<"\n\n\t\t\t\t\t Email or Incorrect Phone Number"<<endl;
	}
}
int main(){
	system("color F0");
	bus b;
	a:
	system("cls");
	string email,pass;
	char ch;
	int option;
	cout<<"\n\n\t\t\t\t\t\t***Security Required***";
	cout<<"\n\n\n\t\t\t\t\t\t Email:";
	cin>>email;
	cout<<"\n\n\t\t\t\t\t\t Password:";
	cin>>pass;
	if(email=="mohsin@superior" && pass=="123456"){  //condition to check email and password
		cout<<"\n\n\n\t\t\t\t\t\t      Loading";  //loop for loading
		for(int i=1;i<=5;i++){
			Sleep(500);
			cout<<".";
		}
		b.menu();	
	}
	else{
		cout<<"\n\n\t\t\t\t\t\t Invalid Email or Password...";
		cout<<"\n\n\t\t\t\t\t\t Want To Reset Password:";
		cout<<"\n\n\t\t\t\t\t\t Press 1 to Reset 2 For Exit:";
		cin>>option;
		if(option==1){
		reset();
		}
		else if(option==2){
			exit(0);
		}
		else{
			cout<<"\n\n\t\t\t\t\t\t Incorrect Option";
			exit(0);
		}
		getch();
		goto a;
	}	
}
