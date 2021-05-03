#ifndef VENDING_MACHINE_ITEMS_H
#define VENDING_MACHINE_ITEMS_H


class Vending_Machine_Items
{
public:
    Vending_Machine_Items();
    void Vending_Machine_Money_input();
    void Vending_Machine_Money_repeat_input();            /// repeat input money process .
    void Vending_Machine_Choices_Items();                 /// Choice item first time .
    void Vending_Machine_Money();                         /// reminder of money first time .
    void Vending_Machine_Anther_choice();                 /// Choice item second time .
    void Vending_Machine_counter_if_counter_equal_zero(); /// if counter  = 0 ( number of one item = 0 ) i will calling the ( Vending_Machine_Anther_choice ) function .
    void break_fun();                                     /// Break function i use it in code when i use if condition and i want to i=use it not while loop in code .
    void setnumber();

    float new_temp; /// new reminder of money input .
    int number ;    /// use it in Anther Choice Function .
    int item_Choice_number;  /// choose number from user .
    float input_money; /// input money if user .
    int counter1 , counter2 , counter3 , counter4 , counter5 , counter6 , counter7 , counter8 , counter9 , counter10 ;  /// i use it in files of items to find number of item in file in this time .

private:
    float temp;   /// reminder money in first time .
    float number_of_item; /// number of item user need it .
    float repeat_input;  /// when i use repeat function this variable use it to take money from user ( that equal the input money in Vending_Machine_Money_input function ).

};

#endif
