#include "manufacturer.h"
#include <string>

Manufacturer::Manufacturer(const std::string &name, const std::string &model, const std::string &Class)
{
  _name = name;
  _model = model;
  _class = Class;
}
Manufacturer::Manufacturer(const Manufacturer &b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
}
Manufacturer::Manufacturer(Manufacturer &&b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
}
Manufacturer &Manufacturer::operator=(const Manufacturer &b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
  return *this;
}
Manufacturer &Manufacturer::operator=(Manufacturer &&b)
{
  _name = b._name;
  _model = b._model;
  _class = b._class;
  return *this;
}


