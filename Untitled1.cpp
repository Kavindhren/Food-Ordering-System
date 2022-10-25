#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>

using namespace std;

//welcoming
void welcome();

//main menu
void main_menu();

//administration Section
void administration_section();
void add_staff();
void view_staff();
void menu_price();
void add_food();

//customer section
void customer_section();
void vegetarian();
void non_vegetarian();
void details_veg();
void details_nveg();
void veg_sales();
void nveg_sales();
void nof_veg();
void nof_nveg();
void customer_veg();
void customer_nveg();

void about_us();

int main()
{
	welcome();
	main_menu();
	
	return 0;
}

void welcome() // this function displays welcoming messages
{
	cout<<"\n********************************************** WELCOME TO SHANVI VILLAS **********************************************"<<endl;
	cout<<"-----------------------------------------where food speaks with your palate!!!-----------------------------------------"<<endl;
}

void main_menu() // this function displays options for further information for administration and customers
{
	int choice;
	cout<<"\n\nPlease enter your choice:-\n"<<endl;
	cout<<"1)	Administration Section\n"<<endl;
	cout<<"2)	Customer Section\n"<<endl;
	cout<<"3)	About Us\n"<<endl;
	cout<<"4)	Exit\n"<<endl;
	cin>>choice;
	if(choice==1)//option 1 brings to administration section
	{
		administration_section();
	}
	else if(choice==2)//option 2 brings to customer section
	{
		customer_section();
	}
	else if(choice==3)//option 3 reveals restaurants details
	{
		about_us();
	}
	else if(choice==4)//option 4 to exit from program
	{
		system("cls");
		
		cout<<"\n\n\n*****************************************************THANK YOU*********************************************************\n"<<endl;

		cout<<"******************************************Eat right. Work hard. Feel good.*********************************************\n\n"<<endl;
	}
	else //main_menu function will be called if user enters wrong input
	{
		system("cls");
		cout<<"Wrong entry. Please try again. Thank you"<<endl;
		main_menu();
	}
	
	
}
void administration_section()//allows manager to look into restaurant organisation and details
{
	int adChoice;
	system("cls");
	cout<<"						Please enter your choice\n"<<endl;
	cout<<"			1) Add new staff record-->"; //add new staff details when staff gets hired
	cout<<"			    2) View staffs records-->\n"<<endl;//view all staffs' details
	cout<<"			3) View menu-->";//view food menu,prices and food preparation time
	cout<<"					    4) Add new food to menu-->\n"<<endl;//add new meal/food to menu
	cout<<"			5) View orders-->";//view all orders placed by customers
	cout<<"				    6) Total orders-->\n"<<endl;//view total orders received 
	cout<<"			7) Total sales-->";//view total sales reached by restaurant 
	cout<<"				    8) Number of customers-->\n"<<endl;// view number of customers who placed orders
	cout<<"	 				9) Back to main menu-->\n"<<endl;//back to main menu fucntion
	cin>>adChoice;
	if(adChoice==1)//option 1 calls add_staff function to add new staff's records
	{
		add_staff(); 
	}
	else if(adChoice==2)//option 2 calls view_staff function to view all records of staffs
	{
		view_staff();
	}
	else if(adChoice==3)//option 3 calls manu_price function to view food menu,prices and food preparation time
	{
		menu_price();
	}
	else if(adChoice==4)//option 4 calls add_food function to add new meal/food to restaurant's menu
	{
		add_food();
	}
	else if(adChoice==5)//option 5 let's higher ups to view order records placed by customers
	{
		system("cls");
		int order;
		cout<<"\n	Enter '1' to view vegetarian order records    |    Enter '2' to view non-vegetarian order records"<<endl;
		cin>>order;
		if(order==1)//option 1 allows to view vegetarian orders placed by customers 
		{
			system("cls");
			string myText;
	    	ifstream MyReadFile("Order record Veg.txt");//read from the text file  
	    
    		while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    		{
				cout << myText<<endl;//output the text from the file
			}
   			MyReadFile.close();// Close the file
   			string b;
   			cout<<"\n\nEnter any key to get back to administration "<<endl;
   			cin>>b;
   			administration_section();
		}
		else if(order==2)//option 2 allows to view non-vegetarian orders placed by customers
		{
			system("cls");
			string myText;
   			ifstream MyReadFile("Order record Non-veg.txt");//read from the text file  
   
    		while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
   			{
				cout << myText<<endl;//output the text from the file
			}
   			MyReadFile.close();// Close the file
   			string b;
   			cout<<"\n\nEnter any key to get back to administration "<<endl;
   			cin>>b;
   			administration_section();	
		}
		else 
		{//program will be revert to administration section if input was other than 1 or 2 is enetered
			system("cls");
			cout<<"You have entered a wrong entry so system will be restarted"<<endl;
			administration_section();
		}
		
	}
	else if(adChoice==6)//option 6 allows to view total number of oders placed 
	{
		system("cls");
		int check;
		cout<<"\n  Enter '1' to check number of order for vegetarian  |   Enter '2' to check number of order for non-vegetarian "<<endl;
		cin>>check;
		if(check==1)//option 1 allows to view total number of orders plaved for vegetarian food by customers
		{
			system("cls");
			nof_veg();
		}
		else if(check==2)//option 2 allows to view total number of orders plaved for non-vegetarian food by customers
		{
			system("cls");
			nof_nveg();
		}
		else//program will be revert to administration section if input was other than 1 or 2 is enetered
		{
			system("cls");
			administration_section();
		}
	}
	else if(adChoice==7)//option 7 allows to view total sales 
	{
		system("cls");
		int check;
		cout<<"\n  		 Enter '1' to check vegetarian sales   |   Enter '2' to check non-vegetarian sales"<<endl;
		cin>>check;
		if(check==1)//option 1 allows to view total sales for vegetarian 
		{
			system("cls");
			veg_sales();
		}
		else if(check==2)//option 1 allows to view total sales for non-vegetarian
		{
			system("cls");
			nveg_sales();
		}
		else//program will be revert to administration section if input was other than 1 or 2 is enetered
		{
			system("cls");
			administration_section();
		}
	}
	else if(adChoice==8)//choice 8 allows to view number of customers who placed oders
	{
		system("cls");
		int check;
		cout<<"\n  Enter '1' to check number of customers for vegetarian   |    Enter '2' to check number of customer for non-vegetarian"<<endl;
		cin>>check;
		if(check==1)//option 1 allows to vies number of customers for vegetarian
		{
			system("cls");
			customer_veg();
		}
		else if(check==2)//option 1 allows to vies number of customers for non-vegetarian
		{
			system("cls");
			customer_nveg();
		}
		else//program will be revert to administration section if input was other than 1 or 2 is enetered
		{
			system("cls");
			administration_section();
		}
	}
	else if(adChoice==9)//option 9 allows to go back to main menu
	{
		system("cls");
		main_menu();
	}
	else//wrong entry so program goes back to administration_section() until it gets correct input
	{
		while(adChoice<=1||adChoice>=9)
		{
			cout<<"Wrong Entry!! Try again"<<endl;
			administration_section();
		}
	}

}

