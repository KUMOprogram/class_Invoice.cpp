//(Invoice Class) Create a class called Invoice that a hardware store might use to represent
//an invoice for an item sold at the store. An Invoice should include four data members—a part number
//(type string), a part description (type string), a quantity of the item being purchased (type int)
//and a price per item (type int). [Note: In subsequent chapters, we’ll use numbers that contain
//decimal points (e.g., 2.75)—called floating-point values—to represent dollar amounts.] Your class
//should have a constructor that initializes the four data members. Provide a set and a get function for
//each data member. In addition, provide a member function named getInvoiceAmount that calculates
//the invoice amount (i.e., multiplies the quantity by the price per item), then returns the
//amount as an int value. If the quantity is not positive, it should be set to 0. If the price per item is
//not positive, it should be set to 0. Write a test program that demonstrates class Invoice’s capabilities.

#include <iostream>
#include <string>
#include <stdbool.h>
#include <cstdlib>
#include <vector>
using namespace std;

class Invoice
{
	private:
		string part_number;
		string part_description;
		int quantity;
		int price;
	public:
		Invoice(string xpart_number, string xpart_description, int xquantity, int xprice);
		string getpart_number();
		string getpart_description();
		int getquantity();
		int getprice();
		void setpart_number(string xpart_number);
		void setpart_description(string xpart_description);
		void setquantity(int xquantity);
		void setprice(int xprice);
		int getinvoice_amount(int quantity, int price);
		int control(int a);
};

Invoice::Invoice(string xpart_number, string xpart_description, int xquantity, int xprice)
{
    	part_number=xpart_number;
	part_description=xpart_description;
	quantity=xquantity;
	price=xprice;
}

string Invoice::getpart_number()
{
	return part_number;
}

string Invoice::getpart_description()
{
	return part_description;
}

int Invoice::getquantity()
{
	return control(quantity);
}

int Invoice::getprice()
{
	return control(price);
}

void Invoice::setpart_number(string xpart_number)
{
    part_number=xpart_number;
}

void Invoice::setpart_description(string xpart_description)
{
    part_description=xpart_description;
}

void Invoice::setquantity(int xquantity)
{
    quantity=control(xquantity);
}

void Invoice::setprice(int xprice)
{
    price=control(xprice);
}

int Invoice::getinvoice_amount(int quantity, int price)
{
	return control(price*quantity);
}

int Invoice::control(int a)
{
	if(a<0)
	{
		return 0;
	}else{
		return a;
	}
}

void menu()
{
	system("cls");
	cout<<endl;
	cout<<" New Part ------------------------ 1"<<endl;
	cout<<" Show Parts ---------------------- 2"<<endl;
	cout<<" Edit Part ----------------------- 3"<<endl;
	cout<<" Invoice Amounts ----------------- 4"<<endl;
	cout<<" Close --------------------------- 0"<<endl<<endl;
    	cout<<" CHOICE: ";
}

Invoice newpart();
void print_parts(vector <Invoice> parts);
void print_amounts(vector <Invoice> parts);
vector <Invoice> edit_parts(vector <Invoice> parts);

int main()
{
system("color f1");

	vector <Invoice> parts;
	int choose;
	while(true)
	{
		menu();
		cin>>choose;
		cout<<endl;
		
		if (choose==1)
		{
            parts.push_back(newpart());
            cout<<endl;
		}
		
		if (choose==2)
		{
			print_parts(parts);
		}
		
		if (choose==3)
		{
            		if (parts.size()==0)
			{
				cout<<" NO PARTS REGISTERED YET"<<endl<<endl;
			}else{
				parts=edit_parts(parts);
			}
		}
		
		if (choose==4)
		{
			print_amounts(parts);
		}
		
		if (choose==0)
		{
			break;
		}
		
		if ((choose!=0)&&(choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4))
		{
			cout<<" ERROR: WRONG CHOICE"<<endl;
		}
		
	system("pause");
	}
system("pause");
}

