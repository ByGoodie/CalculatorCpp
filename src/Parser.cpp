#include "../include/Parser.h"
#include <cstdarg>

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

size_t ParseNode::getChildrenCount() {
	return m_children.size();
}

ParseNode &ParseNode::getChild(int level, ...) {
	va_list args;
	va_start(args, level);
	ParseNode &node = *this;
	for (int i = 0; i < level; i++) {
		node = node.m_children[va_arg(args, int)];
	}
	va_end(args);
	return node;
}

NodeType TermNode::getNodeType() const {
	return NodeType::Term;
}

NodeType NumberNode::getNodeType() const {
	return NodeType::Number;
}

NodeType OperatorNode::getNodeType() const {
	return NodeType::Operator;
}

void parse(ParseNode &root_node, FileTokenizer &tokenizer) {
	std::pair<std::string, char> tokens;
	do {
		
	} while (tokens.second != EOF);
}	

void parseTerm(TermNode &root_node) {
	std::pair<std::string, char> tokens;
	std::stringstream stream(root_node.m_value);
	StringTokenizer tokenizer(stream);
}
