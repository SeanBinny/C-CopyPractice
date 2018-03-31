// Define class Gradebook with a member function disaplayMessage 
// create a GradeBook object, and call its displayMessage function
#include <iostream>
using namespace std;

// GradeBook calss defination
class GradeBook
{
public:
	// function that displays a welcome message to the GradeBook user
	void disaplayMessage() const
	{
		cout << "Welcome to the Grade Book!" << endl;
	} // end function disaplayMessage
}; // end class GradeBook

// function main begins program exection
int main()
{
	Gradebook myGradeBook; // create a GradeBook object named myGradeBook
	myGradeBook.disaplayMessage(); // call object's disaplayMessage funtion
} // end main