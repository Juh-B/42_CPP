#include <iostream>
#include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		int count;
		int nextIndex;

	public:
		PhoneBook();

		void addContact();
		void searchContact() const;
		void displayContact(int index) const;
}
