#include<iostream>
#include<string>
#include<cmath> //math functions like sqrt()
#include<limits> //for numeric limits which helps clean up the input stream


//declare functions
bool ColorAccepted(int, int, int);
void GetColors();
int DeuteranopiaComparison(int, int, int, int, int, int);
int TritanopiaComparison(int, int, int, int); // no B values because they we replace blue with green since they mix those up
int ProtanopiaComparison(int, int, int, int, int, int);
void CompareAll();
float Sqr(float);
void AskContinue();

//variables to hold the rgb values of inputted colors
int aR;
int aG;
int aB;

int bR;
int bG;
int bB;

//variable for whether or not we continue
bool continuing = true;


int main()
{
    while (continuing == true)
    {
        //Start by explaining the program to the user
        std::cout << "Hi there! this program lets you check how distinguishable two colors are for some types of colorblindness!\n" 
        << "Start by selecting a type of color blindness. Input the number associated with the type and hit enter.\n\n"
        << "Deuteranopia:\t1\nTritanopia:\t2\nProtanopia:\t3\n\nFor all types tested together:\t4\n";
        
        //get the colorblindness type -- user will enter a number if not defualt runs
        int type;
        std::cin >> type;


        switch (type)
        {
            case 1:
            {
                std::cout << "You chose Deuteranopia!\nNow I would like you to input two colors," 
                << " and then I will check how distinguishable they are for people with Deuteranopia.\n\n";
                
                GetColors();
                int dFinalScore = DeuteranopiaComparison(aR, aG, aB, bR, bG, bB);
                
                //output results
                std::cout << "\n\nAll done!\nThe two main categories we looked into were the lightness and the color intensity.\n"
                << "For deuteranopia, we particularly looked at the intensity green in your colors.\n"
                << "Since people with deuteranopia are missing their green cones.\n\n";
                //std::cout << "score: " << dFinalScore << '\n'; //debug line
                //NOTE following if statements have the potential issue where a 99 is low and a  100 is high
                if (dFinalScore < 100)
                {
                    std::cout << "Your colors together resulted in a low visibility score.\n"
                    << "They would be extremely difficult to distinguish for somebody with Deuteranopia.\n"
                    << "People with deuteranopia do not differentiate red and green well, they also have trouble with some purples and pinks.\n";
                }
                else if (dFinalScore < 200)
                {
                    std::cout << "Your colors together resulted in a high visibility score.\n"
                    << "Somebody with Deuteranopia should be able to distinguish these colors without concern.\n";
                }
                else
                {
                    std::cout << "Your colors together resulted in a very high visibility score.\n"
                    << "These colors are extremely distinguishable for someone with Deuteranopia.\n";
                }

                //ask if they want to continue
                AskContinue();
                break;
            }
            case 2:
            {
                std::cout << "You chose Tritanopia!\nNow I would like you to input two colors," 
                << " and then I will check how distinguishable they are for people with Tritanopia.\n\n";

                GetColors();

                int tFinalScore = TritanopiaComparison(aR, aG, bR, bG); // no B values because they we replace blue with green since they mix those up
                
                //output results
                std::cout << "\n\nAll done!\nThe two main categories we looked into were the lightness and the color intensity.\n"
                << "For Tritanopia, we particularly looked at the intensity of red in your colors.\n"
                << "Since that is the main color that people with Tritanopia can see sharply.\n\n";
                //std::cout << "score: " << tFinalScore << '\n'; //debug line
                //NOTE following if statements have the potential issue where a 99 is low and a  100 is high
                if (tFinalScore < 100)
                {
                    std::cout << "Your colors together resulted in a low visibility score.\n"
                    << "They would be extremely difficult to distinguish for somebody with Tritanopia.\n"
                    << "People with Tritanopia do not differentiate blue with green well, along with yellow and violet.\n";
                }
                else if (tFinalScore < 200)
                {
                    std::cout << "Your colors together resulted in a high visibility score.\n"
                    << "Somebody with Tritanopia should be able to distinguish these colors without concern.\n";
                }
                else
                {
                    std::cout << "Your colors together resulted in a very high visibility score.\n"
                    << "These colors are extremely distinguishable for someone with Tritanopia.\n";
                }


                //ask if they want to continue
                AskContinue();
                break;         
            }
            case 3:
            {
                std::cout << "You chose Protanopia!\nNow I would like you to input two colors," 
                << " and then I will check how distinguishable they are for people with Protanopia.\n\n";

                GetColors();

                int pFinalScore = ProtanopiaComparison(aR, aG, aB, bR, bG, bB);
                
                //output results
                std::cout << "\n\nAll done!\nThe two main categories we looked into were the lightness and the color intensity.\n"
                << "For Protanopia, we particularly looked at the intensity of red in your colors.\n"
                << "Since people with Protanopia are missing red cones.\n\n";
                //std::cout << "score: " << pFinalScore << '\n'; //debug line
                //NOTE following if statements have the potential issue where a 99 is low and a  100 is high
                if (pFinalScore < 100)
                {
                    std::cout << "Your colors together resulted in a low visibility score.\n"
                    << "They would be extremely difficult to distinguish for somebody with Protanopia.\n"
                    << "People with Protanopia do not differentiate red and green well.\n";
                }
                else if (pFinalScore < 200)
                {
                    std::cout << "Your colors together resulted in a high visibility score.\n"
                    << "Somebody with Protanopia should be able to distinguish these colors without concern.\n";
                }
                else
                {
                    std::cout << "Your colors together resulted in a very high visibility score.\n"
                    << "These colors are extremely distinguishable for someone with Protanopia.\n";
                }

                //ask if they want to continue
                AskContinue();
                break; 
            }
            case 4:
            {
                //Ask for colors now that type has been declared
                std::cout << "You chose the general type!\nNow I would like you to input two colors" 
                << " and then I will check how distinguishable they are for almost all colorblindness types combined.\n\n";

                GetColors();
                CompareAll();
                
                //ask if they want to continue
                AskContinue();
                break;
            }
            default:
            {
                //if char is typed it will fuck up the input stream - have to clear it
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //For above I looked this up, basically the numerlic limits streamsize max is going to cover a very large sized input and it will ignore all of it.
                //the \n then stops it from continuing to remove input after an enter or new line was input
                
                std::cout << "Your input was invalid. Instead type 1-4 to get started\n\n\n"; 
                break;
            }
        }

    }

}



