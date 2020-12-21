i64 extgcd(i64 a,i64 b,i64 &x,i64 &y){
    i64 d = a;
    if(b){
        d = extgcd(b,a % b,y,x);
        y -= (a / b) * x;
    }else{
        x = 1,y = 0;
    }
    return d;
}