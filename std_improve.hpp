#ifndef STD_IMPROVE_H_
# define STD_IMPROVE_H_

# include <exception>
# include <string>
# include <sstream>

// # define stringify(c_string) std::string(c_string)

template <typename T>
T	fromString(std::string str)
{
  std::stringstream s;
  T v;
  s << str;
  s >> v;
  return v;
}

template <typename T>
std::string	toString(T v)
{
  std::stringstream s;
  std::string str;
  s << v;
  s >> str;
  return str;
}

#endif /* !STD_IMPROVE_H_ */
