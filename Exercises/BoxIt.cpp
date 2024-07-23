#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
    private:
        int l, b, h = 0;
        
    public:
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }
        Box(int l, int b, int h) {
            this->l = l;
            this->b = b;
            this->h = h;
        }
        Box(Box& B) {
            l = B.getLength();
            b = B.getBreadth();
            h = B.getHeight();
        }
        
        int getLength() {
            return l;
        }
        int getBreadth(){
            return b;
        }
        int getHeight() {
            return h;
        }
        long long CalculateVolume() {
            long long vol = 1;
            vol *= l;
            vol *= b;
            vol *= h;
            
            return vol;
        }
        
        bool operator<(Box& box) {
            return l < box.getLength() || (b < box.getBreadth() && l == box.getBreadth()) || (h < box.getHeight() && b == box.getBreadth() && l == box.getBreadth());
        }
        
        
};
ostream& operator<<(ostream& out, Box& B) {
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
            
    return out;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
