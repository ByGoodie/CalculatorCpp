#pragma once

#include "Tokenizer.h"
#include <vector>
#include <memory>

enum class NodeType : unsigned int {
	None,
	Term,
	Number,
	Operator
};

class ParseNode {
public:  
	typedef std::unique_ptr<ParseNode> Ptr;

public:
	ParseNode() = default;

	virtual NodeType getNodeType() const;
	void attachChild(Ptr node);
	Ptr detachChild(int index);
	size_t getChildrenCount() const;
	ParseNode &getChild(size_t level, ...);

private:
	std::vector<Ptr> m_children;

	ParseNode(const ParseNode &);
	ParseNode &operator=(const ParseNode &);
};

class TermNode : public ParseNode {
public:
	TermNode(const std::string &val);

	virtual NodeType getNodeType() const override;

	std::string value;
};

class NumberNode : public ParseNode {
public:
	NumberNode(long double val);

	virtual NodeType getNodeType() const override;

	long double value;
};

class OperatorNode : public ParseNode {
public:
	OperatorNode(char val);

	virtual NodeType getNodeType() const override;

	char value;
};

void parseFile(ParseNode &root_node, FileTokenizer &tokenizer);
void parseTerm(TermNode &root_node);