void add_staff()//this fucntion allows manager to add staffs
{
	system("cls");
	char addChoice;
	string name,dob,place,department;
	long long int id,year;
	ofstream outputFile;
	ifstream inputFile;
	inputFile.open("Add Staff.txt");
	outputFile.open("Add Staff.txt",ios::app);
	if(inputFile.is_open())
		cout<<"1.Staff name: ";
		cin.ignore();
		getline(cin, name);
		cout<<"2.Staff ID: ";
		cin>>id;
		cout<<"3.Date of birth (DD/MM/YYYY): ";
		cin>>dob;
		cout<<"4.Hired year: ";
		cin>>year;
		cout<<"5.Staff's from: ";
		cin.ignore();
        getline(cin, place);
		cout<<"6.Department: ";
		getline(cin, department);
		cout<<"\n"<<endl;
		//staff's details will be saved into textfile
		outputFile<<"Name: "<<name<<endl;
	    outputFile<<"ID: "<<id<<endl;
	    outputFile<<"Date of birth: "<<dob<<endl;
    	outputFile<<"Hired year: "<<year<<endl;
    	outputFile<<"Staff's from: "<<place<<endl;
    	outputFile<<"Department: "<<department<<endl;
    	outputFile<<"\n";

	outputFile.close();
	inputFile.close();
	
	begining:
	cout<<"Do you wish to add new record"<<endl;
	cout<<"If yes please click Y or y or else please click N or n"<<endl;
	cin>>addChoice;
	
		if(addChoice=='Y'||addChoice=='y')//enter yes to insert new staff's details
		{
			add_staff();
		}
		else if(addChoice=='N'||addChoice=='n')//exit if no more staff details to add
		{
			administration_section();
		}
		else//wrong input doesn't lead to new path, the program stays as it is till user enters valid input
		{
			system("cls");
			cout<<"\n\nWrong entry!! Try again"<<endl;
			goto begining;
		}
	
}

