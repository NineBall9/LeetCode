bool judgeCircle(string moves) {
    int count_L=0, count_R=0, count_U=0, count_D = 0;
    for(int i = 0; i < moves.length(); i++){
        switch (moves[i]){
            case 'U': 
                count_U += 1;
                continue;
            case 'D':
                count_D += 1;
                continue;
            case 'L':
                count_L += 1;
                continue;
            case 'R':
                count_R += 1;
                continue;
            
        }
    }
    return (count_U == count_D && count_L == count_R);
    
}
