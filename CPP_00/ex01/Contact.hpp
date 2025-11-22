#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		void setContact(void);

		void setFirstName(void);
		void setLastName(void);
		void setNickName(void);
		void setPhoneNumber(void);
		void setDarkestSecret(void);

		void getFullInfo(void);

		const std::string& getFirstName(void);
		const std::string& getLastName(void);
		const std::string& getNickName(void);
		const std::string& getPhoneNumber(void);
		const std::string& getDarkestSecret(void);

	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string		_darkestSecret;
};

#endif
