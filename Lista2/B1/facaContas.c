int faz_conta_direito(int parcelas, char op){
    int i, valor, sum = 0;
    for(i = 0; i < parcelas; i++){
        scanf("%d", &valor);
        if(i == 0){
            sum = valor;
        }
        if(op == '+' && i != 0){
            sum += valor;
        }else if (op == '-'  && i != 0){
            sum -= valor;
        }
    }
    return sum;
}