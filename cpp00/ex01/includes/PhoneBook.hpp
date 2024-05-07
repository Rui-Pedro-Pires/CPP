#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact         contacts_list[8];

public:
    int             i;
    int             total_contacts;
    void            add_contact();
    void            search_contacts();
    std::string     trim_string(std::string str);
};

#endif