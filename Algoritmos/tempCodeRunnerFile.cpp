float Fn(float x){
    return (pow(1/4, x)-pow(x,2)+4*x-3);
}

float derivada_Fn(float x){
    return(pow(1/4, x)-log(1/4)-2*x+4);
}