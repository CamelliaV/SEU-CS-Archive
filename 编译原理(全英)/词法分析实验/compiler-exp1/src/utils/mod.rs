use std::{fs::File, io::{ErrorKind, Read, Write}};
#[derive(PartialEq)]
pub enum Type {
    Digit,
    Letter,
    Separator,
    Operator,
    Other
}

pub fn judge_type(ch: &char) -> Type {
    if is_digit(ch) {
        return Type::Digit; 
    } else if is_letter(ch) {
        return Type::Letter;
    } else if is_separator(ch) != error_code {
        return Type::Separator;
    } else if is_operator(&ch.to_string()) != error_code {
        return Type::Operator;
    } else {
        return Type::Other;
    }
}

const keywords: &[&str] = &[
    "int",      "alignas",      "const_cast", "static_assert",
    "long",     "alignof",      "continue",   "static_cast",
    "and",      "mutable",      "co_await",   "struct",
    "and_eq",   "co_return",    "switch",     "namespace",
    "co_yield", "new",          "template",   "asm",
    "decltype", "this",         "auto",       "noexcept",
    "default",  "bitand",       "not",        "thread_local",
    "bitor",    "delete",       "not_eq",     "throw",
    "bool",     "do",           "nullptr",    "true",
    "double",   "break",        "operator",   "try",
    "case",     "dynamic_cast", "or",         "typedef",
    "catch",    "or_eq",        "else",       "typeid",
    "char",     "private",      "typename",   "enum",
    "char8_t",  "explicit",     "union",      "protected",
    "char16_t", "public",       "unsigned",   "export",
    "using",    "char32_t",     "register",   "extern",
    "class",    "false",        "virtual",    "reinterpret_cast",
    "float",    "void",         "compl",      "requires",
    "for",      "volatile",     "concept",    "return",
    "friend",   "wchar_t",      "short",      "const",
    "signed",   "while",        "consteval",  "goto",
    "sizeof",   "if",           "xor",        "constexpr",
    "inline",   "xor_eq",       "constinit",  "static"
];

const separators: &[char] = &[
    ',', ';', '.', '(',
    ')', '[', ']', '{',
    '}', '#'
];
const operators: &[&str] = &[
    "+",  "-",  "++", "--",
    "*",  "/",  "<",  "<=",
    ">",  ">=", "=",  "==",
    "!=", "<<", ">>", "&&",
    "||"
];

const spaces: &str = " \n\r\t";

pub const error_code: i32 = -1;
pub const integer_code: i32 = 666;
pub const float_code: i32 = 777;
pub const identifier_code: i32 = 888;
const keyword_shift: i32 = 10086;
const separator_shift: i32 = 911;
const operator_shift: i32 = 476;

pub fn read_safe(path: &str) -> String {
    let mut res = String::new();
    match File::open(path) {
        Ok(mut file) => match file.read_to_string(&mut res) {
            Ok(_) => res,
            Err(err) => panic!("Error: error occurred while reading file: {:?}", err)
        },
        Err(err) => match err.kind() {
            ErrorKind::NotFound => panic!("Error: file not found! Please check your path!"),
            _ => panic!("Error: error occurred while opening file: {:?}", err)
        }
    }
}

pub fn write_safe(path: &str, content: &str) {
    match File::create(path) {
        Ok(mut file) => match file.write(content.as_bytes()) {
            Ok(_) => {},
            Err(err) => panic!("Error: error occurred while writing file, {:?}", err)
        },
        Err(err) => panic!("Error: error occurred while creating file, {:?}", err)
    }
}

pub fn is_digit(ch: &char) -> bool {
    ch.is_ascii_digit()
}

// bytes() would be adopted but for the support for Unicode
pub fn is_letter(ch: &char) -> bool {
    ch.is_alphabetic()
}

pub fn is_keyword(string: &str) -> i32 {
    match keywords.iter().position(|&r| r == string) {
        Some(pos) => keyword_shift + pos as i32,
        None => error_code
    }
}

pub fn is_separator(ch: &char) -> i32 {
    match separators.iter().position(|&r| r == *ch) {
        Some(pos) => separator_shift + pos as i32,
        None => error_code
    }
}

pub fn is_operator(string: &str) -> i32 {
    match operators.iter().position(|&r| r == string) {
        Some(pos) => operator_shift + pos as i32,
        None => error_code
    }
}

pub fn is_space(ch: &char) -> bool {
    spaces.contains(*ch)
}

pub fn is_new_line(ch: &char) -> bool {
    *ch == '\n'
}

pub fn is_float(ch: &char) -> bool {
    *ch == '.'
}