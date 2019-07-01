//Ref https://github.com/rui314/8cc
#ifndef NINECC_H
#define NINECC_H

#include<assert.h>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<iostream>

/* all types of token */
enum Token_type{
    TOKEN_ID,
    TOKEN_KEYWORD,
    TOKEN_NUM,
    TOKEN_CHAR,
    TOKEN_STRING,
    TOKEN_EOF,
    TOKEN_INVALID,
    TOKEN_NEWLINE,
    TOKEN_SPACE,
    TOKEN_MACRO_PARAM,
};
/*all types of the basic data type and return type of func */
enum Var_type{
    TYPE_VOID,
    TYPE_BOOL,
    TYPE_CHAR,
    TYPE_SHORT,
    TYPE_INT,
    TYPE_LONG,
    TYPE_LLONG,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_LDOUBLE,//TO BE CHECKED
    TYPE_ARRAY,
    TYPE_ENUM,
    TYPE_PTR,
    TYPE_STRUCT,
    TYPE_FUNC,
    TYPE_STUB,//only used in parser noted in 8cc
};
// id for AST building
enum AST_OP_Keyword{
    AST_LITERAL = 256,
    AST_LVAR,
    AST_GVAR,
    AST_TUPEDEF,
    AST_FUNCALL,
    AST_FUNCPTR_CALL,
    AST_FUNCDESG,
    AST_FUNC,
    AST_DECL,
    AST_INIT,
    AST_CONV,
    AST_ADDR,
    AST_DEREF,
    AST_IF,
    AST_TERNARY,
    AST_DEFAULT,
    AST_RETURN,
    AST_COMPOUND_STMT,
    AST_STRUCT_REF,
    AST_GOTO,
    AST_COMPUTED_GOTO,
    AST_LABEL,
    //----------I'm a split line--------
    OP_SIZEOF,
    OP_CAST,
    OP_SHR,
    OP_SHL,
    OP_A_SHR,
    OP_A_SHL,
    OP_PRE_INC,
    OP_PRE_DEC,
    OP_POST_INC,
    OP_POST_DEC,
    OP_LABEL_ADDR,
#define op(name, _) name,
#define keyword(name, x, y) name,
#include "keyword.inc"
#undef keyword
#undef op
};
enum ENC_Type{
    ENC_NONE,
    ENC_CHAR16,
    ENC_CHAR32,
    ENC_UTF8,
    ENC_WCHAR
};
struct AST_Node{
    
    
};
struct File{
    FILE* file;
    char* p;
    char* name;
    int line;
    int column;
    int ntoken;
    int last;      //the last character read from file
    int buf[3];
    int buflen;
    time_t mtime;  //last modified time. 0 for string-backed file
    File(){

    }
};
struct Token{
    int kind;
    File* file;
    int line;
    int column;
    bool space;
    bool bol;      //ture if the token is at the beginning of the line
    int count;
    //for macro, 8cc used a Set-like structure
    union data
    {
        int id;    //keyword
        
        struct str{
            char* sval;
            int slen;
            int c;
            int enc;
        };

        struct macro_param{
            bool is_var;
            int position;
        };
    };
    Token(){

    };


};
struct Type{

};
struct Buffer{

};
struct SourceLoc{

};

#endif