/* Gerry Gialias
 *
 */
#include "fio.h"

std::string& File::getStream(std::string filepath)
{
	std::ifstream fio(filepath);
	static std::string str((std::istreambuf_iterator<char>(fio)),
  									std::istreambuf_iterator<char>());
	return str;
};
 