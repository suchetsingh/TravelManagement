#include<iostream>//basic input output file
#include<fstream>//handles files
#include<iomanip>
#include<windows.h>

using namespace std;

void menu();

class ManageMenu
{
	protected:
		string userName;//hide admin name
	public:
		ManageMenu()
		{
			cout<<"\n\n\n\n\n\n\n\n\t Enter Your Name to Continue as an Admin:";
			cin>>userName;
			system("CLS");
			menu();
		}
		~ManageMenu(){
		}
};

class Customers
{
public:
	string name,gender,address;
	int age,mobileno;
	static int cusID;
	char all[999];
	
	void getDetails()
	{
		ofstream out("old-customer.txt",ios::app);//it is used to create files and write data to files
		{
			cout<<"Enter Customer ID:";
			cin>>cusID;
			cout<<"Enter Name:";
			cin>>name;
			cout<<"Enter Age:";
			cin>>age;
			cout<<"Enter MobileNo:";
			cin>>mobileno;
			cout<<"Enter Address:";
			cin>>address;
			cout<<"Enter Gender:";
			cin>>gender;
		}
		out<<"\nCustomer ID:"<<cusID<<"\nName:"<<name<<"\nAge:"<<age<<"\nMobileNo:"<<mobileno<<"\nAddress:"<<address<<"\nGender"<<gender<<endl;
		out.close();
		cout<<"\nSaved\nNOTE: We saved your details record for future purposes\n"<<endl;
	}
	
	
	void showdetails()
	{
		ifstream in("old-customer.txt");//this allows us to read any information contained in file
		{
			if(!in)
			{
				cout<<"File Error!"<<endl;//if the file is empty....
			}
			while(!(in.eof()))//eof is used to check if end of stram checked or not  if end occurs return 1
			{
				in.getline(all,999); //getting all the lines and saving in all array 
				cout<<all;
			}
			in.close();
		}
	}
};
int Customers::cusID;
class Cabs
{
public:
	int cabChoice;
	int kilometers;
	float cabCost;
	static float lastcabCost;
	
	void cabDetails()
	{
		cout<<"We collaborated with fastest, safest and smartest cab service around the country"<<endl;
		cout<<"-------------------Suchet Singh Cabs----------------\n"<<endl;
		cout<<"1. Rent a Standard Cab - Rs.15 per 1KM"<<endl;
		cout<<"2. Rent a Luxury Cab - Rs.25 per 1KM"<<endl;
		
		cout<<"\nTo calculate the cost for your journey:"<<endl;
		cout<<"Enter which kind of cab you need:";
		cin>>cabChoice;
		cout<<"Enter Kilometers you have to travel:";
		cin>>kilometers;
		
		int hireCab;
		
		if(cabChoice==1)
		{
			cabCost=kilometers*15;
			cout<<"\nYour tour cost->"<<cabCost<<" rupees for a Standard Cab"<<endl;
			cout<<"Press 1 to hire this cab: or";
			cout<<"Press 2 to select another cab";
			cin>>hireCab;     //if user decided to go back then above things should pop up again...
			
			system("CLS"); //this is used to clear the screen after a cout statement
			if(hireCab==1)
			{
				lastcabCost=cabCost;
				cout<<"\nYou have successfully hired Standard Cab"<<endl;
				cout<<"\n GOTO Menu and take the recipt"<<endl;
			}
			else if(hireCab==2)
			{
				cabDetails();//This means user decided not to select cab 1 
			}
			else {
				cout<<"Invalid Input ! Redirecting into previous menue\nPlease Wait"<<endl;
				Sleep(999);
				system("CLS");
				cabDetails();
			}	
		}
		else if(cabChoice==2)
		{
			cabCost=kilometers*25;
			cout<<"\nYour tour will cost->"<<cabCost<<"rupees for a Luxury Cab"<<endl;
			cout<<"Press 1 to hire this cab: or";
			cout<<"Press 2 to select another cab";
			cin>>hireCab;     //if user decided to go back then above things should pop up again...
			
			system("CLS"); //this is used to clear the screen after a cout statement
			if(hireCab==1)
			{
				lastcabCost=cabCost;
				cout<<"\nYou have successfully hired Luxury Cab"<<endl;
				cout<<"\n GOTO Menu and take the recipt"<<endl;
			}
			else if(hireCab==2)
			{
				cabDetails();//This means user decided not to select cab 1 
			}
			else {
				cout<<"Invalid Input ! Redirecting into Previous Menue\nPlease Wait"<<endl;
				Sleep(999);
				system("CLS");
				cabDetails();
			}	
		}
		else
		{
				cout<<"Invalid Input ! Redirecting into Main Menue\nPlease Wait"<<endl;
				Sleep(999);
				system("CLS");
				menu();
		}
		cout<<"\nPress 1 to Redirect to Main Menue:";
		cin>>hireCab;
		system("CLS");
		if(hireCab==1)
		{
			menu();
		}
		else {
			menu();
		}
	}
};

