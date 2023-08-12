#include "../gUtils.h"

char gUtils::getLine(Stream &source, std::string &str, const std::string &delims) {
	char ch = source.get();
	for (char ch = source.get(); ch != EOF && delims.find(ch) == std::string::npos; ch = source.get()) {
		str.append(ch);
	}
	return ch;
}
