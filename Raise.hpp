#ifndef RAISE_H_
# define RAISE_H_

# include <exception>
# include <string>
# include "std_improve.hpp"

// Usage example
// ======================
// module_new_raise(ParsingRaise)
// module_new_raise_from(ParsingSpecialTokenRaise, ParsingRaise)
// module_new_raise_from(ParsingUniqueTokenRaise, ParsingRaise)
// raise(ParsingRaise, "Error of parsing about your ';'");

class StandardRaise : public std::exception {
public:
  StandardRaise(std::string const & name,
		std::string const & str,
		size_t const line=0,
		std::string const & file = "") :
    _name(name), _str(str), _line(line), _file(file) {
  }
  virtual ~StandardRaise() throw() {
  }
  virtual const char *what() const throw() {
#ifdef STD_IMPROVE_H_
    return (_name + " : " + _str + " at <" + _file + ":" + toString(_line) + ">").c_str();
#else
    return (_name + " : " + _str + " at <" + _file + ":?>").c_str();
#endif
  }
  void setLine(size_t line) { _line = line; }
  void setFile(std::string const & file) { _file = file; }

protected:
  std::string _name;
  std::string _str;
  size_t _line;
  std::string _file;
};

# define module_new_raise_from(name, base)				\
  class name : public base {						\
  public: name(std::string const & name,				\
	       std::string const & str,					\
	       size_t const line=0,					\
	       std::string const & file = "") :				\
    base(name, str, line, file) {}					\
    virtual ~name() throw() {}						\
  };

# define module_new_raise(name) module_new_raise_from(name, StandardRaise)

# define raise(errtype, why) throw errtype(#errtype, why, __LINE__, __FILE__)

#endif /* !RAISE_H_ */
