#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Menus
{
public:
    int inpt, add_book_qnt, filterTarget;
    int confirm_fail = 0;
    float add_book_price, add_purchase_total;
    string add_book_id, add_book_name, add_book_category, add_book_author, confirm, add_purchase_id, add_purchase_customer, text, text2, categorySearch, authorSearch, searchInput, oldData, newData, deleteData;

    string err = "MESSAGE: Please Select From The Options Listed!!\n\n";
    string selection = "Your Selection: ";

    void closeApp()
    {
        cout << "Exiting...\n";
        Sleep(1000);
        exit;
    }
    int inputcheck()
    {
        while (cin.fail())
        {
            cout << err;
            cin.clear();
            cin.ignore(256, '\n');
            cout << selection;
            cin >> inpt;
        }
        return inpt;
    }
    float floatCheck(float add_book_price)
    {
        do
        {
            if (cin.fail() || add_book_price < 1)
            {
                confirm_fail = 1;
                cin.clear();
                cin.ignore(80, '\n');
                cout << "\nInvalid Input\nEnter Book Price: ";
                cin >> add_book_price;
            }
            else
            {
                confirm_fail = 0;
                break;
            }
        } while (confirm_fail == 1);
        return add_book_price;
    }
    int integerCheck(int add_book_qnt)
    {
        do
        {
            if (cin.fail() || add_book_qnt < 1)
            {
                confirm_fail = 1;
                cin.clear();
                cin.ignore(80, '\n');
                cout << "\nInvalid Input\nEnter Book Quantity: ";
                cin >> add_book_qnt;
            }
            else
            {
                confirm_fail = 0;
                break;
            }
        } while (confirm_fail == 1);
        return add_book_qnt;
    }
    // main menu start
    int mainMenu()
    {
        cout << " Main Menu\n===========\n";
        cout << "[1] Inventory\n[2] Transaction\n[11] Exit\n";
        cout << selection;
        cin >> inpt;
        cout << endl;
        inputcheck();
        system("cls"); // clears all the previous menus

        switch (inpt)
        {
        case 1:
            cout << "Message: Going To Inventory\n\n";
            inventory();
            break;

        case 2:
            cout << "Message: Going To Transactions\n\n"
                 << endl;
            transaction();
            break;

        case 11:
            closeApp();
            break;

        default:
            cout << err;
            mainMenu();
            break;
        }
        return 0;
    }
    // main menu end

    // inventory start
    int inventory()
    {
        cout << " Inventory\n===========\n";
        cout << "[1] View Books\n[2] Add New Book\n[3] Update Book Info\n[4] Delete Book\n[0] Back\n[11] Exit\n";
        cout << selection;
        cin >> inpt;
        cout << endl;
        inputcheck();
        system("cls"); // clears all the previous menus

        switch (inpt)
        {
        case 1:
            viewBooks();
            break;

        case 2:
            addBook();
            break;

        case 3:
            cout << "MESSAGE: Select Book ID From Lhe List To Update\n\n";
            updateBook();
            break;

        case 4:
            cout << "MESSAGE: Select Book ID From Lhe List To Delete\n\n";
            deleteBook();
            break;

        case 0:
            cout << "MESSAGE: Going To Main Menu\n\n";
            mainMenu();
            break;

        case 11:
            closeApp();
            break;

        default:
            cout << err;
            inventory();
            break;
        }
        return 0;
    }
    // inventory end

    // transaction start
    int transaction()
    {
        cout << " Transaction\n=============\n";
        cout << "[1] View\n[2] Add Transaction\n[3] Purchase Details\n[0] Back\n[11] Exit\n";
        cout << selection;
        cin >> inpt;
        cout << endl;
        inputcheck();
        system("cls"); // clears all the previous menus

        switch (inpt)
        {
        case 1:
            viewPurchase();
            break;

        case 2:
            addPurchase();
            break;

        case 3:
            cout << "MESSAGE: Type Purchase ID To See Full Details\n\n";
            text = "Purchase ID\n";
            text2 = "\n Purchase ID Search Results\n============================\n";
            purchaseDetails();
            break;

        case 0:
            cout << "MESSAGE: Going To Main Menu\n\n";
            mainMenu();
            break;

        case 11:
            closeApp();
            break;

        default:
            cout << err;
            transaction();
            break;
        }
        return 0;
    }
    // transaction end

    // Add Book end
    int addBook()
    {
        cout << "\n\n Add Book\n==========\n";
        cout << "Enter Book ID: ";
        getline(cin >> ws, add_book_id);

        cout << "Enter Book Name: ";
        getline(cin >> ws, add_book_name);

        cout << "Enter Book Category: ";
        getline(cin >> ws, add_book_category);

        cout << "Enter Author's Name: ";
        getline(cin >> ws, add_book_author);

        cout << "Enter Book Price: ";
        cin >> add_book_price;
        floatCheck(add_book_price);

        cout << "Enter Book Quantity: ";
        cin >> add_book_qnt;
        integerCheck(add_book_qnt);
        do
        {
            cout << "\nConfirm (y/n): ";
            cin >> confirm;
            if (confirm == "y")
            {
                ofstream myfile;
                myfile.open("Data_Books.txt", ios::app);
                myfile << add_book_id << "," << add_book_name << "," << add_book_category << "," << add_book_author << "," << add_book_price << "," << add_book_qnt << endl;
                myfile.close();
                system("cls");
                cout << "MESSAGE: Book Added Successfully\n\n";
                inventory();
                break;
            }
            else if (confirm == "n")
            {
                system("cls");
                cout << "MESSAGE: Cancelled Adding Book\n\n";
                inventory();
                break;
            }
            else
            {
                cout << "\nPlease Type 'y' or 'n'\n";
            }
        } while (confirm != "y" || confirm != "n");
        return 0;
    }
    // Add Book end

    int table()
    {
        string fileText;
        ifstream myFile("Data_Books.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            cout << "\nID: " << v[0] << " | ";
            cout << "Title: " << v[1] << " | ";
            cout << "Category: " << v[2] << " | ";
            cout << "Author: " << v[3] << " | ";
            cout << "Price: RM" << v[4] << " | ";
            cout << "Quantity: " << v[5] << "";
        }
        cout << "\n\n";
        myFile.close();
        return 0;
    }

    int tableByID(string add_book_id)
    {
        string fileText;
        ifstream myFile("Data_Books.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            if (v[0] == add_book_id)
            {
                cout << "\nID: " << v[0] << " | ";
                cout << "Title: " << v[1] << " | ";
                cout << "Category: " << v[2] << " | ";
                cout << "Author: " << v[3] << " | ";
                cout << "Price: RM" << v[4] << " | ";
                cout << "Quantity: " << v[5] << "";
            }
        }
        cout << "\n";
        myFile.close();
        return 0;
    }

    int updateBookExecution(string text, int filterTarget)
    {
        cout << text;
        cout << "Current Info: ";
        getline(cin >> ws, oldData);
        cout << "New Info: ";
        getline(cin >> ws, newData);

        string fileText;
        fstream myFile("Data_Books.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            if (v[filterTarget] == oldData)
            {
                ofstream myTempFile;
                myTempFile.open("Data_Books_Temp.txt", ios::app);
                if (filterTarget == 0)
                {
                    myTempFile << newData << "," << v[1] << "," << v[2] << "," << v[3] << "," << v[4] << "," << v[5] << endl;
                }
                else if (filterTarget == 1)
                {
                    myTempFile << v[0] << "," << newData << "," << v[2] << "," << v[3] << "," << v[4] << "," << v[5] << endl;
                }
                else if (filterTarget == 2)
                {
                    myTempFile << v[0] << "," << v[1] << "," << newData << "," << v[3] << "," << v[4] << "," << v[5] << endl;
                }
                else if (filterTarget == 3)
                {
                    myTempFile << v[0] << "," << v[1] << "," << v[2] << "," << newData << "," << v[4] << "," << v[5] << endl;
                }
                else if (filterTarget == 4)
                {
                    myTempFile << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "," << newData << "," << v[5] << endl;
                }
                else if (filterTarget == 5)
                {
                    myTempFile << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "," << v[4] << "," << newData << endl;
                }
                myTempFile.close();
            }
            else
            {
                ofstream myTempFile;
                myTempFile.open("Data_Books_Temp.txt", ios::app);
                myTempFile << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "," << v[4] << "," << v[5] << endl;
                myTempFile.close(); // rename this to the actual file name
            }
        }
        cout << "\n";
        myFile.close(); //and delete this file
        remove("Data_Books.txt");
        rename("Data_Books_Temp.txt", "Data_Books.txt");

        system("cls");
        cout << "MESSAGE: Book Information Updated Successfully\n\n";
        inventory();
        return 0;
    }
    int updateBook()
    {
        cout << " Book List\n===========";
        table();
        cout << "Book ID: ";
        cin >> add_book_id;
        system("cls");
        cout << "\n\n Selected Book\n===============";
        tableByID(add_book_id);
        cout << "\n Update Book Info\n==================\n";
        cout << "[1] ID\n[2] Title\n[3] Category\n[4] Author\n[5] Price\n[6] Stock\n[0] Back\n[11] Exit\n";
        cout << selection;
        cin >> inpt;
        cout << endl;
        inputcheck();

        switch (inpt)
        {
        case 1:
            text = "Confirm And Update Book ID\n";
            filterTarget = 0;
            updateBookExecution(text, filterTarget);
            break;

        case 2:
            text = "Confirm And Update Book Title\n";
            filterTarget = 1;
            updateBookExecution(text, filterTarget);
            break;

        case 3:
            text = "Confirm And Update Category\n";
            filterTarget = 2;
            updateBookExecution(text, filterTarget);
            break;

        case 4:
            text = "Confirm And Update Author Name\n";
            filterTarget = 3;
            updateBookExecution(text, filterTarget);
            break;

        case 5:
            text = "Confirm And Update Price\n";
            filterTarget = 4;
            updateBookExecution(text, filterTarget);
            break;

        case 6:
            text = "Confirm And Update Stock\n";
            filterTarget = 5;
            updateBookExecution(text, filterTarget);
            break;

        case 0:
            system("cls");
            cout << "MESSAGE: Going To Inventory\n\n";
            inventory();
            break;

        case 11:
            closeApp();
            break;

        default:
            system("cls");
            cout << err;
            updateBook();
            break;
        }
        return 0;
    }

    int deleteBookExecution()
    {
        string line;
        cout << text;
        cout << "Enter Book ID: ";
        getline(cin >> ws, deleteData);
        ifstream myfile;
        myfile.open("Data_Books.txt");
        ofstream temp;
        temp.open("Data_Books_Temp.txt");
        while (getline(myfile, line))
        {
            if (line.substr(0, deleteData.size()) != deleteData)
                temp << line << endl;
        }
        myfile.close();
        temp.close();
        remove("Data_Books.txt");
        rename("Data_Books_Temp.txt", "Data_Books.txt");
        system("cls");
        cout << "MESSAGE: Book Item (ID: " << deleteData << ") Deteted Successfully\n\n";
        inventory();
        return 0;
    }

    int deleteBook()
    {
        cout << " Book List\n===========";
        table();
        cout << "Book ID: ";
        cin >> add_book_id;
        system("cls");
        cout << "\n\n Selected Book\n===============";
        tableByID(add_book_id);
        cout << "\n Delete Book Info\n==================\n";
        cout << "[1] Delete Book\n[2] Select Different Book\n[0] Back\n[11] Exit\n";
        cout << selection;
        cin >> inpt;
        cout << endl;
        inputcheck();

        switch (inpt)
        {
        case 1:
            text = "Confirm Book ID To Delete\n";
            filterTarget = 0;
            deleteBookExecution();
            break;

        case 2:
            system("cls");
            cout << "MESSAGE: Select Book ID To Delete\n\n";
            deleteBook();
            break;

        case 0:
            system("cls");
            cout << "MESSAGE: Going To Inventory\n\n";
            inventory();
            break;

        case 11:
            closeApp();
            break;

        default:
            system("cls");
            cout << err;
            deleteBook();
            break;
        }
        // bookSearch();
        return 0;
    }

    // Show Books start
    int viewBooks()
    {
        system("cls");
        cout << "\n\n Viewing Books\n===============\n";
        string fileText;
        ifstream myFile("Data_Books.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            cout << "ID: " << v[0] << " | ";
            cout << "Title: " << v[1] << " | ";
            cout << "Category: " << v[2] << " | ";
            cout << "Author: " << v[3] << " | ";
            cout << "Price: " << v[4] << " | ";
            cout << "Quantity: " << v[5] << "\n";
        }
        myFile.close();
        bookSearch();

        return 0;
    }
    // Show Books end

    // book search start
    int bookSearch()
    {
        cout << "\n Search By\n===========\n";
        cout << "[1] Category\n[2] Author\n[0] Back\n[11] Exit\n";
        cout << selection;
        cin >> inpt;
        cout << endl;
        inputcheck();
        system("cls"); // clears all the previous menus
        switch (inpt)
        {
        case 1:
            cout << "MESSAGE: Type Category Name To Search\n\n";
            text = "Category\n";
            text2 = "\n Category Search Results\n=========================\n";
            filterTarget = 2;
            bookFilter();
            break;

        case 2:
            cout << "MESSAGE: Type Author Name To Search\n\n";
            text = "Author\n";
            text2 = "\n Author Search Results\n=======================\n";
            filterTarget = 3;
            bookFilter();
            break;

        case 0:
            cout << "MESSAGE: Going To Inventory\n\n";
            inventory();
            break;

        case 11:
            closeApp();
            break;

        default:
            cout << err;
            bookSearch();
            break;
        }
        return 0;
    }
    int bookFilter()
    {
        cout << text;
        cout << selection;
        getline(cin >> ws, searchInput);
        cout << text2;

        string fileText;
        ifstream myFile("Data_Books.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }

            if (v[filterTarget] == searchInput)
            {
                cout << "\nID: " << v[0] << " | ";
                cout << "Title: " << v[1] << " | ";
                cout << "Category: " << v[2] << " | ";
                cout << "Author: " << v[3] << " | ";
                cout << "Price: RM" << v[4] << " | ";
                cout << "Quantity: " << v[5] << "\n";
            }
        }
        cout << "\n\n";
        myFile.close();
        bookSearch();
        return 0;
    }
    // book search end

    // Add purchases start
    int addPurchase()
    {
        cout << "\n\n Books Available In Stock\n==========================\n";
        string fileText;
        ifstream myFile("Data_Books.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            cout << "ID: " << v[0] << " | ";
            cout << "Title: " << v[1] << " | ";
            cout << "Category: " << v[2] << " | ";
            cout << "Author: " << v[3] << " | ";
            cout << "Price: " << v[4] << " | ";
            cout << "In Stock: " << v[5] << "\n";
        }
        myFile.close();
        cout << "\n\n Add Purchase\n=============\n";
        cout << "Purchase ID: ";
        getline(cin >> ws, add_purchase_id);

        cout << "Customer Name: ";
        getline(cin >> ws, add_purchase_customer);

        cout << "Book ID: ";
        getline(cin >> ws, add_book_id);

        cout << "Book Name: ";
        getline(cin >> ws, add_book_name);

        cout << "Book Category: ";
        getline(cin >> ws, add_book_category);

        cout << "Book Author: ";
        getline(cin >> ws, add_book_author);

        cout << "Book Price: ";
        cin >> add_book_price;
        floatCheck(add_book_price);

        cout << "Book Quantity: ";
        cin >> add_book_qnt;
        integerCheck(add_book_qnt);
        do
        {
            cout << "\nConfirm (y/n): ";
            cin >> confirm;
            if (confirm == "y")
            {
                add_purchase_total = add_book_qnt * add_book_price;
                ofstream myfile;
                myfile.open("Data_Purchases.txt", ios::app);
                myfile << add_book_id << "," << add_purchase_customer << "," << add_book_id << "," << add_book_name << "," << add_book_category << "," << add_book_author << "," << add_book_price << "," << add_book_qnt << "," << add_purchase_total << endl;
                myfile.close();
                system("cls");
                cout << "MESSAGE: Purchase Added Successfully\n\n";
                transaction();
                break;
            }
            else if (confirm == "n")
            {
                system("cls");
                cout << "MESSAGE: Cancelled Adding Purchase\n\n";
                transaction();
                break;
            }
            else
            {
                cout << "\nPlease Type 'y' or 'n'\n";
            }
        } while (confirm != "y" || confirm != "n");
        return 0;
    }
    // Add purchases end

    // Show Books start
    int viewPurchase()
    {
        system("cls");
        cout << "\n\n Viewing Purchases\n===================\n";
        string fileText;
        ifstream myFile("Data_Purchases.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            cout << "Purchase ID: " << v[0] << " | ";
            cout << "Title: " << v[3] << " | ";
            cout << "Author: " << v[5] << " | ";
            cout << "Category: " << v[4] << " | ";
            cout << "Quantity: " << v[7] << " | ";
            cout << "Total: RM" << v[8] << "\n";
        }
        myFile.close();
        purchaseSearch();
        return 0;
    }
    // Show Books end

    // purchase search start
    int purchaseSearch()
    {
        cout << "\n Search By\n===========\n";
        cout << "[1] Purchase ID\n[2] Title\n[3] Author\n[4] Category\n[0] Back\n[11] Exit\n";
        cout << selection;
        cin >> inpt;
        cout << endl;
        inputcheck();
        system("cls"); // clears all the previous menus
        switch (inpt)
        {
        case 1:
            cout << "MESSAGE: Type Purchase ID To Search\n\n";
            text = "Purchase ID\n";
            text2 = "\n Purchase ID Search Results\n============================\n";
            filterTarget = 0;
            purchaseFilter();
            break;

        case 2:
            cout << "MESSAGE: Type Title To Search\n\n";
            text = "Title\n";
            text2 = "\n Title Search Results\n======================\n";
            filterTarget = 3;
            purchaseFilter();
            break;

        case 3:
            cout << "MESSAGE: Type Author To Search\n\n";
            text = "Author\n";
            text2 = "\n Author Search Results\n=======================\n";
            filterTarget = 5;
            purchaseFilter();
            break;

        case 4:
            cout << "MESSAGE: Type Category To Search\n\n";
            text = "Category\n";
            text2 = "\n Category Search Results\n=========================\n";
            filterTarget = 4;
            purchaseFilter();
            break;

        case 0:
            cout << "MESSAGE: Going To Transaction\n\n";
            transaction();
            break;

        case 11:
            closeApp();
            break;

        default:
            cout << err;
            purchaseSearch();
            break;
        }
        return 0;
    }
    int purchaseFilter()
    {
        cout << text;
        cout << selection;
        getline(cin >> ws, searchInput);
        cout << text2;

        string fileText;
        ifstream myFile("Data_Purchases.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }

            if (v[filterTarget] == searchInput)
            {
                cout << "Purchase ID: " << v[0] << " | ";
                cout << "Title: " << v[3] << " | ";
                cout << "Author: " << v[5] << " | ";
                cout << "Category: " << v[4] << " | ";
                cout << "Quantity: " << v[7] << " | ";
                cout << "Total: RM" << v[8] << "\n";
            }
        }
        cout << "\n\n";
        myFile.close();
        purchaseSearch();
        return 0;
    }
    // purchase search end
    int purchaseDetails()
    {
        cout << text;
        cout << selection;
        getline(cin >> ws, searchInput);
        cout << text2;

        string fileText;
        ifstream myFile("Data_Purchases.txt");
        while (getline(myFile, fileText))
        {
            vector<string> v;
            stringstream ss(fileText);
            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }

            if (v[0] == searchInput)
            {
                cout << "Purchase ID: " << v[0] << " | ";
                cout << "Customer: " << v[1] << " | ";
                cout << "Book ID: " << v[2] << " | ";
                cout << "Title: " << v[3] << " | ";
                cout << "Category: " << v[4] << " | ";
                cout << "Author: " << v[5] << " | ";
                cout << "Price: RM" << v[6] << " | ";
                cout << "Quantity: " << v[7] << " | ";
                cout << "Total: RM" << v[8] << "\n";
            }
        }
        cout << "\n\n";
        myFile.close();
        transaction();
        return 0;
    }
};