Invoice newpart()
{
    	string part_number;
	string part_description;
	int quantity;
	int price;
	Invoice part(part_number,part_description,quantity,price);

	cout<<" Give part number: ";
	cin>>part_number;
	part.setpart_number(part_number);

	cout<<" Give part description: ";
	cin>>part_description;
	part.setpart_description(part_description);

	cout<<" Give quantity: ";
	cin>>quantity;
	part.setquantity(quantity);

	cout<<" Give price per part: ";
	cin>>price;
	part.setprice(price);

	return part;
}

void print_parts(vector <Invoice> parts)
{
	if (parts.size()>0)
	{
		for(int i=0; i<parts.size(); ++i)
		{
			cout<<" --------- PART "<<(i+1)<<" ---------"<<endl;
			cout<<" PART NUMBER: "<<parts[i].getpart_number()<<endl;
			cout<<" PART DESCRIPTION: "<<parts[i].getpart_description()<<endl;
			cout<<" QUANTITY: "<<parts[i].getquantity()<<endl;
			cout<<" PRICE: "<<parts[i].getprice()<<endl<<endl;
		}
	}else{
		cout<<" NO PARTS REGISTERED YET"<<endl<<endl;
	}
}

void print_amounts(vector <Invoice> parts)
{
	if (parts.size()>0)
	{
		for(int i=0; i<parts.size(); ++i)
		{
			cout<<" --------- PART "<<(i+1)<<" ---------"<<endl;
			cout<<" PART NUMBER: "<<parts[i].getpart_number()<<endl;
			cout<<" PART DESCRIPTION: "<<parts[i].getpart_description()<<endl;
			cout<<" AMOUNT: "<<parts[i].getinvoice_amount(parts[i].getquantity(), parts[i].getprice())<<endl<<endl;
		}
	}else{
		cout<<" NO PARTS REGISTERED YET"<<endl<<endl;
	}
}

vector <Invoice> edit_parts(vector <Invoice> parts)
{
	    	string part_number;
		string part_description;
		int quantity;
		int price;
		int xchoose,i;
		
		print_parts(parts);
		
		cout<<" RESULT(S) FOUND: "<<parts.size()<<endl;
		while(true)
		{
			cout<<" CHOOSE 1-"<<parts.size()<<": ";
			cin>>xchoose;
			if((xchoose>=1)&&(xchoose<=parts.size()))
			{
				i=xchoose-1;
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl;
			}
		}
		cout<<endl;
		
		string change;
		cout<<" PART NUMBER: "<<parts[i].getpart_number()<<endl;
		while(true)
		{
			cout<<" PRESS + TO CHANGE, ELSE - : ";
			cin>>change;
			if(change=="+")
			{
                cout<<" NEW PART NUMBER: ";
				cin>>part_number;
				parts[i].setpart_number(part_number);
				break;
			}else if(change=="-")
			{
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl;
			}
		}
		cout<<endl;
		
		cout<<" PART DESCRIPTION: "<<parts[i].getpart_description()<<endl;
		while(true)
		{
			cout<<" PRESS + TO CHANGE, ELSE - : ";
			cin>>change;
			if(change=="+")
			{
                cout<<" NEW PART DESCRIPTION: ";
                cin>>part_description;
				parts[i].setpart_description(part_description);
				break;
			}else if(change=="-")
			{
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl;
			}
		}
		cout<<endl;
		
		cout<<" QUANTITY: "<<parts[i].getquantity()<<endl;
		while(true)
		{
			cout<<" PRESS + TO CHANGE, ELSE - : ";
			cin>>change;
			if(change=="+")
			{
                cout<<" NEW QUANTITY: ";
                cin>>quantity;
				parts[i].setquantity(quantity);
				break;
			}else if(change=="-")
			{
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl;
			}
		}
		cout<<endl;
		
		cout<<" PRICE: "<<parts[i].getprice()<<endl;
		while(true)
		{
			cout<<" PRESS + TO CHANGE, ELSE - : ";
			cin>>change;
			if(change=="+")
			{
                cout<<" NEW PRICE: ";
                cin>>price;
				parts[i].setprice(price);
				break;
			}else if(change=="-")
			{
				break;
			}else{
				cout<<" @@@ ERROR: WRONG CHOICE @@@"<<endl;
			}
		}
		
		cout<<endl<<" **********************************************"<<endl<<endl;
		print_parts(parts);
		
		return parts;
}
