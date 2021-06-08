# CommonLib is project of cpp-libraries containing the most common classes
***  
## Brief Content  
* [ ] common.lib  
    * [ ] namespace Common  
        * [x] namespace Errors  
            * [x] class BaseError - base class for creat of errors description stack  
        * [x] class Str - common utf-8 string class that extends of std::string base class  
            * [x] Str& Replace(const Str& from, const Str& to) - replaces substing in target string  
            * [x] Str& Format(const Str& substring, const Types& ... remainSubstrings) - performs formating string by templates - {0}, {1}, ... {N}  
    * [ ] namespace AAC  
        * [x] template<bool is_const, class CollectionType> class IndexIterator - creates iterator to some container for get its values by index  
        * [x] template<class CollectionType> using II = IndexIterator<false, CollectionType>  
        * [x] template<class CollectionType> using CII = IndexIterator<true, CollectionType>  
        ***
        * [x] template<bool is_const, int64_t index, class CollectionType> class IndexIteratorStatic - creates static iterator to predefined position inside container  
        * [x] template<int64_t index, class CollectionType> using IIS = IndexIteratorStatic<false, index, CollectionType>  
        * [x] template<int64_t index, class CollectionType> using CIIS = IndexIteratorStatic<true, index, CollectionType>  
        ***
        * [x] template<bool is_const, class CollectionType> class IndexTrasmitter - creates and manages iterators for some subrange of elements from an arbitrary container  
        * [x] template<class CollectionType> using IT = IndexTrasmitter<false, CollectionType>  
        * [x] template<class CollectionType> using CIT = IndexTrasmitter<true, CollectionType>  
        * [x] template<class CollectionType> IT<CollectionType> MakeIT(CollectionType& collection, int64_t from = 0, int64_t to = -1) - creates an instance of IndexTrasmitter-class for non const data  
        * [x] template<class CollectionType> CIT<CollectionType> MakeCIT(const CollectionType& collection, int64_t from = 0, int64_t to = -1) - creates an instance of IndexTrasmitter-class for const data  
        ***
        Here are the implementation of all find-algorithms from SLT by means of applying AAC-Logic to each of them
        * [x] template<bool is_optional_result = true, class CollectionType, class ValueType> decltype(auto) Find(const CIT<CollectionType>& cit, ValueType&& value)
        * [x] template<bool is_optional_result = true, class CollectionType, class ValueType> decltype(auto) FindIf(const CIT<CollectionType>& cit, ValueType&& value)
        * [x] template<bool is_optional_result = true, class CollectionType, class ValueType> decltype(auto) FindIfNot(const CIT<CollectionType>& cit, ValueType&& value)
        * [x] template<bool is_optional_result = true, class CollectionType, class CollectionTypeWhere, class... ValuesTypes> decltype(auto) FindEnd(const CIT<CollectionType>& cit, const CIT<CollectionTypeWhere>& cit_what, ValuesTypes&&... values)
        * [x] template<bool is_optional_result = true, class CollectionType, class CollectionTypeWhere, class... ValuesTypes> decltype(auto) FindFirstOf(const CIT<CollectionType>& cit, const CIT<CollectionTypeWhere>& cit_what, ValuesTypes&&... values)
        * [x] template<bool is_optional_result = true, class CollectionType, class... ValuesTypes> decltype(auto) FindAdjacent(const CIT<CollectionType>& cit, ValuesTypes&&... values)
        ***
        Here are the implementation of all any-algorithms from SLT by means of applying AAC-Logic to each of them
        * [x] template<class CollectionType, class UnaryPredicateType> bool AnyOf(const CIT<CollectionType>& cit, UnaryPredicateType&& predicate)
        * [x] template<class CollectionType, class UnaryPredicateType> bool AllOf(const CIT<CollectionType>& cit, UnaryPredicateType&& predicate)
        * [x] template<class CollectionType, class UnaryPredicateType> bool NoneOf(const CIT<CollectionType>& cit, UnaryPredicateType&& predicate)