void view_staff()//function to view staffs' records
{
	system("cls");
	string myText;
	char back;
    ifstream MyReadFile("Add Staff.txt");//read from the text file  
    
    while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    {
		cout << myText<<endl;//output the text from the file
	}
   MyReadFile.close();// Close the file
   
   begining:
   cout<<"\nEnter B to go back to administration section "<<endl;
   cin>>back;
   if(back=='B'||back=='b')//brings back to administration section
   administration_section();
   else//wrong input doesn't lead to new path, the program stays as it is till user enters valid input
   	system("cls");
   goto begining;
	
}

void menu_price()//function to view food menu,price and preparation time
{
	string myText;
	int foodOption,option;
	char opt;
	system("cls");
	cout<<"Select your choice to view the chosen option"<<endl;
	cout<<"  |\n  |\n  |"<<endl;
	cout<<"  --> 1) Non-Vegetarian\n  |"<<endl;
	cout<<"  --> 2) Vegetarian\n  |"<<endl;
	cout<<"  --> 3) Back to administration section"<<endl;
	cin>>foodOption;
	if(foodOption==1)//opens non-vegetarian's menu
	{
		system("cls");
		ifstream MyReadFile("Non-vegetarian.txt");//read from the text file  
    
    	while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    	{
			cout << myText<<endl;//output the text from the file
		}
   		MyReadFile.close();// Close the file
   		cout<<"\nClick 'B' to go back to food option"<<endl;
   		cin>>opt;
   		if(opt=='B'||opt=='b')//brings back to menu_price
   		{
   			menu_price();
		}
		else //wrong input will restart the program. Thus, the program starts from main menu
		{
			system("cls");
			cout<<"You have entered a wrong entry so system will be restarted"<<endl;
			main_menu();
		}
	}
	else if(foodOption==2)//opens vegetarian menu
	{
		char opt;
		system("cls");
		ifstream MyReadFile("Vegetarian.txt");//read from the text file  
    
    	while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    	{
			cout << myText<<endl;//output the text from the file
		}
   		MyReadFile.close();// Close the file
   		cout<<"\nClick 'B' to go back to food option"<<endl;
   		cin>>opt;
   		if(opt=='B'||opt=='b')
   		{
   			menu_price();//brings back to menu_price
		}
		else//wrong input will restart the program. Thus, the program starts from main menu
		{
			system("cls");
			cout<<"You have entered a wrong entry so system will be restarted"<<endl;
			main_menu();
		}		
	}
	else if(foodOption==3)//brings back to administration section
	{
		administration_section();
	}
	else//menu_price function will be called if input other than 1,2 or 3 is entered 
	{
		menu_price();
	}
    
}

