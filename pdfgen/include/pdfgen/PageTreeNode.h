// PDF "Page Tree Node"
// Intermediate nodes in the page tree structure that point to
// either page objects or other page tree nodes
namespace pdf
{
  namespace data_type
  {
    class PageTreeNode
    {
	    protected:
		    PageTreeNode();
		    ~PageTreeNode();
	    private:
		    pdf::Name m_type;
		    pdf::Dictionary m_parent;
		    pdf::Array m_kids;
		    pdf::Integer m_count;
    }; // class PageTreeNode
  } // namespace data_type
} // namespace pdf
