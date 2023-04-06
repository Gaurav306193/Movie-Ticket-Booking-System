#include<iostream>
#include<windows.h>
#include <limits>
#include <cstdlib>
using namespace std;


	//declare functions
	void Menu1();
	void validateMenu1();
	void seatAssigment();
	void Twin(int seat);
	void Premier(int seat_number);
	void Gold(int seat_number);
	void Economy(int seat_number);
	void seating_plan();
	int payment_reserved_seat();
	bool availableSeat(int seat_number, char category);
	bool checkRangeSeat(char category,char row , int column);
	bool verify_seat_status(int row,int column, int seat_number);
	void reset_seating_plan();
	int update_sales(int seat_number);
	void update_seatingplan(int seat_number);
	bool isNum(char input);
	bool isAlpha(char input);
	const int row = 16;
	const int column = 20;
    char cinema[row][column];
    int total_seat = 320;
HANDLE hConsole;
 
	int total_sales = 0;
	int seat_number, price = 0;
	int row_seat, column_seat;
	char seat_action;
	char category, menu;
	char row_convert;
	char choice;
 	bool IsContinue = true; // use for the exit in menu
	char answer;
	string choose_seat;
int main()
{

	for(int i = 0 ; i < 16; i++) // set the symbol *
	{
	    for(int j = 0; j < 20; j++)
		{


			cinema [i][j] = '*';

		}
	//cinema [0][8] = 'X';
	//cinema [0][4] = 'X';

}


while(IsContinue)
	{
	system("cls");//clear screen
	seating_plan();
	Menu1();// the function which display the Main Menu interface

	validateMenu1();//the function to validate the Menu1 user input

















	     cout<<endl;
            cout<<" "<< "Do you want to repeat the program?\n";        //option for user to repeat program or end program
            cout<<" "<< "Type any key & press enter continue or\n";
            cout<<" "<< "Type (q) & press enter to quit the program\n";
            cout<<" "<< "Option : ";
            cin >> answer;
            cout<<endl;

       if ((answer == 'Q') || (answer == 'q'))
			{
				while ( !IsContinue );

                cout<<endl;
				cout << "(:Thank You ! Have a nice show ! :)" << endl; // quit message
				system("pause");
				return 0;
			}
    }
}











void validateMenu1()
{
char choice;
bool isChar1Invalid = true;

          while(isChar1Invalid) // error checking for alphabetics
            {
                cout<<endl;
                cout<<"     "<<"Option : ";
                cin>>choice;
                cout<<endl;

                if(isalpha(choice))
                    {
						 if ((choice == 'A') ||(choice == 'a') ) //if functions
                         {
                          seatAssigment();
						  isChar1Invalid = false;
						 }
						 else if((choice == 'B') ||(choice == 'b'))
						 {
						 payment_reserved_seat();
						 isChar1Invalid = false;
						 }
						 else if((choice == 'C') ||(choice == 'c'))
						 {
						  reset_seating_plan();
						  isChar1Invalid = false;
						 }
						 else if((choice == 'D') ||(choice == 'd'))
						 {
						  cout<<endl;
				          cout << "(:Thank You ! Have a nice show ! :)" << endl; // quit message
				          system("pause");

							 exit (1);
						 isChar1Invalid = false;
						 }
						 else
						 {
						cout<<"     "<<"Invalid Choice";
                        isChar1Invalid = true;
                        cout<<endl;
						 }

                    }
                else
                    {
                        cout<<"     "<<"Error: Invalid Choice Please try again!"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<char>::max(), '\n');
                        cout<<endl;
                    }
            }




}



void Menu1() // interface function
{
    cout<<endl;
    cout<<"     |||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"     ||                                                 ||"<<endl;
    cout<<"     ||                                                 ||"<<endl;
    cout<<"     ||              A.Seat Assignment                  ||"<<endl;
    cout<<"     ||              B.Payment (for reserved seat)      ||"<<endl;
    cout<<"     ||              C.Reset Seating Plan               ||"<<endl;
    cout<<"     ||              D.EXIT                             ||"<<endl;
    cout<<"     ||                                                 ||"<<endl;
    cout<<"                  # HAVE YOUR BEST TIME HERE:)          ||"<<endl;
    cout<<"     ||                                                 ||"<<endl;
    cout<<"     |||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
}


