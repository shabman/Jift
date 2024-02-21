/* 
 * This file is part of the JiftUI distribution (https://github.com/shabman/Jift.git)
 * Copyright (c) 2024 Mustafa Malik.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIB_JIFTUI_TOKENS_H__
#define __LIB_JIFTUI_TOKENS_H__

// TODO: Add more when needed
typedef enum jift_tokens {
    /* Language Specifics */
    JIFT_TOKEN_KEYWORD,
    JIFT_TOKEN_CLASS_DECL,
    JIFT_TOKEN_METHOD_DECL,
    JIFT_TOKEN_VARIABLE_DECL,

    /* String related */
    JIFT_TOKEN_WHITESPACE,
    JIFT_TOKEN_TABSPACE,

    /* Data Types */
    JIFT_TOKEN_NON_PRIMITIVE_TYPE,
    JIFT_TOKEN_EXTERNAL_TYPE,

    /* Modules and Packages */
    JIFT_TOKEN_MODULE,
    JIFT_TOKEN_PACKAGE,
    JIFT_TOKEN_PACKAGE_NAME_SEP,
    JIFT_TOKEN_PACKAGE_NAME,

    /* Syntax Behaviour */
    JIFT_TOKEN_OPEN_PAREN,
    JIFT_TOKEN_CLOSE_PAREN,
    JIFT_TOKEN_TERMINATOR,

    JIFT_TOKEN_OPEN_BRACE,
    JIFT_TOKEN_CLOSE_BRACE,

    JIFT_TOKEN_COMMENT_DEFAULT,
    JIFT_TOKEN_COMMENT_DOCUMENT,
    JIFT_TOKEN_COMMENT_MULTILINE,

    /* Character Symbols */
    JIFT_TOKEN_CHARACTER,
    JIFT_TOKEN_NUMERICAL,
    JIFT_TOKEN_DIFF_SYMBOL,

    JIFT_TOKEN_INVALID_SYNTAX

} jift_tokens_t;

#endif /* __LIB_JIFTUI_TOKENS_H__ */