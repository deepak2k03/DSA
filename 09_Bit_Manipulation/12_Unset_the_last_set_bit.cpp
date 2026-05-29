int removeLastSetBit(int n){
    return (n&(n-1));
    //another apporach is find position of last set bit and then toggle it
}