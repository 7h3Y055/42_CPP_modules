
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class contact{
    private:
        std::string Fname;
        std::string Lname;
        std::string Nname;
        std::string Dsecret;
        std::string Pnumber;
    public:
        contact();
        ~contact();
        std::string get_fname();
        void set_fname(std::string);
        std::string get_lname();
        void set_lname(std::string);
        std::string get_nname();
        void set_nname(std::string);
        std::string get_dsecret();
        void set_dsecret(std::string);
        std::string get_pnumber();
        void set_pnumber(std::string);

};



#endif