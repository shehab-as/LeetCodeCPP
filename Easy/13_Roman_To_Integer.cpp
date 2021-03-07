class Solution {
public:
    int romanToInt(string s) {
        int roman_to_int=0;
        map<char, int> roman_to_int_table;
        roman_to_int_table['I'] = 1;
        roman_to_int_table['V'] = 5;
        roman_to_int_table['X'] = 10;
        roman_to_int_table['L'] = 50;
        roman_to_int_table['C'] = 100;
        roman_to_int_table['D'] = 500;
        roman_to_int_table['M'] = 1000;
        char symb;
        int d;
        bool possible_sub_instances[3] = {false};
        for (int i=0; i<s.length(); i++)
        {
            symb = s[i];
            d = roman_to_int_table[symb];
            if (symb == 'I')
                possible_sub_instances[0] = true;
            else if (symb == 'X')
                possible_sub_instances[1] = true;
            else if (symb == 'C')
                possible_sub_instances[2] = true;
            
            if((symb == 'V' || symb == 'X') && possible_sub_instances[0])
            {
                roman_to_int -= roman_to_int_table['I'];
                d = roman_to_int_table[symb] - roman_to_int_table['I'];
                bool possible_sub_instances[3] = {false};
            }
            else if((symb == 'L' || symb == 'C') && possible_sub_instances[1])
            {
                roman_to_int -= roman_to_int_table['X'];
                d = roman_to_int_table[symb] - roman_to_int_table['X'];
                bool possible_sub_instances[3] = {false};
            }
            else if((symb == 'D' || symb == 'M') && possible_sub_instances[2])
            {
                roman_to_int -= roman_to_int_table['C'];
                d = roman_to_int_table[symb] - roman_to_int_table['C'];
                bool possible_sub_instances[3] = {false};
            }
            roman_to_int += d;
        }
        
        return roman_to_int;
    }
};