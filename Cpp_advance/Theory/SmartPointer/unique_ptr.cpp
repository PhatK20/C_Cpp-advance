// C++ program to demonstrate the working of unique_ptr
// Here we are showing the unique_pointer is pointing to P1.
// But, then we remove P1 and assign P2 so the pointer now
// points to P2.

#include <iostream>
using namespace std;
// Dynamic Memory management library
#include <memory>

class Rectangle
{
	int length;
	int breadth;

public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int area() { return length * breadth; }
};

int main()
{
	// --\/ Smart Pointer
	unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl; // This'll print 50

	// unique_ptr<Rectangle> P2(P1);
	unique_ptr<Rectangle> P2;
	// P2 = P1; error
	// Tại một thời điểm, chỉ có một unique_ptr duy nhất được phép truy cập và sở hữu một vùng nhớ cụ thể.
	// Dùng lênh move() để chuyển quyền điều khiển vùng nhớ.
	P2 = move(P1);// không thể truy cập vào P1 được nữa

	// This'll print 50
	cout << P2->area() << endl;

	// cout<<P1->area()<<endl;
	return 0;
}
