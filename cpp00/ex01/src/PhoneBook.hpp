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
    void            print_error();
    std::string     trim_string(std::string str);
};