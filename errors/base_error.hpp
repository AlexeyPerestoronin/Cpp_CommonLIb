#pragma once

#include "ptr.hpp"
#include "types.hpp"

namespace Common {
    namespace Errors {
        /**
        * brief: default output format for errors
        * example:
        * ```
        * Error:
        * | cannot set connection with host
        * | connection.lib
        * | Connector::SetConnection(Str)
        * | C:/.../connect.cpp(342)
        * ```
        */
        const Str DefaultErrorFormat = "Error:\n|{what}\n|{module}\n|{func}\n|{file}({line})";

        /**
        * brief: default delimiter between two errors in output
        * example:
        * ```
        * Error 1: ...
        * Error 2: ...
        * ...
        * Error N: ...
        * ```
        */
        const Str DefaultErrorsDelimiter = "\n";

        /**
        * brief: base class for creat of errors description stack
        */
        class BaseError : public std::exception {
            PtrStr(BaseError);

            private:
            // error's suberro and so on ...
            BaseError::UniPtr _suberror{};
            // total quantity of linked error
            uint32_t _deep{ 1 };

            // error's output format
            OptStr _delimiter{};
            OptStr _format{};

            // error's description fields
            OptStr _module{};
            OptStr _file{};
            OptStr _func{};
            OptStr _line{};
            OptStr _what{};

            public:
            BaseError();
            BaseError(Str format);
            BaseError(BaseError&&) = default;
            ~BaseError();

            BaseError(const BaseError&) = delete;
            BaseError operator=(const BaseError&) = delete;

            private: // std::exception
            virtual const char* what() const override;

            public:
            BaseError& AddSuberror(BaseError&& suberror);

            BaseError& SetDelimiter(Str delimiter);
            BaseError& SetFormat(Str format);
            BaseError& SetModule(Str module);
            BaseError& SetFile(Str file);
            BaseError& SetFunc(Str func);
            BaseError& SetLine(Str line);
            BaseError& SetWhat(Str what);

            /**
            * brief: gets total quantity of linked errors
            */
            uint32_t GetDeep() const;

            Str WhatHappened() const;
        }; // class BaseError

    } // namespace Errors

} // namespace Common

#define RAISE_ERROR(module_name, what_happend) \
    throw std::move(Common::Errors::BaseError().SetModule(module_name).SetFile(__FILE__).SetFunc(__FUNCTION__).SetLine(std::to_string(__LINE__)).SetWhat(what_happend));

#define RAISE_ERROR_AGAIN(module_name, what_happend, suberror) \
    throw std::move(Common::Errors::BaseError().SetModule(module_name).SetFile(__FILE__).SetFunc(__FUNCTION__).SetLine(std::to_string(__LINE__)).SetWhat(what_happend).AddSuberror(std::move(suberror)));