///Check for if inputted rgb values are valid
bool ColorAccepted(int r, int g, int b)
{
    if ((0 <= r && r <= 255) && (0 <= g && g <= 255) && (0 <= b && b <= 255))
    {
        return true;
    }
    else
    {
        return false;
    }
}


///Ask for colors and store them
void GetColors()
{
    //ask for first color
    std::cout << "When inputting the colors please type them out by their RGB values, Ex: 255 0 0 and make sure to put a space between each number.\n"
    << "Lets start with the first color, enter the RGB values and then hit enter.\n";

    //first color
            bool firstColor = false;
            while (!firstColor)
            {
                std::cin >> aR >> aG >> aB;
                if (ColorAccepted(aR, aB, aG))
                {
                    std::cout << "Thank you, this color is accepted. Please type another color.\n";
                    firstColor = true;
                }
                else
                {
                    std::cout << "The color was input wrong, please try again.\n"
                    << "Remember type the color out by its three rgb values with a space between each one, then hit enter.\n";
                }
            }

            //second color
            bool secondColor = false;
            while (!secondColor)
            {
                std::cin >> bR >> bG >> bB; 
                //Make sure color is input correctly
                if (ColorAccepted(bR, bG, bB))
                {
                    std::cout << "Thank you, we will now look more in depth at these two colors.\n";
                    secondColor = true;
                }
                else
                {
                    std::cout << "The color was input wrong, please try again.\n"
                    << "Remember type the color out by its three rgb values with a space between each one, then hit enter.\n";
                }

            }
            std::cout << "Your colors are: " << aR << ' ' << aG << ' ' << aB << " and: " << bR << ' ' << bG << ' ' << bB << "\n";
}


