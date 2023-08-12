#include <fstream>
#include <string>

namespace gUtils {
	template <class Stream>
	char getLine(Stream &source, std::string &str, const std::string &delims);
}
