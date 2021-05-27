#include "test-unit-common.hpp"
#include "errors/base_error.hpp"

#define RAISE_TEST_ERROR(message) RAISE_ERROR("tests", message)

#define RAISE_TEST_ERROR_AGAIN(what_happend, suberror) RAISE_ERROR_AGAIN("test", what_happend, suberror)

using BaseError = Common::Errors::BaseError;

using FromTo = std::tuple<uint32_t, uint32_t>;

void RecursiveCall(FromTo from_to) {
    auto& [from, to] = from_to;
    try {
        if (from < to) {
            RecursiveCall({ from + 1, to });
        } else {
            RAISE_TEST_ERROR(Common::Str("test error message: from {0} to {1}").Format(std::to_string(from), std::to_string(to)));
        }
    } catch (BaseError& error) {
        if (from != to) {
            RAISE_TEST_ERROR_AGAIN(Common::Str("test error message: from {0} to {1}").Format(std::to_string(from), std::to_string(to)), error);
        } else {
            throw std::move(error);
        }
    }
}

TEST(BaseError, Test1) {
    try {
        RecursiveCall({ 0, 3 });
        FAIL() << "exception must be raised";
    } catch (BaseError& error) {
        ASSERT_EQ(error.GetDeep(), 4);
        std::cout << error.WhatHappened();
    }
}
