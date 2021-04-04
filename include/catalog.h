// PDF "Catalog Dictionary"
// The root of a document's object heirarchy is the catalog dictionary,
// located via the Root entry in the trailer of the PDF file. Contains 
// references to other objects defining the document's contents, out-line,
// article threads, named destinations, and other attributes.
class Catalog
{
	protected:
		Catalog();
		~Catalog();
}
