#include<iostream>
using namespace std;
class Rectangle
{
private:
    float length;
    float width;

public:
    void setdimensions()
    {
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
    }
    void updatedimensions()
    {
        cout << "Enter new length: ";
        cin >> length;
        cout << "Enter new width: ";
        cin >> width;
    }
    float area()
    {
        return length * width;
    }
    float perimeter()
    {
        return 2 *(length+width);
    }
    void display()
    {
        cout <<"Length: "<<length<<endl;
        cout <<"Width : "<<width<<endl;
        cout <<"Area  : "<<area()<<endl;
        cout <<"Perimeter: "<< perimeter()<<endl;
    }
};

int main()
{
    Rectangle r[10];
    int count = 0;
    int choice;

    while(true)
    {
        cout<<"\n1. Add Rectangle";
        cout<<"\n2. Update Rectangle";
        cout<<"\n3. Display All Rectangles";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if(count<10)
            {
                r[count].setdimensions();
                count++;
            }
            else
            {
              cout<<"Maximum limit reached"<<endl;
            }
            break;

        case 2:
            int index;
            cout<<"Enter rectangle number to update (1 to "<< count<< "): ";
            cin>>index;
            if(index>=1&&index<=count)
            {
                r[index - 1].updatedimensions();
            }
            else
            {
                cout<<"Invalid rectangle number"<<endl;
            }
            break;

        case 3:
            for(int i=0;i<count; i++)
            {
                cout<<"\nRectangle"<<i+1<<endl;
                r[i].display();
            }
            break;

        case 4:
            return 0;

        default:
            cout<<"Invalid choice"<<endl;
        }
    }
}
