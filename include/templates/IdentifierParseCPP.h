#ifndef VLEX_TEMPLATES_IDENTIFIER_PARSE_CPP_H
#define VLEX_TEMPLATES_IDENTIFIER_PARSE_CPP_H 1

#include <string_view>

namespace templates
{
    constexpr std::string_view IdentifierParseCPP = R"(        if (isIdentifierStart(current()))
        {{
            std::string text = std::string(1, current());
            while (isIdentifier(peek(1)))
            {{
                consume();
                text += current();
            }}

            if (keywords.find(text) != keywords.end())
            {{
                SourceLocation end = mSourceLocation;
                end.col++;
                end.position++;
                return Token(std::move(text), keywords.at(text), start, end);
            }}

            SourceLocation end = mSourceLocation;
            end.col++;
            end.position++;
            return Token(std::move(text), TokenType::{}, start, end);
        }}
)";
}

#endif // VLEX_TEMPLATES_IDENTIFIER_PARSE_CPP_H