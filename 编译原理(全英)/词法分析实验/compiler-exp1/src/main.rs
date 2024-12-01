/* Disable unnecessary warnings */
#![allow(non_upper_case_globals, unused_mut)]
mod utils;

use utils::*;

fn new_line(line: i32, res: &mut String) {
    let string = format!("=============== line: {}", line);
    println!("{}", string);
    res.push_str(&(string + "\r\n"));
}

/* 
* A token will be generated each time 'scan' gets invoked.
* The program is originally designed to generate tokens out of C++ code text;
* however, not all features are included in the target list
* eg. ` ` - whitespace (skip), `'` - single quote, `''` - double quote, `//` - comment (Not supported)
* comments, punctuation and string literals are not supported
* unicode text is supported
*/
fn scan(content: &Vec<char>, pointer: usize, line: i32, res: &mut String) -> (String, i32, usize, i32) {
    
    let mut line = line;
    let end = content.len();
    /* token id (indicate the category) */
    let mut id = 1453_05_29;
    /* token buffer */
    let mut buffer = String::new();
    /* Rust only accepts usize as type of indices */
    let mut i: usize = pointer;
    /* Scan, do nothing if space occurs, start new line if '\n' occurs */
    while i < end && is_space(&content[i]) {
        if is_new_line(&content[i]) {
            line += 1;
            new_line(line, res);
        }
        i += 1;
    }
    /* guarantee safe access to i in the following code */
    if i == end {
        return (buffer, id, i, line);
    }
    
    /* judge the type of character encountered, act according to the type */
    match judge_type(&content[i]) {
        /* token starts with digit -> integer | float */
        Type::Digit => {
            /* accept both . and digits, try to get all the acceptable pushed to buffer */
            while i < end && (is_float(&content[i]) || is_digit(&content[i])) {
                buffer.push(content[i]);
                i += 1;
            }
            /* error handling for multiple float points */
            if buffer.matches('.').count() > 1 {
                panic!("{}", "Reject: multiple float points".to_string());
            }
            /* error handling for digits followed by letter */
            if i < end && is_letter(&content[i]) {
                panic!("{}", "Reject: letter appeared right after digits".to_string());
            
            } else if buffer.contains('.') {
                id = float_code;    
            } else {
                id = integer_code;
            }
            
        },
        /* token starts with letter -> identifier | keyword  */
        Type::Letter => {
            while i < end && (is_digit(&content[i]) || is_letter(&content[i])) {
                buffer.push(content[i]);
                i += 1;
            }
            let code = is_keyword(&buffer);
            id = if code == error_code {identifier_code} else {code};
        },
        /* token starts with separator */
        Type::Separator => {
            buffer.push(content[i]);
            id = is_separator(&content[i]);
            i += 1;
        },
        /* token starts with operator */
        Type::Operator => {
            buffer.push(content[i]);
            /* may take two positions */
            if i + 1 < end && is_operator(&(buffer.clone() + &content[i + 1].to_string())) != error_code {
                i += 1;
                buffer.push(content[i]);
            } 
            id = is_operator(&buffer);
            i += 1;
        },
        /* ignore other occurrences */
        Type::Other => {
            i += 1;
        }
    }    
    /* last sentence without ; will be returned in Rust */
    (buffer, id, i, line)
}

fn main() {

    let mut path = String::from("");
    
    /* dis-comment the following statement to input given file name, pay attention to the location of file */
    std::io::stdin().read_line(&mut path).unwrap(); 
    
    /* Encapsulated file reader */
    let content = read_safe(&path.trim());
    
    let file_name: Vec<&str> = path.split(".").collect();
    let file_name = file_name[0].to_string();
    let file_name = file_name + "_out.txt";
    
    println!("{:?}", content);
    
    /* String access with indices is not allowed in Rust, i.e "random words"[0] -> X */
    let content: Vec<char> = content.chars().collect();
    
    
    let end = content.len();
    let mut buffer;
    let mut id;
    let mut i = 0;
    let mut line = 0;
    let mut res = String::new();
    
    new_line(line, &mut res);
    while i < end {
        (buffer, id, i, line) = scan(&content, i, line, &mut res); 
        let token = format!("({}, {})", if buffer == "" {"Not supported"} else {&buffer}, id);
        println!("{}", token);
        res.push_str(&(token + "\r\n"));
    }
    write_safe(&file_name, &res);
}




    
