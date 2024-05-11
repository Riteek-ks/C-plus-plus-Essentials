// With virtual Runtime polymorphism
// TextBox Accept
// Numeric TExtBox Accept
// Numeric TExtBox Accept
// Masked TExtBox Accept

// Without virtual it is Shadowing
// TextBox Accept
// Numeric TExtBox Accept
// TextBox Accept
// TextBox Accept

// override keyword if added gives error when the function overriden is not declared virtual.

#include <iostream>
#include <string>
using namespace std;

class TextBox
{
public:
    virtual void accept(string text) { cout << "TextBox Accept" << endl; }
};
class NumericTextBox : public TextBox
{
public:
    void accept(string text) override { cout << "Numeric TExtBox Accept" << endl; }
};
class MaskedTextBox : public TextBox
{
public:
    void accept(string text) override { cout << "Masked TExtBox Accept" << endl; }
};
int main()
{
    TextBox nameTextBox;
    nameTextBox.accept("tom");

    NumericTextBox ageTextBox;
    ageTextBox.accept("25");

    TextBox *basePtr = &ageTextBox;
    basePtr->accept("35");

    MaskedTextBox phoneNumberTextBox;
    basePtr = &phoneNumberTextBox;
    basePtr->accept("+91-1234567890");
}