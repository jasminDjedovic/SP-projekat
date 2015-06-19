#ifndef _LISTA_NIZOM_HXX
#define _LISTA_NIZOM_HXX
#include <iostream>
#include <string>

template <typename T>
class lista
{
  private:
    T *array;
    int _current;
    int _size;
    int _capacity;
  public:
    lista(int n = 100) : _size{0},_capacity{n}, _current{0}, array{new T[n]}{}
    lista(const lista<T> &);
    lista(lista<T> &&);
    lista<T> &operator=(const lista<T> &);
    lista<T> &operator=(lista<T> &&);
    ~lista();
    bool empty(){return _size==0;} 
    bool full(){return _size==_capacity;} 
    int size() const {return _size;}
    int getCurrent() const {return _current;}
    int getCapacity() const {return _capacity;}
    T *getArray() const {return array;}
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    void insert(T);
    void erase();
    T &operator[](int a) {return array[a];} 
    T &operator[](int a) const {return array[a];} 
    struct iterator; 
    iterator begin() {return iterator(array);}
    iterator end() {return iterator(array+_size-1);}
};

template <typename T>
lista<T>::lista(const lista<T> &b)
{
  _current = b.getCurrent();
  _size = b.size();
  _capacity = b.getCapacity();
  array = new T[_capacity];
  for(int i=0;i<_size;++i)
    array[i] = b[i];

}
template <typename T>
lista<T>::lista(lista<T> &&b)
{
  _current = b.getCurrent();
  _size = b.size();
  _capacity = b.getCapacity();
  array = b.getArray();

  b.array = nullptr;

}
template <typename T>
lista<T> &lista<T>::operator=(const lista<T> &b)
{
  if(_size!=b.size())
    throw std::string("Greska!!");

  for(int i=0;i<_size;++i)
    array[i] = b[i];

  return *this;
}
template <typename T>
lista<T> &lista<T>::operator=(lista<T> &&b)
{
  if(_size!=b.size())
    throw std::string("Greska!!");

  array = b.getArray();

  b.array = nullptr;
}

template <typename T>
void lista<T>::push_back(T val)
{
  if(!full())
  {
    array[_size] = val;
    _current = _size;
    ++_size;
  }
  else
    throw std::string("Lista je puna!!");
}
template <typename T>
void lista<T>::push_front(T val)
{
  if(!full())
  {
    for(int i=_size-1;i>=0;--i)
      array[i+1] = array[i];

    array[0] = val;
    ++_size;
    _current = 0;
  }
  else
    throw std::string("Lista je puna!!");
}
template <typename T>
void lista<T>::pop_back()
{
  if(!empty())
  {
    --_size;
    _current = size-1;
  }
  else
    throw std::string("Prazna lista!!");
}
template <typename T>
void lista<T>::pop_front()
{
  if(!empty())
  {
    for(int i=0;i<_size;++i)
      array[i] = array[i+1];

    --_size;
    _current =0;
  }
  else
    throw std::string("Prazna lista!!");
}
template <typename T>
void lista<T>::insert(T val)
{
  if(!full())
  {
    for(int i=_size-1;i>=_current;--i)
      array[i+1] = array[i];

    array[_current] = val;
    ++_current;
    ++_size;
  }
  else
  {
    throw std::string("Lista puna!!");
  }
}
template <typename T>
void lista<T>::erase()
{
  if(!empty())
  {
    for(int i=_current;i<_size;++i)
      array[i] = array[i+1];

    --_size;

  }
  else
    throw std::string("Prazna lista!!");
}

template <typename T>
lista<T>::~lista()
{
  delete [] array;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, lista<T> &b)
{
  for(int i=0;i<b.size();++i)
    out<<b[i]<<" ";

  out<<std::endl;

  return out;
}

template <typename T>
struct lista<T>::iterator
{
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef size_t difference_type;
  typedef T* pointer;
  typedef T& reference;

  T *ptr;
  iterator() : ptr{nullptr} {}
  iterator(T *val) : ptr{val} {}
  iterator(const iterator &it) : ptr{it.ptr} {}
  iterator(iterator &&it) : ptr{it.ptr} {}
  iterator &operator=(const iterator &it) {ptr=it.ptr; return *this;}
  iterator &operator=(iterator &&it) {ptr = it.ptr; return *this;}
  
  bool operator==(const iterator &it) const {return ptr==it.ptr;}
  bool operator!=(const iterator &it) const {return ptr!=it.ptr;}
  bool operator<(const iterator &it) const {return ptr<it.ptr;}
  bool operator>(const iterator &it) const {return ptr>it.ptr;}
  T &operator*() const {return *ptr;}
  iterator &operator++(){++ptr; return *this;}
  iterator operator++(int) {
    iterator temp = *this;
    ++ptr;
    return temp;
  }
  iterator &operator--(){--ptr; return *this;}
  iterator operator--(int){
    iterator temp = *this;
    --ptr;
    return temp;
  }
  iterator operator+(const int &val) const {return ptr+val;}
  iterator operator-(const int &val) const {return ptr-val;}
  int operator-(const iterator &it) const {return ptr-it.ptr;}
  int operator+(const iterator &it) const {return ptr+it.ptr;}
  
};


#endif