float Sqr(float x)
{
    return x * x;
}

void AskContinue()
{
    std::cout << "\n\nIf you would like to do another color blindness type or if you want to try new colors type 'c' to continue\n";
    char response;
    std::cin >> response;
    if (response == 'c')
    {
        continuing = true;
    }
    else
    {
        continuing = false;
    }
}


///Check if colors are distinguishable for deuteranopia missing green cone
///Take in rgb and convert to be red green blind. So nullify the red and green, and expand the blue
///then convert to LAB --- Checking for light intensty and yellow-blue intesity.
///Not getting red/green because they can't see that anyways so dont need A from LAB
///After LAB conversion - compare intensities and score visibility
int DeuteranopiaComparison(int aR, int aG, int aB, int bR, int bG, int bB)
{

    //make rgb colors what a dueteranope would see by making red and green channel identical
    float aRConverted = (aR * 0.290) + (aG * 0.710); 
    float aGConverted = aRConverted;
    //magic number come from web, has to do with how deuteranopes percieve color. They don't see green so when taking in green light some goes to the red cone
    //red light is dimmer than green so green light takes up a large portion of what the red cone sees.
    float bRConverted = (bR * 0.290) + (bG * 0.710);
    float bGConverted = bRConverted;

    //lightness variable
    //red and blue give small amount of percieved light --- green gives a lot
    // math formula from web
    float aLIntensity = ((aRConverted * 0.2126) + (aGConverted * 0.7152) + (aB * 0.0722));
    float bLIntensity = ((bRConverted * 0.2126) + (bGConverted * 0.7152) + (bB * 0.0722)); // get light value of both

    //get one light intensity value
    //square lA - lB then get square root - this way we get positive value every time depicting the distance between them
    float lIntensity = std::sqrt(Sqr(aLIntensity - bLIntensity));

    // get the visible color intensity ie how much blue or yellow intensity the color has
    float aBIntensity = aB - ((aRConverted + aGConverted) / 2.0);
    float bBIntensity = bB - ((bRConverted + bGConverted) / 2.0);

    //find the absolute value for the intensity distance between both colors -- just like with the L value
    float bIntensity = std::sqrt(Sqr(aBIntensity-bBIntensity));

    //put the intensities together for a value of percieved visibilty
    //squaring here not only gets the absolute value, but it also exponentially favors higher numbers
    int score = std::sqrt(Sqr(lIntensity) + Sqr(bIntensity));
    // scores should range from 0 (same color) to 500 (vibrant blue vs yellow)
    // scores under 100 - hard to tell. above 200 great - numbers not totally consistent

    return score;
}




///Check if colors are distinguishable for Protanopia missing red cone
///Take in rgb and convert to be red green blind. So nullify the red and green, and expand the blue
///then convert to LAB --- Checking for light intensty and yellow-blue intesity.
///Not getting red/green because they can't see that anyways so dont need A from LAB
///After LAB conversion - compare intensities and score visibility
int ProtanopiaComparison(int aR, int aG, int aB, int bR, int bG, int bB)
{

    //make rgb colors what a Protanope would see by making red and green channel identical
    float aRConverted = (aR * 0.080) + (aG * 0.920); 
    float aGConverted = aRConverted;
    //magic number come from web, has to do with how protanopes percieve color. They don't see red and red light isn't very strong
    //so the green cone only takes in 8% of the light that red is pushing
    float bRConverted = (bR * 0.080) + (bG * 0.920);
    float bGConverted = bRConverted;

    //lightness variable
    //red and blue give small amount of percieved light --- green gives a lot
    // math formula from web
    float aLIntensity = ((aRConverted * 0.2126) + (aGConverted * 0.7152) + (aB * 0.0722));
    float bLIntensity = ((bRConverted * 0.2126) + (bGConverted * 0.7152) + (bB * 0.0722)); // get light value of both

    //get one light intensity value
    //square lA - lB then get square root - this way we get positive value every time depicting the distance between them
    float lIntensity = std::sqrt(Sqr(aLIntensity - bLIntensity));

    // get the visible color intensity ie how much blue or yellow intensity the color has
    float aBIntensity = aB - ((aRConverted + aGConverted) / 2.0);
    float bBIntensity = bB - ((bRConverted + bGConverted) / 2.0);

    //find the absolute value for the intensity distance between both colors -- just like with the L value
    float bIntensity = std::sqrt(Sqr(aBIntensity-bBIntensity));

    //put the intensities together for a value of percieved visibilty
    //squaring here not only gets the absolute value, but it also exponentially favors higher numbers
    int score = std::sqrt(Sqr(lIntensity) + Sqr(bIntensity));
    // scores should range from 0 (same color) to 500 (vibrant blue vs yellow)
    // scores under 100 - hard to tell. above 200 great - numbers not totally consistent

    return score;
}