void seatAssigment()
{


			 //this portion of code verify that the user enter a valid integer input
			bool isNum = false;
			do{
			   do
                {
                cout<<endl;
				
                cout<<"Enter Number of seat required: ";
				  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				//SetConsoleTextAttribute(hConsole, 1);
				SetConsoleTextAttribute
						  (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                cin>>seat_number;
				if(cin.fail())
					{
					    SetConsoleTextAttribute(hConsole, 4);
					    cout<<"Input Error:Pleae Enter an integer value"<<endl;
						cin.clear();
						cin.ignore(numeric_limits<char>::max(), '\n');
						cout<<endl;
						isNum = true;
						system("pause");
					}
				else
				{
				isNum = false;
                cout << endl;

				}
				}while(isNum);

                cout<<endl;
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 7);

				cout << " --------------------------" << endl;
				cout << "| Seat category   |Price(RM)" << endl;
				cout << "|---------------- |--------|" << endl;
				cout << "|   Twin          |   15   |" << endl;
				cout << "|   Premeire      |   12   |" << endl;
				cout << "|   Gold          |   10   |" << endl;
				cout << "|   Economy       |   6    |" << endl;
				cout << "----------------------------" << endl;

			    do
                {
                cout<<endl;
                cout<<"Desired seat category: ";
                string temp;
				
			    cin >> temp;
				if(temp=="Twin" || temp=="twin" ||temp=="TWIN")
				{
				category='t';
			    }
				else if(temp=="Premiere" || temp=="premiere"||temp=="PREMIERE")
				{
				category='P';
			    }
				else if(temp=="Gold" || temp=="gold"||temp=="GOLD")
				{
				category='g';
			    }
				else if(temp=="Economy" || temp=="economy"||temp=="ECONOMY")
				{
				category='E';
			    }
                cout<<endl;
                }while(isAlpha(category)); // error checking for a valid seat category 


			} while(!availableSeat(seat_number,category));
 do{
   string rowAndColumn;
    do {
			cout << "Choose Seat: " ; // change the seat status
			// this code will handle the change of color later
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			//SetConsoleTextAttribute(hConsole, 1);
			SetConsoleTextAttribute
					  (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			
			cin >> rowAndColumn ;
		   column_seat =atoi((rowAndColumn.substr(1,2)).c_str());//get the column from the string variable and convert to integer
			
			SetConsoleTextAttribute(hConsole, 7);
			
			SetConsoleTextAttribute(hConsole, 7);
			} while(rowAndColumn.length()!=2 && !checkRangeSeat(category,rowAndColumn[0],column_seat));
			column_seat--;
			row_seat = int (rowAndColumn[0]);	// change from A to 1. must always uppercase for the alphabet

			if (row_seat >= 65 && row_seat <= 80) //for the capital letter. Refer to ASCII table
			{
				row_seat = row_seat - 64;
			}
			else if (row_seat >= 97 && row_seat <= 112) // small letter. Refer to ASCII table
			{
				row_seat = row_seat - 96;
			}

			row_seat--; // because array always start at 0 so row - 1 is row become 0.

  }while(!verify_seat_status(row_seat,column_seat,seat_number));
	
	bool done =false;
	do
	 {            cout<<endl;
				 cout << "Action [O or X]: " ;
				 HANDLE hConsole;
						  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				//SetConsoleTextAttribute(hConsole, 1);
				SetConsoleTextAttribute
						  (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

				 cin >> seat_action;
				 SetConsoleTextAttribute(hConsole, 7);
				switch (seat_action)
				{
					case 'x' :
					case 'X' : seat_action = 'X';
					done =true;
					break;
					case 'o' :
					case 'O' : seat_action = 'O';
					done =true;
					break;
					default : cout << "Invalid Action,try again!" << endl;
					system("pause");
					break;
				}
	} while (!done);

	// change from A to 1. must always uppercase for the alphabet


	 update_seatingplan(seat_number);





}


bool isNum(char input)
{
	if(isalpha(input))
	{
	

		 cout<<"Input Error:Pleae Enter an integer value"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<char>::max(), '\n');
                        cout<<endl;
		return true;
	}
	else
	{
	cout<<endl;	//cout<<"not alpha";
	return false;
	}
}

//function to veify that the user as entered a valide seat category[T,t,P,p,G,g,E or e]
bool isAlpha(char input)
{

	if(isalpha(input))
	{

		if ((input == 'T') ||(input == 't') )
		{
		cout<<endl;
		return false;
		}
		else if ((input == 'P') ||(input == 'p') )
		{
		cout<<endl;
		return false;
		}
		else if ((input == 'G') ||(input == 'g') )
		{
		cout<<endl;
		return false;
		}
		else if ((input == 'E') ||(input == 'e') )
		{
		cout<<endl;
		return false;
		}
		else
		{
		 cout<<"Input Error:Pleae Enter a valid Seat Category [Twin,Premiere,Gold OR Economy]"<<endl;
         return true;
		}


	}
	else
	{

		 cout<<"Input Error:Pleae Enter a valid Seat Category [Twin,Premiere,Gold OR Economy]"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<char>::max(), '\n');
                        cout<<endl;
		return true;


	}
}

