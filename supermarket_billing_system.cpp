//SuperMarket Billing system
#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstring>
#include <fstream>
using namespace std;
class product 
    {
        int product_number;
        char name[256];
        float price,qty, tax;
        public:
            void create_product() 
            {
                cout <<endl<<"Enter Product Number :: ";
                cin >> product_number;
                cout <<endl<<"Enter The Name of The Product ::";
                cin.ignore();
                cin.getline(name,256);
                cout << "\nEnter The Price of The Product ::"<<endl;
                cin >> price;
            }

        void show_product() 
        {
            cout << "\nProduct Number :: " << product_number;
            cout << "\nName of Product :: ";
            puts(name);
            cout << "\nPrice of Product :: " << price;
        }

        int return_productno() 
        {
            return product_number;
        }
        char * return_name() 
        {
            return name;
        }
        float return_price() 
        {
            return price;
        }

    };
fstream fp;
product pr;
void write_product() 
{
    fp.open("Shopinventory.dat", ios::out | ios::app);
    pr.create_product();
    fp.write((char * ) & pr, sizeof(product));
    fp.close();
    cout << "\n\nProduct Has Been Created and Saved";
    getch();
}
void display_details() 
{
    cout << "******Displaying All Records******";
    fp.open("Shopinventory.dat", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product))) 
    {
        pr.show_product();
        cout <<endl<<"***********************************"<<endl;
    }
    fp.close();
    getch();
}
void display_sp(int n) 
{
    int flag = 0;
    fp.open("Shopinventory.dat", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product))) 
    {
        if (pr.return_productno() == n) 
        {
            pr.show_product();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nrecord not exist";
    getch();
}

void modify_product() 
{
    int no, found = 0;
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tPlease Enter The Product No. of The Product";
    cin >> no;
    fp.open("Shopinventory.dat", ios:: in | ios::out);
    while (fp.read((char * ) & pr, sizeof(product)) && found == 0) 
    {
        if (pr.return_productno() == no) 
        {
            pr.show_product();
            cout << "\nPlease Enter The New Details of Product" << endl;
            pr.create_product();
            int pos = -1 * sizeof(pr);
            fp.seekp(pos, ios::cur);
            fp.write((char * ) & pr, sizeof(product));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}
void delete_product() 
{
    int no;
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin >> no;
    fp.open("Shopinventory.dat", ios:: in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char * ) & pr, sizeof(product))) 
    {
        if (pr.return_productno() != no) 
        {
            fp2.write((char * ) & pr, sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shopinventory.dat");
    rename("Temp.dat", "Shop.dat");
    cout << "\n\n\tRecord Deleted ..";
    getch();
}
void menu() 
{
    fp.open("Shopinventory.dat", ios:: in );
    if (!fp) 
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
        cout << "\n\n\n Program is closing ....";
        getch();
        exit(0);
    }

    cout << "\n\n\t\tProduct MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fp.read((char * ) & pr, sizeof(product))) 
    {
        cout << pr.return_productno() << "\t\t" << pr.return_name() << "\t\t" << pr.return_price() << endl;
    }
    fp.close();
}
void place_order() 
{
    int order_arr[50], quan[50], c = 0;
    float amt,total = 0;
    char ch = 'Y';
    menu();
    cout << "\n============================";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n============================\n";
    do 
    {
        cout << "\n\nEnter The Product No. Of The Product : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();
    cout << "\n\n******************************** INVOICE ************************\n";
    cout<<endl<<"S.no  |        Product name         | Quantity | Amount ";
    cout<<endl<<"--------------------------------------------------------";
    for (int x = 0; x <= c; x++) 
    {
        fp.open("Shopinventory.dat", ios:: in );
        fp.read((char * ) & pr, sizeof(product));
        while (!fp.eof()) 
        {
            if (pr.return_productno() == order_arr[x]) 
            {
                amt = pr.return_price() * quan[x];
                cout<<endl<<x+1;
                for(int i=0;i<6-(to_string(x).length());i++)
                {
                    cout<<" ";
                }
                cout<<"|";
                string name;
                name=pr.return_name();
                cout<<pr.return_name();
                for(int i=0;i<29-(name.length());i++)
                {
                    cout<<" ";
                }
                cout<<"|";
                cout<<quan[x];
                for(int i=0;i<10-(to_string(quan[x]).length());i++)
                {
                    cout<<" ";
                }
                cout<<"|";
                cout<<amt;
                
/*                amt = pr.return_price() * quan[x];
                damt = amt - (amt * pr.return_discount() / 100);
                cout << "\n" << order_arr[x] << "\t" << pr.return_name() <<
                    "\t" << quan[x] << "\t\t" << pr.return_price() << "\t" << amt << "\t\t" << damt;*/
                total += amt;
            }
            fp.read((char * ) & pr, sizeof(product));
        }

        fp.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
}
void admin_menu() 
{
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
    ch2 = getche();
    switch (ch2) 
    {
    case '1':
        write_product();
        break;
    case '2':
        display_details();
        break;
    case '3':
        int num;
        cout << "\n\n\tPlease Enter The Product No. ";
        cin >> num;
        display_sp(num);
        break;
    case '4':
        modify_product();
        break;
    case '5':
        delete_product();
        break;
    case '6':
        menu();
        getch();
    case '7':
        break;
    default:
        cout << "\a";
        admin_menu();
    }
}
int main() 
{
    char ch;
    do 
    {
        cout <<endl<<endl<<"\tMAIN MENU";
        cout <<endl<<endl<<"\t01. CUSTOMER";
        cout <<endl<<endl<<"\t02. ADMINISTRATOR";
        cout <<endl<<endl<<"\t03. EXIT";
        cout <<endl<<endl<<"\tPlease Select Your Option (1-3) ";
        ch = getche();
        switch (ch) 
        {
        case '1':
            place_order();
            getch();
            break;
        case '2':
            admin_menu();
            break;
        case '3':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '3');
}




