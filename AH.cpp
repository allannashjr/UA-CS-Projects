#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>

int main()
{
    // Declares the Strings Needed for the Program/Files
    std::string fileName, line, movie;

    // Prompts the User for a File Name
    std::cout << "Enter File Name: ";
    std::cin >> fileName;

    // Creates an inStream Using the Txt File
    std::ifstream in(fileName);

    // Creates a Map Called Ratings
    std::map<std::string, std::map<std::string, int> > ratings;

    // If the File Exists/Is Open, the Program Runs
    if(in.is_open())
    {
        // Sets the Precision to 1 Decimal Point
        std::cout << std::setprecision(1) << std::fixed;

        // Gets the First Line and Converts it to an Int to Determine the Number of Total Ratings
        getline(in, line);
        int totalReviews = atoi(line.c_str());

        // For Loop for the Amount of Reviews to Get and Set the Information in the Inputted File
        for(int i = 0; i < totalReviews; ++i)
        {
            getline(in, movie);
            getline(in, line);
            int rating = atoi(line.c_str());

            // If There's Another Rating for That Movie
            if(ratings.find(movie) != ratings.end())
            {
                ratings[movie]["totalReviews"]++;                 // Adds One to the Total Amount of Reviews
                ratings[movie]["totalRatings"] += rating;       // Adds the Review Score to the totalRatings
            }

            // Otherwise, There's Only One Review for That Movie
            else
            {
                ratings[movie]["totalReviews"] = 1;               // Sets the Amount of Reviews to One
                ratings[movie]["totalRatings"] = rating;        // Sets the totalRatings to the Rating of the One Review
            }
        }

        // For Loop to Iterate Through the Map to Determine the Total Reviews and Ratings
        for(auto itr = ratings.begin(); itr != ratings.end(); ++itr)
        {
            // If the Movie Has More Than One Review, Says 'Reviews' Instead of 'Review'
            if(itr->second["totalReviews"] > 1)
            {
                std::cout << itr->first << ": " << std::endl;             // Outputs the Name of the Movie
                // Outputs the Amount of Reviews and the totalRatings(As a Double)
                std::cout << "\t" << itr->second["totalReviews"] << " Reviews with an Average of " << itr->second["totalRatings"] / (double)itr->second["totalReviews"] << " / 5" << std::endl << std::endl;
            }

            // If the Movie Has More Than One Review, Says 'Review' Instead of 'Reviews'
            else
            {
                std::cout << itr->first << ": " << std::endl;             // Outputs the Name of the Movie
                // Outputs the One Review and the totalRatings(As a Double)
                std::cout << "\t" << itr->second["totalReviews"] << " Review with an Average of " << itr->second["totalRatings"] / (double)itr->second["totalReviews"] << " / 5" << std::endl << std::endl;
            }
        }
        in.close(); //Closes the The inStream File
    }

    // If the File Doesn't Exist/Isn't Open, the Program Ends Displaying Error Message
    else
    {
        std::cout << "Invalid File Name. Please Restart the Program and Enter a Valid File Name!" << std::endl;
    }

    return 0;
}
