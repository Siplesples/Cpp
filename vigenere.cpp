#include <iostream>
#include <string>

using namespace std;

string vigenere(string pass, string username) {
    string ciper = "";
    int maxSaya = username.length();
    for (int i = 0; i < pass.length(); ++i) {
        char pakai = pass[i];
        if (!isalpha(pakai)) {
            ciper += pakai;
            continue;
        }
        char usrid = username[i % maxSaya];
        usrid = toupper(usrid);
        int shift = usrid - 'A';
        if (islower(pakai)) {
            ciper += 'a' + (pakai - 'a' + shift) % 26;
        } else {
            ciper += 'A' + (pakai - 'A' + shift) % 26;
        }
    }
    return ciper;
}

int main() {
    string pass;
    string username;
    cout << "Masukan Username: ";
    cin >> username;
    cout << "Masukan password: ";
    cin >> pass;
    
    string encrypt = vigenere(pass, username);
    cout << "Password anda: " << encrypt << endl;
    return 0;
}
