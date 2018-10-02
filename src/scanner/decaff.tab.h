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
    O_SEMICOLON = 267,
    KEY_IF = 268,
    KEY_ELSE = 269,
    KEY_CALLOUT = 270,
    STRING = 271,
    EQUAL_OP = 272,
    ADD_EQUAL_OP = 273,
    SUB_EQUAL_OP = 274,
    LEFT_CBRACE = 275,
    RIGHT_CBRACE = 276,
    INT_LITERAL = 277,
    LEFT_SBRACE = 278,
    RIGHT_SBRACE = 279,
    BOOL_LITERAL = 280,
    BINARY_ADD = 281,
    BINARY_SUBTRACT = 282,
    BINARY_MULTIPLY = 283,
    BINARY_DIVISION = 284,
    BINARY_MOD = 285,
    O_LEF = 286,
    O_RIT = 287,
    O_NOT = 288,
    O_LEQ = 289,
    O_GEQ = 290,
    O_LES = 291,
    O_GRE = 292,
    O_EQL = 293,
    O_NEQ = 294,
    R_AND = 295,
    R_OR = 296,
    R_EQUALS = 297,
    R_NOT_EQUALS = 298,
    R_GREATER_THAN = 299,
    R_GREATER_THAN_EQUAL = 300,
    R_LESS_THAN = 301,
    R_LESS_THAN_EQUAL = 302,
    UNARY_NOT = 303
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

#line 110 "decaff.tab.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DECAFF_TAB_H_INCLUDED  */
