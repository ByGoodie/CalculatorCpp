#include <string>
#include <fstream>
#include <stringstream>

template <class Stream>
class Tokenizer {
public:
	Tokenizer(Stream &source);

	std::pair<std::string, char> getCurrentToken(const std::string& delimiters);

private:
	S &m_source;
};

#include "../src/Tokenizer.inl"

typedef Tokenizer<std::ifstream> FileTokenizer;
typedef Tokenizer<std::stringstream> StringTokenizer;
