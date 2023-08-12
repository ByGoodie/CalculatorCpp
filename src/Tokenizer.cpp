#include "Tokenizer.h"
#include "../external/gUtils/include/gUtils.h"

template <class Stream>
Tokenizer<Stream>::Tokenizer(Stream &source) : m_source(source) {}

template <class Stream>
std::pair<std::string, char> Tokenizer<Stream>::getCurrentToken(const std::string &delimiters) {
	std::pair<std::string, char> result;
	result.second = gUtils::getLine(m_source, result.first, delimiters);
	return result;
}
