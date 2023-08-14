#include <string>
#include <fstream>
#include <sstream>

template <class StreamT>
class Tokenizer {
public:
	Tokenizer(StreamT &source);

	std::pair<std::string, char> getCurrentToken(const std::string& delimiters);

private:
	StreamT &m_source;
};

#include "../src/Tokenizer.inl"

typedef Tokenizer<std::ifstream> FileTokenizer;
typedef Tokenizer<std::stringstream> StringTokenizer;