void add_food()//allows to add new food to menu
{
	system("cls");
	int add;
	char addChoice;
	string food,price,time;
	cout<<"Add new food to:"<<endl;
	cout<<"  |\n  |\n  |"<<endl;
	cout<<"  --> 1) Non-Vegetarian\n  |"<<endl;
	cout<<"  --> 2) Vegetarian"<<endl;
	cin>>add;
	if(add==1)//alows to add new food in non-vegetarian's menu
	{
		system("cls");
		cout<<"1)Menu format!!\nFood's name should be followed with code number\n	RULES:\n	-(code number must be added by 3 with previous food's code number)\n	-(Refer to food menu before adding new food)"<<endl;
		cout<<"2)Price should be written in numbers followed by reference 'price' in bracket	\nExample:	\n**.** (price)"<<endl;
		cout<<"3)Preparation time should be written in numbers followed by reference 'mins' "<<endl;
		cout<<"4)Failed to do so will lead to program crash or food option wouldn't be accpeted by program"<<endl;
		ofstream outputFile;
		ifstream inputFile;
		inputFile.open("Non-Vegetarian.txt");
		outputFile.open("Non-Vegetarian.txt",ios::app);
		if(inputFile.is_open())
		cout<<"\n1.Food name: ";
		cin.ignore();
		getline(cin, food);
		cout<<"2.Price: ";
		getline(cin, price);
		cout<<"3.Preparation time: ";
		getline(cin, time);
		
		outputFile<<food<<"\n"<<price<<"\n"<<time<<endl; //details will be added to textfile

	outputFile.close();
	inputFile.close();
	
	cout<<"Do you wish to add new record"<<endl;
	cout<<"If yes please click Y or y or else please click N or n"<<endl;
	cin>>addChoice;
	
		if(addChoice=='Y'||addChoice=='y')//enter Y/y to insert new staff's details
		{
			add_food();
		}
		else if(addChoice=='N'||addChoice=='n')//enetr N/n to exit if no more staff details to add
		{
			administration_section();
		}
		else//program will be restarted 
		{
			system("cls");
			cout<<"wrong entry, program will be restarted"<<endl;
			main_menu();
		}
	
	}
	else if(add==2)//alows to add new food in vegetarian's menu
	{
		system("cls");
		cout<<"1)Menu format!!\nFood's name should be followed with code number\n	RULES:\n	-(code number must be added by 3 with previous food's code number)\n	-(Refer to food menu before adding new food)"<<endl;
		cout<<"2)Price should be written in numbers followed by reference 'price' in bracket	\nExample:	\n**.** (price)"<<endl;
		cout<<"3)Preparation time should be written in numbers followed by reference 'mins' "<<endl;
		cout<<"4)Failed to do so will lead to program crash or food option wouldn't be accpeted by program"<<endl;
		ofstream outputFile;
		ifstream inputFile;
		inputFile.open("Vegetarian.txt");
		outputFile.open("Vegetarian.txt",ios::app);
		if(inputFile.is_open())
		cout<<"1.Food name: ";
		cin.ignore();
		getline(cin, food);
		cout<<"2.Price: ";
		getline(cin, price);
		cout<<"3.Preparation time: ";
		getline(cin, time);
		
		outputFile<<food<<"\n"<<price<<"\n"<<time<<endl; //stored data in textfile

	outputFile.close();
	inputFile.close();
	
	cout<<"Do you wish to add new record"<<endl;
	cout<<"If yes please click Y or y or else please click N or n"<<endl;
	cin>>addChoice;
	
		if(addChoice=='Y'||addChoice=='y')//enter Y/y to insert new staff's details
		{
			add_food();
		}
		else if(addChoice=='N'||addChoice=='n')//enter N/n exit if no more staff details to add
		{
			administration_section();
		}
		else//program will be restarted 
		{
			system("cls");
			cout<<"wrong entry, program will be restarted"<<endl;
			main_menu();
		}
	
	}
	else//inputs other than 1 or 2 will call add_food function again
	{
		system("cls");
		add_food();
	}
}


