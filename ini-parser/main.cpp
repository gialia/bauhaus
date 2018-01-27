/* Gerry Gialias
 *
 */
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>
#include <map>
#include <utility>

#include "fio.h"


int main (int argc, char *argv[])
{

	std::string&	stream 		 = File::getStream("config");
	std::string 	rules_string =	".+=.*\n|\\[.+\\]\n";
	std::regex 		rules(rules_string);
	
	std::sregex_token_iterator itr(stream.begin(), stream.end(), rules, 0);
	std::sregex_token_iterator endIter;
	
	std::map< std::string, std::map<std::string, std::string> > tokenMap;

	std::string category = "[default]";
	std::string container;
	
	for (; itr != endIter; ++itr)
	{
		container = itr->str();

		if (container.compare(0, 1, "[") == 0)
			category = itr->str();
		else
		{
			std::string delimiter = "=";
			std::string firstPart  = container.substr(0, container.find(delimiter));
			std::string secondPart = container.substr(container.find(delimiter), container.length());
			tokenMap[category][firstPart] = secondPart;
		}

	    std::cout << itr->str() << std::endl;
	}



}