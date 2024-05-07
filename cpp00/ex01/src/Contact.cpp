#include "../includes/Contact.hpp"

std::string Contact::get_first_name()
{
    return (first_name);
}

std::string Contact::get_last_name()
{
    return (last_name);
}

std::string Contact::get_nick_name()
{
    return (nick_name);
}

std::string Contact::get_darkest_secret()
{
    return (darkest_secret);
}

int Contact::get_phone_number()
{
    return (phone_number);
}

void Contact::set_first_name(std::string name_to_add)
{
    first_name = name_to_add;
}

void Contact::set_last_name(std::string name_to_add)
{
    last_name = name_to_add;
}

void Contact::set_nick_name(std::string name_to_add)
{
    nick_name = name_to_add;
}

void Contact::set_darkest_secret(std::string secret_to_add)
{
    darkest_secret = secret_to_add;
}

void Contact::set_phone_number(int number_to_add)
{
    phone_number = number_to_add;
}
