#include "../external/gUtils/include/gUtils.h"
#include <iostream>

template <class StreamT>
Tokenizer<StreamT>::Tokenizer(StreamT &source) : m_source(source) {}

template <class StreamT>
std::pair<std::string, char> Tokenizer<StreamT>::getCurrentToken(const std::string &delimiters) {
	std::pair<std::string, char> result;
	result.second = gUtils::getLine(m_source, result.first, delimiters);
	return result;
}