void customer_section()//allow customers to placed order on non-vegetarian/vegetaraian
{
	double total;
	system("cls");
	int num;
	cout<<"Enter your choice:"<<endl;
	cout<<"  |\n  |\n  |"<<endl;
	cout<<"  -->1) Non-vegetarian\n  |"<<endl;
	cout<<"  -->2) Vegetarian\n  |"<<endl;
	cout<<"  -->3) Main menu"<<endl;
	cin>>num;
	if(num==1)//can place order for non-vegetarian food
	{
		system("cls");
		non_vegetarian();
	}
	else if(num==2)//can place order for vegetarian food
	{
		system("cls");
		vegetarian();
	}
	else if(num==3)//reverts back to main_menu
	{
		system("cls");
		main_menu();
	}
	else//program stays in customer section until customer enter a valid input
	customer_section();
}
	
void vegetarian()//vegetarian section
{	
	details_veg();
	system("cls");
	double n_total=0,t_time=0,total_sales=0,eh_sales=0;
	begining:
	string myText;
	ifstream MyReadFile("Vegetarian.txt");//read from the text file  
    
    	while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    	{
			cout << myText<<endl;//output the text from the file
		}
   	MyReadFile.close();// Close the file
   	
	int num;
  	cout<<"\nEnter the code of food you want to order: "<<endl;	
   	cin>>num;
   	
   	double numb;
    string line;
	ifstream file ("Vegetarian.txt");//this file is opened to read price of the specific food order
  	if (file.is_open())
 	{
   		for (int lineno = 1; getline (file,line) && lineno < 100; lineno++)
      	if (lineno == num+1)
      	{
      		numb=stod(line);
		}
    	file.close();
  	}
  	
    string line1,name;
	ifstream infile ("Vegetarian.txt");//this file is opened to read name of the food oder and store it in different file to calcuate total orders
  	if (infile.is_open())
 	{
   		for (int lineno = 1; getline (infile,line1) && lineno < 100; lineno++)
      	if (lineno == num)
      	{
      		name=line1;
      		
      		ofstream outFile;
			ifstream inFile;
			inFile.open("veg_name.txt");
			outFile.open("veg_name.txt",ios::app);
			if(inFile.is_open())
	
			outFile<<name<<endl;
	
			outFile.close();
			inFile.close();
		}
    	infile.close();
  	}
  	
  	double numb2,time;
    string line2;
	ifstream inputfile ("Vegetarian.txt");//this file is opened to read preparation time for specific order
  	if (inputfile.is_open())
 	{
   		for (int lineno = 1; getline (inputfile,line2) && lineno < 100; lineno++)
      	if (lineno == num+2)
      	{
      		numb2=stod(line2);
		}
    	inputfile.close();
  	}
  	
	//formule below calculates total by multipling quantity of the order placed with price of the order
	double total;
	int quantity;
	cout<<"Enter the quantity you want: "<<endl;
	cin>>quantity;
	total=numb*quantity;
	
	ofstream outputFile;
	ifstream inputFile;
	inputFile.open("Order record Veg.txt");
	outputFile.open("Order record Veg.txt",ios::app);
	if(inputFile.is_open())
	
	outputFile<<quantity<<" "<<name<<" is odered"<<endl;//this text file is opened to store ordered food name and quantity
	
	outputFile.close();
	inputFile.close();	
	
	//formule below calculates the grand total
	int choice;
	n_total +=total;
	cout<<"\nYour total will be RM"<<n_total<<endl;
	
	//the formule below calculates the total preparation time 
	time=quantity*numb2;
  	t_time=t_time+time;
  	cout<<"Your order will be prepared in "<<t_time<<"minutes"<<endl;
	
	cout<<"Press 1 to continue ordering!\nPress 2 to get your total!"<<endl;
  	cin>>choice;
  	if(choice==1)//allows customer to place another order
  	{
  		system("cls");
  		goto begining;
	}
	else if(choice==2)//program terminates and outputs grand total and delivering time
	{
		system("cls");
		cout<<"Grand Total: RM"<<n_total<<endl;
		cout<<"Your order will be delivered in "<<t_time+10<<" mins "<<endl;//10(average delivery time) is added to preparation time to get delievry time
		ofstream outputFile;
		ifstream inputFile;
		inputFile.open("Order record Veg.txt");
		outputFile.open("Order record Veg.txt",ios::app);
		if(inputFile.is_open())
		
		outputFile<<"the total amount will be RM"<<n_total<<endl;//grand total is stored in textfile
		outputFile<<"your order will be delivered in "<<t_time+10<<" minutes\n"<<endl;//delivery time is stored in textfile
		
		outputFile.close();
		inputFile.close();	
		
		ofstream outFile;
		ifstream inFile;
		inFile.open("Vegetarian sales record.txt");
		outFile.open("Vegetarian sales record.txt",ios::app);
		if(inFile.is_open())
	
		outFile<<n_total<<endl;//grand total is stored in different textfile to calculate total sales
	
		outFile.close();
		inFile.close();
	cout<<"\n\n\n*****************************************************THANK YOU*********************************************************\n"<<endl;

	cout<<"******************************************Eat right. Work hard. Feel good.*********************************************\n\n"<<endl;
	}
}

