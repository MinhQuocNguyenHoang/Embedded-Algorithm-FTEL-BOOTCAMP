bool judgeCircle(char* moves) {
    int origin_coordinates[]={0,0};
    int move_coordinates[]={0,0};
    if(move_coordinates[0] < 0 || move_coordinates[1] < 0) return false;
    
    int i=0;
    while(moves[i]!='\0'){
        if(moves[i]=='U') ++move_coordinates[0];
        else if(moves[i]=='D') --move_coordinates[0];
        else if(moves[i]=='L') --move_coordinates[1];
        else ++move_coordinates[1];
       i++; 
    }
    if(move_coordinates[0]==0 && move_coordinates[1]==0) return true;
    return false;
}