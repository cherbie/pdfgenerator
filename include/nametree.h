// PDF "Name Tree" common data-type
// The name tree serves a similar purpose to a dictionary, associating 
// keys and values. Constructed of nodes, each of which is a dictionary object.
// Three different node types: Root Node, Intermediate Node and Leaf Node
class NameTree
{
	protected:
		NameTree();
		~NameTree();
		class Node
		{
			protected:
				Node();
				~Node();
		} // Node
} // NameTree