void veg_sales()
{
	system("cls");
	string myText;
	double num,total=0;
	ifstream MyReadFile("Vegetarian sales record.txt");//read from the text file  
    
    	while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    	{
    		num=stod(myText);
    		total+=num;
		}
		cout<<"Total sales for vegetarian is: RM"<<total;//shows total sales for vegetarian
   	MyReadFile.close();// Close the file	
   	MyReadFile.close();// Close the file	
   	string b;
   	cout<<"\n\nEnter any key to get back to administration "<<endl;//back to administration section
   	cin>>b;
   	administration_section();
}

void nof_veg()
{
	system("cls");
	int count = 0;
    string line;
 
    /* Creating input filestream */ 
    ifstream file("veg_name.txt");
    while (getline(file, line))
        count++;
 
    cout << "Numbers of vegetarian orders: " << count << endl;//number of total vegetarian orders
    string b;
   	cout<<"\n\nEnter any key to get back to administration "<<endl;//back to administration section
  	cin>>b;
	administration_section();
}

void details_veg()//customer's details stored in 2d array
{
	system("cls");
	string arr[50][50];
	ofstream outputFile;
	ifstream inputFile;
	inputFile.open("Order record Veg.txt");
	outputFile.open("Order record Veg.txt",ios::app);
	if(inputFile.is_open())
	outputFile<<"\nCustomer's name, contact number, email address and address: "<<endl;
	cout<<"Please insert\n-name\n-contact number\n-email address\n-address "<<endl;
	cin.ignore();
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			std::getline(std::cin, arr[i][j]);
			outputFile<<arr[i][j]<<endl;
		}
	}
		ofstream outFile;
		ifstream inFile;
		inFile.open("Veg customer.txt");
		outFile.open("Veg customer.txt",ios::app);
		if(inFile.is_open())
	
		outFile<<arr[0][0]<<endl;//arr[0][0] which is customer's name is stored in different textfile to calculate total number of customers
	
		outFile.close();
		inFile.close();	

	outputFile.close();
	inputFile.close();	

		
}

