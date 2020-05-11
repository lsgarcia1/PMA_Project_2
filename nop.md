nop.md

Authors: Hannah Tippin, Leonardo Garcia, Brandon Steege

COSC 4010

May 12, 2020

Strengths: Our encoding function has multiple function calls to functions that encode particular variable types using different ciphers. This makes our code tougher to analyze because knowledge of mutiple ciphers along with nested function calls allows for further obfuscation. We also didn't use any external libraries for the ciphers. This means that an attacker likely will not be able to find any descriptors in the strings when using analysis tools. 

Weaknesses: The cipher keys are hardcoded into the program without any obfuscation. This means that if an attacker is able to determine what cipher is being used, they will likely be able to easily break it with the use of the key values. The other portion that they will need would be the library for Caeser Ciphers in particular. This is also not obfuscated in our code and was fairly easy to find as well. Lastly, with the variable declarations being at the top of main, they are all in one spot essentially. This gives an attacker easier access to them without having to spend as much time digging through code to find them. 

Future Changes: Ideally, the main change that we should make would be to obfuscate the cipher keys and libraries. This adds a further layer of difficulty for the attacker. We could also further localize our variables, so that they are more spread throughout the code, rather than in one single place. A hardcoded and obfuscated string could be used instead of a calculated one to check the correctness of Defaults.txt. 