///Check if colors are distinguishable for tritanopia missing blue cone
///Take in rgb and convert to be blue blind. So nullify the blue to be equal to green
///then convert to LAB --- Checking for light intensty and red green intesity(A).
///Not getting blue because they can't see that anyways so dont need B from LAB
///After LAB conversion - compare intensities and score visibility
int TritanopiaComparison(int aR, int aG, int bR, int bG)
{

    //make rgb colors more like what a tritanope would see by making blue and green channel identical
    float aBConverted = (aR + 0.5) + (aG * 0.5);
    float bBConverted = (bR + 0.5) + (bG * 0.5);
    // blue light is inbetween both so neither cone takes in the blue light. However it does take in light just no blue coloring
    //we make the blue value a mixed dimmer version of red and green for a more realistic simulation

    //lightness variable
    //red and blue give small amount of percieved light --- green gives a lot
    // math formula from web
    float aLIntensity = ((aR * 0.2126) + (aG * 0.7152) + (aBConverted * 0.0722));
    float bLIntensity = ((bR * 0.2126) + (bG * 0.7152) + (bBConverted * 0.0722));

    //get one light intensity value
    //square lA - lB then get square root - this way we get positive value every time depicting the distance between them
    float lIntensity = std::sqrt(Sqr(aLIntensity - bLIntensity));

    // get the visible color intensity ie how much red vs green intensity the color has
    float aAIntensity = aR - (aG+ aBConverted) / 2;
    float bAIntensity = bR - (bG+ bBConverted) / 2;

    //find the absolute value for the intensity distance between both colors -- just like with the L value
    float aIntensity = std::sqrt(Sqr(aAIntensity-bAIntensity));

    //put the intensities together for a value of percieved visibilty
    //squaring here not only gets the absolute value, but it also exponentially favors higher numbers
    int score = std::sqrt(Sqr(lIntensity) + Sqr(aIntensity));
    // scores should range from 0 (same color) to 500 (very distinguishable)
    // scores under 100 - hard to tell. above 200 great - numbers not totally consistent

    return score;
}



///test for all together
void CompareAll()
{
    int dScore = DeuteranopiaComparison(aR, aG, aB, bR, bG, bB);
    int tScore = TritanopiaComparison(aR, aG, bR, bG);
    int pScore = ProtanopiaComparison(aR, aG, aB, bR, bG, bB);

    if ((dScore > 100) && (tScore > 100) && (pScore > 100))
    {
        std::cout << "\nComparison complete!\nThese colors are distinguisable between all the color blindnes types we tried.\n"
        << "People with Deuteranopia, Protanopia, and Tritanopia would be able to tell the difference between the colors.\n";
    }
    else
    {
        std::cout <<"\nComparison complete!\nThese colors are not easily distinguishable for all the colorblindness types we tried.\n"
        << "It is hard to tell the difference for one of or all of Deuteranopia, Protanopia, and Tritanopia.\n";
    }

}