void customer_veg()
{
	system("cls");
	int count = 0;
    string line;
 
    /* Creating input filestream */ 
    ifstream file("Veg customer.txt");
    while (getline(file, line))
        count++;
 
    cout << "Numbers of vegetarian customers: " << count << endl;//shows total number of customers who placed orders for vegetarian foods
    string b;
   	cout<<"\n\nEnter any key to get back to administration "<<endl;
  	cin>>b;
	administration_section();//back to administration section
}

void non_vegetarian()//non-vegetarian section
{	
	details_nveg();
	system("cls");
	double n_total=0,t_time=0;
	begining:
	string myText;
	ifstream MyReadFile("Non-vegetarian.txt");//read from the text file  
    
    	while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    	{
			cout << myText<<endl;//output the text from the file
		}
   	MyReadFile.close();// Close the file
   	
	int num;
  	cout<<"\nEnter the code of food you want to order: "<<endl;	
   	cin>>num;
   	
   	double numb;
    string line;
	ifstream file ("Non-vegetarian.txt");//this file is opened to read price of the specific food order
  	if (file.is_open())
 	{
   		for (int lineno = 1; getline (file,line) && lineno < 100; lineno++)
      	if (lineno == num+1)
      	{
      		numb=stod(line);
		}
    	file.close();
  	}
  	
    string line1,name;
	ifstream infile ("Non-vegetarian.txt");//this file is opened to read name of the food oder and store it in different file to calcuate total orders
  	if (infile.is_open())
 	{
   		for (int lineno = 1; getline (infile,line1) && lineno < 100; lineno++)
      	if (lineno == num)
      	{
      		name=line1;
      		
      		ofstream outFile;
			ifstream inFile;
			inFile.open("nveg_name.txt");
			outFile.open("nveg_name.txt",ios::app);
			if(inFile.is_open())
	
			outFile<<name<<endl;
		}
    	infile.close();
  	}
  	
  	double numb2,time;
    string line2;
	ifstream inputfile ("Non-vegetarian.txt");//this file is opened to read preparation time for specific order
  	if (inputfile.is_open())
 	{
   		for (int lineno = 1; getline (inputfile,line2) && lineno < 100; lineno++)
      	if (lineno == num+2)
      	{
      		numb2=stod(line2);
		}
    	inputfile.close();
  	}
  	//formule below calculates total by multipling quantity of the order placed with price of the order
	double total;
	int quantity;
	cout<<"Enter the quantity you want: "<<endl;
	cin>>quantity;
	total=numb*quantity;
	
	ofstream outputFile;
	ifstream inputFile;
	inputFile.open("Order record Non-veg.txt");
	outputFile.open("Order record Non-veg.txt",ios::app);
	if(inputFile.is_open())
	
	outputFile<<quantity<<" "<<name<<" is odered"<<endl;//this text file is opened to store ordered food name and quantity
	
	outputFile.close();
	inputFile.close();	
	
	//formule below calculates the grand total
	int choice;
	n_total +=total;
	cout<<"\n"<<n_total<<endl;
	
	//the formule below calculates the total preparation time 
	time=quantity*numb2;
  	t_time=t_time+time;
  	cout<<t_time<<endl;
	
	cout<<"Press 1 to continue ordering!\nPress 2 to get your total!"<<endl;
  	cin>>choice;
  	if(choice==1)//allows customer to place another order
  	{
  		system("cls");
  		goto begining;
	}
	else if(choice==2)//program terminates and outputs grand total and delivering time
	{
		system("cls");
		cout<<"Grand Total: RM"<<n_total<<endl;
		cout<<"Your order will be delivered in "<<t_time+10<<" mins "<<endl;//10(average delivery time) is added to preparation time to get delievry time
		ofstream outputFile;
		ifstream inputFile;
		inputFile.open("Order record Non-veg.txt");
		outputFile.open("Order record Non-veg.txt",ios::app);
		if(inputFile.is_open())
		
		outputFile<<"the total amount will be RM"<<n_total<<endl;//grand total is stored in textfile
		outputFile<<"your order will be delivered in "<<t_time+10<<" minutes\n"<<endl;//delivery time is stored in textfile
		
		outputFile.close();
		inputFile.close();	
		
		ofstream outFile;
		ifstream inFile;
		inFile.open("Non-vegetarian sales record.txt");
		outFile.open("Non-vegetarian sales record.txt",ios::app);
		if(inFile.is_open())
	
		outFile<<n_total<<endl;//grand total is stored in different textfile to calculate total sales
	
		outFile.close();
		inFile.close();
		
	cout<<"\n\n\n*****************************************************THANK YOU*********************************************************\n"<<endl;

	cout<<"******************************************Eat right. Work hard. Feel good.*********************************************\n\n"<<endl;
	}
}

