analysis.md

Authors: Hannah Tippin, Leonardo Garcia, Brandon Steege

COSC 4010

May 12, 2020


Initially, we began our analysis by attempting to find the local variable that we knew to be in the main function of our C++ program. Our main tool that was used for this analysis was IDA Pro 7.0 as that was the only version that would run on our Windows 10 machines. 

Once we were able to determine the variables and the memory locations that they were tied to, it was much easier for us to then determine the functions that were called, since we could relate them to certain variables. Since the encoder function is likely the most important function when it comes to protecting the data, we started by trying to track it down. We knew that it was only called once and it would be called after the variables were declared in main so we looked in that general location in the code until we found the correct one. 

From there, we examined the encoder function in more detail. The encoder function is supposed take in all values to be encoded and pass them to functions that encode based off of the variable type. These sub-encoder functions are passed a key value and the original value of the game attributes and return an encoded version of those values. Based on this knowledge we were able to see the hard-coded key values that were being passed to each function. The next step was to determine what types of encoding were being used for each function. 

As we analized each sub encoding function, we were able to determine that every function that took in an int or a double used an XOR Cipher while the functions that took in strings and chars used a Caeser Cipher. The Caeser Cipher uses a dictionary containing only uppercase letters from the alphabet stored in an array that was easy to identify. Based on the structure of the function, we were able to identify that those fuctions were using a Caeser Cipher. The functions that we determined to by using the XOR Cipher were much easier to identify as they contained an XOR on the stack. 

Knowing what types of ciphers were being used, along with being able to find the key values, we determined that we would be able to change the values of the variables into any value that we wanted once we reversed engineered the ciphers. 
