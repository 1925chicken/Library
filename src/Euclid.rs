fn euclid(mut x:i64,mut y:i64) -> i64 {
    let mut r:i64 = 1e9 as i64;
    if x < y{
        std::mem::swap(&mut x,&mut y);
    }
    while r != 0 {
        r = x % y;
        x = y;
        y = r;
    }
    x
}