void nveg_sales()
{
	system("cls");
	string myText;
	double num,total=0;
	ifstream MyReadFile("Non-vegetarian sales record.txt");//read from the text file  
    
    	while (getline (MyReadFile, myText)) //use a while loop together with the getline() function to read the file line by line
    	{
    		num=stod(myText);
    		total+=num;
		}
		cout<<"Total sales for Non-vegetarian is: RM"<<total;//shows total sales for non-vegetarian
   	MyReadFile.close();// Close the file	
   	string b;
   	cout<<"\n\nEnter any key to get back to administration "<<endl;
   	cin>>b;
   	administration_section();//back to administration section
}

void nof_nveg()
{
	system("cls");
	int count = 0;
    string line;
 
    /* Creating input filestream */ 
    ifstream file("nveg_name.txt");
    while (getline(file, line))
        count++;
 
    cout << "Numbers of non-vegetarian orders: " << count << endl;//number of total non-vegetarian orders
    string b;
   	cout<<"\n\nEnter any key to get back to administration "<<endl;//back to administration section
   	cin>>b;
   	administration_section();
}


void details_nveg()//customer's details stored in 2d array
{
	system("cls");
	string arr[50][50];
	ofstream outputFile;
	ifstream inputFile;
	inputFile.open("Order record Non-veg.txt");
	outputFile.open("Order record Non-veg.txt",ios::app);
	if(inputFile.is_open())
	outputFile<<"\nCustomer's name, contact number, email address and address: "<<endl;
	cout<<"Please insert\n-name\n-contact number\n-email address\n-address "<<endl;
	cin.ignore();
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			std::getline(std::cin, arr[i][j]);
			outputFile<<arr[i][j]<<endl;
		}
	}
		ofstream outFile;
		ifstream inFile;
		inFile.open("Non-veg customer.txt");
		outFile.open("Non-veg customer.txt",ios::app);
		if(inFile.is_open())
	
		outFile<<arr[0][0]<<endl;//arr[0][0] which is customer's name is stored in different textfile to calculate total number of customers
	
		outFile.close();
		inFile.close();	

	outputFile.close();
	inputFile.close();	

		
}

void customer_nveg()
{
	system("cls");
	int count = 0;
    string line;
 
    /* Creating input filestream */ 
    ifstream file("Non-veg customer.txt");
    while (getline(file, line))
        count++;
 
    cout << "Numbers of non-vegetarian customers: " << count << endl;//shows total number of customers who placed orders for non-vegetarian foods
    string b;
   	cout<<"\n\nEnter any key to get back to administration "<<endl;
  	cin>>b;
	administration_section();//back to administration section
}

void about_us()
{
	system("cls");

	cout<<"					Doing the Right Thing Since 1968"<<endl;
	cout<<"			The friendly greeting you get when you visit Shanti Villas isn't a gimmick."<<endl;
	cout<<"	              It's how we do business, and always have. Sure, we've grown, but our aim is still"<<endl;
	cout<<"			     to be like a hometown neihbor -- relible,valued,trustworthy."<<endl;

	string b;
   	cout<<"\n\nEnter any key to get back to administration "<<endl;//back to administration section
   	cin>>b;
   	main_menu();
}



