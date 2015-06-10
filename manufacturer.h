#ifndef _MANUFACTURER_H_
#define _MANUFACTURER_H_
#include <string>

class Manufacturer
{
  protected:
    std::string _name;
    std::string _model;
    std::string _class;
  public:
    Manufacturer() : _name(""), _model(""), _class("") {}
    Manufacturer(const std::string &, const std::string &, const std::string &);
    Manufacturer(const Manufacturer &);
    Manufacturer(Manufacturer &&);
    Manufacturer &operator=(const Manufacturer &);
    Manufacturer &operator=(Manufacturer &&);
};

#endif