// function Available Seat takes 2 parameters the number of seat required and the seat category
bool availableSeat(int seat_number, char category)
{

 int start_column = 0;
   int end_column= 20;
   int start_row;
   int end_row ;
   int A = 0;
   int C= 0;
	if(seat_number>total_seat)
	{
    cout<<"Available Seats: None"<<endl;
	cout<<"Please Try Again!"<<endl;
	system("pause");
	return false;
	}
	else
	{
   cout<<"Available Seats:"<<endl;
   if(category=='E'||category=='e')
	{
	 start_row  = 12;
     end_row = 16;
     }
	else if(category=='G'||category=='g')
	{
	start_row  = 6;
    end_row = 11;
	}
	else if(category=='P'||category=='p')
	{
	start_row  = 0;
    end_row = 5;
	}

	else if(category=='T'||category=='t')
	{
	 start_column  = 4;
     end_column = 15;
	 start_row = 0;
     end_row = 1;
	 seat_number = seat_number*2;

	}


	
           if(category=='p'||category=='P')
            {
			
              	for(int j =0;j<=5;j++)
				{

				for(int y =0;y<20;y++)
				{
				int A= 0;
				for(int x= y;x<20 && cinema[j][x]=='*';x++)
				{
				if(cinema[j][x]=='*')
				{
				A = A + 1;
				}

				}


				if(A>=seat_number )//check if the number of available seat is greater than the seat required
				{
				if(j==0||j==1)
				{
				if(y!=4 && y!=5 && y!=6 && y!=7 && y!=8 && y!=9 && y!=10 && y!=11 && y!=12 && y!=13 && y!=14)
				{
				C = C+ 1;// variable to count the number of time there is an available seat we will use it down to display Available Seat:None Please try Again if C<=0
				cout << char(65 + j) <<y+1<<","<<A; //display the seat row, seat column and the number of available seat from that seat(I am using Ascii character table to display the letters)
				cout<<" ";
				}
				}
				else
				{
				C = C+ 1;// variable to count the number of time there is an available seat we will use it down to display Available Seat:None Please try Again if C<=0
				cout << char(65 + j) <<y+1<<","<<A; //display the seat row, seat column and the number of available seat from that seat(I am using Ascii character table to display the letters)
				cout<<" ";
				
				}
				}

				}
				cout<<endl;

				}
				return true;
				if (C<=0)
				{
				cout<<"None"<<endl;
				cout<<"Please Try Again!"<<endl;
				system("pause");
				return false;
				}

			
			
			
			}

               			
			
             else
             {			 
	
	

				for(int j =start_row;j<=end_row;j++)
				{

				for(int y =start_column;y<end_column;y++)
				{
				int A= 0;
				for(int x= y;x<end_column && cinema[j][x]=='*';x++)
				{
				if(cinema[j][x]=='*')
				{
				A = A + 1;
				}

				}


				if(A>=seat_number )//check if the number of available seat is greater than the seat required
				{
				 C = C+ 1;// variable to count the number of time there is an available seat we will use it down to display Available Seat:None Please try Again if C<=0
				cout << char(65 + j) <<y+1<<","<<A; //display the seat row, seat column and the number of available seat from that seat(I am using Ascii character table to display the letters)
				cout<<" ";
				}

				}
				cout<<endl;

				}
				return true;
				if (C<=0)
				{
				cout<<"None"<<endl;
				cout<<"Please Try Again!"<<endl;
				system("pause");
				return false;
				}

				}

	}			
	}
