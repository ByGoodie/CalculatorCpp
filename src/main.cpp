#include <iostream>
#include <cassert>
#include "../include/Parser.h"

int main(int argc, char **argv) {
	try {
	ParseNode root_node;
	std::ifstream stream(argv[1]);
	FileTokenizer tokenizer(stream);
	parseFile(root_node, tokenizer);
	for (int i = 0; i < root_node.getChildrenCount(); i++) {
		ParseNode &node = root_node.getChild(1, i);
		for (int j = 0; j < node.getChildrenCount(); j++) {
			ParseNode &child_node = node.getChild(1, j);
			switch (child_node.getNodeType()) {
				case NodeType::Number:
				{
					std::cout << static_cast<NumberNode&>(child_node).value;
					break;
				}
				case NodeType::Operator:
				{
					std::cout << static_cast<OperatorNode&>(child_node).value;
					break;
				}
			}
		}
		if (node.getNodeType() == NodeType::Operator) std::cout << static_cast<OperatorNode&>(node).value;
	}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
} 
