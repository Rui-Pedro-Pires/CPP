#include <iostream>

class Contact
{
private:
	int     phone_number;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	darkest_secret;

public:
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nick_name();
	std::string	get_darkest_secret();
	int     	get_phone_number();
	void    	set_first_name(std::string name_to_add);
	void    	set_last_name(std::string name_to_add);
	void    	set_nick_name(std::string name_to_add);
	void    	set_phone_number(int number_to_add);
	void    	set_darkest_secret(std::string secret_to_add);
};