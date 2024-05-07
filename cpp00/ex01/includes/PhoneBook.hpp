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
    void            render_add_menu(std::string str);
    void            render_main_menu(void);
    void            render_search_menu(void);
    void            add_contact(void);
    void            search_contacts(void);
    std::string     trim_string(std::string str);
};

#endif