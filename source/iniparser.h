#ifndef __INI_PARSER_H__
#define __INI_PARSER_H__

#include "base.h"
#include <string>

namespace ccc {

struct IniDictionary
{
	
};

typedef IniDictionary IniDictionary;

class IniParser
{
public:
	explicit IniParser(const char* filename) : m_inifile(filename) 
	{

	}
	
	virtual ~IniParser();

private:
	const char* m_inifile;	

};

}  //namespace ccc

#endif 
