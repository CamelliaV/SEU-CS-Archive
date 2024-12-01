use std::{fs, io};


/* u8 for 'char' replacement in C, as char in rust takes four bytes */
struct Prod<'a>(u8, &'a str);
/* E' -> R    T' -> Y */
const productions: [Prod; 8] = [
    Prod(b'E', "TR"),       // 0 E->TE'
    Prod(b'R', "+TR"),      // 1 E'->+TE'
    Prod(b'R', "ε"),        // 2 E'->ε
    Prod(b'T', "FY"),       // 3 T->FT'
    Prod(b'Y', "*FY"),      // 4 T'->*FT'
    Prod(b'Y', "ε"),        // 5 T'->ε
    Prod(b'F', "(E)"),      // 6 F->(E)
    Prod(b'F', "i"),        // 7 F->i
]; 
const MATCH: usize = usize::MAX;
/* 
* return MATCH if terminal is given and matched with the first input string character 
* else the index of productions
* panic if the entry is blank (error - failure in grammatical analysis)
*/
fn ll_1_match(stack_top: u8, input_first: u8) -> usize {
    /* terminal */
    if stack_top == input_first {
        return MATCH;
    }
    if stack_top.is_ascii_lowercase() {
        panic!("Failure in grammatical analysis: terminal not matched");
    }
    /* maybe not good for efficiency, but fine for readability */
    match (stack_top, input_first) {
        (b'E', b'(') => 0,
        (b'E', b'i') => 0,
        (b'R', b'+') => 1,
        (b'R', b')') => 2,
        (b'R', b'$') => 2,
        (b'T', b'(') => 3,
        (b'T', b'i') => 3,
        (b'Y', b'+') => 5,
        (b'Y', b'*') => 4,
        (b'Y', b')') => 5,
        (b'Y', b'$') => 5,
        (b'F', b'(') => 6,
        (b'F', b'i') => 7,
        _ => panic!("Failure in grammatical analysis: no correct production available")
    }
}
fn format_output(str: String) -> String {
    str.replace("R", "E'").replace("Y", "T'")
}
fn print_current(stack: &Vec<u8>, input_string: &[u8], input_pointer: usize, step: u8, prod: usize) -> String {
    let production = if prod == MATCH {
        "".to_string() 
    } else {
        let prod = &productions[prod];
        let prod = (prod.0 as char).to_string() + "->" + prod.1;
        format_output(prod)
    };
    format!("{:<8} {:8} {:8} {:8}\n", step, format_output(String::from_utf8_lossy(stack).to_string()), String::from_utf8_lossy(&input_string[input_pointer..]), production)
}
fn analyze(input_string: &str) -> Vec<String> {
    let mut res = vec![];
    let mut stack = vec![b'$', b'E'];
    let input_string = input_string.to_string() + "$";
    let mut prod = MATCH;
    let input_string = input_string.as_bytes();
    let mut input_pointer = 0usize;
    let mut step = 0u8;
    res.push(format!("{:8} {:8} {:8} {:8}\n", "step", "stack", "input", "prod"));
    print!("{}", res[0]);
    while stack.len() != 0 {
        res.push(print_current(&stack, input_string, input_pointer, step, prod));
        print!("{}", res.last().unwrap());
        step += 1;
        prod = ll_1_match(stack.pop().unwrap(), input_string[input_pointer]);
        if prod == MATCH {
            input_pointer += 1;
        } else {
            let to_push = productions[prod].1;
            if to_push == "ε" {
                continue;            
            }
            let mut to_push = String::from(to_push);
            let to_push = unsafe { to_push.as_bytes_mut() };
            to_push.reverse();
            to_push.iter().for_each(|el| stack.push(*el));
        }
    }
    res
}
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Fail to read input string");
    fs::write("out.txt", analyze(&input.trim()).join("")).expect("Fail to write output");
}
