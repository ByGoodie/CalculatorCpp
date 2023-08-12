#pragma once

#include "Tokenizer.h"
#include <vector>
#include <memory>

enum class NodeType : unsigned int {
	None,
	Term,
	Number,
	Operator
}

class ParseNode {
public:  
	typedef std::unique_ptr<ParseNode> Ptr;

public:
	virtual NodeType getNodeType() const;
	void attachChild(Ptr node);
	Ptr detachChild(int index);
	size_t getChildrenCount();
	ParseNode &getChild(size_t level, ...);

private:
	std::vector<Ptr> m_children;
}

class TermNode : public ParseNode {
public:
	virtual NodeType getNodeType() const override;

	std::string value;
}

class NumberNode : public ParseNode {
public:
	virtual NodeType getNodeType() const override;

	long double value;
}

class OperatorNode : public ParseNode {
public:
	virtual NodeType getNodeType() const override;

	char value;
}

void parse(ParseNode &root_node, FileTokenizer &tokenizer);
void parseTerm(TermNode &root_node);
