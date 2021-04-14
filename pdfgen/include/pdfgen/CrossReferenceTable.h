// pdf file structure defined Cross-Reference Table
// contains information that permits random access to indirect objects
// within the file. One line entry for each indirect object, specifying
// the location of that object within the body of the file
// example:
//
namespace pdf
{
  class CrossReferenceTable
  {
	  protected:
		  CrossReferenceTable();
		  ~CrossReferenceTable();
  }; // class CrossReferenceTable
} // namespace pdf
