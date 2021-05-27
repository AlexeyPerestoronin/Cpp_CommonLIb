#include "test-unit-common.hpp"
#include "str.hpp"

using Str = typename Common::Str;

TEST(Str, ConstructorsTest) {
    {
        Str str("string");
        EXPECT_STREQ(str.data(), "string");
    }

    {
        std::string s{ "string" };
        Str str(s);
        EXPECT_FALSE(s.empty());
        EXPECT_STREQ(str.data(), "string");
    }

    {
        std::string s{ "string" };
        Str str(std::move(s));
        EXPECT_TRUE(s.empty());
        EXPECT_STREQ(str.data(), "string");
    }

    {
        std::string s{ "string" };
        Str str(s.begin(), s.end());
        EXPECT_FALSE(s.empty());
        EXPECT_STREQ(str.data(), "string");
    }

    {
        std::string s{ "string" };
        Str str{};
        std::move(s.begin(), s.end(), std::back_inserter(str));
        EXPECT_STREQ(str.data(), "string");
    }
}

TEST(Str, RepalceTest) {
    {
        Str s{ "text [1] text" };
        s.Replace("[1]", "text");
        EXPECT_STREQ(s.data(), "text text text");
    }

    {
        Str s{ "text [1] text [1] text" };
        s.Replace("[1]", "text");
        EXPECT_STREQ(s.data(), "text text text text text");
    }

    {
        Str s{ "[1]" };
        s.Replace("[1]", "text");
        EXPECT_STREQ(s.data(), "text");
    }

    {
        Str s{ "--[1]" };
        s.Replace("[1]", "text");
        EXPECT_STREQ(s.data(), "--text");
    }

    {
        Str s{ "[1]--" };
        s.Replace("[1]", "text");
        EXPECT_STREQ(s.data(), "text--");
    }

    {
        Str s{ "[1][1]" };
        s.Replace("[1]", "");
        EXPECT_STREQ(s.data(), "");
    }

    {
        Str s{ "[1][1]" };
        ASSERT_THROW(s.Replace("[1]", "[1]"), std::exception);
    }

    {
        Str s{ "[1]" };
        ASSERT_THROW(s.Replace("[1]", "[[1]]"), std::exception);
    }
}

TEST(Str, FormatTest) {
    {
        Str s{ "" };
        s.Format("text");
        EXPECT_STREQ(s.data(), "");
    }

    {
        Str s{ "{1}" };
        s.Format("text");
        EXPECT_STREQ(s.data(), "{1}");
    }

    {
        Str s{ "{1}" };
        s.Format<1>("text");
        EXPECT_STREQ(s.data(), "text");
    }

    {
        Str s{ "{0}" };
        s.Format("text");
        EXPECT_STREQ(s.data(), "text");
    }

    {
        Str s{ "{0}{0}{0}" };
        s.Format("text");
        EXPECT_STREQ(s.data(), "texttexttext");
    }

    {
        Str s{ "{0}-{1}" };
        s.Format("text", "name");
        EXPECT_STREQ(s.data(), "text-name");
    }

    {
        Str s{ "{0}-{1}-{0}" };
        s.Format("text", "name");
        EXPECT_STREQ(s.data(), "text-name-text");
    }

    {
        Str s{ "{1}-{0}" };
        s.Format("text", "name");
        EXPECT_STREQ(s.data(), "name-text");
    }
}