//function to verify that selected seat fall within the range of the category choosen
bool checkRangeSeat(char category,char row , int column)
{
if(category=='t'||category=='T')
{
if(row=='A' && column>=5 && column<=15 || row=='a' && column>=5 && column<=15)
{
return true;
}
else if(row=='B' && column>=5 && column<=15 || row=='b' && column>=5 && column<=15)
{
return true;
}
else
{
cout<<"Error:[choose row A or B and a colum between 5-15 for the Twin category]"<<endl;
return false;
}
}

else if(category=='G'||category=='g')
{
if(row=='G' || row=='g' && column>=1 && column<=20)
{
return true;
}
else if(row=='H' || row=='h' && column>=1 && column<=20)
{
return true;
}
else if(row=='I' || row=='i' && column>=1 && column<=20)
{
return true;
}
else if(row=='J' || row=='j' && column>=1 && column<=20)
{
return true;
}
else if(row=='K' || row=='k' && column>=1 && column<=20)
{
return true;
}
else if(row=='L' || row=='l' && column>=1 && column<=20)
{
return true;
}
else
{
cout<<"Error:[choose row [G,H,I,J,K,L]  and a colum between 1-20 for the Gold category]"<<endl;
return false;
}
}

else if(category=='E'||category=='e')
{
if(row=='M' && column>=1 && column<=20 || row=='m' && column>=1 && column<=20)
{
return true;
}
else if(row=='N'&& column>=1 && column<=20 || row=='n' && column>=1 && column<=20)
{
return true;
}
else if(row=='O'&& column>=1 && column<=20 || row=='o' && column>=1 && column<=20)
{
return true;
}
else if(row=='P'&& column>=1 && column<=20 || row=='p' && column>=1 && column<=20)
{
return true;
}

else
{
	cout<<"Error:Invalid Economic category]"<<endl;
return false;
}
}

else if(category=='p'||category=='P')
{
if(row=='A' && column>=1 && column<=4 || row=='a' && column>=1 && column<=4)
{
return true;
}
else if(row=='B' && column>=1 && column<=4 || row=='b' && column>=1 && column<=4)
{
return true;
}
if(row=='A' && column>=1 && column<=4|| row=='a' && column>15 && column<=20)
{
return true;
}
else if(row=='B' && column>=1 && column<=4 || row=='b' && column>15 && column<=20)
{
return true;
}
else if(row=='C' && column>=1 && column<=20 || row=='c' && column>=1 && column<=20)
{
return true;
}
else if(row=='D'&& column>=1 && column<=20 || row=='d' && column>=1 && column<=20)
{
return true;
}
else if(row=='E'&& column>=1 && column<=20 || row=='e' && column>=1 && column<=20)
{
return true;
}
else if(row=='F'&& column>=1 && column<=20 || row=='f' && column>=1 && column<=20)
{
return true;
}
else
{
cout<<"Error:Invalid Premiere Category "<<endl;
return false;
}
}


}

bool verify_seat_status(int row,int column,int seat_number)
{
	int C = 0;
	int A= 0;
	int limit = 20;
	if (category=='t'|| category=='T')
	{
		seat_number = seat_number*2;
		limit = 15;
	}

	for(int x= column;x<limit && cinema[row][x]=='*';x++)
	{
		if(cinema[row][x]=='*')
		{
		A = A + 1;
		}




	if(A>=seat_number )//check if the number of available seat is greater than the seat required
	{

		C=C+1;
	return true;
	}

	}
	if (C<=0)
	{	cout<<column;
	 cout<<row;
	 cout<<seat_number;
	cout<<"Insufficient Seat "<<endl;
	cout<<"Please Try Again!"<<endl;
	system("pause");
	return false;
	}


	if(cinema[row][column]!='*')
	{
	cout<<"Seat already Booked";
	cout<<"Please Try another Seat"<<endl;
	}
	return false;
}

int update_sales(int seat_number)

{
	if(seat_action=='o'||seat_action=='O')
	{
	price = 0;
	}
	else if(seat_action=='X'||seat_action=='x')
	{
	if(category=='t' ||category=='T')
	{
	price = 15;
	}
	else if(category=='p' ||category=='P')
	{
	price = 12;
	}
	if(category=='G' ||category=='g')
	{
	price = 10;
	}
	if(category=='e' ||category=='E')
	{
	price = 6;
	}
	}

total_sales =total_sales+ (seat_number*price);

return total_sales;
}
void update_seatingplan(int seat_number)
{
	if(category=='t'||category=='T')
	{
	seat_number=seat_number*2;
	}
	for (int k = 0; k <seat_number; k++)

	{
		cinema[row_seat][column_seat + k] = seat_action; // column_seat + k to add the seat and in the same time change the seat status

	}
	total_seat = total_seat - seat_number;
	update_sales(seat_number);
	seating_plan();
	while(!IsContinue)
	{

	        cout<<endl;
            cout<<" "<< "Do you want to Assign another seat?\n";        //option for user to repeat program or end program
            cout<<" "<< "Type any key & press enter continue or\n";
            cout<<" "<< "Type (q) & press enter to quit the program\n";
            cout<<" "<< "Option : ";
            cin >> answer;
            cout<<endl;

			if ((answer == 'Q') || (answer == 'q'))
			{
				while ( IsContinue );

                cout<<endl;
				cout << "(:Thank You ! Have a nice show ! :)" << endl; // quit message
				system("pause");
				IsContinue = true;
			}
    seatAssigment();
	}




}

