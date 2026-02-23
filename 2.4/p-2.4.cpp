#include <iostream>
#include <string>
using namespace std;
class item
{
private:
    int itemID;
    string itemname;
    float price;
    int quantity;

public:
    item()
    {
        itemID=0;
        itemname= "";
        price=0;
        quantity=0;
    }


    item(int id, string name, float p, int q)
    {
        itemID=id;
        itemname=name;
        price=p;
        quantity=q;
    }


    void addStock(int q)
    {
        quantity=quantity+q;
        cout<<"Stock updated\n";
    }
    void sellItem(int q)
    {
        if(q<=quantity)
        {
            quantity=quantity-q;
            cout<<"Item sold\n";
        }
        else
        {
            cout<<"Not enough stock available\n";
        }
    }
    void display()
    {
        cout<<"Item Details:\n";
        cout<<"Item ID: " << itemID<<endl;
        cout<<"Item Name: " << itemname<<endl;
        cout<<"Price: " << price<<endl;
        cout<<"Quantity in Stock: "<<quantity<<endl;
    }
};

int main()
{
    int id, qty, choice;
    string name;
    float price;

    cout<<"Enter Item ID: ";
    cin>>id;
    cout<<"Enter Item Name: ";
    cin>>name;
    cout<<"Enter Price: ";
    cin>>price;
    cout<<"Enter Initial Quantity: ";
    cin>>qty;
    item item1(id, name, price, qty);
    do
    {

        cout<<"1)Add Stock\n";
        cout<<"2)Sell Item\n";
        cout<<"3)Display Item\n";
        cout<<"4) Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter quantity to add: ";
            cin>>qty;
            item1.addStock(qty);
            break;
        case 2:
            cout<<"Enter quantity to sell: ";
            cin>>qty;
            item1.sellItem(qty);
            break;
        case 3:
            item1.display();
            break;
        case 4:
            cout<<"Exiting program";
            break;
        default:
            cout<<"Invalid choice";
        }
    }
    while(choice!=4);
    return 0;
}
