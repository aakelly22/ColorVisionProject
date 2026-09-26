# Color Distinguishability Reference for Color Blindness

## Description

**version 1.0**

This program asks the user to choose one of Deuteranopia, Tritanopia, Protanopia, or all at once.
Then it asks for two colors. After it will check for how distinguishable the colors are from each other for the type of colorblindness chosen.


## Developer

Aidan Kelly

## Example

To run the program, type a number 1-4 for the type of blindness. After input two rgb colors. Make sure to put a space between your R G and B values.
To keep using the program type 'c' and it will restart.

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Hi there! this program lets you check how distinguishable two colors are for some types of colorblindness!
Start by selecting a type of color blindness. Input the number associated with the type and hit enter.

Deuteranopia:   1
Tritanopia:     2
Protanopia:     3

For all types tested together:  4
1
You chose Deuteranopia!
Now I would like you to input two colors, and then I will check how distinguishable they are for people with Deuteranopia.

When inputting the colors please type them out by their RGB values, Ex: 255 0 0 and make sure to put a space between each number.
Lets start with the first color, enter the RGB values and then hit enter.
100 200 0
Thank you, this color is accepted. Please type another color.
234 90 0
Thank you, we will now look more in depth at these two colors.
Your colors are: 100 200 0 and: 234 90 0


All done!
The two main categories we looked into were the lightness and the color intensity.
For deuteranopia, we particularly looked at the intensity green in your colors.
Since people with deuteranopia are missing their green cones.

Your colors together resulted in a low visibility score.
They would be extremely difficult to distinguish for somebody with Deuteranopia.
People with deuteranopia do not differentiate red and green well, they also have trouble with some purples and pinks.


If you would like to do another color blindness type or if you want to try new colors type 'c' to continue
```