void seating_plan()
{
system("cls");
cout<<endl;


cout <<"  "; // space number 1
	for(int c = 1 ; c <= 20; c++) // number column 1,2... 20
	{
		if(c == 5 || c == 17)
		{
			cout << "   "; // space the number 1
		}
	    cout << c << " ";
	}cout << endl;


	for(int a = 0; a < 16; a++) // row
	{
	if(a == 6 || a == 12)
	{
		cout << endl; // row spaces between F-G and L-M
	}
		cout << char(65 + a) << " "; //add alphabet on 1st, row 65 is ASCII code which represent a


			for(int b = 0; b < 20; b++) // * column
			{
			if (b == 4 || b == 16) // column space for the door
				{
				cout <<"   ";
				}
				if ( b >= 9)
				{
					cout <<cinema [a][b] <<"  "; // got [] [] is array
				}
				else
				{
				cout <<cinema [a][b] <<" "; //show the star
				}
			}
			cout << endl;
	}

	cout<<"  ";
				for(int i=1;i<=54;i++)
				{
				cout<<"-";
				}
				cout<< endl;
				cout<<" |\t\t\t   S C R E E N \t\t\t|"<< endl;
				cout<<"  ";
				for(int i=1;i<=54;i++)
				{
				cout<<"-";
				}
				cout<< endl;
				cout<< endl;
				//cout<< "  ";

cout << "Number of seat available: " << total_seat << endl;
					cout << "Total sales: " << total_sales << endl;
					cout << endl;

}

void reset_seating_plan()
{
	for(int i = 0 ; i < 16; i++) // set the symbol *
	{
	    for(int j = 0; j < 20; j++)
		{


			cinema [i][j] = '*';

		}
	}
	total_sales = 0;
	total_seat = 320;
	seating_plan();
}

int payment_reserved_seat()
{
	do {
		cout<<endl;


				cout << " --------------------------" << endl;
				cout << "|Seat category    |Price(RM)" << endl;
				cout << "|---------------- |--------|" << endl;
				cout << "|       Twin      |   15   |" << endl;
				cout << "|       Premeire  |   12   |" << endl;
				cout << "|       Gold      |   10   |" << endl;
				cout << "|    Economy   |   6    |" << endl;
				cout << "----------------------------" << endl;

			    do
                {
                cout<<endl;
                cout<<"Desired seat category: ";
                cin >> category;
                cout<<endl;
                }while(isAlpha(category)); // error checking for a valid seat category [T,t,G,g,P,p,E,e]



    cout << "Choose Row Seat:" << endl; // change the seat status
    /* this code will handle the change of color later
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);*/
	
	cin >> row_convert ;
	cout << "Choose your Column seat" << endl;
	cin >> column_seat ;
	} while(!checkRangeSeat(category,row_convert,column_seat));

	column_seat--;
	row_seat = int (row_convert);	// change from A to 1. must always uppercase for the alphabet

	if (row_seat >= 65 && row_seat <= 80) //for the capital letter. Refer to ASCII table
	{
		row_seat = row_seat - 64;
	}
	else if (row_seat >= 97 && row_seat <= 112) // small letter. Refer to ASCII table
	{
		row_seat = row_seat - 96;
	}

	row_seat--; // because array always start at 0 so row - 1 is row become 0.
	if(cinema [row_seat][column_seat] =='O'||cinema [row_seat][column_seat] =='o')
	{
	cinema [row_seat][column_seat] ='X';

	if(category=='t' ||category=='T')
	{
	price = 15;
	}
	else if(category=='p' ||category=='P')
	{
	price = 12;
	}
	if(category=='G' ||category=='g')
	{
	price = 10;
	}
	if(category=='e' ||category=='E')
	{
	price = 6;
	}


total_sales =total_sales + price;

return total_sales;
	}

	else
	{
		cout<<"You are not allow to make a payment for this seat"<<endl;
		system("pause");
	}


	seating_plan();

}