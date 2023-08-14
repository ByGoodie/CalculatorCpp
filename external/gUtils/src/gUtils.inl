template <class Stream>
char gUtils::getLine(Stream &source, std::string &str, const std::string &delims) {
	char ch;
	for (ch = source.get(); ch != EOF && delims.find(ch) == std::string::npos; ch = source.get()) {
		str.append(1, ch);
	}
	return ch;
}
