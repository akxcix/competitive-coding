use std::io;

fn main(){
    let mut n = String::new();
    io::stdin()
        .read_line(& mut n)
        .expect("failed to read input");
    let n: i64 = n.trim().parse().expect("invalid input");
    println!("{}", n);
}
