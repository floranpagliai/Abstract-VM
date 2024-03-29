#ifndef __EXCEPTION_HPP__
#define	__EXCEPTION_HPP__

#include <string>
#include <exception>

class Exception : public std::exception
{
public:
  Exception(std::string const& msg) throw();
  virtual ~Exception() throw();

  virtual const char* what() const throw();

private:
  std::string   _msg;
};

#endif	/* __EXCEPTION_HPP__ */

