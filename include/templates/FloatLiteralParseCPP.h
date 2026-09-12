// Copyright 2026 Jannik Laugmand Bülow

#ifndef VLEX_TEMPLATES_FLOAT_LITERAL_PARSE_CPP_H
#define VLEX_TEMPLATES_FLOAT_LITERAL_PARSE_CPP_H 1

namespace templates
{
    constexpr const char* FloatLiteralParseCPP = R"(        if (std::isdigit(current()) || (current() == '.' && std::isdigit(peek(1)))
        {{
            std::string text;

            if (current() == '.')
            {{
                text += current();

                while (std::isdigit(peek(1)))
                {{
                    consume();
                    text += current();

                    if (isDigitSeparator(peek(1)))
                    {{
                        consume();
                    }}
                }}
            }}
            else
            {{
                text += current();

                if (isDigitSeparator(peek(1)))
                {{
                    consume();
                }}

                while (std::isdigit(peek(1)))
                {{
                    consume();
                    text += current();

                    if (isDigitSeparator(peek(1)))
                    {{
                        consume();
                    }}
                }}

                // Fractional part
                if (peek(1) == '.')
                {{
                    consume();
                    text += current();

                    while (std::isdigit(peek(1)))
                    {{
                        consume();
                        text += current();

                        if (isDigitSeparator(peek(1)))
                        {{
                            consume();
                        }}
                    }}
                }}
            }}

            if (peek(1) == 'e' || peek(1) == 'E')
            {{
                consume();
                text += current();

                if (peek(1) == '+' || peek(1) == '-')
                {{
                    consume();
                    text += current();
                }}

                while (std::isdigit(peek(1)))
                {{
                    consume();
                    text += current();

                    if (isDigitSeparator(peek(1)))
                    {{
                        consume();
                    }}
                }}
            }}

            return Token(std::move(text), TokenType::{}, start, mSourceLocation);
        }}
)";
}

#endif //VLEX_TEMPLATES_FLOAT_LITERAL_PARSE_CPP_H
