String letter;

String translateToLetter(String message) {
    if (message == ".-") letter = "A";
    if (message == "-...") letter = "B";
    if (message == "-.-.") letter = "C";
    if (message == "-..") letter = "D";
    if (message == ".") letter = "E";
    if (message == "..-.") letter = "F";
    if (message == "--.") letter = "G";
    if (message == "....") letter = "H";
    if (message == "..") letter = "I";
    if (message == ".---") letter = "J";
    if (message == "-.-") letter = "K";
    if (message == ".-..") letter = "L";
    if (message == "--") letter = "M";
    if (message == "-.") letter = "N";
    if (message == "---") letter = "O";
    if (message == ".--.") letter = "P";
    if (message == "--.-") letter = "Q";
    if (message == ".-.") letter = "R";
    if (message == "...") letter = "S";
    if (message == "-") letter = "T";
    if (message == "..-") letter = "U";
    if (message == "...-") letter = "V";
    if (message == ".--") letter = "W";
    if (message == "-..-") letter = "X";
    if (message == "-.--") letter = "Y";
    if (message == "--..") letter = "Z";
    if (message == ".-...") letter = "1";
    if (message == "---.") letter = "2";
    if (message == ".--.-") letter = "3";
    if (message == "--...") letter = "4";
    if (message == ".-.-") letter = "5";
    if (message == ".-..-") letter = "6";
    if (message == "....-") letter = "7";
    if (message == "--.") letter = "8";
    if (message == ".....") letter = "9";
    if (message == "-----") letter = "0";
    if (message == ";") letter = " ";

    return letter;
}