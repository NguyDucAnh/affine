#include <bits/stdc++.h>
using namespace std;
string encryptMessage(string msg, int a, int b)
{
    string cipher = "";
    for(int i = 0; i < msg.length(); i++)
    {
        if(msg[i] != ' ')
            cipher += (char) ((((a * (msg[i] - 'A')) + b) % 26 ) + 'A');
        else
            cipher += msg[i];
    }
    return cipher;
}

string decryptCipher(string cipher, int a, int b)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;

    // Find modular inverse of a
    for(int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if(flag == 1)
        {
            a_inv = i;
            break;
        }
    }

    for(int i = 0; i < cipher.length(); i++)
    {
        if(cipher[i] != ' ')
        {
            int temp = ((a_inv * (cipher[i] - 'A' - b)) % 26);
            if(temp < 0) // Handle negative values
                temp += 26;
            msg += (char) (temp + 'A');
        }
        else
        {
            msg += cipher[i];
        }
    }
    return msg;
}
int main()
{
	int a, b;
	cout<<"Nhap vao khoa K co a la: ";
	cin>>a;
	cout<<"Nhap vao khoa K co b la: ";
	cin>>b;
	string msg;
	cout<<"Nhap vao chuoi ban ro: ";
	cin.ignore();
	getline(cin, msg);
	string cip;
	cout<<"Nhap vao chuoi ban ma: ";
	cin.ignore();
	getline(cin, cip);

	cout<<"Encrypted Message is: "<< encryptMessage(msg, a, b)<<endl;

	cout<<"Decrypted Message is: "<< decryptCipher(cip, a, b)<<endl;

	return 0;


}
