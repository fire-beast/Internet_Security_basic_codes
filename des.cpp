#include <iostream>
#include<string>
using namespace std;

int main() {
    int i;
    int new_arr[64];
    int ip[64] = {58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
                  62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
                  57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
                  61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
    int l_side[32], r_side[32];
    int input_block[64] ={1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0};


    for (i = 0; i < 64; i++) {
        int temp = ip[i] - 1;
        new_arr[i] = input_block[temp];
    }

    int c = 0;
    for (i = 0; i < 64; i++) {
        cout << new_arr[i] << ",";
        c++;
        if (c == 8) {
            cout << endl;
            c = 0;
        }
    }

    for (i = 0; i < 32; i++) {
        l_side[i] = new_arr[i];
        r_side[i] = new_arr[i + 32];
    }

    cout << "left part:" << endl;
    for (i = 0; i < 32; i++) {
        cout << l_side[i] << " ,";
    }
    cout << endl;

    cout << "right part:" << endl;
    for (i = 0; i < 32; i++) {
        cout << r_side[i] << " ,";
    }
    cout << endl;

    int key[64] = {
        0, 1, 1, 0, 1, 0, 0, 1,
        1, 0, 0, 1, 1, 1, 0, 0,
        0, 1, 0, 1, 1, 0, 1, 0,
        1, 0, 1, 0, 0, 0, 1, 1,
        1, 0, 1, 0, 0, 1, 1, 0,
        0, 0, 1, 1, 1, 0, 1, 0,
        0, 1, 0, 1, 1, 1, 0, 0,
        1, 0, 1, 0, 0, 1, 0, 1
    };

    int array_56_bit[56], c1 = 0;
    for (int i = 0; i < 64; i++) {
        if ((i + 1) % 8 == 0) {
            continue;
        } else {
            array_56_bit[c1++] = key[i];
        }
    }

    cout << "Array after removing 8th positions:" << endl;
    for (i = 0; i < 56; i++) {
        cout << array_56_bit[i] << " ,";
    }
    cout << endl;

    int lkey[28], rkey[28];
    for (i = 0; i < 28; i++) {
        lkey[i] = array_56_bit[i];
        rkey[i] = array_56_bit[i + 28];
    }

    cout << "left key" << endl;
    for (i = 0; i < 28; i++) {
        cout << lkey[i] << " ";
    }
    cout << endl;

    cout << "right key" << endl;
    for (i = 0; i < 28; i++) {
        cout << rkey[i] << " ";
    }
    cout << endl;

    int templ = lkey[0];
    int tempr = rkey[0];
    for (int i = 1; i < 28; i++) {
        lkey[i - 1] = lkey[i];
        rkey[i - 1] = rkey[i];
    }
    lkey[27] = templ;
    rkey[27] = tempr;

    cout << "Left key after rotation" << endl;
    for (i = 0; i < 28; i++) {
        cout << lkey[i] << " ";
    }
    cout << endl;

    cout << "Right key after rotation" << endl;
    for (i = 0; i < 28; i++) {
        cout << rkey[i] << " ";
    }
    cout << endl;

    cout << "Concatenated Array:" << endl;
    int concatened_arr[56];
    for (i = 0; i < 28; i++) {
        concatened_arr[i] = lkey[i];
        concatened_arr[i + 28] = rkey[i];
    }
    for (i = 0; i < 56; i++) {
        cout << concatened_arr[i] << " ";
    }
    cout << endl;

    int compression_key_table[48] = {
        14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
    };

    int compressed_key_array[48];
    for (i = 0; i < 48; i++) {
        int temp3 = compression_key_table[i];
        compressed_key_array[i] = concatened_arr[temp3 - 1];
    }

    cout << "After Compression from 56 to 48:" << endl;
    for (i = 0; i < 48; i++) {
        cout << compressed_key_array[i] << " ";
    }
    cout << endl;

    int exp_d[48] = {32, 1, 2, 3, 4, 5, 4, 5,
                     6, 7, 8, 9, 8, 9, 10, 11,
                     12, 13, 12, 13, 14, 15, 16, 17,
                     16, 17, 18, 19, 20, 21, 20, 21,
                     22, 23, 24, 25, 24, 25, 26, 27,
                     28, 29, 28, 29, 30, 31, 32, 1};

    int new_right[48];
    for (i = 0; i < 48; i++) {
        new_right[i] = r_side[exp_d[i] - 1];
    }

    cout << "After Expansion from 32 to 48 of right part:" << endl;
    for (i = 0; i < 48; i++) {
        cout << new_right[i] << " ,";
    }
    cout << endl;

    // XOR operation between new_right and compressed_key_array
    int xor_result[48];
    for (i = 0; i < 48; i++) {
        xor_result[i] = new_right[i] ^ compressed_key_array[i];
    }

    cout << "XOR Result of new_right and compressed_key_array:" << endl;
    for (i = 0; i < 48; i++) {
        cout << xor_result[i] << " ,";
    }
    cout << endl;



    int sbox_1[4][16]={
        14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
         0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
         4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
         15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
    };
    int sbox2[4][16]={
        15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
        3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
        0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
        13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

    int sbox3[4][16]={
         10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
         13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
         13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
         1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
        };

    int sbox4[4][16]={
        7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
        13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
        10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
        3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

    int sbox5[4][16]={
    2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
    14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

     int sbox6[4][16]={
         12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
         10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
         9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
         4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

         int sbox7[4][16]={
             4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
             13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
             1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
             6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
         };

         int sbox8[4][16]={
             13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
         1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
         7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
         2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11

         };
         int function_op[32];
         int b0,b1,b2,b3,b4,b5;
         int row=0,column=0;
     for(i=0;i<1;i++)
     {
            b0=xor_result[i];
            b1=xor_result[i+1];
            b2=xor_result[i+2];
            b3=xor_result[i+3];
            b4=xor_result[i+4];
            b5=xor_result[i+5];
            if(b0==1 && b5==0)
            {
                row=0;
            }
            else if(b0==0 && b5==1)
            {
                row=1;
            }
            else if(b0==1 && b5==0)
            {
                row=2;
            }
            else if(b0==1 && b5==1)
            {
                row=3;
            }
            string column=to_string(b1)+to_string(b2)+to_string(b3)+to_string(b4);
            cout<<column;
            int bit4=stoi(column);
            cout<<bit4;
     }






    return 0;
}
