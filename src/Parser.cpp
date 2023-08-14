#include "../include/Parser.h"
#include <cassert>
#include <cstdarg>

enum OperatorType {
	SumSub,
	MultDiv
};

const std::string operators[2] = {"+-", "*/"};

NodeType ParseNode::getNodeType() const {
	return NodeType::None;
}

void ParseNode::attachChild(Ptr node) {
	m_children.push_back(std::move(node));
}

ParseNode::Ptr ParseNode::detachChild(int index) {
	assert(index > 0 && index < m_children.size());
	ParseNode::Ptr node = std::move(m_children[index]);
	m_children.erase(m_children.begin() + index);
	return std::move(node);
}

size_t ParseNode::getChildrenCount() const {
	return m_children.size();
}

ParseNode &ParseNode::getChild(size_t level, ...) {
	va_list args;
	va_start(args, level);
	ParseNode *node = this;
	for (int i = 0; i < level; i++) {
		node = node->m_children[va_arg(args, int)].get();
	}
	va_end(args);
	return *node;
}

TermNode::TermNode(const std::string &val) : value(val) {}

NodeType TermNode::getNodeType() const {
	return NodeType::Term;
}

NumberNode::NumberNode(long double val) : value(val) {}

NodeType NumberNode::getNodeType() const {
	return NodeType::Number;
}

OperatorNode::OperatorNode(char val) : value(val) {}

NodeType OperatorNode::getNodeType() const {
	return NodeType::Operator;
}

void parseFile(ParseNode &root_node, FileTokenizer &tokenizer) {
	std::pair<std::string, char> tokens;
	do {
		tokens = tokenizer.getCurrentToken(operators[OperatorType::SumSub]);
		ParseNode::Ptr term(new TermNode(tokens.first));
		parseTerm(static_cast<TermNode&>(*term));
		root_node.attachChild(std::move(term));
		if (tokens.second != EOF) {
			ParseNode::Ptr op(new OperatorNode(tokens.second));
			root_node.attachChild(std::move(op));
		}
	} while (tokens.second != EOF);
}	

void parseTerm(TermNode &root_node) {
	std::pair<std::string, char> tokens;
	std::stringstream stream(root_node.value);
	StringTokenizer tokenizer(stream);
	do {
		tokens = tokenizer.getCurrentToken(operators[OperatorType::MultDiv]);
		gUtils::trim(tokens.first, ' ');
		ParseNode::Ptr number(new NumberNode(std::stold(tokens.first)));
		root_node.attachChild(std::move(number));
		if (tokens.second != EOF) {
			ParseNode::Ptr op(new OperatorNode(tokens.second));
			root_node.attachChild(std::move(op));
		}
	} while (tokens.second != EOF);
}
