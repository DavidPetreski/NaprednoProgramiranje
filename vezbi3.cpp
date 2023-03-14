#include <bits/stdc++.h>
using namespace std;

enum Mesec {
    Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

int main()
{
    int i;
    for (i=Jan; i <= Dec; i++)
        cout << i <<" ";

    int input;
    cout << endl << "Vnesi mesec (Kako BROJ vo datumite): ";
    cin >> input;

    Mesec mesec = static_cast<Mesec>(input);

    if (mesec < Jan || mesec > Dec) {
        cout << "Nepostoecki mesec" << endl;
        return 0;
    }

    Mesec next_mesec = static_cast<Mesec>((mesec % 12) );
     string month_names[] = {"", "Januari", "Februari", "Mart", "April", "Maj",
                            "Juni", "Juli", "Avgust", "Septemvri", "Oktomvri",
                            "Noemvri", "Dekemvri"};

    cout << "Go vnesivte mesecot: " << month_names[mesec] << endl;
    switch (next_mesec)
    {
        case Jan:
        case Feb:
        case Dec:
            cout << "Zimski mesec " << next_mesec << endl;
            break;
        case Mar:
        case Apr:
        case May:
            cout << "Proleten mesec " << next_mesec << endl;
            break;
        case Jun:
        case Jul:
        case Aug:
            cout << "Leten mesec " << next_mesec << endl;
            break;
        case Sep:
        case Oct:
        case Nov:
            cout << "Esenski mesec " << next_mesec << endl;
            break;
        default:
            cout << "Nepostoecki mesec" << endl;
    }

    return 0;
}