#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact         _contacts_list[8];
    int             _i;
    int             _total_contacts;

public:
    PhoneBook();
    ~PhoneBook();
    void            add_contact();
    void            search_contacts();
    std::string     trim_string(std::string str);
};

#endif