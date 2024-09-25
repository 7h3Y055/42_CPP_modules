#include "contact.hpp"

contact::contact()
{
}

contact::~contact()
{
}


std::string contact::get_fname(){
    return Fname;
}

void contact::set_fname(std::string first_name){
    Fname = first_name;
}

std::string contact::get_lname(){
    return Lname;
}

void contact::set_lname(std::string last_name){
    Lname = last_name;
}

std::string contact::get_nname(){
    return Nname;
}

void contact::set_nname(std::string nickname){
    Nname = nickname;
}

std::string contact::get_dsecret(){
    return Dsecret;
}

void contact::set_dsecret(std::string secret){
    Dsecret = secret;
}

std::string contact::get_pnumber(){
    return Pnumber;
}

void contact::set_pnumber(std::string phone_number){
    Pnumber = phone_number;
}