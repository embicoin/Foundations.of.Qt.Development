#include "signal_slot.h"

MyClass::MyClass(const QString &text, QObject *parent)
{
    m_text = text;
    parent;
}

/*
const QString& MyClass::text() const
{
    return m_text;    
}
int MyClass::getLengthOfText() const
{
    return m_text.length();
}
*/

void MyClass::setText(const QString &text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(m_text);
}

