// Copyright 2025 JesusTouchMe

#ifndef VLEX_TEMPLATES_STRING_LITERAL_PARSE_CPP_H
#define VLEX_TEMPLATES_STRING_LITERAL_PARSE_CPP_H 1

namespace templates
{
    constexpr const char* StringLiteralParseCPP = R"(        if (current() == '"')
        {{
            consume();
            std::string text;
            while (current() != '"')
            {{
                if (current() == '\\')
                {{
                    consume();
                    switch(current())
                    {{
                        case 'n':
                            text += '\n';
                            break;
                        case '\'':
                            text += '\'';
                            break;
                        case '\"':
                            text += '\"';
                            break;
                        case '\\':
                            text += '\\';
                            break;
                        case '0':
                            text += '\0';
                            break;
                    }}
                }}
                else
                {{
                    text += current();
                }}
                consume();
            }}
            SourceLocation end = mSourceLocation;
            end.col++;
            end.position++;
            return Token(std::move(text), TokenType::{}, start, end);
        }}
)";
}

#endif // VLEX_TEMPLATES_STRING_LITERAL_PARSE_CPP_H