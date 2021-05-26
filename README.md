# CommonLib - project of cpp-libraries that are contains common cpp-code for all projects
***  
## Brief Content  
* [ ] common.lib  
    * [ ] namespace Common  
        * [ ] namespace Errors (error.lib) 
            * [ ] class BaseError - ...  
        * [x] class Str - common utf-8 string class that extends of std::string base class  
            * [x] Str& Replace(const Str& from, const Str& to) - replaces substing in target string  
            * [x] Str& Format(const Str& substring, const Types& ... remainSubstrings) - performs formating string by templates - {0}, {1}, ... {N}  
        * [x] template<int64_t index, class Collection> class IndexIteratorStatic - creates static iterator to predefined position inside container
            * [x] CollectIt Get() cosnt - gets iterator to predefined position --> iterator to the static-indexed element
        * [x] template<class Collection> class IndexIterator - creates iterator to some container for get its values by index
            * [x] CollectIt operator[] (int64_t index) const - gets the container value by index --> iterator to the indexed element
        * [ ] template<bool isNeedCheck> class AdvancedAlgorithms - 
            * [x] template<int64_t from = 0, int64_t to = -1, bool isOptionalResult = true, class Collection, class Action> static decltype(auto) Find(Collection& collection, Action&& value) - finds element in collection in predefined range - [from, to) --> if isOptionalResult-flag is true - optional value with desired element; otherwise - iterator to found element or end-iterator
