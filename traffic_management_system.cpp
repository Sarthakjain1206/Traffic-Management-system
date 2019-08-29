#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;
const char BACKSPACE=8;
const char RETURN=13;
void gotoXY(int x, int y); 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
static int a;
class staff_login;
class register_now
{
	string name[10];
	public:
		int instructions_form();
		int registration_form();
		int confirmform();
		friend staff_login;
};
class staff_login 
{
	public:
		string userr;
	string userr1;
		int login();
		void vehicle_details();
		void challan();
		void contactdetails();
		int pay_challan();
		int submit_challan();
		
//		void getdata_challan(){
//			cout<<"Enter the name";
//			cin>>userr;
//			cout<<"enter the vehicle number";
//			cin>>userr1;
//		}
//		void show_challan_data(){
//			cout<<endl<<"NAME :"<<userr;
//			cout<<endl<<"VEHICLE NUMBER :"<<userr1<<endl;
//		}
		void read_challan_data();
	friend register_now;
};
class guest_login
{
	public:
		void front();
		int contact();
		int display();
};

void guest_login::front(){
	system("cls");
	cout<<"\n               HI! GUEST... I WOULD LOVE TO KNOW YOUR NAME.\n\n";
	cout<<"ENTER YOUR GOOD NAME :";
	string name;
	cin>>name;
	cout<<"\n\n  HI! "<<name<<"YOU'RE WELCOME HERE.";
	cout<<"\n\n  As you are not a staff member so you can only view-->\n";
	cout<<"  1. contact details of staff members.\n  2. vehicle details with their owner name.";
	cout<<"\n\n  enter your choice :";
	int u;
	cin>>u;
	switch(u){
		case 1:contact();
      				break;
		case 2:display();
					break;
		default:exit;
	}
}
int guest_login::contact(){
	string s;
	system("cls");
	cout<<"\n\n\n             HERE ARE THE DETAILS OF STAFF MEMBERS ===>>";
	ifstream fin6;
	fin6.open("list_of_staff.dat",ios::in);
	cout<<"\n\n\n";
	cout<<"USername       Name               Father name          Mobile no.         College            Registeration Amount\n";
	while(!fin6.eof())
	{
		getline(fin6,s);
		cout<<s;
		cout<<"\n";
	}
	Sleep(500);
	char str;
	cout<<"\n\nPress any key to logout";
	cin>>str;
	return 0;

}
int guest_login::display(){
	string s;
	system("cls");
	cout<<"\n\n\n             HERE ARE THE DETAILS OF CARS ===>>";
	ifstream fin6;
	fin6.open("car_details.txt",ios::in);
	cout<<"\n\n\n";
	cout<<"Vehicle name            VEhicle owner           Vehicle number\n";
	while(!fin6.eof())
	{
		getline(fin6,s);
		cout<<s;
		cout<<"\n";
	}
	Sleep(500);
	char str;
	cout<<"\n\nPress any key to logout";
	cin>>str;
	return 0;
}
int staff_login::login()
{
//	staff_login s2;
	int u;
	string a[100],user1,user2,user3;
	char line[80];
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n                    USERNAME:";
	cin>>user1;
	int i=0;char ch;
	string password;
	cout<<"                    PASSWORD:";
	while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                cout <<"\b \b";
                password.resize(password.length()-1);
            }
        }
       else if(ch==0 || ch==224) // handle escape sequences
        {
            getch(); 
            continue;
        }
       else
        {
            password+=ch;
            cout <<'*';
        }
    }
	int j=0;
	user2=password;
	user3=user1+user2;
	ifstream fil5;
	fil5.open("password.txt",ios::out);
	while(fil5)
	{
		fil5.getline(line,80);
		a[j]=line;
		j++;
	}
		for(int k=0;k<50;k++)
		{
		if(a[k]==user3)
		{
		while(1)
		{
			system("cls");
			cout<<"\n\n WELCOME TO "<<user1;
			cout<<"\n\n\n\n\n                  1.ENTER VEHICLES DETAILS";
			cout<<"\n                  2.CHALLAN DETAILS";
			cout<<"\n                  3.To LOGOUT";
			cout<<"\n\n\n\n\n\n Select your option";
			cin>>u;
			switch(u)
				{
				case 1:vehicle_details();
						break;
				case 2:challan();
						break;
				case 3:system("cls");
						cout<<"\n\n\n\n\n\n\n            PLEASE WAIT ... LOADING";
						Sleep(500);
						return 0;
				default:exit;
				}
		}
    	}
    }
    system("cls");
		cout<<"\n\n\n      SORRY,"
			<<"\n      invalid username and password";
		Sleep(300);
	return 1;
}
void staff_login::vehicle_details(){
	system("cls");
	int n,i;
	cout<<"\n\n\n                Of how many vehicles you want to enter the details? :"<<endl;
	cin>>n;
	string owner_name[n];
	string car_name[n];
	string car_no[n];
	fstream fil3;
	for(i=0;i<n;i++)
	{
		cout<<"     Enter the car name :"<<endl;
		cin>>car_name[i];
		cout<<"     enter the name of owner of car :"<<endl;
		cin>>owner_name[i];
		cout<<"     Enter the car no. :"<<endl;
		cin>>car_no[i];
	}
	fil3.open("car_details.txt",ios::app|ios::binary);
	fil3.seekg(74);
	for(int i=0;i<n;i++)
	{
	fil3.setf(ios::left,ios::adjustfield);
	fil3<<setw(20)<<car_name[i];
	fil3.setf(ios::left,ios::adjustfield);
	fil3<<setw(20)<<owner_name[i];
	fil3.setf(ios::left,ios::adjustfield);
	fil3<<setw(20)<<car_no[i];
	fil3<<endl;
	fil3.seekg(74);
	}
	fil3<<endl;
	fil3.close();
	cout<<endl<<"data entry has been completed";
	Sleep(500);

	
	
	
	
}
void staff_login::challan()
{
//	staff_login s2;
	int u;
	system("cls");
	cout<<"            HI!! user"<<"\n\n            You Can perform the following tasks-->";
	cout<<"\n\n\n\n\n                  1.SUBMIT CHALLAN";
	cout<<"\n                  2.PAY CHALLAN of a customer";
	cout<<"\n                  3.SEE CHALLAN DETAILS";
	cout<<"\n\n\n\n   Select your OPtion :";
	cin>>u;

	switch(u)
	{
		case 1:
			submit_challan();
			break;
		case 2:
			pay_challan();
			break;
		case 3:
			read_challan_data();
			break;
		default:exit;
	}
}
int staff_login::submit_challan()
{
//	staff_login s2;
	ofstream fout;
	system("cls");
	int n;
	cout<<"\n\n\n\n\n                  Hello staff!!";
	cout<<"\n\n You can submit the details of persons whose challans are pending";
	cout<<"\n\n\n\n Of how many people you want to submit the challan details? ";
	cin>>n;
	string owner_name[n];
	string car_name[n];
	string car_no[n];
	fstream fil3;
	for(int i=0;i<n;i++)
	{
		cout<<"     enter the name of owner of car :"<<endl;
		cin>>owner_name[i];
		cout<<"     Enter the car name :"<<endl;
		cin>>car_name[i];
		cout<<"     Enter the car no. :"<<endl;
		cin>>car_no[i];
	}
	fil3.open("car_challan_details.txt",ios::app|ios::binary);
	fil3.seekg(74);
	for(int i=0;i<n;i++)
	{
	
	fil3.setf(ios::left,ios::adjustfield);
	fil3<<setw(20)<<owner_name[i];
	fil3.setf(ios::left,ios::adjustfield);
	fil3<<setw(20)<<car_name[i];
	fil3.setf(ios::left,ios::adjustfield);
	fil3<<setw(20)<<car_no[i];
	fil3<<endl;
	fil3.seekg(74);
	}
	fil3<<endl;
	fil3.close();
	cout<<endl<<"data entry of challans has been completed";
	Sleep(500);
	challan();
	
}
int staff_login::pay_challan()
{
	staff_login s2;
	int a;
	char ch;
	string user;
	string user2;
	system("cls");
	cout<<"\n\n\n\n\n                  Enter the name of concern person.";
	cin>>user;
	cout<<"\n\n\n\n\n                  Enter the Vehicle number.";
	cin>>user2;
	cout<<"\n                  How much amount you have to pay?";
	cin>>a;
	for(int i=0;i<100;i++)
	{
		system("COLOR 2");
		cout<<"loading..."<<system("cls")<<i<<"%";
		Sleep(50);
	}
	system("cls");
	cout<<"\n\n\n\n\n                  AMOUNT has been PAID.";
	cout<<"\n\n\n Press Y to delete the record of "<<user<<"fron challan data record, else any other key to go back to main menu";
	cin>>ch;
	if(ch=='Y'||ch== 'y')
	{
//		ifstream fin;
//		ofstream fout;
//		fout.open("tempfile2.txt",ios::out|ios::binary);
//		fin.open("file1.txt",ios::in|ios::binary);
//		fin.read((char*)&s2,sizeof(s2));
//		while(!fin.eof())
//		{
//			if(user!=userr)
//			{
//				fout.write((char*)&s2,sizeof(s2));
//			}
//			fin.read((char*)&s2,sizeof(s2));
//		}
//		fin.close();
//		fout.close();
//		remove("file2.txt");
//		rename("tempfile2.txt","file2.txt");
	string sss;
	ifstream is;
	is.open("car_challan_details.txt",ios::in);
	
    // open file in write mode or out mode 
    ofstream ofs; 
    ofs.open("temp.txt", ofstream::out); 
  
    // loop getting single characters 
    string c; 
	while(!is.eof())
	{
		getline(is,c);
		sss=c.substr(0,user.length());
		if(sss!=user)
		{
			ofs<<c;
			ofs<<endl;
		}
	}
    // closing output file 
    ofs.close(); 
  
    // closing input file 
    is.close(); 
  	getch();
    // remove the original file 
    remove("car_challan_details.txt"); 
  
    // rename the file 
    rename("temp.txt","car_challan_details.txt");
	}
	else{
		return 0;
	}
	
}
void staff_login::read_challan_data()
{
//	staff_login s2;
//	system("cls");
//	ifstream fin;
//	char ch;
//	fin.open("file2.txt",ios::in|ios::binary);
//	fin.read((char*)this,sizeof(*this));
//	while(!fin.eof())
//		{
//			cout<<endl<<"NAME :"<<s2.userr<<endl;
//			cout<<endl<<"VEHICLE NUMBER :"<<s2.userr1<<endl;
//		fin.read((char*)&s2,sizeof(s2));
//		}
//	fin.close();
	string s;
	system("cls");
	cout<<"\n\n\n             HERE ARE THE DETAILS OF CHALLANS OF CARS ===>>";
	ifstream fin6;
	fin6.open("car_challan_details.txt",ios::in);
	cout<<"\n\n\n";
	cout<<"Vehicle owner            VEhicle name           Vehicle number\n";
	while(!fin6.eof())
	{
		getline(fin6,s);
		cout<<s;
		cout<<"\n";
	}
	Sleep(500);
	char str;
	cout<<"\n\nPress any key to logout";
	cin>>str;
//	return 0;
}
		
