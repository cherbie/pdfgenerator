// PDF "Number Tree"
// Similar to a "name tree", except it's keys are integers instead of strings,
// sorted in ascending numerical order
namespace pdf
{
  namespace data_type
  {
    class NumberTree
    {
      protected:
        NumberTree();
	      ~NumberTree();

		  public:
        class Node
	      {
			    protected:
				    Node();
				    ~Node();
		    }; // class Node
    } // class NumberTree
  } // namespace data_type
} // namespace pdf
