class Solution {
public:

    string romanNum(int digit, int digit_no){
        string s;
        if(digit_no==1){
            if(digit==4 or digit==9){
                s="I";
                digit++;
            }
        }
        else if(digit_no==2){
            if(digit==4 or digit==9){
                s="X";
                digit++;
            }
        }
        else if(digit_no==3){
            if(digit==4 or digit==9){
                s="C";
                digit++;
            }
        }
        digit_no--;
        while(digit_no>0){
            digit*=10;
            digit_no--;
        }
        while(digit>0){
            if(digit>=1000) digit-=1000, s+='M';
            else if(digit>=500) digit-=500, s+='D';
            else if(digit>=100) digit-=100, s+='C';
            else if(digit>=50) digit-=50, s+='L';
            else if(digit>=10) digit-=10, s+='X';
            else if(digit>=5) digit-=5, s+='V';
            else if(digit>=1) digit-=1, s+='I';
        }
        return s;
    }
    string intToRoman(int num) {
        string number=to_string(num),res;
        for(int i=0;i<number.size();i++){
            res+=romanNum((number[i]-'0'),number.size()-i);
        }
        return res;
    }
};