
int findComplement(int num){
        unsigned int bits=floor(log2(num))+1, i=1;;
        return ((i<<bits)-i) ^ num;
}