int register_now::instructions_form() 
{
	system("cls");
	cout<<"\n          ";
	char b[]="Read the following Instructions\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
	char ch;
	char a;
	ifstream ins1;
	ins1.open("instructions.txt",ios::in);
		while(ins1) 
		{
			ins1.get(ch);
			cout<<ch;
		}
	cout<<"To accept the above instructions press Y : ";
	cin>>a;
		if(a == 'y' || a == 'Y')
		{
			registration_form();
		}
	 	else 
		{
			system("cls");
			cout<<"\n\n\n\n\n               sorry,YOU ENTERED A WRONG CHOICE.....";
			Sleep(1000);
			system("cls");
		}
}
int register_now::registration_form()
{
	string password;
//	char pwd[5];
	unsigned char ch=0;
//	const char BACKSPACE=8;
//    const char RETURN=13;

	int i=0;
	system("cls");
	a++;
	fstream fil5;
	fil5.open("password.txt",ios::out|ios::app);
	cout<<"              \n";
	char b[]="REGISTRATION FORM\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
	cout<<endl<<endl<<setw(5)<<"NAME :";
	cin>>name[0];
	cout<<setw(40)<<"FATHER NAME :";
	cin>>name[1];
	cout<<endl<<setw(5)<<"Ph_no:";
	cin>>name[2];
	cout<<setw(35)<<"ADDRESS:";
	cin>>name[3];

	
	cout<<endl<<endl<<"Your username :";
	cout<<"STAF"<<a;
	again:
	cout<<endl<<"PASSWORD :";
	while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                cout <<"\b \b";
                password.resize(password.length()-1);
            }
        }
       else if(ch==0 || ch==224) // handle escape sequences
        {
            getch(); 
            continue;
        }
       else
        {
            password+=ch;
            cout <<'*';
        }
    }
    string s;
    s=password;
    bool dig  = false;
    bool lE = false;
    bool uE = false;
    bool sp = false;
    for (int i = 0; i<s.length(); i+=1) {
        if(s[i]>='0' and s[i]<='9')
        {
            dig = true;
        }
        else if (s[i]>='a' and s[i]<='z')
        {
            lE = true;
        }
        else if (s[i]>='A' and s[i]<='Z')
        {
            uE = true;
        }
        else{
            sp = true;
        }
    }
    if(dig==1 && lE==1 && uE==1 && sp==1 && s.length()>6)
	{
	fil5<<"STAF"<<a;
	fil5<<password<<"\n";
	name[4]="1000";
	fil5.close();
	fstream fil2;
	fil2.open("list_of_staff.dat",ios::in | ios::out | ios::app);
	fil2.seekg(74);
	fil2<<"STAF"<<a<<"          ";
	//fil2.setf(ios::left,ios::adjustfield);
	for(int i=0;i<6;i++)
	{
	fil2.setf(ios::left,ios::adjustfield);
	fil2<<setw(20)<<name[i];
	}
	fil2<<endl;
	Sleep(500);
	confirmform();
	}
	else
	{
		cout<<"\n\n SORRY, Your password isn't strong enough.";
		cout<<"\n YOur Password must contain atleast one lowercase , uppercase , special character as well as digit.";
		cout<<"\n\n\n TRY AGAIN!";
		password.erase();
		goto again;
	}
}
int register_now::confirmform()
{
	char ch;
	system("cls");
	char sentzz[]="          ***************CONFIRM FORM*****************";
	int x;              //special dialogue
	int size; 
	size=strlen(sentzz);
    for(x=0;x<size;x++)
    {   
        Sleep(50); 
        cout<<sentzz[x];
    }
    cout.setf(ios::left,ios::adjustfield);
	cout<<endl<<endl<<"     NAME :"<<name[0];
	cout<<"                  FATHER NAME :"<<name[1];
	cout<<endl<<endl<<"     Ph_no:"<<name[2];
	cout<<"                   ADDRESS:"<<name[3];
	cout<<endl<<endl<<endl<<"            Total amount to be paid : Rs 1,000|- on or before 5th july"<<endl
	<<endl<<endl<<"                                                              student sign";
    	int a;
    	Sleep(400);
    	cout<<endl<<endl<<"    Enter any key to return back to main menu :";
    	getch();
    	return 1;
	}
