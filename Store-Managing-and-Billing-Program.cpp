//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class product
{
	int pno;
	string name;
	float price, qty, tax, dis;
public:
	void create_product()
	{
		cout << "\n\nPlease Enter The Product No. of The Product ";
		cin >> pno;
		cout << "\nPlease Enter The Name of The Product ";
		cin>> name;
		cout << "\nPlease Enter The Price of The Product ";
		cin >> price;
		cout << "\nPlease Enter The Discount (%) ";
		cin >> dis;
	}

	void show_product()
	{
		cout << "\nThe Product No. of The Product : " << pno;
		cout << "\nThe Name of The Product : " << name;
		cout << "\nThe Price of The Product : " << price;
		cout << "\nDiscount : " << dis;
	}

	int  retpno()
	{
		return pno;
	}

	float retprice()
	{
		return price;
	}

	string retname()
	{
		return name;
	}

	int retdis()
	{
		return dis;
	}

};         //class ends here


//************************************************************************
//   global declaration of product pointer and vector of product pointer 
//************************************************************************

product* p;

vector<product*> v;

//***************************************************************
//    	function to add in file
//****************************************************************

void add_product()
{
	p = new product;
	p->create_product();
	v.push_back(p);
}


//***************************************************************
//    	function to read all records from file
//****************************************************************


void display_all()
{
	system("cls");
	for (int i = 0; i < v.size(); i++)
		v[i]->show_product();
	_getch();
}



//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_sp(int n)
{
	int flag = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->retpno() == n)
		{
			system("cls");
			v[i]->show_product();
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "\n\nrecord not exist";
	_getch();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_product()
{
	int no, found = 0;
	system("cls");
	cout << "\n\n\tTo Modify ";
	cout << "\n\n\tPlease Enter The Product No. of The Product ";
	cin >> no;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->retpno() == no)
		{
			v[i]->show_product();
			cout << "\n\nPlease Enter The Details of New Product" ;
			p = new product;
			p->create_product();
			v[i] = p;
			cout << "\n\n\t Record Updated";
			found = 1;
			break;
		}
	}
	if (found == 0)
		cout << "\n\n Record Not Found ";
	_getch();
}


//***************************************************************
//    	function to delete a product
//****************************************************************


void delete_product()
{
	int no,found=0;
	system("cls");
	cout << "\n\n\n\tDelete Record";
	cout << "\n\nPlease Enter The product no. of The Product You Want To Delete ";
	cin >> no;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->retpno() == no)
		{
			v[i]->show_product();
			delete(v[i]);
			//std::vector<product*>::erase(v[i]);
			cout << "\n\n\t Product Deleted";
			found = 1;
		}
	}
	if (found == 0)
		cout << "\n\n Product Not Found ";
	_getch();
}


//***************************************************************
//    	function to display all products price list
//****************************************************************

void menu()
{
	system("cls");;

	cout << "\n\n\t\tProduct MENU\n\n";
	cout << "====================================================\n";
	cout << "P.NO.\t\tNAME\t\tPRICE\n";
	cout << "====================================================\n";

	for (int i = 0; i < v.size(); i++)
		cout << v[i]->retpno() << "\t\t" << v[i]->retname() << "\t\t" << v[i]->retprice() << endl;
}




//***************************************************************
//    	function to place order and generating bill for Products
//****************************************************************

void place_order()
{
	int  order_prno[50], quan[50], c = -1, found=0;
	float amt, damt, total = 0;
	char ch = 'Y';
	menu();
	cout << "\n============================";
	cout << "\n    PLACE YOUR ORDER";
	cout << "\n============================\n";
	do {
		c++;
		cout << "\n\nEnter The Product No. Of The Product : ";
		cin >> order_prno[c];
		cout << "\nQuantity in number : ";
		cin >> quan[c];
		
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i]->retpno() == order_prno[c])
				found = 1;
		}
		if (found == 0)
			cout << "\n\n Record Not Found ";
		cout << "\nDo You Want To Order Another Product ? (y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << "\n\nThank You For Placing The Order"; 
	
	system("cls");
	cout << "\n\n********************************INVOICE************************\n";
	cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
	for (int x = 0; x <= c; x++)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i]->retpno() == order_prno[x])
			{
				amt = v[i]->retprice() * quan[x];
				damt = amt - (amt * v[i]->retdis() / 100);
				cout << "\n" << order_prno[x] << "\t" << v[i]->retname() << "\t" << quan[x] << "\t\t" << v[i]->retprice() << "\t" << amt << "\t\t" << damt;
				total += damt;
			}
		}
	}
	cout << "\n\n\t\t\t\t\tTOTAL = " << total;
	_getch();
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	system("cls");
	cout << "\n\n\t\t\tSTORE MANAGING AND BILLING PROGRAM";
	
	cout << "\n\n\tMADE BY  : SHREYANSH AGARWAL";
	cout << "\n\n\tROLL NO. : MS20BTECH11021";

	_getch();
}




//***************************************************************
//    	ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
	system("cls");
	char ch2;
	cout << "\n\n\n\tADMIN MENU";
	cout << "\n\n\t1.CREATE PRODUCT";
	cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
	cout << "\n\n\t3.QUERY ";
	cout << "\n\n\t4.MODIFY PRODUCT";
	cout << "\n\n\t5.DELETE PRODUCT";
	cout << "\n\n\t6.VIEW PRODUCT MENU";
	cout << "\n\n\t7.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-7) ";
	ch2 = _getche();
	switch (ch2)
	{
	case '1': system("cls");
		add_product();
		break;
	case '2': system("cls");
		display_all(); 
		break;
	case '3':
		int num;
		system("cls");
		cout << "\n\n\tPlease Enter The Product No. ";
		cin >> num;
		display_sp(num);
		break;
	case '4': modify_product(); 
		break;
	case '5': delete_product(); 
		break;
	case '6': menu();
		_getch();
	case '7': break;
	default:cout << "\a"; admin_menu();
	}
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{

	char ch;
	intro();
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. CUSTOMER";
		cout << "\n\n\t02. ADMINISTRATOR";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		ch = _getche();
		switch (ch)
		{
		case '1': system("cls");
			place_order();
			break;
		case '2': system("cls"); 
			admin_menu();
			break;
		case '3':exit(0);
		default:cout << "\a";
		}
	} while (ch != '3');

	return 0;
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
