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
