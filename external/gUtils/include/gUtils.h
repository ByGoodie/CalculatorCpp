#include <fstream>
#include <string>

namespace gUtils {
	template <class StreamT>
	char getLine(StreamT &source, std::string &str, const std::string &delims);

	void trim(std::string &str, char ch);
}

#include "../src/gUtils.inl"