class Booking
{

public:
	int choiceHotel;
	int packChoice;
	static float hotelCost;
	
	void hotels()   //details of hotels
	{
		string hotelNo[]= { "Radisson Blu","ChoiceYou","ElephantBay"};
		for(int a=0;a<3;a++)
		{
			cout<<(a+1)<<". Hotel"<<hotelNo[a]<<endl; 
		}
		cout<<"\nCurrently we are collaborated with above hotels!"<<endl;
		
		cout<<"Press any key to back or\nEnter number of the Hotel you want to book:";
		cin>>choiceHotel;	
		system("CLS");
		
		if(choiceHotel==1)
		{
			cout<<"---------WELCOME TO HOTEL RADISSON BLU-------------\n"<<endl;
			
			cout<<"The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun."<<endl;
			
			cout<<"Packages offered by RADISSON BLU:\n"<<endl;
			
			cout<<"1. Standard Pack"<<endl;
			cout<<"\tAll basic facilities you need just for: Rs.50000.00"<<endl;
			cout<<"2. Premium Pack"<<endl;
			cout<<"\tEnjoy Premium: Rs.10000.00"<<endl;
			cout<<"3. Luxury Pack"<<endl;
			cout<<"\tLive a Luxury at RADISSON BLU: Rs15000.00"<<endl; 
			
			cout<<"\nPress another key to back or\nEnter Package number you want to book:";
			cin>>packChoice;
			
			
			if(packChoice==1)
			{
				hotelCost=5000.00;
				cout<<"\nYou have successfully booked Standard Pack at RADISSON BLU"<<endl;
				cout<<"Goto Menue and take the recipt"<<endl;
			}
			else if(packChoice==2)
			{
				hotelCost=10000.00;
				cout<<"\nYou have successfully booked Premium Pack at RADISSON BLU"<<endl;
				cout<<"Goto Menue and take the recipt"<<endl;
			}
			else if(packChoice==3)
			{
				hotelCost=15000.00;
				cout<<"\nYou have successfully booked Luxury Pack at RADISSON BLU"<<endl;
				cout<<"Goto Menue and take the recipt"<<endl;
			} else 
			{
				cout<<"Invalid Input! Redirecting to Previous Menu\nPlease Wait!"<<endl;
				Sleep(1100);
				system("CLS");
				hotels();
			}
			int gotomenu;
			cout<<"\nPress 1 to redirect to main menu: ";
			cin>>gotomenu;
			system("CLS");
			if(gotomenu==1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}
		if(choiceHotel==2)
		{
			cout<<"---------WELCOME TO HOTEL CHOICE YOU-------------\n"<<endl;
			
			cout<<"Swimming Pool | Free Wifi | Family Rooms \n Fitness Center | Restaurant & Bar"<<endl;
			
			cout<<"Packages offered by CHOICE YOU:\n"<<endl;
			
			cout<<"1. Family Pack"<<endl;
			cout<<"\t Rs.15000.00 for a day"<<endl;
			cout<<"2. Couple Pack"<<endl;
			cout<<"\t Rs.10000.00 for a day"<<endl;
			cout<<"3. Single Pack"<<endl;
			cout<<"\t Rs5000.00 for a day"<<endl; 
			
			cout<<"\nPress another key to back or\nEnter Package number you want to book:";
			cin>>packChoice;
			
			
			if(packChoice==1)
			{
				hotelCost=15000.00;
				cout<<"\nYou have successfully booked Family Pack at CHOICE YOU"<<endl;
				cout<<"Goto Menue and take the recipt"<<endl;
			}
			else if(packChoice==2)
			{
				hotelCost=10000.00;
				cout<<"\nYou have successfully booked Couple Pack at CHOICE YOU"<<endl;
				cout<<"Goto Menue and take the recipt"<<endl;
			}
			else if(packChoice==3)
			{
				hotelCost=5000.00;
				cout<<"\nYou have successfully booked Single Pack at CHOICE YOU"<<endl;
				cout<<"Goto Menue and take the recipt"<<endl;
			} else 
			{
				cout<<"Invalid Input! Redirecting to Previous Menu\nPlease Wait!"<<endl;
				Sleep(1100);
				system("CLS");
				hotels();
			}
			int gotomenu;
			cout<<"\nPress 1 to redirect to main menu: ";
			system("CLS");
			cin>>gotomenu;
			if(gotomenu==1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}
		
			if(choiceHotel==3)
		{
			cout<<"---------WELCOME TO HOTEL ELEPHANTBAY-------------\n"<<endl;
			
			cout<<"Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants"<<endl;
			cout<<"Amazing offer in this summer: Rs.5000.00 for a one day!!!"<<endl;
			
			cout<<"Press another key to back or\nPress 1 to book this Special Package:";
			cin>>packChoice;
			
			if(packChoice==1)
			{
				hotelCost=5000.00;
				cout<<"\nYou have successfully booked ElephantBay Special Pack"<<endl;
				cout<<"Goto Menue and take the recipt"<<endl;
			}
			else 
			{
				cout<<"Invalid Input! Redirecting to Previous Menu\nPlease Wait!"<<endl;
				Sleep(1100);
				system("CLS");
				hotels();
			}
			int gotomenu;
			cout<<"\nPress 1 to redirect to main menu: ";
			cin>>gotomenu;
			system("CLS");
			if(gotomenu==1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}
		else
		{
			cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
			Sleep(1100);
			system("CLS");
			menu();
		}	
	}
};
float Booking::hotelCost;
float Cabs::lastcabCost;

class Charges : public	Booking, Cabs, Customers
{
public:
	void printBill()
	{
		ofstream outf("receipt.txt");
		{
			outf<<"---------SUCHET SINGH TRAVEL AGENCY------------"<<endl;
			outf<<"----------------Receipt------------------------"<<endl;
			outf<<"_______________________________________________"<<endl;
			
			outf<<"Customer ID:"<<Customers::cusID<<endl<<endl;
			outf<<"Description\t\t Total"<<endl;
			outf<<"Hotel cost:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
			outf<<"Travel (cab) cost:\t"<<fixed<<setprecision(2)<<Cabs::lastcabCost<<endl;
			
			
			outf<<"_______________________________________________"<<endl;
			outf<<"Total Charge:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastcabCost<<endl;
			outf<<"_______________________________________________"<<endl;
			outf<<"---------------THANK  YOU----------------------"<<endl;
		}
		outf.close(); 	
	}
	void showBill()
	{
		ifstream inf("receipt.txt");
		{
			if(!inf)
			{
				cout<<"File Opening error!"<<endl;
			}
			while(!(inf.eof()))
			{
				inf.getline(all,999);
				cout<<all<<endl;
			}
		}
		inf.close();
	}
};

void menu()
{
	
	int mainChoice;
	int inChoice; 
	int gotoMenu;
	
	
	cout<<"\n\n\n\t\t      *SUCHET SINGH TRAVELS*\n"<<endl;
	cout<<"---------------------------------Main Menu---------------------"<<endl;
	
	cout<<"\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
	cout<<"\t|\t\t\t\t\t\t"<<endl;
	cout<<"\t|\tCustomer Management ->  1\t|"<<endl;
	cout<<"\t|\tCabs Management     ->  2\t|"<<endl;
	cout<<"\t|\tBooking Management  ->  3\t|"<<endl;
	cout<<"\t|\tCharges & Bills     ->  4\t|"<<endl;
	cout<<"\t|\tExit                ->  5\t|"<<endl;
	cout<<"\t|\t\t\t\t\t|"<<endl;
	cout<<"\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
	
	
	cout<<"\nEnter Your Choice"<<endl;
	cin>>mainChoice;
	
	system("CLS");
	Customers a2;
	Cabs a3;
	Booking a4;
	Charges a5;
	
	
	if(mainChoice==1)
	{
		cout<<"-----Customers-----\n"<<endl;
		cout<<"1. Enter New Customers"<<endl;
		cout<<"2. See Old Customers"<<endl;
		
		cout<<"\nEnter Choice:";
		cin>>inChoice;
		
		system("CLS");
		
		if(inChoice==1)
		{
			a2.getDetails();
		}
		else if(inChoice==2)
		{
			a2.showdetails();
		}
		else {
			cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
			Sleep(1100);
			system("CLS");
			menu();
		}
		cout<<"\nPress 1 to Readirect to main menu:";
		cin>>gotoMenu;
		system("CLS");
		
		if(gotoMenu==1)
		menu();
		else menu();
	}
	else if(mainChoice==2)
	{
		a3.cabDetails();
	}
	else if(mainChoice==3)
	{
		cout<<"---> Book a luxury hotel using the system<---"<<endl;
		a4.hotels();
	}
	else if(mainChoice==4)
	{
		cout<<"-->Get your receipt<--"<<endl; 
		a5.printBill();
		
		cout<<"Your receipt is already printed yoy can get it from file path\n"<<endl;
		cout<<"to display your receipt int the screen, Enter 1: or Enter another key to back main menu:";
		
		cin>>gotoMenu;
		if(gotoMenu==1)
		{
			system("CLS");
			a5.showBill();
			cout<<"\nPress 1 to redierct to main menu:";
			cin>>gotoMenu;
			system("CLS");
			if(gotoMenu==1)
			{
				menu();
			}
			else {
				menu();
			}
		}
		else
		{
			system("CLS");
			menu();
		}
	}
	else if(mainChoice==5)
	{
		cout<<"---GOOD BYE----"<<endl;
		Sleep(999);
		system("CLS");
		menu();	
	}
	else
	{
		cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait!"<<endl;
		Sleep(1100);
		system("CLS");
		menu();
	}
}

int main()
{
	ManageMenu starObj;
	cout<<"HELLO"<<endl;
	return 0;
}
