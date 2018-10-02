/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_DECAFF_TAB_H_INCLUDED
# define YY_YY_DECAFF_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INTG = 258,
    T_FLOT = 259,
    T_BOOL = 260,
    T_NEWLINE = 261,
    IDENTIFIER = 262,
    KEY_CLASS = 263,
    KEY_PROGRAM = 264,
    O_COMMA = 265,
    KEY_TYPE = 266,
    KEY_FOR = 267,
    O_SEMICOLON = 268,
    KEY_IF = 269,
    KEY_ELSE = 270,
    KEY_CALLOUT = 271,
    STRING = 272,
    EQUAL_OP = 273,
    ADD_EQUAL_OP = 274,
    SUB_EQUAL_OP = 275,
    LEFT_CBRACE = 276,
    RIGHT_CBRACE = 277,
    INT_LITERAL = 278,
    LEFT_SBRACE = 279,
    RIGHT_SBRACE = 280,
    BOOL_LITERAL = 281,
    CHAR_LITERAL = 282,
    BINARY_ADD = 283,
    BINARY_SUBTRACT = 284,
    BINARY_MULTIPLY = 285,
    BINARY_DIVISION = 286,
    BINARY_MOD = 287,
    O_LEF = 288,
    O_RIT = 289,
    O_NOT = 290,
    O_LEQ = 291,
    O_GEQ = 292,
    O_LES = 293,
    O_GRE = 294,
    O_EQL = 295,
    O_NEQ = 296,
    R_AND = 297,
    R_OR = 298,
    R_EQUALS = 299,
    R_NOT_EQUALS = 300,
    R_GREATER_THAN = 301,
    R_GREATER_THAN_EQUAL = 302,
    R_LESS_THAN = 303,
    R_LESS_THAN_EQUAL = 304,
    UNARY_NOT = 305,
    KEY_RETURN = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "decaff.y" /* yacc.c:1910  */

    int ival;
    float fval;
    bool bval;
    char cval;

#line 113 "decaff.tab.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DECAFF_TAB_H_INCLUDED  */
