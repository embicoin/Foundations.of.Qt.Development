#include "textandnumber.h"

TextAndNumber::TextAndNumber()
{
    number = 0;
    text = "";
}

TextAndNumber::TextAndNumber( int num, QString txt )
{
    number = num;
    text = txt;
}
