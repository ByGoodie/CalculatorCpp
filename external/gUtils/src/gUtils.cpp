#include "../include/gUtils.h"

void gUtils::trim(std::string &str, char ch) {
	if (str.starts_with(ch)) str.erase(str.begin());
	if (str.ends_with(ch)) str.erase(str.end() - 1);
}