int main()
{
	while(1)
	{
	system("cls");
	system("COLOR 2C");
	cout<<endl<<endl;
	Sleep(1000);
	system("COLOR 8F");
	char a[]="                 $$$$$$$$$$$ TRAFFIC MANAGEMENT SYSTEM WELCOMES YOU $$$$$$$$$$$";
	int size;
	size=strlen(a);
	for(int i=0;i<size;i++)
		{
			Sleep(25);
			cout<<a[i];
		}
	int c=1;
	cout<<endl<<endl;
	Sleep(0);
	cout<<"\n                    1.REGISTERATION TO BE A STAFF MEMBER \n                    2.STAFF LOGIN \n                    3.GUEST LOGIN \n";

	for(int i=0;i<1;i++)
    {
    	int x = 16;
    	int y = 10;
    	for (y=10;y<19;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(100);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  		}
  		y=19;
  		for (x=16;x<63;x++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(20);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  		}
  		for (y=10;y<20;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(100);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  		}
	}
	for(int i=0;i<1;i++)
    {
    	int x = 1;
    	int y = 20;
    	for (x=40;x>1;x--)  
   		{
    	  gotoXY(x,y);
    	  cout << "Thanks to all my friends who helped in development of this program";
    	  Sleep(100);
    	  gotoXY(x,y); 
		  cout << "                                                         ";
		     cout<<"                                            "; 
  		}
  		cout <<endl<<"       Thanks to all our friends who helped in development of this program"<<endl;
	}
  	
	register_now r1;
	staff_login s2;
	guest_login s3;
	int ch;
	cout<<endl<<endl<<"enter your choice ";
	cin>>ch;
	if(ch==1)
	r1.instructions_form();
	if(ch==2)
	{
		s2.login();
	}
	if(ch==3)
	{
		s3.front();
	}
	}
	getch();
	return 0;
}
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
