#include<stdio.h>
#include<string.h>
typedef long long int DATATYPE;

// -9223372036854775807 to 9223372036854775807;

char ones[][10]= {"One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
char tens[][10]= {"Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
char elev[][12]= {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Forteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Ninteen "};
char expo[][15]= {"Thousand ", "Million ", "Billion ", "Trillion ", "Quadrillion ", "Quintillion "};

void partial(short x, char str[]) {
    short o = x % 10;
    short t = x % 100 / 10;
    short h = x / 100;

    str[0] = '\0';
    if (h != 0) {
        strcat(str, ones[h-1]);
        strcat(str, "Hundred ");
    }

    if (t != 0) {
        if (t == 1) 
            strcat(str, elev[o]);
        else {
            strcat(str, tens[t-2]);
            strcat(str, ones[o-1]);
        }
    } else 
        strcat(str, ones[o-1]);
}

void solve(DATATYPE x) {
    if (x == 0) {
        printf("Zero\n");
        return;
    }

    short i, negative = x < 0;
    char res[255]="", temp[255], val[255];

    x = x < 0 ? -x : x;
    for (i = 0; x != 0; i++) {
        partial(x % 1000, val);
        if (i != 0 && strcmp(val, ""))
            strcat(val, expo[i-1]);

        x /= 1000;
        strcpy(temp, res);
        strcpy(res, val);
        strcat(res, temp);
    }

    if (negative) {
        strcpy(temp, res);
        strcpy(res, "Negative ");
        strcat(res, temp);
    }

    puts(res);
}

int main() {
    DATATYPE n;
    printf("Enter a number: ");
    scanf("%lld", &n);
    solve(n);
    return 0;
}
