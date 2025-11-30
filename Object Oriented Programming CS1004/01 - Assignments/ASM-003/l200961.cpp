// 20L-0961      Ammar Ahmed     ASM-003 //
#include <iostream>
using namespace std;

//Note: You can add additional members to the class if required
class Decoder
{
private:
    string message;
public:
    // default constructor is needed since inheritance is implemented
    Decoder(string);
    virtual void Decode();
    string getMessage() {
        return message;
    }
};
class SuperDecoder : public Decoder
{
public:
    SuperDecoder(string);
    virtual void Decode();
};
class PremiumDecoder : public Decoder
{
public:
    PremiumDecoder(string);
    void Decode();
};

void OperateDecoder(Decoder& Instance);

int main()
{
    //implementation of the "Hello" decryption in example
    Decoder* D[3];
    D[0] = new Decoder("Mjqqt");
    D[1] = new SuperDecoder("Mjqqt");
    D[2] = new PremiumDecoder("Mjqqt");
   
    // I have used polymorphism in my code due to the 
    // nature of OperateDecoder function
    for (int i = 0; i < 3; i++) 
        OperateDecoder(*D[i]);

    return 0;
}

Decoder::Decoder(string message = "") {
    this->message = message;
}

SuperDecoder::SuperDecoder(string messsage = ""):Decoder(messsage) {
}

PremiumDecoder::PremiumDecoder(string message = ""):Decoder(message) {
}

void Decoder::Decode() {
    int key = 5;
    for (int i = 0; i < message.size(); ++i) {
        char ch = this->message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            this->message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch > 'a') {
                ch = ch + 'Z' - 'A' + 1;
            }
            this->message[i] = ch;
        }
    }
    cout << "\nDecoded message: " << message << endl;
}

void superFeatures(string in) {
    int words = 0, vowels = 0, consonant = 0, i = 0;
    while (i < in.size()) {
        char ch = in[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            words++;
        }
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u')
            ++vowels;

        else if ((ch >= 'a' && ch <= 'z'))
            ++consonant;

        ++i;
    }

    cout << "Words found " << words 
       << "\nVowels " << vowels 
       << "\nNon-vowels " << consonant << endl;
}

void SuperDecoder::Decode() {
    cout << "\nSuperDecoder called";
    Decoder::Decode();
    superFeatures(getMessage());
}

void PremiumDecoder::Decode() {
    cout << "\nPremiumDecoder called";

    Decoder::Decode(); 
    superFeatures(getMessage());

    string message = getMessage();
    for (int i = 0; i < (message.size()) / 2; i++)
        swap(message[i], message[message.size() - i - 1]);

    cout << "Reversed Decode " << message << endl;
}

void OperateDecoder(Decoder& Instance) {
    Instance.Decode();
}